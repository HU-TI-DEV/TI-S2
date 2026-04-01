---

# C++ Bits — Slides

TI-S2 • Software (C++)
Gera Pronk

Bronnen:
- [bits](https://github.com/HU-TI-DEV/TI-S2/blob/main/programma/lesprogramma/programma-cpp-bits.md)
- Content laten mixen tot ruwe slides: CoPilot

---

# 🧩 Introductie
- Bits: laagste representatieniveau (`0` of `1`)
- Belangrijk voor embedded systemen, IoT en software voor hardware-interfacing

---

# 📦 Bits en datatype
- We gebruiken vaak het type: `uint8_t`.
- Dit type bestaat uit slechts één byte (8 bits).
Bijvoorbeeld:
```cpp
uint8_t val_zeroes = 0x00;   // 00000000
uint8_t val_ones =   0xFF;   // 11111111

uint8_t value =      0x6b;   // 01101011
```
- printen kan zo:
```cpp
#include <bitset>

std::cout << std::bitset<8>(value);
```
- zie [std::bitset](https://en.cppreference.com/w/cpp/utility/bitset.html)

---

# ⚙️ Bits & Bitoperaties
Operators:
- &: AND
- |: OR
- ^: XOR
- ~: NOT
- <<: shift left
- \>>: shift right

---

# 📦 Bitoperaties

table: |
| Bit A | Bit B | A AND B | A OR B | A XOR B | NOT A |
| ----- | ----- | -------- | ------ | ------- | ---- |
|0|0|0|0|0|1|
|0|1|0|1|1|1|
|1|0|0|1|1|0|
|1|1|1|1|0|0|

---

# Code voorbeelden in lesstof
- Laten we kijken naar enkele codevoorbeelden in de lesstof:
[bits](https://github.com/HU-TI-DEV/TI-S2/blob/main/software/c%2B%2B/bits/README.md)

- Docent: runbare code staat in:
[uitleg_bits.cpp](https://github.com/HU-TI-DEV/TI-S2-teacher/blob/main/software/c%2B%2B/opdrachten/bits/uitleg_bits.cpp)

---

# 🧮 Kijk of je onderstaande nu kunt uitrekenen

```cpp
uint8_t flags = 0;
flags |= (1 << 2);
flags &= ~(1 << 2);
bool isSet = flags & (1 << 2);
```

---

# 🧪 Oefening Bits (alleen bij tijd over)
Maak een programma dat het volgende bevat:
1. uint8_t flags = 0;
2. zet bit, wis bit, toon bits
3. een bitnummer inleest (0-7)
4. bit-operaties uitvoert

---
# 📝 Samenvatting
- Bits → low-level controle
- Gecombineerd → efficiënt en compact