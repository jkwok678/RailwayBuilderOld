#ifndef MAP_H
#define MAP_H
#include <vector>
#include  "element.h"

class Map
{
private:
    std::vector<Element> elementList;

public:
    Map();
    std::vector<Element> getElementList(){return elementList;};
    void setElementList(std::vector<Element> newElementList);
    void addElement(Element newElement);
    void deleteElement(int xLocation, int yLocation);
};

#endif // MAP_H
