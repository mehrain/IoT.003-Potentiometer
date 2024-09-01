#include <Arduino.h> // Include the Arduino core library
#include <WiFi.h> // Include the WiFi library

// Pin declarations
const int ledPin2 = 2; // yellow
const int ledPin5 = 5; // green
const int ledPin22 = 22; // red

// Hardcoded WiFi credentials
const char* ssid = "String";
const char* password = "String";

// Setup function
void setup() {
    Serial.begin(115200);
    Serial.println("Setup started");
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin5, OUTPUT);
    pinMode(ledPin22, OUTPUT);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Setup completed");
}

// Main loop function
void loop() {
    Serial.println("Loop started");
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
    Serial.println("Loop ended");
}