#include <WebServer.h>
#include "WebServerHandler.h"

// Create a web server object that listens on port 80
WebServer server(80);

// Flag to control the loop
extern bool isRunning;


// Function to handle the root path
void handleRoot() {
    server.send(200, "text/plain", "ESP32 Web Server");
}

// Function to handle enabling the loop
void handleEnable() {
    isRunning = true;
    server.send(200, "text/plain", "Loop enabled");
    Serial.println("Loop enabled");
}

// Function to handle disabling the loop
void handleDisable() {
    isRunning = false;
    
    server.send(200, "text/plain", "Loop disabled and LEDs turned off");
    Serial.println("Loop disabled");
}

// Function to set up the web server
void setupWebServer() {
    server.on("/", handleRoot);
    server.on("/enable", handleEnable);
    server.on("/disable", handleDisable);
    server.begin();
    Serial.println("Web server started");
}

// Function to handle client requests
void handleClientRequests() {
    server.handleClient();
}