![logo](../UART/img/UART_block_diagram.svg) [](logo-id)

# UART[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [UART communicatie tussen Raspberry Pi en Arduino](#uart-communicatie-tussen-raspberry-pi-en-arduino)
  - [Handleiding UART communicatie Raspberry Pi - Arduino](#handleiding-uart-communicatie-raspberry-pi---arduino)
  - [Python versie controleren](#python-versie-controleren)
  - [Virtual Environments gebruiken](#virtual-environments-gebruiken)
  - [Informatie opvragen over UARTs](#informatie-opvragen-over-uarts)
  - [Loopback test met Raspberry Pi](#loopback-test-met-raspberry-pi)
  - [Zenden met Raspberry Pi](#zenden-met-raspberry-pi)
  - [Ontvangen met Raspberry Pi](#ontvangen-met-raspberry-pi)
  - [Zenden en ontvangen met Arduino Uno](#zenden-en-ontvangen-met-arduino-uno)
  - [Zenden met Arduino Uno](#zenden-met-arduino-uno)
  - [Ontvangen met Arduino Uno](#ontvangen-met-arduino-uno)
  - [Referenties](#referenties)

---

**v0.1.1 [](version-id)** Start document voor UART door HU IICT[](author-id).

---

## Een introductie

UART staat voor “Universal Asynchronous Receiver/Transmitter”. UART is een asynchrone seriele interface met configuratie mogelijkheden zoals het aantal stopbits en even of oneven pariteit. UART wordt gebruikt voor communicatie met randapparatuur. Een microcontroller heeft meestal een of meerdere UARTs op de chip. UARTs maken vaak gebruik van communicatiestandaarden als RS-232 en RS-422.

  Pariteit is een eenvoudige vorm van foutcontrole. Stuur je data met even pariteit dan moeten alle 1-bits even zijn. Zijn de 1-bits even dan is de pariteit bit 0. Zijn de 1-bits oneven dan is de pariteit bit 1 zodat het totaal weer even is.

  | Data | Aantal 1-bits | Even Pariteit (toegevoegde bit) 
  | --- | --- | --- | 
  | 10101100 | 4 (even) | 0	 
  | 10101101 | 5 (oneven) | 1 

# UART communicatie tussen Raspberry Pi en Arduino

Wil je (sensor)data uitwisselen tussen je Arduino Uno en een Raspberry Pi gebruik dan bij voorkeur UART. Het is relatief eenvoudig. Je hebt maar twee (signaal-)draden nodig. Het is betrouwbaar en je hebt meerdere UARTs tot je beschikking om meerdere Arduino's te koppelen.

> Deze handleiding gaat uit van Raspbian OS (Debian Bookworm). Ubuntu kan ook maar vergt wat meer zelf uitzoeken.

## Handleiding UART communicatie Raspberry Pi - Arduino

Eerst installeer je op de Raspberry Pi ghostwriter om makkelijk `.md` files zoals deze te maken:  

```bash
...$ sudo apt-get install ghostwriter
```

## Python versie controleren

```bash
...$ python --version
```

laat zien: python 3.11.2 is geinstalleerd. (10-2024)

De folder structuur die we maken van het Python project:

- mijn_project
  - venv
  - src
  - tests
  - Readme.md

Thonny schijnt een snelle editor te zijn op Raspberry Pi die gaan we voor dit project gebruiken.

```bash
...$ sudo apt install thonny   # (pre installed on latest release)
```

Als je rechtsboven aanklikt "switch to regular mode" en Thonny herstart dan krijg je de versie met alle opties te zien.

Vanaf de command line kun je dan bijvoorbeeld typen:  

```bash
...$ thonny tests/tmpTest1.py
```

of als de commandline parallel moet blijven werken:

```bash
...$ thonny tests/tmpTest1.py &
```

> Bij het gebruik van Ubuntu vink de optie `Tools` > `Options` > `General` "Use Tk file dialogs instead of Zenity" aan.

## Virtual Environments gebruiken

Je kunt met Python Virtual Environment (venv) een lichtgewicht geisoleerde Python omgeving maken.

Installeer Python venv als volgt:

```bash
...$ sudo apt-get install python3-venv  # (pre installed on latest release)
```

Change directory (`cd`) naar je Python project directory (`mijn_project`) en creeer er dan de folder met de environment:

```bash
...$ python3 -m venv myenv
```

Activeer je venv:  

```bash
...$ source myenv/bin/activate
```

Je ziet dan aan `(myenv)` aan het begin van de command prompt dat je in die environment "zit".

Nu kun je `pip install` gebruiken:

```bash
...$ pip install matplotlib
```

Wat echt nodig is voor UART communicatie:

```bash
...$ pip install pyserial
```

Je code uitvoeren:

```bash
...$ python tests/tmpTest1.py
```

> De venv weer verlaten kan eenvoudig met: **deactivate**

Vervolgens de ingebouwde UART van de Raspberry Pi (uart0) inschakelen via:  

```bash
...$ sudo raspi-config
```

> Voor Ubuntu volg deze [video](https://www.youtube.com/watch?v=rcPYJvVVWsc)

Kies vervolgens:\
-> Interfacing Options -> Serial Port aanzetten.

## Informatie opvragen over UARTs

```bash
...$ cat /boot/overlays/README
```

levert oonder andere informatie over de UARTs, bij mijn Raspberry Pi 4:

```text
Name:   uart0
Info:   Change the pin usage of uart0
Load:   dtoverlay=uart0,  <param>=<val>
Params: txd0_pin                GPIO pin for TXD0 (14, 32 or 36 - default 14)

        rxd0_pin                GPIO pin for RXD0 (15, 33 or 37 - default 15)
    
        pin_func                Alternative pin function - 4(Alt0) for 14&15,
                                7(Alt3) for 32&33, 6(Alt2) for 36&37
Name:   uart1
Info:   Change the pin usage of uart1
Load:   dtoverlay=uart1,<param>=<val>
Params: txd1_pin                GPIO pin forimport serial

Name:   uart2
Info:   Enable uart 2 on GPIOs 0-3. BCM2711 only.
Load:   dtoverlay=uart2,<param>
Params: ctsrts                  Enable CTS/RTS on GPIOs 2-3 (default off)

Name:   uart3
Info:   Enable uart 3 on GPIOs 4-7. BCM2711 only.
Load:   dtoverlay=uart3,<param>
Params: ctsrts                  Enable CTS/RTS on GPIOs 6-7 (default off)

Name:   uart4
Info:   Enable uart 4 on GPIOs 8-11. BCM2711 only.
Load:   dtoverlay=uart4,<param>
Params: ctsrts                  Enable CTS/RTS on GPIOs 10-11 (default off)

Name:   uart5
Info:   Enable uart 5 on GPIOs 12-15. BCM2711 only.
Load:   dtoverlay=uart5,<param>
Params: ctsrts                  Enable CTS/RTS on GPIOs 14-15 (default off)
```

Die BCM2711 is een communicatiechip die Raspberry Pi 4 boardjes hebben.

Voorbeeld:

- Bij `uart2` staat: `gpios 0-3`. Dat impliceert:
- gpio0 = tx, gpio1 = rx, gpio2 = cts en gpio3 = rts
- `cts` (clear to send) en `rts` (request to send) zijn twee signalen die je zou kunnen toevoegen om de UART communicatie betrouwbaarder te maken, maar dat doen we normaal gesproken niet (het verdubbelt het aantal signaallijnen van twee tot vier)

Controleer de UART-GPIO pin mapping voor je eigen boardje:  

```bash
...$ cat /proc/cpuinfo
```

Het kan zijn dat jouw Raspberry Pi 4 een andere versie heeft: BM2835.  

Backup de config file (van Raspbian 'Debian Bookworm'):

```bash
...$ sudo cp /boot/firmware/config.txt /boot/firmware/config.txt.backup 
...$ sudo nano /boot/firmware/config.txt
```

Zorg dat daar in staat:  

```text
enable_uart=1
```

En ook (bijvoorbeeld pas eronder) op basis van het bovenstaande:

```text
dtoverlay=uart0,txd0``_``pin=14,rxd0``_``pin=15  
dtoverlay=uart1,txd1``_``pin=32,rxd1``_``pin=33  
dtoverlay=uart2  
dtoverlay=uart3  
dtoverlay=uart4  
dtoverlay=uart5
```

De bovenstaande pinnen zijn zogenoemde "bcm pinnen".\
Bijvoorbeeld komt "bcm pin 15" overeen met
"pin10 van de connector van de rpi".

Bewaar de veranderingen en reboot:  

```bash
...$ sudo reboot
```

Controleer na het opstarten of het gelukt is met:

```bash
...$ ls /dev/ttyAMA*
```

Als het goed is zie je nu 4 extra uart poorten: `ttyAMA2` tot en met `ttyAMA5` in het lijstje erbij staan.

Welke pinnen gebruikt worden kan je zien met (welke functie op welke pin in je huidige configuratie):

```bash
...$ raspi-gpio get
```

Op 'Debian Bookworm' lijken de nummers gelijk getrokken:

- ttyAMA2 voor uart2
- ttyAMA3 voor uart3
- etc.

## Loopback test met Raspberry Pi

Een test of een UART werkt kan je doen door TX met RX te verbinden dit noemen we een `loopback test`.

- Wat je dan de UART laat zenden moet je ook meteen van de UART kunnen teruglezen.
- Je hebt alleen maar een draadje daarvoor nodig.

Je kunt een `loopback test` uitvoeren op `/dev/ttyAMA3` door pin 4 en 5 te verbinden:

```python
import serial
import time

def send_data_to_serial(port_name, baudrate=9600):
    # Maak een verbinding met de seriële poort
    ser = serial.Serial(port_name, baudrate, timeout=1)

    try:
        while True:
            # Stuur de cijferreeks naar de seriële poort
            ser.write(b'12345\n')
    
            # Wacht een seconde
            time.sleep(1)
            
            data = ser.readline()  # Lees een regel van de seriële poort
            if data:
                print(f"Ontvangen: {data.decode().strip()}")
    except KeyboardInterrupt:
        print("\nProgramma gestopt.")
    finally:
        ser.close()

if __name__ == "__main__":
    PORT_NAME = '/dev/ttyAMA3'  # Aangepast voor de Raspberry Pi
    send_data_to_serial(PORT_NAME)
```

## Zenden met Raspberry Pi

Met de volgende Python code kan je het verzenden testen:

```python
import serial
import time

def send_data_to_serial(port_name, baudrate=9600):
    # Maak een verbinding met de seriële poort
    ser = serial.Serial(port_name, baudrate, timeout=1)

    try:
        print(f"Verzemdem van gegevens op {port_name} ...")
        while True:
            # Stuur de cijferreeks naar de seriële poort
            ser.write(b'12345\n')
    
            # Wacht een seconde
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nProgramma gestopt.")
    finally:
        ser.close()

if __name__ == "__main__":
    PORT_NAME = '/dev/ttyAMA2'  # Aangepast voor de Raspberry Pi
    send_data_to_serial(PORT_NAME)
```

## Ontvangen met Raspberry Pi

Ook het luisteren werkt:

```python
import serial

def listen_to_serial(port_name, baudrate=9600):
    # Maak een verbinding met de seriële poort
    ser = serial.Serial(port_name, baudrate, timeout=1)

    try:
        print(f"Luisteren naar gegevens op {port_name} ...")
        while True:
            data = ser.readline()  # Lees een regel van de seriële poort
            if data:
                print(f"Ontvangen: {data.decode().strip()}")
    except KeyboardInterrupt:
        print("\nProgramma gestopt.")
    finally:
        ser.close()

if __name__ == "__main__":
    PORT_NAME = '/dev/ttyAMA2'  # Voor de Raspberry Pi
    listen_to_serial(PORT_NAME)
```

## Zenden en ontvangen met Arduino Uno

De Arduino Uno beschikt slechts over één enkele Hardware-UART.
Deze Hardware-UART gebruiken we ook voor het uploaden van software op de Arduino (Arduino sketch).

Als we een andere UART willen gebruiken, of meer dan een UART nodig hebben kunnen we een `Software-UART` gebruiken.

- Slimme software vervangt dan de hardware en we kunnen bijna iedere GPIO-pin gebruiken.
- Nadeel is dat het programma groter wordt, dat de processor ermee bezig is. De Software-UART is ook vaak niet zo snel en kan daardoor minder rap data verwerken als met een Hardware-UART.

## Zenden met Arduino Uno

```cpp
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open seriële communicaties en wacht:
  Serial.begin(9600);
  while (!Serial) {
    ; // wacht tot seriële poort verbonden is. Nodig voor native USB-poort alleen
  }

  // stel de data rate in voor de SoftwareSerial-poort:
  mySerial.begin(9600);
}

void loop() { // verstuur de cijferreeks elke 2 seconden
  mySerial.println("12345");
  delay(2000);
}
```

## Ontvangen met Arduino Uno

```cpp
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX (pas dit aan naar jouw pins)

void setup() {
  Serial.begin(9600);      // Start de hardware seriële poort
  mySerial.begin(9600);    // Start de software seriële poort
}

void loop() {
  // Als er data beschikbaar is op de extra UART, print het op de standaard UART
  while (mySerial.available()) {
    char c = mySerial.read();
    Serial.print(c);
  }

  // Als je ook data van de standaard UART naar de extra UART wilt sturen:
  while (Serial.available()) {
    char c = Serial.read();
    mySerial.print(c);
  }
}
```

## Referenties

- UART (<https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter>)
- Thonny (<https://thonny.org/>)
