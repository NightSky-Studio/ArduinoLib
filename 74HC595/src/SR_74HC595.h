/**
 * @file SR_74HC595.h
 * @author NightStar
 * @brief 由於不想寫太過繁瑣的程式碼,所以開發了這個 74HC595 移位佔存器 的lib :)
 * @version 1.0
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022 NightSky Studio All Rights Reserved
 *
 */
#ifndef _SR_74HC595_H_
#define _SR_74HC595_H_

/**
 * LFirst (Hight)
 * 00000001 = Q7
 * 00000010 = Q6
 * 00000100 = Q5
 * 00001000 = Q4
 * 00010000 = Q3
 * 00100000 = Q2
 * 01000000 = Q1
 * 10000000 = Q0
 */

#include <Arduino.h>

/**
 * @brief 74HC595 移位佔存器 的lib
 */
class SR_74HC595
{
public:
    SR_74HC595(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin);
    void begin(void);
    void write(uint8_t data, bool LFirst = true);
    void write_one(uint8_t pin, bool mod = false);

    void SetAllLow(void);
    void SetAllHigh(void);

private:
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _latchPin;
    uint8_t _olddata;
};

#endif // _SR_74HC595_H_
