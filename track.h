#ifndef TRACK_H
#define TRACK_H
#include <string>
#include "element.h"



class Track : public Element
{
private:


protected:
    int offsetX;
    int offsetY;
    int xLocation;
    int yLocation;
    bool electrified;
    std :: string electrificationMethod;
    int trackSpeed{200};
    int trackLength{100};
    bool trackLinks [9];
    bool location;


public:
    Track();
};

class StraightTrack : public Track
{
private:
    bool platform;



protected:


public:
    StraightTrack(int newOffsetX, int newOffsetY, int newXLocation, int newYLocation,bool newIsElectrified, std :: string newElectrificationMethod);
};

#endif // TRACK_H
