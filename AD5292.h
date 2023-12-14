/*
  AD5292.h - AD5292 library for Arduino
  MIT License 
  Copyright (c) 2023 Markus Kreitzer.
  Website: https://github.com/nostoslabs/AD5292

AD5292 Commands (From Datasheet):
DC - CONT - COMMAND
0) 00 - 0000 - XXXXXXXXXX  Do Nothing
1) 00 - 0001 - NNNNNNNNNN  Write To RDAC
2) 00 - 0010 - XXXXXXXXXX  Read RDAC from SDO in next frame
3) 00 - 0011 - XXXXXXXXXX  Store wiper setting: store RDAC setting to 20-TP memory.
4) 00 - 0100 - XXXXXXXXXX  Reset: refresh RDAC with 20-TP stored value.
5) 00 - 0101 - XXXXXNNNNN  Read contents of 20-TP memory, or status of 20-TP memory, from the SDO output in the next frame.
6) 00 - 0110 - XXXXXXNNNN  Write contents of serial data to control register.
7) 00 - 0111 - XXXXXXXXXX  Read control register from the SDO output in the next frame.
8) 00 - 1000 - XXXXXXXXXN  Software shutdown.
                           N = 0 (normal mode).
                           N = 1 (device placed in shutdown mode).

N: a digit in serial buffer (MSB)
X: Don't Care

*/

#ifndef AD5292_H
#define AD5292_H

#include <Arduino.h>
#include <SPI.h>

class AD5292 {
public:
    AD5292(uint8_t csPin, uint32_t spiFreq = 1000000);

    void begin();
    bool setWiperPosition(uint16_t position);
    void setSpiFrequency(uint32_t spiFreq);

private:
    uint8_t _csPin;
    uint32_t _spiFreq;
    void sendCommand(uint16_t command);
};

#endif // AD5292_H
