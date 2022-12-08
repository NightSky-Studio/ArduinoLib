/***
 * MFirst Progressor
 *  以MFirst方式进行累加的显示
 * 
 *    Q7 Q6 Q5 Q4 Q3 Q2 Q1 Q0
 * 0b  0  0  0  0  0  0  0  0
*/
#include <Arduino.h>
#include "SR_74HC595.h"

uint8_t dataPin = 2;
uint8_t latchPin = 3;
uint8_t clockPin = 4;
SR_74HC595 LED(dataPin, latchPin, clockPin);

void setup()
{
    LED.begin();
}

void loop()
{
    for (uint8_t i = 0; i < 254; i++)
    {
        LED.write(i, false);
        delay(100);
    }
    for (uint8_t i = 254; i > 0; i--)
    {
        LED.write(i, false);
        delay(100);
    }
}