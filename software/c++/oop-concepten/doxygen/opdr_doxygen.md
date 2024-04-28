# Opdrachten Doxygen C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Doxygen C++](#opdrachten-doxygen-c)
    - [Inhoud](#inhoud)
    - [Achtergrondinformatie](#achtergrondinformatie)
    - [Opdracht OO2.2 Doxygen](#opdracht-oo22-doxygen)


### Achtergrondinformatie
Links naar meer informatie:
- [Lesmateriaal](README.md).
- [Codevoorbeelden van Doxygen zelf](https://www.doxygen.nl/manual/docblocks.html#docexamples)
- [Installeer Doxygen](https://www.doxygen.nl/manual/install.html), indien nodig. Zie: [Doxygen downloads](https://www.doxygen.nl/download.html)
- Voeg doxygen aan je (Windows) path toe. 

### Opdracht OO2.2 Doxygen
- Kopieer de inhoud van de [rational.hpp](./rational.hpp) file naar je eigen ontwikkelomgeving (maak een nieuwe directory).
- Run vervolgens Doxygen in de directory: `doxygen -g`
  Als doxygen niet herkend wordt, check dan je installatie en het pad (zie boven).
- Bekijk de documentatie: er is nu een Doxyfile configuratiebestand aangemaakt. Je kunt dit bestand ook ongewijzigd laten.
- Run vervolgens nogmaals doxygen maar nu zonder opties: `doxygen`.
- Let goed op de uitvoer in de terminal.
- Er ontbreekt Doxygen documentatie voor één operator (bij het genereren geeft Doxygen een warning). Voeg die documentatie toe en genereer de documentatie opnieuw. 
- Check in de Doxygen uitvoer dat die operator nu wel goed gedocumenteerd is. 
- Zorg dat bij het inleveren de gegenereerde documentatie *niet* wordt meegenomen (via .gitignore).