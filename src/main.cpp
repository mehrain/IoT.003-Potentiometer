#include <Arduino.h> // Include the Arduino core library
#include <Wire.h> // Include the Wire library for I2C
//#include "WiFiConnection.h" // Include the WiFi connection header
//#include "WebServerHandler.h" // Include the Web Server handler header

// // Enter your WiFi credentials
// const char* ssid = "YourSSID";
// const char* password = "YourPassword";

// D2 is potentiometer pin, D4 is LED pin green1 and D5 is LED pin green2, D18 is ledpin yellow and d19 is ledpin red 

extern bool isRunning = true;

// Analog pin for potentiometer
const int potPin = 2; // GPIO2/D2 (ADC1_6)
const int ledPinGreen1 = 4; // GPIO4/D4
const int ledPinGreen2 = 5; // GPIO5/D5
const int ledPinYellow = 18; // GPIO18/D18
const int ledPinRed = 19; // GPIO19/D19


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

    // Control LEDs based on potentiometer value
    if (potValue > 4000) {
        digitalWrite(ledPinGreen1, HIGH);
        digitalWrite(ledPinGreen2, HIGH);
        digitalWrite(ledPinYellow, HIGH);
        digitalWrite(ledPinRed, HIGH);
        Serial.println("Red ON");
    } else if (potValue > 3000) {
        digitalWrite(ledPinGreen1, HIGH);
        digitalWrite(ledPinGreen2, HIGH);
        digitalWrite(ledPinYellow, HIGH);
        digitalWrite(ledPinRed, LOW);
        Serial.println("Yellow ON");
    } else if (potValue > 2000) {
        digitalWrite(ledPinGreen1, HIGH);
        digitalWrite(ledPinGreen2, HIGH);
        digitalWrite(ledPinYellow, LOW);
        digitalWrite(ledPinRed, LOW);
        Serial.println("Green2 ON");
    } else if (potValue > 1000) {
        digitalWrite(ledPinGreen1, HIGH);
        digitalWrite(ledPinGreen2, LOW);
        digitalWrite(ledPinYellow, LOW);
        digitalWrite(ledPinRed, LOW);
        Serial.println("Green1 ON");
    } else {
        digitalWrite(ledPinGreen1, LOW);
        digitalWrite(ledPinGreen2, LOW);
        digitalWrite(ledPinYellow, LOW);
        digitalWrite(ledPinRed, LOW);
        Serial.println("All LEDs OFF");
    }


    // // Handle client requests
    // handleClientRequests();

    // Add a small delay to avoid flooding the serial monitor
    delay(500);
}