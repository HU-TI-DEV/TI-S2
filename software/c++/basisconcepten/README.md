![logo](../img/ISO_C++_Logo.svg) [](logo-id)

# Basisconcepten C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Introductie](#introductie)
  - [Main](#main)
  - [Layout en puntkomma’s](#layout-en-puntkommas)
- [Commentaar](#commentaar)

---

**v0.1.0 [](version-id)** Start document voor basisconcepten C++ door HU IICT[](author-id).

---

## Introductie

### Main

Het startpunt van elk C++ programma is de functie main(). Als het programma start wordt deze functie aangeroepen. In onderstaand codevoorbeeld staat een simpel C++ programma dat “hello, world” op het scherm print. Hier staan veel nieuwe dingen, dus we gaan het regel voor regel langs, maar we beginnen met een opmerking over de layout.

```cpp {.line-numbers}
#include <iostream> 
using namespace std;

int main(){ 
    cout << "hello, world\n"; 
    }
```
*Codevoorbeeld 2.1 hello, world*

### Layout en puntkomma’s

Belangrijk om te weten voordat je naar C++ code kijkt is dat de compiler in C++ niks geeft om de layout. Dit in tegenstelling tot bijvoorbeeld Python. Inspringen, enters en andere zaken die de layout beïnvloeden maken het voor ons mensen makkelijk om te lezen, maar voor de compiler had het net zo goed op één regel geschreven kunnen staan. In C++ sluiten we instructies af met een ; (puntkomma)(zie regel 2, 6 en 7). Met accolades ({ en }) geven we aan wat bij groepering hoort (zie regel 5 en 8).

Regel 0:
```cpp
#include <iostream> 
```

Net als in andere programmeertalen kun je in C++ gebruik maken van libraries. Sommige zijn al standaard geïnstalleerd. Om makkelijk dingen te printen op het scherm wordt in C++ de library iostream gebruikt . Op regel 0 vertellen we de compiler dat we gebruik willen maken van deze library. Dit doen we met de commando #include en de naam van de library tussen punthaken (< en >). Het object cout op regel 4 komt uit deze library. Later zullen we ook nog andere libraries gebruiken. Het includeren van een library is geen instructie, dus er is geen puntkomma (;) nodig om de regel af te sluiten.

Regel 1 (namespace):
```cpp
using namespace std;
```
Deze regel zegt dat de functies en operatoren in iostream gebruikt moeten worden op de “standaard manier” (std is een afkorting voor standard). Dit zorgt ervoor dat we op regel 4 enkel cout hoeven te typen en niet std::cout om iets te printen op de console.

Regel 3 en 5 (main-functie):
```cpp
int main(){ ...
    }
```
We definiëren de main functie. In hoofdstuk 8 gaan we dieper in op functies. In C++ hebben inspringingen geen effect op de uitvoer van de code (in tegenstelling met Python). De accolades ({ en }) geven aan wat behoort tot de inhoud  van de main-functie. Regel 4 behoort dus tot de inhoud van de functie. In onze code hebben we wel een inspringing. Dit is enkel om de code leesbaarder te maken.

Regel 4 (cout):
```cpp
cout << "hello, world\n"; 
```
Op deze regel printen we de string “hello, world\n”. Als je het woord cout ziet als je beeldscherm, dan kan je de punthaken << zien als dat de string naar het scherm wordt gestuurd.

## Commentaar
In C++ kan commentaar toegevoegd worden aan de code met het gebruik van twee schuine strepen (//). Alles wat achter de twee schuine strepen staat zal worden genegeerd door de compiler. Onderstaand codevoorbeeld laat code zien met commentaar.

```cpp
#include <iostream> 
using namespace std;

int main(){
    // print "hello world" on the screen: 
    cout << "hello, world\n"; 
    }
```
*Codevoorbeeld 2.2 Programma met commentaar in de code*

Net als in de meeste andere programmeertalen kunnen we in C++ waarden opslaan in variabelen. In C++ moet bij de declaratie van de variabele aangegeven worden van welke type het is. Het type van een variabele legt vast hoeveel geheugenruimte een variabele nodig heeft, welke bewerkingen mogelijk zijn en natuurlijk welke soort waardes we erin kunnen stoppen.
