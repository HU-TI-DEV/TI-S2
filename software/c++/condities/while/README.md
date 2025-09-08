![logo](../c++/img/ISO_C++_Logo.svg) [](logo-id)

# while[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Introductie](#introductie)
  - [while](#while)
  - [do-while](#do-while)
  - [While - codevoorbeelden](#while---codevoorbeelden)


## Introductie

### while
Het basis herhalingsstatement in C++ is de while. Bij een while-loop wordt eerst de
conditie (wat staat tussen de ronde haken) gecontroleerd. Als dat waar is (true), dan
wordt de body van de while-loop (wat staat tussen de krulhaken) uitgevoerd. Dit
herhaalt zich, totdat de conditie niet waar is (false).

### do-while
C++ kent ook een [do-while-loop](#do-while). Deze behandelen we niet in de les, maar kan soms wel handig zijn.

### While - codevoorbeelden 
Codevoorbeelden 5.4, 5.5 en 5.6 laten while-loops zien.

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
*Codevoorbeeld 5.4 - while-loop 1*

``` c++
#include <iostream>
using namespace std;

int main(){
    char letter = 'h';
    cout << "start letter: " << letter << "\n";
    while(letter >= 'a' && letter <= 'z'){
        cout << "letter: " << letter << "\n";
        if(letter <= 'e'){
            letter -= 2;
        }else{
            letter--;
        }
    }
    cout << "end letter: " << letter << "\n";
    // start letter: h
    // letter: h
    // letter: g
    // letter: f
    // letter: e
    // letter: c
    // letter: a
    // end letter: _
}
```
*Codevoorbeeld 5.5 - while-loop 2*

```c++
#include <iostream>
using namespace std;

int main(){
    int y = 0;
    cout << "start y: " << y << "\n";
    while(y<=6){
        int z = 9;
        cout << "start z: " << z << "\n";
        cout << "start second while loop: \n";
        while(z > 0){
            z -= 2;
            cout << '\t' << z << ", ";
        }
        cout << "\nend second while loop. \n";
        cout << "end z:" << z << "\n";
        y += 3;
        cout << "y: " << y << "\n";
    }
    cout << "end y:" << y << "\n";
    // start y: 0
    // start z: 9
    // start second while loop:
    // 7, 5, 3, 1, -1
    // end second while loop
    // end z: -1
    // y: 3

    // start z: 9
    // start second while loop:
    // 7, 5, 3, 1, -1
    // end second while loop
    // end z: -1
    // y: 6
    
    // start z: 9
    // start second while loop:
    // 7, 5, 3, 1, -1
    // end second while loop
    // end z: -1
    // y: 9
    // end y: 9
}
```
*Codevoorbeeld 5.6 - while-loop 3*
