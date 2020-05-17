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
    exitLeftUpImage = new QImage(":/graphics/graphics/exitLeftUp.png");
    exitRightUpImage = new QImage(":/graphics/graphics/exitRightUp.png");
    exitLeftDownImage = new QImage(":/graphics/graphics/exitLeftDown.png");
    exitRightDownImage = new QImage(":/graphics/graphics/exitRightDown.png");
    curve5Image = new QImage (":/graphics/graphics/curve5.png");
    curve6Image = new QImage (":/graphics/graphics/curve6.png");
    curve7Image = new QImage (":/graphics/graphics/curve7.png");
    curve8Image = new QImage (":/graphics/graphics/curve8.png");
    bufferLeftImage = new QImage (":/graphics/graphics/bufferLeft.png");
    bufferRightImage = new QImage (":/graphics/graphics/bufferRight.png");
    bufferDownImage = new QImage (":/graphics/graphics/bufferDown.png");
    bufferUpImage = new QImage (":/graphics/graphics/bufferUp.png");
    bufferLeftUpImage = new QImage (":/graphics/graphics/bufferLeftUp.png");
    bufferRightUpImage = new QImage (":/graphics/graphics/bufferRightUp.png");
    bufferLeftDownImage = new QImage (":/graphics/graphics/bufferLeftDown.png");
    bufferRightDownImage = new QImage (":/graphics/graphics/bufferRightDown.png");
    signalLeftImage = new QImage (":/graphics/graphics/signalLeft.png");
    signalRightImage = new QImage (":/graphics/graphics/signalRight.png");
    signalDownImage = new QImage (":/graphics/graphics/signalDown.png");
    signalUpImage = new QImage (":/graphics/graphics/signalUp.png");
    signalLeftUpImage = new QImage (":/graphics/graphics/signalLeftUp.png");
    signalRightUpImage = new QImage (":/graphics/graphics/signalRightUp.png");
    signalLeftDownImage = new QImage (":/graphics/graphics/signalLeftDown.png");
    signalRightDownImage = new QImage (":/graphics/graphics/signalRightDown.png");
    shuntLeftImage = new QImage (":/graphics/graphics/shuntLeft.png");
    shuntRightImage = new QImage (":/graphics/graphics/shuntRight.png");
    shuntDownImage = new QImage (":/graphics/graphics/shuntDown.png");
    shuntUpImage = new QImage (":/graphics/graphics/shuntUp.png");
    shuntLeftUpImage = new QImage (":/graphics/graphics/shuntLeftUp.png");
    shuntRightUpImage = new QImage (":/graphics/graphics/shuntRightUp.png");
    shuntLeftDownImage = new QImage (":/graphics/graphics/shuntLeftDown.png");
    shuntRightDownImage = new QImage (":/graphics/graphics/shuntRightDown.png");
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

int Canvas::getAspect() const
{
    return canvasAspect;
}

void Canvas::setAspect(int &newAspect)
{
    canvasAspect = newAspect;
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

         switch (*canvasChosen) {
           case ElementType::NONE:
            {


             break;
            }
           case ElementType::STRAIGHTH:
            {
             std::shared_ptr<StraightTrack> straightH(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(straightH);
             break;
            }
           case ElementType::STRAIGHTV:
            {
             std::shared_ptr<StraightTrack> straightV(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             std::cout << offsetX << std::flush;

             drawnLayout->addElement(straightV);
             break;
            }
           case ElementType::DIRECTLEFT:
            {
             std::shared_ptr<DirectTrack> directLeft(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(directLeft);
             break;
            }
           case ElementType::DIRECTRIGHT:
            {
             std::shared_ptr<DirectTrack> directRight(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(directRight);
             break;
            }
           case ElementType::DIRECTUP:
            {
             std::shared_ptr<DirectTrack> directUp(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(directUp);
             break;
            }
           case ElementType::DIRECTDOWN:
            {
             std::shared_ptr<DirectTrack> directDown(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(directDown);
             break;
            }
           case ElementType::STRIAGHTRIGHTUP:
            {
             std::shared_ptr<StraightTrack> straightRightUp(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(straightRightUp);
             break;
            }
           case ElementType::STRAIGHTLEFTUP:
            {
             std::shared_ptr<StraightTrack> straightLeftUp(new StraightTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(straightLeftUp);
             break;
            }
          case ElementType::DIRECTRIGHTUP:
            {
             std::shared_ptr<DirectTrack> directRightUp(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
             drawnLayout->addElement(directRightUp);
             break;
            }
          case ElementType::DIRECTLEFTUP:
            {
            std::shared_ptr<DirectTrack> directLeftUp(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(directLeftUp);
            break;
            }
          case ElementType::DIRECTLEFTDOWN:
            {
            std::shared_ptr<DirectTrack> directLeftDown(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(directLeftDown);
            break;
            }
          case ElementType::DIRECTRIGHTDOWN:
            {
            std::shared_ptr<DirectTrack> directRightDown(new DirectTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(directRightDown);
            break;
            }

          case ElementType::TIGHTCURVE1:
            {
            std::shared_ptr<CurvedTrack> tightCurve1(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(tightCurve1);
            break;
            }
          case ElementType::TIGHTCURVE2:
            {
            std::shared_ptr<CurvedTrack> tightCurve2(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(tightCurve2);
            break;
            }
           case ElementType::TIGHTCURVE3:
            {
            std::shared_ptr<CurvedTrack> tightCurve3(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(tightCurve3);
            break;
            }
           case ElementType::TIGHTCURVE4:
            {
            std::shared_ptr<CurvedTrack> tightCurve4(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(tightCurve4);
            break;
            }
           case ElementType::CURVE1:
            {
            std::shared_ptr<CurvedTrack> curve1(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(curve1);
            break;
            }
           case ElementType::CURVE2:
            {
            std::shared_ptr<CurvedTrack> curve2(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(curve2);
            break;
            }
           case ElementType::CURVE3:
            {
            std::shared_ptr<CurvedTrack> curve3(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(curve3);
            break;
            }
           case ElementType::CURVE4:
            {
            std::shared_ptr<CurvedTrack> curve4(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
            drawnLayout->addElement(curve4);
            break;
            }

         case ElementType::LINKLEFT:
          {
          std::shared_ptr<LinkedTrack> linkLeft(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkLeft);
          break;
          }
         case ElementType::LINKRIGHT:
          {
          std::shared_ptr<LinkedTrack> linkRight(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkRight);
          break;
          }
         case ElementType::LINKDOWN:
          {
          std::shared_ptr<LinkedTrack> linkDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkDown);
          break;
          }
         case ElementType::LINKUP:
          {
          std::shared_ptr<LinkedTrack> linkUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkUp);
          break;
          }
         case ElementType::LINKLEFTUP:
          {
          std::shared_ptr<LinkedTrack> linkLeftUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkLeftUp);
          break;
          }
         case ElementType::LINKRIGHTUP:
          {
          std::shared_ptr<LinkedTrack> linkRightUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkRightUp);
          break;
          }
         case ElementType::LINKRIGHTDOWN:
          {
          std::shared_ptr<LinkedTrack> linkRightDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkRightDown);
          break;
          }
         case ElementType::LINKLEFTDOWN:
          {
          std::shared_ptr<LinkedTrack> linkLeftDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(linkLeftDown);
          break;
          }

         case ElementType::EXITLEFT:
          {
          std::shared_ptr<ExitTrack> exitLeft(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitLeft);
          break;
          }
         case ElementType::EXITRIGHT:
          {
          std::shared_ptr<ExitTrack> exitRight(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitRight);
          break;
          }
         case ElementType::EXITDOWN:
          {
          std::shared_ptr<ExitTrack> exitDown(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitDown);
          break;
          }
         case ElementType::EXITUP:
          {
          std::shared_ptr<ExitTrack> exitUp(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitUp);
          break;
          }

         case ElementType::EXITLEFTUP:
          {
          std::shared_ptr<ExitTrack> exitLeftUp(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitLeftUp);
          break;
          }
         case ElementType::EXITRIGHTUP:
          {
          std::shared_ptr<ExitTrack> exitRightUp(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitRightUp);
          break;
          }

         case ElementType::EXITLEFTDOWN:
          {
          std::shared_ptr<ExitTrack> exitLeftDown(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitLeftDown);
          break;
          }
         case ElementType::EXITRIGHTDOWN:
          {
          std::shared_ptr<ExitTrack> exitRightDown(new ExitTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(exitRightDown);
          break;
          }

         case ElementType::CURVE5:
          {
          std::shared_ptr<CurvedTrack> curve5(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(curve5);
          break;
          }
         case ElementType::CURVE6:
          {
          std::shared_ptr<CurvedTrack> curve6(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(curve6);
          break;
          }
         case ElementType::CURVE7:
          {
          std::shared_ptr<CurvedTrack> curve7(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(curve7);
          break;
          }
         case ElementType::CURVE8:
          {
          std::shared_ptr<CurvedTrack> curve8(new CurvedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(curve8);
          break;
          }

         case ElementType::BUFFERLEFT:
          {
          std::shared_ptr<LinkedTrack> bufferLeft(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferLeft);
          break;
          }
        case ElementType::BUFFERRIGHT:
          {
          std::shared_ptr<LinkedTrack> bufferRight(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferRight);
          break;
          }
        case ElementType::BUFFERDOWN:
          {
          std::shared_ptr<LinkedTrack> bufferDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferDown);
          break;
          }
        case ElementType::BUFFERUP:
          {
          std::shared_ptr<LinkedTrack> bufferUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferUp);
          break;
          }
         case ElementType::BUFFERLEFTUP:
          {
          std::shared_ptr<LinkedTrack> bufferLeftUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferLeftUp);
          break;
          }
        case ElementType::BUFFERRIGHTUP:
          {
          std::shared_ptr<LinkedTrack> bufferRightUp(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferRightUp);
          break;
          }
        case ElementType::BUFFERLEFTDOWN:
          {
          std::shared_ptr<LinkedTrack> bufferLeftDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferLeftDown);
          break;
          }
        case ElementType::BUFFERRIGHTDOWN:
          {
          std::shared_ptr<LinkedTrack> bufferRightDown(new LinkedTrack(*canvasChosen,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(bufferRightDown);
          break;
          }
         case ElementType::SIGNALLEFT:
          {
          std::shared_ptr<SignalTrack> signalLeft(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalLeft);
          break;
          }
         case ElementType::SIGNALRIGHT:
          {
          std::shared_ptr<SignalTrack> signalRight(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalRight);
          break;
          }
         case ElementType::SIGNALDOWN:
          {
          std::shared_ptr<SignalTrack> signalDown(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalDown);
          break;
          }
         case ElementType::SIGNALUP:
          {
          std::shared_ptr<SignalTrack> signalUp(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalUp);
          break;
          }

         case ElementType::SIGNALLEFTUP:
          {
          std::shared_ptr<SignalTrack> signalLeftUp(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalLeftUp);
          break;
          }
         case ElementType::SIGNALRIGHTUP:
          {
          std::shared_ptr<SignalTrack> signalRightUp(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalRightUp);
          break;
          }

         case ElementType::SIGNALLEFTDOWN:
          {
          std::shared_ptr<SignalTrack> signalLeftDown(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalLeftDown);
          break;
          }
         case ElementType::SIGNALRIGHTDOWN:
          {
          std::shared_ptr<SignalTrack> signalRightDown(new SignalTrack(*canvasChosen,canvasAspect,offsetX,offsetY,finalX,finalY));
          drawnLayout->addElement(signalRightDown);
          break;
          }


         }


         }

         update();


}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (auto& currentElement : drawnLayout->getElementList()){

        if (offsetX==currentElement->getOffsetX() && offsetY ==currentElement->getOffsetY()) {

        switch (currentElement->getElementType()) {

          case ElementType::NONE:

            break;

          case ElementType::STRAIGHTH:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*straightHImage);
            break;

          case ElementType::STRAIGHTV:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*straightVImage);
            break;

          case ElementType::DIRECTLEFT:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directLeftImage);
            break;

          case ElementType::DIRECTRIGHT:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directRightImage);
            break;
          case ElementType::DIRECTUP:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directUpImage);
            break;
          case ElementType::DIRECTDOWN:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directDownImage);
            break;

          case ElementType::STRIAGHTRIGHTUP:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*straightRightUpImage);
            break;

          case ElementType::STRAIGHTLEFTUP:
            painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*straightLeftUpImage);
            break;
        case ElementType::DIRECTRIGHTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directRightUpImage);
          break;
        case ElementType::DIRECTLEFTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directLeftUpImage);
          break;
        case ElementType::DIRECTLEFTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directLeftDownImage);
          break;
        case ElementType::DIRECTRIGHTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*directRightDownIamge);
          break;
        case ElementType::TIGHTCURVE1:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*tightCurve1Image);
          break;

        case ElementType::TIGHTCURVE2:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*tightCurve2Image);
          break;
        case ElementType::TIGHTCURVE3:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*tightCurve3Image);
          break;

        case ElementType::TIGHTCURVE4:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*tightCurve4Image);
          break;
        case ElementType::CURVE1:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve1Image);
          break;

        case ElementType::CURVE2:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve2Image);
          break;
        case ElementType::CURVE3:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve3Image);
          break;

        case ElementType::CURVE4:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve4Image);
          break;

        case ElementType::LINKLEFT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkLeftImage);
          break;

        case ElementType::LINKRIGHT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkRightImage);
          break;
        case ElementType::LINKDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkDownImage);
          break;

        case ElementType::LINKUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkUpImage);
          break;

        case ElementType::LINKLEFTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkLeftUpImage);
          break;

        case ElementType::LINKRIGHTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkRightUpImage);
          break;
        case ElementType::LINKRIGHTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkRightDownImage);
          break;

        case ElementType::LINKLEFTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*linkLeftDownImage);
          break;

        case ElementType::EXITLEFT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitLeftImage);
          break;

        case ElementType::EXITRIGHT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitRightImage);
          break;
        case ElementType::EXITDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitDownImage);
          break;

        case ElementType::EXITUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitUpImage);
          break;

        case ElementType::EXITLEFTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitLeftUpImage);
          break;

        case ElementType::EXITRIGHTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitRightUpImage);
          break;

        case ElementType::EXITLEFTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitLeftDownImage);
          break;

        case ElementType::EXITRIGHTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*exitRightDownImage);
          break;

        case ElementType::CURVE5:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve5Image);
          break;

        case ElementType::CURVE6:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve6Image);
          break;
        case ElementType::CURVE7:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve7Image);
          break;

        case ElementType::CURVE8:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*curve8Image);
          break;

        case ElementType::BUFFERLEFT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferLeftImage);
          break;

        case ElementType::BUFFERRIGHT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferRightImage);
          break;
        case ElementType::BUFFERDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferDownImage);
          break;

        case ElementType::BUFFERUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferUpImage);
          break;

        case ElementType::BUFFERLEFTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferLeftUpImage);
          break;

        case ElementType::BUFFERRIGHTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferRightUpImage);
          break;
        case ElementType::BUFFERLEFTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferLeftDownImage);
          break;

        case ElementType::BUFFERRIGHTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*bufferRightDownImage);
          break;

        case ElementType::SIGNALLEFT:
          currentElement->

          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalLeftImage);
          break;

        case ElementType::SIGNALRIGHT:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalRightImage);
          break;
        case ElementType::SIGNALDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalDownImage);
          break;

        case ElementType::SIGNALUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalUpImage);
          break;

        case ElementType::SIGNALLEFTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalLeftUpImage);
          break;

        case ElementType::SIGNALRIGHTUP:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalRightUpImage);
          break;
        case ElementType::SIGNALLEFTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalLeftDownImage);
          break;

        case ElementType::SIGNALRIGHTDOWN:
          painter.drawImage(currentElement->getLocationX(),currentElement->getLocationY(),*signalRightDownImage);
          break;


        }

        }



    }

}



