#include "packet.h"

Packet::Packet(Stream &Stream, uint8_t starter, uint8_t terminator, uint8_t emptydata)
{
    _Stream = &Stream;
    _starter = starter;
    _terminator = terminator;
    _emptydata = emptydata;
    isConnect = false;
    length = 0;
    datainit();
}

void Packet::setstarter(uint8_t starter)
{
    _starter = starter;
}
void Packet::setterminator(uint8_t terminator)
{
    _terminator = terminator;
}
void Packet::setting(uint8_t starter, uint8_t terminator)
{
    _starter = starter;
    _terminator = terminator;
}

void Packet::datainit()
{
    for (uint8_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        data[i] = _emptydata;
}

bool Packet::loop()
{
    if (_Stream->available())
    {
        if (isConnect)
        {
            _Stream->readBytesUntil(_terminator, data, sizeof(data) / sizeof(data[0]));
            length = findlength();
        }
        else
        {
            if (_Stream->read() == _starter)
            {
                isConnect = true;
                datainit();
                _Stream->readBytesUntil(_terminator, data, sizeof(data) / sizeof(data[0]));
                length = findlength();
            }
        }
        return true;
    }
    return false;
}

void Packet::write(uint8_t *data, uint8_t length)
{
    uint8_t temp[length + 3];
    temp[0] = _starter;
    temp[length + 1] = length;
    temp[length + 2] = _terminator;
    for (uint8_t i = 0; i < length; i++)
        temp[i + 1] = data[i];

    _Stream->write(temp, length + 3);
}

uint8_t Packet::findlength()
{
    for (uint8_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        if (data[i] == _emptydata)
        {
            length = i;
            return length;
        }
    }
    return 0;
}

void Packet::outlog(Stream &str, bool clear)
{
    Stream *temp = &str;
    temp->println(F("接收到資料"));

    temp->println(F("資料內容"));
    for (uint8_t i = 0; i < length; i++)
    {
        temp->print(data[i]);
        temp->print(" ");
    }
    temp->println();

    temp->println(F("資料長度"));
    temp->println(length);
    temp->println();

    if (clear)
        isConnect = false;
}
