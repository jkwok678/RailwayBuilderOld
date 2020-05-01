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
    Element getElementAt(int locationX, int locationY);
    bool checkElementExists(int locationX, int locationY);
    void deleteElement(int locationX, int locationY);
};

#endif // MAP_H
