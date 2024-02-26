# Expressies[](title-id)

### Inhoud[](toc-id)
- [Expressies](#expressies)
    - [Inhoud](#inhoud)
  - [Rekenkundige expressies](#rekenkundige-expressies)
    - [Bewerkingsvolgorde](#bewerkingsvolgorde)
    - [++ en --](#-en---)
  - [Logische expressies](#logische-expressies)
    - [Bewerkingsvolgorde](#bewerkingsvolgorde-1)


C++ kent meerdere expressies om de data te bewerken en de stroom door het programma
te sturen. In dit hoofdstuk kijken we naar rekenkundige expressies, logische
expressies en de bewerkingsvolgorde van operatoren.

## Rekenkundige expressies
Een rekenkundige expressie is opgebouwd uit operanden (waarden, variabelen) en operatoren (+;-;*;/). Een rekenkundige expressie berekent een getalswaarde. 

Codevoorbeelden 4.1, 4.2 en 4.3 laten meerdere rekenkundige expressies zien.

```c++
#include <iostream>
using namespace std;

int main() {
    int x = 5 + 5;
    cout << "x: " << x << "\n";
    // x: 10

    float y = 100 / 8.0;
    cout << "y: " << y << "\n";
    // y = 12.5

    char c = 'F';
    c += 1;
    cout << "c: " << c << "\n";
    // c: G
}
```
*Codevoorbeeld 4.1 Rekenkundige expressies*

```c++
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;
    int result1 = a + b * 5;
    int result2 = (a+b) * 5;

    cout << "result1: " << result1 << "\n";
    cout << "result2: " << result2 << "\n";

    // result1: 55
    // result2: 75
}
```
*Codevoorbeeld 4.2 Gecombineerde rekenkundige expressies*

### Bewerkingsvolgorde
De berekening van een rekenkundige expressie is gebaseerd op de bewerkingsvolgorde van de operatoren. Zo gaat vermenigvuldigen vóór optellen. 
De complete lijst van bewerkingsvolgorden kun je vinden op: http://en.cppreference.com/w/cpp/language/operator_precedence.

Voor het bewerkstelligen
van een andere berekeningsvolgorde worden ronde haakjes ( ( en ) ) gebruikt. Dit zien
we in *codevoorbeeld 4.1* bij variabele result2. Haakjes worden ook gebruikt om de leesbaarheid te verhogen.

```c++
#include <iostream>
using namespace std;

int main() {
    int z = 3;
    z++;
    cout << "z: " << z << endl;
    // z: 4

    float w = 3.5;
    w--;
    cout << "w: " << w << endl;
    // w: 2.5
}
```
*Codevoorbeeld 4.3 Rekenkundige expressies ++ en --*

### ++ en --
In C++ is het mogelijk om een variabele met 1 te verhogen door middel van de operator ++. In codevoorbeeld 4.2 zien we dit bij variabele z.

`z++;` betekent hetzelfde als `z += 1;`, wat weer gelijk is aan `z = z + 1;`. Een variabele met
1 verlagen kan in C++ met de operator --. In codevoorbeeld 4.1 zien we dit bij
variabele w.  

`w--;` betekent hetzelfde als `w -= 1;`, wat weer gelijk is aan `w = w - 1;`.

## Logische expressies

Logische expressies bevatten logische operatoren. Deze gebruiken we om condities
en/of booleans met elkaar te combineren of te vergelijken. Onder logische operatoren
vallen:
- `&&` (en), 
- `||` (of), 
- `!` (niet), 
- `<`(kleiner dan), 
- `>` (groter dan), 
- `<=` (kleiner of gelijk aan), 
- `>=` (groter of gelijk aan), 
- `==` (gelijk aan) en 
- `!=` (niet gelijk aan). 

Een logische expressie levert als waarde *false* of *true* op. Codevoorbeelden 4.4, 4.5, 4.6 en 4.7 laten een aantal logische expressies zien.

```c++
#include <iostream>
using namespace std;

int main(){
  bool a = 5 > 4;
  cout << "a: " << a << "\n";
  // a: 1

  bool b = 5 <= 4;
  cout << "b: " << b << "\n";
  // b: 0
}
```
*Codevoorbeeld 4.4 Logische expressies > en <=*

```c++
#include <iostream>
using namespace std;

int main(){
  int c = 6;
  bool com1 = 5 > c && 2 < c;
  bool com2 = 5 > c || 2 < c;

  cout << "com1: " << com1 << "\n";
  cout << "com2: " << com2 << "\n";
  // com1: 0
  // com2: 1
}
```
*Codevoorbeeld 4.5 Logische expressies && en ||*

```c++
#include <iostream>
using namespace std;

int main(){
  bool x = true;
  bool y = !x;
  cout << "y: " << y << "\n";
  // y: 0
  bool z = !(5 < 3);
  cout << "z: " << z << "\n";
  // z: 1
}
```
*Codevoorbeeld 4.6 Logische expressies !operator*

```c++
#include <iostream>
using namespace std;

int main(){
  bool k = 5 != 6;
  cout << "k: " << k << "\n";
  // k: 1

  bool l = 5 == 6;
  cout << "l: " << l << "\n";
  // l: 0
}
```
*Codevoorbeeld 4.7 Logische expressies != en ==*

### Bewerkingsvolgorde
Net als rekenkundige expressies kennen logische expressies een berekeningsvolgorde.
Vergelijkingsoperatoren ( `<` , `<=` , `>`, `>=`, `==` , `!=` ) gaan vóór combineeroperatoren
(`&&`, `||` en `!`).

De complete lijst van bewerkingsvolgorden staat op: http://en.cppreference.com/w/cpp/language/operator_precedence.

Voor het bewerkstelligen van een andere berekeningsvolgorde kun je ronde haakjes ( ( en ) ) gebruiken.

