#include "element.h"

Element::Element() {

}

Element::Element(int currentX, int currentY) {
	locationX = currentX;
	locationY = currentY;

}

ElementType Element::getElementType() const {
	return elementType;
}

void Element::setElementType(const ElementType& newElementType) {
	elementType = newElementType;
}

int Element::getOffsetX() const {
	return offsetX;
}

void Element::setOffsetX(int newOffsetX) {
	offsetX = newOffsetX;
}

int Element::getOffsetY() const {
	return offsetY;
}

void Element::setOffsetY(int newOffsetY) {
	offsetY = newOffsetY;
}

int Element::getLocationX() const {
	return locationX;
}

void Element::setLocationX(int newLocationX) {
	locationX = newLocationX;
}

int Element::getLocationY() const {
	return locationY;
}

void Element::setLocationY(int newLocationY) {
	locationY = newLocationY;
}

Parapet::Parapet(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
}
