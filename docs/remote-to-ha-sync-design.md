# Physical remote → Home Assistant state sync (design)

**Goal:** when a physical Crompton remote is used, HA's fan entities (and dashboard)
must reflect the real fan state, without re-transmitting RF (no echo/double-beep).

**Feasibility recap:** already proven — the ESP32-C3+CC1101 is a transceiver,
`remote_receiver` on GPIO10 (GDO2) is already configured, and `cc1101.begin_rx`
runs at boot and after every TX. The 39 fixed codes are already captured in
`captured_codes.md` → usable as a matching table.

## Architecture

```
Physical remote ──433.92MHz──► CC1101 RX (GDO2→GPIO10)
                                   │ remote_receiver.on_raw
                                   ▼
                       ESPHome event "esphome.rf_fan_remote_press"
                          (raw pulse array, µs)
                                   │ API (native)
                                   ▼
                       HA automation: normalize → match code → update entity
                                   │ (suppress_rf ON, so no RF re-sent)
                                   ▼
                       Fan entity state updates → dashboard syncs
```

## 1. Firmware change (small)

Add to `esphome/rf-fan-remote.yaml`:

```yaml
remote_receiver:
  pin: GPIO10
  tolerance: 25%
  filter: 100us
  idle: 4ms
  buffer_size: 4kb
  on_raw:
    - homeassistant.event:
        event: esphome.rf_fan_remote_press
        data:
          raw: !lambda 'return x;'   # std::vector<int> µs pulses → JSON array
```

Notes:
- No decoding/matching on the ESP → no big C++ lookup table, firmware stays lean.
- RX is automatically paused during TX (half-duplex) — a remote press that
  collides with an HA→fan send may be missed once; acceptable.
- Repeated bursts (5–7 per press) arrive as multiple events; handled on HA side.

## 2. HA side: matching

- One template/script builds the lookup from `docs/captured_codes.md`:
  each raw µs list is normalized to a binary string (`S`/`L` per pulse using a
  ~400 µs threshold) → key = normal string, value = `{fan, button}`.
- Automation `esphome.rf_fan_remote_press`:
  1. Normalize incoming raw pulses the same way (short < 400 µs, long ≥ 400 µs).
  2. Look up key in the 39-entry table.
  3. On match → **same action path as the dashboard buttons**, i.e.:
     `switch.turn_on` suppress_rf → set fan entity (percentage 20/40/60/80/100,
     off, on) → `delay 0.7` → `switch.turn_off` suppress_rf.
     (Reuses the existing loop-safe pattern from `docs/automations.yaml`.)
  4. `mode: single` + cooldown guard (`now() - last_triggered` ≈ ≥1 s) to
     debounce the repeated bursts.
- **No RF emitted by this path:** the fan entity write goes through the template
  output, whose `write_action` dedupes (same `last_level_fanN` → return) and is
  suppressed while `suppress_rf` is on. Double-beep loop cannot recur.

## 3. What can/cannot sync

| Remote button | HA effect |
|---|---|
| ON / OFF / 1–5 | Fan entity on/off + percentage (full sync) |
| Sleep / HYP | No fan-entity equivalent → record to a `sensor.fan_last_remote_command` (text) so the press is visible; optionally a `select` for mode |
| 1H–4H timers | Same — record last command + show timer in sensor (requires knowing remaining time; not reliably available from remote) |

- Entity updates are immediate (~0.5–2 s after press).

## 4. Testing plan

1. `esphome config` validation → compile → OTA push.
2. `esphome logs` while pressing a physical button → confirm `on_raw` fires.
3. HA Developer Tools → Events → subscribe to `esphome.rf_fan_remote_press` → press all
   13 buttons of one remote → verify pulses arrive.
4. Enable automation → press buttons → verify fan entity + dashboard change, and
   **no fan beep/echo** (confirms suppress path works).
5. Repeat for remotes 2 and 3 (codes differ per remote).
6. Press remote while HA writes (collision) → confirm no crash, only a missed
   event on rare collision.

## 5. Future extras (out of scope for v1)

- Decode timer/sleep state from RF (would need sniffing fan's own replies — fans
  are one-way, so not possible; state must be assumed).
- HA-side "last known good" table persisted across restarts (sensor restores).
- Auto-learn mode: capture unknown codes w a "learn" button, like the original
  sniffer workflow.
