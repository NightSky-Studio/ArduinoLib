#include "mqtt.h"

MQTTClient::MQTTClient(String DeviceName,
                       const char *ssid, const char *password,
                       String host, String port) : _name(DeviceName),
                                                   _ssid(ssid), _password(password),
                                                   _host(host), _port(port),
                                                   isInit(false)

{
}

MQTTClient::~MQTTClient(){};

void MQTTClient::init()
{
    WiFi.mode(WIFI_STA);
    WiFi.setSleep(false);
    setClient(*new WiFiClient);

    _led = new LED(LED_BUILTIN);

    isInit = true;
};

bool MQTTClient::begin(uint8_t MaxConnectNumber)
{
    if (!isInit)
        return false;

    WiFi.begin(_ssid, _password);
    _led->begin();
    uint8_t connection = 0;
#ifdef Network_DeBug
    Serial.print(F("Connecting to WiFi"));
#endif

    while (connection < MaxConnectNumber && !isConnect)
    {
        if (WiFi.status() == WL_CONNECTED)
            isConnect = true;
#ifdef Network_DeBug
        Serial.print(".");
#endif
        connection++;

        delay(1000);
    }

    if (!isConnect)
    {
#ifdef Network_DeBug
        Serial.print("\r\n");
        Serial.println(F("Failed to connect to WiFi"));
#endif
        return false;
    }

#ifdef Network_DeBug
    Serial.println(F("Connected to WiFi"));
    Serial.print(F("IP address: "));
    Serial.println(WiFi.localIP());
    WiFi.printDiag(Serial);
#endif

    setServer(_host.c_str(), _port.toInt());
    _led->on();
    return true;
};

bool MQTTClient::IsConnected()
{
    return connected();
}

void MQTTClient::reconnect(uint32_t timeout)
{
    while (!IsConnected())
    {
        Serial.print("Attempting MQTT connection...");
        if (!connect(_name.c_str()))
        {
            Serial.print("failed, rc=");
            Serial.print(state());
            _led->toggle();
            delay(timeout);
        }
        else
        {
            Serial.println("connected");
            _led->on();
        }
    }
}