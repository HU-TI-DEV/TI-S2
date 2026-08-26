# Opdrachten Doxygen C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Achtergrondinformatie](#achtergrondinformatie)
- [Opdracht OO2.2 Doxygen](#opdracht-oo22-doxygen)


### Achtergrondinformatie
Links naar meer informatie:
- [Lesmateriaal](README.md).
- [Codevoorbeelden van Doxygen zelf](https://www.doxygen.nl/manual/docblocks.html#docexamples)
- [Installeer Doxygen](https://www.doxygen.nl/manual/install.html), indien nodig. Zie: [Doxygen downloads](https://www.doxygen.nl/download.html)
- Na installatie/uitpakken: voeg de map waarin het bestand doxygen.exe staat aan je (Windows) path toe. Herstart VS Code.
- Check in een Terminal (CMD) of doxygen herkend wordt: `doxygen -v`.

### Opdracht OO2.2 Doxygen
- Kopieer de inhoud van de [rational.hpp](./rational.hpp) file naar je eigen ontwikkelomgeving (maak een nieuwe directory).
- Open een terminal (CMD) en ga naar de nieuwe directory.
- Run vervolgens Doxygen in de net aangemaakte directory met optie '-g': `doxygen -g`
  Als doxygen niet herkend wordt, check dan je installatie en het pad (zie boven).
- Bekijk de documentatie: er is nu een Doxyfile configuratiebestand aangemaakt. Je kunt dit bestand aanpassen of ongewijzigd laten.
- Run vervolgens nogmaals doxygen maar nu zonder opties: `doxygen`.
- Let goed op de uitvoer in de terminal.
- Er ontbreekt Doxygen documentatie voor één operator (bij het genereren geeft Doxygen een warning). Voeg die documentatie toe en genereer de documentatie opnieuw. 
- Check in de Doxygen uitvoer dat de betreffende operator nu wel goed gedocumenteerd is. 
- Zorg dat bij het inleveren de gegenereerde documentatie *niet* wordt meegenomen (via .gitignore).