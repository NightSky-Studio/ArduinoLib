/**
 * @file packet.h
 * @author NightStar
 * @brief Packet Library
 * @version 0.1
 * @date 2023-02-07
 *
 * @copyright Copyright (c) 2023 NightSky Studio
 */
#ifndef _PACKET_H_
#define _PACKET_H_

#include <Arduino.h>
class Packet
{
public:
    Packet(Stream &Stream, uint8_t starter = 0x0A, uint8_t terminator = 0x0B, uint8_t emptydata = 0x00);

    void setstarter(uint8_t starter);
    void setterminator(uint8_t terminator);
    void setting(uint8_t starter, uint8_t terminator);

    bool loop();
    void write(uint8_t *data, uint8_t length);

    void outlog(Stream &str, bool clear = true);

    uint8_t findlength();
    uint8_t data[11]; // 接收到的資料 (需包含一位結束符號) (11 = 10位資料 + 1位結束符號)
    bool isConnect;   // 是否已接收過封包起始符號
    uint8_t length;   // 資料長度

private:
    Stream *_Stream;     // 串流
    uint8_t _starter;    // 封包起始符號
    uint8_t _terminator; // 封包結束符號
    uint8_t _emptydata;  // 空資料

    void datainit();
};
#endif // _PACKET_H_