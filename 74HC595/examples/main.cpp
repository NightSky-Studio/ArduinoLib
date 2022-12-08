#include <Arduino.h>
#include "SR_74HC595.h"

uint8_t dataPin = 2;  // 74HC595 的 DS
uint8_t latchPin = 3; // 74HC595 的 STCP
uint8_t clockPin = 4; // 74HC595 的 SHCP
SR_74HC595 LED(dataPin, latchPin, clockPin);

void setup()
{
    LED.begin();
}

void loop()
{
    for (uint8_t i = 0; i < 8; i++)
    {
        LED.write_one(i, HIGH);
        delay(100);
    }
    delay(1000);
    for (int8_t i = 8; i > -1; i--)
    {
        LED.write_one(i, LOW);
        delay(100);
    }
    delay(1000);
}