#include "map.h"

Map::Map()
{

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
	int tempoffsetX = newStraightTrack->getOffsetX();
	int tempoffsetY = newStraightTrack->getOffsetY();
	int tempLocationX = newStraightTrack->getLocationX();
	int tempLocationY = newStraightTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		straightTrackList.push_back(newStraightTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();

	}

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
	int tempoffsetX = newDirectTrack->getOffsetX();
	int tempoffsetY = newDirectTrack->getOffsetY();
	int tempLocationX = newDirectTrack->getLocationX();
	int tempLocationY = newDirectTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		directTrackList.push_back(newDirectTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
	}


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
	int tempoffsetX = newCurvedTrack->getOffsetX();
	int tempoffsetY = newCurvedTrack->getOffsetY();
	int tempLocationX = newCurvedTrack->getLocationX();
	int tempLocationY = newCurvedTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		curvedTrackList.push_back(newCurvedTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
	}

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
	int tempoffsetX = newLinkedTrack->getOffsetX();
	int tempoffsetY = newLinkedTrack->getOffsetY();
	int tempLocationX = newLinkedTrack->getLocationX();
	int tempLocationY = newLinkedTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		linkedTrackList.push_back(newLinkedTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
	}

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
	int tempoffsetX = newExitTrack->getOffsetX();
	int tempoffsetY = newExitTrack->getOffsetY();
	int tempLocationX = newExitTrack->getLocationX();
	int tempLocationY = newExitTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		exitTrackList.push_back(newExitTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
	}

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
	int tempoffsetX = newBufferTrack->getOffsetX();
	int tempoffsetY = newBufferTrack->getOffsetY();
	int tempLocationX = newBufferTrack->getLocationX();
	int tempLocationY = newBufferTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		bufferTrackList.push_back(newBufferTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
	}

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
	int tempoffsetX = newSignalTrack->getOffsetX();
	int tempoffsetY = newSignalTrack->getOffsetY();
	int tempLocationX = newSignalTrack->getLocationX();
	int tempLocationY = newSignalTrack->getLocationY();
	if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
		signalTrackList.push_back(newSignalTrack);
	}
	else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
	}

}

std::vector<std::shared_ptr<BridgeUnderpassTrack> > Map::getBridgeUnderpassTrackList() const
{
    return bridgeUnderpassTrackList;
}

void Map::setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> > &newBridgeUnderpassTrackList)
{
    bridgeUnderpassTrackList = newBridgeUnderpassTrackList;
}

void Map::addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack)
{
    int tempoffsetX = newBridgeUnderpassTrack->getOffsetX();
    int tempoffsetY = newBridgeUnderpassTrack->getOffsetY();
    int tempLocationX = newBridgeUnderpassTrack->getLocationX();
    int tempLocationY = newBridgeUnderpassTrack->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        bridgeUnderpassTrackList.push_back(newBridgeUnderpassTrack);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }

}

std::vector<std::shared_ptr<SwitchTrack> > Map::getSwitchTrackList() const
{
    return switchTrackList;
}

void Map::setSwitchTrackList(const std::vector<std::shared_ptr<SwitchTrack> > &newSwitchTrackList)
{
    switchTrackList = newSwitchTrackList;
}

void Map::addSwitchTrack(std::shared_ptr<SwitchTrack> newSwitchTrack)
{
    int tempoffsetX = newSwitchTrack->getOffsetX();
    int tempoffsetY = newSwitchTrack->getOffsetY();
    int tempLocationX = newSwitchTrack->getLocationX();
    int tempLocationY = newSwitchTrack->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        switchTrackList.push_back(newSwitchTrack);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }

}

std::vector<std::shared_ptr<CrossoverTrack> > Map::getCrossoverTrackList() const
{
    return crossoverTrackList;
}

void Map::setCrossoverTrackList(const std::vector<std::shared_ptr<CrossoverTrack> > &newCrossoverTrackList)
{
    crossoverTrackList = newCrossoverTrackList;
}

void Map::addCrossoverTrack(std::shared_ptr<CrossoverTrack> newCrossoverTrack)
{
    int tempoffsetX = newCrossoverTrack->getOffsetX();
    int tempoffsetY = newCrossoverTrack->getOffsetY();
    int tempLocationX = newCrossoverTrack->getLocationX();
    int tempLocationY = newCrossoverTrack->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        crossoverTrackList.push_back(newCrossoverTrack);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }

}

std::vector<std::shared_ptr<FlyoverTrack> > Map::getFlyoverTrackList() const
{
    return flyoverTrackList;
}

void Map::setFlyoverTrackList(const std::vector<std::shared_ptr<FlyoverTrack> > &newFlyoverTrackList)
{
    flyoverTrackList = newFlyoverTrackList;
}

void Map::addFlyoverTrack(std::shared_ptr<FlyoverTrack> newFlyoverTrack)
{
    int tempoffsetX = newFlyoverTrack->getOffsetX();
    int tempoffsetY = newFlyoverTrack->getOffsetY();
    int tempLocationX = newFlyoverTrack->getLocationX();
    int tempLocationY = newFlyoverTrack->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        flyoverTrackList.push_back(newFlyoverTrack);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }

}

std::vector<std::shared_ptr<NamedLocation> > Map::getNamedLocationList() const
{
    return namedLocationList;
}

void Map::setNamedLocationList(const std::vector<std::shared_ptr<NamedLocation> > &newNamedLocationList)
{
    namedLocationList = newNamedLocationList;
}

void Map::addNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation)
{
    int tempoffsetX = newNamedLocation->getOffsetX();
    int tempoffsetY = newNamedLocation->getOffsetY();
    int tempLocationX = newNamedLocation->getLocationX();
    int tempLocationY = newNamedLocation->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        namedLocationList.push_back(newNamedLocation);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }
}

std::vector<std::shared_ptr<Concourse> > Map::getConcourseList() const
{
    return concourseList;
}

void Map::setConcourseList(const std::vector<std::shared_ptr<Concourse> > &newConcourseList)
{
    concourseList = newConcourseList;
}

void Map::addConcourse(std::shared_ptr<Concourse> newConcourseTrack)
{
    int tempoffsetX = newConcourseTrack->getOffsetX();
    int tempoffsetY = newConcourseTrack->getOffsetY();
    int tempLocationX = newConcourseTrack->getLocationX();
    int tempLocationY = newConcourseTrack->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        concourseList.push_back(newConcourseTrack);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }

}

std::vector<std::shared_ptr<Parapet> > Map::getParapetList() const
{
    return parapetList;
}

void Map::setParapetList(const std::vector<std::shared_ptr<Parapet> > &newParapetList)
{
    parapetList = newParapetList;
}

void Map::addParapetTrack(std::shared_ptr<Parapet> newParapet)
{
    int tempoffsetX = newParapet->getOffsetX();
    int tempoffsetY = newParapet->getOffsetY();
    int tempLocationX = newParapet->getLocationX();
    int tempLocationY = newParapet->getLocationY();
    if (!checkElementExists(tempoffsetX, tempoffsetY, tempLocationX, tempLocationY)) {
        parapetList.push_back(newParapet);
    }
    else {
        QMessageBox elementExistsAlreadyAlert;
        elementExistsAlreadyAlert.setIcon(QMessageBox::Critical);
        elementExistsAlreadyAlert.setText("An element already exists here.");
        elementExistsAlreadyAlert.exec();
    }

}



bool Map::checkElementExists(int offsetX, int offsetY, int locationX, int locationY)
{
	bool found = false;
	if (!straightTrackList.empty())
	{
		for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}

		}
	}

	if (!directTrackList.empty() && found == false)
	{
		for (std::shared_ptr<DirectTrack>& currentElement : directTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}
		}
	}

	if (!curvedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<CurvedTrack>& currentElement : curvedTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}
		}
	}

	if (!linkedTrackList.empty() && found == false)
	{
		for (std::shared_ptr<LinkedTrack>& currentElement : linkedTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}
		}
	}

	if (!exitTrackList.empty() && found == false)
	{
		for (std::shared_ptr<ExitTrack>& currentElement : exitTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}
		}
	}

	if (!bufferTrackList.empty() && found == false)
	{
		for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}
		}
	}

	if (!signalTrackList.empty() && found == false)
	{
		for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList) {
			int currentOffsetX = currentElement->getOffsetX();
			int currentOffsetY = currentElement->getOffsetY();
			int currentX = currentElement->getLocationX();
			int currentY = currentElement->getLocationY();
			if (currentOffsetX == offsetX && currentOffsetY == offsetY)
			{
				if (currentX == locationX && currentY == locationY)
				{
					found = true;
				}
			}
		}
	}

    if (!bridgeUnderpassTrackList.empty() && found == false)
    {
        for (std::shared_ptr<BridgeUnderpassTrack>& currentElement : bridgeUnderpassTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    found = true;
                }
            }
        }
    }

    if (!switchTrackList.empty() && found == false)
    {
        for (std::shared_ptr<SwitchTrack>& currentElement : switchTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    found = true;
                }
            }
        }
    }

    if (!crossoverTrackList.empty() && found == false)
    {
        for (std::shared_ptr<CrossoverTrack>& currentElement : crossoverTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    found = true;
                }
            }
        }
    }

    if (!flyoverTrackList.empty() && found == false)
    {
        for (std::shared_ptr<FlyoverTrack>& currentElement : flyoverTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    found = true;
                }
            }
        }
    }

    if (!namedLocationList.empty() && found == false)
    {
        for (std::shared_ptr<NamedLocation>& currentElement : namedLocationList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    found = true;
                }
            }
        }
    }

    if (!concourseList.empty() && found == false)
    {
        for (std::shared_ptr<Concourse>& currentElement : concourseList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    found = true;
                }
            }
        }
    }

    if (!parapetList.empty() && found == false)
    {
        for (std::shared_ptr<Parapet>& currentElement : parapetList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
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

	for (int i = 0; i < straightTrackList.size(); i++) {
		std::shared_ptr<StraightTrack>& currentElement = straightTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			straightTrackList.erase(straightTrackList.begin() + i);
			deleted = true;
		}

	}

	for (int i = 0; i < directTrackList.size(); i++) {
		std::shared_ptr<DirectTrack>& currentElement = directTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			directTrackList.erase(directTrackList.begin() + i);
			deleted = true;
		}

	}

	for (int i = 0; i < curvedTrackList.size(); i++) {
		std::shared_ptr<CurvedTrack>& currentElement = curvedTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			curvedTrackList.erase(curvedTrackList.begin() + i);
			deleted = true;
		}

	}
	for (int i = 0; i < linkedTrackList.size(); i++) {
		std::shared_ptr<LinkedTrack>& currentElement = linkedTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			linkedTrackList.erase(linkedTrackList.begin() + i);
			deleted = true;
		}

	}
	for (int i = 0; i < exitTrackList.size(); i++) {
		std::shared_ptr<ExitTrack>& currentElement = exitTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			exitTrackList.erase(exitTrackList.begin() + i);
			deleted = true;
		}

	}
	for (int i = 0; i < bufferTrackList.size(); i++) {
		std::shared_ptr<BufferTrack>& currentElement = bufferTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			bufferTrackList.erase(bufferTrackList.begin() + i);
			deleted = true;
		}

	}
	for (int i = 0; i < signalTrackList.size(); i++) {
		std::shared_ptr<SignalTrack>& currentElement = signalTrackList[i];
		int currentX = currentElement->getLocationX();
		int currentY = currentElement->getLocationY();
		if (currentX == locationX && currentY == locationY) {
			signalTrackList.erase(signalTrackList.begin() + i);
			deleted = true;
		}

	}
    for (int i = 0; i < bridgeUnderpassTrackList.size(); i++) {
        std::shared_ptr<BridgeUnderpassTrack>& currentElement = bridgeUnderpassTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            bridgeUnderpassTrackList.erase(bridgeUnderpassTrackList.begin() + i);
            deleted = true;
        }

    }
    for (int i = 0; i < switchTrackList.size(); i++) {
        std::shared_ptr<SwitchTrack>& currentElement = switchTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            switchTrackList.erase(switchTrackList.begin() + i);
            deleted = true;
        }

    }
    for (int i = 0; i < crossoverTrackList.size(); i++) {
        std::shared_ptr<CrossoverTrack>& currentElement = crossoverTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            crossoverTrackList.erase(crossoverTrackList.begin() + i);
            deleted = true;
        }

    }
    for (int i = 0; i < flyoverTrackList.size(); i++) {
        std::shared_ptr<FlyoverTrack>& currentElement = flyoverTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            flyoverTrackList.erase(flyoverTrackList.begin() + i);
            deleted = true;
        }

    }
    for (int i = 0; i < namedLocationList.size(); i++) {
        std::shared_ptr<NamedLocation>& currentElement = namedLocationList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            namedLocationList.erase(namedLocationList.begin() + i);
            deleted = true;
        }

    }
    for (int i = 0; i < concourseList.size(); i++) {
        std::shared_ptr<Concourse>& currentElement = concourseList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            concourseList.erase(concourseList.begin() + i);
            deleted = true;
        }

    }
    for (int i = 0; i < parapetList.size(); i++) {
        std::shared_ptr<FlyoverTrack>& currentElement = flyoverTrackList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX == locationX && currentY == locationY) {
            parapetList.erase(parapetList.begin() + i);
            deleted = true;
        }

    }
    return deleted;

}

void Map::addPlatform(Platform side, int offsetX, int offsetY, int locationX, int locationY)
{
    bool added = false;

    if (!straightTrackList.empty() && added == false)
    {
        for (std::shared_ptr<StraightTrack>& currentElement : straightTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();


            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    switch (side) {
                    case Platform::UP:
                        if (currentElement->getElementType()==ElementType::STRAIGHTH) {
                            currentElement->setPlatform1(true);
                            added = true;
                        }
                        break;
                    case Platform::DOWN:
                        if (currentElement->getElementType()==ElementType::STRAIGHTH) {
                            currentElement->setPlatform2(true);
                            added = true;
                            break;
                        }
                    case Platform::LEFT:
                        if (currentElement->getElementType()==ElementType::STRAIGHTV) {
                            currentElement->setPlatform1(true);
                            added = true;
                        }
                        break;
                    case Platform::RIGHT:
                        if (currentElement->getElementType()==ElementType::STRAIGHTV) {
                            currentElement->setPlatform2(true);
                            added = true;
                            break;
                        }
                    }


                }
            }
        }
    }
    if (!directTrackList.empty() && added == false)
    {
        for (std::shared_ptr<DirectTrack>& currentElement : directTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    switch  (side){
                    case Platform::LEFT:
                        if (currentElement->getElementType()==ElementType::DIRECTUP) {
                            currentElement->setPlatform1(true);
                        } else if (currentElement->getElementType()==ElementType::DIRECTDOWN) {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    case Platform::RIGHT:
                        if (currentElement->getElementType()==ElementType::DIRECTUP) {
                            currentElement->setPlatform2(true);
                        } else if (currentElement->getElementType()==ElementType::DIRECTDOWN) {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    case Platform::UP:
                        if (currentElement->getElementType()==ElementType::DIRECTLEFT) {
                            currentElement->setPlatform1(true);
                        } else if (currentElement->getElementType()==ElementType::DIRECTRIGHT) {
                            currentElement->setPlatform1(true);
                        }
                        added = true;
                        break;
                    case Platform::DOWN:
                        if (currentElement->getElementType()==ElementType::DIRECTLEFT) {
                            currentElement->setPlatform2(true);
                        } else if (currentElement->getElementType()==ElementType::DIRECTRIGHT) {
                            currentElement->setPlatform2(true);
                        }
                        added = true;
                        break;
                    default:
                        added = false;
                    }


                }
            }
        }
    }

    if (!bufferTrackList.empty() && added == false)
    {
        for (std::shared_ptr<BufferTrack>& currentElement : bufferTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    switch  (side){
                    case Platform::LEFT:

                        added = true;
                    case Platform::RIGHT:

                        added = true;
                    case Platform::UP:

                        added = true;
                    case Platform::DOWN:

                        added = true;
                    default:
                        added = false;
                    }


                }
            }
        }
    }


    if (!signalTrackList.empty() && added == false)
    {
        for (std::shared_ptr<SignalTrack>& currentElement : signalTrackList) {
            int currentOffsetX = currentElement->getOffsetX();
            int currentOffsetY = currentElement->getOffsetY();
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            if (currentOffsetX == offsetX && currentOffsetY == offsetY)
            {
                if (currentX == locationX && currentY == locationY)
                {
                    switch (currentElement->getElementType()) {

                        case ElementType:: SWITCHTIGHT1:
                        case ElementType:: SWITCHTIGHT2:
                        case ElementType:: SWITCH1:
                        case ElementType:: SWITCH2:
                            if (side==Platform::DOWN){

                                added = true;
                            }
                            break;
                        case ElementType:: SWITCHTIGHT3:
                        case ElementType:: SWITCHTIGHT4:
                        case ElementType:: SWITCH3:
                        case ElementType:: SWITCH4:
                            if (side==Platform::UP) {

                                added= true;
                            }
                            break;
                        case ElementType:: SWITCHTIGHT5:
                        case ElementType:: SWITCHTIGHT7:
                        case ElementType:: SWITCH5:
                        case ElementType:: SWITCH7:
                            if (side==Platform::RIGHT) {

                                added= true;
                            }
                            break;
                        case ElementType:: SWITCHTIGHT6:
                        case ElementType:: SWITCHTIGHT8:
                        case ElementType:: SWITCH6:
                        case ElementType:: SWITCH8:
                            if (side==Platform::LEFT) {

                                added= true;
                            }
                            break;

                    }


                }
            }
        }
    }

}

