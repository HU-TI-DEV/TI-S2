# Recursie[](title-id) <!-- omit in toc -->

## Inhoud[](toc-id) <!-- omit in toc -->

- [Recursie](#recursie)
  - [Droste effect](#droste-effect)
  - [Andere voorbeelden](#andere-voorbeelden)
  - [Aanpak](#aanpak)
    - [Voorbeeld: ga naar huis](#voorbeeld-ga-naar-huis)
  - [Voorbeeld: faculteit](#voorbeeld-faculteit)
    - [Faculteit (factorial)](#faculteit-factorial)
    - [0! = 1](#0--1)
    - [Recursie in faculteit](#recursie-in-faculteit)
- [Het werkt al](#het-werkt-al)
- [Basisgevallen](#basisgevallen)
  - [Meerdere basisgevallen](#meerdere-basisgevallen)
- [Recursieve functie’s bouwen](#recursieve-functies-bouwen)
- [Stappenplan](#stappenplan)
  - [Basisgevallen bouwen](#basisgevallen-bouwen)
  - [De eerste stap](#de-eerste-stap)
  - [De volgende stap](#de-volgende-stap)
  - [De recursiestap](#de-recursiestap)
- [Het uitvoeren van recursieve code](#het-uitvoeren-van-recursieve-code)

## Recursie

Recursie is een speciale krachtige vorm van [reductie](../reductie/README.md). Net als bij reductie splitsen
we het grote probleem op in kleinere deelproblemen.
Het verschil is dat de kleinere
deelproblemen bij recursie *vergelijkbaar* zijn met het originele grote probleem. *We
kunnen de kleinere deelproblemen dus op dezelfde manier oplossen.* We kunnen
voor de deelproblemen dezelfde functie gebruiken als voor het grote probleem!

### Droste effect

Het Droste-effect is een visueel effect, waarbij een afbeelding een verkleinde versie van zichzelf bevat. Dit is **een visuele vorm van recursie**.
In de afbeelding, waar het effect haar naam aan dankt, zien we een vrouw die een blik vasthoudt. Op het blik bevindt zich een kleiner plaatje waarop de vrouw staat met hetzelfde blik. Dat blik bevat ook weer een kleinere afbeelding van haar met het blik, etc.
Een deel van het plaatje is dus gedefinieerd als het plaatje zelf.

![Droste cacao-blik uit 1904. Ontwerp: Jan Misset](./img/droste.png)

*Figuur 14.1 - Droste cacao-blik uit 1904. Ontwerp: Jan Misset*

Een robot die de vrouw met het blik kan tekenen moet het tekenen steeds herhalen.
Het enige dat verandert is dat de robot de afbeelding steeds kleiner moet tekenen. Het grote probleem (de tekening), reduceren we tot de drie deelproblemen:

- het tekenen van de vrouw,
- het tekenen van het blik en
- het tekenen van dezelfde tekening.

Het laatste deelprobleem laat zich makkelijk oplossen: Onze robot kan dit al! De robot moet
enkel zichzelf de opdracht gegeven om de tekening nog een keer te maken, maar dan
kleiner. Dit noemen we *recursie*.

### Andere voorbeelden

Het Droste-effect is één van de bekendste voorbeelden van recursie, maar zeker niet het enige:

1. De afkorting van de programmeertaal PHP bevat recursie. PHP staat namelijk voor "PHP: Hypertext Preprocessor.
2. Je krijgt een interessante maar niet echt hulpvolle suggestie als je [recursion in Google](https://www.google.com/search?q=recursion) intypt.
3. Je kunt prachtige afbeeldingen krijgen met [fractals](https://en.wikipedia.org/wiki/Fractal).
4. [Matroesjka poppen](https://en.wikipedia.org/wiki/Matryoshka_doll) bevatten een kleinere versie van zichzelf.

### Aanpak

Recursie kan aan het begin moeilijk en ingewikkeld aanvoelen. Het kan helpen om te
zien dat recursie grofweg uit twee stappen bestaat:

1. Als het gegeven geval van het probleem klein of simpel is: los het probleem op
2. anders:
(a) reduceer het probleem door een simpele handeling uit te voeren.
(b) los de rest van het probleem op als zijnde één of meer kleinere gevallen van het zelfde probleem.

#### Voorbeeld: ga naar huis

We zien recursie veel in programmeren, maar we kunnen het ook toepassen op
problemen in ons eigen leven. Zo kan de taak "ga naar huis" gedefinieerd worden als:

1. Als je thuis bent: stop met bewegen.
2. anders:
(a) Zet één stap richting je huis.
(b) start de taak "ga naar huis".

### Voorbeeld: faculteit

In *codevoorbeeld 14.1* zien we recursie toegepast in een functie om de faculteit van een getal te berekenen. Bij het berekenen van de faculteit is een geval van het probleem klein of simpel als het gegeven getal kleiner of gelijk is aan 1. In dat geval
is het antwoord 1. (zie regels 5 en 6 in codevoorbeeld 14.1). In alle andere gevallen reduceren we het probleem tot een kleinere geval van het probleem. We laten de functie de faculteit van x-1 berekenen en doen dat keer x (zie regel 7 in codevoorbeeld
14.1). Immers x! is gelijk aan x * ((x-1)!). 6

#### Faculteit (factorial)

De faculteit van een getal is het product van alle positieve integers kleiner of gelijk aan het gegeven getal.
Voor faculteit gebruiken we in de wiskunde het !-teken. De faculteit van 4 schrijven we als: `4!`.
Bijvoorbeeld: `5! = 5 * 4 * 3 * 2 * 1` oftewel 5! = 120.

#### 0! = 1

De faculteit van het getal 0 heeft een bijzondere waarde: 0! is 1, volgens de definitie van het lege product.

#### Recursie in faculteit

5! is gelijk aan 5 *4* 3 *2* 1 (=120).
4! is gelijk aan 4 *3* 2 *1 (=24).
Als we dit combineren kunnen we zeggen dat 5! = 5* (4!).

```cpp
#include <iostream>
using namespace std;

int factorial(int x){
   if(x <= 1)
      return 1;
   return x * factorial(x-1);
}

int main(){
   int answer = factorial(8); // == 8*7*6*5*4*3*2*1
   int zeroAnswer = factorial(0); // == 1
   int oneAnswer = factorial(1); // == 1
   int anotherAnswer = factorial(3); // == 3*2*1

   cout << "answer: " << answer << "\n";
   cout << "zeroAnswer: " << zeroAnswer << "\n";
   cout << "oneAnswer: " << oneAnswer << "\n";
   cout << "anotherAnswer: " << anotherAnswer << "\n";

   //output:
   // answer: 40320
   // zeroAnswer: 1
   // oneAnwser: 1
   // anotherAnswer: 6
}
```

*Codevoorbeeld 14.1 - Recursieve functie om de faculteit te berekenen*

## Het werkt al

Interessant aan het schrijven van een recursieve functie is dat we tijdens het schrijven
eigenlijk *aannemen dat de functie al werkt*. Net als bij reductie zijn we enkel geïnteresseerd in wat de functie teruggeeft en kan het ons (even) niks schelen hoe het is geïmplementeerd. Ook dat de functie nog niet geïmplementeerd is (en dus nog niet
werkt) leggen we naast ons neer.
We nemen aan dat de recursie-fee voor ons een werkende versie van de functie heeft gemaakt.

## Basisgevallen

Als in recursie een geval van het probleem simpel is of niet kan worden opgesplitst in meerdere deelproblemen, dan lost de functie het geval gelijk op. Zulke gevallen noemen we basisgevallen.

In *codevoorbeeld 14.1* is het basisgeval `x <= 1`. De oplossing voor dat basisgeval is `return 1`.
In de taak [ga naar huis](#voorbeeld-ga-naar-huis), die we eerder in dit hoofdstuk zagen, is het basisgeval “als je thuis bent”.
De oplossing voor dat basisgeval is "stop met bewegen".

### Meerdere basisgevallen

Een recursieve functie kan meerdere basisgevallen hebben. In basisgevallen eindigt
de functie altijd. In de niet-basisgevallen roept de functie zichzelf nog een keer aan.

*Als het zichzelf aanroepen van de functie verwarrend is, dan kan kan het helpen om voor te stellen
dat iemand anders de simpelere versie van het probleem gaat oplossen. De recursie-fee kan voor jou die
rol vervullen. Jouw taak wordt om het originele probleem te versimpelen tot kleinere gevallen van het
probleem of om het probleem direct op te lossen als het onnodig of onmogelijk is om het op te splitsen
in kleinere problemen. De recursie-fee zal op magische wijze zorgen dat alle simpele kleinere gevallen
van het probleem worden opgelost.*

Basisgevallen zie je meestal in de functie terug als een set if-statements aan het begin
van de functie.

## Recursieve functie’s bouwen

In eerdere colleges en cursussen heb je vooral geleerd om te programmeren met *while- en for-loops*. Het programmeren met recursie vraagt
een andere manier van denken. Dit maakt dat het snel en makkelijk kunnen werken met recursie oefening vergt, net zoals het aan het begin oefening kostte om te werken met while- en for-loops. Oefenen helpt: kijk eens naar de opdrachten van je eerste programmeercursus. Opdrachten die je
toen moeilijk vond, maak je nu waarschijnlijk vrij snel.

## Stappenplan

Als je start met het maken van recursieve functies kan het fijn zijn om het volgende stappenplan aan te houden:

1. Neem aan dat je functie al werkt.
2. Bedenk: in welke gevallen weet je gelijk het antwoord? Bouw hieruit je basisgevallen.
3. Stel je zit niet in een basisgeval. Bedenk welke stap je kunt zetten om iets dichter bij een basisgeval te komen. Bouw hieruit de recursieve stap.
4. De functie werkt (Hoera!). Controleer nu:
(a) Zijn alle basisgevallen nog nodig?
(b) Kun je een deel van de functie optimaliseren?

### Basisgevallen bouwen

Dit stappenplan kunnen we toepassen op het schrijven van een functie om *de som van de waarden van een integer vector te bepalen*. In codevoorbeeld 14.2 staat de functie die we krijgen door stap 1, 2 en 3 te doorlopen.

### De eerste stap

De eerste stap is om te bedenken in welke gevallen we direct het antwoord weten. Dit kunnen we doen door te kijken naar wanneer het “probleem” klein is. In dit geval gaat het probleem over een vector. Het probleem is klein als de vector klein is. *De kleinst mogelijke
vector is een lege vector.*
De som van een lege vector is gelukkig simpel, want dat is altijd 0. Daarmee hebben we ons eerste basisgeval.

### De volgende stap

Na de lege vector is het kleinste probleem *een vector met één getal erin*. Ook dan weten we direct wat we moeten teruggeven. De som van een vector met één getal is dat ene getal. In *codevoorbeeld 14.2* zien we de basisgevallen uitgewerkt.

### De recursiestap

Als we onze vector, en dus ons geval van het probleem, groter maken, wordt een directe oplossing ingewikkelder. In plaats van dat we direct één waarde terug kunnen geven moeten we nu een berekening doen: de getallen in de vector bij elkaar optellen. Dit wijst erop dat we waarschijnlijk geen andere basisgevallen hebben.

Stap 2 van het stappenplan zegt dat we moeten gaan bedenken *hoe we een stap dichter bij één van de basisgevallen kunnen komen*. Onze basisgevallen gaan over de kleinste vectoren. Dus als we een grotere
vector hebben moeten we zorgen dat de stap die we zetten ervoor zorgt dat de vector kleiner wordt. Als we dit willen doen moeten we in ieder geval één getal uit de vector halen. Dit getal moeten we optellen bij de som van de resterende vector.
Optellen kunnen we gelukkig makkelijk doen met de +-operator.
Hadden we nu maar een manier om de som te bepalen van de rest van de vector. . .
O. . .wacht die hebben we, want die functie zijn we aan het schrijven.

Hiermee wordt de recursiestap dat we één
getal van de vector optellen bij de som van de rest van de vector. Om de som van de rest van de vector te bepalen gebruiken we de functie sum(). In *codevoorbeeld 14.2* is dit uitgewerkt. We gebruiken de variabele *size* om de vector (kunstmatig)
steeds één stapje kleiner te maken: We tellen het laatste element uit numbers op bij de
som van dezelfde rij waarvan we zeggen dat de lengte (size) nu eentje kleiner is.

```cpp
#include <iostream>
#include <vector>
using namespace std;

sum(const vector<int> & numbers, int size){
   if (size <= 0)
      return 0;
   if (size == 1)
      return numbers[0];
   return numbers[size-1] + sum(numbers, size-1);
}
int main(){
   vector<int> a = {5,2,3,2,3};
   int anwser = sum(a, a.size());

   cout << "anwser: " << anwser << "\n";
   
   // output:
   // answer: 15
}
```

*Codevoorbeeld 14.2 - Een recursieve functie om de sum van een vector te berekenen*

###Controle

Het gebeurt bij recursie vaak dat als je aan het programmeren bent je soms een basisgeval te veel hebt bedacht. Met “te veel” bedoelen we dat de functie ook zou werken voor alle gevallen van het probleem zonder dat basisgeval.

De recursieve functie `sum()` uit *codevoorbeeld 14.2* heeft een basisgeval te veel. De recursieve
functie `sum()` uit *codevoorbeeld 14.3* heeft één basisgeval minder, maar werkt ook.

De functie `sum()` in *codevoorbeeld 14.3* is **mooier en leesbaarder**. Bovendien is de functie **sneller**, omdat hij één if-statement per getal minder in de vector hoeft te doorlopen. Dit zou bij een kleine
vector weinig verschil maken, maar aangezien we in de praktijk vaak met gigantische datasets of met kleinere langzamere computers werken kan dit veel tijd schelen. Als je een recursieve functie schrijft, sla dan stap 4 niet over: controleer je code. Misschien kun je je functie wel verbeteren.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<int> & numbers, int size){
   if (size <= 0)
      return 0;
   return numbers[size-1] + sum(numbers, size-1);
}

int main(){
   vector<int> a = {5,2,3,2,3};

   int anwser = sum(a, a.size());
   cout << "anwser: " << anwser << "\n";

   // output:
   // answer: 15
}
```

*Codevoorbeeld 14.3 - Een recursieve functie om de sum van een vector te berekenen*

## Het uitvoeren van recursieve code

Wat doet de computer eigenlijk als we onze code met recursie van codevoorbeeld 14.3 draaien?
Wil je meer lezen over recursie lees dan sectie [Recursie](../recursie/README.md).
