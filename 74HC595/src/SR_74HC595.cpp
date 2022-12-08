#include "SR_74HC595.h"

/**
 * @brief Construct a new SR_74HC595::SR_74HC595 object
 *
 * @param dataPin   The pin number of the data pin (74HC595 的 DS (Pin14))
 * @param latchPin  The pin number of the latch pin (74HC595 的 STCP (Pin 12))
 * @param clockPin  The pin number of the clock Pin (74HC595 的 SHCP (Pin 11))
 */
SR_74HC595::SR_74HC595(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin)
{
    // Initialize data members
    _dataPin = dataPin;
    _clockPin = clockPin;
    _latchPin = latchPin;
}

/**
 * @brief 初始化移位寄存器
 */
void SR_74HC595::begin(void)
{
    // Set the pins to output
    pinMode(_dataPin, OUTPUT);
    pinMode(_clockPin, OUTPUT);
    pinMode(_latchPin, OUTPUT);

    // Set all pins low
    SetAllLow();
}

/**
 * @brief  Write a byte to the shift register
 *
 * @param data The data to write 74HC595 (Binary 8 bits)
 * @param LFirst If true, the data will be shifted out LSB first, otherwise, MSB first
 */
void SR_74HC595::write(uint8_t data, bool LFirst)
{
    // If the data is the same as the old data, do nothing
    if (data == _olddata)
        return;

    // Set the latch pin low
    digitalWrite(_latchPin, LOW);

    // If the data is out of range, return
    if (data > 255)
        return;

    // Shift the data out
    if (LFirst)
        shiftOut(_dataPin, _clockPin, LSBFIRST, data);
    else
        shiftOut(_dataPin, _clockPin, MSBFIRST, data);

    // Set the latch pin high
    digitalWrite(_latchPin, HIGH);

    // Update the old data
    _olddata = data;
}

/**
 * @brief Write one bit to the shift register
 *
 * @param pin  The pin to write to
 * @param mod  If true, the pin will be high, otherwise, the pin will not change
 */
void SR_74HC595::write_one(uint8_t pin, bool mod)
{
    uint8_t data = 0b00000000;

    // If the pin is out of range, return
    if (pin > 7 || pin < 0)
        return;

    if (!LFirst) 
        pin = 7 - pin;

    switch (pin)
    {
    case 0:
        data = mod ? _olddata | 0b00000001 : _olddata & 0b11111110;
        break;
    case 1:
        data = mod ? _olddata | 0b00000010 : _olddata & 0b11111101;
        break;
    case 2:
        data = mod ? _olddata | 0b00000100 : _olddata & 0b11111011;
        break;
    case 3:
        data = mod ? _olddata | 0b00001000 : _olddata & 0b11110111;
        break;
    case 4:
        data = mod ? _olddata | 0b00010000 : _olddata & 0b11101111;
        break;
    case 5:
        data = mod ? _olddata | 0b00100000 : _olddata & 0b11011111;
        break;
    case 6:
        data = mod ? _olddata | 0b01000000 : _olddata & 0b10111111;
        break;
    case 7:
        data = mod ? _olddata | 0b10000000 : _olddata & 0b01111111;
        break;
    default:
        break;
    }

    // If the data is the same as the old data, do nothing
    if (data == _olddata)
        return;

    // Write the data
    write(data, false);
}

/**
 * @brief Set all pins high
 */
void SR_74HC595::SetAllLow(void)
{
    return write(0b00000000);
}

/**
 * @brief Set all pins low
 */
void SR_74HC595::SetAllHigh(void)
{
    return write(0b11111111);
}
