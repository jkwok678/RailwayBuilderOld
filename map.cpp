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

