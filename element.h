#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <QSharedPointer>
#include <memory>
#include <string>
#include <iostream>

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
	SWITCH6, SWITCH7, SWITCH8, SWITCH9, SWITCH10, SWITCH11, SWITCH12, SWITCH13, SWITCH14, SWITCH15, SWITCH16, CROSSOVER1,
	CROSSOVER2, CROSSOVER3, CROSSOVER4, CROSSOVER5, CROSSOVER6, FLYOVER1, FLYOVER2, FLYOVER3, FLYOVER4, FLYOVER5, FLYOVER6,
	FLYOVER7, FLYOVER8, FLYOVER9, FLYOVER10, FLYOVER11, FLYOVER12, NAMEDLOCATION, CONCOURSE, PLATFORMLEFT, PLATFORMRIGHT,
	PLATFORMDOWN, PLATFORMUP, PARAPET1, PARAPET2, PARAPET3, PARAPET4, PARAPET5, PARAPET6, PARAPET7, PARAPET8, PARAPET9,
	PARAPET10, PARAPET11, PARAPET12, PARAPET13, PARAPET14, PARAPET15, PARAPET16, PARAPET17, PARAPET18, PARAPET19, PARAPET20,
    PARAPET21, PARAPET22, PARAPET23, PARAPET24, PARAPET25, PARAPET26, PARAPET27, PARAPET28, LEVELCROSSING, ADDCHANGETEXT, MOVETEXT,SETCHANGENAMEDLOCATION


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
    int getLocationX() const;
	void setLocationX(int locationX);
	int getLocationY() const;
	void setLocationY(int locationY);
};

class Text : public Element
{
private:
    int editableX;
    int editableY;
    int fontSize{ 12 };
    QString readableText;




protected:


public:
    Text(ElementType newElementType, int newLocationX, int newLocationY, QString newReadableText);

    int getEditableX() const;
    void setEditableX(int newEditableX);
    int getEditableY() const;
    void setEditableY(int newEditableY);
    int getFontSize() const;
    void setFontSize(int newFontSize);
    QString getReadableText() const;
    void setReadableText(const QString& newReadableText);
};

class NamedElement : public Element
{
private:


protected:
    bool named { false };
    std::shared_ptr<Text> text {nullptr};


public:
    NamedElement();
    bool getNamed() const;
    void setNamed(bool newNamed);

    std::shared_ptr<Text> getText();
    void setText(std::shared_ptr<Text> &newText);
};


class NamedLocation : public NamedElement
{
private:


protected:



public:
    NamedLocation(ElementType newElementType, int newLocationX, int newLocationY);
};

class Concourse : public NamedElement
{
private:


protected:


public:
    Concourse(ElementType newElementType, int newLocationX, int newLocationY);

};



class Parapet : public Element
{
private:




protected:


public:
    Parapet(ElementType newElementType, int newLocationX, int newLocationY);


};







#endif // ELEMENT_H
