#include "map.h"



Map::Map()
{
    
}

int Map::getTotalTrack() const
{
    return totalTrack;
}

void Map::setTotalTrack(int newTrackTotal)
{
    totalTrack = newTrackTotal;
}


std::vector<std::shared_ptr<StraightTrack> > Map::getStraightTrackList() const
{
    return straightTrackList;
}

void Map::setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> >& newSignalTrackList)
{
	straightTrackList = newSignalTrackList;
}

void Map::addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack)
{

	int tempLocationX = newStraightTrack->getLocationX();
    int templocationY = newStraightTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		straightTrackList.push_back(newStraightTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<StraightTrack> Map::getStraightTrackAt(int locationX, int locationY)
{
    std::shared_ptr<StraightTrack> straightTrack = nullptr;
    if (!straightTrackList.empty())
    {
        for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                straightTrack = currentElement;
                break;
            }
        }
    }
    return straightTrack;
}




std::vector<std::shared_ptr<DirectTrack> > Map::getDirectTrackList() const
{
	return directTrackList;
}

void Map::setDirectTrackList(const std::vector<std::shared_ptr<DirectTrack> >& newDirectTrackList)
{
	directTrackList = newDirectTrackList;
}

void Map::addDirectTrack(std::shared_ptr<DirectTrack> newDirectTrack)
{
	int tempLocationX = newDirectTrack->getLocationX();
    int templocationY = newDirectTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		directTrackList.push_back(newDirectTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<DirectTrack> Map::getDirectTrackAt(int locationX, int locationY)
{
    std::shared_ptr<DirectTrack> directTrack = nullptr;
    if (!directTrackList.empty())
    {
        for (std::shared_ptr<DirectTrack>& currentElement : directTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                directTrack = currentElement;
                break;
            }
        }
    }
    return directTrack;
}




std::vector<std::shared_ptr<CurvedTrack> > Map::getCurvedTrackList() const
{
	return curvedTrackList;
}

void Map::setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> >& newCurvedTrackList)
{
	curvedTrackList = newCurvedTrackList;
}

void Map::addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack)
{
	int tempLocationX = newCurvedTrack->getLocationX();
    int templocationY = newCurvedTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		curvedTrackList.push_back(newCurvedTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<CurvedTrack> Map::getCurvedTrackAt(int locationX, int locationY)
{
    std::shared_ptr<CurvedTrack> curvedTrack = nullptr;
    if (!curvedTrackList.empty())
    {
        for (std::shared_ptr<CurvedTrack>& currentElement : curvedTrackList)
        {

            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                curvedTrack = currentElement;
                break;
            }
        }
    }
    return curvedTrack;
}




std::vector<std::shared_ptr<LinkedTrack> > Map::getLinkedTrackList() const
{
	return linkedTrackList;
}

void Map::setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> >& newLinkedTrackList)
{
	linkedTrackList = newLinkedTrackList;
}

void Map::addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack)
{
	int tempLocationX = newLinkedTrack->getLocationX();
    int templocationY = newLinkedTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		linkedTrackList.push_back(newLinkedTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<LinkedTrack> Map::getLinkedTrackAt(int locationX, int locationY)
{
    std::shared_ptr<LinkedTrack> linkedTrack = nullptr;
    if (!linkedTrackList.empty())
    {
        for (std::shared_ptr<LinkedTrack>& currentElement : linkedTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                linkedTrack = currentElement;
                break;
            }
        }
    }
    return linkedTrack;
}

bool Map::haslinkTrackAt(int locationX, int locationY)
{
    bool found = false;
    if (!linkedTrackList.empty())
    {
        for (std::shared_ptr<LinkedTrack>& currentTrack : linkedTrackList)
        {
            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }
    return found;
}




std::vector<std::shared_ptr<ExitTrack> > Map::getExitTrackList() const
{
	return exitTrackList;
}

void Map::setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> >& newExitTrackList)
{
	exitTrackList = newExitTrackList;
}

void Map::addExitTrack(std::shared_ptr<ExitTrack> newExitTrack)
{
	int tempLocationX = newExitTrack->getLocationX();
    int templocationY = newExitTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		exitTrackList.push_back(newExitTrack);
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}

}

std::shared_ptr<ExitTrack> Map::getExitTrackAt(int locationX, int locationY)
{
    std::shared_ptr<ExitTrack> exitTrack = nullptr;
    if (!exitTrackList.empty())
    {
        for (std::shared_ptr<ExitTrack>& currentElement : exitTrackList)
        {

            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                exitTrack = currentElement;
                break;
            }
        }
    }
    return exitTrack;
}




std::vector<std::shared_ptr<BufferTrack> > Map::getBufferTrackList() const
{
	return bufferTrackList;
}

void Map::setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> >& newBufferTrackList)
{
	bufferTrackList = newBufferTrackList;
}

void Map::addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack)
{
	int tempLocationX = newBufferTrack->getLocationX();
    int templocationY = newBufferTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		bufferTrackList.push_back(newBufferTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<BufferTrack> Map::getBufferTrackAt(int locationX, int locationY)
{
    std::shared_ptr<BufferTrack> bufferTrack = nullptr;
    if (!bufferTrackList.empty())
    {
        for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                bufferTrack = currentElement;
                break;
            }
        }
    }
    return bufferTrack;
}




std::vector<std::shared_ptr<SignalTrack> > Map::getSignalTrackList() const
{
	return signalTrackList;
}

void Map::setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> >& newSignalTrackList)
{
	signalTrackList = newSignalTrackList;
}

void Map::addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack)
{
	int tempLocationX = newSignalTrack->getLocationX();
    int templocationY = newSignalTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		signalTrackList.push_back(newSignalTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<SignalTrack> Map::getSignalTrackAt(int locationX, int locationY)
{
    std::shared_ptr<SignalTrack> signalTrack = nullptr;
    if (!signalTrackList.empty())
    {
        for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                signalTrack = currentElement;
                break;
            }
        }
    }
    return signalTrack;
}




std::vector<std::shared_ptr<BridgeUnderpassTrack> > Map::getBridgeUnderpassTrackList() const
{
	return bridgeUnderpassTrackList;
}

void Map::setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> >& newBridgeUnderpassTrackList)
{
	bridgeUnderpassTrackList = newBridgeUnderpassTrackList;
}

void Map::addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack)
{

	int tempLocationX = newBridgeUnderpassTrack->getLocationX();
    int templocationY = newBridgeUnderpassTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		bridgeUnderpassTrackList.push_back(newBridgeUnderpassTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}

}

std::shared_ptr<BridgeUnderpassTrack> Map::getBridgeUnderpassTrack(int locationX, int locationY)
{
    std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTrack = nullptr;
    if (!bridgeUnderpassTrackList.empty())
    {
        for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                bridgeUnderpassTrack = currentElement;
                break;
            }
        }
    }
    return bridgeUnderpassTrack;
}




std::vector<std::shared_ptr<SwitchTrack> > Map::getSwitchTrackList() const
{
	return switchTrackList;
}

void Map::setSwitchTrackList(const std::vector<std::shared_ptr<SwitchTrack> >& newSwitchTrackList)
{
	switchTrackList = newSwitchTrackList;
}

void Map::addSwitchTrack(std::shared_ptr<SwitchTrack> newSwitchTrack)
{
	int tempLocationX = newSwitchTrack->getLocationX();
    int templocationY = newSwitchTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		switchTrackList.push_back(newSwitchTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<SwitchTrack> Map::getSwitchTrackAt(int locationX, int locationY)
{
    std::shared_ptr<SwitchTrack> switchTrack = nullptr;
    if (!switchTrackList.empty())
    {
        for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switchTrack = currentElement;
                break;
            }
        }
    }
    return switchTrack;
}




std::vector<std::shared_ptr<CrossoverTrack> > Map::getCrossoverTrackList() const
{
	return crossoverTrackList;
}

void Map::setCrossoverTrackList(const std::vector<std::shared_ptr<CrossoverTrack> >& newCrossoverTrackList)
{
	crossoverTrackList = newCrossoverTrackList;
}

void Map::addCrossoverTrack(std::shared_ptr<CrossoverTrack> newCrossoverTrack)
{
	int tempLocationX = newCrossoverTrack->getLocationX();
    int templocationY = newCrossoverTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		crossoverTrackList.push_back(newCrossoverTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}
}

std::shared_ptr<CrossoverTrack> Map::getCrossoverTrackAt(int locationX, int locationY)
{
    bool found = false;
    std::shared_ptr<CrossoverTrack> crossoverTrack = nullptr;
    if (!crossoverTrackList.empty())
    {
        for (std::shared_ptr<CrossoverTrack>& currentElement : crossoverTrackList)
        {

            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                crossoverTrack = currentElement;
                found = true;
                break;
            }
        }
    }
    return crossoverTrack;
}




std::vector<std::shared_ptr<FlyoverTrack> > Map::getFlyoverTrackList() const
{
	return flyoverTrackList;
}

void Map::setFlyoverTrackList(const std::vector<std::shared_ptr<FlyoverTrack> >& newFlyoverTrackList)
{
	flyoverTrackList = newFlyoverTrackList;
}

void Map::addFlyoverTrack(std::shared_ptr<FlyoverTrack> newFlyoverTrack)
{
	int tempLocationX = newFlyoverTrack->getLocationX();
    int templocationY = newFlyoverTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		flyoverTrackList.push_back(newFlyoverTrack);
        ++totalTrack;
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}

}

std::shared_ptr<FlyoverTrack> Map::getFlyoverTrackAt(int locationX, int locationY)
{
    bool found = false;
    std::shared_ptr<FlyoverTrack> flyoverTrack = nullptr;
    if (!flyoverTrackList.empty())
    {
        for (std::shared_ptr<FlyoverTrack>& currentElement : flyoverTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                flyoverTrack = currentElement;
                found = true;
                break;
            }
        }
    }
    return flyoverTrack;
}




std::vector<std::shared_ptr<NamedLocation> > Map::getNamedLocationList() const
{
	return namedLocationList;
}

void Map::setNamedLocationList(const std::vector<std::shared_ptr<NamedLocation> >& newNamedLocationList)
{
	namedLocationList = newNamedLocationList;
}

void Map::addNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation)
{
	int tempLocationX = newNamedLocation->getLocationX();
    int templocationY = newNamedLocation->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		namedLocationList.push_back(newNamedLocation);
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
    }
}

std::shared_ptr<NamedLocation> Map::getNamedLocationAt(int locationX, int locationY)
{
    std::shared_ptr<NamedLocation> namedLocation = nullptr;
    if (!namedLocationList.empty())
    {
        for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                namedLocation = currentElement;
                break;
            }
        }
    }
    return namedLocation;
}




std::vector<std::shared_ptr<Concourse> > Map::getConcourseList() const
{
	return concourseList;
}

void Map::setConcourseList(const std::vector<std::shared_ptr<Concourse> >& newConcourseList)
{
	concourseList = newConcourseList;
}

void Map::addConcourse(std::shared_ptr<Concourse> newConcourseTrack)
{
	int tempLocationX = newConcourseTrack->getLocationX();
    int templocationY = newConcourseTrack->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		concourseList.push_back(newConcourseTrack);
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}

}

std::shared_ptr<Concourse> Map::getConcourseAt(int locationX, int locationY)
{
    std::shared_ptr<Concourse> concourse = nullptr;
    if (!concourseList.empty())
    {
        for (std::shared_ptr<Concourse>& currentElement : concourseList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                concourse = currentElement;
                break;
            }
        }
    }
    return concourse;
}




std::vector<std::shared_ptr<Parapet> > Map::getParapetList() const
{
	return parapetList;
}

void Map::setParapetList(const std::vector<std::shared_ptr<Parapet> >& newParapetList)
{
	parapetList = newParapetList;
}

void Map::addParapet(std::shared_ptr<Parapet> newParapet)
{

	int tempLocationX = newParapet->getLocationX();
    int templocationY = newParapet->getLocationY();
    if (!checkElementExists(tempLocationX, templocationY))
    {
		parapetList.push_back(newParapet);
	}
    else
    {
		QMessageBox elementExistsAlreadyAlert;
		elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
		elementExistsAlreadyAlert.setText("An element already exists here.");
		elementExistsAlreadyAlert.exec();
	}

}

std::shared_ptr<Parapet> Map::getParapetAt(int locationX, int locationY)
{
    bool found = false;
    std::shared_ptr<Parapet> parapet = nullptr;
    if (!parapetList.empty())
    {
        for (std::shared_ptr<Parapet>& currentElement : parapetList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                parapet = currentElement;
                found = true;
                break;
            }
        }
    }
    return parapet;
}




std::vector<std::shared_ptr<Text> > Map::getTextList() const
{
	return textList;
}

void Map::setTextList(const std::vector<std::shared_ptr<Text> >& newTextList)
{
	textList = newTextList;
}

void Map::addText(std::shared_ptr<Text> newText)
{
	textList.push_back(newText);

}




std::shared_ptr<Element> Map::getElementAt(int locationX, int locationY)
{
    bool found = false;
    std::shared_ptr<Element> element = nullptr;
    if (!namedLocationList.empty())
    {
        for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                element = currentElement;
                found = true;
            }
        }
    }

    if (!concourseList.empty() && found == false)
    {
        for (std::shared_ptr<Concourse>& currentElement : concourseList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                element = currentElement;
                found = true;
            }
        }
    }

    if (!parapetList.empty() && found == false)
    {
        for (std::shared_ptr<Parapet>& currentElement : parapetList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                element = currentElement;
                found = true;
            }
        }
    }
    return element;
}

std::shared_ptr<NamedElement> Map::getNamedElementAt(int locationX, int locationY)
{
    bool found = false;
    std::shared_ptr<NamedElement> element = nullptr;
    if (!namedLocationList.empty())
    {
        for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                element = currentElement;
                found = true;
            }
        }
    }

    if (!concourseList.empty() && found == false)
    {
        for (std::shared_ptr<Concourse>& currentElement : concourseList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                element = currentElement;
                found = true;
            }
        }
    }
    return element;
}

std::shared_ptr<Track> Map::getTrackAt(int locationX, int locationY)
{
    bool found = false;
    std::shared_ptr<Track> track = nullptr;

    if (!straightTrackList.empty())
    {
        for (std::shared_ptr<StraightTrack>& currentTrack : straightTrackList)
        {
            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!directTrackList.empty() && found == false)
    {
        for (std::shared_ptr<DirectTrack>& currentTrack : directTrackList)
        {
            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!curvedTrackList.empty() && found == false)
    {
        for (std::shared_ptr<CurvedTrack>& currentTrack : curvedTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!linkedTrackList.empty() && found == false)
    {
        for (std::shared_ptr<LinkedTrack>& currentTrack : linkedTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!exitTrackList.empty() && found == false)
    {
        for (std::shared_ptr<ExitTrack>& currentTrack : exitTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                    found = true;
            }
        }
    }

    if (!bufferTrackList.empty() && found == false)
    {
        for (std::shared_ptr<BufferTrack>& currentTrack : bufferTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!signalTrackList.empty() && found == false)
    {
        for (std::shared_ptr<SignalTrack>& currentTrack : signalTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!bridgeUnderpassTrackList.empty() && found == false)
    {
        for (std::shared_ptr<BridgeUnderpassTrack>& currentTrack : bridgeUnderpassTrackList)
        {
            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!switchTrackList.empty() && found == false)
    {
        for (std::shared_ptr<SwitchTrack>& currentTrack : switchTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!crossoverTrackList.empty() && found == false)
    {
        for (std::shared_ptr<CrossoverTrack>& currentTrack : crossoverTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }

    if (!flyoverTrackList.empty() && found == false)
    {
        for (std::shared_ptr<FlyoverTrack>& currentTrack : flyoverTrackList)
        {

            int currentX = currentTrack->getLocationX();
            int currentY = currentTrack->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                track = currentTrack;
                found = true;
            }
        }
    }
    return track;
}

std::shared_ptr<Text> Map::getTextAt(int locationX, int locationY)
{
    std::shared_ptr<Text> text = nullptr;
    if (!textList.empty())
    {
        for (std::shared_ptr<Text>& currentText : textList)
        {
            int textCurrentX = currentText->getLocationX();
            int textCurrentY = currentText->getLocationY();
            int textEditableX = currentText->getEditableX();
            int textEditableY = currentText->getEditableY();
            if (locationX >= textCurrentX && locationX <=textEditableX)
            {
                //Text point is at bottom left hand corner
                if (locationY >= textCurrentY && locationY <= textEditableY)
                {
                    text = currentText;
                }
            }
        }
    }
    return text;
}

bool Map::checkElementExists(int locationX, int locationY)
{
    bool found = false;
    if (!straightTrackList.empty())
    {
        for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!directTrackList.empty() && found == false)
    {
        for (std::shared_ptr<DirectTrack>& currentElement : directTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!curvedTrackList.empty() && found == false)
    {
        for (std::shared_ptr<CurvedTrack>& currentElement : curvedTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!linkedTrackList.empty() && found == false)
    {
        for (std::shared_ptr<LinkedTrack>& currentElement : linkedTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!exitTrackList.empty() && found == false)
    {
        for (std::shared_ptr<ExitTrack>& currentElement : exitTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!bufferTrackList.empty() && found == false)
    {
        for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!signalTrackList.empty() && found == false)
    {
        for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!bridgeUnderpassTrackList.empty() && found == false)
    {
        for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!switchTrackList.empty() && found == false)
    {
        for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }
    if (!crossoverTrackList.empty() && found == false)
    {
        for (std::shared_ptr<CrossoverTrack>& currentElement : crossoverTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!flyoverTrackList.empty() && found == false)
    {
        for (std::shared_ptr<FlyoverTrack>& currentElement : flyoverTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!namedLocationList.empty() && found == false)
    {
        for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }

    if (!concourseList.empty() && found == false)
    {
        for (std::shared_ptr<Concourse>& currentElement : concourseList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }
    if (!parapetList.empty() && found == false)
    {
        for (std::shared_ptr<Parapet>& currentElement : parapetList)
        {
			int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                found = true;
            }
        }
    }
    return found;
}

bool Map::checkTextExists(int locationX, int locationY)
{
    bool found = false;
    if (!textList.empty())
    {
        for (std::shared_ptr<Text>& currentText : textList)
        {
            int textCurrentX = currentText->getLocationX();
            int textCurrentY = currentText->getLocationY();
            int textEditableX = currentText->getEditableX();
            int textEditableY = currentText->getEditableY();
            if (locationX >= textCurrentX && locationX <=textEditableX)
            {
                if (locationY >= textCurrentY && locationY <= textEditableY)
                {
                found = true;
                }
            }
        }
    }
    return found;
}

bool Map::deleteElement(int locationX, int locationY)
{
    bool deleted = false;
    std::shared_ptr<Track> currentTrack = getTrackAt(locationX, locationY);
    std::shared_ptr<Concourse> currentConcourse = getConcourseAt(locationX, locationY);
    std::shared_ptr<NamedLocation> currentNamedLocation = getNamedLocationAt(locationX, locationY);
    std::shared_ptr<Text> textToDelete = nullptr;
    if (currentTrack != nullptr)
    {
        textToDelete = currentTrack->getText();
        deleteTextFromAllElement(textToDelete);
    }
    else if (currentConcourse != nullptr)
    {
        textToDelete = currentConcourse->getText();
        deleteTextFromAllElement(textToDelete);
    }
    else if (currentNamedLocation != nullptr)
    {
        textToDelete = currentNamedLocation->getText();
        deleteTextFromAllElement(textToDelete);
    }
    if (textToDelete != nullptr)
    {
        for (int j=0; j< textList.size();j++)
        {
            if (textToDelete == textList[j])
            {
                textList.erase(textList.begin() + j);
            }
        }
    }
    for (int i = 0; i < straightTrackList.size(); i++)
    {
        std::shared_ptr<StraightTrack>& currentElement = straightTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY)
        {
            straightTrackList.erase(straightTrackList.begin() + i);
            deleted = true;
            --totalTrack;
            break;
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < directTrackList.size(); i++)
        {
            std::shared_ptr<DirectTrack>& currentElement = directTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                directTrackList.erase(directTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted) {
        for (int i = 0; i < curvedTrackList.size(); i++)
        {
            std::shared_ptr<CurvedTrack>& currentElement = curvedTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                curvedTrackList.erase(curvedTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < linkedTrackList.size(); i++)
        {
            std::shared_ptr<LinkedTrack>& currentElement = linkedTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                if (currentElement->getLinked())
                {
                    std::shared_ptr<LinkedTrack> temp = currentElement->getOtherLinkTrack();
                    temp->setLinked(false);
                    std::shared_ptr<LinkedTrack> empty = nullptr;
                    temp->setOtherLinkTrack(empty);
                }
                linkedTrackList.erase(linkedTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < exitTrackList.size(); i++)
        {
            std::shared_ptr<ExitTrack>& currentElement = exitTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                exitTrackList.erase(exitTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }

        }
    }
    if (!deleted)
    {
        for (int i = 0; i < bufferTrackList.size(); i++)
        {
            std::shared_ptr<BufferTrack>& currentElement = bufferTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                bufferTrackList.erase(bufferTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < signalTrackList.size(); i++)
        {
            std::shared_ptr<SignalTrack>& currentElement = signalTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                signalTrackList.erase(signalTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < bridgeUnderpassTrackList.size(); i++)
        {
            std::shared_ptr<BridgeUnderpassTrack>& currentElement = bridgeUnderpassTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                bridgeUnderpassTrackList.erase(bridgeUnderpassTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < switchTrackList.size(); i++)
        {
            std::shared_ptr<SwitchTrack>& currentElement = switchTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switchTrackList.erase(switchTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < crossoverTrackList.size(); i++)
        {
            std::shared_ptr<CrossoverTrack>& currentElement = crossoverTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY ==     locationY)
            {
                crossoverTrackList.erase(crossoverTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < flyoverTrackList.size(); i++)
        {
            std::shared_ptr<FlyoverTrack>& currentElement = flyoverTrackList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                flyoverTrackList.erase(flyoverTrackList.begin() + i);
                deleted = true;
                --totalTrack;
                break;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < namedLocationList.size(); i++)
        {
            std::shared_ptr<NamedLocation>& currentElement = namedLocationList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                namedLocationList.erase(namedLocationList.begin() + i);
                deleted = true;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < concourseList.size(); i++)
        {
            std::shared_ptr<Concourse>& currentElement = concourseList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                concourseList.erase(concourseList.begin() + i);
                deleted = true;
            }
        }
    }
    if (!deleted)
    {
        for (int i = 0; i < parapetList.size(); i++)
        {
            std::shared_ptr<Parapet>& currentElement = parapetList[i];
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                parapetList.erase(parapetList.begin() + i);
                deleted = true;
            }
        }
    }
    return deleted;
}

bool Map::deleteText(std::shared_ptr<Text> textToDelete)
{
    bool deleted = false;
    for (int i = 0; i < textList.size(); i++)
    {
        std::shared_ptr<Text>& currentText = textList[i];
        if (currentText == textToDelete)
        {
            textList.erase(textList.begin() + i);
            deleted = true;
            break;
        }
    }
    return deleted;
}

void Map::deleteTextFromAllElement(std::shared_ptr<Text> textToDelete)
{
    for (int i = 0; i < straightTrackList.size(); i++)
    {
        std::shared_ptr<StraightTrack>& currentElement = straightTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < directTrackList.size(); i++)
    {
        std::shared_ptr<DirectTrack>& currentElement = directTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }

    for (int i = 0; i < curvedTrackList.size(); i++)
    {
        std::shared_ptr<CurvedTrack>& currentElement = curvedTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < linkedTrackList.size(); i++)
    {
        std::shared_ptr<LinkedTrack>& currentElement = linkedTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }

    for (int i = 0; i < exitTrackList.size(); i++)
    {
        std::shared_ptr<ExitTrack>& currentElement = exitTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            currentElement->getText().reset();
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < bufferTrackList.size(); i++)
    {
        std::shared_ptr<BufferTrack>& currentElement = bufferTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < signalTrackList.size(); i++)
    {
        std::shared_ptr<SignalTrack>& currentElement = signalTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < bridgeUnderpassTrackList.size(); i++)
    {
        std::shared_ptr<BridgeUnderpassTrack>& currentElement = bridgeUnderpassTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < switchTrackList.size(); i++)
    {
        std::shared_ptr<SwitchTrack>& currentElement = switchTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < crossoverTrackList.size(); i++)
    {
        std::shared_ptr<CrossoverTrack>& currentElement = crossoverTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < flyoverTrackList.size(); i++)
    {
        std::shared_ptr<FlyoverTrack>& currentElement = flyoverTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < namedLocationList.size(); i++)
    {
        std::shared_ptr<NamedLocation>& currentElement = namedLocationList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < concourseList.size(); i++)
    {
        std::shared_ptr<Concourse>& currentElement = concourseList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
    for (int i = 0; i < parapetList.size(); i++)
    {
        std::shared_ptr<FlyoverTrack>& currentElement = flyoverTrackList[i];
        if (currentElement->getText() == textToDelete)
        {
            std::shared_ptr<Text> empty;
            currentElement->setText(empty);
            currentElement->setNamed(false);
        }
    }
}

void Map::addPlatform(Platform side, int locationX, int locationY)
{
    bool added = false;
    if (!straightTrackList.empty() && added == false)
    {
        for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            bool levelCrossing = currentElement->hasLevelCrossing();
            if (currentX == locationX && currentY == locationY)
            {
                if (!levelCrossing)
                {
                    switch (side)
                    {
                        case Platform::UP:
                        {
                            if (currentElement->getStraightType() == StraightType::STRAIGHTH)
                            {
                                currentElement->setPlatform1(true);
                                added = true;
                            }
                            break;
                        }
                        case Platform::DOWN:
                        {
                            if (currentElement->getStraightType() == StraightType::STRAIGHTH)
                            {
                                currentElement->setPlatform2(true);
                                added = true;
                            }
                            break;
                        }
                        case Platform::LEFT:
                        {
                            if (currentElement->getStraightType() == StraightType::STRAIGHTV)
                            {
                                currentElement->setPlatform1(true);
                                added = true;
                            }
                            break;
                        }
                        case Platform::RIGHT:
                        {
                            if (currentElement->getStraightType() == StraightType::STRAIGHTV)
                            {
                                currentElement->setPlatform2(true);
                                added = true;
                            }
                            break;
                        }
                    }
                }
                if (added)
                {
                    currentElement->setPlatformAny(true);
                }
            }
        }
    }
    if (!directTrackList.empty() && added == false)
    {
        for (std::shared_ptr<DirectTrack>& currentElement : directTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switch (side)
                {
                    case Platform::LEFT:
                    {
                        if (currentElement->getDirectType() == DirectType::DIRECTUP)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getDirectType() == DirectType::DIRECTDOWN)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::RIGHT:
                    {
                        if (currentElement->getDirectType() == DirectType::DIRECTUP)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getDirectType() == DirectType::DIRECTDOWN)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::UP:
                    {
                        if (currentElement->getDirectType() == DirectType::DIRECTLEFT)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getDirectType() == DirectType::DIRECTRIGHT)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::DOWN:
                    {
                        if (currentElement->getDirectType() == DirectType::DIRECTLEFT)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getDirectType() == DirectType::DIRECTRIGHT)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    default:
                    {
                        added = false;
                        break;
                    }
                }
            }
            if (added)
            {
                currentElement->setPlatformAny(true);
            }
        }
    }
    if (!bufferTrackList.empty() && added == false)
    {
        for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switch (side)
                {
                    case Platform::LEFT:
                    {
                        if (currentElement->getBufferType() == BufferType::BUFFERUP)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getBufferType() == BufferType::BUFFERDOWN)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::RIGHT:
                    {
                        if (currentElement->getBufferType() == BufferType::BUFFERUP)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getBufferType() == BufferType::BUFFERDOWN)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::UP:
                    {
                        if (currentElement->getBufferType() == BufferType::BUFFERLEFT)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getBufferType() == BufferType::BUFFERRIGHT)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::DOWN:
                    {
                        if (currentElement->getBufferType() == BufferType::BUFFERLEFT)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getBufferType() == BufferType::BUFFERRIGHT)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    default:
                    {
                        added = false;
                    }
                }
            }
            if (added)
            {
                currentElement->setPlatformAny(true);
            }
	}
    }
    if (!signalTrackList.empty() && added == false)
    {
        for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switch (side)
                {
                    case Platform::LEFT:
                    {
                        if (currentElement->getSignalType() == SignalType::SIGNALUP)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getSignalType() == SignalType::SIGNALDOWN)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::RIGHT:
                    {
                        if (currentElement->getSignalType() == SignalType::SIGNALUP)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getSignalType() == SignalType::SIGNALDOWN)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::UP:
                    {
                        if (currentElement->getSignalType() == SignalType::SIGNALLEFT)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getSignalType() == SignalType::SIGNALRIGHT)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::DOWN:
                    {
                        if (currentElement->getSignalType() == SignalType::SIGNALLEFT)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getSignalType() == SignalType::SIGNALRIGHT)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    default:
                    {
                        added = false;
                    }
                }
            }
            if (added)
            {
                currentElement->setPlatformAny(true);
            }
	}
    }
    if (!bridgeUnderpassTrackList.empty() && added == false)
    {
        for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switch (side)
                {
                    case Platform::LEFT:
                    {
                        if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE2)
                        {
                           currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS2)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::RIGHT:
                    {
                        if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE2)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS2)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::UP:
                    {
                        if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE1)
                        {
                            currentElement->setPlatform1(true);
                        }
                        else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS1)
                        {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    }
                    case Platform::DOWN:
                    {
                        if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::BRIDGE1)
                        {
                            currentElement->setPlatform2(true);
                        }
                        else if (currentElement->getBridgeUnderpassType() == BridgeUnderpassType::UNDERPASS1)
                        {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    }
                    default:
                    {
                        added = false;
                    }
                }
            }
            if (added)
            {
                currentElement->setPlatformAny(true);
            }
        }
    }
    if (!switchTrackList.empty() && added == false)
    {
        for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList)
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentX == locationX && currentY == locationY)
            {
                switch (currentElement->getSwitchType())
                {
                    case SwitchType::SWITCHTIGHT1:
                    case SwitchType::SWITCHTIGHT2:
                    case SwitchType::SWITCH1:
                    case SwitchType::SWITCH2:
                    {
                        if (side == Platform::DOWN)
                        {
                            currentElement->setPlatform2(true);
                            added = true;
                        }
                        break;
                    }
                    case SwitchType::SWITCHTIGHT3:
                    case SwitchType::SWITCHTIGHT4:
                    case SwitchType::SWITCH3:
                    case SwitchType::SWITCH4:
                    {
                        if (side == Platform::UP)
                        {
                            currentElement->setPlatform1(true);
                            added = true;
                        }
                        break;
                    }
                    case SwitchType::SWITCHTIGHT5:
                    case SwitchType::SWITCHTIGHT7:
                    case SwitchType::SWITCH5:
                    case SwitchType::SWITCH7:
                    {
                        if (side == Platform::RIGHT)
                        {
                            currentElement->setPlatform2(true);
                            added = true;
                        }
                        break;
                    }
                    case SwitchType::SWITCHTIGHT6:
                    case SwitchType::SWITCHTIGHT8:
                    case SwitchType::SWITCH6:
                    case SwitchType::SWITCH8:
                    {
                        if (side == Platform::LEFT)
                        {
                            currentElement->setPlatform1(true);
                            added = true;
                        }
                        break;
                    }
                    case SwitchType::SWITCHSPLIT1:
                    case SwitchType::SWITCHSPLIT2:
                    case SwitchType::SWITCHSPLIT3:
                    case SwitchType::SWITCHSPLIT4:
                    case SwitchType::SWITCHSPLIT5:
                    case SwitchType::SWITCHSPLIT6:
                    case SwitchType::SWITCHSPLIT7:
                    case SwitchType::SWITCHSPLIT8:
                    case SwitchType::SWITCH9:
                    case SwitchType::SWITCH10:
                    case SwitchType::SWITCH11:
                    case SwitchType::SWITCH12:
                    case SwitchType::SWITCH13:
                    case SwitchType::SWITCH14:
                    case SwitchType::SWITCH15:
                    case SwitchType::SWITCH16:
                    {
                        break;
                    }
                }
            }
            if (added)
            {
                currentElement->setPlatformAny(true);
            }
        }
    }
}

void Map::addLevelCrossing(int locationX, int locationY)
{
    for (int i = 0; i < straightTrackList.size(); i++)
    {
        std::shared_ptr<StraightTrack>& currentElement = straightTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        bool platform1 = currentElement->getPlatform1();
        bool platform2 = currentElement->getPlatform2();
        if (currentX == locationX && currentY == locationY)
        {
            if (!platform1 && !platform2)
            {
                currentElement->addLevelCrossing();
            }
        }
    }
}

void Map::linkLocalText(int locationX, int locationY, std::shared_ptr<Text> linkedText)
{
    if (checkElementExists(locationX, locationY))
    {
        //Get whatever is at that location
        std::shared_ptr<Track> track = getTrackAt(locationX,locationY);
        std::shared_ptr<Concourse> concourse = getConcourseAt(locationX, locationY);
        std::shared_ptr<NamedLocation> namedLocation = getNamedLocationAt(locationX, locationY);
        //link text to it
        if (track != nullptr)
        {
            if (track->getPlatformAny())
            {
                track->setText(linkedText);
                track->setNamed(true);
            }
        }
        if (concourse != nullptr)
        {
            if (!concourse->getNamed())
            {
                concourse->setText(linkedText);
                concourse->setNamed(true);
            }
        }
        if (namedLocation != nullptr)
        {
            if (!namedLocation->getNamed())
            {
                namedLocation->setText(linkedText);
                namedLocation->setNamed(true);
            }
        }
        if (track != nullptr || concourse != nullptr)
        {
            //See if there's a track above it
            if (checkElementExists(locationX, locationY+16))
            {
                std::shared_ptr<Track> trackTempYP16 = getTrackAt(locationX,locationY+16);
                std::shared_ptr<Concourse> concourseTempYP16 = getConcourseAt(locationX,locationY+16);
                //Try link the track to text if it has a platform.
                //Try link if the the element isn't named yet.
                if (trackTempYP16 != nullptr)
                {
                    if (trackTempYP16->getPlatformAny())
                    {
                        if (!trackTempYP16->getNamed())
                        {
                        //Link it if there's a track there and it hasn't been named
                        linkLocalText(locationX, locationY+16, linkedText);
                        }
                    }
                }
                else if (concourseTempYP16 != nullptr)
                {
                    if (!concourseTempYP16->getNamed())
                    {
                        linkLocalText(locationX, locationY+16, linkedText);
                    }
                }
            }
            //See if there's a track underneath
            if (checkElementExists(locationX, locationY-16))
            {
                std::shared_ptr<Track> trackTempYM16 = getTrackAt(locationX,locationY-16);
                std::shared_ptr<Concourse> concourseTempYM16 = getConcourseAt(locationX,locationY-16);

                if (trackTempYM16 != nullptr)
                {
                    if (trackTempYM16->getPlatformAny())
                    {
                        if (!trackTempYM16->getNamed())
                        {
                        linkLocalText(locationX, locationY-16, linkedText);
                        }
                    }
                }
                else if (concourseTempYM16 != nullptr)
                {
                    if (!concourseTempYM16->getNamed())
                    {
                        linkLocalText(locationX, locationY-16, linkedText);
                    }
                }
            }
            //See if there's a track on the right of it
            if (checkElementExists(locationX+16, locationY))
            {
                std::shared_ptr<Track> trackTempXP16 = getTrackAt(locationX+16,locationY);
                std::shared_ptr<Concourse> concourseTempXP16 = getConcourseAt(locationX+16,locationY);

                if (trackTempXP16 != nullptr)
                {
                    if (trackTempXP16->getPlatformAny())
                    {
                        if (!trackTempXP16->getNamed())
                        {
                        linkLocalText(locationX+16, locationY, linkedText);
                        }
                    }
                }
                else if (concourseTempXP16 != nullptr)
                {
                    if (!concourseTempXP16->getNamed())
                    {
                        linkLocalText(locationX+16, locationY, linkedText);
                    }
                }
            }
            //See if there's a track on the left of it
            if (checkElementExists(locationX-16, locationY))
            {
                std::shared_ptr<Track> trackTempXM16 = getTrackAt(locationX-16,locationY);
                std::shared_ptr<Concourse> concourseTempXM16 = getConcourseAt(locationX-16,locationY);
                if (trackTempXM16 != nullptr)
                {
                    if (trackTempXM16->getPlatformAny())
                    {
                        if (!trackTempXM16->getNamed())
                        {
                        linkLocalText(locationX-16, locationY, linkedText);
                        }
                    }
                }
                else if (concourseTempXM16 != nullptr)
                {
                    if (!concourseTempXM16->getNamed())
                    {
                        linkLocalText(locationX-16, locationY, linkedText);
                    }
                }
            }
        }
        //Same for namedLocation.
        else
        {
            if (checkElementExists(locationX, locationY+16))
            {
                std::shared_ptr<NamedLocation> namedLocationTempYP16 = getNamedLocationAt(locationX,locationY+16);
                if (namedLocationTempYP16 != nullptr)
                {
                    if (!namedLocationTempYP16->getNamed())
                    {
                        linkLocalText(locationX, locationY+16, linkedText);
                    }
                }
            }
            if (checkElementExists(locationX, locationY-16))
            {
                std::shared_ptr<NamedLocation> namedLocationYM16 = getNamedLocationAt(locationX,locationY-16);

                if (namedLocationYM16 != nullptr)
                {
                    if (!namedLocationYM16->getNamed())
                    {
                        linkLocalText(locationX, locationY-16, linkedText);
                    }
                }
            }
            if (checkElementExists(locationX+16, locationY))
            {
                std::shared_ptr<NamedLocation> namedLocationXP16 = getNamedLocationAt(locationX+16,locationY);
                if (namedLocationXP16 != nullptr)
                {
                    if (!namedLocationXP16->getNamed())
                    {
                        linkLocalText(locationX+16, locationY, linkedText);
                    }
                }
            }
            if (checkElementExists(locationX-16, locationY))
            {
                std::shared_ptr<NamedLocation> namedLocationTempXM16 = getNamedLocationAt(locationX-16,locationY);
                if (namedLocationTempXM16 != nullptr)
                {
                    if (!namedLocationTempXM16->getNamed())
                    {
                        linkLocalText(locationX-16, locationY, linkedText);
                    }
                }
            }
        }
    }
}

void Map::linkNewBlockToText(int locationX, int     locationY)
{
    //Get what's there currently
    std::shared_ptr<Track> track = getTrackAt(locationX,locationY);
    std::shared_ptr<Concourse> concourse = getConcourseAt(locationX, locationY);
    std::shared_ptr<NamedLocation> namedLocation = getNamedLocationAt(locationX, locationY);
    std::shared_ptr<Text> textToLink = nullptr;

    //Get what's above the current Element
    std::shared_ptr<NamedLocation> namedLocationTempYP16 = getNamedLocationAt(locationX,locationY+16);
    std::shared_ptr<Track> trackTempYP16 = getTrackAt(locationX,locationY+16);
    std::shared_ptr<Concourse> concourseTempYP16 = getConcourseAt(locationX,locationY+16);
    std::shared_ptr<Text> textTempYP16 = nullptr;
    //Get the text that occupies that location
    if (namedLocationTempYP16 != nullptr)
    {
        if (namedLocationTempYP16->getNamed())
        {
            textTempYP16 = namedLocationTempYP16->getText();

        }
    }
    else if (trackTempYP16 != nullptr)
    {
        if (trackTempYP16->getNamed())
        {
            textTempYP16 = trackTempYP16->getText();
        }
    }
    else if (concourseTempYP16 != nullptr)
    {
        if (concourseTempYP16->getNamed())
        {
            textTempYP16 = concourseTempYP16->getText();
        }
    }
    //Get the surrounding track/elements if they exist
    //Get what's below the current Element
    std::shared_ptr<NamedLocation> namedLocationTempYM16 = getNamedLocationAt(locationX,locationY-16);
    std::shared_ptr<Track> trackTempYM16 = getTrackAt(locationX,locationY-16);
    std::shared_ptr<Concourse> concourseTempYM16 = getConcourseAt(locationX,locationY-16);
    std::shared_ptr<Text> textTempYM16 = nullptr;
    if (namedLocationTempYM16 != nullptr)
    {
        if (namedLocationTempYM16->getNamed())
        {
            textTempYM16 = namedLocationTempYM16->getText();

        }
    }
    else if (trackTempYM16 != nullptr)
    {
        if (trackTempYM16->getNamed())
        {
            textTempYM16 = trackTempYM16->getText();
        }
    }
    else if (concourseTempYM16 != nullptr)
    {
        if (concourseTempYM16->getNamed())
        {
            textTempYM16 = concourseTempYM16->getText();
        }
    }
    //Get what's right of the current element
    std::shared_ptr<NamedLocation> namedLocationTempXP16 = getNamedLocationAt(locationX+16,locationY);
    std::shared_ptr<Track> trackTempXP16 = getTrackAt(locationX+16,locationY);
    std::shared_ptr<Concourse> concourseTempXP16 = getConcourseAt(locationX+16,locationY);
    std::shared_ptr<Text> textTempXP16 = nullptr;

    if (namedLocationTempXP16 != nullptr)
    {
        if (namedLocationTempXP16->getNamed())
        {
            textTempXP16 = namedLocationTempXP16->getText();

        }
    }
    else if (trackTempXP16 != nullptr)
    {
        if (trackTempXP16->getNamed())
        {
            textTempXP16 = trackTempXP16->getText();
        }
    }
    else if (concourseTempXP16 != nullptr)
    {
        if (concourseTempXP16->getNamed())
        {
            textTempXP16 = concourseTempXP16->getText();
        }
    }
    //Get what's left of the current element
    std::shared_ptr<NamedLocation> namedLocationTempXM16 = getNamedLocationAt(locationX-16,locationY);
    std::shared_ptr<Track> trackTempXM16 = getTrackAt(locationX-16,locationY);
    std::shared_ptr<Concourse> concourseTempXM16 = getConcourseAt(locationX-16,locationY);
    std::shared_ptr<Text> textTempXM16 = nullptr;

    if (namedLocationTempXM16 != nullptr)
    {
        if (namedLocationTempXM16->getNamed())
        {
            textTempXM16 = namedLocationTempXM16->getText();

        }
    }
    else if (trackTempXM16 != nullptr)
    {
        if (trackTempXM16->getNamed())
        {
            textTempXM16 = trackTempXM16->getText();
        }
    }
    else if (concourseTempXM16 != nullptr)
    {
        if (concourseTempXM16->getNamed())
        {
            textTempXM16 = concourseTempXM16->getText();
        }
    }
    //Add it to a list of surrounding elements.
    std::vector<std::shared_ptr<Text>> surroundTextList;
    std::vector<std::shared_ptr<Text>> toDeleteTextList;
    if (textTempYP16 != nullptr)
    {
        surroundTextList.push_back(textTempYP16);
    }
    if (textTempYM16 != nullptr)
    {
        surroundTextList.push_back(textTempYM16);
    }
    if (textTempXP16 != nullptr)
    {
        surroundTextList.push_back(textTempXP16);
    }
    if (textTempXM16 != nullptr)
    {
        surroundTextList.push_back(textTempXM16);
    }
    //Add to delete list if more than 1 text
    if (surroundTextList.size() >1)
    {
        for (int i = 0; i < surroundTextList.size(); i++)
        {
            std::shared_ptr<Text>& currentText = surroundTextList[0];
            std::shared_ptr<Text>& currentText1 = surroundTextList[i];
            if (currentText != currentText1)
            {
                toDeleteTextList.push_back(currentText1);
            }
        }
    }
    //Delete that Text from all elements, then delete all trace of it
    if (toDeleteTextList.size() >0)
    {
        for (int i = 0; i < toDeleteTextList.size(); i++)
        {
            deleteTextFromAllElement(toDeleteTextList[i]);
            for (int j=0; j< textList.size();j++)
            {
                if (toDeleteTextList[i] == textList[j])
                {
                    textList.erase(textList.begin() + j);
                }
            }
        }
        toDeleteTextList.clear();

    }

    bool redNamed = false;
    if (namedLocation != nullptr)
    {
        if (checkElementExists(locationX, locationY+16))
        {
            //Get what exists above it, and set the textToLink to the same text
            namedLocationTempYP16 = getNamedLocationAt(locationX,locationY+16);
            if (namedLocationTempYP16 != nullptr)
            {
                if (namedLocationTempYP16->getNamed())
                {
                    textToLink = namedLocationTempYP16->getText();
                }
            }
        }
        if (checkElementExists(locationX, locationY-16))
        {
            //Get what exists below it, and set the textToLink to the same text
            namedLocationTempYM16 = getNamedLocationAt(locationX,locationY-16);
            if (namedLocationTempYM16 != nullptr)
            {
                if (namedLocationTempYM16->getNamed())
                {
                    textToLink = namedLocationTempYM16->getText();
                }
            }
        }
        if (checkElementExists(locationX+16, locationY))
        {
            //Get what exists below it, and set the textToLink to the same text
            namedLocationTempXP16 = getNamedLocationAt(locationX+16,locationY);
            if (namedLocationTempXP16 != nullptr)
            {
                if (namedLocationTempXP16->getNamed())
                {
                    textToLink = namedLocationTempXP16->getText();
                }
            }
        }
        if (checkElementExists(locationX-16, locationY))
        {
            //Get what exists on the left of it, and set the textToLink to the same text
            namedLocationTempXM16 = getNamedLocationAt(locationX-16,locationY);
            if (namedLocationTempXM16 != nullptr)
            {
                if (namedLocationTempXM16->getNamed())
                {
                    textToLink = namedLocationTempXM16->getText();
                }
            }
        }
        //If it is a namedlocation, and there is text around it, set it, and do it for surrounding namedLocations
        if (namedLocation != nullptr && textToLink != nullptr)
        {
            namedLocation->setText(textToLink);
            namedLocation->setNamed(true);
            //Recursive bit
            if (checkElementExists(locationX, locationY+16))
            {
                namedLocationTempYP16 = getNamedLocationAt(locationX,locationY+16);
                if (namedLocationTempYP16 != nullptr)
                {
                    if (!namedLocationTempYP16->getNamed())
                    {
                        linkLocalText(locationX,locationY+16,textToLink);
                    }
                }
            }
            if (checkElementExists(locationX, locationY-16))
            {
                namedLocationTempYM16 = getNamedLocationAt(locationX,locationY-16);
                if (namedLocationTempYM16 != nullptr)
                {
                    if (!namedLocationTempYM16->getNamed())
                    {
                        linkLocalText(locationX,locationY-16,textToLink);
                    }
                }
            }
            if (checkElementExists(locationX+16, locationY))
            {
                namedLocationTempXP16 = getNamedLocationAt(locationX+16,locationY);
                if (namedLocationTempXP16 != nullptr)
                {
                    if (!namedLocationTempXP16->getNamed())
                    {
                        linkLocalText(locationX+16,locationY,textToLink);
                    }
                }
            }
            if (checkElementExists(locationX-16, locationY))
            {
                namedLocationTempXM16 = getNamedLocationAt(locationX-16,locationY);
                if (namedLocationTempXM16 != nullptr)
                {
                    if (!namedLocationTempXM16->getNamed())
                    {
                        linkLocalText(locationX-16,locationY,textToLink);
                    }
                }
            }
        }
    }
    //If it is a track or concourse, and there is text around it, set it, and do it for surrounding them too
    else
    {
        if (checkElementExists(locationX, locationY+16))
        {
            trackTempYP16 = getTrackAt(locationX,locationY+16);
            concourseTempYP16 = getConcourseAt(locationX,locationY+16);
            if (trackTempYP16 != nullptr)
            {
                if (trackTempYP16->getNamed())
                {
                    textToLink = trackTempYP16->getText();
                }
            }
            else
            {
                if (concourseTempYP16->getNamed())
                {
                    textToLink = concourseTempYP16->getText();
                }

            }
        }
        if (checkElementExists(locationX, locationY-16))
        {
            trackTempYM16 = getTrackAt(locationX,locationY-16);
            concourseTempYM16 = getConcourseAt(locationX,locationY-16);
            if (trackTempYM16 != nullptr)
            {
                if (trackTempYM16->getNamed())
                {
                    textToLink = trackTempYM16->getText();
                }
            }
            else
            {
                if (concourseTempYM16->getNamed())
                {
                    textToLink = concourseTempYM16->getText();
                }
            }

        }
        if (checkElementExists(locationX+16, locationY))
        {
            trackTempXP16 = getTrackAt(locationX+16,locationY);
            concourseTempXP16 = getConcourseAt(locationX+16,locationY);
            if (trackTempXP16 != nullptr)
            {
                if (trackTempXP16->getNamed())
                {
                    textToLink = trackTempXP16->getText();
                }
            }
            else
            {
                if (concourseTempXP16->getNamed())
                {
                    textToLink = concourseTempXP16->getText();
                }
            }

        }
        if (checkElementExists(locationX-16, locationY))
        {
            trackTempXM16 = getTrackAt(locationX-16,locationY);
            concourseTempXM16 = getConcourseAt(locationX-16,locationY);
            if (trackTempXM16 != nullptr)
            {
                if (trackTempXM16->getNamed())
                {
                    textToLink = trackTempXM16->getText();
                }
            }
            else
            {
                if (concourseTempXM16->getNamed())
                {
                    textToLink = concourseTempXM16->getText();
                }
            }

        }
        //Set the track or concourse to the text
        if (track != nullptr && textToLink != nullptr)
        {
            track->setText(textToLink);
            track->setNamed(true);
            redNamed = true;
        }
        else if (concourse != nullptr && textToLink != nullptr)
        {
            concourse->setText(textToLink);
            concourse->setNamed(true);
            redNamed = true;
        }

        if (redNamed)
        {
            //Recursive bit
            if (checkElementExists(locationX, locationY+16))
            {
                trackTempYP16 = getTrackAt(locationX,locationY+16);
                concourseTempYP16 = getConcourseAt(locationX,locationY+16);
                if (trackTempYP16 != nullptr)
                {
                    if (!trackTempYP16->getNamed())
                    {
                        linkLocalText(locationX,locationY+16, textToLink);
                    }
                }
                else
                {
                    if (!concourseTempYP16->getNamed())
                    {
                        linkLocalText(locationX,locationY+16, textToLink);
                    }

                }
            }
            if (checkElementExists(locationX, locationY-16))
            {
                trackTempYM16 = getTrackAt(locationX,locationY-16);
                concourseTempYM16 = getConcourseAt(locationX,locationY-16);
                if (trackTempYM16 != nullptr)
                {
                    if (!trackTempYM16->getNamed())
                    {
                        linkLocalText(locationX,locationY-16, textToLink);
                    }
                }
                else
                {
                    if (!concourseTempYM16->getNamed())
                    {
                        linkLocalText(locationX,locationY-16, textToLink);
                    }
                }

            }
            if (checkElementExists(locationX-16, locationY))
            {
                trackTempXM16 = getTrackAt(locationX-16,locationY);
                concourseTempXM16 = getConcourseAt(locationX-16,locationY);
                if (trackTempXM16 != nullptr)
                {
                    if (!trackTempXM16->getNamed())
                    {
                        linkLocalText(locationX-16,locationY, textToLink);
                    }
                }
                else
                {
                    if (!concourseTempXM16->getNamed())
                    {
                        linkLocalText(locationX-16,locationY, textToLink);
                    }
                }
            }
            if (checkElementExists(locationX+16, locationY))
            {
                trackTempXP16 = getTrackAt(locationX+16,locationY);
                concourseTempXP16 = getConcourseAt(locationX+16,locationY);
                if (trackTempXP16 != nullptr)
                {
                    if (!trackTempXP16->getNamed())
                    {
                        linkLocalText(locationX+16,locationY, textToLink);
                    }
                }
                else
                {
                    if (!concourseTempXP16->getNamed())
                    {
                        linkLocalText(locationX+16,locationY, textToLink);
                    }
                }
            }
        }
    }
}




std::shared_ptr<LinkedTrack> Map::getLinkedTrack1() const
{
    return linkedTrack1;
}

void Map::setLinkedTrack1(const std::shared_ptr<LinkedTrack> &value)
{
    linkedTrack1 = value;
}

std::shared_ptr<LinkedTrack> Map::getLinkedTrack2() const
{
    return linkedTrack2;
}

void Map::setLinkedTrack2(const std::shared_ptr<LinkedTrack> &value)
{
    linkedTrack2 = value;
}

void Map::connectLinkedTrack()
{
    linkedTrack1->setOtherLinkTrack(linkedTrack2);
    linkedTrack2->setOtherLinkTrack(linkedTrack1);
    linkedTrack1->setLinked(true);
    linkedTrack2->setLinked(true);
    linkedTrack1 = nullptr;
    linkedTrack2 = nullptr;
}

void Map::checkAllLinkTrackLinked()
{
    allLinkedTrackLinked = true;
    if (linkedTrackList.size() % 2 ==0)
    {
        for (std::shared_ptr<LinkedTrack> linkedTrack: linkedTrackList)
        {
            if (!linkedTrack->getLinked())
            {
                allLinkedTrackLinked = false;
                break;
            }
        }
    }
}






std::vector<std::shared_ptr<Track> > Map::makeTrackList()
{
    std::vector<std::shared_ptr<Track>> tempTrackList;
    if (!straightTrackList.empty())
    {
        for (std::shared_ptr<Track> track : straightTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!directTrackList.empty())
    {
        for (std::shared_ptr<Track> track : directTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!curvedTrackList.empty())
    {
        for (std::shared_ptr<Track> track : curvedTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!linkedTrackList.empty())
    {
        for (std::shared_ptr<Track> track : linkedTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!exitTrackList.empty())
    {
        for (std::shared_ptr<Track> track : exitTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!bufferTrackList.empty())
    {
        for (std::shared_ptr<Track> track : bufferTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!signalTrackList.empty())
    {
        for (std::shared_ptr<Track> track : signalTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!bridgeUnderpassTrackList.empty())
    {
        for (std::shared_ptr<Track> track : bridgeUnderpassTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!switchTrackList.empty())
    {
        for (std::shared_ptr<Track> track : switchTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!crossoverTrackList.empty())
    {
        for (std::shared_ptr<Track> track : crossoverTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    if (!flyoverTrackList.empty())
    {
        for (std::shared_ptr<Track> track : flyoverTrackList)
        {
            tempTrackList.push_back(track);
        }
    }
    return tempTrackList;
}

std::shared_ptr<Track> Map::findTopLeftTrack()
{
    std::shared_ptr<Track> track = nullptr;
    std::vector<std::shared_ptr<Track>> tempTrackList = makeTrackList();
    if (!tempTrackList.empty())
    {
        track = tempTrackList[0];
        for (std::shared_ptr<Track> currentTrack: tempTrackList)
        {
            if (currentTrack->getLocationX() < track->getLocationX())
            {
                if (currentTrack->getLocationY() > track->getLocationY())
                {
                    track = currentTrack;
                }
            }
        }
    }
    return track;
}

void Map::checkAllTracks()
{
    std::shared_ptr<Track> startTrack = findTopLeftTrack();
    trackList = makeTrackList();
    allConnected = true;
    checkAllLinkTrackLinked();
    for (std::shared_ptr<Track> currentTrack : trackList)
    {
        int centreTrackX = currentTrack->getLocationX();
        int centreTrackY = currentTrack->getLocationY();
        if (currentTrack->getLink0())
        {
            std::shared_ptr<Track> leftUpTrack = getTrackAt(centreTrackX-16, centreTrackY+16);
            if (leftUpTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink1() && allConnected)
        {
            std::shared_ptr<Track> upTrack = getTrackAt(centreTrackX, centreTrackY+16);
            if (upTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink2() && allConnected)
        {
            std::shared_ptr<Track> rightUpTrack = getTrackAt(centreTrackX+16, centreTrackY+16);
            if (rightUpTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink3() && allConnected)
        {
            std::shared_ptr<Track> leftTrack = getTrackAt(centreTrackX-16, centreTrackY);
            if (leftTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink5() && allConnected)
        {
            std::shared_ptr<Track> rightTrack = getTrackAt(centreTrackX+16, centreTrackY);
            if (rightTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink6() && allConnected)
        {
            std::shared_ptr<Track> rightDownTrack = getTrackAt(centreTrackX-16, centreTrackY-16);
            if (rightDownTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink7() && allConnected)
        {
            std::shared_ptr<Track> downTrack = getTrackAt(centreTrackX, centreTrackY-16);
            if (downTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (currentTrack->getLink8() && allConnected)
        {
            std::shared_ptr<Track> rightDownTrack = getTrackAt(centreTrackX+16, centreTrackY-16);
            if (rightDownTrack == nullptr)
            {
                allConnected = false;
            }
        }
        if (!allConnected)
        {
            break;
        }

    }
    if (allConnected && allLinkedTrackLinked)
    {
        QMessageBox allConnectedBox;
        allConnectedBox.setText("All track connected");
        allConnectedBox.exec();
    }
    else
    {
        QMessageBox notConnectedBox;
        notConnectedBox.setText("Not all track connected");
        notConnectedBox.exec();
    }

}

bool Map::getAllLinkedTrackLinked() const
{
    return allLinkedTrackLinked;
}

void Map::setAllLinkedTrackLinked(bool newAllLinkedTrackLinked)
{
    allLinkedTrackLinked = newAllLinkedTrackLinked;
}

bool Map::getAllConnected() const
{
    return allConnected;
}

void Map::setAllConnected(bool newAllConnected)
{
    allConnected = newAllConnected;
}



std::shared_ptr<Track> Map::getStart() const
{
    return start;
}

void Map::setStart(const std::shared_ptr<Track> &newStart)
{
    start = newStart;
}

std::shared_ptr<Track> Map::getEnd() const
{
    return end;
}

void Map::setEnd(const std::shared_ptr<Track> &newEnd)
{
    end = newEnd;
}


std::vector<std::shared_ptr<Track> > Map::getSetTrackSpeedLengthList() const
{
    return setTrackSpeedLengthList;
}

void Map::setSetTrackSpeedLengthList(const std::vector<std::shared_ptr<Track> > &newSetTrackSpeedLengthList)
{
    setTrackSpeedLengthList = newSetTrackSpeedLengthList;
}

void Map::fillSetTrackSpeedLengthList(std::shared_ptr<Track> track)
{

    int currentX = track->getLocationX();
    int currentY = track->getLocationY();
    int destinationX = end->getLocationX();
    int destinationY = end->getLocationY();

    /*
     *
     *  -------
     *  |0|1|2|
     *  -------
     *  |3|4|5|
     *  -------
     *  |6|7|8|
     *  -------
     *
     */



    if (currentX != destinationX || currentY != destinationY)
    {
        if (currentX < destinationX  && currentY < destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }
            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }
            }
            else if (track->getLink1())
            {
                if (!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }
            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }

            }
            else if (track->getLink0())
            {
                if (!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }
            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }

            }
            else if (track->getLink7() )
            {
                if(!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }

            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }

            }


        }
        else if (currentX > destinationX && currentY > destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }
            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }
            }
            else if (track->getLink7())
            {
                if (!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }
            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }

            }
            else if (track->getLink0())
            {
                if (!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }
            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }

            }
            else if (track->getLink1() )
            {
                if(!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }

            }
            else if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }

            }

        }
        else if (currentX > destinationX && currentY < destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink0())
            {
                if (!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }
            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }
            }
            else if (track->getLink1())
            {
                if (!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }
            }
            else if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }

            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }
            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }

            }
            else if (track->getLink7() )
            {
                if(!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }

            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }

            }

        }
        else if (currentX < destinationX && currentY > destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }
            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }
            }
            else if (track->getLink7())
            {
                if (!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }
            }
            else if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }

            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }
            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }

            }
            else if (track->getLink1() )
            {
                if(!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }

            }
            else if (track->getLink0())
            {
                if (!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }

            }
        }
        else if (currentX == destinationX && currentY < destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink1())
            {
                if (!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }
            }
            else if (track->getLink0())
            {
                if (!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }
            }
            else if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }
            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }

            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }
            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }

            }
            else if (track->getLink7() )
            {
                if(!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }

            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }

            }

        }
        else if (currentX == destinationX && currentY > destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink7())
            {
                if (!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }
            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }
            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }
            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }

            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }
            }
            else if (track->getLink1())
            {
                if (!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }

            }
            else if (track->getLink0() )
            {
                if(!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }

            }
            else if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }

            }
        }
        else if (currentX < destinationX && currentY == destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }
            }
            else if (track->getLink2())
            {
                if (!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }
            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }
            }
            else if (track->getLink1())
            {
                if (!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }

            }
            else if (track->getLink7())
            {
                if (!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }
            }
            else if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }

            }
            else if (track->getLink0() )
            {
                if(!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }

            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }

            }
        }
        else if (currentX > destinationX && currentY == destinationY)
        {
            std::shared_ptr<Track> track0 = getTrackAt(currentX-16, currentY+16);
            std::shared_ptr<Track> track1 = getTrackAt(currentX, currentY+16);;
            std::shared_ptr<Track> track2 = getTrackAt(currentX+16, currentY+16);
            std::shared_ptr<Track> track3 = getTrackAt(currentX-16, currentY);
            std::shared_ptr<Track> track5 = getTrackAt(currentX+16, currentY);
            std::shared_ptr<Track> track6 = getTrackAt(currentX-16, currentY-16);
            std::shared_ptr<Track> track7 = getTrackAt(currentX, currentY-16);
            std::shared_ptr<Track> track8 = getTrackAt(currentX+16, currentY-16);

            if (track->getLink3())
            {
                if (!track3->getFound())
                {
                    setTrackSpeedLengthList.push_back(track3);
                    track3->setFound(true);
                    if (track3->getLocationX() != destinationX || track3->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track3);
                    }
                }
            }
            else if (track->getLink0())
            {
                if (!track0->getFound())
                {
                    setTrackSpeedLengthList.push_back(track0);
                    track0->setFound(true);
                    if (track0->getLocationX() != destinationX || track0->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track0);
                    }
                }
            }
            else if (track->getLink6())
            {
                if (!track6->getFound())
                {
                    setTrackSpeedLengthList.push_back(track6);
                    track6->setFound(true);
                    if (track6->getLocationX() != destinationX || track6->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track6);
                    }
                }
            }
            else if (track->getLink1())
            {
                if (!track1->getFound())
                {
                    setTrackSpeedLengthList.push_back(track1);
                    track1->setFound(true);
                    if (track1->getLocationX() != destinationX || track1->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track1);
                    }
                }

            }
            else if (track->getLink7())
            {
                if (!track7->getFound())
                {
                    setTrackSpeedLengthList.push_back(track7);
                    track7->setFound(true);
                    if (track7->getLocationX() != destinationX || track7->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track7);
                    }
                }
            }
            else if (track->getLink5())
            {
                if (!track5->getFound())
                {
                    setTrackSpeedLengthList.push_back(track5);
                    track5->setFound(true);
                    if (track5->getLocationX() != destinationX || track5->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track5);
                    }
                }

            }
            else if (track->getLink2() )
            {
                if(!track2->getFound())
                {
                    setTrackSpeedLengthList.push_back(track2);
                    track2->setFound(true);
                    if (track2->getLocationX() != destinationX || track2->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track2);
                    }
                }

            }
            else if (track->getLink8())
            {
                if (!track8->getFound())
                {
                    setTrackSpeedLengthList.push_back(track8);
                    track8->setFound(true);
                    if (track8->getLocationX() != destinationX || track8->getLocationY() != destinationY)
                    {
                        fillSetTrackSpeedLengthList(track8);
                    }
                }

            }

        }
        else
        {

        }

    }
}

void Map::setSectionSpeedLength()
{
    setTrackSpeedLengthList.push_back(start);
    fillSetTrackSpeedLengthList(start);
}

void Map::resetSetTrackSpeedLengthMechanics()
{
    std::shared_ptr<Track> track{nullptr};
    std::shared_ptr<Track> track2Temp{nullptr};

    start = track;
    end = track2Temp;
    setTrackSpeedLengthList.clear();
}
