# Char [](title-id)

### Inhoud[](toc-id)
- [Char ](#char-)
    - [Inhoud](#inhoud)
  - [Character](#character)
    - [Char](#char)
    - [Aanhalingstekens](#aanhalingstekens)
    - [Rekenen met char](#rekenen-met-char)
  - [Referenties](#referenties)

---

## Character
Voor losse karakters heeft C++ een apart datatype: character. Dit geven we aan met het sleutelwoord *char*. Een variabele met het type character kan enkel één character-waarde bevatten. Characters worden opgeslagen volgens de ASCII codering. Voor meer informatie, zie: https://en.wikipedia.org/wiki/ASCII.

*Codevoorbeeld 3.5* geeft voorbeeldcode voor het werken met characters.

```c++
#include <iostream>
using namespace std;

int main() {
    char letter = 'd';
    cout << "letter: " << letter << "\n";
    // letter: d

    char result1 = letter + 1;
    cout << "result1: " << result1 << "\n";
    // result1: e

    char result2 = 'c' - 'a';
    cout << "result2: " << int(result2) << "\n";
    // result2: 2
}
```
*Codevoorbeeld 3.5 Characters*

### Char
Met het sleutelwoord char geven we aan dat een variabele van het datatype character is.

### Aanhalingstekens
Let op bij het gebruik van (literal) [strings](../data-types/string/README.md) en chars goed op de aanhalingstekens. Enkele aanhalingsteken (bijvoorbeeld ‘t’) geven aan dat het van het type char is en dus één karakter is. Dubbele aanhalingstekens (bijvoorbeeld: “t”) geven aan dat het van het type literal string is en dus één of meerdere karakters kunnen zijn.

### Rekenen met char
Er is in C++ een sterke relatie tussen integers en characters. Dit zorgt ervoor dat we characters kunnen initialiseren met een integer en een integer met een character*. Daarbij zorgt het er ook voor dat we kunnen rekenen met characters. Het opslaan van integers in characters (en andersom) maakt je code minder leesbaar, dus dat doen we niet. Door hoe ASCII is ingericht kan rekenen met characters wel zin hebben. Bijvoorbeeld door twee hoofdletters of twee kleine letters van elkaar af te trekken kunnen we bepalen hoeveel posities ze van elkaar verwijderd zijn in het alfabet.

**Pas wel op bij initialisatie van een character-variabele met een integer. Een integer variabele heeft meer geheugen beschikbaar dan een character (meestal 4 bytes tegenover 1 byte). We kunnen dus in een integer variabelen grotere getallen opslaan dan in characters.*

## Referenties

- ASCII (<https://en.wikipedia.org/wiki/ASCII>)