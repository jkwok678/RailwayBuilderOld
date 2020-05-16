#include "map.h"

Map::Map()
{


}


void
Map::setElementList(std::vector<std::unique_ptr<Element>> newElementList)
{
    this->elementList = newElementList;
}

void
Map::addElement(std::unique_ptr<Element> newElement)
{
    elementList.push_back(std::move(newElement));
}

std::unique_ptr<Element> Map::getElementAt(int locationX, int locationY)
{

}

bool Map::checkElementExists(int locationX, int locationY)
{
    bool found = false;
    for (std::unique_ptr<Element> &currentElement : elementList){
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
        std::unique_ptr<Element> &currentElement = elementList[i];
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        if (currentX==locationX && currentY==locationY) {
            elementList.erase(elementList.begin() + i);
        }

    }

}

