#ifndef POSITION_H
#define POSITION_H

#include <Arduino.h>

struct Position {

    Position(float lat, float lon);
    float latitude, longitude;

};

#endif // POSITION_H