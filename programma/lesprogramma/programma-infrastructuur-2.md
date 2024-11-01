# Infrastructuur

- Docker & Docker containers
- Operating Systems & Raspberry Pi OS

## Voorbereiding

Lees de introductie van de [Raspberry Pi computer](../../hardware-interfacing/embedded/computer/Raspberry-Pi/README.md) en de inleiding van [Docker containers](../../infrastructuur/Docker/README.md).

## Dit hebben we in een vorige les gedaan

Jullie hebben een [Operating System (OS)](../../infrastructuur/OS/Raspberry-Pi-OS/README.md) op de Raspberry Pi geinstalleerd. 
Daarnaast hebben jullie nu een werkende [Docker](../../infrastructuur/Docker/README.md) emet de volgende Docker containers: Postgres, [MQTT](../../software/communicatie/MQTT/README.md), [Node-RED](../../software/visueel-programmeren/Node-RED/README.md) en [Flask](../../software/webserver/Flask/README.md). De installatie instructies kan je [hier](../../infrastructuur/OS/Raspberry-Pi-OS/README.md) vinden.

## Tijdens de les

Opdracht: Sluit een temperatuur-sensor aan op een Arduino Uno. Zet een UART communicatie op via de Raspberry Pi en sla de data op in een database. Post de laatste sensor uitlezing op MQTT. Maak eventueel een eenvoudige website met Flask of een dashboard via Node-Red. 

UML Daigram

![Diagram](./files/Flask_workshop.drawio.svg)

## Portfolio-Tip

De komende dagen verzinnen en maken jullie zelf een oplossing met behulp van bovenstaande software paketten. Bijvoorbeeld:
- Het opslaan van weergegevens uit een weer API in een database.
- Meten van temperatuur en opslag van deze data in een database.
- Het tonen van metingen in je project op een Flask webpagina.
- Het publiceren van temperatuur-, rv- (relatieve luchtvochtigheid), CO2 of fijnstof metingen op een MQTT server. 
