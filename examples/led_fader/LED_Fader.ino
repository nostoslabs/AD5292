#include "AD5292.h"
#define CS_PIN 5  // Chip Select pin for AD5292


/*
  AD5292 library for Arduino
  MIT License 
  Copyright (c) 2023 Markus Kreitzer.
  Website: https://github.com/markuskreitzer/AD5292
  Example Use of the AD5292 library
*/


AD5292 digitalPot(CS_PIN);

void setup() {
    Serial.begin(115200);
    digitalPot.begin();
}

void loop() {
    for (int i = 0; i <= 1023; i++) {
        digitalPot.setWiperPosition(i);
        delay(5);  // Adjust for desired speed of fading
    }
    for (int i = 1023; i >= 0; i--) {
        digitalPot.setWiperPosition(i);
        delay(5);  // Adjust for desired speed of fading
    }
}
