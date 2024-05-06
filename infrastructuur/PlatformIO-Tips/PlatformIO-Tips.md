# PlatformIO - Tips

## Installatie op VSCode

- Ga naar "Extensions" zijbalk.

- Kies "PlatformIO IDE" -> install

- Herstart VSCode

- Er is nu een PlatformIO Home button in de zijbalk (een alien)

- Klik er op

- Je kunt nu een project aanmaken (ik prefereer in een handmatig gekozen folder)

- Zet dit (igv arduino uno) in de platformio.ini file
  [env:uno]
  
  platform = atmelavr
  
  board = uno
  
  framework = arduino
  
  upload_port = COM9
  
  monitor_port = COM9
  
  monitor_speed = 9600

- Pas de COM ports en speeds aan 

- Gebruik wat standaard Arduino Code (platformio is daar compatibel mee)

- PlatformIO Home Button -> Upload and Monitor

## Verdere wetenswaardigheden

- Begin je code met #include <Arduino.h> om de vanilla arduino-ide compatible commando's voor pinnen, I2C etc te gebruiken.

- Additionele libraries kun je copieren in de lib folder.

- Include files in de include folder.

- Die folders en ook de structuur erbinnen komen overeen met wat je gewend bent van Arduino IDE.

- Je kunt ook libraries toevoegen door op de libraries button te klikken en je library als zoekterm in te typen. Dependencies worden meestal automatisch meegeinstalleerd.

- Soms komen die libs dan niet in de lib folder terecht, maar ergens anders.

## Praktische issues en oplossingen

### PIO Home button werkt niet meer

<img src="file://D:\OneDrive\OneDrive - Stichting Hogeschool Utrecht\MaveHU\Docs\Mijn Lessen\S2\OOPC-voor-S2\img\screenshot-error2.png?msec=1714984658607" title="" alt="" width="452">

Oplossing: herstarten van VSCode (?!)

### Compiler geeft error bij aanroep van functies die verderop gedeclareerd worden

De compiler van PlatformIO is daarin wat strenger dan die van de Arduino IDE.
Je kunt dat oplossen door functie declaraties en implementaties in aparte files te zetten of bovenaan forward declaraties van de betreffende functies toe te voegen.
