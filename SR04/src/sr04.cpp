#include "sr04.h"

SR04::SR04(uint8_t TrigPin, uint8_t EchoPin)
{
    _trig = TrigPin;
    _echo = EchoPin;
    _speed = 0.034;
}
SR04::SR04() { SR04(255, 255); }

void SR04::attach(uint8_t TrigPin, uint8_t EchoPin)
{
    _trig = TrigPin;
    _echo = EchoPin;
}

void SR04::begin()
{
    if (_trig != 255 && _echo != 255)
    {
        pinMode(_trig, OUTPUT);
        pinMode(_echo, INPUT);
    }
}

void SR04::setSpeed(double speed)
{
    _speed = speed;
}

unsigned long SR04::getcm()
{
    return get() * _speed / 2;
}

unsigned long SR04::getmm()
{
    return getcm() * 10;
}

unsigned long SR04::get()
{
    if (_trig == 255 || _echo == 255)
        return 0;

    digitalWrite(_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);
    return pulseIn(_echo, HIGH);
}