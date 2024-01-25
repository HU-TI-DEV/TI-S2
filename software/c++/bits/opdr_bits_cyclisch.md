# Opdrachten Bits C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Bits C++](#opdrachten-bits-c)
    - [Inhoud](#inhoud)
    - [Opdracht 4.6 Verschuif Cyclisch](#opdracht-46-verschuif-cyclisch)
      - [Voorbeeld 1](#voorbeeld-1)
      - [Voorbeeld 2](#voorbeeld-2)


### Opdracht 4.6 Verschuif Cyclisch
Schrijf een functie met twee parameters. De eerste parameter, *ch*, is een uint8_t. De
tweede parameter, n, geeft aan hoeveel posities de bitjes van *ch* opgeschoven moeten
worden. Als n > 0 is dan worden de bitjes naar links geschoven. Als n < 0 is dan worden
de bitjes naar rechts geschoven. De bitjes die wegvallen worden aan de andere kant van
de byte weer teruggeplaatst.

#### Voorbeeld 1
*ch* met bitwaarde 10110001 en n is gelijk aan 3 resulteert in een *ch* met de bitwaarde:
`10001101`.

#### Voorbeeld 2
*ch* met bitwaarde 10111000 en n is gelijk aan -4 resulteert in een *ch* met de bitwaarde:
`11000101`.