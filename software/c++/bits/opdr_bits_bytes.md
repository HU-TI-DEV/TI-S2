# Opdrachten Bits C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Bits C++](#opdrachten-bits-c)
    - [Inhoud](#inhoud)
  - [Opdracht 3.1 Bytewaarde](#opdracht-31-bytewaarde)
  - [Opdracht 3.2 Hoger en lager](#opdracht-32-hoger-en-lager)


## Opdracht 3.1 Bytewaarde
In onderstaande code heeft de variabele `b` steeds een andere byte-waarde. Schrijf elke
keer dat de waarde van b verandert zijn nieuwe byte-waarde op.

```c++
int main(){
    uint8_t mask = 0x6b;
    uint8_t b = 15;
    b = b | (1 << 6);
    b = ~b;
    b = b << 1;
    b |= 7;
    b &= ~(1 << 1);
    b ^= mask;
}
```

## Opdracht 3.2 Hoger en lager
Beschrijf in maximaal twee zinnen wat de onderstaande functie `upperAndLower()` doet.
**Probeer dit te doen zonder de code op een computer uit te voeren.** 
Je mag aannemen in je beschrijving dat de parameter van de functie enkel letters bevat.

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void upperAndLower(vector<string> & text){
    for(unsigned int i=0; i<text.size(); i++){
        for(unsigned int j=0; j<text[i].size(); j++){
            if(i % 2 == 0){
                text[i][j] |= (1 << 5);
            }else{
                text[i][j] &= ~(1 << 5);
            }
        }
    }
}
```