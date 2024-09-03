#include <Arduino.h> // Include the Arduino core library
#include <Wire.h> // Include the Wire library for I2C
//#include "WiFiConnection.h" // Include the WiFi connection header
//#include "WebServerHandler.h" // Include the Web Server handler header

// // Enter your WiFi credentials
// const char* ssid = "YourSSID";
// const char* password = "YourPassword";

extern bool isRunning = true;

// Analog pin for potentiometer
const int potPin = 2; // GPIO2/D2 (ADC1_6)

void setup() {
    Serial.begin(115200);
    Serial.println("Setup started");

    // // Connect to WiFi
    // connectToWiFi(ssid, password);

    // // Set up the web server
    // setupWebServer();

    // Initialize the potentiometer pin
    pinMode(potPin, INPUT);

    Serial.println("Setup completed");
}

// Main loop - Mandatory in Arduino
void loop() {
    // Read the potentiometer value
    int potValue = analogRead(potPin);

    // Transmit the potentiometer value to the serial monitor
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);

    // // Handle client requests
    // handleClientRequests();

    // Add a small delay to avoid flooding the serial monitor
    delay(500);
}