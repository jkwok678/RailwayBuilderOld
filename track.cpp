#include "track.h"
#include "element.h"

Track::Track()
{

};


StraightTrack :: StraightTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newXLocation,int newYLocation)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newXLocation;
    locationY = newYLocation;
};
