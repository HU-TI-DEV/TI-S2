# Opdrachten Classes C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht OO1.6 Samengesteld object](#opdracht-oo16-samengesteld-object)


### Opdracht OO1.6 Samengesteld object
*Maak eerst opdracht [OO1.5, Gevulde rechthoek](./opdr_rechthoek.md)*.

- Gebruik de code van opgave [OO1.5 Gevulde rechthoek](./opdr_rechthoek.md) als uitgangspunt. 
- Maak een samengestelde klasse voor een grafisch object (cpp en hpp files) dat (ten minste) het volgende moet bevatten:
  - 1 **rechthoek** (de bestaande of de in de vorige opgave gemaakte gevulde rechthoek),
  - 1 **lijn**
  - 1 **cirkel**.
De samengestelde klasse is dus een compositie van meerdere klassen.
- Van de basis objecten (rechthoek, lijn, cirkel) moet er tenminste 1 meer dan 1x gebruikt worden.

Verdere vereisten:
- Het grafische object moet iets *herkenbaars* zijn. Bijvoorbeeld: een huis, trein, wolkenlucht, fabriek, pacman.
- De constructor van jouw object moet (ten minste) 1 parameter hebben *die het aantal 'onderliggende' objecten aanpast*. Bijvoorbeeld voor een trein het aantal wagons; voor een huis het aantal ramen, etc.
- Maak een UML-diagram met:
  - jouw samengestelde klasse, 
  - de onderliggende klassen en 
  - de window klasse.
- Demonstreer jouw klasse in een applicatie (lees: een `main.cpp`) die er (ten minste) twee verschillende varianten van afbeeldt door de constructor met verschillende parameters aan te roepen.
