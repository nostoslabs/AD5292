/*
  AD5292.h - AD5292 library for Arduino
  MIT License 
  Copyright (c) 2023 Markus Kreitzer.
  Website: https://github.com/markuskreitzer/AD5292

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
