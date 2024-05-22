# Units en waarden (title-id)

### Inhoud[](toc-id)
- [Units en waarden (title-id)](#units-en-waarden-title-id)
    - [Inhoud](#inhoud)
  - [Waarden](#waarden)
  - [Grootheden](#grootheden)
  - [Schalen: nominaal, ordinaal, interval en ratio](#schalen-nominaal-ordinaal-interval-en-ratio)
    - [Nominaal - geen volgorde](#nominaal---geen-volgorde)
      - [Geen volgorde](#geen-volgorde)
    - [Ordinaal - geordend](#ordinaal---geordend)
    - [Interval - geordend en vergelijkbaar](#interval---geordend-en-vergelijkbaar)
    - [Ratio - volgorde, afstand én nulpunt](#ratio---volgorde-afstand-én-nulpunt)
  - [C++ Enum type](#c-enum-type)
      - [Voorbeeld: windrichting](#voorbeeld-windrichting)
      - [Een gewone enum](#een-gewone-enum)
    - [Enum - globaal dus uniek](#enum---globaal-dus-uniek)
    - [Enum class](#enum-class)
  - [Integers en floats](#integers-en-floats)
  - [Floating point typen](#floating-point-typen)
  - [Interval schalen](#interval-schalen)
  - [Eenheden](#eenheden)
  - [Mars Climate Orbiter ongeluk](#mars-climate-orbiter-ongeluk)
  - [Buiten stof S2: templates, literals en user defined suffixes](#buiten-stof-s2-templates-literals-en-user-defined-suffixes)


## Waarden
Behandelde begrippen:
- Grootheden
- Meetschalen
- Eenheden
- User-defined literals
- Stelsels
- Boost::units

## Grootheden
Een grootheid is iets waarvan we de waarde kunnen *meten of tellen*. Denk aan kilometers of bedragen in euro's. Deze waarden zul je meestal omzetten naar `integer` of `float`.

Maar wat doe je met de grootheid 'kleur'?
Als je de waarden van kleur omzet naar `integer` kun je in je code onzinnige berekeningen doen: bijvoorbeeld blauw met 3 vermenigvuldigen.

Het is verstandig dit niet in je programma te doen, en tot op zekere hoogte kan de compiler je daarbij helpen. Het is belangrijk je bewust te zijn van de soorten **schalen** waarin grootheden kunnen worden uitgedrukt, en van de **relaties* tussen verschillende grootheden (uitgedrukt in hun eenheden).

## Schalen: nominaal, ordinaal, interval en ratio
Er zijn verschillende soorten schalen die uitdrukken hoe waarden zich onderling verhouden. 

Er zijn 4 bekende soorten schalen: 
- nominaal, 
- ordinaal, 
- interval, en 
- ratio.

In deze volgorde nemen de relaties tussen waarden toe.

### Nominaal - geen volgorde
Het meest eenvoudige soort schaal is de nominale schaal. De waarden in een nominale schaal zijn verschillend van elkaar (anders waren het geen aparte waarden), **maar dat is ook alles dat je kunt zeggen over die waarden**. 
Voorbeelden: landen, kleuren.

#### Geen volgorde
Je kunt nominale waarden niet op een (zinvolle) **volgorde* leggen. Denk bijvoorbeeld aan landen.
of kleuren. Soms wordt aan een nominale opsomming om praktische redenen wel een volgorde toegekend, bijvoorbeeld om te kunnen sorteren en zoeken. Kleuren zou je alfabetisch kunnen sorteren.

### Ordinaal - geordend
Als de waarden van een schaal wel een duidelijke volgorde hebben dan spreken we van een ordinale (geordende) schaal. 
- Een set waarden uit een ordinale schaal kun je dus (zinnig) **sorteren**. Denk bij een ordinale schaal bijvoorbeeld aan de manier waarop enquêtes meestal om je mening vragen: je mag kiezen uit een reeks termen, bijvoorbeeld **zeer goed, goed, matig, slecht en zeer slecht**. Daar zit een duidelijke volgorde in.

### Interval - geordend en vergelijkbaar
Bij een interval schaal hebben de waarden uit de schaal niet alleen 
- **een volgorde**, maar daarbovenop zijn 
- de onderlinge **afstanden gelijk**.
*Strikt genomen hoeven de onderlinge afstanden niet gelijk te zijn, als ze maar (zinnig) in een getal uit te drukken zijn.*

Je kunt dus verschillen tussen waarden met elkaar vergelijken, en **het gemiddelde bepalen**. 
Bijvoorbeeld temperatuur, uitgedrukt in graden Celsius of Fahrenheit.


### Ratio - volgorde, afstand én nulpunt
Bij een ratio schaal zitten de waarden op gelijke afstanden en **er is een (zinnig) nulpunt**. Dit betekent dat je waarden (zinnig) kunt **vermenigvuldigen met een getal**. 

Ratio schalen zijn bijvoorbeeld de temperatuur in graden Kelvin, je leeftijd, of het saldo op je bankrekening.
*Strikt genomen: 10°C is 283°K. Kelvin is wel een ratio schaal, dus 2 keer 283°K is 566°K en dat is 293°C.*


## C++ Enum type
Een enumerate type (enumeratie, opsomming) is een C++ type dat een reeks waarden kan aannemen; elke waarde heeft een naam. Je kunt deze zelf definiëren.

#### Voorbeeld: windrichting
De vier windrichtingen kun je definiëren in een enum type.

```c++
enum wind { north, east, south, west };
wind w = north;
```
*Codevoorbeeld - enum van windrichting*

#### Een gewone enum
Bij deze vorm van enumerate is de enumerate zelf 
- een soort integer, 
- en de waarden zijn een soort integer constanten. 

Dit betekent 
- dat je aan de enumerate een integer kan toekennen, 
- je er mee kan rekenen, en 
- dat je een probleem krijgt als je dezelfde naam wilt gebruiken voor waarden van verschillende enumeraties.

```c++
enum wind { north, east, south, west };
wind x = 2; // geen foutmelding
x++; // geen foutmelding
x = north + east; // geen foutmelding

enum pole { north, south }; // error: duplicate enumerate value
```
*Codevoorbeeld - Gebruik dubbele enum waarden (north en south) niet toegestaan*

### Enum - globaal dus uniek
Enum waarden zijn globaal en moeten dus uniek zijn.

### Enum class
In C++ is er naast de bovenstaande C-style enum een nieuwe versie, de enum class. Iedere enum class is een apart type, los van integer, en de benoemde waarden zijn alleen zichtbaar ‘binnen’ de enum type naam. Hierdoor 
- is er *geen probleem met het gebruik van dezelfde naam* binnen meerdere enumeraties, en 
- je kunt niet per ongeluk met de waarden rekenen.

In nieuwe code is het sterk aangeraden enum class te gebruiken in plaats van de gewone enum.

```c++
enum class wind { north, east, south, west };
wind x = 2; // error
x++; // error
x = wind::north + wind::east; // error

enum class pole { north, south }; // OK
pole y = pole::south;
```
*Codevoorbeeld - Enum class*

Enum class waarden zijn *lokaal* binnen de enum.
Enumeraties zijn geschikt om nominale en ordinale schalen te implementeren, maar de waarden zijn *geordend* (je kunt ze vergelijken met <, >, <=, >=) dus voor een nominale schaal zijn ze eigenlijk minder handig. Je zou zelf een soort enumerate kunnen maken die als vergelijkingen alleen == en != ondersteunt, maar dat is veel werk en wordt dus niet vaak gedaan.

```c++
class language {
private:
  int x;
  constexpr language( int x ): x{ x }{};
  static constexpr const char * const names[ 3 ]{
    "dutch", "english", "french"
  };

public:
  constexpr static language dutch_() { return language{0}; }
  constexpr static language english_(){ return language{1}; }
  constexpr static language french_() { return language{2}; }
  constexpr language( const language & rhs ): x{ rhs.x }{}

  friend hwcpp::io::ostream & operator<<(
    hwcpp::io::ostream & lhs,
    language x );
  bool operator==( const language &rhs ){
    return x == rhs.x;
  }
  bool operator!=( const language &rhs ){
    return *this != rhs;
  }
};

constexpr const char * const language::names[ 3 ];
constexpr const language dutch { language::dutch_() };
constexpr const language english { language::english_() };
constexpr const language french { language::french_() };
```
*Codevoorbeeld - 
Een DIY enum met alleen == en != (dus geen < etc.)*


## Integers en floats
Voor interval en ratio schalen kun je gebruik maken van de diverse integer en float typen, afhankelijk van je gewenste bereik (hoogste en laagste waarde) en nauwkeurigheid. Wees je wel bewust van de beperkingen van deze typen.
- Integers hebben een beperkt bereik. Een berekening die een waarde buiten het bereik zou opleveren is een *overflow (of underflow)*. 
- Voor signed integers is een overflow undefined behaviour. Dat betekent niet alleen dat je niet weet wat er aan waarde uitkomt, maar het kan betekenen dat je programma iets volkomen anders doet dan je verwacht had. 
- Voor unsigned integers worden alle berekeningen uitgevoerd modulo het bereik van het type. Hierdoor zijn signed integer berekeningen vaak sneller, maar unsigned berekeningen zijn veiliger.

## Floating point typen
Floating point typen (float en double) hebben ook een bereik, maar dat is zo groot (zeker voor double: 1.7E-308 to 1.7E+308) dat je daar meestal geen probleem mee zal hebben. Wat wel een probleem kan zijn is dat 
- floating point getallen altijd een benadering zijn. 
- Hierdoor zijn ze eigenlijk nooit geschikt voor code waarin je wil kijken of twee (floating point) getallen *gelijk* zijn. 
- Bij het gebruik van floating point type zijn operatoren `==` en `!=` niet zinnig om te gebruiken (we hebben ook geen `=<` en `>=`). 
- Een ander probleem van floating point getallen in een real-time systeem is dat de *snelheid* van de meeste floating point hardware berekeningen onafhankelijk is van de waarden (dat is een heel wenselijke eigenschap in een real-time systeem), behalve voor zogenaamde ‘de-normalized’ waarden. Dat zijn waarden net boven (of onder) nul, die qua formaat afwijken van de ‘normale’ waarden waar de hardware voor is ontworpen. *Het resultaat is dat berekeningen op zulke waarden 10 .. 100 keer meer tijd kosten dan berekeningen op normale waarden.* Veel systemen hebben de mogelijkheid dit te vermijden door de-normalized waarden als 0 te behandelen, maar hoe je dit moet bereiken verschilt per systeem.

## Interval schalen
Voor interval schalen moet je bedenken dat
- vermenigvuldigen en delen van waarden niet zinnig is. Wat is twee keer 10°C? Niet 20°C! *Voor zulke schalen zouden we dus eigenlijk integer en floating point typen moeten gebruiken die geen `*` en `/` operatoren hebben. (En `+` en `–` zijn ook verdacht.)*

## Eenheden
Als we een waarde meten dan is het resultaat niet alleen een getal. Is mijn lengte 185, 1.85, of 1.955466109E-16? (Om nog maar te zwijgen van de benadering 6”1). **Zo’n getal heeft pas betekenis als je weet in welke eenheid (cm, m, C) het is uitgedrukt**. Als je een kale (integer of floating point) variabele gebruikt om een dergelijk waarde op te slaan dan is het sterk aan te raden de eenheid in de naam van de variabele te verwerken, bijvoorbeeld *length_cm*.

## Mars Climate Orbiter ongeluk
In 1999 ging de Mars Climate Orbiter satelliet verloren doordat het onderdeel van besturingssoftware waarden doorgaf uitgedrukt in het Amerikaanse-Britse systeem (in pond-seconden), aan software die deze waarde interpreteerde volgens het SI-systeem (in Newton-seconden). Hierdoor remde de satelliet te weinig, kwam in een te lage baan om Mars terecht, en verbrandde. De atmosfeer van Mars is heel ijl maar toch genoeg om een dergelijke satelliet af te remmen.

Het is niet al te lastig om een eenvoudige templateklasse te maken waarin je waarden kunt uitdrukken ten opzichte van een gegeven eenheid, waarmee je eenheid problemen zoals die van de Mars Orbiter kan voorkomen.

## Buiten stof S2: templates, literals en user defined suffixes
Uitleg over templates, literals en user defined suffixes volgt later (deze stof maakt geen onderdeel uit van semester S2).