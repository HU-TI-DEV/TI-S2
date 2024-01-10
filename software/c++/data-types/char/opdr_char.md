# Opdrachten Char C++[](title-id)

### Inhoud[](toc-id)

### Opdracht 1.6 — Character plus integer.
Schrijf een programma dat:
- om een char vraagt, 
- deze inleest, 
- bij de char 32 optelt, 
- de som afdrukt, 
- de uitkomst afdrukt als integer 
- en de uitkomst afdrukt als character. 
  
Een voorbeeld van de in- en output:

```console
> Geef een character: B
B + 32 = 98
B + 32 = b
```


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