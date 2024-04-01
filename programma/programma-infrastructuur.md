# Infrastructuur

- Docker & Docker containers
- Operating Systems & Raspberry Pi OS

## Voorbereiding

Lees de introductie van de [Raspberry Pi computer](../hardware-interfacing/embedded/computer/README.md) en de inleiding van [Docker containers](../infrastructuur/Docker/README.md).

## Tijdens en na de les

[Installeer](../infrastructuur/OS/Raspberry-Pi-OS/README.md) een Operating System (OS) op de Raspberry Pi. Zorg dat deze toegang heeft tot Eduroam en maak toegang via ssh mogelijk.

Gebruik dit script en de LCD opstelling van om de IP van de Raspberry Pi te achterhalen [RaspberryPI - Show IP and Time on LCD on startup](https://github.com/RickMageddon/RaspberryPI-LCD-IPonStartup). Je kunt ook verbinding maken met de hostnaam van je device mits deze uniek is. 

[Installeer](../infrastructuur/Docker/README.md) Docker en start en configureer de volgende Docker containers: Postgres, [MQTT](../software/communicatie/MQTT/README.md), [Node-RED](../software/visueel-programmeren/Node-RED/README.md) en [Flask](../software/webserver/Flask/README.md)

## Portfolio-Tip

De komende dagen verzinnen en maken jullie zelf een oplossing met behulp van bovenstaande software paketten. Bijvoorbeeld:
- Het opslaan van weergegevens uit een weer API in een database.
- Meten van temperatuur in je kas en opslag in een database.
- Het tonen van meetingen in de kas op een Flask webpagina.
- Het publiceren van temperatuur en vochtigheid op een MQTT server. 

Aan het eind van de week presenteer je als team een zelf gekozen oplossing voor de klas (max. 5 min.).  