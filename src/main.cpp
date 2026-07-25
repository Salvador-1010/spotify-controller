#include <Arduino.h>
#include <WiFi.h>
#include <LiquidCrystal.h>
//imports the confidential file in order to get the wifi name and password
#include "confidential.h"

const int RS_PIN = 27;
//for now we have R/W pin set to GND since we only plan to write 
const int E_PIN = 14;
//we'll be using the simpler 4-bit method do D0-D3 will be disconnected
const int D4 = 32;
const int D5 = 33;
const int D6 = 25;
const int D7 = 26;

LiquidCrystal lcd(RS_PIN, E_PIN, D4, D5, D6, D7);

void setup() 
{ 
    //setting up the LCD 
    lcd.begin(16,2);
    lcd.print("hi there");

    //setting up the esp32 to connect to an existing wifi router
    WiFi.mode(WIFI_STA);
    //starts wifi connection
    WiFi.begin(wifi_name, wifi_pass);

    //Begins serial communication at 115200 
    Serial.begin(115200);

    //Gives the serial connection a small delay to initialize
    delay(1000);

    //just a little code to make sure ik wifi is up
    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("Wifi Successfully Connected");
    }
}

void loop()
{


}