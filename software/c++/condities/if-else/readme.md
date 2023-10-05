![logo](../c++/img/ISO_C++_Logo.svg) [](logo-id)

# if-else[](title-id)

### Inhoud[](toc-id)

## Introductie

Met if/else statements kunnen we sturen welke delen van ons programma worden uitgevoerd. 

### if statement

Codevoorbeeld met if-statements:

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

### Haakjes

In C++ staat bij de if-statement de conditie altijd tussen ronde haakjes. Het weglaten van deze haakjes resulteert in een compile-error.
