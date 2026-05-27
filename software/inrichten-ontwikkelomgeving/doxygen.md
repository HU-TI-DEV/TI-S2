# Doxygen installeren[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Wat is Doxygen?](#wat-is-doxygen)
- [Installatie Doxygen algemeen](#installatie-doxygen-algemeen)
  - [Optie 1: Windows + VSCode](#optie-1-windows--vscode)
  - [Optie 2: Windows + elke IDE](#optie-2-windows--elke-ide)
  - [Optie 3: Windows + winget](#optie-3-windows--winget)
  - [Controleer of doxygen werkt](#controleer-of-doxygen-werkt)
  - [Meer informatie](#meer-informatie)


### Wat is Doxygen?
Doxygen is een tool die helpt bij het genereren van commentaar of documentatie. Doxygen is ontwikkeld door Dimitri van Heesch.

### Installatie Doxygen algemeen
Er zijn verschillende manieren om Doxygen te installeren. Je kunt dit vinden op [de homepage van Doxygen](https://www.doxygen.nl/manual/install.html).
Hieronder staan enkele tips voor:
- Windows + VSCode
- Windows + andere IDE

#### Optie 1: Windows + VSCode
- Gebruik een VSCode extensie (zoek binnen je VScode naar extensies). Bv: [bbenoist.Doxygen](https://marketplace.visualstudio.com/items?itemName=bbenoist.Doxygen).

#### Optie 2: Windows + elke IDE
- [Installeer de binaries van Doxygen](https://www.doxygen.nl/manual/install.html#install_bin_windows) (via de downloadknop)
- Voeg na het installeren de directory waarin het bestand `doxygen.exe` staat toe aan je PATH. Bijvoorbeeld: C:\Program Files\doxygen\bin
- Herstart je IDE (bv VS Code).

#### Optie 3: Windows + winget
- Open een nieuwe Command Prompt (CMD) of PowerShell en typ:
- `winget install doxygen`
- Voeg na het installeren de directory waarin het bestand `doxygen.exe` staat toe aan je PATH. Bijvoorbeeld: C:\Program Files\doxygen\bin
- Herstart je IDE (bv VS Code).

#### Controleer of doxygen werkt
- Open een nieuwe Command Prompt (CMD) of PowerShell en typ:
- `doxygen -v`
- Als het goed is, zie je een versienummer van Doxygen.

#### Meer informatie
[Uitleg en gebruik Doxygen in c++ code](../c++/oop-concepten/doxygen/README.md)
Informatie op de Doxygen site: https://www.doxygen.nl/index.html#cplusplus.