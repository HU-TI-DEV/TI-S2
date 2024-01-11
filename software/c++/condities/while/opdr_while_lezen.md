# Opdrachten While C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten While C++](#opdrachten-while-c)
    - [Inhoud](#inhoud)
    - [Opdracht 1.4 While-loop - code lezen](#opdracht-14-while-loop---code-lezen)
    - [Controle](#controle)


### Opdracht 1.4 While-loop - code lezen

In de onderstaande code krijgt de variabele *number* verschillende waarden. 
Schrijf deze waarden in goede volgorde op.
Doe dit **zonder** de code uit te voeren.

```c++ {.line-numbers}
#include <iostream>
using namespace std;

int main(){
    int number = 65;
    while( number < 90){
        if(number < 70){
            number = 70;
        }else if( number < 80){
            number++;
        }
        number += 3;
    }
}
```
*Opdracht 1.4 while-loop*

### Controle
Controleer je antwoorden door de code uit te voeren.