# Opdrachten Meerdere bronbestanden C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Meerdere bronbestanden C++](#opdrachten-meerdere-bronbestanden-c)
    - [Inhoud](#inhoud)
    - [Opdracht 4.2 TV sensatie](#opdracht-42-tv-sensatie)
      - [Tips voor VS code gebruikers](#tips-voor-vs-code-gebruikers)


### Opdracht 4.2 TV sensatie
De TV-sensatie “Heel Idols bakt a Voice on Ice with Stars Island” is bijna afgelopen.
Tijdens de finale willen de producenten zo snel mogelijk de winnaar berekenen. 

- De *winnende score* is de score die het dichtst bij de gemiddelde score zit. Daarnaast moet
worden bepaald wie de mol is, want die zoekt een boer. 
- De *mol* is de deelnemer die de
score heeft met het grootste verschil met de winnaar.

Schrijf een programma die deze berekeningen uitvoert. Een header-file en de main-file
zijn al geschreven. Verander de source file `winners.cpp` zodat het programma werkt.

#### Tips voor VS code gebruikers
Check je `tasks.json` file:

`"${workspaceFolder}/*cpp"` werkt niet als je meerdere mapjes aan hebt gemaakt in je workspace folder.

`"${fileDirname}\*.cpp"` is een beter alternatief als al je .cpp en .hpp files in 1 map hebt staan.
Met dank aan [@Aimane0](https://github.com/Aimane0).

**winners.hpp**:
```c++
#ifndef WINNERS_HPP
#define WINNERS_HPP

#include <vector>
#include <iostream>

using namespace std;

float nearestScore2Average(const vector<float>& scores);
float furthestScoreFromWinner(const vector<float>& scores);

#endif /* WINNERS_HPP */
```
**main.cpp**:
```c++
#include "winners.hpp"

int main(){
  vector<float> results {5.322,8.76,2.12,745,98.1,23.6,87.3};

  float winner = nearestScore2Average(results);
  float mole = furthestScoreFromWinner(results);

  cout << "De winnaar is: " << winner << "\n";
  cout << "De mol is: " << mole << "\n";

  return 0;
}
```

**winners.cpp**:
```c++
#include "winners.hpp"

float nearestScore2Average(const vector<float>& scores) { return 0.0; }
float furthestScoreFromWinner(const vector<float>& scores) { return 0.0; }
```