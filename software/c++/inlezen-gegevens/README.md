# Inlezen van gegevens[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [cin](#cin)
  - [iostream library](#iostream-library)
  - [Spaties](#spaties)
- [Getline](#getline)


Programma’s worden meestal een stuk praktischer als ze input kunnen krijgen van een
gebruiker en deze kunnen verwerken. In dit hoofdstuk kijken we naar hoe C++ invoer
van een toetsenbord kan inlezen.

## cin
Voor de uitvoer naar het scherm gebruiken we het sleutelwoord *cout* en de punthaken
<<. Voor het lezen van invoer van het toetsenbord gebruiken we een vergelijkbaar
constructie: het sleutelwoord *cin* en de punthaken >>. Als we *cin* als het toetsenbord zien, dan kunnen we de `>>` zien die de waarde van het toetsenbord richting de variabele stuurt.

### iostream library
Voor *cin* hebben we net als
voor *cout* de library *iostream* nodig. In codevoorbeeld 6.1 wordt de gebruiker om
input gevraagd.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n_tables;
    cout << "Enter number of tables in the room: ";
    cin >> n_tables;

    int total_legs = n_tables * 4;
    cout << "there are " << total_legs << " table legs in the room.\n";
}
```
*Codevoorbeeld 6.1 Cin*

### Spaties
De invoer wordt in C++ automatisch gescheiden op spaties en enters. Dit kun je
gebruiken om meerdere inputs tegelijk te krijgen. Net zoals we bij *cout* meerdere
waarden en/of variabelen tegelijk naar het scherm kunnen sturen, kunnen we met *cin*
meerdere waarden ontvangen. Dit doen we door meerdere variabelen te koppelen met
dubbele punthaken `>>`. 

In codevoorbeeld 6.2 is hier een voorbeeld van gegeven. Als er meer waarden worden ingevoerd dan er variabelen zijn, wordt wat “over” is
genegeerd.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    float price;
    int quantity;
    cout << "Enter price and quantity: ";
    cin >> price >> quantity;

    float total_price = price * quantity;
    cout << "Total price: " << total_price << "\n";
}
```
*Codevoorbeeld 6.2 Cin - meerdere variabelen*

## Getline
Het scheiden van inputwaarden met spaties kan fijn zijn, maar is meestal niet wat de
gebruiker verwacht. Zeker niet als de gebruiker wordt gevraagd om een string in te
voeren. Met de functie `getline()` kunnen we een hele regel inlezen als één invoer.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    string sentence;
    cout << "Enter a sentence: \n";
    getline(cin, sentence);

    int count = 0;
    for(unsigned int i=0; i<sentence.size(); i++){
        if(sentence[i] == ' '){
            count++;
        }
    }
    cout << "the sentence contains " << count << " spaces\n";
}
```
*Codevoorbeeld 6.3 Getline* 