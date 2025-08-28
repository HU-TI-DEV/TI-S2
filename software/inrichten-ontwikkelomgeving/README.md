![logo](../c++/img/ISO_C++_Logo.svg) [](logo-id)

# Inrichten ontwikkelomgeving[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Installeren](#installeren)
  - [Arduino IDE](#arduino-ide)
  - [MinGW](#mingw)
  - [Visual Studio Code](#visual-studio-code)
  - [Doxygen](#doxygen)
- [Een C++programma uitvoeren](#een-cprogramma-uitvoeren)
- [Project](#project)
- [Alternatieven](#alternatieven)
  - [Online C++ editor/compiler](#online-c-editorcompiler)
  - [CodeLite](#codelite)

## Installeren

In dit semester wordt onder andere gebruik gemaakt van de volgende, vrij verkrijgbare, software:

- Arduino IDE
- MinGW
- Git
- Visual Studio Code

### Arduino IDE

Om C++ code te draaien, gebruiken we in eerste instantie een [Arduino IDE](https://docs.arduino.cc/learn/starting-guide/the-arduino-software-ide/).

### MinGW

MinGW is een GCC compiler voor Windows. Je kunt MinGW installeren via de link op: <http://tdm-gcc.tdragon.net/download>. Neem de 32 bits versie.

### Visual Studio Code

Visual Studio Code (VSC) is een lichtgewicht ontwikkelomgeving die draait op je desktop. VSC is beschikbaar voor Windows, macOS en Linux.
- [Installatie VScode](visualstudiocode.md)
- [Configuratietips](vscode_tips.md)

### Doxygen

Doxygen is een tool die helpt bij het genereren van commentaar of documentatie.
- [Installatie Doxygen](./doxygen.md)

## Een C++programma uitvoeren

Om een C++programma uit te voeren moet je eerst een **workspace** hebben. In een workspace kunnen meerdere C++ programma’s staan.
Een workspace maak je automatisch aan met: `File` -> `Open Folder`.

[Meer uitleg over workspaces staat op deze site.](https://code.visualstudio.com/docs/editor/workspaces/workspaces)

## Project

(NB: oudere versies van VS Code en sommige plug-ins/extensies bieden deze aparte optie.)

Voor elk C++programma moet je een **project** aanmaken in je workspace. Een project maak je aan met:

- File -> new -> project.
- Kies "Simple executable (g++)" -> next.
- Geef je project een naam.
- next -> Finish.
  
In het project staat nu een bestand genaamd `main.cpp`. Hierin schrijf je je C++ code.

## Alternatieven

### Online C++ editor/compiler

Mocht het helemaal niet lukken met de ontwikkelomgeving, gebruik dan *tijdelijk* een online C++ editor/compiler (bv <https://onecompiler.com/cpp>).

### CodeLite

Of stap over op een andere IDE: bijvoorbeeld [CodeLite](codelite.md).
