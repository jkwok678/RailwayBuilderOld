#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

enum class ElementType
{
	NONE, STRAIGHTH, STRAIGHTV, STRAIGHTLEFTUP, STRIAGHTRIGHTUP, DIRECTLEFT, DIRECTRIGHT, DIRECTUP, DIRECTDOWN, DIRECTRIGHTUP,
	DIRECTLEFTUP, DIRECTLEFTDOWN, DIRECTRIGHTDOWN, TIGHTCURVE1, TIGHTCURVE2, TIGHTCURVE3, TIGHTCURVE4, CURVE1, CURVE2, CURVE3,
	CURVE4, CURVE5, CURVE6, CURVE7, CURVE8, LINKLEFT, LINKRIGHT, LINKDOWN, LINKUP, LINKLEFTUP, LINKRIGHTUP, LINKLEFTDOWN,
	LINKRIGHTDOWN, EXITLEFT, EXITRIGHT, EXITDOWN, EXITUP, EXITLEFTUP, EXITRIGHTUP, EXITLEFTDOWN, EXITRIGHTDOWN, BUFFERLEFT, BUFFERRIGHT,
	BUFFERDOWN, BUFFERUP, BUFFERLEFTUP, BUFFERRIGHTUP, BUFFERLEFTDOWN, BUFFERRIGHTDOWN, SIGNALLEFT, SIGNALRIGHT, SIGNALDOWN, SIGNALUP,
    SIGNALLEFTUP, SIGNALRIGHTUP, SIGNALLEFTDOWN, SIGNALRIGHTDOWN, BRIDGE1, BRIDGE2, UNDERPASS1, UNDERPASS2, SWITCHTIGHT1,
    SWITCHTIGHT2, SWITCHTIGHT3, SWITCHTIGHT4, SWITCHTIGHT5, SWITCHTIGHT6, SWITCHTIGHT7, SWITCHTIGHT8, SWITCHSPLIT1, SWITCHSPLIT2,
    SWITCHSPLIT3, SWITCHSPLIT4, SWITCHSPLIT5, SWITCHSPLIT6, SWITCHSPLIT7, SWITCHSPLIT8, SWITCH1, SWITCH2, SWITCH3, SWITCH4, SWITCH5,
    SWITCH6, SWITCH7, SWITCH8, SWITCH9, SWITCH10, SWITCH11, SWITCH12, SWITCH13, SWITCH14, SWITCH15, SWITCH16,CROSSOVER1,
    CROSSOVER2, CROSSOVER3, CROSSOVER4, CROSSOVER5, CROSSOVER6, FLYOVER1, FLYOVER2, FLYOVER3, FLYOVER4, FLYOVER5, FLYOVER6,
    FLYOVER7, FLYOVER8, FLYOVER9, FLYOVER10, FLYOVER11, FLYOVER12,NAMEDLOCATION, CONCOURSE, PLATFORMLEFT, PLATFORMRIGHT,
    PLATFORMDOWN, PLATFORMUP, PARAPET1, PARAPET2, PARAPET3, PARAPET4, PARAPET5, PARAPET6,
    PARAPET7, PARAPET8, PARAPET9, PARARPET10

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
	void setElementType(const ElementType& newElementType);
	int getOffsetX() const;
	void setOffsetX(int offsetX);
	int getOffsetY() const;
	void setOffsetY(int offsetY);
	int getLocationX() const;
	void setLocationX(int locationX);
	int getLocationY() const;
	void setLocationY(int locationY);
};

class NamedLocation : public Element
{
private:






protected:
    bool named;
    std::string name;


public:
    NamedLocation();
    NamedLocation(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);
    bool getNamed() const;
    void setNamed(bool newNamed);

};


class Concourse : public NamedLocation
{
private:




protected:


public:
    Concourse(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};


class Parapet : public Element
{
private:




protected:


public:
    Parapet(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};




#endif // ELEMENT_H
