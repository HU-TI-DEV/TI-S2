# Constant

### Inhoud[](toc-id)

## const
“By reference” meegeven is meestal sneller. Dus eigenlijk willen we dit altijd doen, maar dit is eng voor de gebruiker van de functies. Hoe weet de gebruiker, zonder de code in detail te bekijken, of de functie de meegegeven variabele aanpast?

Gelukkig heeft C++ het sleutelwoord **const**. Hiermee beloven we dat we de variabele niet gaan aanpassen. Sterker nog als we een parameter const maken, dan kunnen we dat niet eens meer. (Als we dat toch proberen zal de compiler een compile-error genereren!)

## const ref
Door het gebruik van *const* weet de gebruiker van de functie dat het veilig is om zijn variabelen mee
te geven aan de functie. 
De standaard is dat we parameters **const &** maken. Dit noemen we het “by const reference” meegeven van een variabele.

Codevoorbeeld 8.8 laat een functie getNext zien met een parameter letter die const & is.

## by copy
Als we de waarde van de parameter wel willen aanpassen, dan zorgen we dat de waarde “by copy” meegegeven wordt (zonder const en zonder &). 

```c++
#include <iostream>
using namespace std;

char getNext(const char & letter){
    char next_letter = letter + 1;
    return next_letter;
}

int main()
{
    char x = 'A';
    char y = getNext(x);
    char z = getNext('D');
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";
    cout << "z: " << z << "\n";
    //output
    // x: A
    // y: B
    // z: E
}
```
*Codevoorbeeld 8.8 - Const ref parameter*