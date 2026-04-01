---
title: "C++ Files input - slides"
course: "TI-S2 • Software (C++)"
author: Gera Pronk
sources:
  - text: "Files input"
    url: "https://github.com/HU-TI-DEV/TI-S2/slides/S2_Files_input.md"
  - "Content laten mixen tot ruwe slides: CoPilot"
---

# Files input/output C++

**TI-S2 • Software (C++)**  
Gera Pronk

C++ — Files input

Bronnen:
- TI‑S2 software index; C++ ifstream en getline referenties.  [hu-ti-dev.github.io], [en.cppreference.com], [en.cppreference.com]
[files-input](https://github.com/HU-TI-DEV/TI-S2/blob/main/software/c++/files-input/README.md)
- Content laten mixen tot ruwe slides: CoPilot

---

## Leerdoelen
- Een bestand **openen** en **sluiten** met `std::ifstream`.
- Regels **lijn‑voor‑lijn** inlezen met `std::getline`.
- **Tokens/waarden** inlezen met de `>>`‑operator.
- Fouten en **EOF** netjes afhandelen (`is_open`, `fail`, `eof`).
- Eenvoudige **CSV** of “gescheiden velden” lezen met `std::stringstream`.

---

## Voorbereiding & context

- Header: #include <fstream> en vaak ook #include <string> voor tekstregels. [en.cppreference.com]
- Bestanden worden geassocieerd met een stream (ifstream) die je daarna net als cin kunt gebruiken. [cplusplus.com]
- In TI‑S2 gebruiken we dit o.a. voor het inlezen van meetdata. [hu-ti-dev.github.io]

---

## Een bestand openen
```cpp
#include <fstream>
#include <iostream>

const int SUCCEEDED = 0; 
const int FAILED = 1;

int main() {
    std::ifstream in{"data.txt"};   // open voor lezen
    if (!in.is_open()) {    // in.is_open() --> false als openen is mislukt
        std::cerr << "Kon data.txt niet openen";
        return 1; // oh, oh: een magic number - hoe kan dit anders?
    }
}
```
- `ifstream in{"pad/naar/bestand"};` opent direct; anders in.open(...).
- Controleer altijd `is_open()` en later de statusbits (`fail(), eof()`).
---

## Regels lezen met `std::getline`
```cpp
std::string line;
while (std::getline(in, line)) {
    std::cout << line << '';
}
```
- `std::getline(stream, string)` leest tot aan lijnafbreking en laat de delimiter achterwege.
- De while‑conditie faalt automatisch bij `EOF` of fout.
- 
---

## Tokens/waarden lezen met `>>`
```cpp
int x; double y; std::string naam;
while (in >> x >> y >> naam) {
    std::cout << x << " " << y << " " << naam << " ";
}
```
- De operator `>>` skipt whitespace en parseert types.
- Bij een type‑mismatch zet de stream het `failbit` en stopt de loop.
---

## CSV splitten
```cpp
std::stringstream ss(line);
std::string cel;
while (std::getline(ss, cel, ',')) {
    // verwerk cel
}
```

---

## Statusbits & foutafhandeling
Belangrijkste checks op een input‑stream:

- `good()` — geen fouten.
- `eof()` — einde van bestand bereikt.
- `fail()` — parse/format‑fout (bijv. int verwacht).
- `bad()` — onherstelbare I/O‑fout.

In code, bijvoorbeeld:

```cpp
if (in.fail()) {    // eventueel in.clear(); om verder te gaan na herstel}
```

- `getline` op een te korte buffer (C‑style) of leesfouten kan failbit zetten; met std::string + std::getline heb je dat zelden nodig. [en.cppreference.com], [stackoverflow.com]

---

##  Lijn splitten (bijv. CSV)
```cpp
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> split_csv(const std::string& line, char sep=',') {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string cell;
    while (std::getline(ss, cell, sep)) 
        fields.push_back(cell);
    return fields;
}
```

- Combineer `std::getline` met een `std::stringstream` om simpele, niet‑gequote CSV te lezen.
- Voor volledige CSV (quotes/escapes) heb je een echte parser nodig. [en.cppreference.com]

---

## Binaire bestanden
```cpp
#include <fstream>
#include <vector>

int main() {
    std::ifstream in{"image.bin", std::ios::binary};
    std::vector<char> buf((std::istreambuf_iterator<char>(in)),
                          std::istreambuf_iterator<char>());
}
```
- Gebruik `std::ios::binary` en lees bytes i.p.v. tekst. [en.cppreference.com]
---

## Paden & best practices

- Relatieve paden werken t.o.v. het werkdirectory van je proces.
- Sluit niet per se handmatig: RAII sluit bij scope‑einde; expliciet close() mag wel.
- Altijd status controleren en duidelijke foutmeldingen geven (bestand niet gevonden, permissies). [cplusplus.com]

---

## Veelvoorkomende valkuilen

- `operator>>` leest tot eerste whitespace — namen met spaties vereisen `std::getline`. [en.cppreference.com]
- Windows CRLF: combinaties van platforms kunnen onverwachte \r achterlaten — line.erase(...) als nodig. (Let op tijdens testen.) [en.cppreference.com]
- UTF‑8 BOM: eerste regel kan beginnen met BOM‑bytes; strip indien nodig. (Afhankelijk van bronbestand en platform.) [cplusplus.com]

---

## Mini‑opdracht 1 — regels tellen

Schrijf een programma dat:

1. een bestandsnaam via argv[1] leest,
2. het aantal regels, woorden en tekens print.


Hints: `std::getline`, `std::istringstream` voor woorden, check `in.fail()`. [en.cppreference.com]

---

## Mini‑opdracht 2 — simpele CSV naar struct

1. Lees `meetdata.csv` met kolommen: `tijd, temperatuur, luchtvochtigheid`.
2. Parse naar een struct en print gemiddelde temperatuur.

Hints: std::getline + stringstream, conversie met std::stod. [en.cppreference.com]

---

## Checklist / Rubric

 - Opent bestand veilig; meldt fouten. [en.cppreference.com]
 - Gebruikt std::getline of >> passend bij input. [en.cppreference.com]
 - Controleert statusbits (fail/eof). [en.cppreference.com]
 - Scheidt I/O en logica (functies). (TI‑S2 good practice) [hu-ti-dev.github.io]

---

## Einde
Vragen?

---

## Referenties & verder lezen

- TI‑S2 – software index (navigatie naar files‑input en verwante pagina’s). [hu-ti-dev.github.io]
- std::ifstream — C++ referentie (openen, status, binary). [en.cppreference.com]
- std::getline — C++ referentie (tekstregels, delimiters). [en.cppreference.com]
- C++ tutorial — File I/O (overzicht ifstream/ofstream/fstream). [cplusplus.com]