# RF protocol notes

## What we found

- Carrier: **433.92 MHz**, ASK/OOK, CC1101 `filter_bandwidth` ≈ 540 kHz.
- Each key is a **fixed code** (repeats identically on every press; no rolling code).
- Each press emits ~5–7 frame bursts, ~60 ms apart — the fans expect this; we mimic with `repeat: 3 × 15ms`.
- Frames are ~65 alternating mark/space pulses (µs), two widths:
  - short ≈ 250–300 µs
  - long ≈ 750–800 µs
- **Not RCSwitch.** The dumper’s CanalSatLD match is incidental (IR decoder matching OOK RF); raw lists are used for TX.

## 32-bit view (informational)

Reading mark/space pairs (long mark + short space = 1; short mark + long space = 0, MSB first) gives:

| Remote | Button | 32-bit value |
|---|---|---|
| R1 | OFF | `0x26A25605` |
| R1 | ON | `0x26A25E7A` |
| R1 | Speed 1 | `0x26A25535` |

All three remotes are individually keyed (R1 vs R2 codes differ in ~28 pulse positions, so per-fan control is possible).

> The `crompton-bldc-rf` HACS integration targets model `CFENHP35W48IVYRM` (`0x9145…` codes) — **different family**; it will not control these fans without adding a new model/code table.
