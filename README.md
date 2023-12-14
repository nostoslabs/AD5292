# AD5292 Arduino/ESP32 Library

This is an Arduino library for interfacing with the AD5292 digital potentiometer using the SPI communication protocol. I've mainly used this with an ESP32, but the initial testing was on an Arduino MEGA so should work on anything that complies with the Arduino API. It should be trivial to adapt to other Analog Devices digital potentiometers. PR/MRs are welcome.

## Features

- Easy interfacing with the AD5292 digital potentiometer.
- Support for setting the wiper position.
- Configurable SPI frequency.
- Simple and efficient methods for communicating with the device.

## Installation

1. Download this library as a zip file.
2. In the Arduino IDE, go to `Sketch` > `Include Library` > `Add .ZIP Library...` and select the downloaded file.
3. Restart the Arduino IDE.

## Usage

Include the library in your sketch and follow the example below to get started:

```cpp
#include <SPI.h>
#include "AD5292.h"

// Define the Chip Select pin
#define CS_PIN 5

// Create an instance of the AD5292 class
AD5292 digitalPot(CS_PIN);

void setup() {
    // Initialize the AD5292 device
    digitalPot.begin();

    // Set the wiper position
    if (digitalPot.setWiperPosition(512)) {
        Serial.println("Wiper position set successfully.");
    } else {
        Serial.println("Failed to set wiper position.");
    }
}

void loop() {
    // Your code here
}
```

## Methods

- `begin()`: Initializes the SPI interface and configures the chip select pin.
- `setWiperPosition(uint16_t position)`: Sets the wiper position of the AD5292.
- `setSpiFrequency(uint32_t spiFreq)`: Sets the SPI communication frequency.

## License

This library is released under the [MIT License](LICENSE).

## Author

[Markus Kreitzer](https://github.com/markuskreitzer)

## License 
MIT License
Copyright (c) 2023 Markus Kreitzer


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.