#include <Arduino.h>
#include "TinyGPS++.h"

TinyGPSPlus gps;

void setup() {
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop() {

    while(Serial1.available())
    {
        if(gps.encode(Serial1.read()))
        {
            String msg = Serial1.readStringUntil('\r');
            Serial.println(msg);

            Serial.print("LAT="); Serial.println(gps.location.lat(), 6);
            Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
            Serial.print("ALT="); Serial.println(gps.altitude.meters(), 6);
            delay(4*1000);
        }
    }  
}