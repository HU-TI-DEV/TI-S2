---
title: "C++ Meerdere bestanden — slides"
course: "TI-S2 • Software (C++)"
author: Gera Pronk
sources:
  - text: "meerdere bestanden"
    url: "https://github.com/HU-TI-DEV/TI-S2/slides/S2_meerdere_bestanden.md"
  - "Content laten mixen tot ruwe slides: CoPilot"
---
# C++ – Programmeren met meerdere bestanden

C++ - Interface, implementatie & header files

**TI-S2  Software (C++)**
Gera Pronk

Bronnen:
- [C++ meerdere bestanden](https://github.com/HU-TI-DEV/TI-S2/blob/main/programma/lesprogramma/programma-cpp-meerdere-bestanden.md)
- Content laten mixen tot ruwe slides: CoPilot
  
---

# Waarom meerdere bestanden?

- Grotere C++-programma’s worden opgesplitst voor **overzicht**.  
- Snellere compile-tijd: alleen gewijzigde delen hoeven opnieuw.  
- Onderhoudsvriendelijk & modulair.  
- Scheiding tussen *wat* iets doet en *hoe* het werkt.

---

# Include en compilatietijd

## Wat doet `#include`?

- De preprocessor **kopieert letterlijk** de inhoud van het bestand in het actieve bestand.

## Waarom geen `#include` van `.cpp`-files:
- Inclusie van `.cpp` werkt wel, maar:
  - Niet netjes
  - Langzamere compile‑tijd

✅ Oplossing: gebruik **header‑files (.hpp)** voor de interface.

---

# Interface vs. implementatie

| Onderdeel | Inhoud | Bestandssoort |
|----------|--------|---------------|
| **Interface** | Declaraties (hoe gebruik je het?) | `.hpp` |
| **Implementatie** | Definities (wat doet het?) | `.cpp` |

- De interface verandert minder vaak → snellere builds
[meerdere bronbestanden](https://hu-ti-dev.github.io/TI-S2/software/c++/meerdere-bronbestanden/)

---

# Header‑files (.hpp of .h)

Een header bevat:
- Functie‑declaraties  
- Klasse‑definities - komt later
- Constantes / macro’s 
- Template‑code  - komt later

---

### Voorbeeld - add()

```cpp
// mathutils.hpp

int add(int a, int b);

#endif
```

---

```cpp
// mathutils.cpp
#include "mathutils.hpp"

int add(int a, int b) {
  return a + b;
}
```
---

```cpp
#include <iostream>
#include "mathutils.hpp"
using namespace std;

int main() {
  cout << add(3, 4);
}
```
---

# Dubbele invoeging voorkomen

Gebruik include guards in je .hpp file:
```cpp
#ifndef BESTANDSNAAM_HPP
#define BESTANDSNAAM_HPP
// inhoud
#endif
```
---

### Voorbeeld - mathutils.hpp

```cpp
// mathutils.hpp
#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

int add(int a, int b);

#endif
```

---

# Structuur van een project
```
/project
│ main.cpp
│ mathutils.cpp
│ mathutils.hpp
```

---

# Compileren op de command line

```sh
g++ filename1.cpp filename2.cpp main.cpp -o myprogram
```
---

# Oefening

## Splits een functie uit in meerdere bestanden

**Stap 1 — Maak een header-file**
```cpp
#ifndef CONVERTER_HPP
#define CONVERTER_HPP

double celsiusToKelvin(double c);

#endif
```

**Stap 2 — Maak een implementatiebestand**
```cpp
#include "converter.hpp"

double celsiusToKelvin(double c) {
  return c + 273.15;
}
```

**Stap 3 — Gebruik de functie in main.cpp**
```cpp
#include <iostream>
#include "converter.hpp"
using namespace std;

int main() {
  cout << celsiusToKelvin(21.0) << endl;
}
```

---

**Stap 4 — Compileer de files via de CLI**

```sh
g++ converter.cpp main.cpp -o celToKel
```

Run het programma:
```sh
./celToKel
```

---

# Samenvatting

- Gebruik `.hpp` voor interfaces, `.cpp` voor implementaties  
- Nooit `.cpp` includen  
- Include‑guards verplicht  
- Modulaire opbouw = overzichtelijk + snel compileren  

---

# Vragen?
---