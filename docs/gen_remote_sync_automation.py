#!/usr/bin/env python3
"""Extract the 39 RF codes from the ESPHome firmware and emit the HA
automation lookup table (normalized S/L signatures)."""
import re, sys, collections

SRC = sys.argv[1] if len(sys.argv) > 1 else "esphome/rf-fan-remote.yaml"
OUT = sys.argv[2] if len(sys.argv) > 2 else "docs/automations_remote_sync.yaml"

text = open(SRC).read()

BUTTONS = {
    0: "OFF", 1: "1", 2: "2", 3: "3", 4: "4", 5: "5",
    6: "ON", 7: "Sleep", 8: "HYP",
    9: "1H", 10: "2H", 11: "3H", 12: "4H",
}

THRESHOLD = 450  # µs: < short(S), >= long(L)

def normalize(pulses):
    return "".join("L" if abs(p) >= THRESHOLD else "S" for p in pulses)

# parse scripts
patterns = re.findall(
    r"- id: (fan[123]_send)\n\s+parameters:\n\s+key: int\n\s+then:\n"
    r"(.*?)(?=\n  - id: fan|\noutput:)",
    text, re.DOTALL)

table = collections.OrderedDict()
dup = collections.defaultdict(list)

for script_name, body in patterns:
    fan = script_name[3]  # '1'/'2'/'3'
    for m in re.finditer(r"lambda: 'return key == (\d+);'\n\s+then:\n\s+- remote_transmitter\.transmit_raw:\n\s+code: \[([^\]]+)\]", body):
        key = int(m.group(1))
        raw = [int(v.strip()) for v in m.group(2).split(",") if v.strip()]
        sig = normalize(raw)
        code = f"{fan}:{BUTTONS[key]}"
        if sig in table:
            dup[sig].append((table[sig], code))
        table[sig] = code

print(f"scripts parsed: {len(patterns)}  codes: {len(table)}")
if dup:
    print("!! COLLISIONS:")
    for sig, pairs in dup.items():
        print("  ", sig, pairs)
    sys.exit(1)

# emit YAML automation
lines = []
lines.append("# Generated from firmware codes — do not edit by hand.")
lines.append("# Source: esphome/rf-fan-remote.yaml (fan1/2/3_send scripts)")
lines.append("# Re-generate with docs/gen_remote_sync_automation.py")
lines.append("")
lines.append("alias: RF Fan Remote · physical remote sync")
lines.append("description: Sync HA fan entities when a physical remote is used (matches captured RF codes).")
lines.append("trigger:")
lines.append("  - platform: event")
lines.append("    event_type: esphome.rf_fan_remote_press")
lines.append("condition: []")
lines.append("action:")
lines.append("  - variables:")
lines.append("      rc_map:")
for sig, code in table.items():
    lines.append(f'        "{sig}": "{code}"')
lines.append("  - variables:")
lines.append("      rc_raw: \"{{ trigger.event.data.get('raw', '') }}\"")
lines.append("  - condition: template")
lines.append("    value_template: >-")
lines.append("      {% set delims = [',', ' '] %}")
lines.append("      {{ rc_raw | length > 50 }}")
lines.append("  - variables:")
lines.append("      rc_sig: >-")
lines.append("        {% set parts = rc_raw.split(',') | map('int') | list %}")
lines.append("        {% set ns = namespace(pulses='') %}")
lines.append("        {% for p in parts %}")
lines.append("          {% set ns.pulses = ns.pulses ~ ('L' if p | abs >= 450 else 'S') %}")
lines.append("        {% endfor %}")
lines.append("        {{ ns.pulses }}")
lines.append("  - variables:")
lines.append("      rc_hit: \"{{ rc_map.get(rc_sig, rc_map.get(rc_sig[:-1], '')) }}\"")
lines.append("  - condition: template")
lines.append("    value_template: \"{{ rc_hit | length > 0 }}\"")
lines.append("  - variables:")
lines.append("      rc_fan: \"{{ rc_hit.split(':')[0] }}\"")
lines.append("      rc_btn: \"{{ rc_hit.split(':')[1] }}\"")
lines.append("  - service: switch.turn_on")
lines.append("    target:")
lines.append("      entity_id: switch.bedroom_fan_rf_remote_3_fans_rf_suppress")
lines.append("  - if:")
lines.append("      condition: template")
lines.append("      value_template: \"{{ rc_btn == 'OFF' }}\"")
lines.append("    then:")
lines.append("      - service: fan.turn_off")
lines.append("        target:")
lines.append("          entity_id: \"fan.bedroom_fan_rf_remote_3_fans_fan_{{ rc_fan }}\"")
lines.append("  - if:")
lines.append("      condition: template")
lines.append("      value_template: \"{{ rc_btn in ['1','2','3','4','5'] }}\"")
lines.append("    then:")
lines.append("      - service: fan.set_percentage")
lines.append("        target:")
lines.append("          entity_id: \"fan.bedroom_fan_rf_remote_3_fans_fan_{{ rc_fan }}\"")
lines.append("        data:")
lines.append("          percentage: \"{{ [20,40,60,80,100][rc_btn|int - 1] }}\"")
lines.append("      - service: fan.turn_on")
lines.append("        target:")
lines.append("          entity_id: \"fan.bedroom_fan_rf_remote_3_fans_fan_{{ rc_fan }}\"")
lines.append("  - if:")
lines.append("      condition: template")
lines.append("      value_template: \"{{ rc_btn == 'ON' }}\"")
lines.append("    then:")
lines.append("      - service: fan.turn_on")
lines.append("        target:")
lines.append("          entity_id: \"fan.bedroom_fan_rf_remote_3_fans_fan_{{ rc_fan }}\"")
lines.append("  - if:")
lines.append("      condition: template")
lines.append("      value_template: \"{{ rc_btn not in ['OFF','1','2','3','4','5','ON'] }}\"")
lines.append("    then:")
lines.append("      - service: input_text.set_value")
lines.append("        target:")
lines.append("          entity_id: input_text.fan_last_remote_command")
lines.append("        data:")
lines.append("          value: \"Fan {{ rc_fan }} · {{ rc_btn }} @ {{ now().strftime('%H:%M:%S') }}\"")
lines.append("  - delay: 0.7")
lines.append("  - service: switch.turn_off")
lines.append("    target:")
lines.append("      entity_id: switch.bedroom_fan_rf_remote_3_fans_rf_suppress")
lines.append("mode: single")

open(OUT, "w").write("\n".join(lines) + "\n")
print(f"wrote {OUT} ({len(table)} entries)")
