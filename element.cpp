#include "element.h"


Element ::Element()
{

}

Element::Element(int currentX, int currentY)
{
    xLocation = currentX;
    yLocation = currentY;

}

int
Element::getXLocation() const
{
  return xLocation;
}

int
Element::getYLocation() const
{
  return yLocation;
}

void
Element::setXLocation(int currentX) {
  xLocation= currentX;
}

void
Element::setYLocation(int currentY) {
  yLocation= currentY;
}

int Element::getXOffset() const
{
    return xOffset;
}

void Element::setXOffset(int value)
{
    xOffset = value;
}

int Element::getYOffset() const
{
    return yOffset;
}

void Element::setYOffset(int value)
{
    yOffset = value;
}
