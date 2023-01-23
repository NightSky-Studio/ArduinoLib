# NightSky-Studio ArduinoLib

## LED - LED Library

This library is used to control the LED. It is a simple library that allows you to turn on and off and blink the LED.

```cpp
#include <LED.h>
```

## Constructor

Use one of the two, if you use `LED()`, you need to use it with `attach(Pin)`

```cpp
LED(uint8_t pin);
LED();
```

## Methods

This method is used to attach the LED to the pin, but it is recommended to call it in the `setup()` function.

```cpp
void attach(uint8_t pin);
```

This method is used to Initialize connection and GPIO pins,
but it is recommended to call it in the `setup()` function.

```cpp
void begin(bool off);
```

This method is used to turn on the LED.

```cpp
void on(void);
```

This method is used to turn off the LED.

```cpp
void off(void);
```

This method is used to toggle the LED.

```cpp
void toggle(void);
```

This method is used to set the LED state.

```cpp
void state(bool state);
```

## Example

For more examples, please refer to the examples folder

```cpp
#include <Arduino.h> // include Arduino library
#include <LED.h>     // include LED library

uint8_t pin = 13; // LED pin
LED led;
// or
// LED led(pin);

void setup()
{
    led.attach(pin); // attach pin to LED
    led.begin();     // initialize LED
}

void loop()
{
    led.on();    // turn on LED
    delay(1000); // wait for a second
    led.off();   // turn off LED
    delay(1000); // wait for a second
}
```
