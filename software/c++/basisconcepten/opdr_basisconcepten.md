# Opdrachten Basisconcepten C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Basisconcepten C++](#opdrachten-basisconcepten-c)
    - [Inhoud](#inhoud)
  - [Opdracht 1.0 Hello, project](#opdracht-10-hello-project)
  - [Opdracht 1.1 Hello world commentaar](#opdracht-11-hello-world-commentaar)
  - [Opdracht 1.2 Naam en studentnummer](#opdracht-12-naam-en-studentnummer)
  - [Opdracht 1.3 Spelen met fouten](#opdracht-13-spelen-met-fouten)


## Opdracht 1.0 Hello, project

- Draai de code uit *Codevoorbeeld 2.1 hello, world*
- Pas de code aan zodat het programma iets over je project print. Bijvoorbeeld:
`"Hello, greenhouse!"` of `"Hello, climate monitor!"`.

```c++ {.line-numbers}
#include <iostream> 
using namespace std;

int main(){ 
    cout << "hello, world\n"; 
}
```
*Codevoorbeeld 2.1 hello, world*

## Opdracht 1.1 Hello world commentaar
Bestudeer *Codevoorbeeld 2.2 Programma met commentaar in de code, in [basisconcepten](README.md)*
- 1.1.a Voeg een regel commentaar toe aan het main programma en run het programma.

## Opdracht 1.2 Naam en studentnummer
Zet je naam en studentnummer in commentaar bovenaan je programma. 
Probeer dit altijd te doen. Kijk zelf of je een bepaalde layout hiervoor kiest. Vraag je projectdocenten welke gegevens je voor je project kunt toevoegen.

## Opdracht 1.3 Spelen met fouten
Gebruik codevoorbeeld 2.1:
- 1.3.a Verwijder de `';'` in de regel `cout << "hello, world\n";` en run het programma. Wat gebeurt er? 
  
Zet de `';'` weer in de code.
- 1.3.b Verwijder de `'}'` in de laatste regel en run het programma. Wat gebeurt er?

Het is handig om foutmeldingen te leren herkennen. 
- 1.3.b Probeer zelf om andere fouten te genereren. Kijk welke meldingen dit oplevert.