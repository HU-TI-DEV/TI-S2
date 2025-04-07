# Infrastructuur

- Docker & Docker containers
- Operating Systems & Raspberry Pi OS

## Voorbereiding

Lees de introductie van de [Raspberry Pi computer](../../hardware-interfacing/embedded/computer/Raspberry-Pi/README.md) en de inleiding van [Docker containers](../../infrastructuur/Docker/README.md).

## Dit hebben we in een vorige les gedaan

Installeer een [Operating System (OS)](../../infrastructuur/OS/Raspberry-Pi-OS/README.md) op de Raspberry Pi. Zorg dat deze toegang heeft tot iotroam en maak toegang via ssh mogelijk. 

    Maak eventueel gebruik van Eduroam als iotroam problemen geeft.

## Eduroam

Onze voorkeur heeft dat je gebruik maakt van iotroam. Dit wifi netwerk is speciaal geschikt gemaakt voor dit soort type devices en toepassingen. Mocht je veel problemen ondervinden zou je kunnen terugvallen op Eduroam.

Gebruik dit script en de LCD opstelling om het IP adres van de Raspberry Pi te achterhalen [RaspberryPI - Show IP and Time on LCD on startup](https://github.com/RickMageddon/RaspberryPI-LCD-IPonStartup). Je kunt ook verbinding maken met de hostnaam van je device mits deze uniek is. 

## Tijdens de les

Installeer [Docker](../../infrastructuur/Docker/README.md) en start en configureer de volgende Docker containers: Postgres, [MQTT](../../software/communicatie/MQTT/README.md), [Node-RED](../../software/visueel-programmeren/Node-RED/README.md) en [Flask](../../software/webserver/Flask/README.md). De installatie instructies kan je [hier](../../infrastructuur/OS/Raspberry-Pi-OS/README.md) vinden.

Opdracht: Post een bericht (publish) met Mosquitto op een centrale MQQT browser die we tijdelijk configureren voor deze les. Ieder team zorgt er **in de les** daarnaast voor dat er data van een sensor uit jullie project op een topic komt te staan. Gebruik de eerder lesstof met betrekking tot [UART](../../hardware-interfacing/communicatie/UART/README.md) om de data naar je Raspberry Pi te versturen. Maak als team een verslag en plaatst dit op jullie groeps-repository.

## Portfolio-Tip

De komende dagen verzinnen en maken jullie zelf een oplossing met behulp van bovenstaande software paketten. Bijvoorbeeld:
- Het opslaan van weergegevens uit een weer API in een database.
- Meten van temperatuur en opslag van deze data in een database.
- Het tonen van metingen in je project op een Flask webpagina.
- Het publiceren van temperatuur-, rv- (relatieve luchtvochtigheid), CO2 of fijnstof metingen op een MQTT server. 
