![logo](../c++/img/ISO_C++_Logo.svg) [](logo-id)

# for[](title-id)

### Inhoud[](toc-id)

## Introductie

### For
Bij de while-loop hangt het van de conditie af hoe vaak het stuk code in de loop wordt herhaald. 
De for-loop gebruiken we als de loop niet afhankelijk is van een conditie, maar we de code in de loop een aantal keer willen herhalen. 

Bijvoorbeeld als we 5 keer “Hello, world” willen printen of als we alle characters in een string af willen
gaan. In onderstaande codevoorbeelden zien we de for-loop uitgewerkt.

```c++ {.line-numbers}
#include <iostream>
using namespace std;
int main(){
    for(int i=0; i < 5; i++){
        cout << "Hello, world" << i << "\n";
    }
    // Hello, world0
    // Hello, world1
    // Hello, world2
    // Hello, world3
    // Hello, world4
}
```
codevoorbeeld for-loop

```c++
#include <iostream>
#include <string>
using namespace std;
int main(){
    string text = "Spicy!Hot!";
    for(unsigned int j=0; j<text.size(); j++){
        cout << j << ": " << text[j] << "\n";
    }
    // 0: S
    // 1: p
    // 2: i
    // 3: c
    // 4: y
    // 5: !
    // 6: H
    // 7: o
    // 8: t
    // 9: !
}
```
codevoorbeeld for-loop



