# Patronen

### Inhoud[](toc-id)
- [Patronen](#patronen)
    - [Inhoud](#inhoud)
  - [Introductie](#introductie)
    - [Design Patterns](#design-patterns)
  - [Informatie uit en over één rij](#informatie-uit-en-over-één-rij)
    - [Informatie uit een rij](#informatie-uit-een-rij)
    - [Break](#break)
    - [De gezochte informatie](#de-gezochte-informatie)
    - [Return i](#return-i)
    - [Return -1](#return--1)
- [Todo: p. 55 en verder toevoegen](#todo-p-55-en-verder-toevoegen)

---

## Introductie
Als we programmeren zien we vaak dezelfde situaties. De variabelenamen, de context
en de waarden zijn meestal wel anders, maar **veel problemen die we willen oplossen lijken op elkaar**. Als we een probleem herkennen als iets wat we al eerder hebben
opgelost wordt het programmeren een stuk makkelijker. We kunnen dan dezelfde
oplossing gebruiken. Deze oplossingen noemen we patronen. 

### Design Patterns
Als je in de praktijk met grotere
problemen aan de slag gaat kun je meestal het grote probleem opsplitsen in kleinere problemen waarvan je de oplossingen (de patronen) weet. 
In dit hoofdstuk behandelen we enkele patronen die je als programmeur veel tegenkomt. Zulke patronen (design patterns) overstijgen de taal C++. Zulke patronen zijn ook toepasbaar als je programmeert in Python, Java of een andere procedurele of object georiënteerde taal.

## Informatie uit en over één rij
In veel programma’s en/of functies is het doel om informatie uit een rij (in C++ een
vector of string) te halen of om informatie te berekenen over een rij heen. 
In deze gevallen weet je zeker dat je een for-loop nodig hebt. Afhankelijk van of je de
informatie uit een rij wilt of over een rij wilt berekenen is het patroon net iets anders.

### Informatie uit een rij
Bij problemen in deze categorie ben je : 
- op zoek naar een bepaalde waarde in een rij, 
- op zoek naar naar de index van een bepaalde waarde in een rij of 
- aan het controleren of alle elementen in een rij voldoen aan een bepaalde voorwaarde. 


Enkele voorbeelden hiervan zijn:
  - controleren of een rij getallen enkel uit positieve getallen bestaat
  - het vinden van de index van de eerste keer dat de character ‘a’ in een string voorkomt
  - het vinden van het eerste getal dat groter is dan 10, maar kleiner is dan 15.

Het patroon bestaat uit een for-loop over de gehele rij, een if-statement (of if/elsestatements)
en het teruggeven van de gezochte informatie. 
In codevoorbeeld 9.1 zien we deze structuur toegepast om de index van het eerste getal te vinden dat groter is dan 5.

```c++
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> numbers = {1,3,4,7,2,9,6};

  int index = -1; // variabele to save the searched information
  for(unsigned int i=0; i<numbers.size(); i++){
    if(numbers[i] > 5){ // information we are searching
      index = i; // save the found information
      break;
    }
  }
  if(index > -1){
    cout
    << "The first index with a number larger than 5 is at: "
    << index << "\n";
  }else{
    cout << "All numbers are smaller than 5." << "\n";
  }

  // output:
  // The first index with a number larger than 5 is at: 3
}
```
*Codevoorbeeld 9.1 - Informatie uit een rij 1*

### Break
Als we een getal hebben gevonden dat groter is dan 5 is het niet meer nodig om de rest van de getallen te bekijken. We waren immers op zoek naar de index van het eerste getal groter dan 5. We stoppen daarom de for-loop met een break.

### De gezochte informatie
We willen de gezochte informatie buiten de for-loop kunnen gebruiken. Hiervoor maken we voor de for-loop een variabele aan waarin we de informatie kunnen opslaan als we die gevonden hebben. 
In codevoorbeeld 9.1 is dat de variabele *index*. We geven deze variabele als startwaarde een gekke waarde (een index van -1 kan niet in C++). 
Deze gekke waarde geeft ons de mogelijkheid om makkelijk te herkennen dat de informatie die we zoeken niet in de rij staat. 
Stel dat er in de rij geen getal groter dan 5 zit. In dat geval gaan we met de for-loop de gehele
rij af, maar veranderen we de variabele index niet. Na de for-loop bevat de variabele index dan nog steeds zijn gekke startwaarde -1.

Als we deze for-loop in een functie zetten, dan hebben we geen variabele nodig om de gevonden waarde in op te slaan. 
Dit zien we in codevoorbeeld 9.2.

```c++
#include <iostream>
#include <vector>
using namespace std;

int findIndexNumberBiggerThan5(vector<int> n){
  for(unsigned int i=0; i<n.size(); i++){
    if(n[i] > 5){ // information we are searching
      return i; // returning the found information
    }
  }
  return -1; // return value when the searched information is not found
}

int main(){
  vector<int> numbers = {1,3,4,7,2,9,6};

  int index = findIndexNumberBiggerThan5(numbers);
  if(index > -1){
    cout
    << "The first index with a number larger than 5 is at: "
    << index << "\n";
  }else{
    cout << "All numbers are smaller than 5." << "\n";
  }

  // output:
  // The first index with a number larger than 5 is at: 3
}
```
*Codevoorbeeld 9.2 - Informatie uit een rij 2*

### Return i
Met return i geven we de gezochte informatie terug. Als een return wordt aangeroepen,
dan stopt de functie gelijk en wordt de waarde teruggeven. Aangezien de functie gelijk
stopt, stopt ook de for-loop direct.

### Return -1
Wederom kan het zijn dat in de rij geen getal zit dat groter is dan 5. In dat geval wordt de hele for-loop doorlopen zonder dat er iets wordt gereturned. Om aan de gebruiker duidelijk te maken dat we de gezochte informatie niet hebben gevonden geven we een gekke waarde terug: -1.

# Todo: p. 55 en verder toevoegen
