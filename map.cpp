#include "map.h"

Map::Map()
{


}


void
Map::setElementList(std::vector<std::shared_ptr<Element>> newElementList)
{
    this->elementList = newElementList;
}

void
Map::addElement(std::shared_ptr<Element> newElement)
{
    elementList.push_back(newElement);
}

std::shared_ptr<Element> Map::getElementAt(int locationX, int locationY)
{

}

bool Map::checkElementExists(int locationX, int locationY)
{
    bool found = false;
    for (std::shared_ptr<Element> &currentElement : elementList){
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX==locationX && currentY==locationY) {
            found =true;
        }
    }
    return found;

}

void Map::deleteElement(int locationX, int locationY)
{

    for (int i=0; i<elementList.size();i++){
        std::shared_ptr<Element> &currentElement = elementList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX==locationX && currentY==locationY) {
            elementList.erase(elementList.begin() + i);
        }

    }

}

