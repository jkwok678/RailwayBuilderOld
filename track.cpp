#include "track.h"
#include "element.h"

Track::Track()
{

};


StraightTrack :: StraightTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX,int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
}

StraightTrack::~StraightTrack()
{
    if (elementType==ElementType::STRAIGHTH)
    {
        std::cout.flush() << "Straight H destroyed \n";
    }
    if (elementType==ElementType::STRAIGHTV)
    {
        std::cout.flush() << "Straight V destroyed \n";
    }

};
