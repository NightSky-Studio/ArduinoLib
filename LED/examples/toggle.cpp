#include <Arduino.h> // include Arduino library
#include <LED.h>     // include LED library

uint8_t pin = 13; // LED pin
LED led(pin);
// or
// LED led;

void setup()
{
    // led.attach(pin); // attach pin to LED
    led.begin(); // initialize LED
    led.on();    // turn on LED
}

void loop()
{
    led.toggle(); // toggle LED (on -> off, off -> on)
    delay(1000);  // wait for a second
}