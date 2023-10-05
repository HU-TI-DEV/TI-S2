![logo](../c++/img/ISO_C++_Logo.svg) [](logo-id)

# while[](title-id)

### Inhoud[](toc-id)

## Introductie

### while
De basis herhalingsstatement in C++ is de while. Bij een while-loop wordt eerst de
conditie (wat staat tussen de ronde haken) gecontroleerd. Als dat waar is (true), dan
wordt de body van de while-loop (wat staat tussen de krulhaken) uitgevoerd. Dit
herhaalt zich, totdat de conditie niet waar is (false). 

### do-while
C++ kent ook een [do-while-loop](#do-while). Deze behandelen we niet in de les, maar kan soms wel handig zijn.

### While - codevoorbeelden 
De codevoorbeelden hieronder laten while-loops zien.
```c++
#include <iostream>
using namespace std;

int main(){
int num = 7;
cout << "start num: " << num << "\n";
while(num < 10){
num++;
cout << "num: " << num << "\n";
}
cout << "end num: " << num << "\n";
// start num: 7
// num: 8
// num: 9
// num: 10
// end num: 10
}

```
Codevoorbeeld van een while-loop - 1