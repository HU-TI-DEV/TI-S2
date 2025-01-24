# Infrastructuur

- Docker & Docker containers
- Operating Systems & Raspberry Pi OS

## Voorbereiding

Lees de introductie van de [Raspberry Pi computer](../../hardware-interfacing/embedded/computer/Raspberry-Pi/README.md) en de inleiding van [Docker containers](../../infrastructuur/Docker/README.md).

## Dit hebben we in een vorige les gedaan

Installeer een [Operating System (OS)](../../infrastructuur/OS/Raspberry-Pi-OS/README.md) op de Raspberry Pi. Zorg dat deze toegang heeft tot Eduroam en maak toegang via ssh mogelijk.

Gebruik dit script en de LCD opstelling van om de IP van de Raspberry Pi te achterhalen [RaspberryPI - Show IP and Time on LCD on startup](https://github.com/RickMageddon/RaspberryPI-LCD-IPonStartup). Je kunt ook verbinding maken met de hostnaam van je device mits deze uniek is. 

## Tijdens de les

Installeer [Docker](../../infrastructuur/Docker/README.md) en start en configureer de volgende Docker containers: Postgres, [MQTT](../../software/communicatie/MQTT/README.md), [Node-RED](../../software/visueel-programmeren/Node-RED/README.md) en [Flask](../../software/webserver/Flask/README.md). De installatie instructies kan je [hier](../../infrastructuur/OS/Raspberry-Pi-OS/README.md) vinden.

Opdracht: Post een bericht (publish) met Mosquitto op een centrale MQQT browser die we tijdelijk configureren voor deze les.

## Portfolio-Tip

De komende dagen verzinnen en maken jullie zelf een oplossing met behulp van bovenstaande software paketten. Bijvoorbeeld:
- Het opslaan van weergegevens uit een weer API in een database.
- Meten van temperatuur en opslag van deze data in een database.
- Het tonen van metingen in je project op een Flask webpagina.
- Het publiceren van temperatuur-, rv- (relatieve luchtvochtigheid), CO2 of fijnstof metingen op een MQTT server. 
