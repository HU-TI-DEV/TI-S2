![logo](./img/Mqtt-hor.svg.png) [](logo-id)

# MQTT[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [MQTT Integratie met TTN](#mqtt-integratie-met-ttn)
- [Testen van de MQTT verbinding](#testen-van-de-mqtt-verbinding)


---

**v0.1.0 [](version-id)** Start document voor MQTT integratie en installatie instructies door HU IICT[](author-id).

---

## MQTT Integratie met TTN

Login in op The Things Stack sandbox [eu1.cloud.thethings.network](https://eu1.cloud.thethings.network/console/)

Ga naar je applicatie. De applicatie van mij heeft de naam hu-iot-project. In het linker menu Kies voor 'Other integrations'.
Selecteer MQTT. 

![TTN MQTT integration](./img/MQTT_integration.png)

De default instelling zijn goed. 
   
**Public address**:  eu1.cloud.thethings.network:1883  
**Public TLS address**: eu1.cloud.thethings.network:8883  
**Username**:  hu-iot-project@ttn  
**Password**: xxxxxxx(..)xxxxxxxx (verborgen in verband met veiligheid)  

Maak een API key aan door op de knop Generate new API key te klikken
De getoonde key moet je bewaren! En uiteraard niet openbaar zetten in je repo.

Is het niet gelukt of ben je de key vergeten dan kan je de key verwijderen onder je project-naam bij het menu item ‘API keys’.

## Testen van de MQTT verbinding

We gaan nu eerst testen of we een MQTT verbinding kunnen opzetten. Daarvoor gebruiken we een gratis programmaatje [MQTT Explorer](https://mqtt-explorer.com) dat er voor Windows en MacOS is. Als je op MacOS werkt adviseer ik te installeren via de App Store.

Gebruik de credentials die je hebt gemaakt om een nieuwe verbinding (MQTT Connection) te maken. Vergeet niet voor het verbinden op Save te klikken zodat je later makkelijk kunt verbinden. 

![MQTT Explorer](./img/MQTT_Explorer.png)

Je moet even geduld hebben en wachten op het volgende LoRa bericht. Kan je alle informatie terugvinden? Staat je sensor data er ook tussen?

# Referenties

- MQTT (<https://en.wikipedia.org/wiki/MQTT>)
- The Things Network (<https://www.thethingsnetwork.org>)