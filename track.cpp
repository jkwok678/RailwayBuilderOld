#include "track.h"
#include "element.h"

Track::Track()
{
    
};

int Track::getTrackMainSpeed() const
{
    return trackMainSpeed;
}

void Track::setTrackMainSpeed(int value)
{
    trackMainSpeed = value;
}

int Track::getTrackMainLength() const
{
    return trackMainLength;
}

void Track::setTrackMainLength(int value)
{
    trackMainLength = value;
}

int Track::getTrackSecondarySpeed() const
{
    return trackSecondarySpeed;
}

void Track::setTrackSecondarySpeed(int value)
{
    trackSecondarySpeed = value;
}


int Track::getTrackSecondaryLength() const
{
    return trackSecondaryLength;
}

void Track::setTrackSecondaryLength(int value)
{
    trackSecondaryLength = value;
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

bool Track::getLink0()
{
    return links[0];
}

bool Track::getLink1()
{
     return links[1];
}

bool Track::getLink2()
{
     return links[2];
}

bool Track::getLink3()
{
     return links[3];
}

bool Track::getLink4()
{
     return links[4];
}

bool Track::getLink5()
{
     return links[5];
}

bool Track::getLink6()
{
     return links[6];
}

bool Track::getLink7()
{
     return links[7];
}

bool Track::getLink8()
{
     return links[8];
}

bool Track::getFound() const
{
    return found;
}

void Track::setFound(bool newFound)
{
    found = newFound;
}

StraightTrack::StraightTrack()
{
    
}

StraightTrack::StraightTrack(StraightType newStraightType, int newLocationX, int newLocationY)
{
    straightType = newStraightType;
    locationX = newLocationX;
    locationY = newLocationY;
    switch (straightType)
    {
        case StraightType::STRAIGHTH:
        {
            links[3] = true;
            links[5] = true;
            break;
        }
        case StraightType::STRAIGHTV:
        {
            links[1] = true;
            links[7] = true;
            break;
        }
        case StraightType::STRAIGHTLEFTUP:
        {
            links[0] = true;
            links[8] = true;
            break;
        }
        case StraightType::STRIAGHTRIGHTUP:
        {
            links[2] = true;
            links[6] = true;
            break;
        }
    }

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
    switch(directType)
    {
        case DirectType::DIRECTLEFT:
        case DirectType::DIRECTRIGHT:
        {
            links[3] = true;
            links[5] = true;
            break;
        }
        case DirectType::DIRECTUP:
        case DirectType::DIRECTDOWN:
        {
            links[1] = true;
            links[7] = true;
            break;
        }
        case DirectType::DIRECTLEFTUP:
        case DirectType::DIRECTRIGHTDOWN:
        {
            links[0] = true;
            links[8] = true;
            break;
        }
        case DirectType::DIRECTRIGHTUP:
        case DirectType::DIRECTLEFTDOWN:
        {
            links[2] = true;
            links[6] = true;
            break;
        }

    }

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
    switch (curvedType)
    {
        case CurvedType::TIGHTCURVE1:
        {
            links[5] = true;
            links[7] = true;
            break;
        }
        case CurvedType::TIGHTCURVE2:
        {
            links[3] = true;
            links[7] = true;
            break;
        }
        case CurvedType::TIGHTCURVE3:
        {
            links[1] = true;
            links[5] = true;
            break;
        }
        case CurvedType::TIGHTCURVE4:
        {
            links[1] = true;
            links[3] = true;
            break;
        }
        case CurvedType::CURVE1:
        {
            links[5] = true;
            links[6] = true;
            break;
        }
        case CurvedType::CURVE2:
        {
            links[3] = true;
            links[8] = true;
            break;
        }
        case CurvedType::CURVE3:
        {
            links[0] = true;
            links[5] = true;
            break;
        }
        case CurvedType::CURVE4:
        {
            links[2] = true;
            links[3] = true;
            break;
        }
        case CurvedType::CURVE5:
        {
            links[1] = true;
            links[8] = true;
            break;
        }
        case CurvedType::CURVE6:
        {
            links[1] = true;
            links[6] = true;
            break;
        }
        case CurvedType::CURVE7:
        {
            links[2] = true;
            links[7] = true;
            break;
        }
        case CurvedType::CURVE8:
        {
            links[0] = true;
            links[7] = true;
            break;
        }
    }

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
    linked = false;
    switch(linkedType)
    {
        case LinkedType::LINKLEFT:
        {
            links[5] = true;
            break;
        }
        case LinkedType::LINKRIGHT:
        {
            links[3] = true;
            break;
        }
        case LinkedType::LINKUP:
        {
            links[7] = true;
            break;
        }
        case LinkedType::LINKDOWN:
        {
            links[1] = true;
            break;
        }
        case LinkedType::LINKLEFTUP:
        {
            links[8] = true;
            break;
        }
        case LinkedType::LINKRIGHTDOWN:
        {
            links[0] = true;
            break;
        }
        case LinkedType::LINKLEFTDOWN:
        {
            links[2] = true;
            break;
        }
        case LinkedType::LINKRIGHTUP:
        {
            links[6] = true;
            break;
        }
    }
}

LinkedType LinkedTrack::getLinkedType() const
{
    return linkedType;
}

void LinkedTrack::setLinkedType(const LinkedType &newLinkedType)
{
    linkedType = newLinkedType;
}

bool LinkedTrack::getLinked() const
{
    return linked;
}

void LinkedTrack::setLinked(bool value)
{
    linked = value;
}

std::shared_ptr<LinkedTrack> LinkedTrack::getOtherLinkTrack()
{
    return otherLinkTrack;
}

void LinkedTrack::setOtherLinkTrack(std::shared_ptr<LinkedTrack> &newLinkedTrack)
{
    otherLinkTrack = newLinkedTrack;
}


ExitTrack::ExitTrack(ExitType newExitType, int newLocationX, int newLocationY)
{
    exitType = newExitType;
    locationX = newLocationX;
    locationY = newLocationY;
    switch (exitType)
    {
        case ExitType::EXITLEFT:
        {
            links[5] = true;
            break;
        }
        case ExitType::EXITRIGHT:
        {
            links[3] = true;
            break;
        }
        case ExitType::EXITUP:
        {
            links[7] = true;
            break;
        }
        case ExitType::EXITDOWN:
        {
            links[1] = true;
            break;
        }
        case ExitType::EXITLEFTUP:
        {
            links[8] = true;
            break;
        }
        case ExitType::EXITRIGHTUP:
        {
            links[6] = true;
            break;
        }
        case ExitType::EXITLEFTDOWN:
        {
            links[2] = true;
            break;
        }
        case ExitType::EXITRIGHTDOWN:
        {
            links[0] = true;
            break;
        }
    }

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
    switch (bufferType)
    {
        case BufferType::BUFFERLEFT:
        {
            links[5] = true;
            break;
        }
        case BufferType::BUFFERRIGHT:
        {
            links[3] = true;
            break;
        }
        case BufferType::BUFFERUP:
        {
            links[7] = true;
            break;
        }
        case BufferType::BUFFERDOWN:
        {
            links[1] = true;
            break;
        }
        case BufferType::BUFFERLEFTUP:
        {
            links[8] = true;
            break;
        }
        case BufferType::BUFFERRIGHTUP:
        {
            links[6] = true;
            break;
        }
        case BufferType::BUFFERLEFTDOWN:
        {
            links[2] = true;
            break;
        }
        case BufferType::BUFFERRIGHTDOWN:
        {
            links[0] = true;
            break;
        }
    }

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
    switch (signalType)
    {
        case SignalType::SIGNALLEFT:
        case SignalType::SIGNALRIGHT:
        {
            links[3] = true;
            links[5] = true;
            break;
        }
        case SignalType::SIGNALUP:
        case SignalType::SIGNALDOWN:
        {
            links[1] = true;
            links[7] = true;
            break;
        }
        case SignalType::SIGNALLEFTUP:
        case SignalType::SIGNALRIGHTDOWN:
        {
            links[0] = true;
            links[8] = true;
            break;
        }
        case SignalType::SIGNALRIGHTUP:
        case SignalType::SIGNALLEFTDOWN:
        {
            links[2] = true;
            links[6] = true;
            break;
        }
    }

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
    switch (bridgeUnderpassType)
    {
        case BridgeUnderpassType::BRIDGE1:
        case BridgeUnderpassType::UNDERPASS1:
        {
            links[3] = true;
            links[5] = true;
            break;
        }
        case BridgeUnderpassType::BRIDGE2:
        case BridgeUnderpassType::UNDERPASS2:
        {
            links[1] = true;
            links[7] = true;
            break;
        }
    }
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
    trackSecondaryLength = 100;
    trackSecondarySpeed = 200;
    switch (switchType)
    {
        case SwitchType::SWITCHTIGHT1:
        case SwitchType::SWITCHTIGHT2:
        {
            links[1] = true;
            links[3] = true;
            links[5] = true;
            break;
        }
        case SwitchType::SWITCHTIGHT3:
        case SwitchType::SWITCHTIGHT4:
        {
            links[3] = true;
            links[5] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCHTIGHT5:
        case SwitchType::SWITCHTIGHT7:
        {
            links[1] = true;
            links[3] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCHTIGHT6:
        case SwitchType::SWITCHTIGHT8:
        {
            links[1] = true;
            links[5] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT1:
        {
            //Left diverging is main, right diverging is secondary.
            links[2] = true;
            links[3] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT2:
        {
            //Left diverging is main, Right diverging is secondary.
            links[0] = true;
            links[5] = true;
            links[6] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT3:
        {
            //Left diverging is main, right diverging is secondary.
            links[2] = true;
            links[3] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT4:
        {
            //Left diverging is main, right diverging is secondary.
            links[1] = true;
            links[5] = true;
            links[6] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT5:
        {
            //Left diverging is main, right diverging is secondary.
            links[1] = true;
            links[3] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT6:
        {
            //Left diverging is main, right diverging is secondary.
            links[0] = true;
            links[5] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT7:
        {
            //Left diverging is main, right diverging is secondary.
            links[0] = true;
            links[2] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCHSPLIT8:
        {
            //Left diverging is main, right diverging is secondary.
            links[1] = true;
            links[6] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCH1:
        {
            links[2] = true;
            links[3] = true;
            links[5] = true;
            break;
        }
        case SwitchType::SWITCH2:
        {
            links[0] = true;
            links[3] = true;
            links[5] = true;
            break;
        }
        case SwitchType::SWITCH3:
        {
            links[3] = true;
            links[5] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCH4:
        {
            links[3] = true;
            links[5] = true;
            links[6] = true;
            break;
        }
        case SwitchType::SWITCH5:
        {
            links[0] = true;
            links[1] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCH6:
        {
            links[1] = true;
            links[2] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCH7:
        {
            links[1] = true;
            links[6] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCH8:
        {
            links[1] = true;
            links[7] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCH9:
        {
            links[0] = true;
            links[1] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCH10:
        {
            links[1] = true;
            links[2] = true;
            links[6] = true;
            break;
        }
        case SwitchType::SWITCH11:
        {
            links[2] = true;
            links[6] = true;
            links[7] = true;
            break;
        }
        case SwitchType::SWITCH12:
        {
            links[0] = true;
            links[7] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCH13:
        {
            links[0] = true;
            links[3] = true;
            links[8] = true;
            break;
        }
        case SwitchType::SWITCH14:
        {
            links[2] = true;
            links[5] = true;
            links[6] = true;
            break;
        }
        case SwitchType::SWITCH15:
        {
            links[2] = true;
            links[3] = true;
            links[6] = true;
            break;
        }
        case SwitchType::SWITCH16:
        {
            links[0] = true;
            links[5] = true;
            links[8] = true;
            break;
        }
    }
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
    trackSecondaryLength = 100;
    trackSecondaryLength = 200;
    switch (crossoverType)
    {
        case CrossoverType::CROSSOVER1:
        {
            //Horizontal is main, vertical is secondary
            links[1] = true;
            links[3] = true;
            links[5] = true;
            links[7] = true;
            break;
        }
        case CrossoverType::CROSSOVER2:
        {
            //Top left to Bottom right is main, other is secondary
            links[0] = true;
            links[2] = true;
            links[6] = true;
            links[8] = true;
            break;
        }
        case CrossoverType::CROSSOVER3:
        {
            //Vertical is main, other is secondary
            links[0] = true;
            links[1] = true;
            links[7] = true;
            links[8] = true;
            break;
        }
        case CrossoverType::CROSSOVER4:
        {
            //Vertical is main, other is secondary
            links[1] = true;
            links[2] = true;
            links[6] = true;
            links[7] = true;
            break;
        }
        case CrossoverType::CROSSOVER5:
        {
            //Horizontal is main, other is secondary
            links[0] = true;
            links[3] = true;
            links[5] = true;
            links[8] = true;
            break;
        }
        case CrossoverType::CROSSOVER6:
        {
            //Horizontal is main, other is secondary
            links[2] = true;
            links[3] = true;
            links[5] = true;
            links[6] = true;
            break;
        }
    }

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
    trackSecondaryLength = 100;
    trackSecondaryLength = 200;
    switch (flyoverType)
    {
        case FlyoverType::FLYOVER1:
        case FlyoverType::FLYOVER2:
        {
            //For Flyover 1, vertical is the Top Track and the main track.
            //For Flyover 2, horizontal is the Top Track and the main track.
            links[1] = true;
            links[3] = true;
            links[5] = true;
            links[7] = true;
            break;
        }
        case FlyoverType::FLYOVER3:
        case FlyoverType::FLYOVER4:
        {
            //For Flyover 3, top left to bottom right is the Top Track and the main track.
            //For Flyover 4, top right to bottom left is the Top Track and the main track.
            links[0] = true;
            links[2] = true;
            links[6] = true;
            links[8] = true;
            break;
        }
        case FlyoverType::FLYOVER5:
        case FlyoverType::FLYOVER7:
        {
            //For Flyover 5, Vertical is the Top Track and the main track.
            //For Flyover 7, top left to bottom right is the Top Track and the main track.
            links[0] = true;
            links[1] = true;
            links[7] = true;
            links[8] = true;
            break;
        }
        case FlyoverType::FLYOVER6:
        case FlyoverType::FLYOVER8:
        {
            //For Flyover 6, Vertical is the Top Track and the main track.
            //For Flyover 8, top right to bottom left is the Top Track and the main track.
            links[1] = true;
            links[2] = true;
            links[6] = true;
            links[7] = true;
            break;
        }
        case FlyoverType::FLYOVER9:
        case FlyoverType::FLYOVER11:
        {
            //For Flyover 9, Horizontal is the Top Track and the main track.
            //For Flyover 11, top left to bottom right is the Top Track and the main track.
            links[0] = true;
            links[3] = true;
            links[5] = true;
            links[8] = true;
            break;
        }
        case FlyoverType::FLYOVER10:
        case FlyoverType::FLYOVER12:
        {
            //For Flyover 10, Horizontal is the Top Track and the main track.
            //For Flyover 12, top right to bottom left Top Track and the main track.
            links[2] = true;
            links[3] = true;
            links[5] = true;
            links[6] = true;
            break;
        }
    }

}

FlyoverType FlyoverTrack::getFlyoverType() const
{
    return flyoverType;
}

void FlyoverTrack::setFlyoverType(const FlyoverType &newFlyoverType)
{
    flyoverType = newFlyoverType;
}
