#include <Arduino.h>
#include <WiFi.h>
#include <LiquidCrystal.h>
//imports the confidential file in order to get the wifi name and password
#include "confidential.h"
//library to send code uploads over wifi
#include <ArduinoOTA.h>


const int RS_PIN = 27;
//for now we have R/W pin set to GND since we only plan to write 
const int E_PIN = 14;
//we'll be using the simpler 4-bit method do D0-D3 will be disconnected
const int D4 = 32;
const int D5 = 33;
const int D6 = 25;
const int D7 = 26;

LiquidCrystal lcd(RS_PIN, E_PIN, D4, D5, D6, D7);

//variables to keep track of time
int currentSeconds = 0;
//uses unsigned long to reserve more space for time tracking bc obviously seconds cant be negative
unsigned long elapsed_millis = 0;

void setup() 
{ 
    //setting up the LCD 
    lcd.begin(16,2);

    //setting up the esp32 to connect to an existing wifi router
    WiFi.mode(WIFI_STA);
    //starts wifi connection
    WiFi.begin(wifi_name, wifi_pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        lcd.print("Connecting...");
    }

    //Begins serial communication at 115200 
    Serial.begin(115200);

    //Gives the serial connection a small delay to initialize
    delay(1000);

    //just a little code to make sure ik wifi is up
    if (WiFi.status() == WL_CONNECTED)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Wifi connected!");
        delay(500);
    }

    //sets up wireless code uploads
    ArduinoOTA.setHostname("Spotify-Controller");
    ArduinoOTA.begin();

    //just some practice code to print wifi diagnostic information
    IPAddress ip = WiFi.localIP();
    IPAddress subnet = WiFi.subnetMask();
    IPAddress gateway = WiFi.gatewayIP();
    IPAddress DNS = WiFi.dnsIP();

    Serial.println("IP Address: " + ip.toString());
    Serial.println("Subnet: " + subnet.toString());
    Serial.println("Gateway: " + gateway.toString());
    Serial.println("DNS: " + DNS.toString());

}

void loop()
{
    ArduinoOTA.handle();

    currentSeconds = millis()/1000;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Elapsed Time:");
    lcd.setCursor(0,1);
    //You have to declare the first string as a String type using String() bc by default it is a char pointer so adding an int after it makes C++ think its doing pointer arithmetic
    //rather than string concatenation
    lcd.print(currentSeconds + String(" seconds"));
    delay(1000);
} 