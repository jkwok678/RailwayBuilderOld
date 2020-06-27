#include "track.h"
#include "element.h"




Track::Track()
{
    
};

int Track::getTrackSpeed() const
{
    return trackSpeed;
}

void Track::setTrackSpeed(int value)
{
    trackSpeed = value;
}

int Track::getTrackLength() const
{
    return trackLength;
}

void Track::setTrackLength(int value)
{
    trackLength = value;
}

bool Track::getPlatform1() const
{
    return platform1;
}

void Track::setPlatform1(bool newPlatform)
{
    platform1 = newPlatform;
}

bool Track::getPlatform2() const
{
    return platform2;
}

void Track::setPlatform2(bool newPlatform)
{
    platform2 = newPlatform;
}

bool Track::getNamed() const
{
    return named;
}

void Track::setNamed(bool newNamed)
{
    named = newNamed;
}

std::shared_ptr<Text> Track::getText()
{
    return text;
}

void Track::setText(std::shared_ptr<Text> &newText)
{
    text = newText;
}

StraightTrack::StraightTrack()
{
    
}

StraightTrack::StraightTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
    locationX = newLocationX;
    locationY = newLocationY;

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


bool StraightTrack::hasLevelCrossing() const
{
    return levelCrossing;
}

void StraightTrack::addLevelCrossing()
{
    levelCrossing = true;
}



DirectTrack::DirectTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}


CurvedTrack::CurvedTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}


LinkedTrack::LinkedTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;
}

ExitTrack::ExitTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}

BufferTrack::BufferTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}

SignalTrack::SignalTrack(ElementType newElementType, int newAspect, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	aspect = newAspect;
	locationX = newLocationX;
	locationY = newLocationY;

}

int SignalTrack::getAspect() const
{
	return aspect;
}

void SignalTrack::setAspect(int newAspect)
{
	aspect = newAspect;
}

BridgeUnderpassTrack::BridgeUnderpassTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;
}

SwitchTrack::SwitchTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}

CrossoverTrack::CrossoverTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}

FlyoverTrack::FlyoverTrack(ElementType newElementType, int newLocationX, int newLocationY)
{
	elementType = newElementType;
	locationX = newLocationX;
	locationY = newLocationY;

}
