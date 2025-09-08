![logo](../../img/ISO_C++_Logo.svg) [](logo-id)

# for[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Introductie](#introductie)
  - [For](#for)
- [For - codevoorbeelden](#for---codevoorbeelden)
  - [Unsigned int](#unsigned-int)

## Introductie

### For

Bij de while-loop hangt het van de conditie af hoe vaak de code in de loop wordt herhaald.
De for-loop gebruiken we als de loop niet afhankelijk is van een conditie, maar als we de code in de loop een aantal keer willen herhalen.

Bijvoorbeeld als we 5 keer “Hello, world” willen printen of als we alle characters in een string af willen lopen.

## For - codevoorbeelden

In codevoorbeelden 5.7 en 5.8 zien we de for-loop uitgewerkt.

```cpp {.line-numbers}
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

*Codevoorbeeld 5.7 for-loop*

```cpp
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

*Codevoorbeeld 5.8 for-loop met unsigned int*

### Unsigned int

Een “gewone” integer kan zowel negatieve als positieve getallen bevatten.

Een `unsigned int` kan enkel positieve getallen bevatten.

De functie **.size()** in codevoorbeeld 5.8 geeft als datatype een unsigned integer terug.

Als we een `int` met een `unsigned int` gaan vergelijken, dan kan dit fout gaan bij grote of negatieve getallen.

Gelukkig is dat makkelijk te voorkomen door van de “loop control variabele” (in codevoorbeeld 5.8 variabele j) een `unsigned int` te maken.
