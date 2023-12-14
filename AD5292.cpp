/*
  AD5292.h - AD5292 library for Arduino
  MIT License 
  Copyright (c) 2023 Markus Kreitzer.
  Website: https://github.com/markuskreitzer/AD5292
*/

#include "AD5292.h"

AD5292::AD5292(uint8_t csPin, uint32_t spiFreq) : _csPin(csPin), _spiFreq(spiFreq) {}

void AD5292::begin() {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
    SPI.begin();
}

bool AD5292::setWiperPosition(uint16_t position) {
    if (position > 1023) {
        return false; // Invalid position value
    }

    uint16_t command = (0x01 << 10) | (position & 0x03FF);
    sendCommand(command);
    delay(6);

    return true; // Successful operation
}

void AD5292::sendCommand(uint16_t command) {
    SPI.beginTransaction(SPISettings(_spiFreq, MSBFIRST, SPI_MODE1));
    digitalWrite(_csPin, LOW);
    SPI.transfer16(command);
    digitalWrite(_csPin, HIGH);
    SPI.endTransaction();
}

void AD5292::setSpiFrequency(uint32_t spiFreq) {
    _spiFreq = spiFreq;
}
