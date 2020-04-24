#include "canvas.h"



Canvas::Canvas()
{
    setMinimumSize(1280,800);
    QPalette pal = palette();
    imageSize=15;
    // set black background
    pal.setColor(QPalette::Background, Qt::white);

    setAutoFillBackground(true);
    setPalette(pal);
}

ElementType Canvas::getElementType()
{
    return chosen;
}

void Canvas::setElementType(ElementType newChosen)
{
    chosen=newChosen;
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
         update(finalX,finalY,boundX,boundY);



        }
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.drawImage(finalX,finalY,QImage(":/graphics/graphics/straightH.png"));
    switch (chosen) {
      case ElementType::NONE:

        break;
      case ElementType::STRAIGHTH:
        painter.drawImage(finalX,finalY,QImage(":/graphics/graphics/straightH.png"));
        break;

      case ElementType::STRAIGHTV:
        painter.drawImage(finalX,finalY,QImage(":/graphics/graphics/straightV.png"));
        break;
    }

}

