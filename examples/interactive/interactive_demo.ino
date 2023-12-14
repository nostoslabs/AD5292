#include "AD5292.h"
#define CS_PIN 5

AD5292 digitalPot(CS_PIN);
bool promptDisplayed;
uint16_t y_prev;

void interactive(){
    String inputString = ""; // String to store the input
    int x = -1;

    // Display the prompt only if it hasn't been displayed yet
    if (!promptDisplayed) {
        Serial.println("Enter resistance (0-20 kOhm)");
        promptDisplayed = true;
    }

    if (Serial.available() > 0) {
        inputString = Serial.readStringUntil('\n'); // Read the complete string
        x = inputString.toInt(); // Convert the string to an integer

        // Check if the number is in the valid range
        if (x >= 0 && x <= 20000) {
            Serial.print("We got ");
            Serial.println(x);

            uint16_t y = map(x, 0, 20000, 1, 1023); // Map the value

            if (y != y_prev) {
                Serial.print("Sending ");
                Serial.println(y);
                digitalPot.setWiperPosition(y);
                y_prev = y;

                // Reset promptDisplayed to false so that the prompt is displayed again
                promptDisplayed = false;
            }
        } else {
            Serial.println("Invalid input. Please enter a number between 0 and 20000.");
            // Reset promptDisplayed to false to re-display the prompt after invalid input
            promptDisplayed = false;
        }
    }
    delay(1000);

}
void setup() {
    // Initialize serial communication for debugging
    Serial.begin(115200);
    while (!Serial);  // Wait for the serial port to connect

    // Initialize the AD5292 device
    digitalPot.begin();

    // Set the wiper position
    bool success = digitalPot.setWiperPosition(512);  // Set mid-scale position

    // Check if the operation was successful
    if (success) {
        Serial.println("Wiper position set successfully.");
    } else {
        Serial.println("Failed to set wiper position. Value out of range.");
    }
}

void loop() {
    interactive();
}
