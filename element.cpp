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

NamedLocation::NamedLocation()
{

}

NamedLocation::NamedLocation(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
    named = false;



}

bool NamedLocation::getNamed() const
{
    return named;
}

void NamedLocation::setNamed(bool newNamed)
{
    named = newNamed;
}

Concourse::Concourse(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
    named = false;

}

Parapet::Parapet(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
}


Text::Text(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY, QString newReadableText)
{
    elementType = newElementType;
    offsetX = newOffsetX;
    offsetY = newOffsetY;
    locationX = newLocationX;
    locationY = newLocationY;
    readableText = newReadableText;
    editableX = locationX+fontSize;
    editableY = locationY +fontSize;

}

int Text::getEditableX() const
{
    return editableX;
}

void Text::setEditableX(int newEditableX)
{
    editableX = newEditableX;
}

int Text::getEditableY() const
{
    return editableY;
}

void Text::setEditableY(int newEditableY)
{
    editableY = newEditableY;
}

int Text::getFontSize() const
{
    return fontSize;
}

void Text::setFontSize(int newFontSize)
{
    fontSize = newFontSize;
}

QString Text::getReadableText() const
{
    return readableText;
}

void Text::setReadableText(const QString &newReadableText)
{
    readableText = newReadableText;
}

