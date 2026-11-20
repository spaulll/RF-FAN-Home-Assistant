# Wiring — CC1101 → ESP32-C3 Super Mini

```
┌───────────────────────────┐        ┌─────────────────────────────┐
│  CC1101 module (SMA)      │        │  ESP32-C3 Super Mini       │
│                           │        │                             │
│  VCC ────────────────3V3 ─┼────────┼── 3V3   (never 5V!)        │
│  GND ─────────────────────┼────────┼── GND                       │
│  SCK ─────────────────────┼────────┼── GPIO4   (SPI CLK)         │
│  MISO/SO ─────────────────┼────────┼── GPIO5   (SPI MISO)        │
│  MOSI/SI ─────────────────┼────────┼── GPIO6   (SPI MOSI)        │
│  CSN ─────────────────────┼────────┼── GPIO7   (SPI CS)          │
│  GDO0 ────────────────────┼────────┼── GPIO3   (TX path)         │
│  GDO2 ────────────────────┼────────┼── GPIO10  (RX path)         │
└───────────────────────────┘        └─────────────────────────────┘
```

## Rules

- **VCC = 3V3 only.** Connecting 5V will damage the CC1101.
- **Dual-pin mode**: GDO0 drives the transmit data line (GPIO3), GDO2 drives the receive data line (GPIO10). Do not use single-pin mode for this build.
- Avoid GPIO2, GPIO8, GPIO9 on the ESP32-C3 (strap/boot pins).

## Antenna

- SMA 433 MHz antenna on the module; keep 10–30 cm from remote when capturing.
- When testing, note that during TX the CC1101 is in TX mode — it cannot hear its own frames (no self-echo).
