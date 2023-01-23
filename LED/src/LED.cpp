#include "LED.h"

LED::LED(uint8_t Pin)
{
    _pin = Pin;
}
LED::LED() {}

void LED::attach(uint8_t Pin)
{
    _pin = Pin;
}

void LED::begin(bool off)
{
    pinMode(_pin, OUTPUT);
    _state = digitalRead(_pin);

    if (off)
        this->off();
}

void LED::state(bool state)
{
    if (state)
        return on();
    return off();
}

void LED::on()
{
    if (!_state)
    {
#ifdef ESP8266
        digitalWrite(_pin, LOW);
#else
        digitalWrite(_pin, HIGH);
#endif

        _state = true;
    }
}

void LED::off()
{
    if (_state)
    {
#ifdef ESP8266
        digitalWrite(_pin, HIGH);
#else
        digitalWrite(_pin, LOW);
#endif

        _state = false;
    }
}

void LED::toggle()
{
    if (!_state)
        on();
    else
        off();
}
