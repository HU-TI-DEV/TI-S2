# Constructor (title-id)

### Inhoud[](toc-id)
- [Constructor (title-id)](#constructor-title-id)
    - [Inhoud](#inhoud)
      - [Default constructor](#default-constructor)
        - [Een constructor zonder parameters](#een-constructor-zonder-parameters)
        - [Undefined behaviour](#undefined-behaviour)
      - [Default parameter waarden](#default-parameter-waarden)
      - [Let op de parametervolgorde](#let-op-de-parametervolgorde)
      - [Keuzes](#keuzes)
      - [Foutmeldingen van de compiler](#foutmeldingen-van-de-compiler)
      - [Declaratie vs. implementatie](#declaratie-vs-implementatie)


#### Default constructor
Tot nu toe hebben we bij het aanmaken van een vector steeds aangegeven wat de (initiële) waarde is. 
Stel dat we dat niet willen doen: *we willen een vector variabele aanmaken, zonder initiële waarde.* 

Met de vector declaratie die we tot nu toe hadden kan dat niet: voor de compiler is het aanmaken van een variabele het aanroepen van een constructor, en als je bij het aanmaken geen waarden meegeeft is dat dus een constructor die zonder parameters wordt aangeroepen, de zgn. default constructor. Die is er in ons geval niet. 

##### Een constructor zonder parameters
Zoals zo vaak in C++ is het maken van een constructor zonder parameters geen probleem: (bijna) alles kan, maar je moet het wel zelf doen. In dit geval kunnen we een constructor toevoegen zonder parameters. (We *overloaden* dan dus de constructor.) Die nieuwe constructor hoeft niets te doen:
   - zowel de initialisatielijst als de body zijn leeg. 
   - De vector-attributen, die met deze constructor zijn aangemaakt, hebben geen gedefinieerde waarde, net als een (lokale) integer of float die je aanmaakt.
  
 ```cpp
class vector {
public:
    int x;
    int y;
    // constructor met parameters
    vector( int x, int y ):
      x( x ), y( y )
    {}

    // constructor zonder parameters en attribuutwaarden
    vector(){}
};
vector a;
vector b( 1, 2 );
 ```
*Codevoorbeeld 06-07 - Een vector met twee constructors*

##### Undefined behaviour
Een object met *ongedefinieerde waarden* is tijdens het runnen van je programma snel aangemaakt, maar als je die waarden per ongeluk gebruikt vertoont je programma ‘undefined behaviour’. Dit kan je (ten koste van wat snelheid) voorkomen door in de constructor de x en y wél een waarde te geven. 
Welke waarde doet er niet zo veel toe, meestal wordt 0 gebruikt.

*‘Undefined behaviour’ betekent dat echt alles kan gebeuren. Volgens Murphy werkt alles dus prima als je het zelf test, maar het crasht zodra je er iets belangrijks mee wil doen, bv. demonstreren voor een klant of laten aftekenen bij je docent.*

*De meningen zijn verdeeld over wat een goede default beginwaarde is. Eén stroming pleit voor een ‘logische, handige, neutrale’ waarde, bv. 0 voor getallen, en een lege string voor strings. Het idee is dat je de programmeur werk uit handen neemt door een variabele bij initialisatie als de meest logische beginwaarde te geven. Hier tegenover staat de opvatting dat een programmeur altijd zelf de beginwaarde moet aangeven. Als hij dat vergeet is dat een fout, en de automatische beginwaarde moet die fout zo duidelijk mogelijk maken. Voor getallen kan je dan bv. voor -1 kiezen (voor floats NaN: de speciale not-a-number waarde), en voor strings ‘?’ op alle posities. De automatische beginwaarde dient dan als signaal-waarde bij het debuggen, en zou in de definitieve (productie) versie van de applicatie misschien zelfs weggelaten kunnen worden.*


```cpp
class vector {
public:
    int x;
    int y;
    // constructor met parameters
    vector( int x, int y ):
      x( x ), y( y )
    {}

    // default constructor met attribuutwaarden
    vector():
      x( 0 ), y( 0 )
    {}
};
```
*Codevoorbeeld 06-08 - Een vector met twee constructors. De default constructor zet de attributen wel op een waarde*

#### Default parameter waarden
We hebben nu twee constructors, maar dat is niet nodig als we een andere C++ feature gebruiken. We kunnen in de declaratie van een functie voor een parameter een default waarde aangeven. Bij het aanroepen van zo’n functie mogen de parameters die een default waarde hebben weggelaten worden. Dan worden van links naar rechts de parameters die wél worden meegegeven gebruikt, en voor de overige parameters worden de default waarden gebruikt.
```c++
class vector {
public:
int x;
int y;
vector( int x = 0, int y = 0 ):
x( x ), y( y )
{}
};
vector a;
vector b( 1 );
vector c( 2, 3 );
```
*Codevoorbeeld 06-09 - Een constructor met default parameters*

#### Let op de parametervolgorde
Het heeft geen zin om na een parameter met een default waarde nog een parameter te hebben die geen default waarde heeft: dit mag dus ook niet.
*Beredeneer dit zelf: kun je een functie `f( int x = 0, int y )` zodanig aanroepen dat de default waarde voor x gebruikt wordt?*

#### Keuzes
Een verschil tussen de twee aparte constructors en een enkele constructor met twee default parameters is dat je die enkele constructor ook kan aanroepen met één parameter. Of dit wenselijk is moet je als auteur van de klasse zelf beoordelen.

#### Foutmeldingen van de compiler
Als je een constructor zonder parameters definieert en ook nog een constructor met voor alle parameters een default, dan zijn er twee constructors die beide zonder parameters kunnen worden aangeroepen. Als je dat doet krijg je bij zo’n aanroep een foutmelding van **de compiler die aangeeft dat hij niet weet welke van de twee hij moet aanroepen**. 

Zoals eerder gezegd, geldt dit principe ook voor andere (niet-constructor) functies: *pas bij het aanroepen bepaalt de compiler of hij, aan de hand van de naam en de parameters, precies weet welke functie er aangeroepen moet worden.* Zijn er meerdere kandidaten, dan volgt een foutmelding.

#### Declaratie vs. implementatie
Default waarden voor parameters moet je aangeven bij de **declaratie** van een functie (of methode). Als je een aparte definitie hebt (vaak in een andere file), dan herhaal je de default waarden daar niet. 

De achterliggende reden is dat de default waarden iets te maken hebben met het aanroepen van een functie (en dat doet de compiler met alleen kennis van de declaratie), en niet met de implementatie van de functie (die ziet alleen de waarden van de parameters; niet of die afkomstig zijn van een default of van een door de aanroeper meegegeven waarde).

```cpp
class vector {
public:
  int x;
  int y;

  // default waarden in de declaratie
  vector( int x = 0, int y = 0 );
};

// implementatie constructor
vector::vector( int x, int y ):
  x( x ), y( y )
{}
```
*Codevoorbeeld 06-09 - Default parameters staan in de declaratie, niet in de definitie*