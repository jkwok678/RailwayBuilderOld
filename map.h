#ifndef MAP_H
#define MAP_H
#include <vector>
#include <memory>
#include  "element.h"

class Map
{
private:
    std::vector<std::unique_ptr<Element>> elementList;

public:
    Map();
    std::vector<std::unique_ptr<Element>> getElementList(){return elementList;};
    void setElementList(std::vector<std::unique_ptr<Element>> newElementList);
    void addElement(std::unique_ptr<Element> newElement);
    std::unique_ptr<Element> getElementAt(int locationX, int locationY);
    bool checkElementExists(int locationX, int locationY);
    void deleteElement(int locationX, int locationY);
};

#endif // MAP_H
