# Patronen[](title-id) <!-- omit in toc -->

## Inhoud[](toc-id) <!-- omit in toc -->

- [Introductie](#introductie)
- [Design Patterns](#design-patterns)
- [Informatie uit en over één rij](#informatie-uit-en-over-één-rij)
- [Informatie uit een rij](#informatie-uit-een-rij)
- [Break](#break)
- [De gezochte informatie](#de-gezochte-informatie)
- [Return i](#return-i)
- [Return -1](#return--1)
- [Informatie over een rij](#informatie-over-een-rij)
- [Zinnige beginwaarde](#zinnige-beginwaarde)
- [Waarden omwisselen](#waarden-omwisselen)
- [tmp](#tmp)
- [Informatie uit en over een rij van rijen](#informatie-uit-en-over-een-rij-van-rijen)
- [Informatie uit een rij van rijen](#informatie-uit-een-rij-van-rijen)
- [Size()](#size)
- [Informatie over een rij van rijen](#informatie-over-een-rij-van-rijen)
- [Andere design patterns](#andere-design-patterns)

---

## Introductie

Als we programmeren zien we vaak dezelfde situaties. De variabelenamen, de context
en de waarden zijn meestal wel anders, maar **veel problemen die we willen oplossen lijken op elkaar**. Als we een probleem herkennen als iets wat we al eerder hebben
opgelost wordt het programmeren een stuk makkelijker. We kunnen dan dezelfde
oplossing gebruiken. Deze oplossingen noemen we patronen.

## Design Patterns

Als je in de praktijk met grotere
problemen aan de slag gaat kun je meestal het grote probleem opsplitsen in kleinere problemen waarvan je de oplossingen (de patronen) weet.
In dit hoofdstuk behandelen we enkele patronen die je als programmeur veel tegenkomt. Zulke patronen (design patterns) overstijgen de taal C++. Zulke patronen zijn ook toepasbaar als je programmeert in Python, Java of een andere procedurele of object georiënteerde taal.

## Informatie uit en over één rij

In veel programma’s en/of functies is het doel om informatie uit een rij (in C++ een
vector of string) te halen of om informatie te berekenen over een rij heen.
In deze gevallen weet je zeker dat je een for-loop nodig hebt. Afhankelijk van of je de
informatie uit een rij wilt of over een rij wilt berekenen is het patroon net iets anders.

## Informatie uit een rij

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

```cpp
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

## Break

Als we een getal hebben gevonden dat groter is dan 5 is het niet meer nodig om de rest van de getallen te bekijken. We waren immers op zoek naar de index van het eerste getal groter dan 5. We stoppen daarom de for-loop met een break.

## De gezochte informatie

We willen de gezochte informatie buiten de for-loop kunnen gebruiken. Hiervoor maken we voor de for-loop een variabele aan waarin we de informatie kunnen opslaan als we die gevonden hebben.
In codevoorbeeld 9.1 is dat de variabele *index*. We geven deze variabele als startwaarde een gekke waarde (een index van -1 kan niet in C++).
Deze gekke waarde geeft ons de mogelijkheid om makkelijk te herkennen dat de informatie die we zoeken niet in de rij staat.
Stel dat er in de rij geen getal groter dan 5 zit. In dat geval gaan we met de for-loop de gehele
rij af, maar veranderen we de variabele index niet. Na de for-loop bevat de variabele index dan nog steeds zijn gekke startwaarde -1.

Als we deze for-loop in een functie zetten, dan hebben we geen variabele nodig om de gevonden waarde in op te slaan.
Dit zien we in codevoorbeeld 9.2.

```cpp
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

## Return i

Met return i geven we de gezochte informatie terug. Als een return wordt aangeroepen,
dan stopt de functie gelijk en wordt de waarde teruggeven. Aangezien de functie gelijk
stopt, stopt ook de for-loop direct.

## Return -1

Wederom kan het zijn dat in de rij geen getal zit dat groter is dan 5. In dat geval wordt de hele for-loop doorlopen zonder dat er iets wordt gereturnd. Om aan de gebruiker duidelijk te maken dat we de gezochte informatie niet hebben gevonden geven we een gekke waarde terug: -1.

## Informatie over een rij

Een andere situatie die we met programmeren tegenkomen als we één rij hebben is dat we informatie over de gehele rij willen hebben.

Voorbeelden hiervan zijn:

- het bepalen van het maximum van een rij getallen
- het bereken van het gemiddelde van een rij getallen;
- het verzamelen van alle negatieve getallen van de rij;
- het tellen van het aantal ’b’-tjes in een string.

De oplossing voor dergelijke vragen bestaat altijd uit een for-loop. We beginnen met het definiëren van een resultaat-variabele waarin we de uitkomst opslaan. Deze moeten we een zinnige startwaarde geven. Daarna start een for-loop over de gehele rij. Binnen in de for-loop moeten we aangeven hoe we de resultaat variabele updaten. Afhankelijk van het probleem gebeurt het updaten elke keer of alleen als er wordt voldaan aan de conditie van een if-statement.

In *codevoorbeeld 9.3* zien we dit uitgewerkt voor het bepalen van de maximale waarde uit een vector\<int\>. In *codevoorbeeld 9.4* zien we het bepalen van de frequentie van een letter in een string.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> n){
  int max = n[0]; // variable to save the result

  for(unsigned int i=1; i<n.size(); i++){
    if(max < n[i]){ // when to update the result variable
      max = n[i]; // update the result-variable
    }
  }
  return max; // return the result
}

int main(){
  vector<int> numbers = {5,8,2,4,9,2};
  int m = max(numbers);
  cout << "m: " << m << "\n";

  // output:
  // m: 9
}
```

*Codevoorbeeld 9.3 - Een max-functie*

```cpp
#include <iostream>
#include <string>
using namespace std;

int count(string s, char c){
  int count = 0; // variable to save the result
  for(unsigned int i=0; i<s.size(); i++){
    if(s[i] == c){ // when to update the result-variable
      count++; // update the result-variable
    }
  }
  return count; // return the result
}

int main(){
  string text = "En je hoeft niet te tanken!";
  int count_e = count(text, 'e');
  cout << "count_e: " << count_e << "\n";

  // output:
  // count_e: 5
}
```

*Codevoorbeeld 9.4 - Een tel-functie*

## Zinnige beginwaarde

Het is belangrijk dat je de resultaat-variabele op een zinnige waarde laat starten. Bij de functie `count()` in *codevoorbeeld 9.4* zouden we het verkeerde resultaat krijgen als we de variabele count op regel 5 initialiseren met een waarde anders dan 0.

Wat minder overduidelijk is de startwaarde van resultaat-variabele max in de functie `max()` in *codevoorbeeld 9.3*. Als we max zouden initialiseren op de waarde 0, dan zou de functie nog in veel gevallen het goede resultaat geven. Als een rij echter met enkel negatieve getallen aan de functie wordt meegegeven zal de functie
een 0 teruggeven in plaats van het hoogste negatieve getal uit de rij.

## Waarden omwisselen

Als we in een programma twee variabelen van waarden willen omwisselen, dan moeten we voordat we één van de variabelen de nieuwe waarde geven de oude waarde opslaan.
Doen we dit niet dan gaat één van de waarden verloren.
In *codevoorbeeld 9.5* zien we hoe je correct twee variabelen van waarde laat wisselen.

```cpp
#include <iostream>
using namespace std;

void swap(int & a, int & b){
  int tmp = a;
  a = b;
  b = tmp;
}

int main(){
  int a = 6;
  int b = 10;

  swap(a,b);
  cout << "a: " << a << "\n";
  cout << "b: " << b << "\n";

  // output:
  // a: 10
  // b: 6
}
```

*Codevoorbeeld 9.5 - Swappen*

## tmp

De variabele tmp staat voor temporary. Dit is de gebruikelijke naamgeving voor een variabele die enkel dient als tussenvariabele.

## Informatie uit en over een rij van rijen

Gegevens worden vaak opgeslagen in een rij van rijen. In deze sectie bespreken we hoe je uit een rij van rijen informatie haalt of er informatie uit onttrekt.

## Informatie uit een rij van rijen

Voorbeelden van informatie uit een rij van rijen zijn:

- Het controleren van het voorkomen van een letter in een lijst woorden.
- Het vinden van een locatie van een object in een 2D-spel.
- Het vinden van alle witte pixels in een zwart-wit afbeelding.

De aanpak bij een rij van rijen is niet veel anders dan als bij een enkele rij. Het grootste
verschil is dat we nu twee for-loops nodig hebben.

In *codevoorbeeld 9.6* zien we een functie die informatie zoekt in een rij van rijen.

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> findIndexNumberBiggerThan5(vector<vector<int>> m){
  for(unsigned int i=0; i<m.size(); i++){
    for(unsigned int j =0; j<m[i].size(); j++){
      if(m[i][j] > 5){ // information we are searching
        return {int(i), int(j)}; // returning the found information
      }
    }
  }
  return {-1, -1}; // return value when the searched information is not found
}

int main(){
  vector<vector<int>> numbers =
{% raw %}
  {
   {1, 2, 2}, 
   {1, 2, 4, 7, 9},
   {3},
   {4, 2, 4, 2, 9, 3, 2}
   };
{% endraw %}

  vector<int> index = findIndexNumberBiggerThan5(numbers);

  if(index[0] > -1){
    cout
    << "The first index with a number larger than 5 is at: "
    << "(" << index[0] << ", " << index[1] << ")"<< "\n";
  }else{
    cout << "All number are smaller than 5." << "\n";
  }
}
```

*Codevoorbeeld 9.6 - Informatie uit een rij van rijen*

## Size()

In *codevoorbeeld 9.6* zien we dat in een rij van rijen, de rijen verschillende lengte kunnen
hebben. Het is dus belangrijk dat we in de tweede for-loop echt de size opvragen van de juiste rij. In *codevoorbeeld 9.6* gebeurt dat met de code:
`m[i].size()`.

## Informatie over een rij van rijen

Het kan ook voorkomen dat we informatie willen hebben over een rij van rijen.
Voorbeelden hiervan zijn:

- Het gemiddelde van een matrix.
- Het aantal gele pixels in een afbeelding van Spongebob.

De aanpak hiervoor is vergelijkbaar met die van het verkrijgen van informatie over
een rij. Het grootste verschil is dat we nu twee for-loops nodig hebben.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int max(vector<vector<int>> m){
  int max = m[0][0]; // variable to save the result
  for(unsigned int i=0; i<m.size(); i++){
    for(unsigned int j=0; j<m[i].size(); j++){
      if(max < m[i][j]){ // when to update the result-variable
        max = m[i][j]; // update the result-variable
      }
    }
  }
  return max; // return the result
}

int count(vector<string> v_s, char c){
  int count = 0; // variable to save the result
  for(unsigned int i=0; i<v_s.size(); i++){
    for(unsigned int j=0; j<v_s[i].size(); j++){
      if(v_s[i][j] == c){ // condition when the result-variable needs to be updated
        count++; // update the result-variable
      }
    }
  }
  return count; // return the result
}

int main(){
{% raw %}
  vector<vector<int>> numbers = {{5,8},{2,4},{9,2}};
{% endraw %}
  int m = max(numbers);
  vector<string> text = {"En je hoeft niet te tanken!", "030 beter als 020",
  "Ik vind helemaal mooi", "Nou, nee!"};
  int count_e = count(text, 'e');

  cout << "m: " << m << "\n";
  cout << "count_e: " << count_e << "\n";

  // output:
  // m: 9
  // count_e: 11
}

```

*Codevoorbeeld 9.7 - Informatie over een rij van rijen.*

## Andere design patterns

- [Reductie](reductie/README.md)
- [Recursie](recursie/README.md)
- [Decorator pattern](decorator/README.md)
