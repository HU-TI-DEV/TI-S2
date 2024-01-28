# Strings [](title-id)

### Inhoud[](toc-id)
- [Strings ](#strings-)
    - [Inhoud](#inhoud)
    - [String](#string)
    - [\[ \]](#-)
    - [Literal string](#literal-string)
    - [Aanhalingstekens](#aanhalingstekens)
  - [Functies](#functies)
    - [+](#)


Het datatype character, *char*, kan één karakter bevatten. Als we
meerdere characters in één variabele willen opslaan kunnen we hiervoor in C++ het
datatype *string* gebruiken. 
Hiervoor moet wel de library string toegevoegd worden.
Codevoorbeelden 3.7 en 3.8 laten zien hoe er in C++ met de string gewerkt kan worden.

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string building = "Bank";
    cout << "building: " << building << "\n";
    // building: Bank
    char c = building[2]; // this is a char
    cout << "c: " << c << "\n";
    // c: n
    building[1] = 'u'; // single airqoutes
    cout << "building: " << building << "\n";
    // building: Bunk
}
```
*Codevoorbeeld 3.7 Strings*

### String
Met het sleutelwoord string geven we aan dat een variabele van het datatype string is.

### [ ]
Een string bestaat uit meerdere characters. Met vierkante haken ([ en ]) kunnen we een
character van een bepaalde positie ophalen of aanpassen. Dit zien we in *codevoorbeeld
3.7*; building[1] en building[2].

C++ controleert niet of de waarde tussen de vierkante haken wel binnen de string
valt. Je kunt dus de character waarde opvragen van een index die buiten je string valt.
Je krijgt dan geen error, maar de byte die toevallig op dat geheugenplekje staat, vertaalt
naar een character. Dat is een fout die niet snel opvalt, maar wel grote gevolgen voor
je programma kan hebben. 
*Controleer dus altijd of je een geldige index opvraagt.*

In C++ gebruik je enkel positieve indexen. Bij het gebruik van negatieve indexen
krijg je geen error. Het programma zal de byte die toevallig op dat geheugenplekje
staat, vertaald naar een character, gebruiken. Je programma zal dan onverwacht gedrag vertonen!

### Literal string
Een variabele van het datatype string noemen we een string. Als we meerdere
characters tegelijk in een string willen stoppen gebruiken we hiervoor dubbele aanhalingstekens
(“ en ”). De waarde die we erin stoppen heeft in C++ een andere naam.
We noemen dit een *literal string*. 
In codevoorbeeld 3.7 zien we de
string *building* en de literal string “Bank”.

### Aanhalingstekens
Let bij het gebruik van (literal) strings en chars (zie [char](../data-types/char/README.md)) goed op de aanhalingstekens.
- Enkele aanhalingstekens (bijvoorbeeld ‘t’) geven aan dat iets van het type char is. 
- Dubbele aanhalingstekens (bijvoorbeeld: “t”) geven aan dat iets van het type literal
string is.


```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "hello";
    int length = text.size(); // this is an integer
    cout << "length: " << length << "\n";
    // length: 5

    string z = "Robotica";
    string subz = z.substr(2,3);
    cout << "subz: " << subz << "\n";
    // subz: bot

    string v = "C";
    v.append("++");
    v += " is fun.";
    cout << "v: " << v << "\n";
    // v: C++ is fun.

    string e = "Eating cake!";
    e.erase(3,3);
    cout << "e: " << e << "\n";
    // e: Eat cake!

    string r = "Buy vegetables!";
    r.replace(4,10,"candy");
    cout << "r: " << r;
    // r: Buy candy
}
```
*Codevoorbeeld 3.8 Stringfuncties*

## Functies
De library string komt met meerdere handige functies voor het gebruik van strings.
In codevoorbeeld 3.8 zien we de functies *size()*, *.append()*, *.erase()*, *.substring()*
en *.replace()*. 

Voor een compleet overzicht van stringfuncties, zie: http://www.cplusplus.com/reference/string/string/


```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "hello";
    string x = "world";
    string result1 = text + x;
    string result2 = string("The bird") + string(" is the word");
    cout << "result1: " << result1 << "\n";
    cout << "result2: " << result2 << "\n";
    // result1: helloworld
    // result2: the bird is the word
}
```
*Codevoorbeeld 3.9 String +operator*

### +
De +operator kan in C++ worden gebruikt om twee strings aan elkaar te koppelen. Dit kunnen we zien in codevoorbeeld 3.9 bij de variabele *result1* (text + x). 
Dit werkt echter niet als we twee literal strings tussen dubbele aanhalingstekens bij elkaar willen
voegen. Hiervoor is de +operator niet gedefinieerd. Een oplossing hiervoor vinden we
in codevoorbeeld 3.9 bij de variabele *result2* (en in codevoorbeeld 3.8, bij de variabele v).