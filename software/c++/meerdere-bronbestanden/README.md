# Meerdere bronbestanden[](title-id)

## Inhoud[](toc-id)
- [Meerdere bronbestanden](#meerdere-bronbestanden)
  - [Inhoud](#inhoud)
  - [Include](#include)
    - [Include en compilatietijd](#include-en-compilatietijd)
    - [Interface vs. implementatie](#interface-vs-implementatie)
  - [Header-files](#header-files)
    - [ad. 13.3 includeren van de headerfile .hpp](#ad-133-includeren-van-de-headerfile-hpp)
    - [ad. 13.3 addTwice()](#ad-133-addtwice)
    - [ad. 13.3 add()](#ad-133-add)
  - [Dubbele invoeging header-files](#dubbele-invoeging-header-files)
    - [Voorwaardelijke compilatie](#voorwaardelijke-compilatie)
    - [\_FILE\_NAME\_HPP](#_file_name_hpp)
    - [Compile time](#compile-time)
    - [#ifndef en #endif](#ifndef-en-endif)
    - [define en macro](#define-en-macro)


Grotere C++ programma’s worden door goede programmeurs tekstueel opgesplitst over meerdere tekstfiles. Dit zorgt ervoor dat onze code overzichtelijk blijft en dat het compileren sneller gaat.

## Include
Om een bestand toegang te geven tot de variabelen en functies van een ander bestand gebruiken we het sleutelwoord `#include`. Dit hebben we in bijna alle code voorbeelden al gezien bij het invoegen van libraries. 

Zie bijvoorbeeld *codevoorbeeld 3.1*. Hierin
'includeren' we de library `iostream` met het commando `#include <iostream>`, zodat we gebruik kunnen maken van `cout`.

`Include` kunnen we ook gebruiken voor andere bestanden. Bij onze eigen bestanden moeten we wel gebruik maken van aanhalingtekens `(“ ”)`. Bijvoorbeeld: `#include “myotherfile.cpp”`. Het includeren van .cpp bestanden wordt echter als niet netjes beschouwd: het maakt het compileren van je code langzamer. Om het includeren van bestanden netjes te
doen gebruiken we zogenaamde **header-files**.

### Include en compilatietijd
Het includeren van een `.cpp`-bestand is niet illegaal in de taal. Als je een bestand includeert
dan vertel je de preprocessor om de inhoud van het gehele bestand te pakken en dat te kopiëren in het actieve bestand. De preprocessor maakt dus van al je bestanden één groot bestand. Daarna gaat de compiler ermee aan de slag.
Dat lijkt geen probleem te zijn, maar met grote programma’s kan dit voor een lange compileer-tijd zorgen. Als je in één bestand iets kleins hebt aangepast (bijvoorbeeld *int a = 5 + 5;* naar *int a = 10;)* wordt daarna alle code opnieuw gecompileerd. Met grote programma’s kan het dan uren duren voordat je klaar bent met compileren.

### Interface vs. implementatie
Gelukkig is er een manier om verschillende bestanden los van elkaar te laten compileren, én om van elkaar gebruik te laten maken. Als een bestand dan niet
gewijzigd is, hoeft het niet opnieuw gecompileerd te worden. Om dit voor elkaar te krijgen moeten we het *hoe te gebruiken* scheidden van *wat het doet*. In andere woorden:
we moeten de *interface* (declaratie) scheidden van de *implementatie* (definitie). Dit doen we met **header-files** (.hpp) en **source-files** (.cpp).

## Header-files
Bij het schrijven van meerdere bronbestanden maken we gebruik van header-files.
Een headerfile (.hpp) bevat de interface. Het vertelt:
- welke **functies** er in de gelijknamige sourcefile (.cpp) zitten die gebruikt mogen worden door andere bestanden en 
- welke **globale variabelen** mogen worden gebruikt door andere bestanden. 

*Codevoorbeelden 13.1* (`func.hpp`), *13.2* (`func.cpp`) en *13.3* (`main.cpp`) geven voorbeelden van het gebruik van meerdere bronbestanden.

```c++
int addTwice(int a, int b);
```
*Codevoorbeeld 13.1 - Headerfile func.hpp*

```c++
#include "func.hpp"

int add(int x, int y){
  return x + y;
}

int addTwice(int a , int b){
  int result = add(a, b);
  result = add(result, b);
  return result;
}
```
*Codevoorbeeld 13.2 - Sourcefile func.cpp*

```c++
#include "func.hpp"

int main(){
  int n1 = 8;
  int n2 = 10;
  int r = addTwice(n1, n2);

  // r now contains the integer 28
}
```
*Codevoorbeeld 13.3 - main.cpp die gebruikt maakt van func.hpp*

### ad. 13.3 includeren van de headerfile .hpp
De header-file (in dit geval `func.hpp`) moet worden geïncludeerd in 
- zowel het bestand waarin we de geïmporteerde functies willen gebruiken (in dit geval `main.cpp`) als in
- het source bestand behorende bij de header-file (in dit geval `func.cpp`).
  
### ad. 13.3 addTwice()
De functie `addTwice()` wordt gedefinieerd in de header-file. Hierdoor weet de compiler
als bestanden `func.hpp` includeren hoe hij hiermee moet omgaan. De interface, het hoe te gebruiken, is tenslotte bekend. De compiler kan zien welke types in de functie gaan en welke types uit de functie komen.

### ad. 13.3 add()
De functie `add()` is niet gedefinieerd in de header-file. In het bestand `main.cpp` kan
niet met de functie `add()` worden gewerkt. De compiler weet niet welke functie er bedoeld wordt.

## Dubbele invoeging header-files
Als een file meerdere header-files invoegt, en de header-files op hun beurt ook weer headerfiles
invoegen, kan het voorkomen dat (onbedoeld) dezelfde header-file meer dan één keer wordt ingevoegd. 
Dit leidt tot dubbele definities en compile-errors. 

### Voorwaardelijke compilatie
Om dubbele definities te voorkomen begint een header-file vaak met beschermende compilatievoorwaarden: definieer (`define`) de volgende code alleen als deze nog niet eerder is gedefinieerd (`ifndef`). 
Hoe dit werkt is te zien in *codevoorbeeld 13.4*.
Het bestand `func.hpp` uit *codevoorbeeld 13.1* is in *codevoorbeeld 13.5* uitgebreid met een beschermende opbouw.

### _FILE_NAME_HPP
Merk op dat `FILE_NAME` in `_FILE_NAME_HPP` wordt vervangen door de naam van de betreffende file (in voorbeeld 13.5 is dit: `FUNC`).

```c++
#ifndef _FILE_NAME_HPP
#define _FILE_NAME_HPP
... // content of the header file
#endif /* _FILE_NAME_HPP */
```
*Codevoorbeeld 13.4 - Header-file opbouw*

```c++
#ifndef _FUNC_HPP
#define _FUNC_HPP
int addTwice(int a, int b);
#endif /* _FUNC_HPP */
```
*Codevoorbeeld 13.5 - Func.hpp met bescherming tegen dubbel invoegen.*

### Compile time
Tijdens het compileren kan er ook code worden uitgevoerd. Hiervoor hebben we speciale sleutelwoorden: `#ifndef`, `#endif` en `#define` zijn zulke sleutelwoorden. Als de compiler code uitvoert tijdens het compileren, dan zeggen we dat dat gebeurt tijdens *compiletime*.

### #ifndef en #endif
Het sleutelwoord `#ifndef` staat voor *“if not defined”*. Als de variabele achter `#ifndef` nog niet bestaat, dan zal de code tussen dit sleutelwoord en het sleutelwoord `#endif` worden meegenomen door de compiler. De code in *codevoorbeeld 13.5* wordt dus enkel meegenomen door de compiler als `_FUNC_HPP` nog niet bestaat.

### define en macro
Met het sleutelwoord `#define` maken we een *macro* aan. Een macro is een stuk tekst uit het bronbestand dat een naam heeft gekregen. Een macro gedraagt zich anders (en is iets anders) dan een variabele, daarom schrijven we de naam van een macro altijd in hoofdletters.
In *codevoorbeeld 13.5* heet de macro `_FUNC_HPP`.
