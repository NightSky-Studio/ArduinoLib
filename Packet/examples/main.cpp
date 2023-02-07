#include <Arduino.h>

#include "packet.h"
Packet packet(Serial);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    packet.loop();
    if (packet.isConnect)
        packet.outlog(Serial);
}
