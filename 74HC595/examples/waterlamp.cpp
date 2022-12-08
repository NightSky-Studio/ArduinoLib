#include <Arduino.h>
#include "SR_74HC595.h"

uint8_t dataPin = 2;  // 74HC595 的 DS
uint8_t latchPin = 3; // 74HC595 的 STCP
uint8_t clockPin = 4; // 74HC595 的 SHCP
SR_74HC595 LED(dataPin, latchPin, clockPin);

uint8_t data[10]{
    0b00000000,
    0b10000000,
    0b01000000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
    0b00000000,
};

void setup()
{
    Serial.begin(9600);
    LED.begin();
}

void loop()
{
    for (int i = 0; i < 10; i++)
    {
        LED.write(data[i]);
        delay(100);
    }
    delay(500);
    for (int i = 9; i >= 0; i--)
    {
        LED.write(data[i]);
        delay(100);
    }
    delay(500);
}