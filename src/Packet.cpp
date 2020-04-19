#include "Packet.h"
#include <Arduino.h>

Packet::Packet(unsigned int bikeid, float lat, float lon, bool unlockable, bool locked){

    this->bikeID = bikeid;
    this->latitude = lat;
    this->longitude = lon;
    this->unlockable = unlockable;
    this->locked = locked;

    this->toByte();
    
}

Packet::~Packet()
{

}

void Packet::toByte(){
    
    union {
        float val;
        byte ar[4];
    } lat, lon;

    lat.val = latitude;
    lon.val = longitude;

    ar[0] = 0x00;
    ar[1] = (byte)((bikeID >> 8) & 0xff);
    ar[2] = (byte)(bikeID & 0xff);
    ar[3] = 0x01;
    ar[4] = lat.ar[0];
    ar[5] = lat.ar[1];
    ar[6] = lat.ar[2];
    ar[7] = lat.ar[3];
    ar[8] = 0x02;
    ar[9] = lon.ar[0];
    ar[10] = lon.ar[1];
    ar[11] = lon.ar[2];
    ar[12] = lon.ar[3];
    ar[13] = 0x03;
    ar[14] = (byte)(unlockable & 0xff);
    ar[15] = 0x04;
    ar[16] = (byte)(locked & 0xff);
    ar[17] = 0x0A;

}