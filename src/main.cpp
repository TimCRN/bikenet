#include "Packet.h"
#include "Bike.h"
#include <Arduino.h>

// Object decleration 
Position* bp = new Position((float)12445.1266654,(float)154662.156442);
Bike* bike = new Bike((unsigned)12, *bp, 1, 1);

// Led pin decleration
int ledLockState = 2;
int ledUnlockable = 3;
int buttonLock = 4;

// Time buffer variable for lock and unlock
unsigned long lockBuffer = 0;

void setup() 
{
  pinMode(ledLockState, OUTPUT);
  pinMode(ledUnlockable, OUTPUT);
  pinMode(buttonLock, INPUT);

  bike->SetUnlockTime();

  Serial.begin(9600);   
}

void update() {   

  // Compose Packet
  // Packet* p = nullptr;
  Packet p(
    bike->GetID(), 
    (bike->GetPosition()).latitude, 
    (bike->GetPosition()).longitude,
    bike->GetUnlockable(),
    bike->GetLockState()
    );

  // Write the Byte Array
  for(int i = 0; i < 18; i++) {
    Serial.write(p.toByte()[i]);
  }

  // Delete Packet Pointer
  // delete p;  

}

void listen() {

  byte command;
  command = Serial.read();

  switch((int)command){

    case 1: // Make bike unlockable

      update();
      break;

    case 2: // Request Packet

      bike->SetUnlockable(true);
      bike->SetUnlockTime();        
      break;    

    default: // Undefined commands

      Serial.print("Command ");
      Serial.print("'");
      Serial.print(command);
      Serial.print("'");
      Serial.println(" not defined!");

      break;
  }

}

void ledUpdate() {

  if(bike->GetUnlockable() && digitalRead(ledUnlockable) != HIGH) {
    digitalWrite(ledUnlockable, HIGH);
  }
  else if(!bike->GetUnlockable() && digitalRead(ledUnlockable) != LOW) {
    digitalWrite(ledUnlockable, LOW);
  }

  if(bike->GetLockState() && digitalRead(ledLockState) != HIGH) {
    digitalWrite(ledLockState, HIGH);
  }
  else if(!bike->GetLockState() && digitalRead(ledLockState) != LOW) {
    digitalWrite(ledLockState, LOW);
  }

}

void lockLogicUpdate(){

  if(bike->GetUnlockable() && (millis() - bike->GetUnlockTime()) >= 10000) {
    bike->SetUnlockable(false);
  }

  if(digitalRead(buttonLock) == HIGH && bike->GetUnlockable()) {
    bike->SetLockState(false);
    bike->SetUnlockable(false);
    lockBuffer = millis();
  }
  else if (digitalRead(buttonLock) == HIGH && !bike->GetUnlockable() &&  millis() - lockBuffer >= 2000 ) {
    bike->SetLockState(true);
    lockBuffer = 0;
  }  

}

void loop() {

  lockLogicUpdate();
  ledUpdate();  

  if(Serial.available() > 0){
    listen();
  }  

  delay(3);
    
}