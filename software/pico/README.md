## Gebruik van Pico SDK

**11 oktober 2025**

De test is doorlopen op een M4 Mac mini met besturingssysteem macOS 15.7.1. Ik heb gebruik gemaakt van de Visual Studio Code met de Raspberry Pi Pico extension versie 0.19.0

Zie de [handleiding](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
Ik heb de requirements (`$ xcode-select --install`) niet hoeven uitvoeren omdat ik dit al eerder heb gedaan.

Installeer de extensie.

![Pico SDK extension](./img/Screenshot%202025-10-10%20at%2016.45.25.png)

Bij het openen van je eerste project begint eigenlijk de SDK installatie pas. De SDK komt bij mij te staan onder "/Users/hwsnippe/.pico-sdk" (een verborgen map). De SDK versie op dit moment is 2.2.0.

Links in het menu komt er een Pico board logo bij. Kies voor `New C/C++ Project`. 

![New Project](./img/Screenshot%202025-10-10%20at%2016.49.48.png)

Vervolgens de volgende instellingen gebruiken:
- Geef je project een naam
- Board type is Pico W (gebruikt in Semester 1)
- aanvinken Console over USB
- aanvinken Generate C++ code

![New Project](./img/Screenshot%202025-10-11%20at%2015.04.37.png)

Onder in het scherm kan je het project dan compileren (Compile) en op de Pico Flashen (Run). Daat gaat dan op de BOOTSEL (Boot Select) manier. De bootknop van de Pico inhouden en dan verschijnt de Pico als USB device ('RPI-RP2'). Je zet dan het UF2 bestand op de microcontroller.

![Compile and Run](./img/Screenshot%202025-10-11%20at%2012.31.49.png)

Via de Serial Monitor tabblad kan je serial data via USB lezen. Ik moet kiezen voor mijn device op `/dev/tty.usbmodem212401 - Raspberry Pi`. Klik op Start monitoring voor de console out berichten (printf).

![Serial monitor](./img/Screenshot%202025-10-11%20at%2012.11.35.png)

In Semester 2 is de eerste hardware opdracht met de Arduino Uno het [uitlezen van een analoge pin](https://github.com/HU-TI-DEV/TI-S2/blob/main/hardware-interfacing/communicatie/analoog-en-digitaal/ADC/LDR-NTC.md#arduino-voorbeeld-code). De code is als volgt:

```cpp
// LDR-NTC.ino - Analog Input example - 2024-02-04-hp
// Tested on Arduino Nano
// [+5V]---[=LDR or NTC_10K=]---[A0]---[=10k=]---[GND]

const long baudrate = 9600;
const int  delaytime_ms = 1000; // delay 1000ms = 1s

const int pinAnalogIn = A0;
int dataAnalogIn = 0;

// The Arduino Analog-to-Digital Converter (ADC) has 10 bit resolution.
// Each measurement results in a number from 0 to 1023.
// Arduino Uno and Arduino Nano map this to a range from 0 Volts to 5 Volts.
const float analogDataToVolt = 5.0 / 1024;

void setup() {
  pinMode(pinAnalogIn, INPUT);
  // Initialize serial interface and wait for port to open:
  Serial.begin(baudrate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("LDR-NTC.ino - Analog Input example");
}

void loop() {
  dataAnalogIn = analogRead(pinAnalogIn);
  Serial.print("Analog input value: ");
  Serial.print(dataAnalogIn);
  Serial.print(" - Voltage: ");
  Serial.println(dataAnalogIn * analogDataToVolt);
  delay(delaytime_ms);
}

//EOF
```

Met de Pico SDK kom ik tot de volgende code:

```cpp
// LDR-NTC.cpp - Analog Input example - 2025-10-11-noharm
// Tested on Raspberry Pi Pico W
// [+3V3]---[=LDR or NTC_10K=]---[GPIO 26 (ADC0)]---[=10k=]---[GND]
#include <stdio.h>
#include "hardware/adc.h"
#include "pico/stdlib.h"

// The Pico Analog-to-Digital Converter (ADC) has 12 bit resolution.
// Each measurement results in a number from 0 to 4095.
// The Pico maps this to a range from 0 Volts to 3.3 Volts.
static constexpr uint LDR_PIN = 26;   // GPIO26 = ADC0
static constexpr uint LDR_CH   = 0;    // ADC channel 0
static constexpr uint VREF_MV  = 3300; // 3.3 V reference in millivolts

int main()
{
    stdio_init_all();
    adc_init();
    
    adc_gpio_init(LDR_PIN);
    adc_select_input(LDR_CH);

    while (true) {
        uint16_t raw = adc_read();  // 12-bit raw value [0–4095]
        // Convert to millivolts (integer math)
        uint32_t mv = (static_cast<uint32_t>(raw) * VREF_MV) / 4095;

        printf("ADC raw=%u, ~%lumV\n", raw, mv);
        sleep_ms(500);
    }
}
//EOF
```

In de CMakesLists.txt moet je bij **target_link_libraries** 

![CMakesLists.txt](./img/Screenshot%202025-10-11%20at%2015.08.15.png)

de `hardware_adc` aan de lijst toevoegen.

![hardware ADC](./img/Screenshot%202025-10-11%20at%2015.08.35.png)

Het proces is met de VSC plugin redelijk eenvoudig. De BOOTSEL werkwijze is niet erg handig. Ik krijg daarnaast na een succesvol schrijven 'Disk not properly ejected' foutmelding van mijn besturingssysteem.

    Complexe projecten met submappen kan je zo niet maken echter kan je CMAKE zo configureren dat het wel kan.

De GPIO pin 26 heb ik gebruikt voor ADC0 op fysieke pin 31.

![Pico Pin Layout](./img/picow-pinout.svg)

Ik meet mwt een 10k Ohm weerstand ~500 mV en ~2500 mV met veel licht.

![ADC pico with LDR](./img/Screenshot%202025-10-11%20at%2017.12.57.png)