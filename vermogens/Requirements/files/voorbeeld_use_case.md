# Voorbeeld: Use case diagram Watersysteem
![Use case diagram](UseCaseDiagram.png)

# UC01 – Watersysteem
## Actor
Gebruiker, Plant

## Scenario
### Scenario 1: Waterreservoir vullen
1. Op dashboard aangeven dat waterreservoir gevuld wordt.
2. Waterreservoir vullen
3. Op dashboard aangeven dat waterreservoir gevuld is.

### Scenario 2: Afvoerreservoir legen
1. Op dashboard aangeven dat afvoerreservoir geleegd wordt.
2. Afvoerreservoir legen
3. Op dashboard aangeven dat afvoerreservoir geleegd is.

### Scenario 3: Planten water geven
1. Watersysteem configuratie ophalen.
2. Wachten op geconfigureerde water geef moment.
3. Planten water geven doormiddel van planten bak vullen.
4. Wachten op geconfigureerde water opneem duur.
5. Planten water bak legen.
6. Controleren waterniveau waterreservoir.
7. Controleren waterniveau afvoerreservoir.
8. Informatie updaten op het dashboard.

## Preconditie
- Er moet informatie zijn voor wat het watersysteem moet doen en hoe.
- Er moet water in het waterreservoir zijn.
- Er moet voldoende ruimte zijn in het afvoerreservoir.
- Het waterreservoir moet niet actief gevuld worden.
- Het afvoerreservoir moet niet actief geleegd worden.

## Postconditie
- De plant heeft water gekregen.
- Er is gecontroleerd dat het waterreservoir vol is en het afvoerreservoir leeg is.
- Er is informatie gegeven aan het dashboard over dat er water is gegeven, hoe vol het waterreservoir is en hoe vol het afvoerreservoir is.

## Uitzondering
- Wanneer er geen informatie is over wat het watersysteem moet doen, moet hier een melding van gemaakt worden.
- Wanneer er geen water in het waterreservoir is, moet hier een melding van gemaakt worden.
- Wanneer er geen ruimte is in het afvoerreservoir, moet hier een melding van gemaakt worden.
- Het systeem kan niet beginnen wanneer een reservoir geleegd of gevuld wordt.