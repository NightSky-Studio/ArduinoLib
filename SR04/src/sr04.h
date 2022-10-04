#ifndef _SR04_H_
#define _SR04_H_
#include <Arduino.h>

class SR04
{
public:
    SR04(uint8_t TrigPin, uint8_t EchoPin);
    SR04();

    void attach(uint8_t TrigPin, uint8_t EchoPin);
    void begin(void);
    void setSpeed(double speed);

    unsigned long getcm(void);
    unsigned long getmm(void);
    unsigned long get(void);

private:
    uint8_t _trig;
    uint8_t _echo;
    double _speed;
};

#endif // _SR04_H_