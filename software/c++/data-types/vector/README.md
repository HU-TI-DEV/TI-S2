# Vector

### Inhoud[](toc-id) <!-- omit in toc -->
- [Vector](#vector)
  - [Vector](#vector-1)
    - [vector library](#vector-library)
    - [C++11 of hoger](#c11-of-hoger)
    - [Vector codevoorbeelden](#vector-codevoorbeelden)
  - [Functies](#functies)
    - [Unsigned int](#unsigned-int)


We kunnen een string gebruiken om meerdere
characters in één variabele op te slaan. Dit is iets wat we niet alleen voor characters
willen kunnen doen, maar ook voor andere datatypes. 

Hiervoor kunnen we in C++ een vector gebruiken. Hieronder leggen we het gebruik van een vector uit.

## Vector
Een vector is een reeks met elementen die een waarde hebben. 

### vector library 
Om vectoren te kunnen gebruiken, moeten we de library *vector* toevoegen aan onze code. 

Een vector maak je aan:
- met het sleutelwoord *vector* 
- en tussen punthaken (< en >) welk datatype in de vector zit.

Een vector kan alle datatypes die we eerder zijn tegengekomen bevatten. Inclusief strings en vectoren. 

In codevoorbeelden 7.1, 7.2, 7.3, 7.4 en 7.5 zie je
het gebruik van een vector in C++.

### C++11 of hoger
Mocht het gebruik van een vector in je programma zorgen voor een compile error, controleer
dan of bij je project de “C++ compiler options” op C++11 of hoger staat.

### Vector codevoorbeelden
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<float> numbers = {5.3,3.2,6.4,7.1};
  for(unsigned int i=0; i<numbers.size(); i++){
    cout << "number " << i << " is: " << numbers[i] << "\n";
  }

  //output:
  // number 0 is: 5.3
  // number 1 is: 3.2
  // number 2 is: 6.4
  // number 3 is: 7.1
}
```
*Codevoorbeeld 7.1 Een vector met floats* 

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> money = {5,8};
  money.push_back(3); // add 3 to the end of the vector money
  for(unsigned int i=0; i<money.size(); i++){
    cout << "money " << i << " is: " << money[i] << "\n";
  }

  //output:
  // money 0 is: 5
  // money 1 is: 8
  // money 2 is: 3
}
```
*Codevoorbeeld 7.2 Een vector met integers*

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> colors = {"blue", "red"};
  colors.push_back(string("green")); // add "green" to the vector colors
  cout << colors[0] << ", " << colors[1] << ", " << colors[2] << endl;
  cout << colors[0][0] << colors[0][1] << ", ";
  cout << colors[1][0] << colors[1][1] << ", ";
  cout << colors[2][0] << colors[2][1] << endl;

  //output:
  // blue, red, green
  // bl, re, gr
}
```

*Codevoorbeeld 7.3 Een vector met strings* 

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector< vector<int> > matrix = { {3, 99}, {32, 88} };
  vector<int> row = {54, 28};
  matrix.push_back(row); // add row to the vector matrix
    for (unsigned int i=0; i<matrix.size(); i++){
      for (unsigned int j=0; j<matrix[i].size(); j++){
        cout << "(" << i << "," << j << "): " << matrix[i][j] << "\n";
      }
  }

  //output:
  // (0,0): 3
  // (0,1): 99
  // (1,0): 32
  // (1,1): 88
  // (2,0): 54
  // (2,1): 28
}
```

*Codevoorbeeld 7.4 Een vector met vectoren van integers* 

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<char> letters = {'A', 'B', 'C', 'D'};
  letters[0] = 'Z'; // replace element 0 in letters with a 'Z'
  letters.pop_back(); // remove last element
  cout << "letters: ";
  for(unsigned int i=0; i<letters.size(); i++){
    cout << letters[i] << ", ";
  }
  cout << "\n";

  //output:
  // letters: Z, B, C,
}
```
*Codevoorbeeld 7.5 Een vector met characters* \

## Functies
Het datatype vector komt samen met een aantal functies. In codevoorbeeld 7.1 zien
we `size()`, `push_back()` en `pop_back()`. De functie `size()` geeft de lengte van de de
vector terug. De functie `push_back()` voegt een element toe aan het einde van de
vector. De functie `pop_back()` verwijdert het laatste element. 

De complete lijst met vector-functies staat op: http://en.cppreference.com/w/cpp/container/vector.


### Unsigned int
Een “gewone” integer kan zowel negatieve als positieve getallen bevatten. Een *unsigned int* kan enkel positieve getallen bevatten. De functie `size()` in *codevoorbeeld
7.1* geeft als datatype een unsigned integer terug. Als we een int met een unsigned
int gaan vergelijken, dan kan dit fout gaan bij grote of negatieve getallen. Gelukkig
is dat makkelijk te voorkomen door van de “loop control variable” (in codevoorbeeld 7.1 variabele i) een *unsigned int* te maken.
