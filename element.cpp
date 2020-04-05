#include "element.h"

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
