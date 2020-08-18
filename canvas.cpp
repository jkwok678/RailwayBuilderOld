#include "canvas.h"

Canvas::Canvas()
{

    pal = palette();
    imageSize = 15;
    // set black background
    drawnLayout = new Map;
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    show();
    canvasSizeX = width();
    canvasSizeY = height();
    setMouseTracking(true);
    loadAllTrackImages();
    fillImageList();


    //Hints
    selectRed = new QImage(":/graphics/graphics/select1.png");
    selectGreen = new QImage(":/graphics/graphics/select2.png");
    selectBlue = new QImage(":/graphics/graphics/select3.png");

    setAutoFillBackground(true);
    setPalette(pal);
}

void Canvas::loadAllTrackImages()
{
    //ElementBlock1 images
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
    tightCurve1Image = new QImage(":/graphics/graphics/tightCurve1.png");
    tightCurve2Image = new QImage(":/graphics/graphics/tightCurve2.png");
    tightCurve3Image = new QImage(":/graphics/graphics/tightCurve3.png");
    tightCurve4Image = new QImage(":/graphics/graphics/tightCurve4.png");
    curve1Image = new QImage(":/graphics/graphics/curve1.png");
    curve2Image = new QImage(":/graphics/graphics/curve2.png");
    curve3Image = new QImage(":/graphics/graphics/curve3.png");
    curve4Image = new QImage(":/graphics/graphics/curve4.png");

    linkLeftUnsetImage = new QImage(":/graphics/graphics/linkLeftUnset.png");
    linkRightUnsetImage = new QImage(":/graphics/graphics/linkRightUnset.png");
    linkDownUnsetImage = new QImage(":/graphics/graphics/linkDownUnset.png");
    linkUpUnsetImage = new QImage(":/graphics/graphics/linkUpUnset.png");
    linkLeftUpUnsetImage = new QImage(":/graphics/graphics/linkLeftUpUnset.png");
    linkRightUpUnsetImage = new QImage(":/graphics/graphics/linkRightUpUnset.png");
    linkRightDownUnsetImage = new QImage(":/graphics/graphics/linkRightDownUnset.png");
    linkLeftDownUnsetImage = new QImage(":/graphics/graphics/linkLeftDownUnset.png");
    linkLeftSetImage = new QImage(":/graphics/graphics/linkLeftSet.png");
    linkRightSetImage = new QImage(":/graphics/graphics/linkRightSet.png");
    linkDownSetImage = new QImage(":/graphics/graphics/linkDownSet.png");
    linkUpSetImage = new QImage(":/graphics/graphics/linkUpSet.png");
    linkLeftUpSetImage = new QImage(":/graphics/graphics/linkLeftUpSet.png");
    linkRightUpSetImage = new QImage(":/graphics/graphics/linkRightUpSet.png");
    linkRightDownSetImage = new QImage(":/graphics/graphics/linkRightDownSet.png");
    linkLeftDownSetImage = new QImage(":/graphics/graphics/linkLeftDownSet.png");
    exitLeftImage = new QImage(":/graphics/graphics/exitLeft.png");
    exitRightImage = new QImage(":/graphics/graphics/exitRight.png");
    exitDownImage = new QImage(":/graphics/graphics/exitDown.png");
    exitUpImage = new QImage(":/graphics/graphics/exitUp.png");
    exitLeftUpImage = new QImage(":/graphics/graphics/exitLeftUp.png");
    exitRightUpImage = new QImage(":/graphics/graphics/exitRightUp.png");
    exitLeftDownImage = new QImage(":/graphics/graphics/exitLeftDown.png");
    exitRightDownImage = new QImage(":/graphics/graphics/exitRightDown.png");
    curve5Image = new QImage(":/graphics/graphics/curve5.png");
    curve6Image = new QImage(":/graphics/graphics/curve6.png");
    curve7Image = new QImage(":/graphics/graphics/curve7.png");
    curve8Image = new QImage(":/graphics/graphics/curve8.png");

    bufferLeftImage = new QImage(":/graphics/graphics/bufferLeft.png");
    bufferRightImage = new QImage(":/graphics/graphics/bufferRight.png");
    bufferDownImage = new QImage(":/graphics/graphics/bufferDown.png");
    bufferUpImage = new QImage(":/graphics/graphics/bufferUp.png");
    bufferLeftUpImage = new QImage(":/graphics/graphics/bufferLeftUp.png");
    bufferRightUpImage = new QImage(":/graphics/graphics/bufferRightUp.png");
    bufferLeftDownImage = new QImage(":/graphics/graphics/bufferLeftDown.png");
    bufferRightDownImage = new QImage(":/graphics/graphics/bufferRightDown.png");
    signalLeftImage = new QImage(":/graphics/graphics/signalLeft.png");
    signalRightImage = new QImage(":/graphics/graphics/signalRight.png");
    signalDownImage = new QImage(":/graphics/graphics/signalDown.png");
    signalUpImage = new QImage(":/graphics/graphics/signalUp.png");
    signalLeftUpImage = new QImage(":/graphics/graphics/signalLeftUp.png");
    signalRightUpImage = new QImage(":/graphics/graphics/signalRightUp.png");
    signalLeftDownImage = new QImage(":/graphics/graphics/signalLeftDown.png");
    signalRightDownImage = new QImage(":/graphics/graphics/signalRightDown.png");
    shuntLeftImage = new QImage(":/graphics/graphics/shuntLeftRed.png");
    shuntRightImage = new QImage(":/graphics/graphics/shuntRightRed.png");
    shuntDownImage = new QImage(":/graphics/graphics/shuntDownRed.png");
    shuntUpImage = new QImage(":/graphics/graphics/shuntUpRed.png");
    shuntLeftUpImage = new QImage(":/graphics/graphics/shuntLeftUpRed.png");
    shuntRightUpImage = new QImage(":/graphics/graphics/shuntRightUpRed.png");
    shuntLeftDownImage = new QImage(":/graphics/graphics/shuntLeftDownRed.png");
    shuntRightDownImage = new QImage(":/graphics/graphics/shuntRightDownRed.png");
    bridgeUnset1Image = new QImage(":/graphics/graphics/bridgeUnset1.png");
    bridgeUnset2Image = new QImage(":/graphics/graphics/bridgeUnset2.png");
    underpassUnset1Image = new QImage(":/graphics/graphics/underpassUnset1.png");
    underpassUnset2Image = new QImage(":/graphics/graphics/underpassUnset2.png");
    bridgeSet1Image = new QImage(":/graphics/graphics/brdigeSet1.png");
    bridgeSet2Image = new QImage(":/graphics/graphics/bridgeSet2.png");
    underpassSet1Image = new QImage(":/graphics/graphics/underpassSet1.png");
    underpassSet2Image = new QImage(":/graphics/graphics/underpassSet2.png");

    //ElementBlock2 images
    switchTight1Image = new QImage(":/graphics/graphics/switchTight1.png");
    switchTight2Image = new QImage(":/graphics/graphics/switchTight2.png");
    switchTight3Image = new QImage(":/graphics/graphics/switchTight3.png");
    switchTight4Image = new QImage(":/graphics/graphics/switchTight4.png");
    switchTight5Image = new QImage(":/graphics/graphics/switchTight5.png");
    switchTight6Image = new QImage(":/graphics/graphics/switchTight6.png");
    switchTight7Image = new QImage(":/graphics/graphics/switchTight7.png");
    switchTight8Image = new QImage(":/graphics/graphics/switchTight8.png");
    switchSplit1Image = new QImage(":/graphics/graphics/switchSplit1.png");
    switchSplit2Image = new QImage(":/graphics/graphics/switchSplit2.png");
    switchSplit3Image = new QImage(":/graphics/graphics/switchSplit3.png");

    switch1Image = new QImage(":/graphics/graphics/switch1.png");
    switch2Image = new QImage(":/graphics/graphics/switch2.png");
    switch3Image = new QImage(":/graphics/graphics/switch3.png");
    switch4Image = new QImage(":/graphics/graphics/switch4.png");
    switch5Image = new QImage(":/graphics/graphics/switch5.png");
    switch6Image = new QImage(":/graphics/graphics/switch6.png");
    switch7Image = new QImage(":/graphics/graphics/switch7.png");
    switch8Image = new QImage(":/graphics/graphics/switch8.png");
    switchSplit4Image = new QImage(":/graphics/graphics/switchSplit4.png");
    switchSplit5Image = new QImage(":/graphics/graphics/switchSplit5.png");
    switchSplit6Image = new QImage(":/graphics/graphics/switchSplit6.png");

    switch9Image = new QImage(":/graphics/graphics/switch9.png");
    switch10Image = new QImage(":/graphics/graphics/switch10.png");
    switch11Image = new QImage(":/graphics/graphics/switch11.png");
    switch12Image = new QImage(":/graphics/graphics/switch12.png");
    switch13Image = new QImage(":/graphics/graphics/switch13.png");
    switch14Image = new QImage(":/graphics/graphics/switch14.png");
    switch15Image = new QImage(":/graphics/graphics/switch15.png");
    switch16Image = new QImage(":/graphics/graphics/switch16.png");
    switchSplit7Image = new QImage(":/graphics/graphics/switchSplit7.png");
    switchSplit8Image = new QImage(":/graphics/graphics/switchSplit8.png");

    //ElementBlock3 images
    crossover1Image = new QImage(":/graphics/graphics/crossover1.png");
    crossover2Image = new QImage(":/graphics/graphics/crossover2.png");
    flyover1Image = new QImage(":/graphics/graphics/flyover1.png");
    flyover2Image = new QImage(":/graphics/graphics/flyover2.png");
    flyover3Image = new QImage(":/graphics/graphics/flyover3.png");
    flyover4Image = new QImage(":/graphics/graphics/flyover4.png");

    crossover3Image = new QImage(":/graphics/graphics/crossover3.png");
    crossover4Image = new QImage(":/graphics/graphics/crossover4.png");
    flyover5Image = new QImage(":/graphics/graphics/flyover5.png");
    flyover6Image = new QImage(":/graphics/graphics/flyover6.png");
    flyover7Image = new QImage(":/graphics/graphics/flyover7.png");
    flyover8Image = new QImage(":/graphics/graphics/flyover8.png");

    crossover5Image = new QImage(":/graphics/graphics/crossover5.png");
    crossover6Image = new QImage(":/graphics/graphics/crossover6.png");
    flyover9Image = new QImage(":/graphics/graphics/flyover9.png");
    flyover10Image = new QImage(":/graphics/graphics/flyover10.png");
    flyover11Image = new QImage(":/graphics/graphics/flyover11.png");
    flyover12Image = new QImage(":/graphics/graphics/flyover12.png");

    //ElementBlock4 images
    namedLocationUnsetImage = new QImage(":/graphics/graphics/namedLocationUnset.png");
    namedLocationSetImage = new QImage(":/graphics/graphics/namedLocationSet.png");
    concourseUnsetImage = new QImage(":/graphics/graphics/concourseUnset.png");
    concourseSetImage = new QImage(":/graphics/graphics/concourseSet.png");
    platformDownUnsetImage = new QImage(":/graphics/graphics/platformDownUnset.png");
    platformDownSetImage = new QImage(":/graphics/graphics/platformDownSet.png");
    platformUpUnsetImage = new QImage(":/graphics/graphics/platformUpUnset.png");
    platformUpSetImage = new QImage(":/graphics/graphics/platformUpSet.png");
    platformLeftUnsetImage = new QImage(":/graphics/graphics/platformLeftUnset.png");
    platformLeftSetImage = new QImage(":/graphics/graphics/platformLeftSet.png");
    platformRightUnsetImage = new QImage(":/graphics/graphics/platformRightUnset.png");
    platformRightSetImage = new QImage(":/graphics/graphics/platformRightSet.png");

    //ElementBlock5 images
    parapet1Image = new QImage(":/graphics/graphics/parapet1.png");
    parapet2Image = new QImage(":/graphics/graphics/parapet2.png");
    parapet3Image = new QImage(":/graphics/graphics/parapet3.png");
    parapet4Image = new QImage(":/graphics/graphics/parapet4.png");
    parapet5Image = new QImage(":/graphics/graphics/parapet5.png");
    parapet6Image = new QImage(":/graphics/graphics/parapet6.png");
    parapet7Image = new QImage(":/graphics/graphics/parapet7.png");
    parapet8Image = new QImage(":/graphics/graphics/parapet8.png");
    parapet9Image = new QImage(":/graphics/graphics/parapet9.png");
    parapet10Image = new QImage(":/graphics/graphics/parapet10.png");

    parapet11Image = new QImage(":/graphics/graphics/parapet11.png");
    parapet12Image = new QImage(":/graphics/graphics/parapet12.png");
    parapet13Image = new QImage(":/graphics/graphics/parapet13.png");
    parapet14Image = new QImage(":/graphics/graphics/parapet14.png");
    parapet15Image = new QImage(":/graphics/graphics/parapet15.png");
    parapet16Image = new QImage(":/graphics/graphics/parapet16.png");
    parapet17Image = new QImage(":/graphics/graphics/parapet17.png");
    parapet18Image = new QImage(":/graphics/graphics/parapet18.png");
    parapet19Image = new QImage(":/graphics/graphics/parapet19.png");
    parapet20Image = new QImage(":/graphics/graphics/parapet20.png");

    parapet21Image = new QImage(":/graphics/graphics/parapet21.png");
    parapet22Image = new QImage(":/graphics/graphics/parapet22.png");
    parapet23Image = new QImage(":/graphics/graphics/parapet23.png");
    parapet24Image = new QImage(":/graphics/graphics/parapet24.png");
    parapet25Image = new QImage(":/graphics/graphics/parapet25.png");
    parapet26Image = new QImage(":/graphics/graphics/parapet26.png");
    parapet27Image = new QImage(":/graphics/graphics/parapet27.png");
    parapet28Image = new QImage(":/graphics/graphics/parapet28.png");

    //ElementBlock6Image
    levelCrossingHImage = new QImage(":/graphics/graphics/levelCrossingH.png");
    levelCrossingVImage = new QImage(":/graphics/graphics/levelCrossingV.png");
}

void Canvas::fillImageList()
{
    //ElementBlock1 images
    imageList.push_back(straightHImage);
    imageList.push_back(straightVImage);
    imageList.push_back(directLeftImage);
    imageList.push_back(directRightImage);
    imageList.push_back(directUpImage);
    imageList.push_back(directDownImage);
    imageList.push_back(straightLeftUpImage);
    imageList.push_back(straightRightUpImage);
    imageList.push_back(directLeftUpImage);
    imageList.push_back(directRightUpImage);
    imageList.push_back(directRightDownIamge);
    imageList.push_back(directLeftDownImage);
    imageList.push_back(tightCurve1Image);
    imageList.push_back(tightCurve2Image);
    imageList.push_back(tightCurve3Image);
    imageList.push_back(tightCurve4Image);
    imageList.push_back(curve1Image);
    imageList.push_back(curve2Image);
    imageList.push_back(curve3Image);
    imageList.push_back(curve4Image);

    imageList.push_back(linkLeftUnsetImage);
    imageList.push_back(linkRightUnsetImage);
    imageList.push_back(linkDownUnsetImage);
    imageList.push_back(linkUpUnsetImage);
    imageList.push_back(linkLeftUpUnsetImage);
    imageList.push_back(linkRightUpUnsetImage);
    imageList.push_back(linkRightDownUnsetImage);
    imageList.push_back(linkLeftDownUnsetImage);
    imageList.push_back(linkLeftSetImage);
    imageList.push_back(linkRightSetImage);
    imageList.push_back(linkDownSetImage);
    imageList.push_back(linkUpSetImage);
    imageList.push_back(linkLeftUpSetImage);
    imageList.push_back(linkRightUpSetImage);
    imageList.push_back(linkRightDownSetImage);
    imageList.push_back(linkLeftDownSetImage);
    imageList.push_back(exitLeftImage);
    imageList.push_back(exitRightImage);
    imageList.push_back(exitDownImage);
    imageList.push_back(exitUpImage);
    imageList.push_back(exitLeftUpImage);
    imageList.push_back(exitRightUpImage);
    imageList.push_back(exitLeftDownImage);
    imageList.push_back(exitRightDownImage);
    imageList.push_back(curve5Image);
    imageList.push_back(curve6Image);
    imageList.push_back(curve7Image);
    imageList.push_back(curve8Image);

    imageList.push_back(bufferLeftImage);
    imageList.push_back(bufferRightImage);
    imageList.push_back(bufferDownImage);
    imageList.push_back(bufferUpImage);
    imageList.push_back(bufferLeftUpImage);
    imageList.push_back(bufferRightUpImage);
    imageList.push_back(bufferLeftDownImage);
    imageList.push_back(bufferRightDownImage);
    imageList.push_back(signalLeftImage);
    imageList.push_back(signalRightImage);
    imageList.push_back(signalDownImage);
    imageList.push_back(signalUpImage);
    imageList.push_back(signalLeftUpImage);
    imageList.push_back(signalRightUpImage);
    imageList.push_back(signalLeftDownImage);
    imageList.push_back(signalRightDownImage);
    imageList.push_back(shuntLeftImage);
    imageList.push_back(shuntRightImage);
    imageList.push_back(shuntDownImage);
    imageList.push_back(shuntUpImage);
    imageList.push_back(shuntLeftUpImage);
    imageList.push_back(shuntRightUpImage);
    imageList.push_back(shuntLeftDownImage);
    imageList.push_back(shuntRightDownImage);
    imageList.push_back(bridgeUnset1Image);
    imageList.push_back(bridgeUnset2Image);
    imageList.push_back(underpassUnset1Image);
    imageList.push_back(underpassUnset2Image);
    imageList.push_back(bridgeSet1Image);
    imageList.push_back(bridgeSet2Image);
    imageList.push_back(underpassSet1Image);
    imageList.push_back(underpassSet2Image);

    //ElementBlock2 images

    imageList.push_back(switchTight1Image);
    imageList.push_back(switchTight2Image);
    imageList.push_back(switchTight3Image);
    imageList.push_back(switchTight4Image);
    imageList.push_back(switchTight5Image);
    imageList.push_back(switchTight6Image);
    imageList.push_back(switchTight7Image);
    imageList.push_back(switchTight8Image);
    imageList.push_back(switchSplit1Image);
    imageList.push_back(switchSplit2Image);
    imageList.push_back(switchSplit3Image);

    imageList.push_back(switch1Image);
    imageList.push_back(switch2Image);
    imageList.push_back(switch3Image);
    imageList.push_back(switch4Image);
    imageList.push_back(switch5Image);
    imageList.push_back(switch6Image);
    imageList.push_back(switch7Image);
    imageList.push_back(switch8Image);
    imageList.push_back(switchSplit4Image);
    imageList.push_back(switchSplit5Image);
    imageList.push_back(switchSplit6Image);

    imageList.push_back(switch9Image);
    imageList.push_back(switch10Image);
    imageList.push_back(switch11Image);
    imageList.push_back(switch12Image);
    imageList.push_back(switch13Image);
    imageList.push_back(switch14Image);
    imageList.push_back(switch15Image);
    imageList.push_back(switch16Image);
    imageList.push_back(switchSplit7Image);
    imageList.push_back(switchSplit8Image);



    //ElementBlock3 images

    imageList.push_back(crossover1Image);
    imageList.push_back(crossover2Image);
    imageList.push_back(flyover1Image);
    imageList.push_back(flyover2Image);
    imageList.push_back(flyover3Image);
    imageList.push_back(flyover4Image);

    imageList.push_back(crossover3Image);
    imageList.push_back(crossover4Image);
    imageList.push_back(flyover5Image);
    imageList.push_back(flyover6Image);
    imageList.push_back(flyover7Image);
    imageList.push_back(flyover8Image);

    imageList.push_back(crossover5Image);
    imageList.push_back(crossover6Image);
    imageList.push_back(flyover9Image);
    imageList.push_back(flyover10Image);
    imageList.push_back(flyover11Image);
    imageList.push_back(flyover12Image);

    //ElementBlock6Image
    levelCrossingHImage = new QImage(":/graphics/graphics/levelCrossingH.png");
    levelCrossingVImage = new QImage(":/graphics/graphics/levelCrossingV.png");
}

Mode Canvas::getMode()
{
    return canvasChosen;
}

void Canvas::setMode(Mode newChosen)
{
    canvasChosen = newChosen;
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

QFont Canvas::getCurrentFont() const
{
    return currentFont;
}

void Canvas::setCurrentFont(QFont &newFont)
{
    currentFont = newFont;
}

Colour Canvas::getCanvasColour() const
{
    return canvasColour;
}

void Canvas::setCanvasColour(const Colour &newColour)
{
    canvasColour = newColour;
}

void Canvas::canvasChangeColour()
{
    if (canvasColour == Colour::LIGHT)
    {
        pal.setColor(QPalette::Window, Qt::white);
    }
    else if (canvasColour == Colour::DARKBLUE)
    {
        pal.setColor(QPalette::Window, Qt::darkBlue);
    }
    else
    {
        pal.setColor(QPalette::Window, Qt::black);
    }
    setPalette(pal);
    show();
}

void Canvas::trackChangeColour()
{
    if (canvasColour == Colour::LIGHT)
    {
        loadAllTrackImages();
    }
    else
    {
        for (QImage* image : imageList)
        {
            int height = image->height();
            int width = image->width();
            QColor black =  QColor(0,0,0,255);
            for (int y=0; y<height; y++)
            {
                for (int x=0; x<width;x++)
                {
                    if (image->pixelColor(x,y) == black)
                    {
                        image->setPixelColor(x,y,Qt::white);
                    }
                }
            }
        }
    }
}

void Canvas::stopSetTrackSpeedLength()
{
    drawnLayout->resetSetTrackSpeedLengthMechanics();
}

void Canvas::setTrackSpeedLength(int length, int speed)
{
    drawnLayout->setLengthSpeed(length, speed);
}

void Canvas::resetAllTrackSpeedLength()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("This will reset all current Track speeds and lengths. Continue?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes)
    {
        drawnLayout->makeTrackList();
        for (std::shared_ptr<Track> track : drawnLayout->getTrackList())
        {
            drawnLayout->restoreDefaultLengthSpeed(track);
        }
        drawnLayout->resetSetTrackSpeedLengthMechanics();
    }


}

void Canvas::resetSelectedTrackSpeedLength()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("This will reset the selected Track speeds and lengths. Continue?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes)
    {
        if (drawnLayout->getSetTrackSpeedLengthList().size()>0)
        {
            for (std::shared_ptr<Track> track : drawnLayout->getSetTrackSpeedLengthList())
            {
                drawnLayout->restoreDefaultLengthSpeed(track);
            }
        }
        drawnLayout->resetSetTrackSpeedLengthMechanics();
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

    int roundedX = exactX - extraX;
    int roundedY = exactY - extraY;
    //Calculate overall coordinate
    int finalX = ((roundedX + (offsetX*canvasSizeX)));
    int finalY;
    if (offsetY==0)
    {
        finalY = 0 - ((roundedY+ (offsetY*canvasSizeY)));
    } else if (offsetY<0 || offsetY >0)
    {
        finalY = 0 - (roundedY- (offsetY*canvasSizeY));
    }
    bool addedTrack = false;
    if (event->button() == Qt::LeftButton)
    {
        switch (canvasChosen)
        {
            case Mode::NONE:
            {
                QMessageBox noELementSelected;
                noELementSelected.setIcon(QMessageBox::Critical);
                noELementSelected.setText("No element has been selected.");
                noELementSelected.exec();
                break;
            }
            case Mode::STRAIGHTH:
            {
                std::shared_ptr<StraightTrack> straightH(new StraightTrack(StraightType::STRAIGHTH, finalX, finalY));
                drawnLayout->addStraightTrack(straightH);
                addedTrack = true;
                break;
            }
            case Mode::STRAIGHTV:
            {
                std::shared_ptr<StraightTrack> straightV(new StraightTrack(StraightType::STRAIGHTV, finalX, finalY));
                drawnLayout->addStraightTrack(straightV);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTLEFT:
            {
                std::shared_ptr<DirectTrack> directLeft(new DirectTrack(DirectType::DIRECTLEFT, finalX, finalY));
                drawnLayout->addDirectTrack(directLeft);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTRIGHT:
            {
                std::shared_ptr<DirectTrack> directRight(new DirectTrack(DirectType::DIRECTRIGHT, finalX, finalY));
                drawnLayout->addDirectTrack(directRight);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTUP:
            {
                std::shared_ptr<DirectTrack> directUp(new DirectTrack(DirectType::DIRECTUP, finalX, finalY));
                drawnLayout->addDirectTrack(directUp);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTDOWN:
            {
                std::shared_ptr<DirectTrack> directDown(new DirectTrack(DirectType::DIRECTDOWN, finalX, finalY));
                drawnLayout->addDirectTrack(directDown);
                addedTrack = true;
                break;
            }
            case Mode::STRIAGHTRIGHTUP:
            {
                std::shared_ptr<StraightTrack> straightRightUp(new StraightTrack(StraightType::STRIAGHTRIGHTUP, finalX, finalY));
                drawnLayout->addStraightTrack(straightRightUp);
                addedTrack = true;
                break;
            }
            case Mode::STRAIGHTLEFTUP:
            {
                std::shared_ptr<StraightTrack> straightLeftUp(new StraightTrack(StraightType::STRAIGHTLEFTUP, finalX, finalY));
                drawnLayout->addStraightTrack(straightLeftUp);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTRIGHTUP:
            {
                std::shared_ptr<DirectTrack> directRightUp(new DirectTrack(DirectType::DIRECTRIGHTUP, finalX, finalY));
                drawnLayout->addDirectTrack(directRightUp);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTLEFTUP:
            {
                std::shared_ptr<DirectTrack> directLeftUp(new DirectTrack(DirectType::DIRECTLEFTUP, finalX, finalY));
                drawnLayout->addDirectTrack(directLeftUp);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTLEFTDOWN:
            {
                std::shared_ptr<DirectTrack> directLeftDown(new DirectTrack(DirectType::DIRECTLEFTDOWN, finalX, finalY));
                drawnLayout->addDirectTrack(directLeftDown);
                addedTrack = true;
                break;
            }
            case Mode::DIRECTRIGHTDOWN:
            {
                std::shared_ptr<DirectTrack> directRightDown(new DirectTrack(DirectType::DIRECTRIGHTDOWN, finalX, finalY));
                drawnLayout->addDirectTrack(directRightDown);
                addedTrack = true;
                break;
            }

            case Mode::TIGHTCURVE1:
            {
                std::shared_ptr<CurvedTrack> tightCurve1(new CurvedTrack(CurvedType::TIGHTCURVE1, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve1);
                addedTrack = true;
                break;
            }
            case Mode::TIGHTCURVE2:
            {
                std::shared_ptr<CurvedTrack> tightCurve2(new CurvedTrack(CurvedType::TIGHTCURVE2, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve2);
                addedTrack = true;
                break;
            }
            case Mode::TIGHTCURVE3:
            {
                std::shared_ptr<CurvedTrack> tightCurve3(new CurvedTrack(CurvedType::TIGHTCURVE3, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve3);
                addedTrack = true;
                break;
            }
            case Mode::TIGHTCURVE4:
            {
                std::shared_ptr<CurvedTrack> tightCurve4(new CurvedTrack(CurvedType::TIGHTCURVE4, finalX, finalY));
                drawnLayout->addCurvedTrack(tightCurve4);
                addedTrack = true;
                break;                
            }
            case Mode::CURVE1:
            {
                std::shared_ptr<CurvedTrack> curve1(new CurvedTrack(CurvedType::CURVE1, finalX, finalY));
                drawnLayout->addCurvedTrack(curve1);
                addedTrack = true;
                break;
            }
            case Mode::CURVE2:
            {
                std::shared_ptr<CurvedTrack> curve2(new CurvedTrack(CurvedType::CURVE2, finalX, finalY));
                drawnLayout->addCurvedTrack(curve2);
                addedTrack = true;
                break;
            }
            case Mode::CURVE3:
            {
                std::shared_ptr<CurvedTrack> curve3(new CurvedTrack(CurvedType::CURVE3, finalX, finalY));
                drawnLayout->addCurvedTrack(curve3);
                addedTrack = true;
                break;
            }
            case Mode::CURVE4:
            {
                std::shared_ptr<CurvedTrack> curve4(new CurvedTrack(CurvedType::CURVE4, finalX, finalY));
                drawnLayout->addCurvedTrack(curve4);
                addedTrack = true;
                break;
            }
            case Mode::LINKLEFT:
            {
                std::shared_ptr<LinkedTrack> linkLeft(new LinkedTrack(LinkedType::LINKLEFT, finalX, finalY));
                drawnLayout->addLinkedTrack(linkLeft);
                addedTrack = true;
                break;
            }
            case Mode::LINKRIGHT:
            {
                std::shared_ptr<LinkedTrack> linkRight(new LinkedTrack(LinkedType::LINKRIGHT, finalX, finalY));
                drawnLayout->addLinkedTrack(linkRight);
                addedTrack = true;
                break;
            }
            case Mode::LINKDOWN:
            {
                std::shared_ptr<LinkedTrack> linkDown(new LinkedTrack(LinkedType::LINKDOWN, finalX, finalY));
                drawnLayout->addLinkedTrack(linkDown);
                addedTrack = true;
                break;
            }
            case Mode::LINKUP:
            {
                std::shared_ptr<LinkedTrack> linkUp(new LinkedTrack(LinkedType::LINKUP, finalX, finalY));
                drawnLayout->addLinkedTrack(linkUp);
                addedTrack = true;
                break;
            }
            case Mode::LINKLEFTUP:
            {
                std::shared_ptr<LinkedTrack> linkLeftUp(new LinkedTrack(LinkedType::LINKLEFTUP, finalX, finalY));
                drawnLayout->addLinkedTrack(linkLeftUp);
                addedTrack = true;
                break;
            }
            case Mode::LINKRIGHTUP:
            {
                std::shared_ptr<LinkedTrack> linkRightUp(new LinkedTrack(LinkedType::LINKRIGHTUP, finalX, finalY));
                drawnLayout->addLinkedTrack(linkRightUp);
                addedTrack = true;
                break;
            }
            case Mode::LINKRIGHTDOWN:
            {
                std::shared_ptr<LinkedTrack> linkRightDown(new LinkedTrack(LinkedType::LINKRIGHTDOWN, finalX, finalY));
                drawnLayout->addLinkedTrack(linkRightDown);
                addedTrack = true;
                break;
            }
            case Mode::LINKLEFTDOWN:
            {
                std::shared_ptr<LinkedTrack> linkLeftDown(new LinkedTrack(LinkedType::LINKLEFTDOWN, finalX, finalY));
                drawnLayout->addLinkedTrack(linkLeftDown);
                addedTrack = true;
                break;
            }
            case Mode::EXITLEFT:
            {
                std::shared_ptr<ExitTrack> exitLeft(new ExitTrack(ExitType::EXITLEFT, finalX, finalY));
                drawnLayout->addExitTrack(exitLeft);
                addedTrack = true;
                break;
            }
            case Mode::EXITRIGHT:
            {
                std::shared_ptr<ExitTrack> exitRight(new ExitTrack(ExitType::EXITRIGHT, finalX, finalY));
                drawnLayout->addExitTrack(exitRight);
                addedTrack = true;
                break;
            }
            case Mode::EXITDOWN:
            {
                std::shared_ptr<ExitTrack> exitDown(new ExitTrack(ExitType::EXITDOWN, finalX, finalY));
                drawnLayout->addExitTrack(exitDown);
                addedTrack = true;
                break;
            }
            case Mode::EXITUP:
            {
                std::shared_ptr<ExitTrack> exitUp(new ExitTrack(ExitType::EXITUP, finalX, finalY));
                drawnLayout->addExitTrack(exitUp);
                addedTrack = true;
                break;
            }
            case Mode::EXITLEFTUP:
            {
                std::shared_ptr<ExitTrack> exitLeftUp(new ExitTrack(ExitType::EXITLEFTUP, finalX, finalY));
                drawnLayout->addExitTrack(exitLeftUp);
                addedTrack = true;
                break;
            }
            case Mode::EXITRIGHTUP:
            {
                std::shared_ptr<ExitTrack> exitRightUp(new ExitTrack(ExitType::EXITRIGHTUP, finalX, finalY));
                drawnLayout->addExitTrack(exitRightUp);
                addedTrack = true;
                break;
            }

            case Mode::EXITLEFTDOWN:
            {
                std::shared_ptr<ExitTrack> exitLeftDown(new ExitTrack(ExitType::EXITLEFTDOWN, finalX, finalY));
                drawnLayout->addExitTrack(exitLeftDown);
                addedTrack = true;
                break;
            }
            case Mode::EXITRIGHTDOWN:
            {
                std::shared_ptr<ExitTrack> exitRightDown(new ExitTrack(ExitType::EXITRIGHTDOWN, finalX, finalY));
                drawnLayout->addExitTrack(exitRightDown);
                addedTrack = true;
                break;
            }
            case Mode::CURVE5:
            {
                std::shared_ptr<CurvedTrack> curve5(new CurvedTrack(CurvedType::CURVE5, finalX, finalY));
                drawnLayout->addCurvedTrack(curve5);
                addedTrack = true;
                break;
            }
            case Mode::CURVE6:
            {
                std::shared_ptr<CurvedTrack> curve6(new CurvedTrack(CurvedType::CURVE6, finalX, finalY));
                drawnLayout->addCurvedTrack(curve6);
                addedTrack = true;
                break;
            }
            case Mode::CURVE7:
            {
                std::shared_ptr<CurvedTrack> curve7(new CurvedTrack(CurvedType::CURVE7, finalX, finalY));
                drawnLayout->addCurvedTrack(curve7);
                addedTrack = true;
                break;
            }
            case Mode::CURVE8:
            {
                std::shared_ptr<CurvedTrack> curve8(new CurvedTrack(CurvedType::CURVE8, finalX, finalY));
                drawnLayout->addCurvedTrack(curve8);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERLEFT:
            {
                std::shared_ptr<BufferTrack> bufferLeft(new BufferTrack(BufferType::BUFFERLEFT, finalX, finalY));
                drawnLayout->addBufferTrack(bufferLeft);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERRIGHT:
            {
                std::shared_ptr<BufferTrack> bufferRight(new BufferTrack(BufferType::BUFFERRIGHT, finalX, finalY));
                drawnLayout->addBufferTrack(bufferRight);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERDOWN:
            {
                std::shared_ptr<BufferTrack> bufferDown(new BufferTrack(BufferType::BUFFERDOWN, finalX, finalY));
                drawnLayout->addBufferTrack(bufferDown);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERUP:
            {
                std::shared_ptr<BufferTrack> bufferUp(new BufferTrack(BufferType::BUFFERUP, finalX, finalY));
                drawnLayout->addBufferTrack(bufferUp);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERLEFTUP:
            {
                std::shared_ptr<BufferTrack> bufferLeftUp(new BufferTrack(BufferType::BUFFERLEFTUP, finalX, finalY));
                drawnLayout->addBufferTrack(bufferLeftUp);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERRIGHTUP:
            {
                std::shared_ptr<BufferTrack> bufferRightUp(new BufferTrack(BufferType::BUFFERRIGHTUP, finalX, finalY));
                drawnLayout->addBufferTrack(bufferRightUp);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERLEFTDOWN:
            {
                std::shared_ptr<BufferTrack> bufferLeftDown(new BufferTrack(BufferType::BUFFERLEFTDOWN, finalX, finalY));
                drawnLayout->addBufferTrack(bufferLeftDown);
                addedTrack = true;
                break;
            }
            case Mode::BUFFERRIGHTDOWN:
            {
                std::shared_ptr<BufferTrack> bufferRightDown(new BufferTrack(BufferType::BUFFERRIGHTDOWN, finalX, finalY));
                drawnLayout->addBufferTrack(bufferRightDown);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALLEFT:
            {
                std::shared_ptr<SignalTrack> signalLeft(new SignalTrack(SignalType::SIGNALLEFT, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalLeft);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALRIGHT:
            {
                std::shared_ptr<SignalTrack> signalRight(new SignalTrack(SignalType::SIGNALRIGHT, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalRight);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALDOWN:
            {
                std::shared_ptr<SignalTrack> signalDown(new SignalTrack(SignalType::SIGNALDOWN, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalDown);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALUP:
            {
                std::shared_ptr<SignalTrack> signalUp(new SignalTrack(SignalType::SIGNALUP, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalUp);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALLEFTUP:
            {
                std::shared_ptr<SignalTrack> signalLeftUp(new SignalTrack(SignalType::SIGNALLEFTUP, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalLeftUp);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALRIGHTUP:
            {
                std::shared_ptr<SignalTrack> signalRightUp(new SignalTrack(SignalType::SIGNALRIGHTUP, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalRightUp);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALLEFTDOWN:
            {
                std::shared_ptr<SignalTrack> signalLeftDown(new SignalTrack(SignalType::SIGNALLEFTDOWN, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalLeftDown);
                addedTrack = true;
                break;
            }
            case Mode::SIGNALRIGHTDOWN:
            {
                std::shared_ptr<SignalTrack> signalRightDown(new SignalTrack(SignalType::SIGNALRIGHTDOWN, canvasAspect, finalX, finalY));
                drawnLayout->addSignalTrack(signalRightDown);
                addedTrack = true;
                break;
            }
            case Mode::BRIDGE1:
            {
                std::shared_ptr<BridgeUnderpassTrack> bridge1(new BridgeUnderpassTrack(BridgeUnderpassType::BRIDGE1, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(bridge1);
                addedTrack = true;
                break;
            }
            case Mode::BRIDGE2:
            {
                std::shared_ptr<BridgeUnderpassTrack> bridge2(new BridgeUnderpassTrack(BridgeUnderpassType::BRIDGE2, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(bridge2);
                addedTrack = true;
                break;
            }
            case Mode::UNDERPASS1:
            {
                std::shared_ptr<BridgeUnderpassTrack> underpass1(new BridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS1, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(underpass1);
                addedTrack = true;
                break;
            }
            case Mode::UNDERPASS2:
            {
                std::shared_ptr<BridgeUnderpassTrack> underpass2(new BridgeUnderpassTrack(BridgeUnderpassType::UNDERPASS2, finalX, finalY));
                drawnLayout->addBridgeUnderpassTrack(underpass2);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT1:
            {
                std::shared_ptr<SwitchTrack> switchTight1(new SwitchTrack(SwitchType::SWITCHTIGHT1, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight1);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT2:
            {
                std::shared_ptr<SwitchTrack> switchTight2(new SwitchTrack(SwitchType::SWITCHTIGHT2, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight2);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT3:
            {
                std::shared_ptr<SwitchTrack> switchTight3(new SwitchTrack(SwitchType::SWITCHTIGHT3, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight3);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT4:
            {
                std::shared_ptr<SwitchTrack> switchTight4(new SwitchTrack(SwitchType::SWITCHTIGHT4, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight4);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT5:
            {
                std::shared_ptr<SwitchTrack> switchTight5(new SwitchTrack(SwitchType::SWITCHTIGHT5, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight5);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT6:
            {
                std::shared_ptr<SwitchTrack> switchTight6(new SwitchTrack(SwitchType::SWITCHTIGHT6, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight6);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT7:
            {
                std::shared_ptr<SwitchTrack> switchTight7(new SwitchTrack(SwitchType::SWITCHTIGHT7, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight7);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHTIGHT8:
            {
                std::shared_ptr<SwitchTrack> switchTight8(new SwitchTrack(SwitchType::SWITCHTIGHT8, finalX, finalY));
                drawnLayout->addSwitchTrack(switchTight8);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT1:
            {
                std::shared_ptr<SwitchTrack> switchSplit1(new SwitchTrack(SwitchType::SWITCHSPLIT1, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit1);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT2:
            {
                std::shared_ptr<SwitchTrack> switchSplit2(new SwitchTrack(SwitchType::SWITCHSPLIT2, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit2);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT3:
            {
                std::shared_ptr<SwitchTrack> switchSplit3(new SwitchTrack(SwitchType::SWITCHSPLIT3, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit3);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH1:
            {
                std::shared_ptr<SwitchTrack> switch1(new SwitchTrack(SwitchType::SWITCH1, finalX, finalY));
                drawnLayout->addSwitchTrack(switch1);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH2:
            {
                std::shared_ptr<SwitchTrack> switch2(new SwitchTrack(SwitchType::SWITCH2, finalX, finalY));
                drawnLayout->addSwitchTrack(switch2);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH3:
            {
                std::shared_ptr<SwitchTrack> switch3(new SwitchTrack(SwitchType::SWITCH3, finalX, finalY));
                drawnLayout->addSwitchTrack(switch3);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH4:
            {
                std::shared_ptr<SwitchTrack> switch4(new SwitchTrack(SwitchType::SWITCH4, finalX, finalY));
                drawnLayout->addSwitchTrack(switch4);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH5:
            {
                std::shared_ptr<SwitchTrack> switch5(new SwitchTrack(SwitchType::SWITCH5, finalX, finalY));
                drawnLayout->addSwitchTrack(switch5);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH6:
            {
                std::shared_ptr<SwitchTrack> switch6(new SwitchTrack(SwitchType::SWITCH6, finalX, finalY));
                drawnLayout->addSwitchTrack(switch6);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH7:
            {
                std::shared_ptr<SwitchTrack> switch7(new SwitchTrack(SwitchType::SWITCH7, finalX, finalY));
                drawnLayout->addSwitchTrack(switch7);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH8:
            {
                std::shared_ptr<SwitchTrack> switch8(new SwitchTrack(SwitchType::SWITCH8, finalX, finalY));
                drawnLayout->addSwitchTrack(switch8);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT4:
            {
                std::shared_ptr<SwitchTrack> switchSplit4(new SwitchTrack(SwitchType::SWITCHSPLIT4, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit4);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT5:
            {
                std::shared_ptr<SwitchTrack> switchSplit4(new SwitchTrack(SwitchType::SWITCHSPLIT5, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit4);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT6:
            {
                std::shared_ptr<SwitchTrack> switchSplit5(new SwitchTrack(SwitchType::SWITCHSPLIT6, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit5);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH9:
            {
                std::shared_ptr<SwitchTrack> switch9(new SwitchTrack(SwitchType::SWITCH9, finalX, finalY));
                drawnLayout->addSwitchTrack(switch9);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH10:
            {
                std::shared_ptr<SwitchTrack> switch10(new SwitchTrack(SwitchType::SWITCH10, finalX, finalY));
                drawnLayout->addSwitchTrack(switch10);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH11:
            {
                std::shared_ptr<SwitchTrack> switch11(new SwitchTrack(SwitchType::SWITCH11, finalX, finalY));
                drawnLayout->addSwitchTrack(switch11);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH12:
            {
                std::shared_ptr<SwitchTrack> switch12(new SwitchTrack(SwitchType::SWITCH12, finalX, finalY));
                drawnLayout->addSwitchTrack(switch12);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH13:
            {
                std::shared_ptr<SwitchTrack> switch13(new SwitchTrack(SwitchType::SWITCH13, finalX, finalY));
                drawnLayout->addSwitchTrack(switch13);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH14:
            {
                std::shared_ptr<SwitchTrack> switch14(new SwitchTrack(SwitchType::SWITCH14, finalX, finalY));
                drawnLayout->addSwitchTrack(switch14);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH15:
            {
                std::shared_ptr<SwitchTrack> switch15(new SwitchTrack(SwitchType::SWITCH15, finalX, finalY));
                drawnLayout->addSwitchTrack(switch15);
                addedTrack = true;
                break;
            }
            case Mode::SWITCH16:
            {
                std::shared_ptr<SwitchTrack> switch16(new SwitchTrack(SwitchType::SWITCH16, finalX, finalY));
                drawnLayout->addSwitchTrack(switch16);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT7:
            {
                std::shared_ptr<SwitchTrack> switchSplit7(new SwitchTrack(SwitchType::SWITCHSPLIT7, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit7);
                addedTrack = true;
                break;
            }
            case Mode::SWITCHSPLIT8:
            {
                std::shared_ptr<SwitchTrack> switchSplit8(new SwitchTrack(SwitchType::SWITCHSPLIT8, finalX, finalY));
                drawnLayout->addSwitchTrack(switchSplit8);
                addedTrack = true;
                break;
            }
            case Mode::CROSSOVER1:
            {
                std::shared_ptr<CrossoverTrack> crossover1(new CrossoverTrack(CrossoverType::CROSSOVER1, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover1);
                addedTrack = true;
                break;
            }
            case Mode::CROSSOVER2:
            {
                std::shared_ptr<CrossoverTrack> crossover2(new CrossoverTrack(CrossoverType::CROSSOVER2, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover2);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER1:
            {
                std::shared_ptr<FlyoverTrack> flyover1(new FlyoverTrack(FlyoverType::FLYOVER1, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover1);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER2:
            {
                std::shared_ptr<FlyoverTrack> flyover2(new FlyoverTrack(FlyoverType::FLYOVER2, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover2);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER3:
            {
                std::shared_ptr<FlyoverTrack> flyover3(new FlyoverTrack(FlyoverType::FLYOVER3, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover3);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER4:
            {
                std::shared_ptr<FlyoverTrack> flyover4(new FlyoverTrack(FlyoverType::FLYOVER4, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover4);
                addedTrack = true;
                break;
            }
            case Mode::CROSSOVER3:
            {
                std::shared_ptr<CrossoverTrack> crossover3(new CrossoverTrack(CrossoverType::CROSSOVER3, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover3);
                addedTrack = true;
                break;
            }
            case Mode::CROSSOVER4:
            {
                std::shared_ptr<CrossoverTrack> crossover4(new CrossoverTrack(CrossoverType::CROSSOVER4, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover4);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER5:
            {
                std::shared_ptr<FlyoverTrack> flyover5(new FlyoverTrack(FlyoverType::FLYOVER5, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover5);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER6:
            {
                std::shared_ptr<FlyoverTrack> flyover6(new FlyoverTrack(FlyoverType::FLYOVER6, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover6);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER7:
            {
                std::shared_ptr<FlyoverTrack> flyover7(new FlyoverTrack(FlyoverType::FLYOVER7, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover7);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER8:
            {
                std::shared_ptr<FlyoverTrack> flyover8(new FlyoverTrack(FlyoverType::FLYOVER8, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover8);
                addedTrack = true;
                break;
            }
            case Mode::CROSSOVER5:
            {
                std::shared_ptr<CrossoverTrack> crossover5(new CrossoverTrack(CrossoverType::CROSSOVER5, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover5);
                addedTrack = true;
                break;
            }
            case Mode::CROSSOVER6:
            {
                std::shared_ptr<CrossoverTrack> crossover6(new CrossoverTrack(CrossoverType::CROSSOVER6, finalX, finalY));
                drawnLayout->addCrossoverTrack(crossover6);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER9:
            {
                std::shared_ptr<FlyoverTrack> flyover9(new FlyoverTrack(FlyoverType::FLYOVER9, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover9);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER10:
            {
                std::shared_ptr<FlyoverTrack> flyover10(new FlyoverTrack(FlyoverType::FLYOVER10, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover10);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER11:
            {
                std::shared_ptr<FlyoverTrack> flyover11(new FlyoverTrack(FlyoverType::FLYOVER11, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover11);
                addedTrack = true;
                break;
            }
            case Mode::FLYOVER12:
            {
                std::shared_ptr<FlyoverTrack> flyover12(new FlyoverTrack(FlyoverType::FLYOVER12, finalX, finalY));
                drawnLayout->addFlyoverTrack(flyover12);
                addedTrack = true;
                break;
            }
            case Mode::NAMEDLOCATION:
            {
                std::shared_ptr<NamedLocation> namedLocation(new NamedLocation(finalX, finalY));
                drawnLayout->addNamedLocation(namedLocation);
                drawnLayout->linkNewBlockToText(finalX,finalY);
                break;
            }
            case Mode::CONCOURSE:
            {
                std::shared_ptr<Concourse> concourse(new Concourse(finalX, finalY));
                drawnLayout->addConcourse(concourse);
                drawnLayout->linkNewBlockToText(finalX,finalY);
                break;
            }
            case Mode::PLATFORMUP:
            {
                drawnLayout->addPlatform(Platform::UP, finalX, finalY);
                drawnLayout->linkNewBlockToText(finalX,finalY);
                break;
            }
            case Mode::PLATFORMDOWN:
            {
                drawnLayout->addPlatform(Platform::DOWN, finalX, finalY);
                drawnLayout->linkNewBlockToText(finalX,finalY);
                break;
            }
            case Mode::PLATFORMLEFT:
            {
                drawnLayout->addPlatform(Platform::LEFT, finalX, finalY);
                drawnLayout->linkNewBlockToText(finalX,finalY);
                break;
            }
            case Mode::PLATFORMRIGHT:
            {
                drawnLayout->addPlatform(Platform::RIGHT, finalX, finalY);
                drawnLayout->linkNewBlockToText(finalX,finalY);
                break;
            }
            case Mode::PARAPET1:
            {
                std::shared_ptr<Parapet> parapet1(new Parapet(ParapetType::PARAPET1, finalX, finalY));
                drawnLayout->addParapet(parapet1);
                break;
            }
            case Mode::PARAPET2:
            {
                std::shared_ptr<Parapet> parapet2(new Parapet(ParapetType::PARAPET2, finalX, finalY));
                drawnLayout->addParapet(parapet2);
                break;
            }
            case Mode::PARAPET3:
            {
                std::shared_ptr<Parapet> parapet3(new Parapet(ParapetType::PARAPET3, finalX, finalY));
                drawnLayout->addParapet(parapet3);
                break;
            }
            case Mode::PARAPET4:
            {
                std::shared_ptr<Parapet> parapet4(new Parapet(ParapetType::PARAPET4, finalX, finalY));
                drawnLayout->addParapet(parapet4);
                break;
            }
            case Mode::PARAPET5:
            {
                std::shared_ptr<Parapet> parapet5(new Parapet(ParapetType::PARAPET5, finalX, finalY));
                drawnLayout->addParapet(parapet5);
                break;
            }
            case Mode::PARAPET6:
            {
                std::shared_ptr<Parapet> parapet6(new Parapet(ParapetType::PARAPET6, finalX, finalY));
                drawnLayout->addParapet(parapet6);
                break;
            }
            case Mode::PARAPET7:
            {
                std::shared_ptr<Parapet> parapet7(new Parapet(ParapetType::PARAPET7, finalX, finalY));
                drawnLayout->addParapet(parapet7);
                break;
            }
            case Mode::PARAPET8:
            {
                std::shared_ptr<Parapet> parapet8(new Parapet(ParapetType::PARAPET8, finalX, finalY));
                drawnLayout->addParapet(parapet8);
                break;
            }
            case Mode::PARAPET9:
            {
                std::shared_ptr<Parapet> parapet9(new Parapet(ParapetType::PARAPET9, finalX, finalY));
                drawnLayout->addParapet(parapet9);
                break;
            }
            case Mode::PARAPET10:
            {
                std::shared_ptr<Parapet> parapet10(new Parapet(ParapetType::PARAPET10, finalX, finalY));
                drawnLayout->addParapet(parapet10);
                break;
            }
            case Mode::PARAPET11:
            {
                std::shared_ptr<Parapet> parapet11(new Parapet(ParapetType::PARAPET11, finalX, finalY));
                drawnLayout->addParapet(parapet11);
                break;
            }
            case Mode::PARAPET12:
            {
                std::shared_ptr<Parapet> parapet12(new Parapet(ParapetType::PARAPET12, finalX, finalY));
                drawnLayout->addParapet(parapet12);
                break;
            }
            case Mode::PARAPET13:
            {
                std::shared_ptr<Parapet> parapet13(new Parapet(ParapetType::PARAPET13, finalX, finalY));
                drawnLayout->addParapet(parapet13);
                break;
            }
            case Mode::PARAPET14:
            {
                std::shared_ptr<Parapet> parapet14(new Parapet(ParapetType::PARAPET14, finalX, finalY));
                drawnLayout->addParapet(parapet14);
                break;
            }
            case Mode::PARAPET15:
            {
                std::shared_ptr<Parapet> parapet15(new Parapet(ParapetType::PARAPET15, finalX, finalY));
                drawnLayout->addParapet(parapet15);
                break;
            }
            case Mode::PARAPET16:
            {
                std::shared_ptr<Parapet> parapet16(new Parapet(ParapetType::PARAPET16, finalX, finalY));
                drawnLayout->addParapet(parapet16);
                break;
            }
            case Mode::PARAPET17:
            {
                std::shared_ptr<Parapet> parapet17(new Parapet(ParapetType::PARAPET17, finalX, finalY));
                drawnLayout->addParapet(parapet17);
                break;
            }
            case Mode::PARAPET18:
            {
                std::shared_ptr<Parapet> parapet18(new Parapet(ParapetType::PARAPET18, finalX, finalY));
                drawnLayout->addParapet(parapet18);
                break;
            }
            case Mode::PARAPET19:
            {
                std::shared_ptr<Parapet> parapet19(new Parapet(ParapetType::PARAPET19, finalX, finalY));
                drawnLayout->addParapet(parapet19);
                break;
            }
            case Mode::PARAPET20:
            {
                std::shared_ptr<Parapet> parapet20(new Parapet(ParapetType::PARAPET20, finalX, finalY));
                drawnLayout->addParapet(parapet20);
                break;
            }
            case Mode::PARAPET21:
            {
                std::shared_ptr<Parapet> parapet21(new Parapet(ParapetType::PARAPET21, finalX, finalY));
                drawnLayout->addParapet(parapet21);
                break;
            }
            case Mode::PARAPET22:
            {
                std::shared_ptr<Parapet> parapet22(new Parapet(ParapetType::PARAPET22, finalX, finalY));
                drawnLayout->addParapet(parapet22);
                break;
            }
            case Mode::PARAPET23:
            {
                std::shared_ptr<Parapet> parapet23(new Parapet(ParapetType::PARAPET23, finalX, finalY));
                drawnLayout->addParapet(parapet23);
                break;
            }
            case Mode::PARAPET24:
            {
                std::shared_ptr<Parapet> parapet24(new Parapet(ParapetType::PARAPET24, finalX, finalY));
                drawnLayout->addParapet(parapet24);
                break;
            }
            case Mode::PARAPET25:
            {
                std::shared_ptr<Parapet> parapet25(new Parapet(ParapetType::PARAPET25, finalX, finalY));
                drawnLayout->addParapet(parapet25);
                break;
            }
            case Mode::PARAPET26:
            {
                std::shared_ptr<Parapet> parapet26(new Parapet(ParapetType::PARAPET26, finalX, finalY));
                drawnLayout->addParapet(parapet26);
                break;
            }
            case Mode::PARAPET27:
            {
                std::shared_ptr<Parapet> parapet27(new Parapet(ParapetType::PARAPET27, finalX, finalY));
                drawnLayout->addParapet(parapet27);
                break;
            }
            case Mode::PARAPET28:
            {
                std::shared_ptr<Parapet> parapet28(new Parapet(ParapetType::PARAPET28, finalX, finalY));
                drawnLayout->addParapet(parapet28);
                break;
            }
            case Mode::LEVELCROSSING:
            {
                drawnLayout->addLevelCrossing(finalX, finalY);
                break;
            }
            case Mode::ADDCHANGETEXT:
            {
                bool ok;
                int textX = exactX + (offsetX*canvasSizeX);
                int textY;
                if (offsetY==0)
                {
                    textY = 0 - ((exactY+ (offsetY*canvasSizeY)));
                }
                else
                {
                    textY = 0 - (exactY- (offsetY*canvasSizeY));
                }
                if (!drawnLayout->checkTextExists(textX,textY))
                {
                    QString readableBit = QInputDialog::getText(this, tr("Add text"), tr("Enter text:"), QLineEdit::Normal, tr(""), &ok);
                    if (readableBit.startsWith(" "))
                    {
                        readableBit.clear();
                    }
                    if(!readableBit.isEmpty())
                    {
                        std::shared_ptr<Text> text(new Text(textX, textY, readableBit, currentFont));
                        drawnLayout->addText(text);
                    }
                }
                else
                {
                    std::shared_ptr<Text> text = drawnLayout->getTextAt(textX,textY);
                    QString newReadableBit = QInputDialog::getText(this, tr("Add text"), tr("Enter text:"), QLineEdit::Normal, text->getReadableText(), &ok);
                    if (newReadableBit.startsWith(" "))
                    {
                        newReadableBit.clear();

                    }
                    if(!newReadableBit.isEmpty())
                    {
                        text->setReadableText(newReadableBit);
                    }
                    else
                    {
                        drawnLayout->deleteText(text);
                    }

                }
                break;
            }
            case Mode::MOVETEXT:
            {
                int textX = exactX + (offsetX*canvasSizeX);
                int textY;
                if (offsetY==0)
                {
                    textY = 0 - ((exactY+ (offsetY*canvasSizeY)));
                } else
                {
                    textY = 0 - (exactY- (offsetY*canvasSizeY));
                }
                if (drawnLayout->checkTextExists(textX,textY))
                {
                    moveText = drawnLayout->getTextAt(textX,textY);
                }
                break;
            }
            case Mode::SETCHANGENAMEDLOCATION:
            {
                bool exist = false;
                bool ok = false;
                std::shared_ptr<Track> track = drawnLayout->getTrackAt(finalX,finalY);
                std::shared_ptr<NamedElement> namedElement = drawnLayout->getNamedElementAt(finalX,finalY);
                std::shared_ptr<BridgeUnderpassTrack> bridgeUnderpassTrack = drawnLayout->getBridgeUnderpassTrack(finalX, finalY);
                QString readableBit;
                if (track != nullptr)
                {
                    if (track->getPlatformAny())
                    {
                        if (track->getNamed())
                        {
                            readableBit = QInputDialog::getText(this, tr("Add location"), tr("Enter location:"), QLineEdit::Normal
                            , track->getText()->getReadableText(), &ok);
                            std::shared_ptr<Text> text = track->getText();
                            if (readableBit.startsWith(" "))
                            {
                                readableBit.clear();
                            }
                            if(!readableBit.isEmpty())
                            {

                                text->setReadableText(readableBit);
                            }
                            else
                            {
                                drawnLayout->deleteTextFromAllElement(text);
                                drawnLayout->deleteText(text);
                            }
                        }
                        else
                        {
                            readableBit = QInputDialog::getText(this, tr("Add location"), tr("Enter location:"), QLineEdit::Normal, tr(""), &ok);
                            if (readableBit.startsWith(" "))
                            {
                                readableBit.clear();
                            }
                            if(!readableBit.isEmpty())
                            {
                                std::shared_ptr<Text> text(new Text(finalX, finalY, readableBit,currentFont));
                                drawnLayout->addText(text);
                                exist = true;
                                drawnLayout->linkLocalText(finalX, finalY, text);
                            }
                        }


                    }
                }
                if (bridgeUnderpassTrack != nullptr)
                {
                    if (bridgeUnderpassTrack->getNamed())
                    {
                        readableBit = QInputDialog::getText(this, tr("Add location"), tr("Enter location:"), QLineEdit::Normal
                        , track->getText()->getReadableText(), &ok);
                        std::shared_ptr<Text> text = track->getText();
                        if (readableBit.startsWith(" "))
                        {
                            readableBit.clear();
                        }
                        if(!readableBit.isEmpty())
                        {

                            text->setReadableText(readableBit);
                        }
                        else
                        {
                            drawnLayout->deleteTextFromAllElement(text);
                            drawnLayout->deleteText(text);
                        }
                    }
                    else
                    {
                        readableBit = QInputDialog::getText(this, tr("Add location"), tr("Enter location:"), QLineEdit::Normal, tr(""), &ok);
                        if (readableBit.startsWith(" "))
                        {
                            readableBit.clear();
                        }
                        if(!readableBit.isEmpty())
                        {
                            std::shared_ptr<Text> text(new Text(finalX, finalY, readableBit,currentFont));
                            drawnLayout->addText(text);
                            exist = true;
                            drawnLayout->linkLocalText(finalX, finalY, text);
                        }
                    }
                }


                if (namedElement != nullptr && exist == false)
                {
                    if (namedElement->getNamed())
                    {
                        readableBit = QInputDialog::getText(this, tr("Add location"), tr("Enter location:"), QLineEdit::Normal
                        , namedElement->getText()->getReadableText(), &ok);
                        std::shared_ptr<Text> text = namedElement->getText();
                        if (readableBit.startsWith(" "))
                        {
                            readableBit.clear();
                        }
                        if(!readableBit.isEmpty())
                        {

                            text->setReadableText(readableBit);
                        }
                        else
                        {
                            drawnLayout->deleteTextFromAllElement(text);
                            drawnLayout->deleteText(text);
                        }
                    }

                    else
                    {
                        readableBit = QInputDialog::getText(this, tr("Add location"), tr("Enter location:"), QLineEdit::Normal, tr(""), &ok);
                        if (readableBit.startsWith(" "))
                        {
                            readableBit.clear();
                        }
                        if(!readableBit.isEmpty())
                        {
                            std::shared_ptr<Text> text(new Text(finalX, finalY, readableBit, currentFont));
                            drawnLayout->addText(text);
                            exist = true;
                            drawnLayout->linkLocalText(finalX, finalY, text);
                        }

                    }
                }
                break;
            }
            case Mode::CONNECTLINKEDTRACK:
            {
                if (drawnLayout->getLinkedTrack1() == nullptr)
                {
                    if (drawnLayout->haslinkTrackAt(finalX,finalY))
                    {
                        std::shared_ptr<LinkedTrack> temp1 = drawnLayout->getLinkedTrackAt(finalX, finalY);
                        if (!temp1->getLinked())
                        {
                            drawnLayout->setLinkedTrack1(drawnLayout->getLinkedTrackAt(finalX, finalY));
                        }
                    }
                }
                else if (drawnLayout->getLinkedTrack2() == nullptr && drawnLayout->getLinkedTrack1() != nullptr)
                {
                    if (drawnLayout->checkElementExists(finalX,finalY))
                    {
                        std::shared_ptr<LinkedTrack> temp2 = drawnLayout->getLinkedTrackAt(finalX, finalY);
                        if (temp2 != drawnLayout->getLinkedTrack1())
                        {
                            if (!temp2->getLinked())
                            {
                                drawnLayout->setLinkedTrack2(drawnLayout->getLinkedTrackAt(finalX, finalY));
                                drawnLayout->connectLinkedTrack();
                            }

                        }
                    }

                }
                break;
            }
            case Mode::SETTRACKLENGTHSPEED:
            {
                if (drawnLayout->getTrackAt(finalX, finalY) != nullptr)
                {
                    std::shared_ptr<Track> track = drawnLayout->getTrackAt(finalX, finalY);
                    if (drawnLayout->getStart() == nullptr)
                    {
                        drawnLayout->setStart(track);
                    }
                    else
                    {
                        drawnLayout->setEnd(track);
                        drawnLayout->setSectionSpeedLength();
                        drawnLayout->resetFoundForAllTrack();
                        emit moreTracksAdded();
                    }

                }
                break;
            }
        };
        update();
        if (addedTrack)
        {

        }
    }
    else if (event->button() == Qt::RightButton)
    {
        drawnLayout->resetSetTrackSpeedLengthMechanics();
        if (drawnLayout->checkElementExists(finalX, finalY))
        {
            switch (canvasChosen)
            {
                case Mode::ADDCHANGETEXT:
                case Mode::MOVETEXT:
                case Mode::CONNECTLINKEDTRACK:
                case Mode::SETTRACKLENGTHSPEED:
                {

                    break;
                }
                default:
                {
                    drawnLayout->deleteElement(finalX, finalY);
                    update();
                    drawnLayout->setAllConnected(false);
                    break;
                }
            }
        }
    }
}

void Canvas::paintEvent(QPaintEvent* event)
{
    canvasSizeX = width();
    canvasSizeY = height();
    QPainter painter(this);
    //painter.drawImage(0, 704, *straightHImage);
    if (canvasChosen == Mode::SETTRACKLENGTHSPEED)
    {
        for (std::shared_ptr<StraightTrack> currentElement : drawnLayout->getStraightTrackList())
        {
            //Get the stored location of track relative to the canvas widget.
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();

            //Find the area you want to output, by using the offset and the size of the canvas widget.
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;

            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayX = ((offsetX+1) * canvasSizeX);
            int minDisplayY = ((offsetY-1) * canvasSizeY);
            int maxDisplayY = (offsetY*canvasSizeY);


            //Find the location on the canvas where you will draw
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getStraightType())
                    {
                        case StraightType::STRAIGHTH:
                        {
                            //std::cout<< currentElement->getNamed() << std::flush;

                            int height = straightHImage->height();
                            int width = straightHImage->width();
                            QColor black =  QColor(0,0,0,255);
                            QColor white = QColor(255,255,255,255);
                            QColor red =  QColor(255,0,0,255);
                            QColor green =  QColor(0,255,0,255);
                            QColor blue =  QColor(0,0,255,255);
                            if (currentElement->getTrackMainLength() == 100 && currentElement->getTrackMainSpeed() != 200)
                            {
                                for (int y=0; y<height; y++)
                                {
                                    for (int x=0; x<width;x++)
                                    {
                                        if (straightHImage->pixelColor(x,y) == black || straightHImage->pixelColor(x,y) == white)
                                        {
                                            straightHImage->setPixelColor(x,y,red);
                                        }
                                    }
                                }
                            }
                            else if (currentElement->getTrackMainLength() != 100 && currentElement->getTrackMainSpeed() == 200)
                            {
                                for (int y=0; y<height; y++)
                                {
                                    for (int x=0; x<width;x++)
                                    {
                                        if (straightHImage->pixelColor(x,y) == black || straightHImage->pixelColor(x,y) == white)
                                        {
                                            straightHImage->setPixelColor(x,y,green);
                                        }
                                    }
                                }
                            }
                            else if (currentElement->getTrackMainLength() != 100 && currentElement->getTrackMainSpeed() != 200)
                            {
                                for (int y=0; y<height; y++)
                                {
                                    for (int x=0; x<width;x++)
                                    {
                                        if (straightHImage->pixelColor(x,y) == black || straightHImage->pixelColor(x,y) == white)
                                        {
                                            straightHImage->setPixelColor(x,y,blue);
                                        }
                                    }
                                }
                            }

                            painter.drawImage(displayX, displayY, *straightHImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }

                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            if (currentElement->hasLevelCrossing())
                            {
                                painter.drawImage(displayX, displayY, *levelCrossingHImage);
                            }
                            break;
                        }
                        case StraightType::STRAIGHTV:
                        {
                            painter.drawImage(displayX, displayY, *straightVImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }

                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            if (currentElement->hasLevelCrossing())
                            {
                                painter.drawImage(displayX, displayY, *levelCrossingVImage);
                            }
                            break;
                        }
                        case StraightType::STRIAGHTRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *straightRightUpImage);
                            break;
                        }
                        case StraightType::STRAIGHTLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *straightLeftUpImage);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getDirectType())
                    {
                        case DirectType::DIRECTLEFT:
                        {
                            painter.drawImage(displayX, displayY, *directLeftImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }

                            }
                            if (currentElement->getPlatform2()) {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTRIGHT:
                        {
                            painter.drawImage(displayX, displayY, *directRightImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTUP:
                        {
                            painter.drawImage(displayX, displayY, *directUpImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2()) {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *directDownImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *directRightUpImage);
                            break;
                        }
                        case DirectType::DIRECTLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *directLeftUpImage);
                            break;
                        }
                        case DirectType::DIRECTLEFTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *directLeftDownImage);
                            break;
                        }
                        case DirectType::DIRECTRIGHTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *directRightDownIamge);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getCurvedType())
                    {
                        case CurvedType::TIGHTCURVE1:
                        {
                            painter.drawImage(displayX, displayY, *tightCurve1Image);
                            break;
                        }
                        case CurvedType::TIGHTCURVE2:
                        {
                            painter.drawImage(displayX, displayY, *tightCurve2Image);
                            break;
                        }
                        case CurvedType::TIGHTCURVE3:
                        {
                            painter.drawImage(displayX, displayY, *tightCurve3Image);
                            break;
                        }
                        case CurvedType::TIGHTCURVE4:
                            painter.drawImage(displayX, displayY, *tightCurve4Image);
                            break;
                        case CurvedType::CURVE1:
                        {
                            painter.drawImage(displayX, displayY, *curve1Image);
                            break;
                        }
                        case CurvedType::CURVE2:
                        {
                            painter.drawImage(displayX, displayY, *curve2Image);
                            break;
                        }
                        case CurvedType::CURVE3:
                        {
                            painter.drawImage(displayX, displayY, *curve3Image);
                            break;
                        }
                        case CurvedType::CURVE4:
                        {
                            painter.drawImage(displayX, displayY, *curve4Image);
                            break;
                        }
                        case CurvedType::CURVE5:
                        {
                            painter.drawImage(displayX, displayY, *curve5Image);
                            break;
                        }
                        case CurvedType::CURVE6:
                        {
                            painter.drawImage(displayX, displayY, *curve6Image);
                            break;
                        }
                        case CurvedType::CURVE7:
                        {
                            painter.drawImage(displayX, displayY, *curve7Image);
                            break;
                        }
                        case CurvedType::CURVE8:
                        {
                            painter.drawImage(displayX, displayY, *curve8Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getLinkedType())
                    {
                        case LinkedType::LINKLEFT:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkLeftUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkLeftSetImage);
                            }

                            break;
                        }
                        case LinkedType::LINKRIGHT:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkRightUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkRightSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKDOWN:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkDownUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkDownSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKUP:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkUpUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkUpSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKLEFTUP:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkLeftUpUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkLeftUpSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKRIGHTUP:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkRightUpUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkRightUpSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKRIGHTDOWN:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkRightDownUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkRightDownSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKLEFTDOWN:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkLeftDownUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkLeftDownSetImage);
                            }
                            break;
                        }
                    }
                    if (canvasChosen == Mode::CONNECTLINKEDTRACK)
                    {
                        if (currentElement == drawnLayout->getLinkedTrack1() || currentElement == drawnLayout->getLinkedTrack2())
                        {
                            painter.drawImage(displayX,displayY,*selectBlue);
                        }
                        else if (!currentElement->getLinked())
                        {
                            painter.drawImage(displayX,displayY,*selectRed);
                        }
                        else if (currentElement->getLinked())
                        {
                            painter.drawImage(displayX,displayY, * selectGreen);
                            painter.drawLine(displayX+8, displayY+8,
                            currentElement->getOtherLinkTrack()->getLocationX()+8- minDisplayX,
                            0-(currentElement->getOtherLinkTrack()->getLocationY()-8 - maxDisplayY));
                        }

                    }
                }
            }
        }

        for (std::shared_ptr<ExitTrack> currentElement : drawnLayout->getExitTrackList())
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getExitType())
                    {
                        case ExitType::EXITLEFT:
                        {
                            painter.drawImage(displayX, displayY, *exitLeftImage);
                            break;
                        }
                        case ExitType::EXITRIGHT:
                        {
                            painter.drawImage(displayX, displayY, *exitRightImage);
                            break;
                        }
                        case ExitType::EXITDOWN:
                        {
                            painter.drawImage(displayX, displayY, *exitDownImage);
                            break;
                        }
                        case ExitType::EXITUP:
                        {
                            painter.drawImage(displayX, displayY, *exitUpImage);
                            break;
                        }
                        case ExitType::EXITLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *exitLeftUpImage);
                            break;
                        }
                        case ExitType::EXITRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *exitRightUpImage);
                            break;
                        }
                        case ExitType::EXITLEFTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *exitLeftDownImage);
                            break;
                        }
                        case ExitType::EXITRIGHTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *exitRightDownImage);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getBufferType())
                    {
                        case BufferType::BUFFERLEFT:
                        {
                            painter.drawImage(displayX, displayY, *bufferLeftImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERRIGHT:
                        {
                            painter.drawImage(displayX, displayY, *bufferRightImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERDOWN:
                        {
                            painter.drawImage(displayX, displayY, *bufferDownImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERUP:
                        {
                            painter.drawImage(displayX, displayY, *bufferUpImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *bufferLeftUpImage);
                            break;
                        }
                        case BufferType::BUFFERRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *bufferRightUpImage);
                            break;
                        }
                        case BufferType::BUFFERLEFTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *bufferLeftDownImage);
                            break;
                        }
                        case BufferType::BUFFERRIGHTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *bufferRightDownImage);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getSignalType())
                    {
                        case SignalType::SIGNALLEFT:
                        {
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
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALRIGHT:
                        {
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
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALDOWN:
                        {
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
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALUP:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntUpImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalUpImage);
                            }
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALLEFTUP:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntLeftUpImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalLeftUpImage);
                            }
                            break;
                        }
                        case SignalType::SIGNALRIGHTUP:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntRightUpImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalRightUpImage);
                            }
                            break;
                        }
                        case SignalType::SIGNALLEFTDOWN:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntLeftDownImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalLeftDownImage);
                            }
                            break;
                        }
                        case SignalType::SIGNALRIGHTDOWN:
                        {
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
        }

        for (std::shared_ptr<BridgeUnderpassTrack> currentElement : drawnLayout->getBridgeUnderpassTrackList())
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getBridgeUnderpassType())
                    {
                        case BridgeUnderpassType::BRIDGE1:
                        {
                            painter.drawImage(displayX, displayY, *bridgeUnset1Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BridgeUnderpassType::BRIDGE2:
                        {
                            painter.drawImage(displayX, displayY, *bridgeUnset2Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case BridgeUnderpassType::UNDERPASS1:
                        {
                            painter.drawImage(displayX, displayY, *underpassUnset1Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BridgeUnderpassType::UNDERPASS2:
                        {
                            painter.drawImage(displayX, displayY, *underpassUnset2Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getSwitchType())
                    {
                        case SwitchType::SWITCHTIGHT1:
                        {
                            painter.drawImage(displayX, displayY, *switchTight1Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT2:
                        {
                            painter.drawImage(displayX, displayY, *switchTight2Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT3:
                        {
                            painter.drawImage(displayX, displayY, *switchTight3Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT4:
                        {
                            painter.drawImage(displayX, displayY, *switchTight4Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT5:
                        {
                            painter.drawImage(displayX, displayY, *switchTight5Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT6:
                        {
                            painter.drawImage(displayX, displayY, *switchTight6Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT7:
                        {
                            painter.drawImage(displayX, displayY, *switchTight7Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT8:
                        {
                            painter.drawImage(displayX, displayY, *switchTight8Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHSPLIT1:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit1Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT2:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit2Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT3:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit3Image);
                            break;
                        }
                        case SwitchType::SWITCH1:
                        {
                            painter.drawImage(displayX, displayY, *switch1Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH2:
                        {
                            painter.drawImage(displayX, displayY, *switch2Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH3:
                        {
                            painter.drawImage(displayX, displayY, *switch3Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH4:
                        {
                            painter.drawImage(displayX, displayY, *switch4Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH5:
                        {
                            painter.drawImage(displayX, displayY, *switch5Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH6:
                        {
                            painter.drawImage(displayX, displayY, *switch6Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH7:
                        {
                            painter.drawImage(displayX, displayY, *switch7Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH8:
                        {
                            painter.drawImage(displayX, displayY, *switch8Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHSPLIT4:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit4Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT5:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit5Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT6:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit6Image);
                            break;
                        }
                        case SwitchType::SWITCH9:
                        {
                            painter.drawImage(displayX, displayY, *switch9Image);
                            break;
                        }
                        case SwitchType::SWITCH10:
                        {
                            painter.drawImage(displayX, displayY, *switch10Image);
                            break;
                        }
                        case SwitchType::SWITCH11:
                        {
                            painter.drawImage(displayX, displayY, *switch11Image);
                            break;
                        }
                        case SwitchType::SWITCH12:
                        {
                            painter.drawImage(displayX, displayY, *switch12Image);
                            break;
                        }
                        case SwitchType::SWITCH13:
                        {
                            painter.drawImage(displayX, displayY, *switch13Image);
                            break;
                        }
                        case SwitchType::SWITCH14:
                        {
                            painter.drawImage(displayX, displayY, *switch14Image);
                            break;
                        }
                        case SwitchType::SWITCH15:
                        {
                            painter.drawImage(displayX, displayY, *switch15Image);
                            break;
                        }
                        case SwitchType::SWITCH16:
                        {
                            painter.drawImage(displayX, displayY, *switch16Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT7:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit7Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT8:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit8Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getCrossoverType())
                    {
                       case CrossoverType::CROSSOVER1:
                        {
                           painter.drawImage(displayX, displayY, *crossover1Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER2:
                        {
                           painter.drawImage(displayX, displayY, *crossover2Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER3:
                        {
                           painter.drawImage(displayX, displayY, *crossover3Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER4:
                        {
                           painter.drawImage(displayX, displayY, *crossover4Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER5:
                        {
                           painter.drawImage(displayX, displayY, *crossover5Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER6:
                        {
                           painter.drawImage(displayX, displayY, *crossover6Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getFlyoverType())
                    {
                        case FlyoverType::FLYOVER1:
                        {
                            painter.drawImage(displayX, displayY, *flyover1Image);
                            break;
                        }
                        case FlyoverType::FLYOVER2:
                        {
                            painter.drawImage(displayX, displayY, *flyover2Image);
                            break;
                        }
                        case FlyoverType::FLYOVER3:
                        {
                            painter.drawImage(displayX, displayY, *flyover3Image);
                            break;
                        }
                        case FlyoverType::FLYOVER4:
                        {
                            painter.drawImage(displayX, displayY, *flyover4Image);
                            break;
                        }
                        case FlyoverType::FLYOVER5:
                        {
                            painter.drawImage(displayX, displayY, *flyover5Image);
                            break;
                        }
                        case FlyoverType::FLYOVER6:
                        {
                            painter.drawImage(displayX, displayY, *flyover6Image);
                            break;
                        }
                        case FlyoverType::FLYOVER7:
                        {
                            painter.drawImage(displayX, displayY, *flyover7Image);
                            break;
                        }
                        case FlyoverType::FLYOVER8:
                        {
                            painter.drawImage(displayX, displayY, *flyover8Image);
                            break;
                        }
                        case FlyoverType::FLYOVER9:
                        {
                            painter.drawImage(displayX, displayY, *flyover9Image);
                            break;
                        }
                        case FlyoverType::FLYOVER10:
                        {
                            painter.drawImage(displayX, displayY, *flyover10Image);
                            break;
                        }
                        case FlyoverType::FLYOVER11:
                        {
                            painter.drawImage(displayX, displayY, *flyover11Image);
                            break;
                        }
                        case FlyoverType::FLYOVER12:
                        {
                            painter.drawImage(displayX, displayY, *flyover12Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getParapetType())
                    {
                        case ParapetType::PARAPET1:
                        {
                            painter.drawImage(displayX, displayY, *parapet1Image);
                            break;
                        }
                        case ParapetType::PARAPET2:
                        {
                            painter.drawImage(displayX, displayY, *parapet2Image);
                            break;
                        }
                        case ParapetType::PARAPET3:
                        {
                            painter.drawImage(displayX, displayY, *parapet3Image);
                            break;
                        }
                        case ParapetType::PARAPET4:
                        {
                            painter.drawImage(displayX, displayY, *parapet4Image);
                            break;
                        }
                        case ParapetType::PARAPET5:
                        {
                            painter.drawImage(displayX, displayY, *parapet5Image);
                            break;
                        }
                        case ParapetType::PARAPET6:
                        {
                            painter.drawImage(displayX, displayY, *parapet6Image);
                            break;
                        }
                        case ParapetType::PARAPET7:
                        {
                            painter.drawImage(displayX, displayY, *parapet7Image);
                            break;
                        }
                        case ParapetType::PARAPET8:
                        {
                            painter.drawImage(displayX, displayY, *parapet8Image);
                            break;
                        }
                        case ParapetType::PARAPET9:
                        {
                            painter.drawImage(displayX, displayY, *parapet9Image);
                            break;
                        }
                        case ParapetType::PARAPET10:
                        {
                            painter.drawImage(displayX, displayY, *parapet10Image);
                            break;
                        }
                        case ParapetType::PARAPET11:
                        {
                            painter.drawImage(displayX, displayY, *parapet11Image);
                            break;
                        }
                        case ParapetType::PARAPET12:
                        {
                            painter.drawImage(displayX, displayY, *parapet12Image);
                            break;
                        }
                        case ParapetType::PARAPET13:
                        {
                            painter.drawImage(displayX, displayY, *parapet13Image);
                            break;
                        }
                        case ParapetType::PARAPET14:
                        {
                            painter.drawImage(displayX, displayY, *parapet14Image);
                            break;
                        }
                        case ParapetType::PARAPET15:
                        {
                            painter.drawImage(displayX, displayY, *parapet15Image);
                            break;
                        }
                        case ParapetType::PARAPET16:
                        {
                            painter.drawImage(displayX, displayY, *parapet16Image);
                            break;
                        }
                        case ParapetType::PARAPET17:
                        {
                            painter.drawImage(displayX, displayY, *parapet17Image);
                            break;
                        }
                        case ParapetType::PARAPET18:
                        {
                            painter.drawImage(displayX, displayY, *parapet18Image);
                            break;
                        }
                        case ParapetType::PARAPET19:
                        {
                            painter.drawImage(displayX, displayY, *parapet19Image);
                            break;
                        }
                        case ParapetType::PARAPET20:
                        {
                            painter.drawImage(displayX, displayY, *parapet20Image);
                            break;
                        }
                        case ParapetType::PARAPET21:
                        {
                            painter.drawImage(displayX, displayY, *parapet21Image);
                            break;
                        }
                        case ParapetType::PARAPET22:
                        {
                            painter.drawImage(displayX, displayY, *parapet22Image);
                            break;
                        }
                        case ParapetType::PARAPET23:
                        {
                            painter.drawImage(displayX, displayY, *parapet23Image);
                            break;
                        }
                        case ParapetType::PARAPET24:
                        {
                            painter.drawImage(displayX, displayY, *parapet24Image);
                            break;
                        }
                        case ParapetType::PARAPET25:
                        {
                            painter.drawImage(displayX, displayY, *parapet25Image);
                            break;
                        }
                        case ParapetType::PARAPET26:
                        {
                            painter.drawImage(displayX, displayY, *parapet26Image);
                            break;
                        }
                        case ParapetType::PARAPET27:
                        {
                            painter.drawImage(displayX, displayY, *parapet27Image);
                            break;
                        }
                        case ParapetType::PARAPET28:
                        {
                            painter.drawImage(displayX, displayY, *parapet28Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    painter.setFont(currentElement->getFont());
                    painter.drawText(displayX, displayY, currentElement->getReadableText());
                }
            }
        }

        std::vector<std::shared_ptr<Track>> chosenList = drawnLayout->getSetTrackSpeedLengthList();

        if (!chosenList.empty())
        {
            for (std::shared_ptr<Track> track : chosenList)
            {
                int currentX = track->getLocationX();
                int currentY = track->getLocationY();
                int minCoordinateX = (offsetX * canvasSizeX);
                int maxCoordinateX = ((offsetX+1) * canvasSizeX);
                int minCoordinateY = ((offsetY-1) * canvasSizeY);
                int maxCoordinateY = (offsetY*canvasSizeY);;
                int minDisplayX = (offsetX * canvasSizeX);
                int maxDisplayY = (offsetY*canvasSizeY);
                if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
                {
                    if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                    {
                        int displayX = currentX- minDisplayX;
                        int displayY = 0-(currentY - maxDisplayY);
                        painter.drawImage(displayX,displayY,*selectBlue);
                    }
                }
            }
        }
        if (drawnLayout->getStart() != nullptr)
        {

            int currentX = drawnLayout->getStart()->getLocationX();
            int currentY = drawnLayout->getStart()->getLocationY();
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    painter.drawImage(displayX,displayY,*selectRed);
                }
            }
        }
        /*
        if (drawnLayout->getEnd() != nullptr)
        {
            int currentX = drawnLayout->getEnd()->getLocationX();
            int currentY = drawnLayout->getEnd()->getLocationY();
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    //painter.drawImage(displayX,displayY,*selectGreen);
                    painter.drawImage(displayX,displayY,*selectRed);
                }
            }
        }
        */

    }
    else
    {
        drawnLayout->resetSetTrackSpeedLengthMechanics();

        for (std::shared_ptr<StraightTrack> currentElement : drawnLayout->getStraightTrackList())
        {
            //Get the stored location of track relative to the canvas widget.
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();

            //Find the area you want to output, by using the offset and the size of the canvas widget.
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;

            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayX = ((offsetX+1) * canvasSizeX);
            int minDisplayY = ((offsetY-1) * canvasSizeY);
            int maxDisplayY = (offsetY*canvasSizeY);

            //Find the location on the canvas where you will draw
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getStraightType())
                    {
                        case StraightType::STRAIGHTH:
                        {
                            //std::cout<< currentElement->getNamed() << std::flush;
                            painter.drawImage(displayX, displayY, *straightHImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }

                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            if (currentElement->hasLevelCrossing())
                            {
                                painter.drawImage(displayX, displayY, *levelCrossingHImage);
                            }
                            break;
                        }
                        case StraightType::STRAIGHTV:
                        {
                            painter.drawImage(displayX, displayY, *straightVImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }

                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            if (currentElement->hasLevelCrossing())
                            {
                                painter.drawImage(displayX, displayY, *levelCrossingVImage);
                            }
                            break;
                        }
                        case StraightType::STRIAGHTRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *straightRightUpImage);
                            break;
                        }
                        case StraightType::STRAIGHTLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *straightLeftUpImage);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getDirectType())
                    {
                        case DirectType::DIRECTLEFT:
                        {
                            painter.drawImage(displayX, displayY, *directLeftImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }

                            }
                            if (currentElement->getPlatform2()) {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTRIGHT:
                        {
                            painter.drawImage(displayX, displayY, *directRightImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTUP:
                        {
                            painter.drawImage(displayX, displayY, *directUpImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2()) {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *directDownImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case DirectType::DIRECTRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *directRightUpImage);
                            break;
                        }
                        case DirectType::DIRECTLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *directLeftUpImage);
                            break;
                        }
                        case DirectType::DIRECTLEFTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *directLeftDownImage);
                            break;
                        }
                        case DirectType::DIRECTRIGHTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *directRightDownIamge);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getCurvedType())
                    {
                        case CurvedType::TIGHTCURVE1:
                        {
                            painter.drawImage(displayX, displayY, *tightCurve1Image);
                            break;
                        }
                        case CurvedType::TIGHTCURVE2:
                        {
                            painter.drawImage(displayX, displayY, *tightCurve2Image);
                            break;
                        }
                        case CurvedType::TIGHTCURVE3:
                        {
                            painter.drawImage(displayX, displayY, *tightCurve3Image);
                            break;
                        }
                        case CurvedType::TIGHTCURVE4:
                            painter.drawImage(displayX, displayY, *tightCurve4Image);
                            break;
                        case CurvedType::CURVE1:
                        {
                            painter.drawImage(displayX, displayY, *curve1Image);
                            break;
                        }
                        case CurvedType::CURVE2:
                        {
                            painter.drawImage(displayX, displayY, *curve2Image);
                            break;
                        }
                        case CurvedType::CURVE3:
                        {
                            painter.drawImage(displayX, displayY, *curve3Image);
                            break;
                        }
                        case CurvedType::CURVE4:
                        {
                            painter.drawImage(displayX, displayY, *curve4Image);
                            break;
                        }
                        case CurvedType::CURVE5:
                        {
                            painter.drawImage(displayX, displayY, *curve5Image);
                            break;
                        }
                        case CurvedType::CURVE6:
                        {
                            painter.drawImage(displayX, displayY, *curve6Image);
                            break;
                        }
                        case CurvedType::CURVE7:
                        {
                            painter.drawImage(displayX, displayY, *curve7Image);
                            break;
                        }
                        case CurvedType::CURVE8:
                        {
                            painter.drawImage(displayX, displayY, *curve8Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getLinkedType())
                    {
                        case LinkedType::LINKLEFT:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkLeftUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkLeftSetImage);
                            }

                            break;
                        }
                        case LinkedType::LINKRIGHT:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkRightUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkRightSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKDOWN:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkDownUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkDownSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKUP:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkUpUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkUpSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKLEFTUP:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkLeftUpUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkLeftUpSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKRIGHTUP:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkRightUpUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkRightUpSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKRIGHTDOWN:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkRightDownUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkRightDownSetImage);
                            }
                            break;
                        }
                        case LinkedType::LINKLEFTDOWN:
                        {
                            if (!currentElement->getLinked())
                            {
                                painter.drawImage(displayX, displayY, *linkLeftDownUnsetImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *linkLeftDownSetImage);
                            }
                            break;
                        }
                    }
                    if (canvasChosen == Mode::CONNECTLINKEDTRACK)
                    {
                        if (currentElement == drawnLayout->getLinkedTrack1() || currentElement == drawnLayout->getLinkedTrack2())
                        {
                            painter.drawImage(displayX,displayY,*selectBlue);
                        }
                        else if (!currentElement->getLinked())
                        {
                            painter.drawImage(displayX,displayY,*selectRed);
                        }
                        else if (currentElement->getLinked())
                        {
                            painter.drawImage(displayX,displayY, * selectGreen);
                            painter.drawLine(displayX+8, displayY+8,
                            currentElement->getOtherLinkTrack()->getLocationX()+8- minDisplayX,
                            0-(currentElement->getOtherLinkTrack()->getLocationY()-8 - maxDisplayY));
                        }

                    }
                }
            }
        }

        for (std::shared_ptr<ExitTrack> currentElement : drawnLayout->getExitTrackList())
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getExitType())
                    {
                        case ExitType::EXITLEFT:
                        {
                            painter.drawImage(displayX, displayY, *exitLeftImage);
                            break;
                        }
                        case ExitType::EXITRIGHT:
                        {
                            painter.drawImage(displayX, displayY, *exitRightImage);
                            break;
                        }
                        case ExitType::EXITDOWN:
                        {
                            painter.drawImage(displayX, displayY, *exitDownImage);
                            break;
                        }
                        case ExitType::EXITUP:
                        {
                            painter.drawImage(displayX, displayY, *exitUpImage);
                            break;
                        }
                        case ExitType::EXITLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *exitLeftUpImage);
                            break;
                        }
                        case ExitType::EXITRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *exitRightUpImage);
                            break;
                        }
                        case ExitType::EXITLEFTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *exitLeftDownImage);
                            break;
                        }
                        case ExitType::EXITRIGHTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *exitRightDownImage);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getBufferType())
                    {
                        case BufferType::BUFFERLEFT:
                        {
                            painter.drawImage(displayX, displayY, *bufferLeftImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERRIGHT:
                        {
                            painter.drawImage(displayX, displayY, *bufferRightImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERDOWN:
                        {
                            painter.drawImage(displayX, displayY, *bufferDownImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERUP:
                        {
                            painter.drawImage(displayX, displayY, *bufferUpImage);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case BufferType::BUFFERLEFTUP:
                        {
                            painter.drawImage(displayX, displayY, *bufferLeftUpImage);
                            break;
                        }
                        case BufferType::BUFFERRIGHTUP:
                        {
                            painter.drawImage(displayX, displayY, *bufferRightUpImage);
                            break;
                        }
                        case BufferType::BUFFERLEFTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *bufferLeftDownImage);
                            break;
                        }
                        case BufferType::BUFFERRIGHTDOWN:
                        {
                            painter.drawImage(displayX, displayY, *bufferRightDownImage);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getSignalType())
                    {
                        case SignalType::SIGNALLEFT:
                        {
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
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALRIGHT:
                        {
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
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALDOWN:
                        {
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
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALUP:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntUpImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalUpImage);
                            }
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SignalType::SIGNALLEFTUP:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntLeftUpImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalLeftUpImage);
                            }
                            break;
                        }
                        case SignalType::SIGNALRIGHTUP:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntRightUpImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalRightUpImage);
                            }
                            break;
                        }
                        case SignalType::SIGNALLEFTDOWN:
                        {
                            if (currentElement->getAspect() == 1)
                            {
                                painter.drawImage(displayX, displayY, *shuntLeftDownImage);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *signalLeftDownImage);
                            }
                            break;
                        }
                        case SignalType::SIGNALRIGHTDOWN:
                        {
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
        }

        for (std::shared_ptr<BridgeUnderpassTrack> currentElement : drawnLayout->getBridgeUnderpassTrackList())
        {
            int currentX = currentElement->getLocationX();
            int currentY = currentElement->getLocationY();
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getBridgeUnderpassType())
                    {
                        case BridgeUnderpassType::BRIDGE1:
                        {
                            if (currentElement->getNamed())
                            {
                                painter.drawImage(displayX, displayY, *bridgeSet1Image);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *bridgeUnset1Image);
                            }

                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BridgeUnderpassType::BRIDGE2:
                        {
                            if (currentElement->getNamed())
                            {
                                painter.drawImage(displayX, displayY, *bridgeSet2Image);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *bridgeUnset2Image);
                            }
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case BridgeUnderpassType::UNDERPASS1:
                        {
                            if (currentElement->getNamed())
                            {
                                painter.drawImage(displayX, displayY, *underpassSet1Image);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *underpassUnset1Image);
                            }
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case BridgeUnderpassType::UNDERPASS2:
                        {
                            if (currentElement->getNamed())
                            {
                                painter.drawImage(displayX, displayY, *underpassSet2Image);
                            }
                            else
                            {
                                painter.drawImage(displayX, displayY, *underpassUnset2Image);
                            }
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getSwitchType())
                    {
                        case SwitchType::SWITCHTIGHT1:
                        {
                            painter.drawImage(displayX, displayY, *switchTight1Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT2:
                        {
                            painter.drawImage(displayX, displayY, *switchTight2Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT3:
                        {
                            painter.drawImage(displayX, displayY, *switchTight3Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT4:
                        {
                            painter.drawImage(displayX, displayY, *switchTight4Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT5:
                        {
                            painter.drawImage(displayX, displayY, *switchTight5Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT6:
                        {
                            painter.drawImage(displayX, displayY, *switchTight6Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT7:
                        {
                            painter.drawImage(displayX, displayY, *switchTight7Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHTIGHT8:
                        {
                            painter.drawImage(displayX, displayY, *switchTight8Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHSPLIT1:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit1Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT2:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit2Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT3:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit3Image);
                            break;
                        }
                        case SwitchType::SWITCH1:
                        {
                            painter.drawImage(displayX, displayY, *switch1Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH2:
                        {
                            painter.drawImage(displayX, displayY, *switch2Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformDownSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformDownUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH3:
                        {
                            painter.drawImage(displayX, displayY, *switch3Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH4:
                        {
                            painter.drawImage(displayX, displayY, *switch4Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformUpSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformUpUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH5:
                        {
                            painter.drawImage(displayX, displayY, *switch5Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH6:
                        {
                            painter.drawImage(displayX, displayY, *switch6Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH7:
                        {
                            painter.drawImage(displayX, displayY, *switch7Image);
                            if (currentElement->getPlatform2())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformRightSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformRightUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCH8:
                        {
                            painter.drawImage(displayX, displayY, *switch8Image);
                            if (currentElement->getPlatform1())
                            {
                                if (currentElement->getNamed())
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftSetImage);
                                }
                                else
                                {
                                    painter.drawImage(displayX, displayY, *platformLeftUnsetImage);
                                }
                            }
                            break;
                        }
                        case SwitchType::SWITCHSPLIT4:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit4Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT5:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit5Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT6:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit6Image);
                            break;
                        }
                        case SwitchType::SWITCH9:
                        {
                            painter.drawImage(displayX, displayY, *switch9Image);
                            break;
                        }
                        case SwitchType::SWITCH10:
                        {
                            painter.drawImage(displayX, displayY, *switch10Image);
                            break;
                        }
                        case SwitchType::SWITCH11:
                        {
                            painter.drawImage(displayX, displayY, *switch11Image);
                            break;
                        }
                        case SwitchType::SWITCH12:
                        {
                            painter.drawImage(displayX, displayY, *switch12Image);
                            break;
                        }
                        case SwitchType::SWITCH13:
                        {
                            painter.drawImage(displayX, displayY, *switch13Image);
                            break;
                        }
                        case SwitchType::SWITCH14:
                        {
                            painter.drawImage(displayX, displayY, *switch14Image);
                            break;
                        }
                        case SwitchType::SWITCH15:
                        {
                            painter.drawImage(displayX, displayY, *switch15Image);
                            break;
                        }
                        case SwitchType::SWITCH16:
                        {
                            painter.drawImage(displayX, displayY, *switch16Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT7:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit7Image);
                            break;
                        }
                        case SwitchType::SWITCHSPLIT8:
                        {
                            painter.drawImage(displayX, displayY, *switchSplit8Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getCrossoverType())
                    {
                       case CrossoverType::CROSSOVER1:
                        {
                           painter.drawImage(displayX, displayY, *crossover1Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER2:
                        {
                           painter.drawImage(displayX, displayY, *crossover2Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER3:
                        {
                           painter.drawImage(displayX, displayY, *crossover3Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER4:
                        {
                           painter.drawImage(displayX, displayY, *crossover4Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER5:
                        {
                           painter.drawImage(displayX, displayY, *crossover5Image);
                           break;
                        }
                       case CrossoverType::CROSSOVER6:
                        {
                           painter.drawImage(displayX, displayY, *crossover6Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getFlyoverType())
                    {
                        case FlyoverType::FLYOVER1:
                        {
                            painter.drawImage(displayX, displayY, *flyover1Image);
                            break;
                        }
                        case FlyoverType::FLYOVER2:
                        {
                            painter.drawImage(displayX, displayY, *flyover2Image);
                            break;
                        }
                        case FlyoverType::FLYOVER3:
                        {
                            painter.drawImage(displayX, displayY, *flyover3Image);
                            break;
                        }
                        case FlyoverType::FLYOVER4:
                        {
                            painter.drawImage(displayX, displayY, *flyover4Image);
                            break;
                        }
                        case FlyoverType::FLYOVER5:
                        {
                            painter.drawImage(displayX, displayY, *flyover5Image);
                            break;
                        }
                        case FlyoverType::FLYOVER6:
                        {
                            painter.drawImage(displayX, displayY, *flyover6Image);
                            break;
                        }
                        case FlyoverType::FLYOVER7:
                        {
                            painter.drawImage(displayX, displayY, *flyover7Image);
                            break;
                        }
                        case FlyoverType::FLYOVER8:
                        {
                            painter.drawImage(displayX, displayY, *flyover8Image);
                            break;
                        }
                        case FlyoverType::FLYOVER9:
                        {
                            painter.drawImage(displayX, displayY, *flyover9Image);
                            break;
                        }
                        case FlyoverType::FLYOVER10:
                        {
                            painter.drawImage(displayX, displayY, *flyover10Image);
                            break;
                        }
                        case FlyoverType::FLYOVER11:
                        {
                            painter.drawImage(displayX, displayY, *flyover11Image);
                            break;
                        }
                        case FlyoverType::FLYOVER12:
                        {
                            painter.drawImage(displayX, displayY, *flyover12Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    switch (currentElement->getParapetType())
                    {
                        case ParapetType::PARAPET1:
                        {
                            painter.drawImage(displayX, displayY, *parapet1Image);
                            break;
                        }
                        case ParapetType::PARAPET2:
                        {
                            painter.drawImage(displayX, displayY, *parapet2Image);
                            break;
                        }
                        case ParapetType::PARAPET3:
                        {
                            painter.drawImage(displayX, displayY, *parapet3Image);
                            break;
                        }
                        case ParapetType::PARAPET4:
                        {
                            painter.drawImage(displayX, displayY, *parapet4Image);
                            break;
                        }
                        case ParapetType::PARAPET5:
                        {
                            painter.drawImage(displayX, displayY, *parapet5Image);
                            break;
                        }
                        case ParapetType::PARAPET6:
                        {
                            painter.drawImage(displayX, displayY, *parapet6Image);
                            break;
                        }
                        case ParapetType::PARAPET7:
                        {
                            painter.drawImage(displayX, displayY, *parapet7Image);
                            break;
                        }
                        case ParapetType::PARAPET8:
                        {
                            painter.drawImage(displayX, displayY, *parapet8Image);
                            break;
                        }
                        case ParapetType::PARAPET9:
                        {
                            painter.drawImage(displayX, displayY, *parapet9Image);
                            break;
                        }
                        case ParapetType::PARAPET10:
                        {
                            painter.drawImage(displayX, displayY, *parapet10Image);
                            break;
                        }
                        case ParapetType::PARAPET11:
                        {
                            painter.drawImage(displayX, displayY, *parapet11Image);
                            break;
                        }
                        case ParapetType::PARAPET12:
                        {
                            painter.drawImage(displayX, displayY, *parapet12Image);
                            break;
                        }
                        case ParapetType::PARAPET13:
                        {
                            painter.drawImage(displayX, displayY, *parapet13Image);
                            break;
                        }
                        case ParapetType::PARAPET14:
                        {
                            painter.drawImage(displayX, displayY, *parapet14Image);
                            break;
                        }
                        case ParapetType::PARAPET15:
                        {
                            painter.drawImage(displayX, displayY, *parapet15Image);
                            break;
                        }
                        case ParapetType::PARAPET16:
                        {
                            painter.drawImage(displayX, displayY, *parapet16Image);
                            break;
                        }
                        case ParapetType::PARAPET17:
                        {
                            painter.drawImage(displayX, displayY, *parapet17Image);
                            break;
                        }
                        case ParapetType::PARAPET18:
                        {
                            painter.drawImage(displayX, displayY, *parapet18Image);
                            break;
                        }
                        case ParapetType::PARAPET19:
                        {
                            painter.drawImage(displayX, displayY, *parapet19Image);
                            break;
                        }
                        case ParapetType::PARAPET20:
                        {
                            painter.drawImage(displayX, displayY, *parapet20Image);
                            break;
                        }
                        case ParapetType::PARAPET21:
                        {
                            painter.drawImage(displayX, displayY, *parapet21Image);
                            break;
                        }
                        case ParapetType::PARAPET22:
                        {
                            painter.drawImage(displayX, displayY, *parapet22Image);
                            break;
                        }
                        case ParapetType::PARAPET23:
                        {
                            painter.drawImage(displayX, displayY, *parapet23Image);
                            break;
                        }
                        case ParapetType::PARAPET24:
                        {
                            painter.drawImage(displayX, displayY, *parapet24Image);
                            break;
                        }
                        case ParapetType::PARAPET25:
                        {
                            painter.drawImage(displayX, displayY, *parapet25Image);
                            break;
                        }
                        case ParapetType::PARAPET26:
                        {
                            painter.drawImage(displayX, displayY, *parapet26Image);
                            break;
                        }
                        case ParapetType::PARAPET27:
                        {
                            painter.drawImage(displayX, displayY, *parapet27Image);
                            break;
                        }
                        case ParapetType::PARAPET28:
                        {
                            painter.drawImage(displayX, displayY, *parapet28Image);
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
            int minCoordinateX = (offsetX * canvasSizeX);
            int maxCoordinateX = ((offsetX+1) * canvasSizeX);
            int minCoordinateY = ((offsetY-1) * canvasSizeY);
            int maxCoordinateY = (offsetY*canvasSizeY);;
            int minDisplayX = (offsetX * canvasSizeX);
            int maxDisplayY = (offsetY*canvasSizeY);
            if (currentX >= minCoordinateX && currentX <= maxCoordinateX)
            {
                if (currentY >= minCoordinateY && currentY <= maxCoordinateY)
                {
                    int displayX = currentX- minDisplayX;
                    int displayY = 0-(currentY - maxDisplayY);
                    painter.setFont(currentElement->getFont());
                    painter.drawText(displayX, displayY, currentElement->getReadableText());
                }
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
    if (canvasChosen == Mode::MOVETEXT)
    {
        canvasSizeX = width();
        canvasSizeY = height();
        int exactX = event->pos().x();
        int exactY = event->pos().y();
        bool ok;
        int textX = exactX + (offsetX*canvasSizeX);
        int textY;

        if (offsetY==0)
        {
            textY = 0 - (exactY+ (offsetY*canvasSizeY));
        } else {
            textY = 0 - (exactY- (offsetY*canvasSizeY));
        }
        if ( event->buttons() & Qt::LeftButton )
        {
            int fontSize = moveText->getFontSize();
            moveText->setLocationX(textX);
            moveText->setLocationY(textY);
            moveText->setEditableX(textX+fontSize);
            moveText->setEditableY(textY+fontSize);
        }
    }

    update();
    if (canvasShowTrackID)
    {
        int exactX = event->pos().x();
        int exactY = event->pos().y();
        int extraX = exactX % 16;
        int extraY = exactY % 16;
        int roundedX = exactX - extraX;
        int roundedY = exactY - extraY;
        int finalX = ((roundedX + (offsetX*canvasSizeX)));
        int finalY;
        if (offsetY==0)
        {
            finalY = 0 - ((roundedY+ (offsetY*canvasSizeY)));
        }
        else
        {
            finalY = 0 - (roundedY- (offsetY*canvasSizeY));
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
                ID = ID.append(QString::number(finalX/16)).append(",").append(QString::number(finalY/16));
                if (canvasShowMoreTrackInfo) {
                   QString text2 = tr("\n").append("Track length = ").append(QString::number(track->getTrackMainLength())).append(" m");
                   QString text3 = tr("\n").append("Track speed = ").append(QString::number(track->getTrackMainSpeed())).append(" km/h");
                   finalText = ID.append(text2).append(text3);
                }
                finalText = ID;
            }
            else
            {
                ID = "Element ID = ";
                ID = ID.append(QString::number(finalX/16)).append(",").append(QString::number(finalY/16));
                finalText = ID;
            }
            setToolTip(finalText);
        }
    }
}






