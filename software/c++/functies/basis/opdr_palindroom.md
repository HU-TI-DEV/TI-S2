# Opdrachten Functies, basis [](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht 2.12 Palindroom](#opdracht-212-palindroom)
  - [2.12 A:](#212-a)
  - [2.12 B:](#212-b)

### Opdracht 2.12 Palindroom
De onderstaande functie controleert of een string een palindroom is. 
Een **palindroom** is een woord dat hetzelfde blijft als je het woord omdraait. Voorbeelden van palindromen zijn: *kok, lepel, meetsysteem*. 
De functie palindroom maakt gebruik van de functie `reverse()` die een string omdraait.

#### 2.12 A:
Schrijf een functie `reverse()`  die een string omdraait. 
- Je mag hiervoor geen nieuwe string
of vector aanmaken en 
- je mag niet gebruik maken van de swap-functie die wordt gegeven door C++ (libraries). 
- Je mag hiervoor wel een nieuwe tijdelijke character variabele gebruiken*.
- Zorg dat de functie werkt in de onderstaande functie `isPalindroom()`. 
- Test de functie met de volgende woorden: stekkerdoos, Halloween, lepel, flesje en bommelding*.

```c++
bool isPalindroom(const string& word){
  string orginalWord = word;
  reverse(orginalWord);
  for(unsigned int i=0; i<word.size(); i++){
    if(word[i] != orginalWord[i]){
      return false;
    }
  }
  return true;
}
```
*Zie hiervoor de sectie “Waarden omwisselen” in de reader.
**De omgedraaide versies van deze woorden zijn: *soodrekkets, neewollaH, lepel, ejself, en gindlemmob*.

#### 2.12 B:
De bovenstaande gegeven functie `isPalindroom()` is eigenlijk niet zo heel mooi. Het
is namelijk helemaal niet nodig om de reverse functie te gebruiken. 
Schrijf je eigen `isPalindroom()` functie die zonder het woord om te draaien of te kopieren controleert of het woord een palindroom is. 
Hint: word[word.size-1] geeft de laatste letter van het woord.