#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <QSharedPointer>
#include <QFont>
#include <memory>
#include <string>
#include <iostream>

enum class ParapetType
{
    PARAPET1, PARAPET2, PARAPET3, PARAPET4, PARAPET5, PARAPET6, PARAPET7, PARAPET8, PARAPET9,
    PARAPET10, PARAPET11, PARAPET12, PARAPET13, PARAPET14, PARAPET15, PARAPET16, PARAPET17, PARAPET18, PARAPET19, PARAPET20,
    PARAPET21, PARAPET22, PARAPET23, PARAPET24, PARAPET25, PARAPET26, PARAPET27, PARAPET28
};

class Element
{
private:

protected:
	int offsetX;
	int offsetY;
	int locationX;
	int locationY;

public:
	Element();
	Element(int currentX, int currentY);
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
    QFont font;




protected:


public:
    Text(int newLocationX, int newLocationY, QString newReadableText, QFont);

    int getEditableX() const;
    void setEditableX(int newEditableX);
    int getEditableY() const;
    void setEditableY(int newEditableY);
    int getFontSize() const;
    void setFontSize(int newFontSize);
    QString getReadableText() const;
    void setReadableText(const QString& newReadableText);
    QFont getFont() const;
    void setFont(const QFont newFont);
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
    NamedLocation(int newLocationX, int newLocationY);
};

class Concourse : public NamedElement
{
private:


protected:


public:
    Concourse(int newLocationX, int newLocationY);

};



class Parapet : public Element
{
private:
    ParapetType parapetType;



protected:


public:
    Parapet(ParapetType newParapetType, int newLocationX, int newLocationY);
    ParapetType getParapetType() const;
    void setParapetType(const ParapetType &newParapetType);
};







#endif // ELEMENT_H
