#include "Packet.h"
#include <Arduino.h>

Packet::Packet(unsigned int bikeid, float lat, float lon, bool unlockable, bool locked){
    this->bikeID = bikeid;
    this->latitude = lat;
    this->longitude = lon;
    this->unlockable = unlockable;
    this->locked = locked;
}

Packet::~Packet()
{
    
}

byte* Packet::toByte(){
    
    union {
        float val;
        byte ar[4];
    } lat, lon;

    lat.val = latitude;
    lon.val = longitude;

    static byte ar[18] =
    {
        0x00,
        (byte)((bikeID >> 8) & 0xff),
        (byte)(bikeID & 0xff),
        0x01,
        lat.ar[0],
        lat.ar[1],
        lat.ar[2],
        lat.ar[3],
        0x02,
        lon.ar[0],
        lon.ar[1],
        lon.ar[2],
        lon.ar[3],
        0x03,
        (byte)(unlockable & 0xff),
        0x04,
        (byte)(locked & 0xff),
        0x0A
    };

    return ar;
}