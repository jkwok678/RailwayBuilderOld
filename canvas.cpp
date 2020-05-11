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
    tightCurve1Image = new QImage (":/graphics/graphics/tightCurve1.png");
    tightCurve2Image = new QImage (":/graphics/graphics/tightCurve2.png");
    tightCurve3Image = new QImage (":/graphics/graphics/tightCurve3.png");
    tightCurve4Image = new QImage (":/graphics/graphics/tightCurve4.png");
    curve1Image = new QImage (":/graphics/graphics/curve1.png");
    curve2Image = new QImage (":/graphics/graphics/curve2.png");
    curve3Image = new QImage (":/graphics/graphics/curve3.png");
    curve4Image = new QImage (":/graphics/graphics/curve4.png");
    linkLeftImage = new QImage (":/graphics/graphics/linkLeftUnset.png");
    linkRightImage = new QImage (":/graphics/graphics/linkRightUnset.png");
    linkDownImage = new QImage (":/graphics/graphics/linkDownUnset.png");
    linkUpImage = new QImage (":/graphics/graphics/linkUpUnset.png");
    linkLeftUpImage = new QImage (":/graphics/graphics/linkLeftUpUnset.png");
    linkRightUpImage = new QImage (":/graphics/graphics/linkRightUpUnset.png");
    linkRightDownImage = new QImage (":/graphics/graphics/linkRightDownUnset.png");
    linkLeftDownImage = new QImage (":/graphics/graphics/linkLeftDownUnset.png");
    exitLeftImage = new QImage(":/graphics/graphics/exitLeft.png");
    exitRightImage = new QImage(":/graphics/graphics/exitRight.png");
    exitDownImage = new QImage(":/graphics/graphics/exitDown.png");
    exitUpImage = new QImage(":/graphics/graphics/exitUp.png");
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

          case ElementType::TIGHTCURVE1:
            {
            std::unique_ptr<CurvedTrack> tightCurve1(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *tightCurve1;
            drawnLayout->addElement(newElement);
            break;
            }
          case ElementType::TIGHTCURVE2:
            {
            std::unique_ptr<CurvedTrack> tightCurve2(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *tightCurve2;
            drawnLayout->addElement(newElement);
            break;
            }
           case ElementType::TIGHTCURVE3:
            {
            std::unique_ptr<CurvedTrack> tightCurve3(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *tightCurve3;
            drawnLayout->addElement(newElement);
            break;
            }
           case ElementType::TIGHTCURVE4:
            {
            std::unique_ptr<CurvedTrack> tightCurve4(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *tightCurve4;
            drawnLayout->addElement(newElement);
            break;
            }
           case ElementType::CURVE1:
            {
            std::unique_ptr<CurvedTrack> curve1(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *curve1;
            drawnLayout->addElement(newElement);
            break;
            }
           case ElementType::CURVE2:
            {
            std::unique_ptr<CurvedTrack> curve2(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *curve2;
            drawnLayout->addElement(newElement);
            break;
            }
           case ElementType::CURVE3:
            {
            std::unique_ptr<CurvedTrack> curve3(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *curve3;
            drawnLayout->addElement(newElement);
            break;
            }
           case ElementType::CURVE4:
            {
            std::unique_ptr<CurvedTrack> curve4(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            newElement = *curve4;
            drawnLayout->addElement(newElement);
            break;
            }

         case ElementType::LINKLEFT:
          {
          std::unique_ptr<LinkedTrack> linkLeft(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkLeft;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKRIGHT:
          {
          std::unique_ptr<LinkedTrack> linkRight(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkRight;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKDOWN:
          {
          std::unique_ptr<LinkedTrack> linkDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkDown;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKUP:
          {
          std::unique_ptr<LinkedTrack> linkUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkUp;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKLEFTUP:
          {
          std::unique_ptr<LinkedTrack> linkLeftUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkLeftUp;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKRIGHTUP:
          {
          std::unique_ptr<LinkedTrack> linkRightUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkRightUp;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKRIGHTDOWN:
          {
          std::unique_ptr<LinkedTrack> linkRightDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkRightDown;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::LINKLEFTDOWN:
          {
          std::unique_ptr<LinkedTrack> linkLeftDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *linkLeftDown;
          drawnLayout->addElement(newElement);
          break;
          }

         case ElementType::EXITLEFT:
          {
          std::unique_ptr<ExitTrack> exitLeft(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *exitLeft;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::EXITRIGHT:
          {
          std::unique_ptr<ExitTrack> exitRight(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *exitRight;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::EXITDOWN:
          {
          std::unique_ptr<ExitTrack> exitDown(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *exitDown;
          drawnLayout->addElement(newElement);
          break;
          }
         case ElementType::EXITUP:
          {
          std::unique_ptr<ExitTrack> exitUp(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          newElement = *exitUp;
          drawnLayout->addElement(newElement);
          break;
          }

         }


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
        case ElementType::TIGHTCURVE1:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*tightCurve1Image);
          break;

        case ElementType::TIGHTCURVE2:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*tightCurve2Image);
          break;
        case ElementType::TIGHTCURVE3:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*tightCurve3Image);
          break;

        case ElementType::TIGHTCURVE4:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*tightCurve4Image);
          break;
        case ElementType::CURVE1:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*curve1Image);
          break;

        case ElementType::CURVE2:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*curve2Image);
          break;
        case ElementType::CURVE3:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*curve3Image);
          break;

        case ElementType::CURVE4:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*curve4Image);
          break;

        case ElementType::LINKLEFT:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkLeftImage);
          break;

        case ElementType::LINKRIGHT:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkRightImage);
          break;
        case ElementType::LINKDOWN:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkDownImage);
          break;

        case ElementType::LINKUP:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkUpImage);
          break;

        case ElementType::LINKLEFTUP:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkLeftUpImage);
          break;

        case ElementType::LINKRIGHTUP:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkRightUpImage);
          break;
        case ElementType::LINKRIGHTDOWN:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkRightDownImage);
          break;

        case ElementType::LINKLEFTDOWN:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*linkLeftDownImage);
          break;

        case ElementType::EXITLEFT:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*exitLeftImage);
          break;

        case ElementType::EXITRIGHT:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*exitRightImage);
          break;
        case ElementType::EXITDOWN:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*exitDownImage);
          break;

        case ElementType::EXITUP:
          painter.drawImage(currentElement.getLocationX(),currentElement.getLocationY(),*exitUpImage);
          break;


        }
        }



    }

}



