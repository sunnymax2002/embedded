from machine import Pin
import time

# Program to blink the on board LED on R Pi Pico

# On-board LED is on Pin 25
pin = Pin(25, Pin.OUT)

while True:
    pin.toggle()
    time.sleep_ms(2000)