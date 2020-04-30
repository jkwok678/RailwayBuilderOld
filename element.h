#ifndef ELEMENT_H
#define ELEMENT_H

enum class ElementType
{
    NONE, STRAIGHTH,STRAIGHTV, DIRECTLEFT, DIRECTRIGHT, DIRECTUP, DIRECTDOWN, STRAIGHTLEFTUP, STRIAGHTRIGHTUP, DIRECTRIGHTUP,
    DIRECTLEFTUP, DIRECTLEFTDOWN, DIRECTRIGHTDOWN, TIGHTCURVE1, TIGHTCURVE2, TIGHTCURVE3, TIGHTCURVE4, CURVE1, CURVE2, CURVE3,
    CURVE4, LINKLEFT, LINKRIGHT, LINKDOWN, LINKUP, LINKLEFTUP, LINKRIGHTUP, LINKLEFTDOWN, LINKRIGHTDOWN

};

class Element
{
private:

protected:
    ElementType elementType;
    int offsetX;
    int offsetY;
    int locationX;
    int locationY;




public:
    Element();
    Element(int currentX, int currentY);

    ElementType getElementType() const;
    void setElementType(const ElementType &newElementType);
    int getOffsetX() const;
    void setOffsetX(int offsetX);
    int getOffsetY() const;
    void setOffsetY(int offsetY);
    int getLocationX() const;
    void setLocationX(int locationX);
    int getLocationY() const;
    void setLocationY(int locationY);
};



#endif // ELEMENT_H
