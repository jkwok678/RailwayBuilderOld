#include "canvas.h"

Canvas::Canvas()
{
    setMinimumSize(1280,800);
    QPalette pal = palette();
    imageSize=15;
    // set black background
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
    return *canvasMap;
}

void Canvas::setMap(Map &map)
{
    canvasMap = &map;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {
         lastPoint = event->pos();
         exactX = event->pos().x();
         exactY = event->pos().y();
         extraX = exactX%16;
         extraY = exactY%16;
         finalX = exactX - extraX;
         finalY = exactY - extraY;
         boundX = finalX+imageSize;
         boundY = finalY+imageSize;
         Element newElement;
         switch (*canvasChosen) {
            case ElementType::NONE:

            break;

            case ElementType::STRAIGHTH:

            break;

            case ElementType::STRAIGHTV:
            painter.drawImage(finalX,finalY,*straightVImage);
            break;

            case ElementType::STRAIGHTV:
            painter.drawImage(finalX,finalY,*straightVImage);
            break;
         }

         update(finalX,finalY,boundX,boundY);



        }
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.drawImage(finalX,finalY,QImage(":/graphics/graphics/straightH.png"));
    switch (*canvasChosen) {
      case ElementType::NONE:

        break;

      case ElementType::STRAIGHTH:
        painter.drawImage(finalX,finalY,*straightHImage);
        break;

      case ElementType::STRAIGHTV:
        painter.drawImage(finalX,finalY,*straightVImage);
        break;

      case ElementType::STRAIGHTV:
      painter.drawImage(finalX,finalY,*straightVImage);
      break;
    }

}

