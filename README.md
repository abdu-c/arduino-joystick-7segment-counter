# Arduino Joystick Controlled 7-Segment Display Counter

[TR] Bu proje, Arduino Uno ve XY Joystick modülü kullanarak 1 Haneli 7-Segment Display (5161BS Ortak Anot) üzerinde 0-9 arası sayıları artıran, azaltan ve butonla sıfırlayan interaktif bir sayıcıdır.
[EN] This project is an interactive 0-9 digit counter using an Arduino Uno, XY Joystick, and a 1-Digit 7-Segment Display (5161BS Common Anode) with increment, decrement, and reset functionalities.

---

## Donanım Gereksinimleri / Hardware Requirements
- 1x Arduino Uno
- 1x 1 Haneli 7-Segment Display (5161BS - Ortak Anot / Common Anode)
- 1x XY Joystick Modülü / Module
- 1x 220 ohm Direnç / Resistor
- Breadboard & Jumper Kablolar / Jumper Wires

## Bağlantı Şeması / Pin Configuration

### 7-Segment Display (5161BS)
- **Ortak Anot (Pin 3 veya 8):** `220 ohm Direnç` üzerinden `+5V`
- **Segment A (Pin 7):** Dijital Pin `2`
- **Segment B (Pin 6):** Dijital Pin `3`
- **Segment C (Pin 4):** Dijital Pin `4`
- **Segment D (Pin 2):** Dijital Pin `5`
- **Segment E (Pin 1):** Dijital Pin `6`
- **Segment F (Pin 9):** Dijital Pin `7`
- **Segment G (Pin 10):** Dijital Pin `8`

### Joystick Modülü / Module
- **VRy (veya VRx):** `A0`
- **SW (Buton):** Dijital Pin `9`
- **+5V:** `5V`
- **GND:** `GND`

## Çalışma Mantığı / Working Principle
- **Joystick Yukarı (Y < 300):** Sayacı 1 artırır (Maksimum 9).
- **Joystick Aşağı (Y > 700):** Sayacı 1 azaltır (Minimum 0).
- **Joystick Butonu (SW - LOW):** Sayacı doğrudan 0'a sıfırlar.
- **Ortak Anot Mantığı:** Pinlere `LOW` (0) sinyali gönderildiğinde ilgili segment yanar, `HIGH` (1) sinyalinde söner.
