![logo](../c++/img/ISO_C++_Logo.svg) [](logo-id)

# if-else[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Introductie](#introductie)
  - [if statement](#if-statement)
  - [if-else statement](#if-else-statement)
  - [Haakjes](#haakjes)
  - [else-if](#else-if)
  - [Geneste if-statements](#geneste-if-statements)


## Introductie

Met if/else statements kunnen we sturen welke delen van ons programma worden uitgevoerd. 
Codevoorbeelden 5.1, 5.2 en 5.3 laten de werking van if/else statements
zien.

### if statement

```c++
#include <iostream> 
using namespace std;

int main(){
    int x = 6; 
    if(x > 3) {
        x = 8;
    }
    cout << "x: " << x << "\n";
    // x: 8

    char y = 'A'; 
    if(y == 'K'){
        y = 'H';
    }
    cout << "y: " << y << "\n";
    // y: A

    char z = 'J';
    if(z == 'H' || z == 'J' || z == 'Q'){
        z = 'C';
    }
    cout << "z: " << z << "\n";
    // z: C

    int a = 8;
    if(true){ 
        a++;
    }
    cout << "a: " << a << "\n";
    // a: 9
}
```
*Codevoorbeeld 5.1 - if-statements*

### if-else statement

Codevoorbeeld met if-else-statements:

```c++
#include <iostream> 
using namespace std;

int main(){ 
    float b = 1.3; 
    if(b != 1.3){ 
        b = 4.43;
    }else{
        b = 6.23;
    }
    cout << "b: " << b << "\n";
    // b: 6.23

    int c = 12; 
    string r; 
    if(c < 10){ 
        r = "9 or smaller";
    }else if(c < 15){ 
        r = "between 9 and 15";
    }else{
        r = "15 or larger";
    }
    cout << "r: " << r << "\n";
    // r: between 9 and 15

}
```
*Codevoorbeeld 5.2 - if/else statements*

### Haakjes

In C++ staat bij de if-statement de conditie altijd tussen ronde haakjes. Het weglaten van deze haakjes resulteert in een compile-error.

### else-if
Het combineren van een else en een if statement doen we in C++ door deze twee
statements op één lijn te zetten. Bijvoorbeeld:
`else if(c < 15) {` 
in *codevoorbeeld 5.2*.

### Geneste if-statements
Een conditie kan gelden binnen een andere conditie: een if-statement kan voorkomen binnen een ander if-statement. Dit noemen we een genest if-statement of *nested if-statement*.

```c++
#include <iostream>
using namespace std;

int main(){
    int d = 62;
    if(d > 0 && d < 100){
        if (d % 2 == 1){
            d = 50;
        }
        d = d * 2;
    }
    cout << "d: " << d << "\n";
    // d: 124
}
```
*Codevoorbeeld 5.3 - genest if-statement (if in if)*
