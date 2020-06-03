#include "Particle.h"

void setup() {
    Wire.begin(0x40); //Initialise argon on slave address 40
    Wire.onReceive(observeEvent); //When master device sends signal, call observeEvent
    
    Serial.print("Light value");
}

void observeEvent(int bytes) {
    int c = Wire.read(); //Read value from RPi
    
    while( Wire.available() ) {

         if( c == 1 ) {
             Serial.println("Too dark"); 
         }
         else if( c == 2 ) {
             Serial.println("Dark"); 
         }
         else if( c == 3 ) {
             Serial.println("Medium"); 
         }
          else if( c == 4 ) {
             Serial.println("Bright"); 
         }
         else {
             Serial.println("Too bright"); 
         }
    }
}

void loop() {
    delay(50);
}