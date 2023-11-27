# Inrichten ontwikkelomgeving[](title-id)

## Inhoud[](toc-id)
- [Inrichten ontwikkelomgeving](#inrichten-ontwikkelomgeving)
  - [Inhoud](#inhoud)
  - [Installeren](#installeren)
    - [CodeLite](#codelite)
    - [MinGW](#mingw)
    - [Een C++programma uitvoeren](#een-cprogramma-uitvoeren)
    - [Project](#project)


## Installeren
In deze cursus wordt gebuik gemaakt van de volgende, vrij verkrijgbare, software:
- CodeLite
- MinGW
- Git


### CodeLite
CodeLite is een editor/IDE die je kunt vinden op: https://codelite.org.

CodeLite heeft de irritante eigenschap bij het opstarten te checken of er een nieuwe
versie is, en als die er niet is lukt het niet om die te installeren. Dit kan je
uitzetten via Settings -> Preferences -> Misc -> Check for new version at startup.

### MinGW
MinGW is een GCC compiler voor Windows. Je kunt MinGW installeren via de link op: http://tdm-gcc.tdragon.net/download. Neem de 32 bits versie.

### Een C++programma uitvoeren
Om een C++programma uit te voeren moet je eerst een **workspace** hebben. In een workspace kunnen meerdere C++ programma’s staan. Een workspace maak je met:
File -> New -> New Workspace.

### Project
Voor elk C++programma moet je een **project** aanmaken in je workspace. Een project maak je aan met: 
- File -> new -> project. 
- Kies "Simple executable (g++)" -> next.
- Geef je project een naam. 
- next -> Finish.
- 
In het project staat nu een bestand genaamd `“main.cpp”`. Hierin schrijf je je C++ code.