# NightSky-Studio ArduinoLib

## SR04 - Ultrasonic Sensor Library

This library is used to control the SR04 ultrasonic sensor. It is a simple library that allows you to get the distance in centimetre or millimetre

```cpp
#include <SR04.h>
```

### Constructor

Use one of the two, if you use `SR04()`, you need to use it with `attach(TrigPin, EchoPin)`

```cpp
SR04(uint8_t trigPin, uint8_t echoPin);
SRO4();
```

## Methods

This method is used to attach the sensor to the pins, but it is recommended to call it in the `setup()` function.

```cpp
void attach(uint8_t trigPin, uint8_t echoPin);
```

This method is used to Initialize connection and GPIO pins, but it is recommended to call it in the `setup()` function.

```cpp
void begin();
```

This method is used to Setting the speed of sound, or 0.034 if not set, but it is recommended to call it in the `setup()` function.

```cpp
void setSpeed(double speed);
```

This method is used to get the distance.

```cpp
unsigned long get();
```

This method is used to get the distance in centimetre.

```cpp
unsigned long getcm();
```

This method is used to get the distance in millimetre.

```cpp
unsigned long getmm();
```

## Example

```cpp
#include <Arduino.h>
#include <SR04.h>

unsigned long Distance
unsigned long Distance_cm
unsigned long Distance_mm
SR04 sensor(2, 3);

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  Distance = sensor.get();
  Distance_cm = sensor.getcm();
  Distance_mm = sensor.getmm();
  Serial.println(Distance);
  Serial.println(Distance_cm);
  Serial.println(Distance_mm);

  delay(1000);
}
```
