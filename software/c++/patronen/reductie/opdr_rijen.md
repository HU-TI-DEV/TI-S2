# Opdrachten Reductie - rijen C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdrachten Reductie - rijen C++](#opdrachten-reductie---rijen-c)
    - [Inhoud](#inhoud)
  - [Opdracht 3.3 Print doolhof](#opdracht-33-print-doolhof)
    - [Opdracht 3.5 Gemiddelde 1](#opdracht-35-gemiddelde-1)
    - [Opdracht 3.6 Gemiddelde 2](#opdracht-36-gemiddelde-2)
    - [Opdracht 3.12 — Voetbalteam](#opdracht-312--voetbalteam)


## Opdracht 3.3 Print doolhof
Een doolhof is gepresenteerd als een *matrix* (een vector van integer vectoren), waarbij
- 0 een veilige plek aangeeft, 
- 1 het einddoel aangeeft en 
- -1 muren en boze eekhoorns aangeeft.

Schrijf een **functie** die de matrix met de waarden 1, 0 en -1 afdrukt. Waarbij de -1 wordt
afgedrukt als een ’x’. 

Voorbeeld van een matrix mat:
```cpp
vector<vector<int>> mat = {
     {-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1},
     {-1, 0,-1, 0, 0, 0,-1,-1, 0,-1,-1},
     {-1, 0,-1, 0,-1,-1,-1, 0, 0, 1,-1},
     {-1, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1},
     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };
```
Uitvoer na afdrukken van de matrix mat:
```console
x0xxxxxxxxx
x0x000xx0xx
x0x0xxx001x
x0000000xxx
xxxxxxxxxxx
```

### Opdracht 3.5 Gemiddelde 1
Schrijf een functie die van een gegeven `vector<int>` het gemiddelde berekent en teruggeeft.

### Opdracht 3.6 Gemiddelde 2
Schrijf een functie die van een gegeven `vector<vector<int>>` het gemiddelde berekent
van de *gehele* `vector<vector<int>>` en deze teruggeeft.
Tip: maak gebruik van je code uit opdracht 3.5.

### Opdracht 3.12 — Voetbalteam
Een groep wiskundigen besluit mee te doen aan een 9-tegen-9-voetbaltoernooi. Na analyse van eerdere wedstrijden wordt besloten dat de beste opstelling drie rijen van drie is. 

Om de tegenstanders te verwarren en omdat hun teamnaam ‘the Transposers’ is, besluiten de wiskundigen om tijdens de wedstrijden af en toe de opstelling te transponeren.

Schrijf een **functie** die de getransponeerde matrix van de opstelling kan berekenen. 
- Een getransponeerde matrix is een matrix die gespiegeld is over zijn hoofddiagonaal. Met andere
woorden, de functie moet van matrix m het element `m[i][ j]` verwisselen met het element `m[ j][i]`.
- De functie moet ook werken voor andere matrixen. - Je mag aannemen dat de kolommen even lang zijn als de rijen. 
- Laat het programma de getransponeerde matrix
afdrukken.

Voorbeeld. Gegeven de matrix *team*:
```cpp
vector<vector<int>> team = { 
    {1,2,3},
    {4,5,6},
    {7,8,9} };
```
Dan is de output van het programma:
```console
1,4,7,
2,5,8,
3,6,9,
```

Eisen:
- Je mag in de functie geen nieuwe matrix aanmaken. - Je mag wel gebruik maken van een tijdelijke variabele. 
- De aanpak is vergelijkbaar met de functie van [**opdracht 2.12 Palindroom**](../../functies/basis/opdr_palindroom.md).
- Je mag geen gebruik maken van de `std::swap` functie. 
- De handtekening van de functie is:
```cpp
void transpose(vector<vector<int>> & matrix){
  ...
  ...
};
```