#ifndef __MQTT_H__
#define __MQTT_H__
#if (defined ESP32) || (defined ESP8266)
#include <Arduino.h>
#include <PubSubClient.h>
#include "LED.h"

#define Network_DeBug

#ifdef ESP32
#include <WiFi.h>
#include <esp_wifi.h>
#include <HTTPClient.h>
#elif ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#endif

class MQTTClient : public PubSubClient
{
public:
    MQTTClient(String DeviceName, const char *ssid, const char *password, String host, String port = "1883");
    ~MQTTClient();

    void init();
    bool begin(uint8_t MaxConnectNumber = 10);

    bool IsConnected();

    void reconnect(uint32_t timeout = 1000);

private:
    String _name;

    const char *_ssid;
    const char *_password;

    String _host;
    String _port;

    // WiFiClass *_wifi;
    LED *_led;

    bool isInit;
    bool isConnect;
};

#else
#error "MQTTClient only support ESP32 and ESP8266"
#endif
#endif // __MQTT_H__