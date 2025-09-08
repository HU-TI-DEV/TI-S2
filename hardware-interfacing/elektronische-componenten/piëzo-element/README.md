![logo](./img/ [](logo-id)

# Piëzo element[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Een introductie](#een-introductie)
- [Piëzo element](#piëzo-element)
- [De schakeling](#de-schakeling)
- [De schakeling](#de-schakeling-1)
- [Referenties](#referenties)

---

**v0.0.1 [](version-id)** Start document voor piëzo element door HU IICT[](author-id).

---

## Een introductie

Het piëzo-elektrisch effect is het verschijnsel dat kristallen van bepaalde materialen onder invloed van druk, bijvoorbeeld door buiging, een elektrische spanning produceren en andersom: er zijn materialen die vervormen als er een elektrische spanning op wordt aangelegd.

## Piëzo element

Een piëzo element kan bijvoorbeeld trillingen meten. Als we juist spanning aansluiten kan piëzo-elektrisch element dit omzetten in beweging, inverse peizo effect. Een vernevelaar gebruikt deze techniek om (water)deeltjes los te trillen.

## De schakeling

We kunnen [PWM](../../communicatie/analoog-en-digitaal/DAC/README.md) met een bepaalde frequentie genereren om zo een piëzo element te laten ossicleren. Hardware PWM op de Arduino Uno gaat echter maar tot 490Hz. Dit kan je zelf proberen te meten met een oscilloscoop. 

```Arduino
int PWM_out_pin = 3; // Must be one of 3, 5, 6, 9, 10, or 11
// for Arduino Uno
void setup() {
pinMode(PWM_out_pin, OUTPUT);
}
void loop() {
byte PWM_out_level;
PWM_out_level = 125
analogWrite( PWM_out_pin, PWM_out_level);
}
```

Er is voor verneveling een veel hogere frequentie nodig om de waterdeeltjes los te krijgen (mist). De resonantie frequentie van de gebruikte piezo element is 113kHz. 

Door direct naar het register te schrijven kunnen we timer2 100kHz of meer laten generen op pin 3. Met de volgende Arduino code kan je een PWM frequentie van 113kHz genereren.

```Arduino
void setup ()
{
  pinMode (3, OUTPUT) ;
  TCCR2A = 0x23 ;
  TCCR2B = 0x09 ; // mode 7, clock prescale by 1
  OCR2A = 141-1 ;  // 141 clock periods = 8.8125us per cycle
  OCR2B =0 ;
  TCNT2 =0 ;
}

void loop ()
{
  // here you can set the duty cycle by writing values between 0 and 140 to OCR2B
  OCR2B = 70;
}
```

## De schakeling
-todo-

## Referenties

- Analoog en digitaal (<https://en.wikipedia.org/wiki/Analogue_electronics#Analogue_vs_digital_electronics>)
- Pulse-width modulation (<https://en.wikipedia.org/wiki/Pulse-width_modulation>)
- Arduino PWM (<https://docs.arduino.cc/tutorials/generic/secrets-of-arduino-pwm>)
- Piezoelectricity (<https://en.wikipedia.org/wiki/Piezoelectricity>)
- 100kHz (<https://forum.arduino.cc/t/100khz-pwm-on-arduino-uno/299922>)