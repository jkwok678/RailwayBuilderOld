#include "track.h"
#include "element.h"

Track::Track()
{

};


StraightTrack::StraightTrack()
{

}

StraightTrack::StraightTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
    platform1 = false;
    platform2 = false;

}

StraightTrack::~StraightTrack()
{
	//Only used for debugging purposes.
	/*if (elementType==ElementType::STRAIGHTH)
	{
		std::cout << "Straight H destroyed \n" << std::flush;;
	}
	if (elementType==ElementType::STRAIGHTV)
	{
		std::cout << "Straight V destroyed \n" << std::flush;;
	}
	*/
};

DirectTrack::DirectTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
    platform1 = false;
    platform2 = false;
}


CurvedTrack::CurvedTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;

}


LinkedTrack::LinkedTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
}

ExitTrack::ExitTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;

}

BufferTrack::BufferTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
    platform1 = false;
    platform2 = false;

}

SignalTrack::SignalTrack(ElementType newElementType, int newAspect, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	aspect = newAspect;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
    platform1 = false;
    platform2 = false;

}

int SignalTrack::getAspect() const
{
	return aspect;
}

void SignalTrack::setAspect(int newAspect)
{
	aspect = newAspect;
}

BridgeUnderpassTrack::BridgeUnderpassTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
    platform1 = false;
    platform2 = false;

}

SwitchTrack::SwitchTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;

}

CrossoverTrack::CrossoverTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;

}

FlyoverTrack::FlyoverTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;

}
