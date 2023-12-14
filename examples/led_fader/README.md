# Breathing LED with AD5292

This example demonstrates how to use the AD5292 digital potentiometer Arduino library to create a breathing LED effect. The LED's brightness is controlled by adjusting the resistance of the potentiometer in a voltage divider configuration.

## Circuit Diagram

Connect your AD5292 and LED as follows:
- A (Terminal A of AD5292) to VDD.
- W (Wiper of AD5292) to the anode of the LED.
- Cathode of the LED to a 330 Ohm resistor, then to the ground. This is to limit current and prevent the LED from burning out.
- B (Terminal B of AD5292) to the ground.

## Setup

1. Connect the AD5292 to your Arduino as per the circuit diagram using the respective SPI pins for your model. For the ESP32 you can follow this table. It is also helpful because it seems like there are many nomenclatures for SPI lines.

 | AD5292 | ESP-WROOM-32 | Comment              |
| ------ | ------------ | --------------------- |
| RESET  | VLogic       |                       |
| RDY    | -            | Float               |
| SDO    | -            | Float (MISO)      |
| SYNC   | CS (D5)      | aka Slave Select (SS) |
| SCLK   | CLK (D18)    | Clock             |
| DIN    | MOSI (D23)   | Data In           |
| VSS    | GND          | 0V                |
| VDD    | <15V         | Can use 3.3V on ESP32 |
| A      | VDD          | Pot A             |
| B      | GND          | Pot B             |
| W      | LED Anode    | Wiper             |
| VLogic | 3.3V         |                   |
| GND    | GND          |                   |


2. Upload the `BreathingLED.ino` sketch to your Arduino.

## Code Explanation

- The sketch gradually increases and then decreases the wiper position, causing the LED to fade in and out, creating a breathing effect.
- The `setWiperPosition` method is used to change the resistance, thus controlling the LED brightness.

## Notes

- Ensure the LED and AD5292 are correctly oriented and connected.
- Adjust the delay in the loop for faster or slower breathing effects.
- The AD5292 has many command functions such as programming preset wiper positions, etc. Feel free to send an MR to add more methods. 

## License

This project is released under the MIT License.

## Author

Markus Kreitzer
