#include "canvas.h"

Canvas::Canvas()
{
    setMinimumSize(1280,800);
    QPalette pal = palette();
    imageSize=15;
    // set black background
    drawnLayout = new Map;
    pal.setColor(QPalette::Background, Qt::white);
    straightHImage = new QImage(":/graphics/graphics/straightH.png");
    straightVImage = new QImage(":/graphics/graphics/straightV.png");
    directLeftImage = new QImage(":/graphics/graphics/directLeft.png");
    directRightImage = new QImage(":/graphics/graphics/directRight.png");
    setAutoFillBackground(true);
    setPalette(pal);
}

ElementType Canvas::getElementType()
{
    return *canvasChosen;
}

void Canvas::setElementType(ElementType &newChosen)
{
    canvasChosen=&newChosen;
}

Map Canvas::getMap()
{
    return *drawnLayout;
}

void Canvas::setMap(Map &map)
{
    drawnLayout = &map;
}

int Canvas::getImageSize() const
{
    return imageSize;
}

void Canvas::setImageSize(int newImageSize)
{
    imageSize = newImageSize;
}
bool Canvas::getModified() const
{
    return modified;
}

void Canvas::setModified(bool newModified)
{
    modified = newModified;
}

int Canvas::getOffsetX() const
{
    return offsetX;
}

void Canvas::setOffsetX(int newOffsetX)
{
    offsetX = newOffsetX;
}

int Canvas::getOffsetY() const
{
    return offsetY;
}

void Canvas::setOffsetY(int newOffsetY)
{
    offsetY = newOffsetY;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    lastPoint = event->pos();
    exactX = event->pos().x();
    exactY = event->pos().y();
    extraX = exactX%16;
    extraY = exactY%16;
    finalX = exactX - extraX;
    finalY = exactY - extraY;


    if (event->button() == Qt::LeftButton) {

         boundX = finalX+imageSize;
         boundY = finalY+imageSize;
         Element newElement;
         switch (*canvasChosen) {
           case ElementType::NONE:

             break;

           case ElementType::STRAIGHTH:
            {
             StraightTrack *straightH = new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY);
             newElement = *straightH;
             break;
            }
           case ElementType::STRAIGHTV:
            {
             StraightTrack *straightV = new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY);
             newElement = *straightV;
             break;
            }

         }
         drawnLayout->addElement(newElement);

         }


         update();


}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (Element currentElement : drawnLayout->getElementList()){

        switch (currentElement.getElementType()) {

          case ElementType::NONE:

            break;

          case ElementType::STRAIGHTH:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*straightHImage);
            break;

          case ElementType::STRAIGHTV:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*straightVImage);
            break;


        }


    }

}



