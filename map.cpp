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

void Map::deleteElement(int xLocation, int yLocation)
{

}

