#include <Arduino.h>
#include <WiFi.h>
//imports the confidential file in order to get the wifi name and password
#include "confidential.h"


void setup() 
{
    //setting up the esp32 to connect to an existing wifi router
    WiFi.mode(WIFI_STA);
    //starts wifi connection
    WiFi.begin(wifi_name, wifi_pass);

    //Begins serial communication at 115200 
    Serial.begin(115200);

    //Gives the serial connection a small delay to initialize
    delay(1000);

    Serial.println();
    Serial.println("Esp32 connection succesful");
}

void loop()
{
    Serial.println("The ESP32 is running");
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("Wifi Successfully Connected");
    }

    delay(1000);
}