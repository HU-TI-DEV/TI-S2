# Operatoren[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Operatoren](#operatoren)
    - [Operator+ en Right Hand Side (rhs)](#operator-en-right-hand-side-rhs)
    - [Operator+ en Left Hand Side (lhs)](#operator-en-left-hand-side-lhs)
    - [Body van operator](#body-van-operator)
    - [Eenzijdige operator (monadic)](#eenzijdige-operator-monadic)
  - [Overloading optel-operatoren](#overloading-optel-operatoren)
  - [Overloading (C++)](#overloading-c)
    - [Geen functie overloading in C](#geen-functie-overloading-in-c)

Verder lezen:
- [Constructor](./constructor.md)
- [Meer operatoren](./meer-operatoren.md)


## Operatoren
In codevoorbeeld 06-04 moeten we voor het optellen van twee locaties twee statements gebruiken, één voor de x en één voor de y. 

```c++
class vector {
public:
  int x;
  int y;
  . . .
};

vector a( 1, 2 ), b( 3, 4 );
// add b to a
a.x += b.x;
a.y += b.y;
```
*Codevoorbeeld 06-04 (herhaald)- Vectoren bij elkaar optellen via publieke attributen*

We kunnen dit makkelijker maken, want in C++ zijn operatoren zoals `+` eigenlijk gewoon methoden (klasse functies). Als een passende `operator+` is gedeclareerd zijn de volgende twee expressies legaal in C++ en betekenen exact hetzelfde:
```c++
a + b a.operator+( b )
```
*Codevoorbeeld 06-05 - Twee manieren om dezelfde operator+ methode aan te roepen*

Als we twee locaties bij elkaar op willen kunnen tellen dan moeten we daar de passende `operator+` voor schrijven.
```c++
class vector {
public:
    int x;
    int y;
    . . . 

vector operator+( const vector & rhs ) const {
        return vector( x + rhs.x, y + rhs.y ); }
};

vector a( 1, 2 ), b( 3, 4 );
// calculations with vectors
a = a + b;
```
*Codevoorbeeld 06-06 - Een operator+ maken*

#### Operator+ en Right Hand Side (rhs)
De `operator+` heeft twee parameters van het type vector: de eerste (linker) parameter is het object zelf, de tweede (rechter) is hier rhs (Right Hand Side) genoemd. De rhs parameter wordt overgedragen by reference (de `&`), en meer specifiek by `const` reference: de operator+ belooft plechtig dat hij die parameter niet zal wijzigen, en de compiler zal hem daaraan houden. Daardoor kan de operator ook aangeroepen worden met als argument een constante of een expressie.
*Behalve voor ingebouwde operatoren typen (bv. int); daarvoor is alleen de a + b schrijfwijze toegestaan.*

#### Operator+ en Left Hand Side (lhs)
Een + is symmetrisch, dus we willen dat de lhs (Left Hand Side, het object zelf dus) ook ‘by const reference’ moet worden overgedragen, maar die lhs zit niet in de parameter lijst, dat is het object zelf. Dit object wordt (als er niets anders is aangegeven) in feite ‘by reference’ overgedragen: de functies van de klasse kunnen de variabelen in het object lezen en schrijven. Als we willen dat de functies van de klasse de variabelen van de klasse kunnen lezen maar niet schrijven, dan moeten we het object ook als ‘const’ markeren. Volgens de C++ syntax moet dat meteen ná de parameterlijst (voor de `{` open-krulhaak).

#### Body van operator
De body van de operator is bijna triviaal: het resultaat van de functie is een waarde van het type `vector`. Die waarde construeren we door de vector constructor aan te roepen met de juiste x en y waarden.

#### Eenzijdige operator (monadic)
Behalve de tweezijdige (diadic) + is er ook een eenzijdige (monadic) +. Dit is een veel minder nuttige operator, die er eigenlijk alleen is omdat de eenzijdige - wél een nuttige operator is. De eenzijdige operatoren hebben geen rhs (de enige parameter is het object zelf, dat impliciet wordt doorgegeven), dus hun parameterlijst is leeg.

```c++
class vector {
public:
  int x;
  int y;
  . . . 
  vector operator+() const { 
    return vector( x, y ); 
  }
};

vector a( 1, 2 ), b( 3, 4 );
a = + b;
```
*Codevoorbeeld 06-07 - Een eenzijdige (monadic) operator+*

### Overloading optel-operatoren
Vector is natuurlijk niet het enige data type waarvoor je een optel-operator zou willen hebben. (En met de diadic en monadic operatoren heeft vector er al twee!) Dat leidt er toe dat er veel operator+ functies kunnen zijn. **In C++ is het geen probleem als er meerdere functies met dezelfde naam zijn, mits de compiler bij iedere aanroep van een functie aan het aantal en de typen van de parameters kan zien welke functie er wordt aangeroepen.**

In het volgende stukje code worden drie + operatoren aangeroepen. 
- De eerste heeft twee parameters van het type `vector` dus de aangeroepen functie is de zojuist beschreven ( `vector + vector` ). 
- De tweede aanroep heeft twee parameters van het type `int`, dus de aangeroepen functie is de ingebouwde ( `int + int` ) operator. 
- De derde aanroep heeft parameters van het type `vector` en `int`. Tenzij iemand een dergelijke functie gemaakt heeft zal de compiler hier een foutmelding geven omdat hij geen passende operator+ kan vinden.

```c++
vector a( 1, 2 ), b( 3, 4 ), c( 5, 6 ); 
int x = 1, y = 2, z;

c = a + b; // vector + vector
z = x + y; // int + int
z = x + b; // compilation error (geen int + vector)
```
*Codevoorbeeld 06-08 - Drie verschillende + operatoren naast elkaar*

### Overloading (C++)
Functies met dezelfde naam worden ‘overloaded’ genoemd. Overloading is in C++ mogelijk voor alle functies en methoden. Het wordt veel gebruikt bij operatoren en bij constructors.

#### Geen functie overloading in C
In C is overloading niet mogelijk, daar moet iedere functie een unieke naam hebben.