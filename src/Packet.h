#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>

struct Packet {

    Packet(unsigned int bikeid, float lat, float lon, bool unlockable, bool locked);
    ~Packet();

    unsigned int bikeID;

    byte ar[18];

    float latitude;
    float longitude;

    bool unlockable;
    bool locked;

    void toByte();   

};

#endif // PACKET_H