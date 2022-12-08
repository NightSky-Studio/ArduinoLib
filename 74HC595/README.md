# NightSky-Studio ArduinoLib

## SR_74HC595 - Shift Register Library

This library is used to control the 74HC595 shift registers. It is a simple library that allows you to control the output of the 74HC595 more easily.

```cpp
#include <SR_74HC595.h>
```

### Constructor

Currently use `SR_74HC595(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin)` to declare the library

```cpp
SR_74HC595(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin);

// Parameter
dataPin：  Pin connected to the DS pin of 74HC595
latchPin： Pin connected to the STCP pin of 74HC595
clockPin： Pin connected to the SHCP pin of 74HC595
```

## Methods

This method is used to Initialize connection and GPIO pins, but it is recommended to call it in the `setup()` function.

```cpp
void begin();
```

This method is used to set the output of the 74HC595.

```cpp
void write(uint8_t data, bool LFirst = true);

// Parameter
data：    The data to output (Values range from 0 to 255)
LFirst：  Whether the data is output from the lowest bit to the highest bit
```

This method is used to set the one pin of the 74HC595.

```cpp
void write_one(uint8_t pin, bool mod = false);

// Parameter
pin：  The pin to output (Values range from 0 to 7)
mod：  Whether to set the pin to high or low (true: high, false: low)
```

This method is used to set all pins of the 74HC595 to low or high.

```cpp
void SetAllLow();
void SetAllHigh();
```

## Example

```cpp
#include <Arduino.h>
#include <SR_74HC595.h>

uint8_t dataPin = 2;  // 74HC595 DS pin to Arduino pin 2
uint8_t latchPin = 3; // 74HC595 STCP pin to Arduino pin 3
uint8_t clockPin = 4; // 74HC595 SHCP pin  to Arduino pin 4
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
```
