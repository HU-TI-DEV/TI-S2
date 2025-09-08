# Files input/output[](title-id) <!-- omit in toc -->

## Inhoud[](toc-id) <!-- omit in toc -->

- [Bestand schrijven](#bestand-schrijven)
  - [Fstream](#fstream)
  - [Ofstream](#ofstream)
  - [\<\<](#)
- [Bestand lezen](#bestand-lezen)
  - [Ifstream](#ifstream)
  - [Meer informatie](#meer-informatie)

Programma’s interacteren niet enkel met gebruikers voor input en output, maar kunnen ook interactie met bestanden hebben. In dit hoofdstuk gaan we in op het schrijven en
lezen van bestanden.

## Bestand schrijven

Schrijven naar een bestand kan op verschillende manieren. In *codevoorbeeld 11.1* staat voorbeeldcode voor het schrijven van een bestand. Hierbij wordt het oorspronkelijke bestand in zijn geheel overschreven. Willen we niet de oorspronkelijke inhoud
verwijderen, maar iets toevoegen aan het einde, dan moeten we aan de open functie de parameter `ofstream::app` (append) toevoegen. Dit zien we in *codevoorbeeld 11.2*.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "overwriting this to a file.\n";
    myfile.close();
}
```

*Codevoorbeeld 11.1 - Het overschrijven van een bestand*

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream myfile;
    myfile.open("example.txt", ofstream::app);
    myfile << "appending this to a file.\n";
    myfile.close();
}
```

*Codevoorbeeld 11.2 - Het toevoegen aan een bestand*

### Fstream

Voor het lezen en schrijven van bestanden hebben we een library nodig: `fstream`. Deze
wordt in *codevoorbeeld 11.1* en in *codevoorbeeld 11.3* in de regel `#include <fstream>` geïmporteerd.
Fstream staat voor "file stream".

### Ofstream

Voor het openen van het bestand moeten we een output stream aanmaken. Dit gebeurt in *codevoorbeeld 11.1* door een variabele van het type `ofstream` aan te maken. Ofstream staat voor “ouput file stream”.

### <<

Na het openen `(.open())` van de output stream kunnen we naar het bestand schrijven op
dezelfde wijze als we eerder hebben gezien bij het sleutelwoord `cout`.
Pas op: pas na het sluiten `(.close())` weten we zeker dat tekst in het bestand zit en pas na het sluiten kunnen andere processen toegang krijgen tot het bestand.

## Bestand lezen

Het lezen van een bestand gaat vergelijkbaar als met het vragen van input aan de gebruiker. In beide gevallen kunnen we `cin` gebruiken om de informatie in een
variabele te stoppen. Met bestanden is het echter makkelijker om met `getline()` te werken (zie [Getline](#getline) voor getline() met gebruikers input).

In *codevoorbeeld 11.3* zien we een voorbeeld van code waarbij een bestand wordt ingelezen en op het scherm
wordt afgedrukt.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    ifstream myfile ("example.txt");

    if (myfile.is_open()){
        while ( getline (myfile, line) ){
            cout << line << '\n';
        }
        myfile.close();
    }else{
        cout << "Unable to open file";
    }
}
```

*Codevoorbeeld 11.3 - Het schrijven van een bestand*

### Ifstream

Voor het openen van het bestand moeten we een input stream aanmaken. Dit gebeurt in *codevoorbeeld 11.3* door een variabele van het type `ifstream` aan te maken.
Ifstream staat voor “input file stream”.

### Meer informatie

Meer informatie over file input en output kun je vinden op: <http://www.cplusplus.com/doc/tutorial/files/>.
