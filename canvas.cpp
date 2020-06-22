#include "canvas.h"

Canvas::Canvas()
{

    QPalette pal = palette();
    imageSize = 15;
    // set black background
    drawnLayout = new Map;
    pal.setColor(QPalette::Window, Qt::white);
    canvasSizeX = width();
    canvasSizeY = height();
    //std::cout << canvasSizeX << std::flush;
    //std::cout <<canvasSizeY << std::flush;
    setMouseTracking(true);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);

        scene = new QGraphicsScene;
        setScene(scene);

        //ElementBlock1 images
        straightHImage = new QPixmap(":/graphics/graphics/straightH.png");
        straightVImage = new QPixmap(":/graphics/graphics/straightV.png");
        directLeftImage = new QPixmap(":/graphics/graphics/directLeft.png");
        directRightImage = new QPixmap(":/graphics/graphics/directRight.png");
        directUpImage = new QPixmap(":/graphics/graphics/directUp.png");
        directDownImage = new QPixmap(":/graphics/graphics/directDown.png");
        straightLeftUpImage = new QPixmap(":/graphics/graphics/straightLeftUp.png");
        straightRightUpImage = new QPixmap(":/graphics/graphics/straightRightUp.png");
        directLeftUpImage = new QPixmap(":/graphics/graphics/directLeftUp.png");
        directRightUpImage = new QPixmap(":/graphics/graphics/directRightUp.png");
        directRightDownIamge = new QPixmap(":/graphics/graphics/directRightDown.png");
        directLeftDownImage = new QPixmap(":/graphics/graphics/directLeftDown.png");
        tightCurve1Image = new QPixmap(":/graphics/graphics/tightCurve1.png");
        tightCurve2Image = new QPixmap(":/graphics/graphics/tightCurve2.png");
        tightCurve3Image = new QPixmap(":/graphics/graphics/tightCurve3.png");
        tightCurve4Image = new QPixmap(":/graphics/graphics/tightCurve4.png");
        curve1Image = new QPixmap(":/graphics/graphics/curve1.png");
        curve2Image = new QPixmap(":/graphics/graphics/curve2.png");
        curve3Image = new QPixmap(":/graphics/graphics/curve3.png");
        curve4Image = new QPixmap(":/graphics/graphics/curve4.png");

        linkLeftImage = new QPixmap(":/graphics/graphics/linkLeftUnset.png");
        linkRightImage = new QPixmap(":/graphics/graphics/linkRightUnset.png");
        linkDownImage = new QPixmap(":/graphics/graphics/linkDownUnset.png");
        linkUpImage = new QPixmap(":/graphics/graphics/linkUpUnset.png");
        linkLeftUpImage = new QPixmap(":/graphics/graphics/linkLeftUpUnset.png");
        linkRightUpImage = new QPixmap(":/graphics/graphics/linkRightUpUnset.png");
        linkRightDownImage = new QPixmap(":/graphics/graphics/linkRightDownUnset.png");
        linkLeftDownImage = new QPixmap(":/graphics/graphics/linkLeftDownUnset.png");
        exitLeftImage = new QPixmap(":/graphics/graphics/exitLeft.png");
        exitRightImage = new QPixmap(":/graphics/graphics/exitRight.png");
        exitDownImage = new QPixmap(":/graphics/graphics/exitDown.png");
        exitUpImage = new QPixmap(":/graphics/graphics/exitUp.png");
        exitLeftUpImage = new QPixmap(":/graphics/graphics/exitLeftUp.png");
        exitRightUpImage = new QPixmap(":/graphics/graphics/exitRightUp.png");
        exitLeftDownImage = new QPixmap(":/graphics/graphics/exitLeftDown.png");
        exitRightDownImage = new QPixmap(":/graphics/graphics/exitRightDown.png");
        curve5Image = new QPixmap(":/graphics/graphics/curve5.png");
        curve6Image = new QPixmap(":/graphics/graphics/curve6.png");
        curve7Image = new QPixmap(":/graphics/graphics/curve7.png");
        curve8Image = new QPixmap(":/graphics/graphics/curve8.png");

        bufferLeftImage = new QPixmap(":/graphics/graphics/bufferLeft.png");
        bufferRightImage = new QPixmap(":/graphics/graphics/bufferRight.png");
        bufferDownImage = new QPixmap(":/graphics/graphics/bufferDown.png");
        bufferUpImage = new QPixmap(":/graphics/graphics/bufferUp.png");
        bufferLeftUpImage = new QPixmap(":/graphics/graphics/bufferLeftUp.png");
        bufferRightUpImage = new QPixmap(":/graphics/graphics/bufferRightUp.png");
        bufferLeftDownImage = new QPixmap(":/graphics/graphics/bufferLeftDown.png");
        bufferRightDownImage = new QPixmap(":/graphics/graphics/bufferRightDown.png");
        signalLeftImage = new QPixmap(":/graphics/graphics/signalLeft.png");
        signalRightImage = new QPixmap(":/graphics/graphics/signalRight.png");
        signalDownImage = new QPixmap(":/graphics/graphics/signalDown.png");
        signalUpImage = new QPixmap(":/graphics/graphics/signalUp.png");
        signalLeftUpImage = new QPixmap(":/graphics/graphics/signalLeftUp.png");
        signalRightUpImage = new QPixmap(":/graphics/graphics/signalRightUp.png");
        signalLeftDownImage = new QPixmap(":/graphics/graphics/signalLeftDown.png");
        signalRightDownImage = new QPixmap(":/graphics/graphics/signalRightDown.png");
        shuntLeftImage = new QPixmap(":/graphics/graphics/shuntLeftRed.png");
        shuntRightImage = new QPixmap(":/graphics/graphics/shuntRightRed.png");
        shuntDownImage = new QPixmap(":/graphics/graphics/shuntDownRed.png");
        shuntUpImage = new QPixmap(":/graphics/graphics/shuntUpRed.png");
        shuntLeftUpImage = new QPixmap(":/graphics/graphics/shuntLeftUpRed.png");
        shuntRightUpImage = new QPixmap(":/graphics/graphics/shuntRightUpRed.png");
        shuntLeftDownImage = new QPixmap(":/graphics/graphics/shuntLeftDownRed.png");
        shuntRightDownImage = new QPixmap(":/graphics/graphics/shuntRightDownRed.png");
    bridgeUnset1Image = new QPixmap(":/graphics/graphics/bridgeUnset1.png");
    bridgeUnset2Image = new QPixmap(":/graphics/graphics/bridgeUnset2.png");
    underpassUnset1Image = new QPixmap(":/graphics/graphics/underpassUnset1.png");
    underpassUnset2Image = new QPixmap(":/graphics/graphics/underpassUnset2.png");
    bridgeSet1Image = new QPixmap(":/graphics/graphics/brdigeSet1.png");
    bridgeSet2Image = new QPixmap(":/graphics/graphics/bridgeSet2.png");
    underpassSet1Image = new QPixmap(":/graphics/graphics/underpassSet1.png");
    underpassSet2Image = new QPixmap(":/graphics/graphics/underpassSet2.png");

    //ElementBlock2 images
    switchTight1Image = new QPixmap(":/graphics/graphics/switchTight1.png");
    switchTight2Image = new QPixmap(":/graphics/graphics/switchTight2.png");
    switchTight3Image = new QPixmap(":/graphics/graphics/switchTight3.png");
    switchTight4Image = new QPixmap(":/graphics/graphics/switchTight4.png");
    switchTight5Image = new QPixmap(":/graphics/graphics/switchTight5.png");
    switchTight6Image = new QPixmap(":/graphics/graphics/switchTight6.png");
    switchTight7Image = new QPixmap(":/graphics/graphics/switchTight7.png");
    switchTight8Image = new QPixmap(":/graphics/graphics/switchTight8.png");
    switchSplit1Image = new QPixmap(":/graphics/graphics/switchSplit1.png");
    switchSplit2Image = new QPixmap(":/graphics/graphics/switchSplit2.png");
    switchSplit3Image = new QPixmap(":/graphics/graphics/switchSplit3.png");

    switch1Image = new QPixmap(":/graphics/graphics/switch1.png");
    switch2Image = new QPixmap(":/graphics/graphics/switch2.png");
    switch3Image = new QPixmap(":/graphics/graphics/switch3.png");
    switch4Image = new QPixmap(":/graphics/graphics/switch4.png");
    switch5Image = new QPixmap(":/graphics/graphics/switch5.png");
    switch6Image = new QPixmap(":/graphics/graphics/switch6.png");
    switch7Image = new QPixmap(":/graphics/graphics/switch7.png");
    switch8Image = new QPixmap(":/graphics/graphics/switch8.png");
    switchSplit4Image = new QPixmap(":/graphics/graphics/switchSplit4.png");
    switchSplit5Image = new QPixmap(":/graphics/graphics/switchSplit5.png");
    switchSplit6Image = new QPixmap(":/graphics/graphics/switchSplit6.png");

    switch9Image = new QPixmap(":/graphics/graphics/switch9.png");
    switch10Image = new QPixmap(":/graphics/graphics/switch10.png");
    switch11Image = new QPixmap(":/graphics/graphics/switch11.png");
    switch12Image = new QPixmap(":/graphics/graphics/switch12.png");
    switch13Image = new QPixmap(":/graphics/graphics/switch13.png");
    switch14Image = new QPixmap(":/graphics/graphics/switch14.png");
    switch15Image = new QPixmap(":/graphics/graphics/switch15.png");
    switch16Image = new QPixmap(":/graphics/graphics/switch16.png");
    switchSplit7Image = new QPixmap(":/graphics/graphics/switchSplit7.png");
    switchSplit8Image = new QPixmap(":/graphics/graphics/switchSplit8.png");

    //ElementBlock3 images
    crossover1Image = new QPixmap(":/graphics/graphics/crossover1.png");
    crossover2Image = new QPixmap(":/graphics/graphics/crossover2.png");
    flyover1Image = new QPixmap(":/graphics/graphics/flyover1.png");
    flyover2Image = new QPixmap(":/graphics/graphics/flyover2.png");
    flyover3Image = new QPixmap(":/graphics/graphics/flyover3.png");
    flyover4Image = new QPixmap(":/graphics/graphics/flyover4.png");

    crossover3Image = new QPixmap(":/graphics/graphics/crossover3.png");
    crossover4Image = new QPixmap(":/graphics/graphics/crossover4.png");
    flyover5Image = new QPixmap(":/graphics/graphics/flyover5.png");
    flyover6Image = new QPixmap(":/graphics/graphics/flyover6.png");
    flyover7Image = new QPixmap(":/graphics/graphics/flyover7.png");
    flyover8Image = new QPixmap(":/graphics/graphics/flyover8.png");

    crossover5Image = new QPixmap(":/graphics/graphics/crossover5.png");
    crossover6Image = new QPixmap(":/graphics/graphics/crossover6.png");
    flyover9Image = new QPixmap(":/graphics/graphics/flyover9.png");
    flyover10Image = new QPixmap(":/graphics/graphics/flyover10.png");
    flyover11Image = new QPixmap(":/graphics/graphics/flyover11.png");
    flyover12Image = new QPixmap(":/graphics/graphics/flyover12.png");

    //ElementBlock4 images
    namedLocationUnsetImage = new QPixmap(":/graphics/graphics/namedLocationUnset.png");
    namedLocationSetImage = new QPixmap(":/graphics/graphics/namedLocationSet.png");
    concourseUnsetImage = new QPixmap(":/graphics/graphics/concourseUnset.png");
    concourseSetImage = new QPixmap(":/graphics/graphics/concourseSet.png");
    platformDownUnsetImage = new QPixmap(":/graphics/graphics/platformDownUnset.png");
    platformDownSetImage = new QPixmap(":/graphics/graphics/platformDownSet.png");
    platformUpUnsetImage = new QPixmap(":/graphics/graphics/platformUpUnset.png");
    platformUpSetImage = new QPixmap(":/graphics/graphics/platformUpSet.png");
    platformLeftUnsetImage = new QPixmap(":/graphics/graphics/platformLeftUnset.png");
    platformLeftSetImage = new QPixmap(":/graphics/graphics/platformLeftSet.png");
    platformRightUnsetImage = new QPixmap(":/graphics/graphics/platformRightUnset.png");
    platformRightSetImage = new QPixmap(":/graphics/graphics/platformRightSet.png");

    //ElementBlock5 images
    parapet1Image = new QPixmap(":/graphics/graphics/parapet1.png");
    parapet2Image = new QPixmap(":/graphics/graphics/parapet2.png");
    parapet3Image = new QPixmap(":/graphics/graphics/parapet3.png");
    parapet4Image = new QPixmap(":/graphics/graphics/parapet4.png");
    parapet5Image = new QPixmap(":/graphics/graphics/parapet5.png");
    parapet6Image = new QPixmap(":/graphics/graphics/parapet6.png");
    parapet7Image = new QPixmap(":/graphics/graphics/parapet7.png");
    parapet8Image = new QPixmap(":/graphics/graphics/parapet8.png");
    parapet9Image = new QPixmap(":/graphics/graphics/parapet9.png");
    parapet10Image = new QPixmap(":/graphics/graphics/parapet10.png");

    parapet11Image = new QPixmap(":/graphics/graphics/parapet11.png");
    parapet12Image = new QPixmap(":/graphics/graphics/parapet12.png");
    parapet13Image = new QPixmap(":/graphics/graphics/parapet13.png");
    parapet14Image = new QPixmap(":/graphics/graphics/parapet14.png");
    parapet15Image = new QPixmap(":/graphics/graphics/parapet15.png");
    parapet16Image = new QPixmap(":/graphics/graphics/parapet16.png");
    parapet17Image = new QPixmap(":/graphics/graphics/parapet17.png");
    parapet18Image = new QPixmap(":/graphics/graphics/parapet18.png");
    parapet19Image = new QPixmap(":/graphics/graphics/parapet19.png");
    parapet20Image = new QPixmap(":/graphics/graphics/parapet20.png");

    parapet21Image = new QPixmap(":/graphics/graphics/parapet21.png");
    parapet22Image = new QPixmap(":/graphics/graphics/parapet22.png");
    parapet23Image = new QPixmap(":/graphics/graphics/parapet23.png");
    parapet24Image = new QPixmap(":/graphics/graphics/parapet24.png");
    parapet25Image = new QPixmap(":/graphics/graphics/parapet25.png");
    parapet26Image = new QPixmap(":/graphics/graphics/parapet26.png");
    parapet27Image = new QPixmap(":/graphics/graphics/parapet27.png");
    parapet28Image = new QPixmap(":/graphics/graphics/parapet28.png");

    //ElementBlock6Image
    levelCrossingHImage = new QPixmap(":/graphics/graphics/levelCrossingH.png");
    levelCrossingVImage = new QPixmap(":/graphics/graphics/levelCrossingV.png");

    setAutoFillBackground(true);
    setPalette(pal);
}

ElementType Canvas::getElementType()
{
    return *canvasChosen;
}

void Canvas::setElementType(ElementType& newChosen)
{
    canvasChosen = &newChosen;
}

Map Canvas::getMap()
{
    return *drawnLayout;
}

void Canvas::setMap(Map& map)
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

void Canvas::setOffsetX(int& newOffsetX)
{
    offsetX = newOffsetX;
}

int Canvas::getOffsetY() const
{
    return offsetY;
}

void Canvas::setOffsetY(int& newOffsetY)
{
    offsetY = newOffsetY;
}

int Canvas::getAspect() const
{
    return canvasAspect;
}

void Canvas::setAspect(int& newAspect)
{
    canvasAspect = newAspect;
}

bool Canvas::getCanvasShowTrackID() const
{
    return canvasShowTrackID;
}

void Canvas::setCanvasShowTrackID(bool &newShowTrackID)
{
    canvasShowTrackID = newShowTrackID;
}

bool Canvas::getCanvasShowMoreTrackInfo() const
{
    return canvasShowMoreTrackInfo;
}

void Canvas::setCanvasShowMoreTrackInfo(bool &newShowMoreTrackInfo)
{
    canvasShowMoreTrackInfo = newShowMoreTrackInfo;
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
    //Get size of the current Canvas Widget.
    canvasSizeX = width();
    canvasSizeY = height();
    //Getlocation of click.
    int exactX = event->pos().x();
    int exactY = event->pos().y();
    //Find out how close it is to the nearest 16 (which is the image size)
    int extraX = exactX % 16;
    int extraY = exactY % 16;

    int roundedX = exactX - extraX;
    int roundedY = exactY - extraY;
    //Calculate overall coordinate
    int finalX = ((roundedX + (offsetX*canvasSizeX))/16);
    int finalY;
    if (offsetY==0)
    {
        finalY = 0 - ((roundedY+ (offsetY*canvasSizeY))/16);
    } else if (offsetY<0 || offsetY >0) {
        finalY = 0 - (roundedY- (offsetY*canvasSizeY))/16;
    }

    if (event->button() == Qt::LeftButton) {
        switch (*canvasChosen)
        {
            case ElementType::NONE:
            {
                QMessageBox noELementSelected;
                noELementSelected.setIcon(QMessageBox::Critical);
                noELementSelected.setText("No element has been selected.");
                noELementSelected.exec();
                break;
            }
            case ElementType::STRAIGHTH:
            {
                std::shared_ptr<StraightTrack> straightH(new StraightTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addStraightTrack(straightH);
                break;
            }
            case ElementType::STRAIGHTV:
            {
                std::shared_ptr<StraightTrack> straightV(new StraightTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addStraightTrack(straightV);
                break;
            }
            case ElementType::DIRECTLEFT:
            {
                std::shared_ptr<DirectTrack> directLeft(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directLeft);
                break;
            }
            case ElementType::DIRECTRIGHT:
            {
                std::shared_ptr<DirectTrack> directRight(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directRight);
                break;
            }
            case ElementType::DIRECTUP:
            {
                std::shared_ptr<DirectTrack> directUp(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directUp);
                break;
            }
            case ElementType::DIRECTDOWN:
            {
                std::shared_ptr<DirectTrack> directDown(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directDown);
                break;
            }
            case ElementType::STRIAGHTRIGHTUP:
            {
                std::shared_ptr<StraightTrack> straightRightUp(new StraightTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addStraightTrack(straightRightUp);
                break;
            }
            case ElementType::STRAIGHTLEFTUP:
            {
                std::shared_ptr<StraightTrack> straightLeftUp(new StraightTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addStraightTrack(straightLeftUp);
                break;
            }
            case ElementType::DIRECTRIGHTUP:
            {
                std::shared_ptr<DirectTrack> directRightUp(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directRightUp);
                break;
            }
            case ElementType::DIRECTLEFTUP:
            {
                std::shared_ptr<DirectTrack> directLeftUp(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directLeftUp);
                break;
            }
            case ElementType::DIRECTLEFTDOWN:
            {
                std::shared_ptr<DirectTrack> directLeftDown(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directLeftDown);
                break;
            }
            case ElementType::DIRECTRIGHTDOWN:
            {
                std::shared_ptr<DirectTrack> directRightDown(new DirectTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addDirectTrack(directRightDown);
                break;
            }

            case ElementType::TIGHTCURVE1:
            {
                std::shared_ptr<CurvedTrack> tightCurve1(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve1);
                break;
            }
            case ElementType::TIGHTCURVE2:
            {
                std::shared_ptr<CurvedTrack> tightCurve2(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve2);
                break;
            }
            case ElementType::TIGHTCURVE3:
            {
                std::shared_ptr<CurvedTrack> tightCurve3(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve3);
                break;
            }
            case ElementType::TIGHTCURVE4:
            {
                std::shared_ptr<CurvedTrack> tightCurve4(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve4);
                break;
            }
            case ElementType::CURVE1:
            {
                std::shared_ptr<CurvedTrack> curve1(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve1);
                break;
            }
            case ElementType::CURVE2:
            {
                std::shared_ptr<CurvedTrack> curve2(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve2);
                break;
            }
            case ElementType::CURVE3:
            {
                std::shared_ptr<CurvedTrack> curve3(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve3);
                break;
            }
            case ElementType::CURVE4:
            {
                std::shared_ptr<CurvedTrack> curve4(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve4);
                break;
            }
            case ElementType::LINKLEFT:
            {
                std::shared_ptr<LinkedTrack> linkLeft(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkLeft);
                break;
            }
            case ElementType::LINKRIGHT:
            {
                std::shared_ptr<LinkedTrack> linkRight(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkRight);
                break;
            }
            case ElementType::LINKDOWN:
            {
                std::shared_ptr<LinkedTrack> linkDown(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkDown);
                break;
            }
            case ElementType::LINKUP:
            {
                std::shared_ptr<LinkedTrack> linkUp(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkUp);
                break;
            }
            case ElementType::LINKLEFTUP:
            {
                std::shared_ptr<LinkedTrack> linkLeftUp(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkLeftUp);
                break;
            }
            case ElementType::LINKRIGHTUP:
            {
                std::shared_ptr<LinkedTrack> linkRightUp(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkRightUp);
                break;
            }
            case ElementType::LINKRIGHTDOWN:
            {
                std::shared_ptr<LinkedTrack> linkRightDown(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkRightDown);
                break;
            }
            case ElementType::LINKLEFTDOWN:
            {
                std::shared_ptr<LinkedTrack> linkLeftDown(new LinkedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addLinkedTrack(linkLeftDown);
                break;
            }
            case ElementType::EXITLEFT:
            {
                std::shared_ptr<ExitTrack> exitLeft(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitLeft);
                break;
            }
            case ElementType::EXITRIGHT:
            {
                std::shared_ptr<ExitTrack> exitRight(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitRight);
                break;
            }
            case ElementType::EXITDOWN:
            {
                std::shared_ptr<ExitTrack> exitDown(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitDown);
                break;
            }
            case ElementType::EXITUP:
            {
                std::shared_ptr<ExitTrack> exitUp(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitUp);
                break;
            }
            case ElementType::EXITLEFTUP:
            {
                std::shared_ptr<ExitTrack> exitLeftUp(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitLeftUp);
                break;
            }
            case ElementType::EXITRIGHTUP:
            {
                std::shared_ptr<ExitTrack> exitRightUp(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitRightUp);
                break;
            }

            case ElementType::EXITLEFTDOWN:
            {
                std::shared_ptr<ExitTrack> exitLeftDown(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitLeftDown);
                break;
            }
            case ElementType::EXITRIGHTDOWN:
            {
                std::shared_ptr<ExitTrack> exitRightDown(new ExitTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addExitTrack(exitRightDown);
                break;
            }
            case ElementType::CURVE5:
            {
                std::shared_ptr<CurvedTrack> curve5(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve5);
                break;
            }
            case ElementType::CURVE6:
            {
                std::shared_ptr<CurvedTrack> curve6(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve6);
                break;
            }
            case ElementType::CURVE7:
            {
                std::shared_ptr<CurvedTrack> curve7(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve7);
                break;
            }
            case ElementType::CURVE8:
            {
                std::shared_ptr<CurvedTrack> curve8(new CurvedTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCurvedTrack(curve8);
                break;
            }
            case ElementType::BUFFERLEFT:
            {
                std::shared_ptr<BufferTrack> bufferLeft(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferLeft);
                break;
            }
            case ElementType::BUFFERRIGHT:
            {
                std::shared_ptr<BufferTrack> bufferRight(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferRight);
                break;
            }
            case ElementType::BUFFERDOWN:
            {
                std::shared_ptr<BufferTrack> bufferDown(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferDown);
                break;
            }
            case ElementType::BUFFERUP:
            {
                std::shared_ptr<BufferTrack> bufferUp(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferUp);
                break;
            }
            case ElementType::BUFFERLEFTUP:
            {
                std::shared_ptr<BufferTrack> bufferLeftUp(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferLeftUp);
                break;
            }
            case ElementType::BUFFERRIGHTUP:
            {
                std::shared_ptr<BufferTrack> bufferRightUp(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferRightUp);
                break;
            }
            case ElementType::BUFFERLEFTDOWN:
            {
                std::shared_ptr<BufferTrack> bufferLeftDown(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferLeftDown);
                break;
            }
            case ElementType::BUFFERRIGHTDOWN:
            {
                std::shared_ptr<BufferTrack> bufferRightDown(new BufferTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBufferTrack(bufferRightDown);
                break;
            }
            case ElementType::SIGNALLEFT:
            {
                std::shared_ptr<SignalTrack> signalLeft(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalLeft);
                break;
            }
            case ElementType::SIGNALRIGHT:
            {
                std::shared_ptr<SignalTrack> signalRight(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalRight);
                break;
            }
            case ElementType::SIGNALDOWN:
            {
                std::shared_ptr<SignalTrack> signalDown(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalDown);
                break;
            }
            case ElementType::SIGNALUP:
            {
                std::shared_ptr<SignalTrack> signalUp(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalUp);
                break;
            }
            case ElementType::SIGNALLEFTUP:
            {
                std::shared_ptr<SignalTrack> signalLeftUp(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalLeftUp);
                break;
            }
            case ElementType::SIGNALRIGHTUP:
            {
                std::shared_ptr<SignalTrack> signalRightUp(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalRightUp);
                break;
            }
            case ElementType::SIGNALLEFTDOWN:
            {
                std::shared_ptr<SignalTrack> signalLeftDown(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalLeftDown);
                break;
            }
            case ElementType::SIGNALRIGHTDOWN:
            {
                std::shared_ptr<SignalTrack> signalRightDown(new SignalTrack(*canvasChosen, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalRightDown);
                break;
            }
            case ElementType::BRIDGE1:
            {
                std::shared_ptr<BridgeUnderpassTrack> bridge1(new BridgeUnderpassTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(bridge1);
                break;
            }
            case ElementType::BRIDGE2:
            {
                std::shared_ptr<BridgeUnderpassTrack> bridge2(new BridgeUnderpassTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(bridge2);
                break;
            }
            case ElementType::UNDERPASS1:
            {
                std::shared_ptr<BridgeUnderpassTrack> underpass1(new BridgeUnderpassTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(underpass1);
                break;
            }
            case ElementType::UNDERPASS2:
            {
                std::shared_ptr<BridgeUnderpassTrack> underpass2(new BridgeUnderpassTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(underpass2);
                break;
            }
            case ElementType::SWITCHTIGHT1:
            {
                std::shared_ptr<SwitchTrack> switchTight1(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight1);
                break;
            }
            case ElementType::SWITCHTIGHT2:
            {
                std::shared_ptr<SwitchTrack> switchTight2(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight2);
                break;
            }
            case ElementType::SWITCHTIGHT3:
            {
                std::shared_ptr<SwitchTrack> switchTight3(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight3);
                break;
            }
            case ElementType::SWITCHTIGHT4:
            {
                std::shared_ptr<SwitchTrack> switchTight4(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight4);
                break;
            }
            case ElementType::SWITCHTIGHT5:
            {
                std::shared_ptr<SwitchTrack> switchTight5(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight5);
                break;
            }
            case ElementType::SWITCHTIGHT6:
            {
                std::shared_ptr<SwitchTrack> switchTight6(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight6);
                break;
            }
            case ElementType::SWITCHTIGHT7:
            {
                std::shared_ptr<SwitchTrack> switchTight7(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight7);
                break;
            }
            case ElementType::SWITCHTIGHT8:
            {
                std::shared_ptr<SwitchTrack> switchTight8(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight8);
                break;
            }
            case ElementType::SWITCHSPLIT1:
            {
                std::shared_ptr<SwitchTrack> switchSplit1(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit1);
                break;
            }
            case ElementType::SWITCHSPLIT2:
            {
                std::shared_ptr<SwitchTrack> switchSplit2(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit2);
                break;
            }
            case ElementType::SWITCHSPLIT3:
            {
                std::shared_ptr<SwitchTrack> switchSplit3(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit3);
                break;
            }
            case ElementType::SWITCH1:
            {
                std::shared_ptr<SwitchTrack> switch1(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch1);
                break;
            }
            case ElementType::SWITCH2:
            {
                std::shared_ptr<SwitchTrack> switch2(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch2);
                break;
            }
            case ElementType::SWITCH3:
            {
                std::shared_ptr<SwitchTrack> switch3(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch3);
                break;
            }
            case ElementType::SWITCH4:
            {
                std::shared_ptr<SwitchTrack> switch4(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch4);
                break;
            }
            case ElementType::SWITCH5:
            {
                std::shared_ptr<SwitchTrack> switch5(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch5);
                break;
            }
            case ElementType::SWITCH6:
            {
                std::shared_ptr<SwitchTrack> switch6(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch6);
                break;
            }
            case ElementType::SWITCH7:
            {
                std::shared_ptr<SwitchTrack> switch7(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch7);
                break;
            }
            case ElementType::SWITCH8:
            {
                std::shared_ptr<SwitchTrack> switch8(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch8);
                break;
            }
            case ElementType::SWITCHSPLIT4:
            {
                std::shared_ptr<SwitchTrack> switchSplit4(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit4);
                break;
            }
            case ElementType::SWITCHSPLIT5:
            {
                std::shared_ptr<SwitchTrack> switchSplit4(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit4);
                break;
            }
            case ElementType::SWITCHSPLIT6:
            {
                std::shared_ptr<SwitchTrack> switchSplit5(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit5);
                break;
            }
            case ElementType::SWITCH9:
            {
                std::shared_ptr<SwitchTrack> switch9(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch9);
                break;
            }
            case ElementType::SWITCH10:
            {
                std::shared_ptr<SwitchTrack> switch10(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch10);
                break;
            }
            case ElementType::SWITCH11:
            {
                std::shared_ptr<SwitchTrack> switch11(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch11);
                break;
            }
            case ElementType::SWITCH12:
            {
                std::shared_ptr<SwitchTrack> switch12(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch12);
                break;
            }
            case ElementType::SWITCH13:
            {
                std::shared_ptr<SwitchTrack> switch13(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch13);
                break;
            }
            case ElementType::SWITCH14:
            {
                std::shared_ptr<SwitchTrack> switch14(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch14);
                break;
            }
            case ElementType::SWITCH15:
            {
                std::shared_ptr<SwitchTrack> switch15(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch15);
                break;
            }
            case ElementType::SWITCH16:
            {
                std::shared_ptr<SwitchTrack> switch16(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switch16);
                break;
            }
            case ElementType::SWITCHSPLIT7:
            {
                std::shared_ptr<SwitchTrack> switchSplit7(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit7);
                break;
            }
            case ElementType::SWITCHSPLIT8:
            {
                std::shared_ptr<SwitchTrack> switchSplit8(new SwitchTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit8);
                break;
            }
            case ElementType::CROSSOVER1:
            {
                std::shared_ptr<CrossoverTrack> crossover1(new CrossoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover1);
                break;
            }
            case ElementType::CROSSOVER2:
            {
                std::shared_ptr<CrossoverTrack> crossover2(new CrossoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover2);
                break;
            }
            case ElementType::FLYOVER1:
            {
                std::shared_ptr<FlyoverTrack> flyover1(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover1);
                break;
            }
            case ElementType::FLYOVER2:
            {
                std::shared_ptr<FlyoverTrack> flyover2(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover2);
                break;
            }
            case ElementType::FLYOVER3:
            {
                std::shared_ptr<FlyoverTrack> flyover3(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover3);
                break;
            }
            case ElementType::FLYOVER4:
            {
                std::shared_ptr<FlyoverTrack> flyover4(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover4);
                break;
            }
            case ElementType::CROSSOVER3:
            {
                std::shared_ptr<CrossoverTrack> crossover3(new CrossoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover3);
                break;
            }
            case ElementType::CROSSOVER4:
            {
                std::shared_ptr<CrossoverTrack> crossover4(new CrossoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover4);
                break;
            }
            case ElementType::FLYOVER5:
            {
                std::shared_ptr<FlyoverTrack> flyover5(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover5);
                break;
            }
            case ElementType::FLYOVER6:
            {
                std::shared_ptr<FlyoverTrack> flyover6(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover6);
                break;
            }
            case ElementType::FLYOVER7:
            {
                std::shared_ptr<FlyoverTrack> flyover7(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover7);
                break;
            }
            case ElementType::FLYOVER8:
            {
                std::shared_ptr<FlyoverTrack> flyover8(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover8);
                break;
            }
            case ElementType::CROSSOVER5:
            {
                std::shared_ptr<CrossoverTrack> crossover5(new CrossoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover5);
                break;
            }
            case ElementType::CROSSOVER6:
            {
                std::shared_ptr<CrossoverTrack> crossover6(new CrossoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover6);
                break;
            }
            case ElementType::FLYOVER9:
            {
                std::shared_ptr<FlyoverTrack> flyover9(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover9);
                break;
            }
            case ElementType::FLYOVER10:
            {
                std::shared_ptr<FlyoverTrack> flyover10(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover10);
                break;
            }
            case ElementType::FLYOVER11:
            {
                std::shared_ptr<FlyoverTrack> flyover11(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover11);
                break;
            }
            case ElementType::FLYOVER12:
            {
                std::shared_ptr<FlyoverTrack> flyover12(new FlyoverTrack(*canvasChosen, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover12);
                break;
            }
            case ElementType::NAMEDLOCATION:
            {
                std::shared_ptr<NamedLocation> namedLocation(new NamedLocation(*canvasChosen, finalX, finalY));
                drawnLayout->addNamedLocation(namedLocation);
                break;
            }
            case ElementType::CONCOURSE:
            {
                std::shared_ptr<Concourse> concourse(new Concourse(*canvasChosen, finalX, finalY));
                drawnLayout->addConcourse(concourse);
                break;
            }
            case ElementType::PLATFORMUP:
            {
                drawnLayout->addPlatform(Platform::UP, finalX, finalY);
                break;
            }
            case ElementType::PLATFORMDOWN:
            {
                drawnLayout->addPlatform(Platform::DOWN, finalX, finalY);
                break;
            }
            case ElementType::PLATFORMLEFT:
            {
                drawnLayout->addPlatform(Platform::LEFT, finalX, finalY);
                break;
            }
            case ElementType::PLATFORMRIGHT:
            {
                drawnLayout->addPlatform(Platform::RIGHT, finalX, finalY);
                break;
            }
            case ElementType::PARAPET1:
            {
                std::shared_ptr<Parapet> parapet1(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet1);
                break;
            }
            case ElementType::PARAPET2:
            {
                std::shared_ptr<Parapet> parapet2(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet2);
                break;
            }
            case ElementType::PARAPET3:
            {
                std::shared_ptr<Parapet> parapet3(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet3);
                break;
            }
            case ElementType::PARAPET4:
            {
                std::shared_ptr<Parapet> parapet4(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet4);
                break;
            }
            case ElementType::PARAPET5:
            {
                std::shared_ptr<Parapet> parapet5(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet5);
                break;
            }
            case ElementType::PARAPET6:
            {
                std::shared_ptr<Parapet> parapet6(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet6);
                break;
            }
            case ElementType::PARAPET7:
            {
                std::shared_ptr<Parapet> parapet7(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet7);
                break;
            }
            case ElementType::PARAPET8:
            {
                std::shared_ptr<Parapet> parapet8(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet8);
                break;
            }
            case ElementType::PARAPET9:
            {
                std::shared_ptr<Parapet> parapet9(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet9);
                break;
            }
            case ElementType::PARAPET10:
            {
                std::shared_ptr<Parapet> parapet10(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet10);
                break;
            }
            case ElementType::PARAPET11:
            {
                std::shared_ptr<Parapet> parapet11(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet11);
                break;
            }
            case ElementType::PARAPET12:
            {
                std::shared_ptr<Parapet> parapet12(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet12);
                break;
            }
            case ElementType::PARAPET13:
            {
                std::shared_ptr<Parapet> parapet13(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet13);
                break;
            }
            case ElementType::PARAPET14:
            {
                std::shared_ptr<Parapet> parapet14(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet14);
                break;
            }
            case ElementType::PARAPET15:
            {
                std::shared_ptr<Parapet> parapet15(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet15);
                break;
            }
            case ElementType::PARAPET16:
            {
                std::shared_ptr<Parapet> parapet16(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet16);
                break;
            }
            case ElementType::PARAPET17:
            {
                std::shared_ptr<Parapet> parapet17(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet17);
                break;
            }
            case ElementType::PARAPET18:
            {
                std::shared_ptr<Parapet> parapet18(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet18);
                break;
            }
            case ElementType::PARAPET19:
            {
                std::shared_ptr<Parapet> parapet19(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet19);
                break;
            }
            case ElementType::PARAPET20:
            {
                std::shared_ptr<Parapet> parapet20(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet20);
                break;
            }
            case ElementType::PARAPET21:
            {
                std::shared_ptr<Parapet> parapet21(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet21);
                break;
            }
            case ElementType::PARAPET22:
            {
                std::shared_ptr<Parapet> parapet22(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet22);
                break;
            }
            case ElementType::PARAPET23:
            {
                std::shared_ptr<Parapet> parapet23(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet23);
                break;
            }
            case ElementType::PARAPET24:
            {
                std::shared_ptr<Parapet> parapet24(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet24);
                break;
            }
            case ElementType::PARAPET25:
            {
                std::shared_ptr<Parapet> parapet25(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet25);
                break;
            }
            case ElementType::PARAPET26:
            {
                std::shared_ptr<Parapet> parapet26(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet26);
                break;
            }
            case ElementType::PARAPET27:
            {
                std::shared_ptr<Parapet> parapet27(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet27);
                break;
            }
            case ElementType::PARAPET28:
            {
                std::shared_ptr<Parapet> parapet28(new Parapet(*canvasChosen, finalX, finalY));
                drawnLayout->addParapet(parapet28);
                break;
            }
            case ElementType::LEVELCROSSING:
            {
                drawnLayout->addLevelCrossing(finalX, finalY);
                break;
            }
            case ElementType::ADDCHANGETEXT:
            {
                bool ok;
                QString readableBit = QInputDialog::getText(this, tr("Add text"), tr("Enter text:"), QLineEdit::Normal, tr(""), &ok);
                std::shared_ptr<Text> text(new Text(*canvasChosen, finalX, finalY, readableBit));
                drawnLayout->addText(text);
            }
        };
    }
    else if (event->button() == Qt::RightButton)
    {
        drawnLayout->deleteElement(finalX, finalY);
        update();
    }
}
void Canvas::paintEvent(QPaintEvent* event)
{
    canvasSizeX = width();
    canvasSizeY = height();
    QPainter painter(this);
    //painter.drawImage(0, 704, *straightHImage);
    for (std::shared_ptr<StraightTrack> currentElement : drawnLayout->getStraightTrackList())
    {
        //Get the stored location of track relative to the canvas widget.
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();

        //Find the area you want to output, by using the offset and the size of the canvas widget.
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;

        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);

        //Find the location on the canvas where you will draw
        if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
        {
            if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::STRAIGHTH:

                        painter.drawImage(displayX, displayY, *straightHImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        if (currentElement->hasLevelCrossing())
                        {
                            painter.drawImage(displayX, displayY, *levelCrossingHImage);
                        }
                        break;

                    case ElementType::STRAIGHTV:
                        painter.drawImage(displayX, displayY, *straightVImage);
                        if (currentElement->getPlatform1() == true)
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2() == true)
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        if (currentElement->hasLevelCrossing())
                        {
                            painter.drawImage(displayX, displayY, *levelCrossingVImage);
                        }
                        break;

                    case ElementType::STRIAGHTRIGHTUP:
                        painter.drawImage(displayX, displayY, *straightRightUpImage);
                        break;

                    case ElementType::STRAIGHTLEFTUP:
                        painter.drawImage(displayX, displayY, *straightLeftUpImage);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<DirectTrack> currentElement : drawnLayout->getDirectTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::DIRECTLEFT:
                        painter.drawImage(displayX, displayY, *directLeftImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2()) {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::DIRECTRIGHT:
                        painter.drawImage(displayX, displayY, *directRightImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::DIRECTUP:
                        painter.drawImage(displayX, displayY, *directUpImage);
                        if (currentElement->getPlatform1())
                        {
                           painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2()) {
                           painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::DIRECTDOWN:
                        painter.drawImage(displayX, displayY, *directDownImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2()) {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::DIRECTRIGHTUP:
                        painter.drawImage(displayX, displayY, *directRightUpImage);
                        break;
                    case ElementType::DIRECTLEFTUP:
                        painter.drawImage(displayX, displayY, *directLeftUpImage);
                        break;
                    case ElementType::DIRECTLEFTDOWN:
                        painter.drawImage(displayX, displayY, *directLeftDownImage);
                        break;
                    case ElementType::DIRECTRIGHTDOWN:
                        painter.drawImage(displayX, displayY, *directRightDownIamge);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<CurvedTrack> currentElement : drawnLayout->getCurvedTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::TIGHTCURVE1:
                        painter.drawImage(displayX, displayY, *tightCurve1Image);
                        break;
                    case ElementType::TIGHTCURVE2:
                        painter.drawImage(displayX, displayY, *tightCurve2Image);
                        break;
                    case ElementType::TIGHTCURVE3:
                        painter.drawImage(displayX, displayY, *tightCurve3Image);
                        break;
                    case ElementType::TIGHTCURVE4:
                        painter.drawImage(displayX, displayY, *tightCurve4Image);
                        break;
                    case ElementType::CURVE1:
                        painter.drawImage(displayX, displayY, *curve1Image);
                        break;
                    case ElementType::CURVE2:
                        painter.drawImage(displayX, displayY, *curve2Image);
                        break;
                    case ElementType::CURVE3:
                        painter.drawImage(displayX, displayY, *curve3Image);
                        break;
                    case ElementType::CURVE4:
                        painter.drawImage(displayX, displayY, *curve4Image);
                        break;
                    case ElementType::CURVE5:
                        painter.drawImage(displayX, displayY, *curve5Image);
                        break;
                    case ElementType::CURVE6:
                        painter.drawImage(displayX, displayY, *curve6Image);
                        break;
                    case ElementType::CURVE7:
                        painter.drawImage(displayX, displayY, *curve7Image);
                        break;
                    case ElementType::CURVE8:
                        painter.drawImage(displayX, displayY, *curve8Image);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<LinkedTrack> currentElement : drawnLayout->getLinkedTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::LINKLEFT:
                        painter.drawImage(displayX, displayY, *linkLeftImage);
                        break;
                    case ElementType::LINKRIGHT:
                        painter.drawImage(displayX, displayY, *linkRightImage);
                        break;
                    case ElementType::LINKDOWN:
                        painter.drawImage(displayX, displayY, *linkDownImage);
                        break;
                    case ElementType::LINKUP:
                        painter.drawImage(displayX, displayY, *linkUpImage);
                        break;
                    case ElementType::LINKLEFTUP:
                        painter.drawImage(displayX, displayY, *linkLeftUpImage);
                        break;
                    case ElementType::LINKRIGHTUP:
                        painter.drawImage(displayX, displayY, *linkRightUpImage);
                        break;
                    case ElementType::LINKRIGHTDOWN:
                        painter.drawImage(displayX, displayY, *linkRightDownImage);
                        break;
                    case ElementType::LINKLEFTDOWN:
                        painter.drawImage(displayX, displayY, *linkLeftDownImage);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<ExitTrack> currentElement : drawnLayout->getExitTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::EXITLEFT:
                        painter.drawImage(displayX, displayY, *exitLeftImage);
                        break;
                    case ElementType::EXITRIGHT:
                        painter.drawImage(displayX, displayY, *exitRightImage);
                        break;
                    case ElementType::EXITDOWN:
                        painter.drawImage(displayX, displayY, *exitDownImage);
                        break;
                    case ElementType::EXITUP:
                        painter.drawImage(displayX, displayY, *exitUpImage);
                        break;
                    case ElementType::EXITLEFTUP:
                        painter.drawImage(displayX, displayY, *exitLeftUpImage);
                        break;
                    case ElementType::EXITRIGHTUP:
                        painter.drawImage(displayX, displayY, *exitRightUpImage);
                        break;
                    case ElementType::EXITLEFTDOWN:
                        painter.drawImage(displayX, displayY, *exitLeftDownImage);
                        break;
                    case ElementType::EXITRIGHTDOWN:
                        painter.drawImage(displayX, displayY, *exitRightDownImage);
                        break;

                }
            }
        }
    }

    for (std::shared_ptr<BufferTrack> currentElement : drawnLayout->getBufferTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::BUFFERLEFT:
                        painter.drawImage(displayX, displayY, *bufferLeftImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::BUFFERRIGHT:
                        painter.drawImage(displayX, displayY, *bufferRightImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::BUFFERDOWN:
                        painter.drawImage(displayX, displayY, *bufferDownImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::BUFFERUP:
                        painter.drawImage(displayX, displayY, *bufferUpImage);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::BUFFERLEFTUP:
                        painter.drawImage(displayX, displayY, *bufferLeftUpImage);
                        break;
                    case ElementType::BUFFERRIGHTUP:
                        painter.drawImage(displayX, displayY, *bufferRightUpImage);
                        break;
                    case ElementType::BUFFERLEFTDOWN:
                        painter.drawImage(displayX, displayY, *bufferLeftDownImage);
                        break;
                    case ElementType::BUFFERRIGHTDOWN:
                        painter.drawImage(displayX, displayY, *bufferRightDownImage);
                        break;

                }
            }
        }
    }

    for (std::shared_ptr<SignalTrack> currentElement : drawnLayout->getSignalTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::SIGNALLEFT:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntLeftImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalLeftImage);
                        }
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::SIGNALRIGHT:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntRightImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalRightImage);
                        }
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::SIGNALDOWN:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntDownImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalDownImage);
                        }
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::SIGNALUP:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntUpImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalUpImage);
                        }
                        if (currentElement->getPlatform1()) {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2()) {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::SIGNALLEFTUP:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntLeftUpImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalLeftUpImage);
                        }
                        break;
                    case ElementType::SIGNALRIGHTUP:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntRightUpImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalRightUpImage);
                        }
                        break;
                    case ElementType::SIGNALLEFTDOWN:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntLeftDownImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalLeftDownImage);
                        }
                        break;
                    case ElementType::SIGNALRIGHTDOWN:
                        if (currentElement->getAspect() == 1)
                        {
                            painter.drawImage(displayX, displayY, *shuntRightDownImage);
                        }
                        else
                        {
                            painter.drawImage(displayX, displayY, *signalRightDownImage);
                        }
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<BridgeUnderpassTrack> currentElement : drawnLayout->getBridgeUnderpassTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::BRIDGE1:
                        painter.drawImage(displayX, displayY, *bridgeUnset1Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::BRIDGE2:
                        painter.drawImage(displayX, displayY, *bridgeUnset2Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::UNDERPASS1:
                        painter.drawImage(displayX, displayY, *underpassUnset1Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;

                    case ElementType::UNDERPASS2:
                        painter.drawImage(displayX, displayY, *underpassUnset2Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<SwitchTrack> currentElement : drawnLayout->getSwitchTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::SWITCHTIGHT1:
                        painter.drawImage(displayX, displayY, *switchTight1Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHTIGHT2:
                        painter.drawImage(displayX, displayY, *switchTight2Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHTIGHT3:
                        painter.drawImage(displayX, displayY, *switchTight3Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHTIGHT4:
                        painter.drawImage(displayX, displayY, *switchTight4Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHTIGHT5:
                        painter.drawImage(displayX, displayY, *switchTight5Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHTIGHT6:
                        painter.drawImage(displayX, displayY, *switchTight6Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHTIGHT7:
                        painter.drawImage(displayX, displayY, *switchTight7Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;

                    case ElementType::SWITCHTIGHT8:
                        painter.drawImage(displayX, displayY, *switchTight8Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHSPLIT1:
                        painter.drawImage(displayX, displayY, *switchSplit1Image);
                        break;
                    case ElementType::SWITCHSPLIT2:
                        painter.drawImage(displayX, displayY, *switchSplit2Image);
                        break;
                    case ElementType::SWITCHSPLIT3:
                        painter.drawImage(displayX, displayY, *switchSplit3Image);
                        break;
                    case ElementType::SWITCH1:
                        painter.drawImage(displayX, displayY, *switch1Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH2:
                        painter.drawImage(displayX, displayY, *switch2Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH3:
                        painter.drawImage(displayX, displayY, *switch3Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH4:
                        painter.drawImage(displayX, displayY, *switch4Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH5:
                        painter.drawImage(displayX, displayY, *switch5Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH6:
                        painter.drawImage(displayX, displayY, *switch6Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH7:
                        painter.drawImage(displayX, displayY, *switch7Image);
                        if (currentElement->getPlatform2())
                        {
                            painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                        }
                        break;
                    case ElementType::SWITCH8:
                        painter.drawImage(displayX, displayY, *switch8Image);
                        if (currentElement->getPlatform1())
                        {
                            painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                        }
                        break;
                    case ElementType::SWITCHSPLIT4:
                        painter.drawImage(displayX, displayY, *switchSplit4Image);
                        break;
                    case ElementType::SWITCHSPLIT5:
                        painter.drawImage(displayX, displayY, *switchSplit5Image);
                        break;
                    case ElementType::SWITCHSPLIT6:
                        painter.drawImage(displayX, displayY, *switchSplit6Image);
                        break;
                    case ElementType::SWITCH9:
                        painter.drawImage(displayX, displayY, *switch9Image);
                        break;
                    case ElementType::SWITCH10:
                        painter.drawImage(displayX, displayY, *switch10Image);
                        break;
                    case ElementType::SWITCH11:
                        painter.drawImage(displayX, displayY, *switch11Image);
                        break;
                    case ElementType::SWITCH12:
                        painter.drawImage(displayX, displayY, *switch12Image);
                        break;
                    case ElementType::SWITCH13:
                        painter.drawImage(displayX, displayY, *switch13Image);
                        break;
                    case ElementType::SWITCH14:
                        painter.drawImage(displayX, displayY, *switch14Image);
                        break;
                    case ElementType::SWITCH15:
                        painter.drawImage(displayX, displayY, *switch15Image);
                        break;
                    case ElementType::SWITCH16:
                        painter.drawImage(displayX, displayY, *switch16Image);
                        break;
                    case ElementType::SWITCHSPLIT7:
                        painter.drawImage(displayX, displayY, *switchSplit7Image);
                        break;
                    case ElementType::SWITCHSPLIT8:
                        painter.drawImage(displayX, displayY, *switchSplit8Image);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<CrossoverTrack> currentElement : drawnLayout->getCrossoverTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                   case ElementType::CROSSOVER1:
                       painter.drawImage(displayX, displayY, *crossover1Image);
                       break;
                   case ElementType::CROSSOVER2:
                       painter.drawImage(displayX, displayY, *crossover2Image);
                       break;
                   case ElementType::CROSSOVER3:
                       painter.drawImage(displayX, displayY, *crossover3Image);
                       break;
                   case ElementType::CROSSOVER4:
                       painter.drawImage(displayX, displayY, *crossover4Image);
                       break;
                   case ElementType::CROSSOVER5:
                       painter.drawImage(displayX, displayY, *crossover5Image);
                       break;
                   case ElementType::CROSSOVER6:
                       painter.drawImage(displayX, displayY, *crossover6Image);
                       break;
                }
            }
        }
    }

    for (std::shared_ptr<FlyoverTrack> currentElement : drawnLayout->getFlyoverTrackList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::FLYOVER1:
                        painter.drawImage(displayX, displayY, *flyover1Image);
                        break;
                    case ElementType::FLYOVER2:
                        painter.drawImage(displayX, displayY, *flyover2Image);
                        break;
                    case ElementType::FLYOVER3:
                        painter.drawImage(displayX, displayY, *flyover3Image);
                        break;
                    case ElementType::FLYOVER4:
                        painter.drawImage(displayX, displayY, *flyover4Image);
                        break;
                    case ElementType::FLYOVER5:
                        painter.drawImage(displayX, displayY, *flyover5Image);
                        break;
                    case ElementType::FLYOVER6:
                        painter.drawImage(displayX, displayY, *flyover6Image);
                        break;
                    case ElementType::FLYOVER7:
                        painter.drawImage(displayX, displayY, *flyover7Image);
                        break;
                    case ElementType::FLYOVER8:
                        painter.drawImage(displayX, displayY, *flyover8Image);
                        break;
                    case ElementType::FLYOVER9:
                        painter.drawImage(displayX, displayY, *flyover9Image);
                        break;
                    case ElementType::FLYOVER10:
                        painter.drawImage(displayX, displayY, *flyover10Image);
                        break;
                    case ElementType::FLYOVER11:
                        painter.drawImage(displayX, displayY, *flyover11Image);
                        break;
                    case ElementType::FLYOVER12:
                        painter.drawImage(displayX, displayY, *flyover12Image);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<NamedLocation> currentElement : drawnLayout->getNamedLocationList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                if (currentElement->getNamed())
                {
                    painter.drawImage(displayX, displayY, *namedLocationSetImage);
                }
                else
                {
                    painter.drawImage(displayX, displayY, *namedLocationUnsetImage);
                }
            }
        }
    }

    for (std::shared_ptr<Concourse> currentElement : drawnLayout->getConcourseList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                if (currentElement->getNamed())
                {
                    painter.drawImage(displayX, displayY, *concourseSetImage);
                }
                else
                {
                    painter.drawImage(displayX, displayY, *concourseUnsetImage);
                }
            }
        }
    }

    for (std::shared_ptr<Parapet> currentElement : drawnLayout->getParapetList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);
                switch (currentElement->getElementType())
                {
                    case ElementType::PARAPET1:
                        painter.drawImage(displayX, displayY, *parapet1Image);
                        break;
                    case ElementType::PARAPET2:
                        painter.drawImage(displayX, displayY, *parapet2Image);
                        break;
                    case ElementType::PARAPET3:
                        painter.drawImage(displayX, displayY, *parapet3Image);
                        break;
                    case ElementType::PARAPET4:
                        painter.drawImage(displayX, displayY, *parapet4Image);
                        break;
                    case ElementType::PARAPET5:
                        painter.drawImage(displayX, displayY, *parapet5Image);
                        break;
                    case ElementType::PARAPET6:
                        painter.drawImage(displayX, displayY, *parapet6Image);
                        break;
                    case ElementType::PARAPET7:
                        painter.drawImage(displayX, displayY, *parapet7Image);
                        break;
                    case ElementType::PARAPET8:
                        painter.drawImage(displayX, displayY, *parapet8Image);
                        break;
                    case ElementType::PARAPET9:
                        painter.drawImage(displayX, displayY, *parapet9Image);
                        break;
                    case ElementType::PARAPET10:
                        painter.drawImage(displayX, displayY, *parapet10Image);
                        break;
                    case ElementType::PARAPET11:
                        painter.drawImage(displayX, displayY, *parapet11Image);
                        break;
                    case ElementType::PARAPET12:
                        painter.drawImage(displayX, displayY, *parapet12Image);
                        break;
                    case ElementType::PARAPET13:
                        painter.drawImage(displayX, displayY, *parapet13Image);
                        break;
                    case ElementType::PARAPET14:
                        painter.drawImage(displayX, displayY, *parapet14Image);
                        break;
                    case ElementType::PARAPET15:
                        painter.drawImage(displayX, displayY, *parapet15Image);
                        break;
                    case ElementType::PARAPET16:
                        painter.drawImage(displayX, displayY, *parapet16Image);
                        break;
                    case ElementType::PARAPET17:
                        painter.drawImage(displayX, displayY, *parapet17Image);
                        break;
                    case ElementType::PARAPET18:
                        painter.drawImage(displayX, displayY, *parapet18Image);
                        break;
                    case ElementType::PARAPET19:
                        painter.drawImage(displayX, displayY, *parapet19Image);
                        break;
                    case ElementType::PARAPET20:
                        painter.drawImage(displayX, displayY, *parapet20Image);
                        break;
                    case ElementType::PARAPET21:
                        painter.drawImage(displayX, displayY, *parapet21Image);
                        break;
                    case ElementType::PARAPET22:
                        painter.drawImage(displayX, displayY, *parapet22Image);
                        break;
                    case ElementType::PARAPET23:
                        painter.drawImage(displayX, displayY, *parapet23Image);
                        break;
                    case ElementType::PARAPET24:
                        painter.drawImage(displayX, displayY, *parapet24Image);
                        break;
                    case ElementType::PARAPET25:
                        painter.drawImage(displayX, displayY, *parapet25Image);
                        break;
                    case ElementType::PARAPET26:
                        painter.drawImage(displayX, displayY, *parapet26Image);
                        break;
                    case ElementType::PARAPET27:
                        painter.drawImage(displayX, displayY, *parapet27Image);
                        break;
                    case ElementType::PARAPET28:
                        painter.drawImage(displayX, displayY, *parapet28Image);
                        break;
                }
            }
        }
    }

    for (std::shared_ptr<Text> currentElement : drawnLayout->getTextList())
    {
        int currentX = currentElement->getLocationX();
        int currentY = currentElement->getLocationY();
        int minCoordinateX = (offsetX * canvasSizeX)/16;
        int maxCoordinateX = ((offsetX+1) * canvasSizeX)/16;
        int minCoordinateY = ((offsetY-1) * canvasSizeY)/16;
        int maxCoordinateY = (offsetY*canvasSizeY)/16;;
        int minDisplayX = (offsetX * canvasSizeX);
        int maxDisplayX = ((offsetX+1) * canvasSizeX);
        int minDisplayY = ((offsetY-1) * canvasSizeY);
        int maxDisplayY = (offsetY*canvasSizeY);
        if (currentX > minCoordinateX && currentX < maxCoordinateX)
        {
            if (currentY > minCoordinateY && currentY < maxCoordinateY)
            {
                int displayX = currentX*16- minDisplayX;
                int displayY = 0-(currentY*16 - maxDisplayY);

                painter.drawText(displayX, displayY, currentElement->getReadableText());
            }
        }
    }

}

void Canvas::resizeEvent(QResizeEvent *event)
{
    int tempX = width();
    int tempY = height();
    int diffX = tempX % 16;
    int diffY = tempY % 16;
    if (diffX != 0 && diffY != 0)
    {
        resize(tempX-diffX,tempY-diffY);
    }

    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if (canvasShowTrackID)
    {
        int exactX = event->pos().x();
        int exactY = event->pos().y();
        int extraX = exactX % 16;
        int extraY = exactY % 16;
        int roundedX = exactX - extraX;
        int roundedY = exactY - extraY;
        int maxX = canvasSizeX/16;
        int maxY = canvasSizeY/16;
        int finalX = ((roundedX + (offsetX*canvasSizeX))/16);
        int finalY;
        if (offsetY==0)
        {
            finalY = 0 - ((roundedY+ (offsetY*canvasSizeY))/16);
        }
        else if (offsetY<0 || offsetY >0)
        {
            finalY = 0 - (roundedY- (offsetY*canvasSizeY))/16;
        }
        if (drawnLayout->checkElementExists(finalX,finalY))
        {
            QString finalText;
            QString ID;
            std::shared_ptr<Element> element = nullptr;
            element = drawnLayout->getElementAt(finalX,finalY);
            if (element== nullptr)
            {
                std::shared_ptr<Track> track = nullptr;
                track = drawnLayout->getTrackAt(finalX,finalY);
                ID = "Track ID = ";
                ID = ID.append(QString::number(finalX)).append(",").append(QString::number(finalY));
                if (canvasShowMoreTrackInfo) {
                   QString text2 = tr("\n").append("Track length = ").append(QString::number(track->getTrackLength())).append(" m");
                   QString text3 = tr("\n").append("Track speed = ").append(QString::number(track->getTrackSpeed())).append(" km/h");
                   finalText = ID.append(text2).append(text3);
                }
                finalText = ID;

            }
            else
            {
                ID = "Element ID = ";
                ID = ID.append(QString::number(finalX)).append(",").append(QString::number(finalY));
                finalText = ID;
            }



            setToolTip(finalText);

        }




    }


}




