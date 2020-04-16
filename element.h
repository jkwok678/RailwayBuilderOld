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
    int xOffset;
    int yOffset;
    ElementType elementType;


public:
    Element();
    Element(int currentX, int currentY);
    int getXLocation() const;
    int getYLocation() const;
    void setXLocation(int currentX);
    void setYLocation(int currentY);
    int getXOffset() const;
    int getYOffset() const;
    void setXOffset(int value);
    void setYOffset(int value);
};



#endif // ELEMENT_H
