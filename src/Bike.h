#ifndef BIKE_H
#define BIKE_H

#include <Arduino.h>
#include "Position.h"

class Bike {
    public:
        Bike(unsigned int id, Position& p, bool unlockable, bool lockState);
        ~Bike();

    private:
        unsigned int id;
        Position& pos;
        bool unlockable;
        bool lockState;
        unsigned long unlockTime;

    public:
        unsigned int GetID();
        Position& GetPosition();
        bool GetUnlockable();
        bool GetLockState();
        unsigned long GetUnlockTime();

        void SetPosition(Position p);
        void SetUnlockable(bool state);
        void SetLockState(bool state);
        void SetUnlockTime();

};

#endif // BIKE_H