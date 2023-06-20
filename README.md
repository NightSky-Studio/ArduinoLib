# NightSky Studio ArduinoLib

This is a collection of Arduino libraries for the NightSky Studio.

## Currently supported libraries

| Library |         Documentation         | Version | Status |
| :-----: | :---------------------------: | :-----: | :----: |
|   LED   |   [Document](LED/README.md)   |  0.1.0  |  Done  |
|  MQTT   |  [Document](MQTT/README.md)   |  0.1.0  |  Bata  |
| 74HC595 | [Document](74HC595/README.md) |  0.1.0  |  Done  |
| Packet  | [Document](Packet/README.md)  |  0.1.0  |  Bata  |

## library Structure

Build based on c++ folder structure, the library.json file is used to describe the library.  
This cannot be directly used in Arduino IDE, but can be used in PlatformIO.

```text
├── examples
│   └── echo.cpp
├── src
│   ├── HelloWorld.h
│   └── HelloWorld.cpp
├── library.json
└── README.md
```

Arduino IDE settings please refer to the instructions below.

```text
\examples\echo.cpp -> \examples\echo\echo.ino
\src\HelloWorld.h -> \HelloWorld.h
\src\HelloWorld.cpp -> \HelloWorld.cpp
```

## Questions and feedback

### GitHub

We use GitHub issues as a bug and feature request tracker. If you think you've found a bug, or you have a new feature idea, please start by making sure it hasn't already been reported or fixed. You can search through existing issues and pull requests to see if someone has reported one similar to yours.

### Bugs and feature requests

You can create an issue on this repository. Please always provide a reproduction case. As a starting point, we recommend you browse the documentation, and select the closest example to your use case. Or you can use a basic template to build your reproduction case.

## Authors

[@NightStar](https://github.com/Night-Star04)

## License

This project is released under the [MIT](https://github.com/NightSky-Studio/ArduinoLib/blob/main/LICENSE)
