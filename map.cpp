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

}

