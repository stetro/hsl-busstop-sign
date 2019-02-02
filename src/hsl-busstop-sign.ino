/**
  HSL Bus Station Query
  - Queries data from HSL with GraphQL
  - Gets current timestamp via NTP
  - Display current waiting time on Serial and I2C LiquidCrystal Display
*/


#define WIFI_SSID "***"
#define WIFI_PASSWORD "***"

#include <Arduino.h>

#ifdef NODE_MCU_ESP8266
#include <ESP8266WiFi.h>
#endif

#ifdef NODE_MCU_ESP32
#include <WiFi.h>
#endif

#include <hsl-display.h>
#include <hsl.h>

Hsl hsl;
HslDisplay display;

void setup() {
  Serial.begin(115200);

  display.init();
  display.showLoadingScreen();

  Serial.println("[WIFI] connecting to wifi ...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void loop() {
  if (wifiConnected()) {
    Serial.println("[WIFI] connected");
    if (hsl.queryTimetable(HSL_QUERY)) {
      while (true) {
        display.clear();
        display.updateTimetable(&hsl);
        display.showTimetable();
        delay(60000);
      }
    } else {
      display.showError();
      delay(20000);
    }
    display.clear();
    display.turnOff();
  } else {
    Serial.println("[WIFI] not connected to wifi, still trying ...");
    delay(1000);
  }
}

bool wifiConnected() { return (WiFi.status() == WL_CONNECTED); }
