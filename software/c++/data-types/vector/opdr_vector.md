# Opdrachten Vector C++[](title-id)

### Inhoud[](toc-id)


### Opdracht 2.3 Positief
In de onderstaande code staan drie functies, *postive1()*, *positive2()* en *positive3()*. 
Wat de functies doen lijkt erg op elkaar.

```c++
#include <vector>
using namespace std;

vector<int> positive1(vector<int> numbers){
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] < 0){
            numbers[i] *= -1;
        }
    }
    return numbers;
}

void positive2(vector<int> & numbers){
    for(unsigned int i=0; i<numbers.size(); i++){
        if(numbers[i] < 0){
            numbers[i] *= -1;
        }
    }
}

vector<int> positive3(const vector<int> & numbers){
    vector<int> newNumbers = numbers;

    for(unsigned int i=0; i<newNumbers.size(); i++){
        if(newNumbers[i] < 0){
            newNumbers[i] *= -1;
        }
    }
    return newNumbers;
}
```
2.3A:
Beschrijf in één zin wat de functie positive1() doet.

2.3B:
De functie positive2() heeft geen return-statement. Hoe geeft de functie zijn resultaat
terug?

2.3C:
De drie functies vervullen alle drie ongeveer dezelfde taak. Ze verschillen voornamelijk
in hun functiedeclaratie. [^1]
Noem van elke functie een voordeel van de functiedeclaratie.
[^1] *Ook wel functiehandtekening of prototype genoemd.*

2.3D:
Welke functie heeft in dit geval je voorkeur? 
Geef minimaal één argument.

