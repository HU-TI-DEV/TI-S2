# References

### Inhoud[](toc-id)
- [References](#references)
    - [Inhoud](#inhoud)
    - [By copy](#by-copy)
    - [By reference](#by-reference)
    - [Snelheid](#snelheid)
    - [Let op](#let-op)

---

### By copy
In C++ worden de variabelen in een functie standaard “by copy” meegegeven. Dit
betekent dat we niet de originele variabele meegeven, maar een kopie van de waarde in de parameter stoppen. 

In codevoorbeeld 8.4 zien we dit bij de variabelen zeros en ones op de regels 69 t/m 72. Bij de functie add1() wordt de parameter v aangepast in
de functie, maar zeros - die wordt meegegeven aan de functie - blijft onveranderd.

### By reference
Als we de meegegeven variabele willen kunnen aanpassen moeten we de parameter
“by reference maken”. Dit doen we met het sleutelwoord &. 
In codevoorbeeld 8.6 en 8.7 zien we de functies *add1()* , *changeTo8* en *getAndSetNext()* met een reference parameter.

```c++
#include <iostream>
#include <vector>
using namespace std;

void changeTo8(int & x){
  x = 8;
}

char getAndSetNext(char & letter){
  letter++;
  return letter;
}

int main(){
  int number = 3;
  changeTo8(number);
  cout << "number: " << number << "\n";
  //output:
  // number: 8

  char x = 'A';
  char y = getAndSetNext(x);
  cout << "x: " << x << "\n";
  cout << "y: " << y << "\n";
  //output:
  // x: B
  // y: B
}
```
*Codevoorbeeld 8.6 Functies met references - 1*


```c++
#include <iostream>
#include <vector>
using namespace std;

void add1(vector<int> & v){
  for(unsigned int i =0; i<v.size(); i++){
    v[i] += 1;
  }
}

void printNumbers(vector<int> n){
  for(unsigned int i=0; i<n.size(); i++){
    cout << n[i] << ", ";
  }
  cout << "\n";
}

int main(){
  vector<int> numbers(4,0); // a vector with 4 zero's.
  add1(numbers);
  printNumbers(numbers);

  //output
  // 1,1,1,1,
}
```
*Codevoorbeeld 8.7 Functies met references - 2*

### Snelheid
Het meegeven van een parameter “by reference” heeft ook als voordeel dat het sneller
is en minder geheugen kost. Immers, er hoeft geen kopie van de originele waarde te
worden weggeschreven naar een andere geheugenlocatie.

### By reference vs. by value
Als je een parameter “by reference” maakt kun je niet een waarde als parameter meegeven. De parameter accepteert dan nog enkel variabelen. 

Bijvoorbeeld: De functie getAndSetNext() in codevoorbeeld 8.6 kan niet worden aangeroepen als getAndSetNext(’A’). Dit geeft een **compile-error**.