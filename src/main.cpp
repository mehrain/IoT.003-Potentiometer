#include <Arduino.h> // Include the Arduino core library
#include "WiFiConnection.h" // Include the WiFi connection header
#include "WebServerHandler.h" // Include the Web Server handler header

// Pin declarations
const int ledPin2 = 2; // yellow
const int ledPin5 = 5; // green
const int ledPin22 = 22; // red

// Enter your WiFi credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

// Flag to control the loop
bool isRunning = true;

void setup() {
    Serial.begin(115200);
    Serial.println("Setup started");
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin5, OUTPUT);
    pinMode(ledPin22, OUTPUT);

    // Connect to WiFi
    connectToWiFi(ssid, password);

    // Set up the web server
    setupWebServer();

    Serial.println("Setup completed");
}

// Main loop - Mandatory in Arduino
void loop() {
    // Handle client requests
    handleClientRequests();

    if (isRunning) {
        //Serial.println("Loop started");
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin22, LOW);
        delay(1000);

        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin22, LOW);
        delay(1000);

        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin5, LOW);
        digitalWrite(ledPin22, HIGH);
        delay(1000);
        //Serial.println("Loop completed");
    }
}