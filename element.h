#ifndef ELEMENT_H
#define ELEMENT_H

enum class ElementType
{
    NONE, STRAIGHTH,STRAIGHTV
};

class Element
{
private:

protected:
    int xLocation;
    int yLocation;
    ElementType elementType;


public:

    Element(int currentX, int currentY);
    int getXLocation() const;
    int getYLocation() const;
    void setXLocation(int currentX);
    void setYLocation(int currentY);
};



#endif // ELEMENT_H
