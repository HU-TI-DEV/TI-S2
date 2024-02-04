# Const [](title-id)

### Inhoud[](toc-id)
- [Const ](#const-)
    - [Inhoud](#inhoud)
    - [Const variabelen](#const-variabelen)
    - [Const parameters](#const-parameters)
      - [By copy](#by-copy)
      - [By reference](#by-reference)
      - [By const reference](#by-const-reference)
    - [Samenvatting](#samenvatting)


### Const variabelen
Je kunt een variabele of parameter const declareren om aan te geven dat de waarde van dit object (na de initiële initialisatie) niet meer zal veranderen. Dit maakt lezen van de code makkelijker, omdat de lezer zich bij het lezen van een expressie waarin de variabele wordt gebruikt niet hoeft af te vragen of de waarde in de tussentijd veranderd is. Daarnaast helpt het de compiler efficiëntere code te genereren.
*De term variabele is wat vreemd voor iets wat niet variabel (wijzigbaar is), maar zo is de terminologie.*

```c++
int main(){
const int answer = 42;
// Imaginge a long and very complex piece of code
std::cout << "The answer is " << answer << "\n";
}
```
*Codevoorbeeld 05-01 - const: je kunt er zeker van zijn dat de waarde niet veranderd*


### Const parameters
Je kunt `const` ook gebruiken om aan te geven dat een parameter van een functie binnen die functie niet veranderd zal worden. Het wijzigen van een gewone (niet-reference) parameter kan in een functie geen gevolgen hebben voor de meegegeven variabele zelf, omdat er een *kopie* van wordt doorgegeven. Maar de functie kan die kopie wél wijzigen, wat voor verwarring kan zorgen als je de code leest.

```c++
void f( int x ){
    . . .
    x = x + 5; // did the author realize that he is modifying a copy?
    . . .
}

. . .
int i = 10;
f( i );
// i is still 10
```
*Codevoorbeeld 05-02 - je kunt toekennen (assignen) aan de parameter van een functie, maar bedoel je dat ook?*

N.B. Als je een functie parameter als const declareert dwing je af dat die parameter in de functie niet gewijzigd wordt. Dit maakt het lezen van je code makkelijker.

```c++
void f( const int x ){
. .
x = x + 5; // compilation error
. . .
}
```
*Codevoorbeeld 05-03 - Een const parameter kun je niet wijzigen*

#### By copy
In C++ wordt een parameter standaard **‘by copy’** overgedragen. Als een object groter is dan een paar bytes is dat niet efficiënt: er moet ruimte gemaakt worden voor de kopie, de inhoud moet gekopieerd worden, en uiteindelijk moet de ruimte ook weer vrijgegeven worden. En dat terwijl de functie body ook gewoon gebruik had kunnen maken van het originele object. 

#### By reference
Het is (voor objecten van enige omvang) efficiënter om **‘by reference’** over te dragen. 
Maar dat heeft twee nadelen:
- De functie kan nu niet meer worden aangeroepen met een const object of met een expressie.
- De aangeroepen functie kan het object nu wél wijzigen.

```c++
void f( int & x ){}

const int x = 10;

f( x );     // compilation error
f( 3 + 5 ); // compilation error
```
*Codevoorbeeld 05-04 - Je kunt geen const of expressie meegeven aan een reference parameter*

#### By const reference
Beide problemen worden ondervangen door de parameter ‘by const reference’ over te dragen. 
- De aangeroepen functie krijgt dan een reference naar het object (een reference heeft dezelfde omvang als een pointer), 
- maar kan via die reference het object niet wijzigen.

*Tip: Er wordt algemeen aangenomen dat code veel vaker gelezen wordt dan geschreven. Het is dus een goed principe om code te optimaliseren voor leesbaarheid, dus niet noodzakelijk voor ‘schrijfbaarheid’.*

```c++
void f( const int & x ){}

void g( const int & x ){
  x = 7; // compilation error
}

int main(){
  const int x = 10;

  f( x ); // OK
  f( 3 + 5 ); // OK
}
```
*Codevoorbeeld 05-05 - Een object doorgeven by const reference*

### Samenvatting
Samenvattend:
- De eerste keuze voor het doorgeven van een parameter is ‘by const reference’. 
  - Reference omdat zo wordt voorkomen dat er een kopie wordt gemaakt. 
  - Const omdat je dan constanten en expressies kunt meegeven, en je in de functie zelf niet ‘per ongeluk’ de waarde kunt veranderen.
- Als een object zo klein is dat een kopie doorgeven efficiënter is dan het doorgeven van een reference dan wordt de reference vaak weggelaten. Dit is bv. het geval bij (losse) integers en characters.
- Als het doel van de functie is om de waarde van een parameter aan te passen dan moet je die parameter uiteraard by reference doorgeven (dus zonder const).