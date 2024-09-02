#include <Arduino.h> // Include the Arduino core library
#include <Wire.h> // Include the Wire library for I2C
#include "WiFiConnection.h" // Include the WiFi connection header
#include "WebServerHandler.h" // Include the Web Server handler header

// I2C address of the OLED display
#define OLED_I2C_ADDRESS 0x3C

// Pin declarations
const int ledPin21 = 21; // SDA
const int ledPin22 = 22; // SCL

// I2C pins
const int i2cSDA = 21; // SDA
const int i2cSCL = 22; // SCL

// Enter your WiFi credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

// Flag to control the loop
bool isRunning = true;

// Function to send a command to the OLED display
void sendCommand(uint8_t command) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(0x00); // Co = 0, D/C = 0
    Wire.write(command);
    Wire.endTransmission();
}

// Function to initialize the OLED display
void initOLED() {
    sendCommand(0xAE); // Display off
    sendCommand(0xD5); // Set display clock divide ratio/oscillator frequency
    sendCommand(0x80); // Suggested ratio
    sendCommand(0xA8); // Set multiplex ratio(1 to 64)
    sendCommand(0x3F); // 1/64 duty
    sendCommand(0xD3); // Set display offset
    sendCommand(0x00); // No offset
    sendCommand(0x40); // Set start line address
    sendCommand(0x8D); // Enable charge pump regulator
    sendCommand(0x14);
    sendCommand(0x20); // Set memory addressing mode
    sendCommand(0x00); // Horizontal addressing mode
    sendCommand(0xA1); // Set segment re-map 0 to 127
    sendCommand(0xC8); // Set COM output scan direction
    sendCommand(0xDA); // Set COM pins hardware configuration
    sendCommand(0x12);
    sendCommand(0x81); // Set contrast control register
    sendCommand(0xCF);
    sendCommand(0xD9); // Set pre-charge period
    sendCommand(0xF1);
    sendCommand(0xDB); // Set VCOMH deselect level
    sendCommand(0x40);
    sendCommand(0xA4); // Entire display ON
    sendCommand(0xA6); // Set normal display
    sendCommand(0xAF); // Display ON
}

void setup() {
    Serial.begin(115200);
    Serial.println("Setup started");

    // Initialize I2C communication
    Wire.begin(i2cSDA, i2cSCL); // SDA, SCL

    // Initialize the OLED display
    initOLED();

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
}