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

bool Track::getPlatformAny() const
{
    return platformAny;
}

void Track::setPlatformAny(bool value)
{
    platformAny = value;
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



StraightTrack::StraightTrack()
{
    
}

StraightTrack::StraightTrack(StraightType newStraightType, int newLocationX, int newLocationY)
{
    straightType = newStraightType;
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

StraightType StraightTrack::getStraightType() const
{
    return straightType;
}

void StraightTrack::setStraightType(const StraightType &newStraightType)
{
    straightType = newStraightType;
}

bool StraightTrack::hasLevelCrossing() const
{
    return levelCrossing;
}

void StraightTrack::addLevelCrossing()
{
    levelCrossing = true;
}


DirectTrack::DirectTrack(DirectType newDirectType, int newLocationX, int newLocationY)
{
    directType = newDirectType;
    locationX = newLocationX;
    locationY = newLocationY;

}

DirectType DirectTrack::getDirectType() const
{
    return directType;
}

void DirectTrack::setDirectType(const DirectType &newDirectType)
{
    directType = newDirectType;
}




CurvedTrack::CurvedTrack(CurvedType newCurvedType, int newLocationX, int newLocationY)
{
    curvedType = newCurvedType;
    locationX = newLocationX;
    locationY = newLocationY;

}

CurvedType CurvedTrack::getCurvedType() const
{
    return curvedType;
}

void CurvedTrack::setCurvedType(const CurvedType &newCurvedType)
{
    curvedType = newCurvedType;
}



LinkedTrack::LinkedTrack(LinkedType newLinkedType, int newLocationX, int newLocationY)
{
    linkedType = newLinkedType;
    locationX = newLocationX;
    locationY = newLocationY;
}

LinkedType LinkedTrack::getLinkedType() const
{
    return linkedType;
}

void LinkedTrack::setLinkedType(const LinkedType &newLinkedType)
{
    linkedType = newLinkedType;
}


ExitTrack::ExitTrack(ExitType newExitType, int newLocationX, int newLocationY)
{
    exitType = newExitType;
    locationX = newLocationX;
    locationY = newLocationY;

}

ExitType ExitTrack::getExitType() const
{
    return exitType;
}

void ExitTrack::setExitType(const ExitType &newExitType)
{
    exitType = newExitType;
}

BufferTrack::BufferTrack(BufferType newBufferType, int newLocationX, int newLocationY)
{
    bufferType = newBufferType;
    locationX = newLocationX;
    locationY = newLocationY;

}

BufferType BufferTrack::getBufferType() const
{
    return bufferType;
}

void BufferTrack::setBufferType(const BufferType &newBufferType)
{
    bufferType = newBufferType;
}

SignalTrack::SignalTrack(SignalType newSignalType, int newAspect, int newLocationX, int newLocationY)
{
    signalType = newSignalType;
    aspect = newAspect;
	locationX = newLocationX;
	locationY = newLocationY;

}

SignalType SignalTrack::getSignalType() const
{
    return signalType;
}

void SignalTrack::setSignalType(const SignalType &newSignalType)
{
    signalType = newSignalType;
}

int SignalTrack::getAspect() const
{
	return aspect;
}

void SignalTrack::setAspect(int newAspect)
{
	aspect = newAspect;
}


BridgeUnderpassTrack::BridgeUnderpassTrack(BridgeUnderpassType newBridgeUnderpassType, int newLocationX, int newLocationY)
{
    bridgeUnderpassType = newBridgeUnderpassType;
    locationX = newLocationX;
    locationY = newLocationY;
}

BridgeUnderpassType BridgeUnderpassTrack::getBridgeUnderpassType() const
{
    return bridgeUnderpassType;
}

void BridgeUnderpassTrack::setBridgeUnderpassType(const BridgeUnderpassType &newBridgeUnderpassType)
{
    bridgeUnderpassType = newBridgeUnderpassType;
}

SwitchTrack::SwitchTrack(SwitchType newSwitchType, int newLocationX, int newLocationY)
{
    switchType = newSwitchType;
    locationX = newLocationX;
    locationY = newLocationY;

}

SwitchType SwitchTrack::getSwitchType() const
{
    return switchType;
}

void SwitchTrack::setSwitchType(const SwitchType &newSwitchType)
{
    switchType = newSwitchType;
}



CrossoverTrack::CrossoverTrack(CrossoverType newCrossoverType, int newLocationX, int newLocationY)
{
    crossoverType = newCrossoverType;
    locationX = newLocationX;
    locationY = newLocationY;

}

CrossoverType CrossoverTrack::getCrossoverType() const
{
    return crossoverType;
}

void CrossoverTrack::setCrossoverType(const CrossoverType &newCrossoverType)
{
    crossoverType = newCrossoverType;
}



FlyoverTrack::FlyoverTrack(FlyoverType newFlyoverType, int newLocationX, int newLocationY)
{
    flyoverType = newFlyoverType;
    locationX = newLocationX;
    locationY = newLocationY;

}

FlyoverType FlyoverTrack::getFlyoverType() const
{
    return flyoverType;
}

void FlyoverTrack::setFlyoverType(const FlyoverType &newFlyoverType)
{
    flyoverType = newFlyoverType;
}
