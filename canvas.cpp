#include "canvas.h"

Canvas::Canvas()
{


    imageSize = 15;
    // set black background
    drawnLayout = new Map;

    setMouseTracking(true);

    int tempX = width();
    int tempY = height();
    int diffX = tempX % 16;
    int diffY = tempY % 16;

    if (diffX != 0 && diffY != 0)
    {
        resize(tempX-diffX,tempY-diffY);
    }

    canvasSizeX = width();
    canvasSizeY = height();
    setAlignment(Qt::AlignLeft | Qt::AlignTop);

    setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    scene = new QGraphicsScene;
    setScene(scene);
    setSceneRect(0, 0, canvasSizeX, canvasSizeY);
    //QTimer *timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &Canvas::redraw);
    //timer->start(30);

    //ElementBlock1 Pixmap
    straightHPixmap = new QPixmap(":/graphics/graphics/straightH.png");
    straightVPixmap = new QPixmap(":/graphics/graphics/straightV.png");
    directLeftPixmap = new QPixmap(":/graphics/graphics/directLeft.png");
    directRightPixmap = new QPixmap(":/graphics/graphics/directRight.png");
    directUpPixmap = new QPixmap(":/graphics/graphics/directUp.png");
    directDownPixmap = new QPixmap(":/graphics/graphics/directDown.png");
    straightLeftUpPixmap = new QPixmap(":/graphics/graphics/straightLeftUp.png");
    straightRightUpPixmap = new QPixmap(":/graphics/graphics/straightRightUp.png");
    directLeftUpPixmap = new QPixmap(":/graphics/graphics/directLeftUp.png");
    directRightUpPixmap = new QPixmap(":/graphics/graphics/directRightUp.png");
    directRightDownPixmap = new QPixmap(":/graphics/graphics/directRightDown.png");
    directLeftDownPixmap = new QPixmap(":/graphics/graphics/directLeftDown.png");
    tightCurve1Pixmap = new QPixmap(":/graphics/graphics/tightCurve1.png");
    tightCurve2Pixmap = new QPixmap(":/graphics/graphics/tightCurve2.png");
    tightCurve3Pixmap = new QPixmap(":/graphics/graphics/tightCurve3.png");
    tightCurve4Pixmap = new QPixmap(":/graphics/graphics/tightCurve4.png");
    curve1Pixmap = new QPixmap(":/graphics/graphics/curve1.png");
    curve2Pixmap = new QPixmap(":/graphics/graphics/curve2.png");
    curve3Pixmap = new QPixmap(":/graphics/graphics/curve3.png");
    curve4Pixmap = new QPixmap(":/graphics/graphics/curve4.png");

    linkLeftPixmap = new QPixmap(":/graphics/graphics/linkLeftUnset.png");
    linkRightPixmap = new QPixmap(":/graphics/graphics/linkRightUnset.png");
    linkDownPixmap = new QPixmap(":/graphics/graphics/linkDownUnset.png");
    linkUpPixmap = new QPixmap(":/graphics/graphics/linkUpUnset.png");
    linkLeftUpPixmap = new QPixmap(":/graphics/graphics/linkLeftUpUnset.png");
    linkRightUpPixmap = new QPixmap(":/graphics/graphics/linkRightUpUnset.png");
    linkRightDownPixmap = new QPixmap(":/graphics/graphics/linkRightDownUnset.png");
    linkLeftDownPixmap = new QPixmap(":/graphics/graphics/linkLeftDownUnset.png");
    exitLeftPixmap = new QPixmap(":/graphics/graphics/exitLeft.png");
    exitRightPixmap = new QPixmap(":/graphics/graphics/exitRight.png");
    exitDownPixmap = new QPixmap(":/graphics/graphics/exitDown.png");
    exitUpPixmap = new QPixmap(":/graphics/graphics/exitUp.png");
    exitLeftUpPixmap = new QPixmap(":/graphics/graphics/exitLeftUp.png");
    exitRightUpPixmap = new QPixmap(":/graphics/graphics/exitRightUp.png");
    exitLeftDownPixmap = new QPixmap(":/graphics/graphics/exitLeftDown.png");
    exitRightDownPixmap = new QPixmap(":/graphics/graphics/exitRightDown.png");
    curve5Pixmap = new QPixmap(":/graphics/graphics/curve5.png");
    curve6Pixmap = new QPixmap(":/graphics/graphics/curve6.png");
    curve7Pixmap = new QPixmap(":/graphics/graphics/curve7.png");
    curve8Pixmap = new QPixmap(":/graphics/graphics/curve8.png");

    bufferLeftPixmap = new QPixmap(":/graphics/graphics/bufferLeft.png");
    bufferRightPixmap = new QPixmap(":/graphics/graphics/bufferRight.png");
    bufferDownPixmap = new QPixmap(":/graphics/graphics/bufferDown.png");
    bufferUpPixmap = new QPixmap(":/graphics/graphics/bufferUp.png");
    bufferLeftUpPixmap = new QPixmap(":/graphics/graphics/bufferLeftUp.png");
    bufferRightUpPixmap = new QPixmap(":/graphics/graphics/bufferRightUp.png");
    bufferLeftDownPixmap = new QPixmap(":/graphics/graphics/bufferLeftDown.png");
    bufferRightDownPixmap = new QPixmap(":/graphics/graphics/bufferRightDown.png");
    signalLeftPixmap = new QPixmap(":/graphics/graphics/signalLeft.png");
    signalRightPixmap = new QPixmap(":/graphics/graphics/signalRight.png");
    signalDownPixmap = new QPixmap(":/graphics/graphics/signalDown.png");
    signalUpPixmap = new QPixmap(":/graphics/graphics/signalUp.png");
    signalLeftUpPixmap = new QPixmap(":/graphics/graphics/signalLeftUp.png");
    signalRightUpPixmap = new QPixmap(":/graphics/graphics/signalRightUp.png");
    signalLeftDownPixmap = new QPixmap(":/graphics/graphics/signalLeftDown.png");
    signalRightDownPixmap = new QPixmap(":/graphics/graphics/signalRightDown.png");
    shuntLeftPixmap = new QPixmap(":/graphics/graphics/shuntLeftRed.png");
    shuntRightPixmap = new QPixmap(":/graphics/graphics/shuntRightRed.png");
    shuntDownPixmap = new QPixmap(":/graphics/graphics/shuntDownRed.png");
    shuntUpPixmap = new QPixmap(":/graphics/graphics/shuntUpRed.png");
    shuntLeftUpPixmap = new QPixmap(":/graphics/graphics/shuntLeftUpRed.png");
    shuntRightUpPixmap = new QPixmap(":/graphics/graphics/shuntRightUpRed.png");
    shuntLeftDownPixmap = new QPixmap(":/graphics/graphics/shuntLeftDownRed.png");
    shuntRightDownPixmap = new QPixmap(":/graphics/graphics/shuntRightDownRed.png");
    bridgeUnset1Pixmap = new QPixmap(":/graphics/graphics/bridgeUnset1.png");
    bridgeUnset2Pixmap = new QPixmap(":/graphics/graphics/bridgeUnset2.png");
    underpassUnset1Pixmap = new QPixmap(":/graphics/graphics/underpassUnset1.png");
    underpassUnset2Pixmap = new QPixmap(":/graphics/graphics/underpassUnset2.png");
    bridgeSet1Pixmap = new QPixmap(":/graphics/graphics/brdigeSet1.png");
    bridgeSet2Pixmap = new QPixmap(":/graphics/graphics/bridgeSet2.png");
    underpassSet1Pixmap = new QPixmap(":/graphics/graphics/underpassSet1.png");
    underpassSet2Pixmap = new QPixmap(":/graphics/graphics/underpassSet2.png");

    //ElementBlock2 Pixmaps
    switchTight1Pixmap = new QPixmap(":/graphics/graphics/switchTight1.png");
    switchTight2Pixmap = new QPixmap(":/graphics/graphics/switchTight2.png");
    switchTight3Pixmap = new QPixmap(":/graphics/graphics/switchTight3.png");
    switchTight4Pixmap = new QPixmap(":/graphics/graphics/switchTight4.png");
    switchTight5Pixmap = new QPixmap(":/graphics/graphics/switchTight5.png");
    switchTight6Pixmap = new QPixmap(":/graphics/graphics/switchTight6.png");
    switchTight7Pixmap = new QPixmap(":/graphics/graphics/switchTight7.png");
    switchTight8Pixmap = new QPixmap(":/graphics/graphics/switchTight8.png");
    switchSplit1Pixmap = new QPixmap(":/graphics/graphics/switchSplit1.png");
    switchSplit2Pixmap = new QPixmap(":/graphics/graphics/switchSplit2.png");
    switchSplit3Pixmap = new QPixmap(":/graphics/graphics/switchSplit3.png");

    switch1Pixmap = new QPixmap(":/graphics/graphics/switch1.png");
    switch2Pixmap = new QPixmap(":/graphics/graphics/switch2.png");
    switch3Pixmap = new QPixmap(":/graphics/graphics/switch3.png");
    switch4Pixmap = new QPixmap(":/graphics/graphics/switch4.png");
    switch5Pixmap = new QPixmap(":/graphics/graphics/switch5.png");
    switch6Pixmap = new QPixmap(":/graphics/graphics/switch6.png");
    switch7Pixmap = new QPixmap(":/graphics/graphics/switch7.png");
    switch8Pixmap = new QPixmap(":/graphics/graphics/switch8.png");
    switchSplit4Pixmap = new QPixmap(":/graphics/graphics/switchSplit4.png");
    switchSplit5Pixmap = new QPixmap(":/graphics/graphics/switchSplit5.png");
    switchSplit6Pixmap = new QPixmap(":/graphics/graphics/switchSplit6.png");

    switch9Pixmap = new QPixmap(":/graphics/graphics/switch9.png");
    switch10Pixmap = new QPixmap(":/graphics/graphics/switch10.png");
    switch11Pixmap = new QPixmap(":/graphics/graphics/switch11.png");
    switch12Pixmap = new QPixmap(":/graphics/graphics/switch12.png");
    switch13Pixmap = new QPixmap(":/graphics/graphics/switch13.png");
    switch14Pixmap = new QPixmap(":/graphics/graphics/switch14.png");
    switch15Pixmap = new QPixmap(":/graphics/graphics/switch15.png");
    switch16Pixmap = new QPixmap(":/graphics/graphics/switch16.png");
    switchSplit7Pixmap = new QPixmap(":/graphics/graphics/switchSplit7.png");
    switchSplit8Pixmap = new QPixmap(":/graphics/graphics/switchSplit8.png");

    //ElementBlock3 Pixmaps
    crossover1Pixmap = new QPixmap(":/graphics/graphics/crossover1.png");
    crossover2Pixmap = new QPixmap(":/graphics/graphics/crossover2.png");
    flyover1Pixmap = new QPixmap(":/graphics/graphics/flyover1.png");
    flyover2Pixmap = new QPixmap(":/graphics/graphics/flyover2.png");
    flyover3Pixmap = new QPixmap(":/graphics/graphics/flyover3.png");
    flyover4Pixmap = new QPixmap(":/graphics/graphics/flyover4.png");

    crossover3Pixmap = new QPixmap(":/graphics/graphics/crossover3.png");
    crossover4Pixmap = new QPixmap(":/graphics/graphics/crossover4.png");
    flyover5Pixmap = new QPixmap(":/graphics/graphics/flyover5.png");
    flyover6Pixmap = new QPixmap(":/graphics/graphics/flyover6.png");
    flyover7Pixmap = new QPixmap(":/graphics/graphics/flyover7.png");
    flyover8Pixmap = new QPixmap(":/graphics/graphics/flyover8.png");

    crossover5Pixmap = new QPixmap(":/graphics/graphics/crossover5.png");
    crossover6Pixmap = new QPixmap(":/graphics/graphics/crossover6.png");
    flyover9Pixmap = new QPixmap(":/graphics/graphics/flyover9.png");
    flyover10Pixmap = new QPixmap(":/graphics/graphics/flyover10.png");
    flyover11Pixmap = new QPixmap(":/graphics/graphics/flyover11.png");
    flyover12Pixmap = new QPixmap(":/graphics/graphics/flyover12.png");

    //ElementBlock4 Pixmaps
    namedLocationUnsetPixmap = new QPixmap(":/graphics/graphics/namedLocationUnset.png");
    namedLocationSetPixmap = new QPixmap(":/graphics/graphics/namedLocationSet.png");
    concourseUnsetPixmap = new QPixmap(":/graphics/graphics/concourseUnset.png");
    concourseSetPixmap = new QPixmap(":/graphics/graphics/concourseSet.png");
    platformDownUnsetPixmap = new QPixmap(":/graphics/graphics/platformDownUnset.png");
    platformDownSetPixmap = new QPixmap(":/graphics/graphics/platformDownSet.png");
    platformUpUnsetPixmap = new QPixmap(":/graphics/graphics/platformUpUnset.png");
    platformUpSetPixmap = new QPixmap(":/graphics/graphics/platformUpSet.png");
    platformLeftUnsetPixmap = new QPixmap(":/graphics/graphics/platformLeftUnset.png");
    platformLeftSetPixmap = new QPixmap(":/graphics/graphics/platformLeftSet.png");
    platformRightUnsetPixmap = new QPixmap(":/graphics/graphics/platformRightUnset.png");
    platformRightSetPixmap = new QPixmap(":/graphics/graphics/platformRightSet.png");

    //ElementBlock5 Pixmaps
    parapet1Pixmap = new QPixmap(":/graphics/graphics/parapet1.png");
    parapet2Pixmap = new QPixmap(":/graphics/graphics/parapet2.png");
    parapet3Pixmap = new QPixmap(":/graphics/graphics/parapet3.png");
    parapet4Pixmap = new QPixmap(":/graphics/graphics/parapet4.png");
    parapet5Pixmap = new QPixmap(":/graphics/graphics/parapet5.png");
    parapet6Pixmap = new QPixmap(":/graphics/graphics/parapet6.png");
    parapet7Pixmap = new QPixmap(":/graphics/graphics/parapet7.png");
    parapet8Pixmap = new QPixmap(":/graphics/graphics/parapet8.png");
    parapet9Pixmap = new QPixmap(":/graphics/graphics/parapet9.png");
    parapet10Pixmap = new QPixmap(":/graphics/graphics/parapet10.png");

    parapet11Pixmap = new QPixmap(":/graphics/graphics/parapet11.png");
    parapet12Pixmap = new QPixmap(":/graphics/graphics/parapet12.png");
    parapet13Pixmap = new QPixmap(":/graphics/graphics/parapet13.png");
    parapet14Pixmap = new QPixmap(":/graphics/graphics/parapet14.png");
    parapet15Pixmap = new QPixmap(":/graphics/graphics/parapet15.png");
    parapet16Pixmap = new QPixmap(":/graphics/graphics/parapet16.png");
    parapet17Pixmap = new QPixmap(":/graphics/graphics/parapet17.png");
    parapet18Pixmap = new QPixmap(":/graphics/graphics/parapet18.png");
    parapet19Pixmap = new QPixmap(":/graphics/graphics/parapet19.png");
    parapet20Pixmap = new QPixmap(":/graphics/graphics/parapet20.png");

    parapet21Pixmap = new QPixmap(":/graphics/graphics/parapet21.png");
    parapet22Pixmap = new QPixmap(":/graphics/graphics/parapet22.png");
    parapet23Pixmap = new QPixmap(":/graphics/graphics/parapet23.png");
    parapet24Pixmap = new QPixmap(":/graphics/graphics/parapet24.png");
    parapet25Pixmap = new QPixmap(":/graphics/graphics/parapet25.png");
    parapet26Pixmap = new QPixmap(":/graphics/graphics/parapet26.png");
    parapet27Pixmap = new QPixmap(":/graphics/graphics/parapet27.png");
    parapet28Pixmap = new QPixmap(":/graphics/graphics/parapet28.png");

    //ElementBlock6Pixmap
    levelCrossingHPixmap = new QPixmap(":/graphics/graphics/levelCrossingH.png");
    levelCrossingVPixmap = new QPixmap(":/graphics/graphics/levelCrossingV.png");

    setAutoFillBackground(true);
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

void Canvas::redraw()
{
    scene->clear();
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
                    {
                        QGraphicsPixmapItem *straightHPixmapItem = scene->addPixmap(*straightHPixmap);
                        straightHPixmapItem->setPos(displayX,displayY);
                        /*std::cout << "MinMax: " << std::flush;
                        std::cout << minCoordinateX << std::flush;
                        std::cout << " "<< std::flush;
                        std::cout << maxCoordinateX << std::flush;
                        std::cout << " "<< std::flush;
                        std::cout << minCoordinateY << std::flush;
                        std::cout << " "<< std::flush;
                        std::cout << maxCoordinateY << std::flush;
                        std::cout << "display: " << std::flush;
                        std::cout << currentX << std::flush;
                        std::cout << " "<< std::flush;
                        std::cout << currentY << std::flush;
                        std::cout << " "<< std::flush;
                        */
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);

                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->hasLevelCrossing())
                        {
                            QGraphicsPixmapItem *levelCrossingHPixmapItem = scene->addPixmap(*levelCrossingHPixmap);
                            levelCrossingHPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::STRAIGHTV:
                    {
                        QGraphicsPixmapItem *straightVPixmapItem = scene->addPixmap(*straightVPixmap);
                        straightVPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->hasLevelCrossing())
                        {
                            QGraphicsPixmapItem *levelCrossingVPixmapItem = scene->addPixmap(*levelCrossingVPixmap);
                            levelCrossingVPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }

                    case ElementType::STRIAGHTRIGHTUP:
                    {
                        QGraphicsPixmapItem *straightRightUpPixmapItem = scene->addPixmap(*straightRightUpPixmap);
                        straightRightUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::STRAIGHTLEFTUP:
                    {
                        QGraphicsPixmapItem *straightLeftUpPixmapItem = scene->addPixmap(*straightLeftUpPixmap);
                        straightLeftUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *directLeftPixmapItem = scene->addPixmap(*directLeftPixmap);
                        directLeftPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::DIRECTRIGHT:
                    {
                        QGraphicsPixmapItem *directRightPixmapItem = scene->addPixmap(*directRightPixmap);
                        directRightPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::DIRECTUP:
                    {
                        QGraphicsPixmapItem *directUpPixmapItem = scene->addPixmap(*directUpPixmap);
                        directUpPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::DIRECTDOWN:
                    {
                        QGraphicsPixmapItem *directDownPixmapItem = scene->addPixmap(*directDownPixmap);
                        directDownPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::DIRECTRIGHTUP:
                    {
                        QGraphicsPixmapItem *directRightUpPixmapItem = scene->addPixmap(*directRightUpPixmap);
                        directRightUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::DIRECTLEFTUP:
                    {
                        QGraphicsPixmapItem *directLeftUpPixmapItem = scene->addPixmap(*directLeftUpPixmap);
                        directLeftUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::DIRECTLEFTDOWN:
                    {
                        QGraphicsPixmapItem *directLeftDownPixmapItem = scene->addPixmap(*directLeftDownPixmap);
                        directLeftDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::DIRECTRIGHTDOWN:
                    {
                        QGraphicsPixmapItem *directRightDownPixmapItem = scene->addPixmap(*directRightDownPixmap);
                        directRightDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *tightCurve1PixmapItem = scene->addPixmap(*tightCurve1Pixmap);
                        tightCurve1PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::TIGHTCURVE2:
                    {
                        QGraphicsPixmapItem *tightCurve2PixmapItem = scene->addPixmap(*tightCurve2Pixmap);
                        tightCurve2PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::TIGHTCURVE3:
                    {
                        QGraphicsPixmapItem *tightCurve3PixmapItem = scene->addPixmap(*tightCurve3Pixmap);
                        tightCurve3PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::TIGHTCURVE4:
                    {
                        QGraphicsPixmapItem *tightCurve4PixmapItem = scene->addPixmap(*tightCurve4Pixmap);
                        tightCurve4PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE1:
                    {
                        QGraphicsPixmapItem *curve1PixmapItem = scene->addPixmap(*curve1Pixmap);
                        curve1PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE2:
                    {
                        QGraphicsPixmapItem *curve2PixmapItem = scene->addPixmap(*curve2Pixmap);
                        curve2PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE3:
                    {
                        QGraphicsPixmapItem *curve3PixmapItem = scene->addPixmap(*curve3Pixmap);
                        curve3PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE4:
                    {
                        QGraphicsPixmapItem *curve4PixmapItem = scene->addPixmap(*curve4Pixmap);
                        curve4PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE5:
                    {
                        QGraphicsPixmapItem *curve5PixmapItem = scene->addPixmap(*curve5Pixmap);
                        curve5PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE6:
                    {
                        QGraphicsPixmapItem *curve6PixmapItem = scene->addPixmap(*curve6Pixmap);
                        curve6PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE7:
                    {
                        QGraphicsPixmapItem *curve7PixmapItem = scene->addPixmap(*curve7Pixmap);
                        curve7PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::CURVE8:
                    {
                        QGraphicsPixmapItem *curve8PixmapItem = scene->addPixmap(*curve8Pixmap);
                        curve8PixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *linkLeftPixmapItem = scene->addPixmap(*linkLeftPixmap);
                        linkLeftPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKRIGHT:
                    {
                        QGraphicsPixmapItem *linkRightPixmapItem = scene->addPixmap(*linkRightPixmap);
                        linkRightPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKDOWN:
                    {
                        QGraphicsPixmapItem *linkDownPixmapItem = scene->addPixmap(*linkDownPixmap);
                        linkDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKUP:
                    {
                        QGraphicsPixmapItem *linkUpPixmapItem = scene->addPixmap(*linkUpPixmap);
                        linkUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKLEFTUP:
                    {
                        QGraphicsPixmapItem *linkLeftUpPixmapItem = scene->addPixmap(*linkLeftUpPixmap);
                        linkLeftUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKRIGHTUP:
                    {
                        QGraphicsPixmapItem *linkRightUpPixmapItem = scene->addPixmap(*linkRightUpPixmap);
                        linkRightUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKRIGHTDOWN:
                    {
                        QGraphicsPixmapItem *linkRightDownPixmapItem = scene->addPixmap(*linkRightDownPixmap);
                        linkRightDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::LINKLEFTDOWN:
                    {
                        QGraphicsPixmapItem *linkLeftDownPixmapItem = scene->addPixmap(*linkLeftDownPixmap);
                        linkLeftDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *exitLeftPixmapItem = scene->addPixmap(*exitLeftPixmap);
                        exitLeftPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITRIGHT:
                    {
                        QGraphicsPixmapItem *exitRightPixmapItem = scene->addPixmap(*exitRightPixmap);
                        exitRightPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITDOWN:
                    {
                        QGraphicsPixmapItem *exitDownPixmapItem = scene->addPixmap(*exitDownPixmap);
                        exitDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITUP:
                    {
                        QGraphicsPixmapItem *exitUpPixmapItem = scene->addPixmap(*exitUpPixmap);
                        exitUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITLEFTUP:
                    {
                        QGraphicsPixmapItem *exitLeftUpPixmapItem = scene->addPixmap(*exitLeftUpPixmap);
                        exitLeftUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITRIGHTUP:
                    {
                        QGraphicsPixmapItem *exitRightUpPixmapItem = scene->addPixmap(*exitRightUpPixmap);
                        exitRightUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITLEFTDOWN:
                    {
                        QGraphicsPixmapItem *exitLeftDownPixmapItem = scene->addPixmap(*exitLeftDownPixmap);
                        exitLeftDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::EXITRIGHTDOWN:
                    {
                        QGraphicsPixmapItem *exitRightDownPixmapItem = scene->addPixmap(*exitRightDownPixmap);
                        exitRightDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *bufferLeftPixmapItem = scene->addPixmap(*bufferLeftPixmap);
                        bufferLeftPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::BUFFERRIGHT:
                    {
                        QGraphicsPixmapItem *bufferRightPixmapItem = scene->addPixmap(*bufferRightPixmap);
                        bufferRightPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::BUFFERDOWN:
                    {
                        QGraphicsPixmapItem *bufferDownPixmapItem = scene->addPixmap(*bufferDownPixmap);
                        bufferDownPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::BUFFERUP:
                    {
                        QGraphicsPixmapItem *bufferUpPixmapItem = scene->addPixmap(*bufferUpPixmap);
                        bufferUpPixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::BUFFERLEFTUP:
                    {
                        QGraphicsPixmapItem *bufferLeftUpPixmapItem = scene->addPixmap(*bufferLeftUpPixmap);
                        bufferLeftUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::BUFFERRIGHTUP:
                    {
                        QGraphicsPixmapItem *bufferRightUpPixmapItem = scene->addPixmap(*bufferRightUpPixmap);
                        bufferRightUpPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::BUFFERLEFTDOWN:
                    {
                        QGraphicsPixmapItem *bufferLeftDownPixmapItem = scene->addPixmap(*bufferLeftDownPixmap);
                        bufferLeftDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::BUFFERRIGHTDOWN:
                    {
                        QGraphicsPixmapItem *bufferRightDownPixmapItem = scene->addPixmap(*bufferRightDownPixmap);
                        bufferRightDownPixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalLeftPixmapItem = scene->addPixmap(*shuntLeftPixmap);
                            signalLeftPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalLeftPixmapItem = scene->addPixmap(*signalLeftPixmap);
                            signalLeftPixmapItem->setPos(displayX,displayY);
                        }

                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALRIGHT:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalRightPixmapItem = scene->addPixmap(*shuntRightPixmap);
                            signalRightPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalRightPixmapItem = scene->addPixmap(*signalRightPixmap);
                            signalRightPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALDOWN:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalDownPixmapItem = scene->addPixmap(*shuntDownPixmap);
                            signalDownPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalDownPixmapItem = scene->addPixmap(*signalDownPixmap);
                            signalDownPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALUP:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalUpPixmapItem = scene->addPixmap(*shuntUpPixmap);
                            signalUpPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalUpPixmapItem = scene->addPixmap(*signalUpPixmap);
                            signalUpPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALLEFTUP:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalLeftUpPixmapItem = scene->addPixmap(*shuntLeftUpPixmap);
                            signalLeftUpPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalLeftUpPixmapItem = scene->addPixmap(*signalLeftUpPixmap);
                            signalLeftUpPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALRIGHTUP:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalRightUpPixmapItem = scene->addPixmap(*shuntRightUpPixmap);
                            signalRightUpPixmapItem->setPos(displayX,displayY);
                            break;
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalRightUpPixmapItem = scene->addPixmap(*signalRightUpPixmap);
                            signalRightUpPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALLEFTDOWN:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalLeftDownPixmapItem = scene->addPixmap(*shuntLeftDownPixmap);
                            signalLeftDownPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalLeftDownPixmapItem = scene->addPixmap(*signalLeftDownPixmap);
                            signalLeftDownPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SIGNALRIGHTDOWN:
                    {
                        if (currentElement->getAspect() == 1)
                        {
                            QGraphicsPixmapItem *signalRightDownPixmapItem = scene->addPixmap(*shuntRightDownPixmap);
                            signalRightDownPixmapItem->setPos(displayX,displayY);
                        }
                        else
                        {
                            QGraphicsPixmapItem *signalRightDownPixmapItem = scene->addPixmap(*signalRightDownPixmap);
                            signalRightDownPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *bridge1PixmapItem = scene->addPixmap(*bridgeUnset1Pixmap);
                        bridge1PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::BRIDGE2:
                    {
                        QGraphicsPixmapItem *bridge2PixmapItem = scene->addPixmap(*bridgeUnset2Pixmap);
                        bridge2PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::UNDERPASS1:
                    {
                        QGraphicsPixmapItem *underpass1PixmapItem = scene->addPixmap(*underpassUnset1Pixmap);
                        underpass1PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::UNDERPASS2:
                    {
                        QGraphicsPixmapItem *underpass2PixmapItem = scene->addPixmap(*underpassUnset2Pixmap);
                        underpass2PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *switchTight1PixmapItem = scene->addPixmap(*switchTight1Pixmap);
                        switchTight1PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT2:
                    {
                        QGraphicsPixmapItem *switchTight2PixmapItem = scene->addPixmap(*switchTight2Pixmap);
                        switchTight2PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT3:
                    {
                        QGraphicsPixmapItem *switchTight3PixmapItem = scene->addPixmap(*switchTight3Pixmap);
                        switchTight3PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT4:
                    {
                        QGraphicsPixmapItem *switchTight4PixmapItem = scene->addPixmap(*switchTight4Pixmap);
                        switchTight4PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT5:
                    {
                        QGraphicsPixmapItem *switchTight5PixmapItem = scene->addPixmap(*switchTight5Pixmap);
                        switchTight5PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT6:
                    {
                        QGraphicsPixmapItem *switchTight6PixmapItem = scene->addPixmap(*switchTight6Pixmap);
                        switchTight6PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT7:
                    {
                        QGraphicsPixmapItem *switchTight7PixmapItem = scene->addPixmap(*switchTight7Pixmap);
                        switchTight7PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHTIGHT8:
                    {
                        QGraphicsPixmapItem *switchTight8PixmapItem = scene->addPixmap(*switchTight8Pixmap);
                        switchTight8PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHSPLIT1:
                    {
                        QGraphicsPixmapItem *switchSplit1PixmapItem = scene->addPixmap(*switchSplit1Pixmap);
                        switchSplit1PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCHSPLIT2:
                    {
                        QGraphicsPixmapItem *switchSplit2PixmapItem = scene->addPixmap(*switchSplit2Pixmap);
                        switchSplit2PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCHSPLIT3:
                    {
                        QGraphicsPixmapItem *switchSplit3PixmapItem = scene->addPixmap(*switchSplit3Pixmap);
                        switchSplit3PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH1:
                    {
                        QGraphicsPixmapItem *switch1PixmapItem = scene->addPixmap(*switch1Pixmap);
                        switch1PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH2:
                    {
                        QGraphicsPixmapItem *switch2PixmapItem = scene->addPixmap(*switch2Pixmap);
                        switch2PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformDownUnsetPixmapItem = scene->addPixmap(*platformDownUnsetPixmap);
                            platformDownUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH3:
                    {
                        QGraphicsPixmapItem *switch3PixmapItem = scene->addPixmap(*switch3Pixmap);
                        switch3PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH4:
                    {
                        QGraphicsPixmapItem *switch4PixmapItem = scene->addPixmap(*switch4Pixmap);
                        switch4PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformUpUnsetPixmapItem = scene->addPixmap(*platformUpUnsetPixmap);
                            platformUpUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH5:
                    {
                        QGraphicsPixmapItem *switch5PixmapItem = scene->addPixmap(*switch5Pixmap);
                        switch5PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH6:
                    {
                        QGraphicsPixmapItem *switch6PixmapItem = scene->addPixmap(*switch6Pixmap);
                        switch6PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH7:
                    {
                        QGraphicsPixmapItem *switch7PixmapItem = scene->addPixmap(*switch7Pixmap);
                        switch7PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform2())
                        {
                            QGraphicsPixmapItem *platformRightUnsetPixmapItem = scene->addPixmap(*platformRightUnsetPixmap);
                            platformRightUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCH8:
                    {
                        QGraphicsPixmapItem *switch8PixmapItem = scene->addPixmap(*switch8Pixmap);
                        switch8PixmapItem->setPos(displayX,displayY);
                        if (currentElement->getPlatform1())
                        {
                            QGraphicsPixmapItem *platformLeftUnsetPixmapItem = scene->addPixmap(*platformLeftUnsetPixmap);
                            platformLeftUnsetPixmapItem->setPos(displayX,displayY);
                        }
                        break;
                    }
                    case ElementType::SWITCHSPLIT4:
                    {
                        QGraphicsPixmapItem *switchSplit4PixmapItem = scene->addPixmap(*switchSplit4Pixmap);
                        switchSplit4PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCHSPLIT5:
                    {
                        QGraphicsPixmapItem *switchSplit5PixmapItem = scene->addPixmap(*switchSplit5Pixmap);
                        switchSplit5PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCHSPLIT6:
                    {
                        QGraphicsPixmapItem *switchSplit6PixmapItem = scene->addPixmap(*switchSplit6Pixmap);
                        switchSplit6PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH9:
                    {
                        QGraphicsPixmapItem *switch9PixmapItem = scene->addPixmap(*switch9Pixmap);
                        switch9PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH10:
                    {
                        QGraphicsPixmapItem *switch10PixmapItem = scene->addPixmap(*switch10Pixmap);
                        switch10PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH11:
                    {
                        QGraphicsPixmapItem *switch11PixmapItem = scene->addPixmap(*switch11Pixmap);
                        switch11PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH12:
                    {
                        QGraphicsPixmapItem *switch12PixmapItem = scene->addPixmap(*switch12Pixmap);
                        switch12PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH13:
                    {
                        QGraphicsPixmapItem *switch13PixmapItem = scene->addPixmap(*switch13Pixmap);
                        switch13PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH14:
                    {
                        QGraphicsPixmapItem *switch14PixmapItem = scene->addPixmap(*switch14Pixmap);
                        switch14PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH15:
                    {
                        QGraphicsPixmapItem *switch15PixmapItem = scene->addPixmap(*switch15Pixmap);
                        switch15PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCH16:
                    {
                        QGraphicsPixmapItem *switch16PixmapItem = scene->addPixmap(*switch16Pixmap);
                        switch16PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCHSPLIT7:
                    {
                        QGraphicsPixmapItem *switchSplit7PixmapItem = scene->addPixmap(*switchSplit7Pixmap);
                        switchSplit7PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::SWITCHSPLIT8:
                    {
                        QGraphicsPixmapItem *switchSplit8PixmapItem = scene->addPixmap(*switchSplit8Pixmap);
                        switchSplit8PixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *crossover1PixmapItem = scene->addPixmap(*crossover1Pixmap);
                        crossover1PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                   case ElementType::CROSSOVER2:
                    {
                        QGraphicsPixmapItem *crossover2PixmapItem = scene->addPixmap(*crossover2Pixmap);
                        crossover2PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                   case ElementType::CROSSOVER3:
                    {
                        QGraphicsPixmapItem *crossover3PixmapItem = scene->addPixmap(*crossover3Pixmap);
                        crossover3PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                   case ElementType::CROSSOVER4:
                    {
                        QGraphicsPixmapItem *crossover4PixmapItem = scene->addPixmap(*crossover4Pixmap);
                        crossover4PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                   case ElementType::CROSSOVER5:
                    {
                        QGraphicsPixmapItem *crossover5PixmapItem = scene->addPixmap(*crossover5Pixmap);
                        crossover5PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                   case ElementType::CROSSOVER6:
                    {
                        QGraphicsPixmapItem *crossover6PixmapItem = scene->addPixmap(*crossover6Pixmap);
                        crossover6PixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    {
                        QGraphicsPixmapItem *flyover1PixmapItem = scene->addPixmap(*flyover1Pixmap);
                        flyover1PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER2:
                    {
                        QGraphicsPixmapItem *flyover2PixmapItem = scene->addPixmap(*flyover2Pixmap);
                        flyover2PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER3:
                    {
                        QGraphicsPixmapItem *flyover3PixmapItem = scene->addPixmap(*flyover3Pixmap);
                        flyover3PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER4:
                    {
                        QGraphicsPixmapItem *flyover4PixmapItem = scene->addPixmap(*flyover4Pixmap);
                        flyover4PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER5:
                    {
                        QGraphicsPixmapItem *flyover5PixmapItem = scene->addPixmap(*flyover5Pixmap);
                        flyover5PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER6:
                    {
                        QGraphicsPixmapItem *flyover6PixmapItem = scene->addPixmap(*flyover6Pixmap);
                        flyover6PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER7:
                    {
                        QGraphicsPixmapItem *flyover7PixmapItem = scene->addPixmap(*flyover7Pixmap);
                        flyover7PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER8:
                    {
                        QGraphicsPixmapItem *flyover8PixmapItem = scene->addPixmap(*flyover8Pixmap);
                        flyover8PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER9:
                    {
                        QGraphicsPixmapItem *flyover9PixmapItem = scene->addPixmap(*flyover9Pixmap);
                        flyover9PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER10:
                    {
                        QGraphicsPixmapItem *flyover10PixmapItem = scene->addPixmap(*flyover10Pixmap);
                        flyover10PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER11:
                    {
                        QGraphicsPixmapItem *flyover11PixmapItem = scene->addPixmap(*flyover11Pixmap);
                        flyover11PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::FLYOVER12:
                    {
                        QGraphicsPixmapItem *flyover12PixmapItem = scene->addPixmap(*flyover12Pixmap);
                        flyover12PixmapItem->setPos(displayX,displayY);
                        break;
                    }
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
                    QGraphicsPixmapItem *namedLocationSetPixmapItem = scene->addPixmap(*namedLocationSetPixmap);
                    namedLocationSetPixmapItem->setPos(displayX,displayY);
                }
                else
                {
                    QGraphicsPixmapItem *namedLocationUnSetPixmapItem = scene->addPixmap(*namedLocationUnsetPixmap);
                    namedLocationUnSetPixmapItem->setPos(displayX,displayY);
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
                    QGraphicsPixmapItem *concourseSetPixmapItem = scene->addPixmap(*concourseSetPixmap);
                    concourseSetPixmapItem->setPos(displayX,displayY);

                }
                else
                {
                    QGraphicsPixmapItem *concourseUnSetPixmapItem = scene->addPixmap(*concourseUnsetPixmap);
                    concourseUnSetPixmapItem->setPos(displayX,displayY);

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
                    {
                        QGraphicsPixmapItem *parapet1PixmapItem = scene->addPixmap(*parapet1Pixmap);
                        parapet1PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET2:
                    {
                        QGraphicsPixmapItem *parapet2PixmapItem = scene->addPixmap(*parapet2Pixmap);
                        parapet2PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET3:
                    {
                        QGraphicsPixmapItem *parapet3PixmapItem = scene->addPixmap(*parapet3Pixmap);
                        parapet3PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET4:
                    {
                        QGraphicsPixmapItem *parapet4PixmapItem = scene->addPixmap(*parapet4Pixmap);
                        parapet4PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET5:
                    {
                        QGraphicsPixmapItem *parapet5PixmapItem = scene->addPixmap(*parapet5Pixmap);
                        parapet5PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET6:
                    {
                        QGraphicsPixmapItem *parapet6PixmapItem = scene->addPixmap(*parapet6Pixmap);
                        parapet6PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET7:
                    {
                        QGraphicsPixmapItem *parapet7PixmapItem = scene->addPixmap(*parapet7Pixmap);
                        parapet7PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET8:
                    {
                        QGraphicsPixmapItem *parapet8PixmapItem = scene->addPixmap(*parapet8Pixmap);
                        parapet8PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET9:
                    {
                        QGraphicsPixmapItem *parapet9PixmapItem = scene->addPixmap(*parapet9Pixmap);
                        parapet9PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET10:
                    {
                        QGraphicsPixmapItem *parapet10PixmapItem = scene->addPixmap(*parapet10Pixmap);
                        parapet10PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET11:
                    {
                        QGraphicsPixmapItem *parapet11PixmapItem = scene->addPixmap(*parapet11Pixmap);
                        parapet11PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET12:
                    {
                        QGraphicsPixmapItem *parapet12PixmapItem = scene->addPixmap(*parapet12Pixmap);
                        parapet12PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET13:
                    {
                        QGraphicsPixmapItem *parapet13PixmapItem = scene->addPixmap(*parapet13Pixmap);
                        parapet13PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET14:
                    {
                        QGraphicsPixmapItem *parapet14PixmapItem = scene->addPixmap(*parapet14Pixmap);
                        parapet14PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET15:
                    {
                        QGraphicsPixmapItem *parapet15PixmapItem = scene->addPixmap(*parapet15Pixmap);
                        parapet15PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET16:
                    {
                        QGraphicsPixmapItem *parapet16PixmapItem = scene->addPixmap(*parapet16Pixmap);
                        parapet16PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET17:
                    {
                        QGraphicsPixmapItem *parapet17PixmapItem = scene->addPixmap(*parapet17Pixmap);
                        parapet17PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET18:
                    {
                        QGraphicsPixmapItem *parapet18PixmapItem = scene->addPixmap(*parapet18Pixmap);
                        parapet18PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET19:
                    {
                        QGraphicsPixmapItem *parapet19PixmapItem = scene->addPixmap(*parapet19Pixmap);
                        parapet19PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET20:
                    {
                        QGraphicsPixmapItem *parapet20PixmapItem = scene->addPixmap(*parapet20Pixmap);
                        parapet20PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET21:
                    {
                        QGraphicsPixmapItem *parapet21PixmapItem = scene->addPixmap(*parapet21Pixmap);
                        parapet21PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET22:
                    {
                        QGraphicsPixmapItem *parapet22PixmapItem = scene->addPixmap(*parapet22Pixmap);
                        parapet22PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET23:
                    {
                        QGraphicsPixmapItem *parapet23PixmapItem = scene->addPixmap(*parapet23Pixmap);
                        parapet23PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET24:
                    {
                        QGraphicsPixmapItem *parapet24PixmapItem = scene->addPixmap(*parapet24Pixmap);
                        parapet24PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET25:
                    {
                        QGraphicsPixmapItem *parapet25PixmapItem = scene->addPixmap(*parapet25Pixmap);
                        parapet25PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET26:
                    {
                        QGraphicsPixmapItem *parapet26PixmapItem = scene->addPixmap(*parapet26Pixmap);
                        parapet26PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET27:
                    {
                        QGraphicsPixmapItem *parapet27PixmapItem = scene->addPixmap(*parapet27Pixmap);
                        parapet27PixmapItem->setPos(displayX,displayY);
                        break;
                    }
                    case ElementType::PARAPET28:
                    {
                        QGraphicsPixmapItem *parapet28PixmapItem = scene->addPixmap(*parapet27Pixmap);
                        parapet28PixmapItem->setPos(displayX,displayY);
                        break;
                    }
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


                QGraphicsTextItem *textItem = scene->addText(currentElement->getReadableText());
                textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
                textItem ->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
                textItem->setFocus();
                textItem->setPos(displayX,displayY);
                //painter.drawText(displayX, displayY, currentElement->getReadableText());
            }
        }
    }
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
    /*
    std::cout << "height: " << std::flush;
    std::cout << height() << std::flush;
    std::cout << " width: " << std::flush;
    std::cout << width() << std::flush;
    */
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
    if (event->button() == Qt::LeftButton)
    {
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
                if (!drawnLayout->checkTextExists(finalX,finalY)) {
                    QString readableBit = "Enter text: ";
                    std::shared_ptr<Text> text(new Text(*canvasChosen, finalX, finalY, readableBit));
                    drawnLayout->addText(text);
                }
                else
                {
                    foreach(QGraphicsItem *item, items())
                    {
                        if (item->x() == finalX)
                        {
                            if (item->y()==finalY){
                                //item->setTextInteractionFlags(Qt::TextEditorInteraction);
                                item ->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
                                item->setFocus();
                            }
                        }
                    }
                }


            }
        };
    }
    else if (event->button() == Qt::RightButton)
    {
        drawnLayout->deleteElement(finalX, finalY);
    }
    redraw();
}

/*void Canvas::paintEvent(QPaintEvent* event)
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
                */


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

    canvasSizeX = width();
    canvasSizeY = height();
    scene->setSceneRect(0, 0, canvasSizeX, canvasSizeY);


    redraw();
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




