#include <WiFi.h>
#include "WiFiConnection.h"

void connectToWiFi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        if (millis() > 10000) {
            Serial.println("\nTried to connect for 10 seconds, timed out");
            break;
        }
    }
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}