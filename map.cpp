#include "map.h"

Map::Map()
{


}


void
Map::setElementList(std::vector<Element> newElementList)
{
    this->elementList = newElementList;
}

void
Map::addElement(Element newElement)
{
    elementList.push_back(newElement);
}

Element Map::getElementAt(int locationX, int locationY)
{

}

bool Map::checkElementExists(int locationX, int locationY)
{
    bool found = false;
    for (Element currentElement : elementList){
        int currentX = currentElement.getLocationX();
        int currentY = currentElement.getLocationY();
        if (currentX==locationX && currentY==locationY) {
            found =true
        }
    }
    return found;

}

void Map::deleteElement(int locationX, int locationY)
{
    int toRemove;

    for (int i=0; i<elementList.size();i++){
        Element currentElement = elementList[i];
        int currentX = currentElement.getLocationX();
        int currentY = currentElement.getLocationY();
        if (currentX==locationX && currentY==locationY) {
            elementList.erase(elementList.begin() + i);
        }

    }

}

