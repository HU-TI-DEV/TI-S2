# Compositie - header en source files [](title-id)

### Inhoud[](toc-id)
- [Compositie - header en source files ](#compositie---header-en-source-files-)
    - [Inhoud](#inhoud)
    - [Verdeling over header en source files](#verdeling-over-header-en-source-files)
      - [Header files](#header-files)
      - [Source files](#source-files)
      - [Namespace](#namespace)
    - [Relaties tussen klassen](#relaties-tussen-klassen)
      - [Compositie](#compositie)
      - [Constructor en initialisatielijst voor compositie](#constructor-en-initialisatielijst-voor-compositie)
      - [Initialisatie van variabelen (in constructor)](#initialisatie-van-variabelen-in-constructor)
    - [Schermobjecten](#schermobjecten)
      - [Gebruik schermobject](#gebruik-schermobject)
    - [Reference parameters en reference variabelen](#reference-parameters-en-reference-variabelen)
    - [Relaties tussen klassen: associatie](#relaties-tussen-klassen-associatie)


### Verdeling over header en source files
Vaak wordt C++ code opgesplitst in twee soorten files:
**header en source files**.

#### Header files
De *declaratie* (interface) van een klasse staat vrijwel altijd in een **header file**: zo kunnen andere onderdelen in een programma deze declaratie binnen hun code 'includen'.
Vaak is een klasse bedoeld om in andere onderdelen van een applicatie gebruikt te worden. Via een header file kunnen deze andere onderdelen de declaratie van de klasse includen. Voor C++ wordt meestal de extensie `.hpp` gebruikt voor header files.

#### Source files
De *definitie* (implementatie) van een klasse functie kan in de klasse declaratie staan (dus in de header file), zoals we hebben gedaan bij de lijn constructor. Dit wordt over het algemeen alleen gedaan met heel simpele functies. Niet-triviale functies worden in de bijbehorende implementatie file gezet: de **source file**. Voor C++ wordt meestal de extensie .cpp gebruikt voor implementatie files. 

Over header files:
- Een header file heeft een `#ifndef/#define/#endif` die zorgt dat er geen problemen ontstaan als een header meer dan 1 keer ge-include wordt. Dit heet een *include Guard*.
- De header file wordt altijd ge-#include door de bijbehorende implementatie file (.cpp). Deze file heeft dezelfde naam (bv `line.hpp` en `line.cpp`)
- De header file wordt ge-#include door alle andere files die gebruik maken van de services die in de header file zijn gedeclareerd.
- In code voorbeelden worden de #include regels vaak weggelaten; in code zijn ze natuurlijk wél nodig.

```c++
#ifndef LINE_HPP
#define LINE_HPP

class line {
. . .
};
```
*Codevoorbeeld 04-07 - Bescherming tegen multiple-inclusion in de file line.hpp*

#### Namespace
Een functie of methode is meestal onderdeel van een bepaalde klasse. Voor de lijn klasse (`class line`) staat de implementatie van de print functie in de `line.cpp` file. Buiten deze klasse declaratie moet je aangeven bij welke klasse de functie behoort: voor de naam van de functie zet je zijn klasse-naam en `::` zetten, anders heb je het over een losse functie die niets met een klasse te maken heeft. Bínnen de klasse definitie zelf hoeft dat niet.
De scope waarbinnen een functie geldig is, heet *namespace*.

```c++
#include ”line.hpp”

void line::print(){
  . . . // code
}
```
*Codevoorbeeld 04-08 - Implementatie van een member-functie (= methode) in de file line.cpp*