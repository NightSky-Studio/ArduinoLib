#ifndef _LED_H_
#define _LED_H_
#include <Arduino.h>

#if ESP32
#define LED_BUILTIN 2
#endif


class LED
{
public:
    LED(uint8_t Pin);
    LED();

    void attach(uint8_t Pin);
    void begin(bool off = true);

    void on(void);
    void off(void);
    void state(bool state);
    void toggle(void);
    
private:
    uint8_t _pin;
    bool _state;
};

#endif // _LED_H_