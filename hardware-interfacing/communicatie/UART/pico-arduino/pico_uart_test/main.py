# UART Test for PICO (W)
# https://docs.micropython.org/en/latest/rp2/quickref.html#uart-serial-bus
# UART0 can be mapped to pins 0/1, 12/13, and 16/17
# UART1 can be mapped to pins 4/5 and 8/9.
#
# Example uses GPIO pins 4 and 5
# PICO Module Pin 3 = GND, Module Pin 6 = TX, Module Pin 7 = RX
# PICO TX can be connected directly to Arduino Pin D0 (RX)
# PICO RX needs two resistors (Arduino TX -- 1k --- PICO RX --- 2.2k -- GND)
# to divide the voltage from 5V to 3,3V for the Pico
from machine import Pin, UART
from time import sleep_ms

try:
    led = Pin("LED", Pin.OUT)
except:
    led = Pin(25, Pin.OUT)


def bist():
    for _ in range(3):
        led.value(1)
        sleep_ms(200)
        led.value(0)
        sleep_ms(200)


bist()
uart1 = UART(1, baudrate=115200, tx=Pin(4), rx=Pin(5))
while True:
    led.value(1)
    uart1.write('hello!\n')
    led.value(0)
    msg = uart1.read(30)
    if msg is not None:
        print("MSG:", msg)
    sleep_ms(1000)

# eof
