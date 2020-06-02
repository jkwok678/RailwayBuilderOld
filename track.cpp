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
    platformLeft = false;
    platformRight = false;
    platformUp = false;
    platformDown = false;
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
}

bool StraightTrack::getPlatformLeft() const
{
    return platformLeft;
}

void StraightTrack::setPlatformLeft(bool newPlatform)
{
    platformLeft = newPlatform;
}

bool StraightTrack::getPlatformRight() const
{
    return platformRight;
}

void StraightTrack::setPlatformRight(bool newPlatform)
{
    platformRight = newPlatform;
}

bool StraightTrack::getPlatformUp() const
{
    return platformUp;
}

void StraightTrack::setPlatformUp(bool newPlatform)
{
    platformUp = newPlatform;
}

bool StraightTrack::getPlatformDown() const
{
    return platformDown;
}

void StraightTrack::setPlatformDown(bool newPlatform)
{
    platformDown = newPlatform;
}

DirectTrack::DirectTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
    platformLeft = false;
    platformRight = false;
    platformUp = false;
    platformDown = false;
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
    platformLeft = false;
    platformRight = false;
    platformUp = false;
    platformDown = false;

}

SignalTrack::SignalTrack(ElementType newElementType, int newAspect, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	aspect = newAspect;
	offsetX = newOffsetX;
	offsetY = newOffsetY;
	locationX = newLocationX;
	locationY = newLocationY;
    platformLeft = false;
    platformRight = false;
    platformUp = false;
    platformDown = false;

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
    platformLeft = false;
    platformRight = false;
    platformUp = false;
    platformDown = false;

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
