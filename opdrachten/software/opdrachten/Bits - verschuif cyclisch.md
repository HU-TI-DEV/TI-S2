# Opdrachten Bits C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht 4.6 Verschuif Cyclisch](#opdracht-46-verschuif-cyclisch)
  - [Voorbeeld 1 - cyclisch links](#voorbeeld-1---cyclisch-links)
  - [Voorbeeld 2 - cyclisch rechts](#voorbeeld-2---cyclisch-rechts)


## Opdracht 4.6 Verschuif Cyclisch
Schrijf een functie met twee parameters. 
- De eerste parameter, *ch*, is een uint8_t. 
- De tweede parameter, n, is een int8_t en geeft aan hoeveel posities de bitjes van *ch* opgeschoven moeten
worden:
  - Als n > 0 is dan worden de bitjes naar links geschoven. 
  - Als n < 0 is dan worden de bitjes naar rechts geschoven. 
  - De bitjes die wegvallen worden aan de andere kant van de byte weer teruggeplaatst.

### Voorbeeld 1 - cyclisch links
- *ch* met bitwaarde `10110001`
- n is gelijk aan 3

resulteert in een *ch* met de bitwaarde: `10001101`.  
Merk op dat de 3 linkerbits `101` die 'eraf' vallen aan de rechterkant worden ingeschoven.

### Voorbeeld 2 - cyclisch rechts
- *ch* met bitwaarde `10010110`
- n is gelijk aan -4

resulteert in een *ch* met de bitwaarde: `01101001`.  
Merk op dat de 4 rechterbits `0110` die 'eraf' vallen aan de linkerkant worden ingeschoven.



Ander leermateriaal:
- [Binary Logical Shifts](https://youtu.be/C_MJ-UW1HkY).
- [Circular shift](https://en.wikipedia.org/wiki/Circular_shift)
