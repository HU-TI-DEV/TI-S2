# Opdrachten Data-types C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Data-types C++](#opdrachten-data-types-c)
    - [Inhoud](#inhoud)
    - [Opdracht 1.3A Int, Float, Char, Bool](#opdracht-13a-int-float-char-bool)
    - [Opdracht 1.3B Int, Float, Char, Bool](#opdracht-13b-int-float-char-bool)
  - [BONUS opdrachten](#bonus-opdrachten)
    - [Opdracht 1.3C Int, Float, Char, Bool](#opdracht-13c-int-float-char-bool)
    - [Opdracht 1.3D Int, Float, Char, Bool](#opdracht-13d-int-float-char-bool)


### Opdracht 1.3A Int, Float, Char, Bool
- **Lees** de code uit *Codevoorbeeld 1.3.1 data-types simpel* (dus NIET uitvoeren!).
- Schrijf van elke variabele (x, y, etc..) de waarde op die de variabele heeft na het uitvoeren. Doe dit zonder de code uit te voeren op een computer.

```c++ {.line-numbers}
#include <string>
using namespace std;

int main(){

    int x = 8.2;
    int y = 18 / 5;
    
    float e = 3.429;
    float f = 18 / 5;

    char a = 'a';
    char b = 'e';
    char c = b;

    bool r = true;
    bool u = (1 & 0);

    string p = "Klaar?";
    string s = string("Nee, nog") + string(" niet");

}
```
*Codevoorbeeld 1.3.1 data-types simpel*

### Opdracht 1.3B Int, Float, Char, Bool
Je wilt natuurlijk weten of je het goed hebt gedaan.
- Voer *Codevoorbeeld 1.3.1 data-types* uit op een computer.
- Wat valt je op als je het programma draait?
- Pas de code aan met `cout` zodat je de variabelen op het scherm print.
- Hint: `cout << "x is: " << x;`

## BONUS opdrachten
### Opdracht 1.3C Int, Float, Char, Bool
- **Lees** de code uit *Codevoorbeeld 1.3.3 data-types complex* (dus NIET uitvoeren!).
- Schrijf van elke variabele (x, y, etc..) de waarde op die de variabele heeft na het uitvoeren. Doe dit zonder de code uit te voeren op een computer.

```c++ {.line-numbers}
#include <string>
using namespace std;

int main(){

    int x = 8.2;
    int y = 18 / 5;
    int z = 18 / 5.0;
    int f = '8' - '0';
    int e = 10 % 3;
    
    float t = 18 / 5;
    float s = 18 / 5.0;

    char a = 'a';
    char b = 'e';
    char d = b;
    char c = 'b' + ('Z'- 'z');

    bool r = true && (false || true);
    bool u = 8 >= 10;

    string p = "Utereg";
    p.append(" Me Stadsie!");
    string station = string("Heidel") + "berglaan";
    string plaats = station.erase(10, station.size()-10);

}
```
*Codevoorbeeld 1.3.3 data-types complex*

### Opdracht 1.3D Int, Float, Char, Bool
- Voer *Codevoorbeeld 1.3.3 data-types complex* uit op een computer.
- Maak gebruik van cout om de waarden te printen.