#include <Arduino.h> // include Arduino library
#include <LED.h>     // include LED library

uint8_t pin = 13; // LED pin
LED led;
// or
// LED led(pin);

void setup()
{
    led.attach(pin); // attach pin to LED
    led.begin();         // initialize LED
}

void loop()
{
    led.on();    // turn on LED
    delay(1000); // wait for a second
    led.off();   // turn off LED
    delay(1000); // wait for a second
}