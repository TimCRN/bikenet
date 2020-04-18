#include "Packet.h"
#include <Arduino.h>

void setup() {

  Serial.begin(9600);  

}

void update() {
  
   Packet* j = nullptr;
  // byte* b = nullptr;

  // Compose Packet
  j = new Packet(1, 1442.0221, 6413.024, 0, 1);
  
  // Turn Packet into Byte Array
  // b = j->toByte();

  // Write the Byte Array
  for(int i = 0; i < 18; i++) {
    Serial.write(j->toByte()[i]);
  }

  // Delete Pointers
  delete j; 
  // delete b;   

}

void listen() {

  byte command;
  command = Serial.read();

  switch((int)command){
    case 1:
    // Some shit
        
      break;
    case 2:
    // Some other fucking shit

      break;
    case 3:
    // Shit that makes you want to kill yourself

      break;      
    default:
    // Big fucking niggers, you asshole
      Serial.println("banaan");

      break;
  }

}

void loop() {
  
  if(Serial.available() > 0){
    listen();
  }
  else {
    update();
  }

  delay(5000);
    
}