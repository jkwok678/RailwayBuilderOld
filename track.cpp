#include "track.h"
#include "element.h"

Track::Track()
{

};


StraightTrack :: StraightTrack(int newOffsetX, int newOffsetY, int newXLocation,
                               int newYLocation,bool newIsElectrified, std :: string newElectrificationMethod)
{
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    xLocation = newXLocation;
    yLocation = newYLocation;
    electrified = newIsElectrified;
    electrificationMethod = newElectrificationMethod;
};
