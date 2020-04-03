#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    private:
    int xLocation;
    int yLocation;


    public:

    Element(int currentX, int currentY);
    int getXLocation() const;
    int getYLocation() const;
    void setXLocation(int currentX);
    void setYLocation(int currentY);
};

#endif // ELEMENT_H
