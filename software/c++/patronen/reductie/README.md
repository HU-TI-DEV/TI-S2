# Reductie[](title-id)

## Inhoud[](toc-id)
- [Reductie](#reductie)
  - [Inhoud](#inhoud)
  - [Reductie](#reductie-1)
    - [Reductie in ons leven](#reductie-in-ons-leven)
      - [Reductie in programmeren](#reductie-in-programmeren)


In de kunst van het programmeren gebruiken we meerdere patronen. Deze patronen helpen om (deel)oplossingen te herkennen, om structuur te brengen in grote lappen
code en in nadenken over onze oplossingen. In [Patronen](#patronen) hebben we patronen
besproken voor het werken met vectoren. 

In dit hoofdstuk gaan we het hebben over
een patroon dat kan helpen in het nadenken over oplossingen: reductie.

## Reductie
Programmeren is niet altijd makkelijk. Vooral niet als het einddoel heel groot is. We
maken het onszelf makkelijker **als we grote problemen splitsen in kleinere deelproblemen**.
Dit noemen we reductie. 

In deze sectie behandelen we reductie en hoe het ons
kan helpen om bij een oplossing te komen.

### Reductie in ons leven
Reductie is een tactiek die we in ons leven dagelijks toepassen. Als we boodschappen willen gaan doen dan verwerken we niet in één keer het gehele probleem, maar splitsen het op in deelproblemen:
- Van huis naar een supermarkt reizen
- Boodschappen in winkelwagen stoppen
- Afrekenen
- Van de supermarkt naar huis reizen.

Het opsplitsen van een probleem in deelproblemen geeft ons drie voordelen. 
- Het eerste voordeel is dat als we nadenken over het oplossen van een deelprobleem **ons probleemgebied kleiner en duidelijker afgebakend is**. Dit maakt het makkelijker om er over na te denken: we weten nu dat het reizen naar een supermarkt los staat van het afrekenen. Tijdens het
reizen houden we ons dus niet bezig met hoe we onze pinpas gaan gebruiken.
- Het tweede voordeel is dat het nu makkelijker is om over het grote probleem na te denken. Voor het uiteindelijke grote probleem van boodschappen doen maakt de implementatie van de functie `reisNaarSupermarkt()` niet uit. Zolang het zijn doel
(het naar een supermarkt gaan) maar bereikt. We kunnen hierdoor over het grotere probleem denken in grotere stappen, **zonder ons zorgen te maken over de details**. Ook betekent dit dat we de implementatie van `reisNaarSupermarkt()` **aan iemand anders
over kunnen laten**; bijvoorbeeld aan een taxi-chauffeur.
- Het laatste voordeel is dat als we de functie slim schrijven, we de functie kunnen
**hergebruiken voor andere problemen**. We kunnen de functie `reisNaarSupermarkt()` herformuleren zodat het de locatie mee krijgt als parameter: `reisNaar(supermarkt)`.
We kunnen de functie dan misschien ook gebruiken voor als we gaan sporten:
`reisNaar(sportschool)`.


#### Reductie in programmeren
Met programmeren splitsen we onze problemen op in kleinere deelproblemen. Dit heb je al meerdere keren gedaan. Zo gebruiken we als we werken met vectoren de
functie `.size()`(zie sectie Vector [Functies](#functies)). 
Met het gebruik van de size functie passen we reductie toe. 
- In de oplossing die we aan het maken zijn hebben we de lengte van de vector nodig (deelprobleem). 
- We weten dat we die kunnen krijgen door middel van de
`.size()`-functie. 
- We denken niet na over de implementatie van de `.size()`-functie; enkel over wat hij teruggeeft. 
- We nemen aan dat de functie goed werkt!

De `.size()`-functie is een functie gegeven bij een library in C++, maar we kunnen natuurlijk ook zelf functies schrijven.
In *codevoorbeeld 14.1.1* zien we een oplossing
voor het grote probleem van **het tellen van hoe vaak het hoogste cijfer voor een tentamen gehaald is**. Hierbij is het probleem gesplitst in meerdere deelproblemen/oplossingen/functies. Dit maakt het makkelijker om over de oplossing na te denken. Daarnaast is het voordeel dat we nieuwe functies `maxValue()` en `countValue()` kunnen hergebruiken voor andere problemen.

De functie `maxValue()` kunnen we bijvoorbeeld hergebruiken voor het berekenen van
hoeveel goedkoper onze winkel een product aanbiedt dan de duurste concurrent. Dit heeft als deelproblemen:
- vind de prijzen van de concurrenten, 
- bepaal de hoogste prijs bij de
concurrenten, 
- vind de winkelprijs, 
- bepaal het verschil tussen winkelprijs en hoogste prijs bij de concurrenten. 
Voor het bepalen van de hoogste prijs zou de functie maxValue() hergebruikt kunnen worden.

Programmeren wordt wel eens de kunst van het reduceren genoemd.


```c++
#include <iostream>
#include <vector>
using namespace std;

int maxValue(vector<int> numbers){
  int max = numbers[0];

  for(unsigned int i=1; i < numbers.size(); i++){
    if(numbers[i] > max){
      max = numbers[i];
    }
  }
  return max;
}

int countValue(vector<int> numbers, int value){
  int count = 0;

  for(unsigned int i=0; i<numbers.size(); i++){
    if(numbers[i] == value){
      count++;
    }
  }
  return count;
}

int countMax(vector<int> numbers){
  int max = maxValue(numbers);
  int count = countValue(numbers, max);
  
  return count;
}

int main(){
  vector<int> grades = {7,8,6,9,7,8,5,9,9,6,7};

  int freqMax = countMax(grades);
  cout << "freqMax: " << freqMax << "\n";

  //output:
  // freqMax: 3
}
```
*Codevoorbeeld 14.1.1 - Reductie bij tellen van het hoogste cijfer*