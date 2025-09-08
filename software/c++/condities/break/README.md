# break[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [break](#break)
- [continue](#continue)

### break

Als we een loop voortijdig willen beeindigen kunnen we hiervoor het sleutelwoord *break*
gebruiken.
Codevoorbeeld 5.9 laat het gebruik van een break zien. Let op dat de code voor de break nog wordt uitgevoerd. De code erna niet meer. De hoofdregel is dat je breaks niet gebruikt. **Code met breaks is bijna altijd minder leesbaar en foutgevoeliger.**
Gebruik breaks dus enkel als het alternatief resulteert in minder leesbare code.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    string text = "Spicy!Hot!";
    for(unsigned int i=0; i<text.size(); i++){
        cout << i << ": " << text[i];
        if(text[i] == '!'){
            break;
        }
        cout << " +\n";
    }
    //output:
    // 0: S +
    // 1: p +
    // 2: i +
    // 3: c +
    // 4: y +
    // 5: !
}
```

*Codevoorbeeld 5.9 - break*

### continue

C++ kent ook het sleutelwoord continue.

Deze wordt hier niet behandeld, omdat gebruik ervan bijna altijd leidt tot minder leesbare en foutgevoeligere code.
> (Docent Hagen heeft daar een andere mening over. Als je die wil weten, vraag hem gerust.)

Desondanks kunnen geïnteresseerden informatie hierover vinden op: 
<http://en.cppreference.com/w/cpp/language/continue>.
