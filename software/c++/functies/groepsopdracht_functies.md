### Teamopdracht: Een kleine tekstverwerker in C++

#### Beschrijving
Jullie gaan als klas samenwerken aan een programma dat tekstbestanden kan lezen, bewerken en opslaan. Het programma bestaat uit vijf functies die door de verschillende teams geschreven moeten worden. Ieder team schrijft één functie. Alleen de standaardbibliotheek, `iostream`, `fstream` en `string` mag worden gebruikt.

Gebruik 'by const reference' wanneer dat kan!

### Functies

Het programma bevat minimaal de volgende functies:

**Team 1:** `readFile()`  
- Leest de inhoud van een bestand en slaat deze op in een `string`.
- Gebruik: `readFile(const string& fileName, string& content);`

**Team 2:** `writeFile()`  
- Schrijft de gemodificeerde inhoud naar een bestand.
- Gebruik: `writeFile(const string& fileName, const string& content);`

**Team 3:** `toUpperCase()`  
- Zet alle letters in de gegeven `string` om naar hoofdletters.
- Gebruik: `toUpperCase(string& content);`

**Team 4:** `findAndReplace()`  
- Vervangt een zoekterm door een vervangterm in de tekst.
- Gebruik: `findAndReplace(string& content, const string& findStr, const string& replaceStr);`

**Team 5:** `displayContent()`  
- Toont de tekst aan de gebruiker.
- Gebruik: `displayContent(const string& content);`

### Samenvoegen van het Programma

Voeg het programma samen in een bestand en presenteer het resultaat voor de klas.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fileName = "bestand.txt";
    string content;

    // Lezen van het bestand
    readFile(fileName, content);
    displayContent(content);

    // Omzetten naar hoofdletters
    toUpperCase(content);
    displayContent(content);

    // Zoeken en vervangen
    string zoekTerm = "V1A";
    string vervangTerm = "TI V1A is de beste";
    findAndReplace(content, zoekTerm, vervangTerm);
    displayContent(content);

    // Opslaan van het resultaat
    writeFile(fileName, content);

    cout << "Alle verwerkingen gedaan. Einde van het programma." << endl;

    return 0;
}
```


