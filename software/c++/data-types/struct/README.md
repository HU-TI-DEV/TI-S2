# Struct datatype[](title-id) <!-- omit in toc -->

## Inhoud[](toc-id) <!-- omit in toc -->
- [Basis](#basis)
- [Structs en vector](#structs-en-vector)
- [Structs en functies](#structs-en-functies)


Een struct combineert een aantal verschillende waarden tot één geheel. Bij een vector moeten de elementen van hetzelfde type zijn: een vector noemen we daarom een *homogeen datatype*.
Een struct noemen we een *heterogeen datatype*. Bij een struct kunnen de interne variabelen van verschillende types zijn. 
Met een `struct` kunnen we variabelen van
verschillende datatypes combineren. De variabelen binnen een struct noemen we `members`.

## Basis
Een struct maken we met het sleutelwoord `struct`. Daarna geven we het een naam en definiëren in de body (tussen de { en } ) de inhoud van de struct. We sluiten de struct
af met een puntkomma (;). 
In *codevoorbeeld 12.1* staat een voorbeeld van een struct.

```c++
#include <iostream>
#include <string>
using namespace std;

struct artikel{
    int code;
    string naam;
    int voorraad;
}; // ; !

int main(void){
    artikel art1 = {1234,"soldeerbout",8};
    art1.voorraad = 12;
    artikel art2 = {};// the members of art are set to default values
    art2.code = 5555;
    art2.naam = "nijptang";
    art2.voorraad = 14;

    cout
    << "Voorraad van artikel " << art1.code << " (" << art1.naam
    << ") is " << art1.voorraad << "\n";
    cout
    << "Voorraad van artikel " << art2.code << " (" << art2.naam
    << ") is " << art2.voorraad << "\n";

    // output:
    // Voorraad van artikel 1234 (soldeerbout) is 12
    // Voorraad van artikel 5555 (nijptang) is 14
}
```
*Codevoorbeeld 12.1 - struct*

## Structs en vector
Een zelfgemaakte struct kan ook worden opgenomen in een vector. *Codevoorbeeld 12.2* laat dit zien.

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct artikel{
    int code;
    string naam;
    int voorraad;
};

int main(void){
    artikel art1 = {1234, "soldeerbout", 12};
    artikel art2 = {5555,"nijptang",14};
    artikel art3 = {4242,"hammer",65};
    vector<artikel> artikelen = {art1, art2};

    artikelen.push_back(art3);
    cout << "We hebben de volgende artikelen:" << "\n";
    for(unsigned int i=0 ; i < artikelen.size(); i++){
        cout << artikelen[i].naam << "\n";
    }

    // output:
    // We hebben de volgende artikelen:
    // soldeerbout
    // nijptang
    // hammer
}
```
*Codevoorbeeld 12.2 - structs en vectoren*

## Structs en functies
Structs kunnen, net als andere datatypes, als parameter worden meegeven aan een functie en terggegeven worden door een functie. Dit wordt zichtbaar gemaakt in *codevoorbeeld 12.3*.

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct artikel{
    int code;
    string naam;
    int voorraad;
};

struct gereedschap{
    string naam;
    vector<string> eigenaars;
};

gereedschap setEigenaars(const artikel & a, const vector<string> & eig){
    gereedschap g = {a.naam, eig};
    return g;
}

int main(void)
{
    artikel art1 = {1234,"soldeerbout",12};
    vector<string> eig = {"Joop", "Wouter", "Jorn", "Arno"};

    gereedschap ger1 = setEigenaars(art1, eig);
    cout << "De volgende mensen zijn eigenaar van een " << ger1.naam << ":" << "\n";

    for(unsigned int i=0 ; i < ger1.eigenaars.size(); i++){
        cout << ger1.eigenaars[i] << "\n";
    }

    // output:
    // De volgende mensen zijn eigenaar van een soldeerbout:
    // Joop
    // Wouter
    // Jorn
    // Arno
}
```
*Codevoorbeeld 12.3 - structs en functies*