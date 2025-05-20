# Library - Voorbeelden

Voor de opdracht "Je eigen library en applicatie" is het handig vooraf te kijken hoe zo'n library normaliter uitziet.
Er zijn honderden voorbeelden van libraries in het Internet.
De TI-S2 C++ docenten hebben enkele Arduino-libraries bekeken en aantekeningen gemaakt.

## Overview Arduino Libraries

Link:

- [Arduino Libraries](https://docs.arduino.cc/libraries/)

## Simple Sensor Library example

Support for the Arduino Nano 33 BLE Sense board to read air pressure abd temperature.

Links:

- [Documentation](https://docs.arduino.cc/libraries/arduino_lps22hb/)
- [Repository](https://github.com/arduino-libraries/Arduino_LPS22HB/tree/master)

Remarks:

- (+) small example, good to get an overview
- (-) no Doxygen-comments
- (-) Hardcoded i2c connection (not usable for e.g. Arduino Due)

## Simple CRC32 Library example

Links:

- [Documentation](https://docs.arduino.cc/libraries/arduino_crc32/)
- [Repository](https://github.com/arduino-libraries/Arduino_CRC32)

Remarks:

- (+) small example
- (+) shows handling of AVR PROGMEM versus other architectures
- (-) fixed generator polynomial, table-driven generation
- (-) no Doxygen-comments

## JSON library example

Links:

- [Documentation](https://docs.arduino.cc/libraries/arduino_json/)
- [Repository](https://github.com/arduino-libraries/Arduino_JSON/tree/master)

Remarks:

- (-) complex memory handling
- (-) only wraps cJSON  (therefore also not much documentation, only examples)

## FIRMATA library
  
Links:

- [Documentation](https://docs.arduino.cc/libraries/firmata/)
- [Repository](https://github.com/firmata/arduino/blob/main/Firmata.cpp)

Remarks:

- (+) uses Doxygen for documentation (-) in *.cpp files
- (+) 'behind the scenes' look into a universal communications library
- (-) complex

## TFT Library

Links:

- [Documentation](https://docs.arduino.cc/libraries/tft/)
- [Repository](https://github.com/arduino-libraries/TFT/blob/master/)

Remarks:

- (+) uses Adafruit components
- (+) shows use of different SPI variants (software/hardware) for constructor
- (+) shows a table-driven initializer
- (-) complex, supports fonts and SD-card files

## Adafruit NeoPixel

Links:

- [Documentation](https://docs.arduino.cc/libraries/adafruit-neopixel/)
- [Repository](https://github.com/adafruit/Adafruit_NeoPixel/tree/master)

Remarks:

- (+) shows how to adapt code for different hardware platforms
- (+) Doxygen comments (-) in *.cpp
- (-) complex (in comparison to [the MicroPython library implementation](https://github.com/micropython/micropython-lib/blob/master/micropython/drivers/led/neopixel/neopixel.py))

## Stepper Motor Driver

Links:

- [Documentation](https://docs.arduino.cc/libraries/stepperdriver/)
- [Repository](https://github.com/laurb9/StepperDriver/tree/master)
- [Code-Example](https://github.com/laurb9/StepperDriver/blob/master/src/BasicStepperDriver.cpp)

Remarks:

- (+) shows how to write code to use various hardware
- (+) shows how to use a template function
- (-) no Doxygen-comments (so no Arduino-site documentation is generated) (+) other comments are useful
- (-) complex (+) but BasicStepperDriver is a good example
