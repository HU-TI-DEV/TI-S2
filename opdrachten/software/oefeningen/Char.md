# Opdrachten Char C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

### Opdracht 1.6 — char plus int
Schrijf een programma dat:
- om een char vraagt, 
- deze inleest, 
- bij de char 32 optelt, 
- de som afdrukt, 
- de uitkomst afdrukt als integer 
- en de uitkomst afdrukt als character. 
  
Een voorbeeld van de in- en output:

```console
> Geef een character: B
B + 32 = 98
B + 32 = b
```

### Opdracht 1.7 1337

Wim, docent aardrijkskunde, heeft problemen met de communicatie met zijn studenten.
Volgens zijn manager komt dat doordat Wim en de leerlingen beide een andere taal spreken. 
Wim snapte niet wat zijn manager bedoelde, maar na wat googlen vond hij `1337-speak`. Wim is nog maar een *n00b*, dus help hem door een vertaalprogramma te
schrijven.

Het programma vraagt de gebruiker om invoer. Vervolgens wordt de invoer afgedrukt,
maar met de volgende aanpassingen:
- Elke ’e’ wordt afgedrukt als ’3’
- Elke ’l’ (letter) wordt afgedrukt als ’1’ (getal)
- Elke ’t’ wordt afgedrukt als ’7’
- Elke ’o’ wordt afgedrukt als ’0’
- Elke andere letter wordt afgedrukt als hoofdletter
  
Uiteraard mag je de vertaling nog meer hax0r maken.
*Gebruik niet de C++ (librarie) functies toupper(), transform() en replace().*

De uitvoer van het programma kan er zo
uitzien:
```console
> Geef een string om te vertalen:
We are going to have fun in school.
1337-speak:
W3 AR3 G0ING 70 HAV3 FUN IN SCH001.
```