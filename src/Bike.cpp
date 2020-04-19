#include "Bike.h"
#include <Arduino.h>

Bike::Bike(unsigned int id, Position& p, bool unlockable, bool lockState):
    pos(p)
{
    this->id = id;
    this->unlockable = unlockable;
    this->lockState = lockState;
}

Bike::~Bike(){
    delete &pos;
}

unsigned int Bike::GetID(){
    return this->id;
}

Position& Bike::GetPosition(){
    return this->pos;
}

bool Bike::GetUnlockable(){
    return this->unlockable;
}

bool Bike::GetLockState(){
    return this->lockState;
}

unsigned long Bike::GetUnlockTime(){
    return this->unlockTime;
}

void Bike::SetPosition(Position p){
    this->pos = p;
}

void Bike::SetUnlockable(bool state){
    this->unlockable = state;
}

void Bike::SetLockState(bool state){
    this->lockState = state;
}

void Bike::SetUnlockTime(){
    this->unlockTime = millis();
}
