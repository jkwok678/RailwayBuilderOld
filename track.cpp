#include "track.h"
#include "element.h"

Track::Track()
{

};


StraightTrack :: StraightTrack(int newOffsetX, int newOffsetY, int newXLocation,int newYLocation)
{
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newXLocation;
    locationY = newYLocation;
};
