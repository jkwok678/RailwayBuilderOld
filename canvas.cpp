#include "canvas.h"

Canvas::Canvas()
{
    setMinimumSize(1280,800);
    QPalette pal = palette();
    imageSize=15;
    // set black background
    drawnLayout = new Map;
    pal.setColor(QPalette::Window, Qt::white);
    straightHImage = new QImage(":/graphics/graphics/straightH.png");
    straightVImage = new QImage(":/graphics/graphics/straightV.png");
    directLeftImage = new QImage(":/graphics/graphics/directLeft.png");
    directRightImage = new QImage(":/graphics/graphics/directRight.png");
    directUpImage = new QImage(":/graphics/graphics/directUp.png");
    directDownImage = new QImage(":/graphics/graphics/directDown.png");
    straightLeftUpImage = new QImage(":/graphics/graphics/straightLeftUp.png");
    straightRightUpImage = new QImage(":/graphics/graphics/straightRightUp.png");
    directLeftUpImage = new QImage(":/graphics/graphics/directLeftUp.png");
    directRightUpImage = new QImage(":/graphics/graphics/directRightUp.png");
    directRightDownIamge = new QImage(":/graphics/graphics/directRightDown.png");
    directLeftDownImage = new QImage(":/graphics/graphics/directLeftDown.png");
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

void Canvas::setOffsetX(int &newOffsetX)
{
    offsetX = newOffsetX;
}

int Canvas::getOffsetY() const
{
    return offsetY;
}

void Canvas::setOffsetY(int &newOffsetY)
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
            {


             break;
            }
           case ElementType::STRAIGHTH:
            {
             std::unique_ptr<StraightTrack> straightH(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));

             newElement = *straightH;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::STRAIGHTV:
            {
             std::unique_ptr<StraightTrack> straightV(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             std::cout << offsetX << std::flush;
             newElement = *straightV;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::DIRECTLEFT:
            {
             std::unique_ptr<DirectTrack> directLeft(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *directLeft;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::DIRECTRIGHT:
            {
             std::unique_ptr<DirectTrack> directRight(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *directRight;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::DIRECTUP:
            {
             std::unique_ptr<DirectTrack> directUp(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *directUp;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::DIRECTDOWN:
            {
             std::unique_ptr<DirectTrack> directDown(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *directDown;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::STRIAGHTRIGHTUP:
            {
             std::unique_ptr<StraightTrack> straightRightUp(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *straightRightUp;
             drawnLayout->addElement(newElement);
             break;
            }
           case ElementType::STRAIGHTLEFTUP:
            {
             std::unique_ptr<StraightTrack> straightLeftUp(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *straightLeftUp;
             drawnLayout->addElement(newElement);
             break;
            }
          case ElementType::DIRECTRIGHTUP:
            {
             std::unique_ptr<DirectTrack> directRightUp(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             newElement = *directRightUp;
             drawnLayout->addElement(newElement);
             break;
            }
          case ElementType::DIRECTLEFTUP:
            {
            std::unique_ptr<DirectTrack> directLeftUp(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *directLeftUp;
            drawnLayout->addElement(newElement);
            break;
            }
          case ElementType::DIRECTLEFTDOWN:
            {
            std::unique_ptr<DirectTrack> directLeftDown(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *directLeftDown;
            drawnLayout->addElement(newElement);
            break;
            }
          case ElementType::DIRECTRIGHTDOWN:
            {
            std::unique_ptr<DirectTrack> directRightDown(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *directRightDown;
            drawnLayout->addElement(newElement);
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

        if (offsetX==currentElement.getOffsetX() && offsetY ==currentElement.getOffsetY()) {

        switch (currentElement.getElementType()) {

          case ElementType::NONE:

            break;

          case ElementType::STRAIGHTH:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*straightHImage);
            break;

          case ElementType::STRAIGHTV:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*straightVImage);
            break;

          case ElementType::DIRECTLEFT:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directLeftImage);
            break;

          case ElementType::DIRECTRIGHT:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directRightImage);
            break;
          case ElementType::DIRECTUP:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directUpImage);
            break;
          case ElementType::DIRECTDOWN:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directDownImage);
            break;

          case ElementType::STRIAGHTRIGHTUP:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*straightRightUpImage);
            break;

          case ElementType::STRAIGHTLEFTUP:
            painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*straightLeftUpImage);
            break;
        case ElementType::DIRECTRIGHTUP:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directRightUpImage);
          break;
        case ElementType::DIRECTLEFTUP:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directLeftUpImage);
          break;
        case ElementType::DIRECTLEFTDOWN:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directLeftDownImage);
          break;
        case ElementType::DIRECTRIGHTDOWN:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*directRightDownIamge);
          break;



        }
        }



    }

}



