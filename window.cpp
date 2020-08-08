#include "window.h"

//Constructor
Window::Window()
{
    //Set default chosen Element to nothing.
    viewColour = Colour::LIGHT;
    modeChosen = Mode::NONE;
    drawingSurface = new Canvas;
    drawingSurface->setMode(modeChosen);
    setMinimumSize(960,544);
    resize(1024,768);
    windowOffsetX = 0;
    windowOffsetY = 0;
    drawingSurface->setOffsetX(windowOffsetX);
    drawingSurface->setOffsetY(windowOffsetY);
    aspect = 4;
    drawingSurface->setAspect(aspect);
    showTrackID = false;
    showMoreTrackInfo = false;
    drawingSurface->setCanvasShowTrackID(showTrackID);
    drawingSurface->setCanvasShowMoreTrackInfo(showMoreTrackInfo);
    createOverallMenu();
    createRightMenu();
    createMenuBar();

    status = new QStatusBar();
    status->setSizeGripEnabled(false);
    QLabel* l = new QLabel (tr("hi"));
    status->addWidget(l);

    QWidget *left = new QWidget();
    left->setFixedHeight(10);


    BorderLayout* layout = new BorderLayout;
    layout->addWidget(drawingSurface, BorderLayout::Center);
    layout->addWidget(menuBar, BorderLayout::North);
    layout->addWidget(buildModifyMenu1, BorderLayout::North);
    layout->addWidget(allMenus, BorderLayout::North);
    layout->addWidget(rightMenu, BorderLayout::East);
    layout->addWidget(left, BorderLayout::West);
    layout->addWidget(status, BorderLayout::South);

    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerRun()));
    timer->start(100);
}


// Private slots

void Window::timerRun()
{
    drawingSurface->update();
    if (drawingSurface->getMap().getLinkedTrackList().size()>0)
    {
        connectLinkedTrackButton->setEnabled(true);
    }
    if (drawingSurface->getMap().getTotalTrack()>0)
    {
        checkAllTrackButton->setEnabled(true);
    }
}

void Window::openRailway()
{

}

void Window::openBuildModifyMenu()
{


}

void Window::openElementMenu()
{
    if (allMenus->currentIndex() != 1)
    {
        allMenus->setCurrentIndex(1);
    }
    else
    {
        allMenus->setCurrentIndex(0);
    }

}

void Window::connectLinkedTrack()
{
    if (modeChosen != Mode::CONNECTLINKEDTRACK)
    {
        int linkTrackNum =  drawingSurface->getMap().getLinkedTrackList().size();
        std::cout<< linkTrackNum << std::flush;
        if ((linkTrackNum % 2) == 0)
        {
            modeChosen = Mode::CONNECTLINKEDTRACK;
        }
        else
        {
            QMessageBox oddNumOfLinkTrack;
            oddNumOfLinkTrack.setIcon(QMessageBox::Critical);
            oddNumOfLinkTrack.setText("Cannot link track. Odd number of LinkedTrack");
            oddNumOfLinkTrack.exec();
        }

    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::checkAllTrack()
{
    drawingSurface->getMap().checkAllTracks();
}

void Window::addEditRemoveText()
{
    if (modeChosen != Mode::ADDCHANGETEXT)
    {
        modeChosen = Mode::ADDCHANGETEXT;
        drawingSurface->setMode(modeChosen);
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::moveText()
{
    if (modeChosen != Mode::MOVETEXT)
    {
        modeChosen = Mode::MOVETEXT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::setChangeNamedLocation()
{
    if (modeChosen != Mode::SETCHANGENAMEDLOCATION)
    {
        modeChosen = Mode::SETCHANGENAMEDLOCATION;

    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::openFontBox()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont( "Calibri", 12 ),this,tr("Pick a font" ));
    drawingSurface->setCurrentFont(font);
}

void Window::openTrackLengthSpeedPanel()
{
    if (allMenus->currentIndex() != 2)
    {
        allMenus->setCurrentIndex(2);
    }
    else
    {
        allMenus->setCurrentIndex(0);
        drawingSurface->getMap().resetSetTrackSpeedLengthMechanics();

    }
    if (modeChosen != Mode::SETTRACKLENGTHSPEED)
    {
        modeChosen = Mode::SETTRACKLENGTHSPEED;

    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::convertMilesYardMetres()
{
    if (!milesEntry->text().isEmpty())
    {
        bool ok = false;
        double tempD = milesEntry->text().toDouble(&ok);
        if (ok)
        {
             miles = tempD;
        }
    }
    else
    {
        miles = 0;
    }
    if (!yardsEntry->text().isEmpty())
    {
        bool ok = false;
        double tempD = yardsEntry->text().toDouble(&ok);
        if (ok)
        {
             yards = tempD;
        }
    }
    else
    {
        yards = 0;
    }
    int metres = round((miles* MILE_FACTOR) + (yards* YARD_FACTOR));
    metres = std::ceil(metres * 100.0) / 100.0;
    actualMetres->setText(QString::number(metres));

}

void Window::swapSpeedLabel()
{
    QString temp = speedLabel1->text();
    speedLabel1->setText(speedLabel2->text());
    speedLabel2->setText(temp);
    if (mphToKmh)
    {
        mphToKmh = false;
    }
    else
    {
        mphToKmh = true;
    }
    convertMPHKMH();
}

void Window::convertMPHKMH()
{
    double result;
    double temp;
    if (!speedEntry1->text().isEmpty())
    {
        bool ok = false;
        double tempD = speedEntry1->text().toDouble(&ok);
        if (ok)
        {
             temp = tempD;
        }
        if (mphToKmh)
        {
            result = temp * MPH_TO_KMH;
        }
        else
        {
            result = temp / MPH_TO_KMH;
        }
        result = std::ceil(result * 100.0) / 100.0;
        speedResult->setText(QString::number(result));
    }

}

void Window::changeAspect()
{
    if (aspect == 4)
    {
        aspect = 3;
        drawingSurface->setAspect(aspect);
        aspectButton->setIcon(*aspect3Icon);
    }
    else if (aspect == 3)
    {
        aspect = 2;
        drawingSurface->setAspect(aspect);
        aspectButton->setIcon(*aspect2Icon);
    }
    else if (aspect == 2)
    {
        aspect = 1;
        drawingSurface->setAspect(aspect);
        aspectButton->setIcon(*aspectShuntIcon);
        signalLeftButton->setIcon(*shuntLeftIcon);
        signalRightButton->setIcon(*shuntRightIcon);
        signalDownButton->setIcon(*shuntDownIcon);
        signalUpButton->setIcon(*shuntUpIcon);
        signalLeftUpButton->setIcon(*shuntLeftUpIcon);
        signalRightUpButton->setIcon(*shuntRightUpIcon);
        signalLeftDownButton->setIcon(*shuntLeftDownIcon);
        signalRightDownButton->setIcon(*shuntRightDownIcon);
    }
    else if (aspect == 1)
    {
        aspect = 4;
        drawingSurface->setAspect(aspect);
        aspectButton->setIcon(*aspect4Icon);
        signalLeftButton->setIcon(*signalLeftIcon);
        signalRightButton->setIcon(*signalRightIcon);
        signalDownButton->setIcon(*signalDownIcon);
        signalUpButton->setIcon(*signalUpIcon);
        signalLeftUpButton->setIcon(*signalLeftUpIcon);
        signalRightUpButton->setIcon(*signalRightUpIcon);
        signalLeftDownButton->setIcon(*signalLeftDownIcon);
        signalRightDownButton->setIcon(*signalRightDownIcon);
    }

}

void Window::toggleTrackID()
{
    if (!showTrackID)
    {
        showTrackID = true;
        showTrackIDAct->setText("Hide trackID");
        drawingSurface->setCanvasShowTrackID(showTrackID);
    }
    else
    {
        showTrackID = false;
        showTrackIDAct->setText("Show trackID");
    }
    drawingSurface->setCanvasShowTrackID(showTrackID);
}

void Window::toggleMoreTrackInfo()
{
    if (!showMoreTrackInfo)
    {
        showMoreTrackInfo = true;
        showMoreTrackInfoAct->setText("Hide more track information");
    }
    else
    {
        showMoreTrackInfo = false;
        showMoreTrackInfoAct->setText("Show more track information");
    }
    drawingSurface->setCanvasShowMoreTrackInfo(showMoreTrackInfo);
}

void Window::canvasToWhite()
{
    drawingSurface->setCanvasColour(Colour::LIGHT);
    drawingSurface->canvasChangeColour();
    drawingSurface->trackChangeColour();
}

void Window::canvasToDarkBlue()
{
    drawingSurface->setCanvasColour(Colour::DARKBLUE);
    drawingSurface->canvasChangeColour();
    drawingSurface->trackChangeColour();
}

void Window::canvasToBlack()
{
    drawingSurface->setCanvasColour(Colour::BLACK);
    drawingSurface->canvasChangeColour();
    drawingSurface->trackChangeColour();
}

void Window::moveRight()
{
    drawingSurface->setOffsetX(++windowOffsetX);
    drawingSurface->update();
}

void Window::moveLeft()
{
    drawingSurface->setOffsetX(--windowOffsetX);
    drawingSurface->update();
}

void Window::moveUp()
{
    drawingSurface->setOffsetY(++windowOffsetY);
    drawingSurface->update();
}

void Window::moveDown()
{
    drawingSurface->setOffsetY(--windowOffsetY);
    drawingSurface->update();

}

void Window::chooseStraightH()
{
    if (modeChosen != Mode::STRAIGHTH)
    {
        modeChosen = Mode::STRAIGHTH;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseStraightV()
{
    if (modeChosen != Mode::STRAIGHTV)
    {
        modeChosen = Mode::STRAIGHTV;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectLeft()
{
    if (modeChosen != Mode::DIRECTLEFT)
    {
        modeChosen = Mode::DIRECTLEFT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectRight()
{
    if (modeChosen != Mode::DIRECTRIGHT)
    {
        modeChosen = Mode::DIRECTRIGHT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectUp()
{
    if (modeChosen != Mode::DIRECTUP)
    {
        modeChosen = Mode::DIRECTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectDown()
{
    if (modeChosen != Mode::DIRECTDOWN)
    {
        modeChosen = Mode::DIRECTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseStraightLeftUp()
{
    if (modeChosen != Mode::STRAIGHTLEFTUP)
    {
        modeChosen = Mode::STRAIGHTLEFTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseStraightRightUp()
{
    if (modeChosen != Mode::STRIAGHTRIGHTUP)
    {
        modeChosen = Mode::STRIAGHTRIGHTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectLeftUp()
{
    if (modeChosen != Mode::DIRECTLEFTUP)
    {
        modeChosen = Mode::DIRECTLEFTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectRightUp()
{
    if (modeChosen != Mode::DIRECTRIGHTUP)
    {
        modeChosen = Mode::DIRECTRIGHTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectLeftDown()
{
    if (modeChosen != Mode::DIRECTLEFTDOWN)
    {
        modeChosen = Mode::DIRECTLEFTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseDirectRightDown()
{
    if (modeChosen != Mode::DIRECTRIGHTDOWN)
    {
        modeChosen = Mode::DIRECTRIGHTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseTightCurve1()
{
    if (modeChosen != Mode::TIGHTCURVE1)
    {
        modeChosen = Mode::TIGHTCURVE1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseTightCurve2()
{
    if (modeChosen != Mode::TIGHTCURVE2)
    {
        modeChosen = Mode::TIGHTCURVE2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseTightCurve3()
{
    if (modeChosen != Mode::TIGHTCURVE3)
    {
        modeChosen = Mode::TIGHTCURVE3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseTightCurve4()
{
    if (modeChosen != Mode::TIGHTCURVE4)
    {
        modeChosen = Mode::TIGHTCURVE4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve1()
{
    if (modeChosen != Mode::CURVE1)
    {
        modeChosen = Mode::CURVE1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve2()
{
    if (modeChosen != Mode::CURVE2)
    {
        modeChosen = Mode::CURVE2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve3()
{
    if (modeChosen != Mode::CURVE3)
    {
        modeChosen = Mode::CURVE3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve4()
{
    if (modeChosen != Mode::CURVE4)
    {
        modeChosen = Mode::CURVE4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkLeft()
{
    if (modeChosen != Mode::LINKLEFT)
    {
        modeChosen = Mode::LINKLEFT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkRight()
{
    if (modeChosen != Mode::LINKRIGHT)
    {
        modeChosen = Mode::LINKRIGHT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkDown()
{
    if (modeChosen != Mode::LINKDOWN)
    {
        modeChosen = Mode::LINKDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkUp()
{
    if (modeChosen != Mode::LINKUP)
    {
        modeChosen = Mode::LINKUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkLeftUp()
{
    if (modeChosen != Mode::LINKLEFTUP)
    {
        modeChosen = Mode::LINKLEFTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkRightUp()
{
    if (modeChosen != Mode::LINKRIGHTUP)
    {
        modeChosen = Mode::LINKRIGHTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkLeftDown()
{
    if (modeChosen != Mode::LINKLEFTDOWN)
    {
        modeChosen = Mode::LINKLEFTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLinkRightDown()
{
    if (modeChosen != Mode::LINKRIGHTDOWN)
    {
        modeChosen = Mode::LINKRIGHTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitLeft()
{
    if (modeChosen != Mode::EXITLEFT)
    {
        modeChosen = Mode::EXITLEFT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitRight()
{
    if (modeChosen != Mode::EXITRIGHT)
    {
        modeChosen = Mode::EXITRIGHT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitDown()
{
    if (modeChosen != Mode::EXITDOWN)
    {
        modeChosen = Mode::EXITDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitUp()
{
    if (modeChosen != Mode::EXITUP)
    {
        modeChosen = Mode::EXITUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitLeftUp()
{
    if (modeChosen != Mode::EXITLEFTUP)
    {
        modeChosen = Mode::EXITLEFTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitRightUp()
{
    if (modeChosen != Mode::EXITRIGHTUP)
    {
        modeChosen = Mode::EXITRIGHTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitLeftDown()
{
    if (modeChosen != Mode::EXITLEFTDOWN)
    {
        modeChosen = Mode::EXITLEFTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseExitRightDown()
{
    if (modeChosen != Mode::EXITRIGHTDOWN)
    {
        modeChosen = Mode::EXITRIGHTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve5()
{
    if (modeChosen != Mode::CURVE5)
    {
        modeChosen = Mode::CURVE5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve6()
{
    if (modeChosen != Mode::CURVE6)
    {
        modeChosen = Mode::CURVE6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve7()
{
    if (modeChosen != Mode::CURVE7)
    {
        modeChosen = Mode::CURVE7;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCurve8()
{
    if (modeChosen != Mode::CURVE8)
    {
        modeChosen = Mode::CURVE8;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferLeft()
{
    if (modeChosen != Mode::BUFFERLEFT)
    {
        modeChosen = Mode::BUFFERLEFT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferRight()
{
    if (modeChosen != Mode::BUFFERRIGHT)
    {
        modeChosen = Mode::BUFFERRIGHT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferDown()
{
    if (modeChosen != Mode::BUFFERDOWN)
    {
        modeChosen = Mode::BUFFERDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferUp()
{
    if (modeChosen != Mode::BUFFERUP)
    {
        modeChosen = Mode::BUFFERUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferLeftUp()
{
    if (modeChosen != Mode::BUFFERLEFTUP)
    {
        modeChosen = Mode::BUFFERLEFTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferRightUp()
{
    if (modeChosen != Mode::BUFFERRIGHTUP)
    {
        modeChosen = Mode::BUFFERRIGHTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferLeftDown()
{
    if (modeChosen != Mode::BUFFERLEFTDOWN)
    {
        modeChosen = Mode::BUFFERLEFTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBufferRightDown()
{
    if (modeChosen != Mode::BUFFERRIGHTDOWN)
    {
        modeChosen = Mode::BUFFERRIGHTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalLeft()
{
    if (modeChosen != Mode::SIGNALLEFT)
    {
        modeChosen = Mode::SIGNALLEFT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalRight()
{
    if (modeChosen != Mode::SIGNALRIGHT)
    {
        modeChosen = Mode::SIGNALRIGHT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalDown()
{
    if (modeChosen != Mode::SIGNALDOWN)
    {
        modeChosen = Mode::SIGNALDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalUp()
{
    if (modeChosen != Mode::SIGNALUP)
    {
        modeChosen = Mode::SIGNALUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalLeftUp()
{
    if (modeChosen != Mode::SIGNALLEFTUP)
    {
        modeChosen = Mode::SIGNALLEFTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalRightUp()
{
    if (modeChosen != Mode::SIGNALRIGHTUP)
    {
        modeChosen = Mode::SIGNALRIGHTUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalLeftDown()
{
    if (modeChosen != Mode::SIGNALLEFTDOWN)
    {
        modeChosen = Mode::SIGNALLEFTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSignalRightDown()
{
    if (modeChosen != Mode::SIGNALRIGHTDOWN)
    {
        modeChosen = Mode::SIGNALRIGHTDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBridge1()
{
    if (modeChosen != Mode::BRIDGE1)
    {
        modeChosen = Mode::BRIDGE1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseBridge2()
{
    if (modeChosen != Mode::BRIDGE2)
    {
        modeChosen = Mode::BRIDGE2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseUnderpass1()
{
    if (modeChosen != Mode::UNDERPASS1)
    {
        modeChosen = Mode::UNDERPASS1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseUnderpass2()
{
    if (modeChosen != Mode::UNDERPASS2)
    {
        modeChosen = Mode::UNDERPASS2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight1()
{
    if (modeChosen != Mode::SWITCHTIGHT1)
    {
        modeChosen = Mode::SWITCHTIGHT1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight2()
{
    if (modeChosen != Mode::SWITCHTIGHT2)
    {
        modeChosen = Mode::SWITCHTIGHT2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight3()
{
    if (modeChosen != Mode::SWITCHTIGHT3)
    {
        modeChosen = Mode::SWITCHTIGHT3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight4()
{
    if (modeChosen != Mode::SWITCHTIGHT4)
    {
        modeChosen = Mode::SWITCHTIGHT4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight5()
{
    if (modeChosen != Mode::SWITCHTIGHT5)
    {
        modeChosen = Mode::SWITCHTIGHT5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight6()
{
    if (modeChosen != Mode::SWITCHTIGHT6)
    {
        modeChosen = Mode::SWITCHTIGHT6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight7()
{
    if (modeChosen != Mode::SWITCHTIGHT7)
    {
        modeChosen = Mode::SWITCHTIGHT7;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchTight8()
{
    if (modeChosen != Mode::SWITCHTIGHT8)
    {
        modeChosen = Mode::SWITCHTIGHT8;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit1()
{
    if (modeChosen != Mode::SWITCHSPLIT1)
    {
        modeChosen = Mode::SWITCHSPLIT1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit2()
{
    if (modeChosen != Mode::SWITCHSPLIT2)
    {
        modeChosen = Mode::SWITCHSPLIT2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit3()
{
    if (modeChosen != Mode::SWITCHSPLIT3)
    {
        modeChosen = Mode::SWITCHSPLIT3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch1()
{
    if (modeChosen != Mode::SWITCH1)
    {
        modeChosen = Mode::SWITCH1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch2()
{
    if (modeChosen != Mode::SWITCH2)
    {
        modeChosen = Mode::SWITCH2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch3()
{
    if (modeChosen != Mode::SWITCH3)
    {
        modeChosen = Mode::SWITCH3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch4()
{
    if (modeChosen != Mode::SWITCH4)
    {
        modeChosen = Mode::SWITCH4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch5()
{
    if (modeChosen != Mode::SWITCH5)
    {
        modeChosen = Mode::SWITCH5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch6()
{
    if (modeChosen != Mode::SWITCH6)
    {
        modeChosen = Mode::SWITCH6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch7()
{
    if (modeChosen != Mode::SWITCH7)
    {
        modeChosen = Mode::SWITCH7;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch8()
{
    if (modeChosen != Mode::SWITCH8)
    {
        modeChosen = Mode::SWITCH8;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit4()
{
    if (modeChosen != Mode::SWITCHSPLIT4)
    {
        modeChosen = Mode::SWITCHSPLIT4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit5()
{
    if (modeChosen != Mode::SWITCHSPLIT5)
    {
        modeChosen = Mode::SWITCHSPLIT5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit6()
{
    if (modeChosen != Mode::SWITCHSPLIT6)
    {
        modeChosen = Mode::SWITCHSPLIT6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch9()
{
    if (modeChosen != Mode::SWITCH9)
    {
        modeChosen = Mode::SWITCH9;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch10()
{
    if (modeChosen != Mode::SWITCH10)
    {
        modeChosen = Mode::SWITCH10;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch11()
{
    if (modeChosen != Mode::SWITCH11)
    {
        modeChosen = Mode::SWITCH11;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch12()
{
    if (modeChosen != Mode::SWITCH12)
    {
        modeChosen = Mode::SWITCH12;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch13()
{
    if (modeChosen != Mode::SWITCH13)
    {
        modeChosen = Mode::SWITCH13;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch14()
{
    if (modeChosen != Mode::SWITCH14)
    {
        modeChosen = Mode::SWITCH14;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch15()
{
    if (modeChosen != Mode::SWITCH15)
    {
        modeChosen = Mode::SWITCH15;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitch16()
{
    if (modeChosen != Mode::SWITCH16)
    {
        modeChosen = Mode::SWITCH16;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit7()
{
    if (modeChosen != Mode::SWITCHSPLIT7)
    {
        modeChosen = Mode::SWITCHSPLIT7;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseSwitchSplit8()
{
    if (modeChosen != Mode::SWITCHSPLIT8)
    {
        modeChosen = Mode::SWITCHSPLIT8;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCrossover1()
{
    if (modeChosen != Mode::CROSSOVER1)
    {
        modeChosen = Mode::CROSSOVER1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCrossover2()
{
    if (modeChosen != Mode::CROSSOVER2)
    {
        modeChosen = Mode::CROSSOVER2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover1()
{
    if (modeChosen != Mode::FLYOVER1)
    {
        modeChosen = Mode::FLYOVER1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover2()
{
    if (modeChosen != Mode::FLYOVER2)
    {
        modeChosen = Mode::FLYOVER2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover3()
{
    if (modeChosen != Mode::FLYOVER3)
    {
        modeChosen = Mode::FLYOVER3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover4()
{
    if (modeChosen != Mode::FLYOVER4)
    {
        modeChosen = Mode::FLYOVER4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCrossover3()
{
    if (modeChosen != Mode::CROSSOVER3)
    {
        modeChosen = Mode::CROSSOVER3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCrossover4()
{
    if (modeChosen != Mode::CROSSOVER4)
    {
        modeChosen = Mode::CROSSOVER4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover5()
{
    if (modeChosen != Mode::FLYOVER5)
    {
        modeChosen = Mode::FLYOVER5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover6()
{
    if (modeChosen != Mode::FLYOVER6)
    {
        modeChosen = Mode::FLYOVER6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover7()
{
    if (modeChosen != Mode::FLYOVER7)
    {
        modeChosen = Mode::FLYOVER7;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover8()
{
    if (modeChosen != Mode::FLYOVER8)
    {
        modeChosen = Mode::FLYOVER8;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCrossover5()
{
    if (modeChosen != Mode::CROSSOVER5)
    {
        modeChosen = Mode::CROSSOVER5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseCrossover6()
{
    if (modeChosen != Mode::CROSSOVER6)
    {
        modeChosen = Mode::CROSSOVER6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover9()
{
    if (modeChosen != Mode::FLYOVER9)
    {
        modeChosen = Mode::FLYOVER9;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover10()
{
    if (modeChosen != Mode::FLYOVER10)
    {
        modeChosen = Mode::FLYOVER10;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover11()
{
    if (modeChosen != Mode::FLYOVER11)
    {
        modeChosen = Mode::FLYOVER11;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseFlyover12()
{
    if (modeChosen != Mode::FLYOVER12)
    {
        modeChosen = Mode::FLYOVER12;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseNamedLocation()
{
    if (modeChosen != Mode::NAMEDLOCATION)
    {
        modeChosen = Mode::NAMEDLOCATION;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseConcourse()
{
    if (modeChosen != Mode::CONCOURSE)
    {
        modeChosen = Mode::CONCOURSE;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::choosePlatformLeft()
{
    if (modeChosen != Mode::PLATFORMLEFT)
    {
        modeChosen = Mode::PLATFORMLEFT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::choosePlatformRight()
{
    if (modeChosen != Mode::PLATFORMRIGHT)
    {
        modeChosen = Mode::PLATFORMRIGHT;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::choosePlatformDown()
{
    if (modeChosen != Mode::PLATFORMDOWN)
    {
        modeChosen = Mode::PLATFORMDOWN;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::choosePlatformUp()
{
    if (modeChosen != Mode::PLATFORMUP)
    {
        modeChosen = Mode::PLATFORMUP;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet1()
{
    if (modeChosen != Mode::PARAPET1)
    {
        modeChosen = Mode::PARAPET1;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet2()
{
    if (modeChosen != Mode::PARAPET2)
    {
        modeChosen = Mode::PARAPET2;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet3()
{
    if (modeChosen != Mode::PARAPET3)
    {
        modeChosen = Mode::PARAPET3;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet4()
{
    if (modeChosen != Mode::PARAPET4)
    {
        modeChosen = Mode::PARAPET4;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet5()
{
    if (modeChosen != Mode::PARAPET5)
    {
        modeChosen = Mode::PARAPET5;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet6()
{
    if (modeChosen != Mode::PARAPET6)
    {
        modeChosen = Mode::PARAPET6;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet7()
{
    if (modeChosen != Mode::PARAPET7)
    {
        modeChosen = Mode::PARAPET7;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet8()
{
    if (modeChosen != Mode::PARAPET8)
    {
        modeChosen = Mode::PARAPET8;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet9()
{
    if (modeChosen != Mode::PARAPET9)
    {
        modeChosen = Mode::PARAPET9;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet10()
{
    if (modeChosen != Mode::PARAPET10)
    {
        modeChosen = Mode::PARAPET10;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet11()
{
    if (modeChosen != Mode::PARAPET11)
    {
        modeChosen = Mode::PARAPET11;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet12()
{
    if (modeChosen != Mode::PARAPET12)
    {
        modeChosen = Mode::PARAPET12;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet13()
{
    if (modeChosen != Mode::PARAPET13)
    {
        modeChosen = Mode::PARAPET13;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet14()
{
    if (modeChosen != Mode::PARAPET14)
    {
        modeChosen = Mode::PARAPET14;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet15()
{
    if (modeChosen != Mode::PARAPET15)
    {
        modeChosen = Mode::PARAPET15;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet16()
{
    if (modeChosen != Mode::PARAPET16)
    {
        modeChosen = Mode::PARAPET16;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet17()
{
    if (modeChosen != Mode::PARAPET17)
    {
        modeChosen = Mode::PARAPET17;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet18()
{
    if (modeChosen != Mode::PARAPET18)
    {
        modeChosen = Mode::PARAPET18;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet19()
{
    if (modeChosen != Mode::PARAPET19)
    {
        modeChosen = Mode::PARAPET19;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet20()
{
    if (modeChosen != Mode::PARAPET20)
    {
        modeChosen = Mode::PARAPET20;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet21()
{
    if (modeChosen != Mode::PARAPET21)
    {
        modeChosen = Mode::PARAPET21;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet22()
{
    if (modeChosen != Mode::PARAPET22)
    {
        modeChosen = Mode::PARAPET22;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet23()
{
    if (modeChosen != Mode::PARAPET23)
    {
        modeChosen = Mode::PARAPET23;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet24()
{
    if (modeChosen != Mode::PARAPET24)
    {
        modeChosen = Mode::PARAPET24;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet25()
{
    if (modeChosen != Mode::PARAPET25)
    {
        modeChosen = Mode::PARAPET25;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet26()
{
    if (modeChosen != Mode::PARAPET26)
    {
        modeChosen = Mode::PARAPET26;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet27()
{
    if (modeChosen != Mode::PARAPET27)
    {
        modeChosen = Mode::PARAPET27;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseParapet28()
{
    if (modeChosen != Mode::PARAPET28)
    {
        modeChosen = Mode::PARAPET28;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}

void Window::chooseLevelCrossing()
{
    if (modeChosen != Mode::LEVELCROSSING)
    {
        modeChosen = Mode::LEVELCROSSING;
    }
    else
    {
        modeChosen = Mode::NONE;
    }
    drawingSurface->setMode(modeChosen);
}



void Window::createMenuBar()
{
    menuBar = new QMenuBar();
    fileMenu = new QMenu("File");
    modeMenu = new QMenu("Mode");
    informationMenu = new QMenu("Information");
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(modeMenu);
    menuBar->addMenu(informationMenu);
    createFileMenu();
    createModeMenu();
    createInformationMenu();
}

void Window::createFileMenu()
{
    openRailwayAct = new QAction(tr("&Open Railway"), this);
    openRailwayAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openRailwayAct->setStatusTip(tr("Open an existing railway"));
    connect(openRailwayAct, &QAction::triggered, this, &Window::openRailway);
    fileMenu->addAction(openRailwayAct);
}

void Window::createModeMenu()
{
    openBuildModifyAct = new QAction(tr("&Build/Modify Menu"), this);
    openBuildModifyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
    connect(openBuildModifyAct, &QAction::triggered, this, &Window::openBuildModifyMenu);
    modeMenu->addAction(openBuildModifyAct);

    toWhiteBackgroundAct = new QAction(tr("&White Background"), this);
    connect(toWhiteBackgroundAct, &QAction::triggered, this, &Window::canvasToWhite);
    modeMenu->addAction(toWhiteBackgroundAct);

    toDarkBlueBackgroundAct = new QAction(tr("&Dark Blue Background"), this);
    connect(toDarkBlueBackgroundAct, &QAction::triggered, this, &Window::canvasToDarkBlue);
    modeMenu->addAction(toDarkBlueBackgroundAct);

    toBlackBackgroundAct = new QAction(tr("&Black Background"), this);
    connect(toBlackBackgroundAct, &QAction::triggered, this, &Window::canvasToBlack);
    modeMenu->addAction(toBlackBackgroundAct);
}

void Window::createInformationMenu()
{
    showTrackIDAct = new QAction(tr("&Show trackID"), this);
    connect(showTrackIDAct, &QAction::triggered, this, &Window::toggleTrackID);
    informationMenu->addAction(showTrackIDAct);
    showMoreTrackInfoAct = new QAction(tr("&Show more track information"), this);
    connect(showMoreTrackInfoAct, &QAction::triggered, this, &Window::toggleMoreTrackInfo);
    informationMenu->addAction(showMoreTrackInfoAct);
}


void Window::createOverallMenu()
{
    //Create top half of Menu.
    buildModifyMenu1 = new QWidget;
    buildModifyMenuLayout1 = new QHBoxLayout;
    createBuildModifyMenu1();
    QPalette pal2 = palette();
    pal2.setColor(QPalette::Window, Qt::red);
    buildModifyMenu1->setAutoFillBackground(true);
    buildModifyMenu1->setPalette(pal2);
    buildModifyMenu1->setLayout(buildModifyMenuLayout1);

    //overallMenuLayout->setAlignment(buildModifyMenu1,Qt::AlignTop);

    //Create second half of Menu.
    allMenus = new QStackedWidget;
    createElementMenu();
    allMenus->addWidget(new QWidget());
    allMenus->addWidget(elementMenu);
    allMenus->setCurrentIndex(0);
    //overallMenuLayout->addWidget(allMenus);

    createSetTrackLengthSpeedMenu();
    allMenus->addWidget(setTrackLengthSpeedMenu);

}

void Window::createBuildModifyMenu1()
{
    elementMenuButton = new QToolButton();
    elementMenuButton->setMaximumSize(QSize(32, 32));
    openElementMenuAct = new QAction();
    elementMenuButton->setDefaultAction(openElementMenuAct);
    connect(openElementMenuAct, &QAction::triggered, this, &Window::openElementMenu);
    trackIcon = new QIcon(":/icons/icons/buildMenuIcon.png");
    elementMenuButton->setIcon(*trackIcon);
    buildModifyMenuLayout1->addWidget(elementMenuButton);

    connectLinkedTrackButton = new QToolButton();
    connectLinkedTrackButton->setMaximumSize(QSize(32, 32));
    connectLinkedTrackAct = new QAction();
    connectLinkedTrackButton->setDefaultAction(connectLinkedTrackAct);
    connect(connectLinkedTrackAct, &QAction::triggered, this, &Window::connectLinkedTrack);
    connectLinkedTrackIcon = new QIcon(":/icons/icons/connectLinkTrack.png");
    connectLinkedTrackButton->setIcon(*connectLinkedTrackIcon);
    buildModifyMenuLayout1->addWidget(connectLinkedTrackButton);
    connectLinkedTrackButton->setEnabled(false);

    checkAllTrackButton = new QToolButton();
    checkAllTrackButton->setMaximumSize(QSize(32, 32));
    checkAllTrackAct = new QAction();
    checkAllTrackButton->setDefaultAction(checkAllTrackAct);
    connect(checkAllTrackAct, &QAction::triggered, this, &Window::checkAllTrack);
    checkAllTrackIcon = new QIcon(":/icons/icons/checkAllTrackLinked.png");
    checkAllTrackButton->setIcon(*checkAllTrackIcon);
    buildModifyMenuLayout1->addWidget(checkAllTrackButton);
    checkAllTrackButton->setEnabled(false);

    addEditRemoveTextButton = new QToolButton();
    addEditRemoveTextButton->setMaximumSize(QSize(32, 32));
    addEditRemoveTextAct = new QAction();
    addEditRemoveTextButton->setDefaultAction(addEditRemoveTextAct);
    connect(addEditRemoveTextAct, &QAction::triggered, this, &Window::addEditRemoveText);
    addEditRemoveTextIcon = new QIcon(":/icons/icons/addEditRemoveText.png");
    addEditRemoveTextButton->setIcon(*addEditRemoveTextIcon);
    buildModifyMenuLayout1->addWidget(addEditRemoveTextButton);

    moveTextButton = new QToolButton();
    moveTextButton->setMaximumSize(QSize(32, 32));
    moveTextAct = new QAction();
    moveTextButton->setDefaultAction(moveTextAct);
    connect(moveTextAct, &QAction::triggered, this, &Window::moveText);
    moveTextIcon = new QIcon(":/icons/icons/moveText.png");
    moveTextButton->setIcon(*moveTextIcon);
    buildModifyMenuLayout1->addWidget(moveTextButton);

    setChangeNamedLocationButton = new QToolButton();
    setChangeNamedLocationButton->setMaximumSize(QSize(32, 32));
    setChangeNamedLocationAct = new QAction();
    setChangeNamedLocationButton->setDefaultAction(setChangeNamedLocationAct);
    connect(setChangeNamedLocationAct, &QAction::triggered, this, &Window::setChangeNamedLocation);
    setChangeNamedLocationIcon = new QIcon(":/icons/icons/setChangeNamedLocation.png");
    setChangeNamedLocationButton->setIcon(*setChangeNamedLocationIcon);
    buildModifyMenuLayout1->addWidget(setChangeNamedLocationButton);

    fontButton = new QToolButton();
    fontButton->setMaximumSize(QSize(32, 32));
    setFontAct = new QAction();
    fontButton->setDefaultAction(setFontAct);
    connect(setFontAct, &QAction::triggered, this, &Window::openFontBox);
    setFontIcon = new QIcon(":/icons/icons/changeFont.png");
    fontButton->setIcon(*setFontIcon);
    buildModifyMenuLayout1->addWidget(fontButton);

    openTrackLengthSpeedPanelButton = new QToolButton();
    openTrackLengthSpeedPanelButton->setMaximumSize(QSize(32, 32));
    openTrackLengthSpeedPanelAct = new QAction();
    openTrackLengthSpeedPanelButton->setDefaultAction(openTrackLengthSpeedPanelAct);
    connect(openTrackLengthSpeedPanelAct, &QAction::triggered, this, &Window::openTrackLengthSpeedPanel);
    openTrackLengthSpeedPanelIcon = new QIcon(":/icons/icons/setDistanceSpeed.png");
    openTrackLengthSpeedPanelButton->setIcon(*openTrackLengthSpeedPanelIcon);
    buildModifyMenuLayout1->addWidget(openTrackLengthSpeedPanelButton);

    aspectButton = new QToolButton();
    aspectButton->setMaximumSize(QSize(32, 32));
    changeAspectAct = new QAction();
    aspectButton->setDefaultAction(changeAspectAct);
    connect(changeAspectAct, &QAction::triggered, this, &Window::changeAspect);
    aspect4Icon = new QIcon(":/icons/icons/aspect4.png");
    aspect3Icon = new QIcon(":/icons/icons/aspect3.png");
    aspect2Icon = new QIcon(":/icons/icons/aspect2.png");
    aspectShuntIcon = new QIcon(":/icons/icons/aspectShunt.png");
    aspectButton->setIcon(*aspect4Icon);
    buildModifyMenuLayout1->addWidget(aspectButton);
}

void Window::createElementMenu()
{

    elementMenu = new QWidget;
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::green);
    elementMenu->setAutoFillBackground(true);
    elementMenu->setPalette(pal);
    elementMenuLayout = new QHBoxLayout;

    createElementBlock1();
    createElementBlock2();
    createElementBlock3();
    createElementBlock4();
    createElementBlock5();

    elementMenuLayout->addLayout(elementBlock1);
    elementMenuLayout->addLayout(elementBlock2);
    elementMenuLayout->addLayout(elementBlock3);
    elementMenuLayout->addLayout(elementBlock4);
    elementMenuLayout->addLayout(elementBlock5);
    elementMenuLayout->setAlignment(elementBlock1, Qt::AlignLeft);
    elementMenuLayout->setAlignment(elementBlock2, Qt::AlignLeft);
    elementMenuLayout->setAlignment(elementBlock3, Qt::AlignLeft);
    elementMenuLayout->setAlignment(elementBlock4, Qt::AlignLeft);
    elementMenuLayout->setAlignment(elementBlock5, Qt::AlignLeft);

    elementMenu->setLayout(elementMenuLayout);
}

void Window::createElementBlock1()
{
    elementBlock1 = new QGridLayout;
    elementBlock1->setContentsMargins(1, 1, 1, 1);
    elementBlock1->setHorizontalSpacing(1);
    elementBlock1->setVerticalSpacing(1);

    straightHButton = new QToolButton();
    straightHButton->setMaximumSize(QSize(32, 32));
    chooseStraightHAct = new QAction();
    straightHButton->setDefaultAction(chooseStraightHAct);
    connect(chooseStraightHAct, &QAction::triggered, this, &Window::chooseStraightH);
    straightHIcon = new QIcon(":/graphics/graphics/straightH.png");
    straightHButton->setIcon(*straightHIcon);
    elementBlock1->addWidget(straightHButton, 0, 0);

    straightVButton = new QToolButton();
    straightVButton->setMaximumSize(QSize(32, 32));
    chooseStraightVAct = new QAction();
    straightVButton->setDefaultAction(chooseStraightVAct);
    connect(chooseStraightVAct, &QAction::triggered, this, &Window::chooseStraightV);
    straightVIcon = new QIcon(":/graphics/graphics/straightV.png");
    straightVButton->setIcon(*straightVIcon);
    elementBlock1->addWidget(straightVButton, 0, 1);

    directLeftButton = new QToolButton();
    directLeftButton->setMaximumSize(QSize(32, 32));
    chooseDirectLeftAct = new QAction();
    directLeftButton->setDefaultAction(chooseDirectLeftAct);
    connect(chooseDirectLeftAct, &QAction::triggered, this, &Window::chooseDirectLeft);
    directLeftIcon = new QIcon(":/graphics/graphics/directLeft.png");
    directLeftButton->setIcon(*directLeftIcon);
    elementBlock1->addWidget(directLeftButton, 0, 2);

    directRightButton = new QToolButton();
    directRightButton->setMaximumSize(QSize(32, 32));
    chooseDirectRightAct = new QAction();
    directRightButton->setDefaultAction(chooseDirectRightAct);
    connect(chooseDirectRightAct, &QAction::triggered, this, &Window::chooseDirectRight);
    directRightIcon = new QIcon(":/graphics/graphics/directRight.png");
    directRightButton->setIcon(*directRightIcon);
    elementBlock1->addWidget(directRightButton, 0, 3);

    directUpButton = new QToolButton();
    directUpButton->setMaximumSize(QSize(32, 32));
    chooseDirectUpAct = new QAction();
    directUpButton->setDefaultAction(chooseDirectUpAct);
    connect(chooseDirectUpAct, &QAction::triggered, this, &Window::chooseDirectUp);
    directUpIcon = new QIcon(":/graphics/graphics/directUp.png");
    directUpButton->setIcon(*directUpIcon);
    elementBlock1->addWidget(directUpButton, 0, 4);

    directDownButton = new QToolButton();
    directDownButton->setMaximumSize(QSize(32, 32));
    chooseDirectDownAct = new QAction();
    directDownButton->setDefaultAction(chooseDirectDownAct);
    connect(chooseDirectDownAct, &QAction::triggered, this, &Window::chooseDirectDown);
    directDownIcon = new QIcon(":/graphics/graphics/directDown.png");
    directDownButton->setIcon(*directDownIcon);
    elementBlock1->addWidget(directDownButton, 0, 5);

    straightRightUpButton = new QToolButton();
    straightRightUpButton->setMaximumSize(QSize(32, 32));
    chooseStraightRightUpAct = new QAction();
    straightRightUpButton->setDefaultAction(chooseStraightRightUpAct);
    connect(chooseStraightRightUpAct, &QAction::triggered, this, &Window::chooseStraightRightUp);
    straightRightUpIcon = new QIcon(":/graphics/graphics/straightRightUp.png");
    straightRightUpButton->setIcon(*straightRightUpIcon);
    elementBlock1->addWidget(straightRightUpButton, 0, 6);

    straightLeftUpButton = new QToolButton();
    straightLeftUpButton->setMaximumSize(QSize(32, 32));
    chooseStraightLeftUpAct = new QAction();
    straightLeftUpButton->setDefaultAction(chooseStraightLeftUpAct);
    connect(chooseStraightLeftUpAct, &QAction::triggered, this, &Window::chooseStraightLeftUp);
    straightLeftUpIcon = new QIcon(":/graphics/graphics/straightLeftUp.png");
    straightLeftUpButton->setIcon(*straightLeftUpIcon);
    elementBlock1->addWidget(straightLeftUpButton, 0, 7);

    directRightUpButton = new QToolButton();
    directRightUpButton->setMaximumSize(QSize(32, 32));
    chooseDirectRightUpAct = new QAction();
    directRightUpButton->setDefaultAction(chooseDirectRightUpAct);
    connect(chooseDirectRightUpAct, &QAction::triggered, this, &Window::chooseDirectRightUp);
    directRightUpIcon = new QIcon(":/graphics/graphics/directRightUp.png");
    directRightUpButton->setIcon(*directRightUpIcon);
    elementBlock1->addWidget(directRightUpButton, 0, 8);

    directLeftUpButton = new QToolButton();
    directLeftUpButton->setMaximumSize(QSize(32, 32));
    chooseDirectLeftUpAct = new QAction();
    directLeftUpButton->setDefaultAction(chooseDirectLeftUpAct);
    connect(chooseDirectLeftUpAct, &QAction::triggered, this, &Window::chooseDirectLeftUp);
    directLeftUpIcon = new QIcon(":/graphics/graphics/directLeftUp.png");
    directLeftUpButton->setIcon(*directLeftUpIcon);
    elementBlock1->addWidget(directLeftUpButton, 0, 9);

    directLeftDownButton = new QToolButton();
    directLeftDownButton->setMaximumSize(QSize(32, 32));
    chooseDirectLeftDownAct = new QAction();
    directLeftDownButton->setDefaultAction(chooseDirectLeftDownAct);
    connect(chooseDirectLeftDownAct, &QAction::triggered, this, &Window::chooseDirectLeftDown);
    directLeftDownIcon = new QIcon(":/graphics/graphics/directLeftDown.png");
    directLeftDownButton->setIcon(*directLeftDownIcon);
    elementBlock1->addWidget(directLeftDownButton, 0, 10);

    directRightDownButton = new QToolButton();
    directRightDownButton->setMaximumSize(QSize(32, 32));
    chooseDirectRightDownAct = new QAction();
    directRightDownButton->setDefaultAction(chooseDirectRightDownAct);
    connect(chooseDirectRightDownAct, &QAction::triggered, this, &Window::chooseDirectRightDown);
    directRightDownIcon = new QIcon(":/graphics/graphics/directRightDown.png");
    directRightDownButton->setIcon(*directRightDownIcon);
    elementBlock1->addWidget(directRightDownButton, 0, 11);

    tightCurve1Button = new QToolButton();
    tightCurve1Button->setMaximumSize(QSize(32, 32));
    chooseTightCurve1Act = new QAction();
    tightCurve1Button->setDefaultAction(chooseTightCurve1Act);
    connect(chooseTightCurve1Act, &QAction::triggered, this, &Window::chooseTightCurve1);
    tightCurve1Icon = new QIcon(":/graphics/graphics/tightCurve1.png");
    tightCurve1Button->setIcon(*tightCurve1Icon);
    elementBlock1->addWidget(tightCurve1Button, 0, 12);

    tightCurve2Button = new QToolButton();
    tightCurve2Button->setMaximumSize(QSize(32, 32));
    chooseTightCurve2Act = new QAction();
    tightCurve2Button->setDefaultAction(chooseTightCurve2Act);
    connect(chooseTightCurve2Act, &QAction::triggered, this, &Window::chooseTightCurve2);
    tightCurve2Icon = new QIcon(":/graphics/graphics/tightCurve2.png");
    tightCurve2Button->setIcon(*tightCurve2Icon);
    elementBlock1->addWidget(tightCurve2Button, 0, 13);

    tightCurve3Button = new QToolButton();
    tightCurve3Button->setMaximumSize(QSize(32, 32));
    chooseTightCurve3Act = new QAction();
    tightCurve3Button->setDefaultAction(chooseTightCurve3Act);
    connect(chooseTightCurve3Act, &QAction::triggered, this, &Window::chooseTightCurve3);
    tightCurve3Icon = new QIcon(":/graphics/graphics/tightCurve3.png");
    tightCurve3Button->setIcon(*tightCurve3Icon);
    elementBlock1->addWidget(tightCurve3Button, 0, 14);

    tightCurve4Button = new QToolButton();
    tightCurve4Button->setMaximumSize(QSize(32, 32));
    chooseTightCurve4Act = new QAction();
    tightCurve4Button->setDefaultAction(chooseTightCurve4Act);
    connect(chooseTightCurve4Act, &QAction::triggered, this, &Window::chooseTightCurve4);
    tightCurve4Icon = new QIcon(":/graphics/graphics/tightCurve4.png");
    tightCurve4Button->setIcon(*tightCurve4Icon);
    elementBlock1->addWidget(tightCurve4Button, 0, 15);

    curve1Button = new QToolButton();
    curve1Button->setMaximumSize(QSize(32, 32));
    chooseCurve1Act = new QAction();
    curve1Button->setDefaultAction(chooseCurve1Act);
    connect(chooseCurve1Act, &QAction::triggered, this, &Window::chooseCurve1);
    curve1Icon = new QIcon(":/graphics/graphics/curve1.png");
    curve1Button->setIcon(*curve1Icon);
    elementBlock1->addWidget(curve1Button, 0, 16);

    curve2Button = new QToolButton();
    curve2Button->setMaximumSize(QSize(32, 32));
    chooseCurve2Act = new QAction();
    curve2Button->setDefaultAction(chooseCurve2Act);
    connect(chooseCurve2Act, &QAction::triggered, this, &Window::chooseCurve2);
    curve2Icon = new QIcon(":/graphics/graphics/curve2.png");
    curve2Button->setIcon(*curve2Icon);
    elementBlock1->addWidget(curve2Button, 0, 17);

    curve3Button = new QToolButton();
    curve3Button->setMaximumSize(QSize(32, 32));
    chooseCurve3Act = new QAction();
    curve3Button->setDefaultAction(chooseCurve3Act);
    connect(chooseCurve3Act, &QAction::triggered, this, &Window::chooseCurve3);
    curve3Icon = new QIcon(":/graphics/graphics/curve3.png");
    curve3Button->setIcon(*curve3Icon);
    elementBlock1->addWidget(curve3Button, 0, 18);

    curve4Button = new QToolButton();
    curve4Button->setMaximumSize(QSize(32, 32));
    chooseCurve4Act = new QAction();
    curve4Button->setDefaultAction(chooseCurve4Act);
    connect(chooseCurve4Act, &QAction::triggered, this, &Window::chooseCurve4);
    curve4Icon = new QIcon(":/graphics/graphics/curve4.png");
    curve4Button->setIcon(*curve4Icon);
    elementBlock1->addWidget(curve4Button, 0, 19);

    linkLeftButton = new QToolButton();
    linkLeftButton->setMaximumSize(QSize(32, 32));
    chooseLinkLeftAct = new QAction();
    linkLeftButton->setDefaultAction(chooseLinkLeftAct);
    connect(chooseLinkLeftAct, &QAction::triggered, this, &Window::chooseLinkLeft);
    linkLeftIcon = new QIcon(":/graphics/graphics/linkLeftSet.png");
    linkLeftButton->setIcon(*linkLeftIcon);
    elementBlock1->addWidget(linkLeftButton, 1, 0);

    linkRightButton = new QToolButton();
    linkRightButton->setMaximumSize(QSize(32, 32));
    chooseLinkRightAct = new QAction();
    linkRightButton->setDefaultAction(chooseLinkRightAct);
    connect(chooseLinkRightAct, &QAction::triggered, this, &Window::chooseLinkRight);
    linkRightIcon = new QIcon(":/graphics/graphics/linkRightSet.png");
    linkRightButton->setIcon(*linkRightIcon);
    elementBlock1->addWidget(linkRightButton, 1, 1);

    linkDownButton = new QToolButton();
    linkDownButton->setMaximumSize(QSize(32, 32));
    chooseLinkDownAct = new QAction();
    linkDownButton->setDefaultAction(chooseLinkDownAct);
    connect(chooseLinkDownAct, &QAction::triggered, this, &Window::chooseLinkDown);
    linkDownIcon = new QIcon(":/graphics/graphics/linkDownSet.png");
    linkDownButton->setIcon(*linkDownIcon);
    elementBlock1->addWidget(linkDownButton, 1, 2);

    linkUpButton = new QToolButton();
    linkUpButton->setMaximumSize(QSize(32, 32));
    chooseLinkUpAct = new QAction();
    linkUpButton->setDefaultAction(chooseLinkUpAct);
    connect(chooseLinkUpAct, &QAction::triggered, this, &Window::chooseLinkUp);
    linkUpIcon = new QIcon(":/graphics/graphics/linkUpSet.png");
    linkUpButton->setIcon(*linkUpIcon);
    elementBlock1->addWidget(linkUpButton, 1, 3);

    linkLeftUpButton = new QToolButton();
    linkLeftUpButton->setMaximumSize(QSize(32, 32));
    chooseLinkLeftUpAct = new QAction();
    linkLeftUpButton->setDefaultAction(chooseLinkLeftUpAct);
    connect(chooseLinkLeftUpAct, &QAction::triggered, this, &Window::chooseLinkLeftUp);
    linkLeftUpIcon = new QIcon(":/graphics/graphics/linkLeftUpSet.png");
    linkLeftUpButton->setIcon(*linkLeftUpIcon);
    elementBlock1->addWidget(linkLeftUpButton, 1, 4);

    linkRightUpButton = new QToolButton();
    linkRightUpButton->setMaximumSize(QSize(32, 32));
    chooseLinkRightUpAct = new QAction();
    linkRightUpButton->setDefaultAction(chooseLinkRightUpAct);
    connect(chooseLinkRightUpAct, &QAction::triggered, this, &Window::chooseLinkRightUp);
    linkRightUpIcon = new QIcon(":/graphics/graphics/linkRightUpSet.png");
    linkRightUpButton->setIcon(*linkRightUpIcon);
    elementBlock1->addWidget(linkRightUpButton, 1, 5);

    linkLeftDownButton = new QToolButton();
    linkLeftDownButton->setMaximumSize(QSize(32, 32));
    chooseLinkLeftDownAct = new QAction();
    linkLeftDownButton->setDefaultAction(chooseLinkLeftDownAct);
    connect(chooseLinkLeftDownAct, &QAction::triggered, this, &Window::chooseLinkLeftDown);
    linkLeftDownIcon = new QIcon(":/graphics/graphics/linkLeftDownSet.png");
    linkLeftDownButton->setIcon(*linkLeftDownIcon);
    elementBlock1->addWidget(linkLeftDownButton, 1, 6);

    linkRightDownButton = new QToolButton();
    linkRightDownButton->setMaximumSize(QSize(32, 32));
    chooseLinkRightDownAct = new QAction();
    linkRightDownButton->setDefaultAction(chooseLinkRightDownAct);
    connect(chooseLinkRightDownAct, &QAction::triggered, this, &Window::chooseLinkRightDown);
    linkRightDownIcon = new QIcon(":/graphics/graphics/linkRightDownSet.png");
    linkRightDownButton->setIcon(*linkRightDownIcon);
    elementBlock1->addWidget(linkRightDownButton, 1, 7);

    exitLeftButton = new QToolButton();
    exitLeftButton->setMaximumSize(QSize(32, 32));
    chooseExitLeftAct = new QAction();
    exitLeftButton->setDefaultAction(chooseExitLeftAct);
    connect(chooseExitLeftAct, &QAction::triggered, this, &Window::chooseExitLeft);
    exitLeftIcon = new QIcon(":/graphics/graphics/exitLeft.png");
    exitLeftButton->setIcon(*exitLeftIcon);
    elementBlock1->addWidget(exitLeftButton, 1, 8);

    exitRightButton = new QToolButton();
    exitRightButton->setMaximumSize(QSize(32, 32));
    chooseExitRightAct = new QAction();
    exitRightButton->setDefaultAction(chooseExitRightAct);
    connect(chooseExitRightAct, &QAction::triggered, this, &Window::chooseExitRight);
    exitRightIcon = new QIcon(":/graphics/graphics/exitRight.png");
    exitRightButton->setIcon(*exitRightIcon);
    elementBlock1->addWidget(exitRightButton, 1, 9);

    exitDownButton = new QToolButton();
    exitDownButton->setMaximumSize(QSize(32, 32));
    chooseExitDownAct = new QAction();
    exitDownButton->setDefaultAction(chooseExitDownAct);
    connect(chooseExitDownAct, &QAction::triggered, this, &Window::chooseExitDown);
    exitDownIcon = new QIcon(":/graphics/graphics/exitDown.png");
    exitDownButton->setIcon(*exitDownIcon);
    elementBlock1->addWidget(exitDownButton, 1, 10);

    exitUpButton = new QToolButton();
    exitUpButton->setMaximumSize(QSize(32, 32));
    chooseExitUpAct = new QAction();
    exitUpButton->setDefaultAction(chooseExitUpAct);
    connect(chooseExitUpAct, &QAction::triggered, this, &Window::chooseExitUp);
    exitUpIcon = new QIcon(":/graphics/graphics/exitUp.png");
    exitUpButton->setIcon(*exitUpIcon);
    elementBlock1->addWidget(exitUpButton, 1, 11);

    exitLeftUpButton = new QToolButton();
    exitLeftUpButton->setMaximumSize(QSize(32, 32));
    chooseExitLeftUpAct = new QAction();
    exitLeftUpButton->setDefaultAction(chooseExitLeftUpAct);
    connect(chooseExitLeftUpAct, &QAction::triggered, this, &Window::chooseExitLeftUp);
    exitLeftUpIcon = new QIcon(":/graphics/graphics/exitLeftUp.png");
    exitLeftUpButton->setIcon(*exitLeftUpIcon);
    elementBlock1->addWidget(exitLeftUpButton, 1, 12);

    exitRightUpButton = new QToolButton();
    exitRightUpButton->setMaximumSize(QSize(32, 32));
    chooseExitRightUpAct = new QAction();
    exitRightUpButton->setDefaultAction(chooseExitRightUpAct);
    connect(chooseExitRightUpAct, &QAction::triggered, this, &Window::chooseExitRightUp);
    exitRightUpIcon = new QIcon(":/graphics/graphics/exitRightUp.png");
    exitRightUpButton->setIcon(*exitRightUpIcon);
    elementBlock1->addWidget(exitRightUpButton, 1, 13);

    exitLeftDownButton = new QToolButton();
    exitLeftDownButton->setMaximumSize(QSize(32, 32));
    chooseExitLeftDownAct = new QAction();
    exitLeftDownButton->setDefaultAction(chooseExitLeftDownAct);
    connect(chooseExitLeftDownAct, &QAction::triggered, this, &Window::chooseExitLeftDown);
    exitLeftDownIcon = new QIcon(":/graphics/graphics/exitLeftDown.png");
    exitLeftDownButton->setIcon(*exitLeftDownIcon);
    elementBlock1->addWidget(exitLeftDownButton, 1, 14);

    exitRightDownButton = new QToolButton();
    exitRightDownButton->setMaximumSize(QSize(32, 32));
    chooseExitRightDownAct = new QAction();
    exitRightDownButton->setDefaultAction(chooseExitRightDownAct);
    connect(chooseExitRightDownAct, &QAction::triggered, this, &Window::chooseExitRightDown);
    exitRightDownIcon = new QIcon(":/graphics/graphics/exitRightDown.png");
    exitRightDownButton->setIcon(*exitRightDownIcon);
    elementBlock1->addWidget(exitRightDownButton, 1, 15);

    curve5Button = new QToolButton();
    curve5Button->setMaximumSize(QSize(32, 32));
    chooseCurve5Act = new QAction();
    curve5Button->setDefaultAction(chooseCurve5Act);
    connect(chooseCurve5Act, &QAction::triggered, this, &Window::chooseCurve5);
    curve5Icon = new QIcon(":/graphics/graphics/curve5.png");
    curve5Button->setIcon(*curve5Icon);
    elementBlock1->addWidget(curve5Button, 1, 16);

    curve6Button = new QToolButton();
    curve6Button->setMaximumSize(QSize(32, 32));
    chooseCurve6Act = new QAction();
    curve6Button->setDefaultAction(chooseCurve6Act);
    connect(chooseCurve6Act, &QAction::triggered, this, &Window::chooseCurve6);
    curve6Icon = new QIcon(":/graphics/graphics/curve6.png");
    curve6Button->setIcon(*curve6Icon);
    elementBlock1->addWidget(curve6Button, 1, 17);

    curve7Button = new QToolButton();
    curve7Button->setMaximumSize(QSize(32, 32));
    chooseCurve7Act = new QAction();
    curve7Button->setDefaultAction(chooseCurve7Act);
    connect(chooseCurve7Act, &QAction::triggered, this, &Window::chooseCurve7);
    curve7Icon = new QIcon(":/graphics/graphics/curve7.png");
    curve7Button->setIcon(*curve7Icon);
    elementBlock1->addWidget(curve7Button, 1, 18);

    curve8Button = new QToolButton();
    curve8Button->setMaximumSize(QSize(32, 32));
    chooseCurve8Act = new QAction();
    curve8Button->setDefaultAction(chooseCurve8Act);
    connect(chooseCurve8Act, &QAction::triggered, this, &Window::chooseCurve8);
    curve8Icon = new QIcon(":/graphics/graphics/curve8.png");
    curve8Button->setIcon(*curve8Icon);
    elementBlock1->addWidget(curve8Button, 1, 19);

    bufferLeftButton = new QToolButton();
    bufferLeftButton->setMaximumSize(QSize(32, 32));
    chooseBufferLeftAct = new QAction();
    bufferLeftButton->setDefaultAction(chooseBufferLeftAct);
    connect(chooseBufferLeftAct, &QAction::triggered, this, &Window::chooseBufferLeft);
    bufferLeftIcon = new QIcon(":/graphics/graphics/bufferLeft.png");
    bufferLeftButton->setIcon(*bufferLeftIcon);
    elementBlock1->addWidget(bufferLeftButton, 2, 0);

    bufferRightButton = new QToolButton();
    bufferRightButton->setMaximumSize(QSize(32, 32));
    chooseBufferRightAct = new QAction();
    bufferRightButton->setDefaultAction(chooseBufferRightAct);
    connect(chooseBufferRightAct, &QAction::triggered, this, &Window::chooseBufferRight);
    bufferRightIcon = new QIcon(":/graphics/graphics/bufferRight.png");
    bufferRightButton->setIcon(*bufferRightIcon);
    elementBlock1->addWidget(bufferRightButton, 2, 1);

    bufferDownButton = new QToolButton();
    bufferDownButton->setMaximumSize(QSize(32, 32));
    chooseBufferDownAct = new QAction();
    bufferDownButton->setDefaultAction(chooseBufferDownAct);
    connect(chooseBufferDownAct, &QAction::triggered, this, &Window::chooseBufferDown);
    bufferDownIcon = new QIcon(":/graphics/graphics/bufferDown.png");
    bufferDownButton->setIcon(*bufferDownIcon);
    elementBlock1->addWidget(bufferDownButton, 2, 2);

    bufferUpButton = new QToolButton();
    bufferUpButton->setMaximumSize(QSize(32, 32));
    chooseBufferUpAct = new QAction();
    bufferUpButton->setDefaultAction(chooseBufferUpAct);
    connect(chooseBufferUpAct, &QAction::triggered, this, &Window::chooseBufferUp);
    bufferUpIcon = new QIcon(":/graphics/graphics/bufferUp.png");
    bufferUpButton->setIcon(*bufferUpIcon);
    elementBlock1->addWidget(bufferUpButton, 2, 3);

    bufferLeftUpButton = new QToolButton();
    bufferLeftUpButton->setMaximumSize(QSize(32, 32));
    chooseBufferLeftUpAct = new QAction();
    bufferLeftUpButton->setDefaultAction(chooseBufferLeftUpAct);
    connect(chooseBufferLeftUpAct, &QAction::triggered, this, &Window::chooseBufferLeftUp);
    bufferLeftUpIcon = new QIcon(":/graphics/graphics/bufferLeftUp.png");
    bufferLeftUpButton->setIcon(*bufferLeftUpIcon);
    elementBlock1->addWidget(bufferLeftUpButton, 2, 4);

    bufferRightUpButton = new QToolButton();
    bufferRightUpButton->setMaximumSize(QSize(32, 32));
    chooseBufferRightUpAct = new QAction();
    bufferRightUpButton->setDefaultAction(chooseBufferRightUpAct);
    connect(chooseBufferRightUpAct, &QAction::triggered, this, &Window::chooseBufferRightUp);
    bufferRightUpIcon = new QIcon(":/graphics/graphics/bufferRightUp.png");
    bufferRightUpButton->setIcon(*bufferRightUpIcon);
    elementBlock1->addWidget(bufferRightUpButton, 2, 5);

    bufferLeftDownButton = new QToolButton();
    bufferLeftDownButton->setMaximumSize(QSize(32, 32));
    chooseBufferLeftDownAct = new QAction();
    bufferLeftDownButton->setDefaultAction(chooseBufferLeftDownAct);
    connect(chooseBufferLeftDownAct, &QAction::triggered, this, &Window::chooseBufferLeftDown);
    bufferLeftDownIcon = new QIcon(":/graphics/graphics/bufferLeftDown.png");
    bufferLeftDownButton->setIcon(*bufferLeftDownIcon);
    elementBlock1->addWidget(bufferLeftDownButton, 2, 6);

    bufferRightDownButton = new QToolButton();
    bufferRightDownButton->setMaximumSize(QSize(32, 32));
    chooseBufferRightDownAct = new QAction();
    bufferRightDownButton->setDefaultAction(chooseBufferRightDownAct);
    connect(chooseBufferRightDownAct, &QAction::triggered, this, &Window::chooseBufferRightDown);
    bufferRightDownIcon = new QIcon(":/graphics/graphics/bufferRightDown.png");
    bufferRightDownButton->setIcon(*bufferRightDownIcon);
    elementBlock1->addWidget(bufferRightDownButton, 2, 7);

    signalLeftButton = new QToolButton();
    signalLeftButton->setMaximumSize(QSize(32, 32));
    chooseSignalLeftAct = new QAction();
    signalLeftButton->setDefaultAction(chooseSignalLeftAct);
    connect(chooseSignalLeftAct, &QAction::triggered, this, &Window::chooseSignalLeft);
    signalLeftIcon = new QIcon(":/graphics/graphics/signalLeft.png");
    shuntLeftIcon = new QIcon(":/graphics/graphics/shuntLeftRed.png");
    signalLeftButton->setIcon(*signalLeftIcon);
    elementBlock1->addWidget(signalLeftButton, 2, 8);

    signalRightButton = new QToolButton();
    signalRightButton->setMaximumSize(QSize(32, 32));
    chooseSignalRightAct = new QAction();
    signalRightButton->setDefaultAction(chooseSignalRightAct);
    connect(chooseSignalRightAct, &QAction::triggered, this, &Window::chooseSignalRight);
    signalRightIcon = new QIcon(":/graphics/graphics/signalRight.png");
    shuntRightIcon = new QIcon(":/graphics/graphics/shuntRightRed.png");
    signalRightButton->setIcon(*signalRightIcon);
    elementBlock1->addWidget(signalRightButton, 2, 9);

    signalDownButton = new QToolButton();
    signalDownButton->setMaximumSize(QSize(32, 32));
    chooseSignalDownAct = new QAction();
    signalDownButton->setDefaultAction(chooseSignalDownAct);
    connect(chooseSignalDownAct, &QAction::triggered, this, &Window::chooseSignalDown);
    signalDownIcon = new QIcon(":/graphics/graphics/signalDown.png");
    shuntDownIcon = new QIcon(":/graphics/graphics/shuntDownRed.png");
    signalDownButton->setIcon(*signalDownIcon);
    elementBlock1->addWidget(signalDownButton, 2, 10);

    signalUpButton = new QToolButton();
    signalUpButton->setMaximumSize(QSize(32, 32));
    chooseSignalUpAct = new QAction();
    signalUpButton->setDefaultAction(chooseSignalUpAct);
    connect(chooseSignalUpAct, &QAction::triggered, this, &Window::chooseSignalUp);
    signalUpIcon = new QIcon(":/graphics/graphics/signalUp.png");
    shuntUpIcon = new QIcon(":/graphics/graphics/shuntUpRed.png");
    signalUpButton->setIcon(*signalUpIcon);
    elementBlock1->addWidget(signalUpButton, 2, 11);

    signalLeftUpButton = new QToolButton();
    signalLeftUpButton->setMaximumSize(QSize(32, 32));
    chooseSignalLeftUpAct = new QAction();
    signalLeftUpButton->setDefaultAction(chooseSignalLeftUpAct);
    connect(chooseSignalLeftUpAct, &QAction::triggered, this, &Window::chooseSignalLeftUp);
    signalLeftUpIcon = new QIcon(":/graphics/graphics/signalLeftUp.png");
    shuntLeftUpIcon = new QIcon(":/graphics/graphics/shuntLeftUpRed.png");
    signalLeftUpButton->setIcon(*signalLeftUpIcon);
    elementBlock1->addWidget(signalLeftUpButton, 2, 12);

    signalRightUpButton = new QToolButton();
    signalRightUpButton->setMaximumSize(QSize(32, 32));
    chooseSignalRightUpAct = new QAction();
    signalRightUpButton->setDefaultAction(chooseSignalRightUpAct);
    connect(chooseSignalRightUpAct, &QAction::triggered, this, &Window::chooseSignalRightUp);
    signalRightUpIcon = new QIcon(":/graphics/graphics/signalRightUp.png");
    shuntRightUpIcon = new QIcon(":/graphics/graphics/shuntRightUpRed.png");
    signalRightUpButton->setIcon(*signalRightUpIcon);
    elementBlock1->addWidget(signalRightUpButton, 2, 13);

    signalLeftDownButton = new QToolButton();
    signalLeftDownButton->setMaximumSize(QSize(32, 32));
    chooseSignalLeftDownAct = new QAction();
    signalLeftDownButton->setDefaultAction(chooseSignalLeftDownAct);
    connect(chooseSignalLeftDownAct, &QAction::triggered, this, &Window::chooseSignalLeftDown);
    signalLeftDownIcon = new QIcon(":/graphics/graphics/signalLeftDown.png");
    shuntLeftDownIcon = new QIcon(":/graphics/graphics/shuntLeftDownRed.png");
    signalLeftDownButton->setIcon(*signalLeftDownIcon);
    elementBlock1->addWidget(signalLeftDownButton, 2, 14);

    signalRightDownButton = new QToolButton();
    signalRightDownButton->setMaximumSize(QSize(32, 32));
    chooseSignalRightDownAct = new QAction();
    signalRightDownButton->setDefaultAction(chooseSignalRightDownAct);
    connect(chooseSignalRightDownAct, &QAction::triggered, this, &Window::chooseSignalRightDown);
    signalRightDownIcon = new QIcon(":/graphics/graphics/signalRightDown.png");
    shuntRightDownIcon = new QIcon(":/graphics/graphics/shuntRightDownRed.png");
    signalRightDownButton->setIcon(*signalRightDownIcon);
    elementBlock1->addWidget(signalRightDownButton, 2, 15);

    bridge1Button = new QToolButton();
    bridge1Button->setMaximumSize(QSize(32, 32));
    chooseBridge1Act = new QAction();
    bridge1Button->setDefaultAction(chooseBridge1Act);
    connect(chooseBridge1Act, &QAction::triggered, this, &Window::chooseBridge1);
    bridge1Icon = new QIcon(":/graphics/graphics/bridgeSet1.png");
    bridge1Button->setIcon(*bridge1Icon);
    elementBlock1->addWidget(bridge1Button, 2, 16);

    bridge2Button = new QToolButton();
    bridge2Button->setMaximumSize(QSize(32, 32));
    chooseBridge2Act = new QAction();
    bridge2Button->setDefaultAction(chooseBridge2Act);
    connect(chooseBridge2Act, &QAction::triggered, this, &Window::chooseBridge2);
    bridge2Icon = new QIcon(":/graphics/graphics/bridgeSet2.png");
    bridge2Button->setIcon(*bridge2Icon);
    elementBlock1->addWidget(bridge2Button, 2, 17);

    underpass1Button = new QToolButton();
    underpass1Button->setMaximumSize(QSize(32, 32));
    chooseUnderpass1Act = new QAction();
    underpass1Button->setDefaultAction(chooseUnderpass1Act);
    connect(chooseUnderpass1Act, &QAction::triggered, this, &Window::chooseUnderpass1);
    underpass1Icon = new QIcon(":/graphics/graphics/underpassSet1.png");
    underpass1Button->setIcon(*underpass1Icon);
    elementBlock1->addWidget(underpass1Button, 2, 18);

    underpass2Button = new QToolButton();
    underpass2Button->setMaximumSize(QSize(32, 32));
    chooseUnderpass2Act = new QAction();
    underpass2Button->setDefaultAction(chooseUnderpass2Act);
    connect(chooseUnderpass2Act, &QAction::triggered, this, &Window::chooseUnderpass2);
    underpass2Icon = new QIcon(":/graphics/graphics/underpassSet2.png");
    underpass2Button->setIcon(*underpass2Icon);
    elementBlock1->addWidget(underpass2Button, 2, 19);




}

void Window::createElementBlock2()
{
    elementBlock2 = new QGridLayout;
    elementBlock2->setContentsMargins(1, 1, 1, 1);
    elementBlock2->setHorizontalSpacing(1);
    elementBlock2->setVerticalSpacing(1);

    switchTight1Button = new QToolButton();
    switchTight1Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight1Act = new QAction();
    switchTight1Button->setDefaultAction(chooseSwitchTight1Act);
    connect(chooseSwitchTight1Act, &QAction::triggered, this, &Window::chooseSwitchTight1);
    switchTight1Icon = new QIcon(":/graphics/graphics/switchTight1.png");
    switchTight1Button->setIcon(*switchTight1Icon);
    elementBlock2->addWidget(switchTight1Button, 0, 0);

    switchTight2Button = new QToolButton();
    switchTight2Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight2Act = new QAction();
    switchTight2Button->setDefaultAction(chooseSwitchTight2Act);
    connect(chooseSwitchTight2Act, &QAction::triggered, this, &Window::chooseSwitchTight2);
    switchTight2Icon = new QIcon(":/graphics/graphics/switchTight2.png");
    switchTight2Button->setIcon(*switchTight2Icon);
    elementBlock2->addWidget(switchTight2Button, 0, 1);

    switchTight3Button = new QToolButton();
    switchTight3Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight3Act = new QAction();
    switchTight3Button->setDefaultAction(chooseSwitchTight3Act);
    connect(chooseSwitchTight3Act, &QAction::triggered, this, &Window::chooseSwitchTight3);
    switchTight3Icon = new QIcon(":/graphics/graphics/switchTight3.png");
    switchTight3Button->setIcon(*switchTight3Icon);
    elementBlock2->addWidget(switchTight3Button, 0, 2);

    switchTight4Button = new QToolButton();
    switchTight4Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight4Act = new QAction();
    switchTight4Button->setDefaultAction(chooseSwitchTight4Act);
    connect(chooseSwitchTight4Act, &QAction::triggered, this, &Window::chooseSwitchTight4);
    switchTight4Icon = new QIcon(":/graphics/graphics/switchTight4.png");
    switchTight4Button->setIcon(*switchTight4Icon);
    elementBlock2->addWidget(switchTight4Button, 0, 3);

    switchTight5Button = new QToolButton();
    switchTight5Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight5Act = new QAction();
    switchTight5Button->setDefaultAction(chooseSwitchTight5Act);
    connect(chooseSwitchTight5Act, &QAction::triggered, this, &Window::chooseSwitchTight5);
    switchTight5Icon = new QIcon(":/graphics/graphics/switchTight5.png");
    switchTight5Button->setIcon(*switchTight5Icon);
    elementBlock2->addWidget(switchTight5Button, 0, 4);

    switchTight6Button = new QToolButton();
    switchTight6Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight6Act = new QAction();
    switchTight6Button->setDefaultAction(chooseSwitchTight6Act);
    connect(chooseSwitchTight6Act, &QAction::triggered, this, &Window::chooseSwitchTight6);
    switchTight6Icon = new QIcon(":/graphics/graphics/switchTight6.png");
    switchTight6Button->setIcon(*switchTight6Icon);
    elementBlock2->addWidget(switchTight6Button, 0, 5);

    switchTight7Button = new QToolButton();
    switchTight7Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight7Act = new QAction();
    switchTight7Button->setDefaultAction(chooseSwitchTight7Act);
    connect(chooseSwitchTight7Act, &QAction::triggered, this, &Window::chooseSwitchTight7);
    switchTight7Icon = new QIcon(":/graphics/graphics/switchTight7.png");
    switchTight7Button->setIcon(*switchTight7Icon);
    elementBlock2->addWidget(switchTight7Button, 0, 6);

    switchTight8Button = new QToolButton();
    switchTight8Button->setMaximumSize(QSize(32, 32));
    chooseSwitchTight8Act = new QAction();
    switchTight8Button->setDefaultAction(chooseSwitchTight8Act);
    connect(chooseSwitchTight8Act, &QAction::triggered, this, &Window::chooseSwitchTight8);
    switchTight8Icon = new QIcon(":/graphics/graphics/switchTight8.png");
    switchTight8Button->setIcon(*switchTight8Icon);
    elementBlock2->addWidget(switchTight8Button, 0, 7);

    switchSplit1Button = new QToolButton();
    switchSplit1Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit1Act = new QAction();
    switchSplit1Button->setDefaultAction(chooseSwitchSplit1Act);
    connect(chooseSwitchSplit1Act, &QAction::triggered, this, &Window::chooseSwitchSplit1);
    switchSplit1Icon = new QIcon(":/graphics/graphics/switchSplit1.png");
    switchSplit1Button->setIcon(*switchSplit1Icon);
    elementBlock2->addWidget(switchSplit1Button, 0, 8);

    switchSplit2Button = new QToolButton();
    switchSplit2Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit2Act = new QAction();
    switchSplit2Button->setDefaultAction(chooseSwitchSplit2Act);
    connect(chooseSwitchSplit2Act, &QAction::triggered, this, &Window::chooseSwitchSplit2);
    switchSplit2Icon = new QIcon(":/graphics/graphics/switchSplit2.png");
    switchSplit2Button->setIcon(*switchSplit2Icon);
    elementBlock2->addWidget(switchSplit2Button, 0, 9);

    switchSplit3Button = new QToolButton();
    switchSplit3Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit3Act = new QAction();
    switchSplit3Button->setDefaultAction(chooseSwitchSplit3Act);
    connect(chooseSwitchSplit3Act, &QAction::triggered, this, &Window::chooseSwitchSplit3);
    switchSplit3Icon = new QIcon(":/graphics/graphics/switchSplit3.png");
    switchSplit3Button->setIcon(*switchSplit3Icon);
    elementBlock2->addWidget(switchSplit3Button, 0, 10);

    switch1Button = new QToolButton();
    switch1Button->setMaximumSize(QSize(32, 32));
    chooseSwitch1Act = new QAction();
    switch1Button->setDefaultAction(chooseSwitch1Act);
    connect(chooseSwitch1Act, &QAction::triggered, this, &Window::chooseSwitch1);
    switch1Icon = new QIcon(":/graphics/graphics/switch1.png");
    switch1Button->setIcon(*switch1Icon);
    elementBlock2->addWidget(switch1Button, 1, 0);

    switch2Button = new QToolButton();
    switch2Button->setMaximumSize(QSize(32, 32));
    chooseSwitch2Act = new QAction();
    switch2Button->setDefaultAction(chooseSwitch2Act);
    connect(chooseSwitch2Act, &QAction::triggered, this, &Window::chooseSwitch2);
    switch2Icon = new QIcon(":/graphics/graphics/switch2.png");
    switch2Button->setIcon(*switch2Icon);
    elementBlock2->addWidget(switch2Button, 1, 1);

    switch3Button = new QToolButton();
    switch3Button->setMaximumSize(QSize(32, 32));
    chooseSwitch3Act = new QAction();
    switch3Button->setDefaultAction(chooseSwitch3Act);
    connect(chooseSwitch3Act, &QAction::triggered, this, &Window::chooseSwitch3);
    switch3Icon = new QIcon(":/graphics/graphics/switch3.png");
    switch3Button->setIcon(*switch3Icon);
    elementBlock2->addWidget(switch3Button, 1, 2);

    switch4Button = new QToolButton();
    switch4Button->setMaximumSize(QSize(32, 32));
    chooseSwitch4Act = new QAction();
    switch4Button->setDefaultAction(chooseSwitch4Act);
    connect(chooseSwitch4Act, &QAction::triggered, this, &Window::chooseSwitch4);
    switch4Icon = new QIcon(":/graphics/graphics/switch4.png");
    switch4Button->setIcon(*switch4Icon);
    elementBlock2->addWidget(switch4Button, 1, 3);

    switch5Button = new QToolButton();
    switch5Button->setMaximumSize(QSize(32, 32));
    chooseSwitch5Act = new QAction();
    switch5Button->setDefaultAction(chooseSwitch5Act);
    connect(chooseSwitch5Act, &QAction::triggered, this, &Window::chooseSwitch5);
    switch5Icon = new QIcon(":/graphics/graphics/switch5.png");
    switch5Button->setIcon(*switch5Icon);
    elementBlock2->addWidget(switch5Button, 1, 4);

    switch6Button = new QToolButton();
    switch6Button->setMaximumSize(QSize(32, 32));
    chooseSwitch6Act = new QAction();
    switch6Button->setDefaultAction(chooseSwitch6Act);
    connect(chooseSwitch6Act, &QAction::triggered, this, &Window::chooseSwitch6);
    switch6Icon = new QIcon(":/graphics/graphics/switch6.png");
    switch6Button->setIcon(*switch6Icon);
    elementBlock2->addWidget(switch6Button, 1, 5);

    switch7Button = new QToolButton();
    switch7Button->setMaximumSize(QSize(32, 32));
    chooseSwitch7Act = new QAction();
    switch7Button->setDefaultAction(chooseSwitch7Act);
    connect(chooseSwitch7Act, &QAction::triggered, this, &Window::chooseSwitch7);
    switch7Icon = new QIcon(":/graphics/graphics/switch7.png");
    switch7Button->setIcon(*switch7Icon);
    elementBlock2->addWidget(switch7Button, 1, 6);

    switch8Button = new QToolButton();
    switch8Button->setMaximumSize(QSize(32, 32));
    chooseSwitch8Act = new QAction();
    switch8Button->setDefaultAction(chooseSwitch8Act);
    connect(chooseSwitch8Act, &QAction::triggered, this, &Window::chooseSwitch8);
    switch8Icon = new QIcon(":/graphics/graphics/switch8.png");
    switch8Button->setIcon(*switch8Icon);
    elementBlock2->addWidget(switch8Button, 1, 7);

    switchSplit4Button = new QToolButton();
    switchSplit4Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit4Act = new QAction();
    switchSplit4Button->setDefaultAction(chooseSwitchSplit4Act);
    connect(chooseSwitchSplit4Act, &QAction::triggered, this, &Window::chooseSwitchSplit4);
    switchSplit4Icon = new QIcon(":/graphics/graphics/switchSplit4.png");
    switchSplit4Button->setIcon(*switchSplit4Icon);
    elementBlock2->addWidget(switchSplit4Button, 1, 8);

    switchSplit5Button = new QToolButton();
    switchSplit5Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit5Act = new QAction();
    switchSplit5Button->setDefaultAction(chooseSwitchSplit5Act);
    connect(chooseSwitchSplit5Act, &QAction::triggered, this, &Window::chooseSwitchSplit5);
    switchSplit5Icon = new QIcon(":/graphics/graphics/switchSplit5.png");
    switchSplit5Button->setIcon(*switchSplit5Icon);
    elementBlock2->addWidget(switchSplit5Button, 1, 9);

    switchSplit6Button = new QToolButton();
    switchSplit6Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit6Act = new QAction();
    switchSplit6Button->setDefaultAction(chooseSwitchSplit6Act);
    connect(chooseSwitchSplit6Act, &QAction::triggered, this, &Window::chooseSwitchSplit6);
    switchSplit6Icon = new QIcon(":/graphics/graphics/switchSplit6.png");
    switchSplit6Button->setIcon(*switchSplit6Icon);
    elementBlock2->addWidget(switchSplit6Button, 1, 10);

    switch9Button = new QToolButton();
    switch9Button->setMaximumSize(QSize(32, 32));
    chooseSwitch9Act = new QAction();
    switch9Button->setDefaultAction(chooseSwitch9Act);
    connect(chooseSwitch9Act, &QAction::triggered, this, &Window::chooseSwitch9);
    switch9Icon = new QIcon(":/graphics/graphics/switch9.png");
    switch9Button->setIcon(*switch9Icon);
    elementBlock2->addWidget(switch9Button, 2, 0);

    switch10Button = new QToolButton();
    switch10Button->setMaximumSize(QSize(32, 32));
    chooseSwitch10Act = new QAction();
    switch10Button->setDefaultAction(chooseSwitch10Act);
    connect(chooseSwitch10Act, &QAction::triggered, this, &Window::chooseSwitch10);
    switch10Icon = new QIcon(":/graphics/graphics/switch10.png");
    switch10Button->setIcon(*switch10Icon);
    elementBlock2->addWidget(switch10Button, 2, 1);

    switch11Button = new QToolButton();
    switch11Button->setMaximumSize(QSize(32, 32));
    chooseSwitch11Act = new QAction();
    switch11Button->setDefaultAction(chooseSwitch11Act);
    connect(chooseSwitch11Act, &QAction::triggered, this, &Window::chooseSwitch11);
    switch11Icon = new QIcon(":/graphics/graphics/switch11.png");
    switch11Button->setIcon(*switch11Icon);
    elementBlock2->addWidget(switch11Button, 2, 2);

    switch12Button = new QToolButton();
    switch12Button->setMaximumSize(QSize(32, 32));
    chooseSwitch12Act = new QAction();
    switch12Button->setDefaultAction(chooseSwitch12Act);
    connect(chooseSwitch12Act, &QAction::triggered, this, &Window::chooseSwitch12);
    switch12Icon = new QIcon(":/graphics/graphics/switch12.png");
    switch12Button->setIcon(*switch12Icon);
    elementBlock2->addWidget(switch12Button, 2, 3);

    switch13Button = new QToolButton();
    switch13Button->setMaximumSize(QSize(32, 32));
    chooseSwitch13Act = new QAction();
    switch13Button->setDefaultAction(chooseSwitch13Act);
    connect(chooseSwitch13Act, &QAction::triggered, this, &Window::chooseSwitch13);
    switch13Icon = new QIcon(":/graphics/graphics/switch13.png");
    switch13Button->setIcon(*switch13Icon);
    elementBlock2->addWidget(switch13Button, 2, 4);

    switch14Button = new QToolButton();
    switch14Button->setMaximumSize(QSize(32, 32));
    chooseSwitch14Act = new QAction();
    switch14Button->setDefaultAction(chooseSwitch14Act);
    connect(chooseSwitch14Act, &QAction::triggered, this, &Window::chooseSwitch14);
    switch14Icon = new QIcon(":/graphics/graphics/switch14.png");
    switch14Button->setIcon(*switch14Icon);
    elementBlock2->addWidget(switch14Button, 2, 5);

    switch15Button = new QToolButton();
    switch15Button->setMaximumSize(QSize(32, 32));
    chooseSwitch15Act = new QAction();
    switch15Button->setDefaultAction(chooseSwitch15Act);
    connect(chooseSwitch15Act, &QAction::triggered, this, &Window::chooseSwitch15);
    switch15Icon = new QIcon(":/graphics/graphics/switch15.png");
    switch15Button->setIcon(*switch15Icon);
    elementBlock2->addWidget(switch15Button, 2, 6);

    switch16Button = new QToolButton();
    switch16Button->setMaximumSize(QSize(32, 32));
    chooseSwitch16Act = new QAction();
    switch16Button->setDefaultAction(chooseSwitch16Act);
    connect(chooseSwitch16Act, &QAction::triggered, this, &Window::chooseSwitch16);
    switch16Icon = new QIcon(":/graphics/graphics/switch16.png");
    switch16Button->setIcon(*switch16Icon);
    elementBlock2->addWidget(switch16Button, 2, 7);

    switchSplit7Button = new QToolButton();
    switchSplit7Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit7Act = new QAction();
    switchSplit7Button->setDefaultAction(chooseSwitchSplit7Act);
    connect(chooseSwitchSplit7Act, &QAction::triggered, this, &Window::chooseSwitchSplit7);
    switchSplit7Icon = new QIcon(":/graphics/graphics/switchSplit7.png");
    switchSplit7Button->setIcon(*switchSplit7Icon);
    elementBlock2->addWidget(switchSplit7Button, 2, 8);

    switchSplit8Button = new QToolButton();
    switchSplit8Button->setMaximumSize(QSize(32, 32));
    chooseSwitchSplit8Act = new QAction();
    switchSplit8Button->setDefaultAction(chooseSwitchSplit8Act);
    connect(chooseSwitchSplit8Act, &QAction::triggered, this, &Window::chooseSwitchSplit8);
    switchSplit8Icon = new QIcon(":/graphics/graphics/switchSplit8.png");
    switchSplit8Button->setIcon(*switchSplit8Icon);
    elementBlock2->addWidget(switchSplit8Button, 2, 9);



}

void Window::createElementBlock3()
{
    elementBlock3 = new QGridLayout;
    elementBlock3->setContentsMargins(1, 1, 1, 1);
    elementBlock3->setHorizontalSpacing(1);
    elementBlock3->setVerticalSpacing(1);

    crossover1Button = new QToolButton();
    crossover1Button->setMaximumSize(QSize(32, 32));
    chooseCrossover1Act = new QAction();
    crossover1Button->setDefaultAction(chooseCrossover1Act);
    connect(chooseCrossover1Act, &QAction::triggered, this, &Window::chooseCrossover1);
    crossover1Icon = new QIcon(":/graphics/graphics/crossover1.png");
    crossover1Button->setIcon(*crossover1Icon);
    elementBlock3->addWidget(crossover1Button, 0, 0);

    crossover2Button = new QToolButton();
    crossover2Button->setMaximumSize(QSize(32, 32));
    chooseCrossover2Act = new QAction();
    crossover2Button->setDefaultAction(chooseCrossover2Act);
    connect(chooseCrossover2Act, &QAction::triggered, this, &Window::chooseCrossover2);
    crossover2Icon = new QIcon(":/graphics/graphics/crossover2.png");
    crossover2Button->setIcon(*crossover2Icon);
    elementBlock3->addWidget(crossover2Button, 0, 1);

    flyover1Button = new QToolButton();
    flyover1Button->setMaximumSize(QSize(32, 32));
    chooseFlyover1Act = new QAction();
    flyover1Button->setDefaultAction(chooseFlyover1Act);
    connect(chooseFlyover1Act, &QAction::triggered, this, &Window::chooseFlyover1);
    flyover1Icon = new QIcon(":/graphics/graphics/flyover1.png");
    flyover1Button->setIcon(*flyover1Icon);
    elementBlock3->addWidget(flyover1Button, 0, 2);

    flyover2Button = new QToolButton();
    flyover2Button->setMaximumSize(QSize(32, 32));
    chooseFlyover2Act = new QAction();
    flyover2Button->setDefaultAction(chooseFlyover2Act);
    connect(chooseFlyover2Act, &QAction::triggered, this, &Window::chooseFlyover2);
    flyover2Icon = new QIcon(":/graphics/graphics/flyover2.png");
    flyover2Button->setIcon(*flyover2Icon);
    elementBlock3->addWidget(flyover2Button, 0, 3);

    flyover3Button = new QToolButton();
    flyover3Button->setMaximumSize(QSize(32, 32));
    chooseFlyover3Act = new QAction();
    flyover3Button->setDefaultAction(chooseFlyover3Act);
    connect(chooseFlyover3Act, &QAction::triggered, this, &Window::chooseFlyover3);
    flyover3Icon = new QIcon(":/graphics/graphics/flyover3.png");
    flyover3Button->setIcon(*flyover3Icon);
    elementBlock3->addWidget(flyover3Button, 0, 4);

    flyover4Button = new QToolButton();
    flyover4Button->setMaximumSize(QSize(32, 32));
    chooseFlyover4Act = new QAction();
    flyover4Button->setDefaultAction(chooseFlyover4Act);
    connect(chooseFlyover4Act, &QAction::triggered, this, &Window::chooseFlyover4);
    flyover4Icon = new QIcon(":/graphics/graphics/flyover4.png");
    flyover4Button->setIcon(*flyover4Icon);
    elementBlock3->addWidget(flyover4Button, 0, 5);

    crossover3Button = new QToolButton();
    crossover3Button->setMaximumSize(QSize(32, 32));
    chooseCrossover3Act = new QAction();
    crossover3Button->setDefaultAction(chooseCrossover3Act);
    connect(chooseCrossover3Act, &QAction::triggered, this, &Window::chooseCrossover3);
    crossover3Icon = new QIcon(":/graphics/graphics/crossover3.png");
    crossover3Button->setIcon(*crossover3Icon);
    elementBlock3->addWidget(crossover3Button, 1, 0);

    crossover4Button = new QToolButton();
    crossover4Button->setMaximumSize(QSize(32, 32));
    chooseCrossover4Act = new QAction();
    crossover4Button->setDefaultAction(chooseCrossover4Act);
    connect(chooseCrossover4Act, &QAction::triggered, this, &Window::chooseCrossover4);
    crossover4Icon = new QIcon(":/graphics/graphics/crossover4.png");
    crossover4Button->setIcon(*crossover4Icon);
    elementBlock3->addWidget(crossover4Button, 1, 1);

    flyover5Button = new QToolButton();
    flyover5Button->setMaximumSize(QSize(32, 32));
    chooseFlyover5Act = new QAction();
    flyover5Button->setDefaultAction(chooseFlyover5Act);
    connect(chooseFlyover5Act, &QAction::triggered, this, &Window::chooseFlyover5);
    flyover5Icon = new QIcon(":/graphics/graphics/flyover5.png");
    flyover5Button->setIcon(*flyover5Icon);
    elementBlock3->addWidget(flyover5Button, 1, 2);

    flyover6Button = new QToolButton();
    flyover6Button->setMaximumSize(QSize(32, 32));
    chooseFlyover6Act = new QAction();
    flyover6Button->setDefaultAction(chooseFlyover6Act);
    connect(chooseFlyover6Act, &QAction::triggered, this, &Window::chooseFlyover6);
    flyover6Icon = new QIcon(":/graphics/graphics/flyover6.png");
    flyover6Button->setIcon(*flyover6Icon);
    elementBlock3->addWidget(flyover6Button, 1, 3);

    flyover7Button = new QToolButton();
    flyover7Button->setMaximumSize(QSize(32, 32));
    chooseFlyover7Act = new QAction();
    flyover7Button->setDefaultAction(chooseFlyover7Act);
    connect(chooseFlyover7Act, &QAction::triggered, this, &Window::chooseFlyover7);
    flyover7Icon = new QIcon(":/graphics/graphics/flyover7.png");
    flyover7Button->setIcon(*flyover7Icon);
    elementBlock3->addWidget(flyover7Button, 1, 4);

    flyover8Button = new QToolButton();
    flyover8Button->setMaximumSize(QSize(32, 32));
    chooseFlyover8Act = new QAction();
    flyover8Button->setDefaultAction(chooseFlyover8Act);
    connect(chooseFlyover8Act, &QAction::triggered, this, &Window::chooseFlyover8);
    flyover8Icon = new QIcon(":/graphics/graphics/flyover8.png");
    flyover8Button->setIcon(*flyover8Icon);
    elementBlock3->addWidget(flyover8Button, 1, 5);

    crossover5Button = new QToolButton();
    crossover5Button->setMaximumSize(QSize(32, 32));
    chooseCrossover5Act = new QAction();
    crossover5Button->setDefaultAction(chooseCrossover5Act);
    connect(chooseCrossover5Act, &QAction::triggered, this, &Window::chooseCrossover5);
    crossover5Icon = new QIcon(":/graphics/graphics/crossover5.png");
    crossover5Button->setIcon(*crossover5Icon);
    elementBlock3->addWidget(crossover5Button, 2, 0);

    crossover6Button = new QToolButton();
    crossover6Button->setMaximumSize(QSize(32, 32));
    chooseCrossover6Act = new QAction();
    crossover6Button->setDefaultAction(chooseCrossover6Act);
    connect(chooseCrossover6Act, &QAction::triggered, this, &Window::chooseCrossover6);
    crossover6Icon = new QIcon(":/graphics/graphics/crossover6.png");
    crossover6Button->setIcon(*crossover6Icon);
    elementBlock3->addWidget(crossover6Button, 2, 1);

    flyover9Button = new QToolButton();
    flyover9Button->setMaximumSize(QSize(32, 32));
    chooseFlyover9Act = new QAction();
    flyover9Button->setDefaultAction(chooseFlyover9Act);
    connect(chooseFlyover9Act, &QAction::triggered, this, &Window::chooseFlyover9);
    flyover9Icon = new QIcon(":/graphics/graphics/flyover9.png");
    flyover9Button->setIcon(*flyover9Icon);
    elementBlock3->addWidget(flyover9Button, 2, 2);

    flyover10Button = new QToolButton();
    flyover10Button->setMaximumSize(QSize(32, 32));
    chooseFlyover10Act = new QAction();
    flyover10Button->setDefaultAction(chooseFlyover10Act);
    connect(chooseFlyover10Act, &QAction::triggered, this, &Window::chooseFlyover10);
    flyover10Icon = new QIcon(":/graphics/graphics/flyover10.png");
    flyover10Button->setIcon(*flyover10Icon);
    elementBlock3->addWidget(flyover10Button, 2, 3);

    flyover11Button = new QToolButton();
    flyover11Button->setMaximumSize(QSize(32, 32));
    chooseFlyover11Act = new QAction();
    flyover11Button->setDefaultAction(chooseFlyover11Act);
    connect(chooseFlyover11Act, &QAction::triggered, this, &Window::chooseFlyover11);
    flyover11Icon = new QIcon(":/graphics/graphics/flyover11.png");
    flyover11Button->setIcon(*flyover11Icon);
    elementBlock3->addWidget(flyover11Button, 2, 4);

    flyover12Button = new QToolButton();
    flyover12Button->setMaximumSize(QSize(32, 32));
    chooseFlyover12Act = new QAction();
    flyover12Button->setDefaultAction(chooseFlyover12Act);
    connect(chooseFlyover12Act, &QAction::triggered, this, &Window::chooseFlyover12);
    flyover12Icon = new QIcon(":/graphics/graphics/flyover12.png");
    flyover12Button->setIcon(*flyover12Icon);
    elementBlock3->addWidget(flyover12Button, 2, 5);

}

void Window::createElementBlock4()
{
    elementBlock4 = new QGridLayout;
    elementBlock4->setContentsMargins(1, 1, 1, 1);
    elementBlock4->setHorizontalSpacing(1);
    elementBlock4->setVerticalSpacing(1);

    namedLocationButton = new QToolButton();
    namedLocationButton->setMaximumSize(QSize(32, 32));
    chooseNamedLocationAct = new QAction();
    namedLocationButton->setDefaultAction(chooseNamedLocationAct);
    connect(chooseNamedLocationAct, &QAction::triggered, this, &Window::chooseNamedLocation);
    namedLocationIcon = new QIcon(":/graphics/graphics/namedLocationSet.png");
    namedLocationButton->setIcon(*namedLocationIcon);
    elementBlock4->addWidget(namedLocationButton, 0, 0);

    concourseButton = new QToolButton();
    concourseButton->setMaximumSize(QSize(32, 32));
    chooseConcourseAct = new QAction();
    concourseButton->setDefaultAction(chooseConcourseAct);
    connect(chooseConcourseAct, &QAction::triggered, this, &Window::chooseConcourse);
    concourseIcon = new QIcon(":/graphics/graphics/concourseSet.png");
    concourseButton->setIcon(*concourseIcon);
    elementBlock4->addWidget(concourseButton, 0, 1);

    platformUpButton = new QToolButton();
    platformUpButton->setMaximumSize(QSize(32, 32));
    choosePlatformUpAct = new QAction();
    platformUpButton->setDefaultAction(choosePlatformUpAct);
    connect(choosePlatformUpAct, &QAction::triggered, this, &Window::choosePlatformUp);
    platformUpIcon = new QIcon(":/graphics/graphics/platformUpSet.png");
    platformUpButton->setIcon(*platformUpIcon);
    elementBlock4->addWidget(platformUpButton, 1, 0);

    platformDownButton = new QToolButton();
    platformDownButton->setMaximumSize(QSize(32, 32));
    choosePlatformDownAct = new QAction();
    platformDownButton->setDefaultAction(choosePlatformDownAct);
    connect(choosePlatformDownAct, &QAction::triggered, this, &Window::choosePlatformDown);
    platformDownIcon = new QIcon(":/graphics/graphics/platformDownSet.png");
    platformDownButton->setIcon(*platformDownIcon);
    elementBlock4->addWidget(platformDownButton, 1, 1);

    platformLeftButton = new QToolButton();
    platformLeftButton->setMaximumSize(QSize(32, 32));
    choosePlatformLeftAct = new QAction();
    platformLeftButton->setDefaultAction(choosePlatformLeftAct);
    connect(choosePlatformLeftAct, &QAction::triggered, this, &Window::choosePlatformLeft);
    platformLeftIcon = new QIcon(":/graphics/graphics/platformLeftSet.png");
    platformLeftButton->setIcon(*platformLeftIcon);
    elementBlock4->addWidget(platformLeftButton, 2, 0);

    platformRightButton = new QToolButton();
    platformRightButton->setMaximumSize(QSize(32, 32));
    choosePlatformRightAct = new QAction();
    platformRightButton->setDefaultAction(choosePlatformRightAct);
    connect(choosePlatformRightAct, &QAction::triggered, this, &Window::choosePlatformRight);
    platformRightIcon = new QIcon(":/graphics/graphics/platformRightSet.png");
    platformRightButton->setIcon(*platformRightIcon);
    elementBlock4->addWidget(platformRightButton, 2, 1);
}

void Window::createElementBlock5()
{
    elementBlock5 = new QGridLayout;
    elementBlock5->setContentsMargins(1, 1, 1, 1);
    elementBlock5->setHorizontalSpacing(1);
    elementBlock5->setVerticalSpacing(1);


    parapet1Button = new QToolButton();
    parapet1Button->setMaximumSize(QSize(32, 32));
    chooseParapet1Act = new QAction();
    parapet1Button->setDefaultAction(chooseParapet1Act);
    connect(chooseParapet1Act, &QAction::triggered, this, &Window::chooseParapet1);
    parapet1Icon = new QIcon(":/graphics/graphics/parapet1.png");
    parapet1Button->setIcon(*parapet1Icon);
    elementBlock5->addWidget(parapet1Button, 0, 0);

    parapet2Button = new QToolButton();
    parapet2Button->setMaximumSize(QSize(32, 32));
    chooseParapet2Act = new QAction();
    parapet2Button->setDefaultAction(chooseParapet2Act);
    connect(chooseParapet2Act, &QAction::triggered, this, &Window::chooseParapet2);
    parapet2Icon = new QIcon(":/graphics/graphics/parapet2.png");
    parapet2Button->setIcon(*parapet2Icon);
    elementBlock5->addWidget(parapet2Button, 0, 1);

    parapet3Button = new QToolButton();
    parapet3Button->setMaximumSize(QSize(32, 32));
    chooseParapet3Act = new QAction();
    parapet3Button->setDefaultAction(chooseParapet3Act);
    connect(chooseParapet3Act, &QAction::triggered, this, &Window::chooseParapet3);
    parapet3Icon = new QIcon(":/graphics/graphics/parapet3.png");
    parapet3Button->setIcon(*parapet3Icon);
    elementBlock5->addWidget(parapet3Button, 0, 2);

    parapet4Button = new QToolButton();
    parapet4Button->setMaximumSize(QSize(32, 32));
    chooseParapet4Act = new QAction();
    parapet4Button->setDefaultAction(chooseParapet4Act);
    connect(chooseParapet4Act, &QAction::triggered, this, &Window::chooseParapet4);
    parapet4Icon = new QIcon(":/graphics/graphics/parapet4.png");
    parapet4Button->setIcon(*parapet4Icon);
    elementBlock5->addWidget(parapet4Button, 0, 3);

    parapet5Button = new QToolButton();
    parapet5Button->setMaximumSize(QSize(32, 32));
    chooseParapet5Act = new QAction();
    parapet5Button->setDefaultAction(chooseParapet5Act);
    connect(chooseParapet5Act, &QAction::triggered, this, &Window::chooseParapet5);
    parapet5Icon = new QIcon(":/graphics/graphics/parapet5.png");
    parapet5Button->setIcon(*parapet5Icon);
    elementBlock5->addWidget(parapet5Button, 0, 4);

    parapet6Button = new QToolButton();
    parapet6Button->setMaximumSize(QSize(32, 32));
    chooseParapet6Act = new QAction();
    parapet6Button->setDefaultAction(chooseParapet6Act);
    connect(chooseParapet6Act, &QAction::triggered, this, &Window::chooseParapet6);
    parapet6Icon = new QIcon(":/graphics/graphics/parapet6.png");
    parapet6Button->setIcon(*parapet6Icon);
    elementBlock5->addWidget(parapet6Button, 0, 5);

    parapet7Button = new QToolButton();
    parapet7Button->setMaximumSize(QSize(32, 32));
    chooseParapet7Act = new QAction();
    parapet7Button->setDefaultAction(chooseParapet7Act);
    connect(chooseParapet7Act, &QAction::triggered, this, &Window::chooseParapet7);
    parapet7Icon = new QIcon(":/graphics/graphics/parapet7.png");
    parapet7Button->setIcon(*parapet7Icon);
    elementBlock5->addWidget(parapet7Button, 0, 6);

    parapet8Button = new QToolButton();
    parapet8Button->setMaximumSize(QSize(32, 32));
    chooseParapet8Act = new QAction();
    parapet8Button->setDefaultAction(chooseParapet8Act);
    connect(chooseParapet8Act, &QAction::triggered, this, &Window::chooseParapet8);
    parapet8Icon = new QIcon(":/graphics/graphics/parapet8.png");
    parapet8Button->setIcon(*parapet8Icon);
    elementBlock5->addWidget(parapet8Button, 0, 7);

    parapet9Button = new QToolButton();
    parapet9Button->setMaximumSize(QSize(32, 32));
    chooseParapet9Act = new QAction();
    parapet9Button->setDefaultAction(chooseParapet9Act);
    connect(chooseParapet9Act, &QAction::triggered, this, &Window::chooseParapet9);
    parapet9Icon = new QIcon(":/graphics/graphics/parapet9.png");
    parapet9Button->setIcon(*parapet9Icon);
    elementBlock5->addWidget(parapet9Button, 0, 8);

    parapet10Button = new QToolButton();
    parapet10Button->setMaximumSize(QSize(32, 32));
    chooseParapet10Act = new QAction();
    parapet10Button->setDefaultAction(chooseParapet10Act);
    connect(chooseParapet10Act, &QAction::triggered, this, &Window::chooseParapet10);
    parapet10Icon = new QIcon(":/graphics/graphics/parapet10.png");
    parapet10Button->setIcon(*parapet10Icon);
    elementBlock5->addWidget(parapet10Button, 0, 9);

    parapet11Button = new QToolButton();
    parapet11Button->setMaximumSize(QSize(32, 32));
    chooseParapet11Act = new QAction();
    parapet11Button->setDefaultAction(chooseParapet11Act);
    connect(chooseParapet11Act, &QAction::triggered, this, &Window::chooseParapet11);
    parapet11Icon = new QIcon(":/graphics/graphics/parapet11.png");
    parapet11Button->setIcon(*parapet11Icon);
    elementBlock5->addWidget(parapet11Button, 1, 0);

    parapet12Button = new QToolButton();
    parapet12Button->setMaximumSize(QSize(32, 32));
    chooseParapet12Act = new QAction();
    parapet12Button->setDefaultAction(chooseParapet12Act);
    connect(chooseParapet12Act, &QAction::triggered, this, &Window::chooseParapet12);
    parapet12Icon = new QIcon(":/graphics/graphics/parapet12.png");
    parapet12Button->setIcon(*parapet12Icon);
    elementBlock5->addWidget(parapet12Button, 1, 1);

    parapet13Button = new QToolButton();
    parapet13Button->setMaximumSize(QSize(32, 32));
    chooseParapet13Act = new QAction();
    parapet13Button->setDefaultAction(chooseParapet13Act);
    connect(chooseParapet13Act, &QAction::triggered, this, &Window::chooseParapet13);
    parapet13Icon = new QIcon(":/graphics/graphics/parapet13.png");
    parapet13Button->setIcon(*parapet13Icon);
    elementBlock5->addWidget(parapet13Button, 1, 2);

    parapet14Button = new QToolButton();
    parapet14Button->setMaximumSize(QSize(32, 32));
    chooseParapet14Act = new QAction();
    parapet14Button->setDefaultAction(chooseParapet14Act);
    connect(chooseParapet14Act, &QAction::triggered, this, &Window::chooseParapet14);
    parapet14Icon = new QIcon(":/graphics/graphics/parapet14.png");
    parapet14Button->setIcon(*parapet14Icon);
    elementBlock5->addWidget(parapet14Button, 1, 3);

    parapet15Button = new QToolButton();
    parapet15Button->setMaximumSize(QSize(32, 32));
    chooseParapet15Act = new QAction();
    parapet15Button->setDefaultAction(chooseParapet15Act);
    connect(chooseParapet15Act, &QAction::triggered, this, &Window::chooseParapet15);
    parapet15Icon = new QIcon(":/graphics/graphics/parapet15.png");
    parapet15Button->setIcon(*parapet15Icon);
    elementBlock5->addWidget(parapet15Button, 1, 4);

    parapet16Button = new QToolButton();
    parapet16Button->setMaximumSize(QSize(32, 32));
    chooseParapet16Act = new QAction();
    parapet16Button->setDefaultAction(chooseParapet16Act);
    connect(chooseParapet16Act, &QAction::triggered, this, &Window::chooseParapet16);
    parapet16Icon = new QIcon(":/graphics/graphics/parapet16.png");
    parapet16Button->setIcon(*parapet16Icon);
    elementBlock5->addWidget(parapet16Button, 1, 5);

    parapet17Button = new QToolButton();
    parapet17Button->setMaximumSize(QSize(32, 32));
    chooseParapet17Act = new QAction();
    parapet17Button->setDefaultAction(chooseParapet17Act);
    connect(chooseParapet17Act, &QAction::triggered, this, &Window::chooseParapet17);
    parapet17Icon = new QIcon(":/graphics/graphics/parapet17.png");
    parapet17Button->setIcon(*parapet17Icon);
    elementBlock5->addWidget(parapet17Button, 1, 6);

    parapet18Button = new QToolButton();
    parapet18Button->setMaximumSize(QSize(32, 32));
    chooseParapet18Act = new QAction();
    parapet18Button->setDefaultAction(chooseParapet18Act);
    connect(chooseParapet18Act, &QAction::triggered, this, &Window::chooseParapet18);
    parapet18Icon = new QIcon(":/graphics/graphics/parapet18.png");
    parapet18Button->setIcon(*parapet18Icon);
    elementBlock5->addWidget(parapet18Button, 1, 7);

    parapet19Button = new QToolButton();
    parapet19Button->setMaximumSize(QSize(32, 32));
    chooseParapet19Act = new QAction();
    parapet19Button->setDefaultAction(chooseParapet19Act);
    connect(chooseParapet19Act, &QAction::triggered, this, &Window::chooseParapet19);
    parapet19Icon = new QIcon(":/graphics/graphics/parapet19.png");
    parapet19Button->setIcon(*parapet19Icon);
    elementBlock5->addWidget(parapet19Button, 1, 8);

    parapet20Button = new QToolButton();
    parapet20Button->setMaximumSize(QSize(32, 32));
    chooseParapet20Act = new QAction();
    parapet20Button->setDefaultAction(chooseParapet20Act);
    connect(chooseParapet20Act, &QAction::triggered, this, &Window::chooseParapet20);
    parapet20Icon = new QIcon(":/graphics/graphics/parapet20.png");
    parapet20Button->setIcon(*parapet20Icon);
    elementBlock5->addWidget(parapet20Button, 1, 9);

    parapet21Button = new QToolButton();
    parapet21Button->setMaximumSize(QSize(32, 32));
    chooseParapet21Act = new QAction();
    parapet21Button->setDefaultAction(chooseParapet21Act);
    connect(chooseParapet21Act, &QAction::triggered, this, &Window::chooseParapet21);
    parapet21Icon = new QIcon(":/graphics/graphics/parapet21.png");
    parapet21Button->setIcon(*parapet21Icon);
    elementBlock5->addWidget(parapet21Button, 2, 0);

    parapet22Button = new QToolButton();
    parapet22Button->setMaximumSize(QSize(32, 32));
    chooseParapet22Act = new QAction();
    parapet22Button->setDefaultAction(chooseParapet22Act);
    connect(chooseParapet22Act, &QAction::triggered, this, &Window::chooseParapet22);
    parapet22Icon = new QIcon(":/graphics/graphics/parapet22.png");
    parapet22Button->setIcon(*parapet22Icon);
    elementBlock5->addWidget(parapet22Button, 2, 1);

    parapet23Button = new QToolButton();
    parapet23Button->setMaximumSize(QSize(32, 32));
    chooseParapet23Act = new QAction();
    parapet23Button->setDefaultAction(chooseParapet23Act);
    connect(chooseParapet23Act, &QAction::triggered, this, &Window::chooseParapet23);
    parapet23Icon = new QIcon(":/graphics/graphics/parapet23.png");
    parapet23Button->setIcon(*parapet23Icon);
    elementBlock5->addWidget(parapet23Button, 2, 2);

    parapet24Button = new QToolButton();
    parapet24Button->setMaximumSize(QSize(32, 32));
    chooseParapet24Act = new QAction();
    parapet24Button->setDefaultAction(chooseParapet24Act);
    connect(chooseParapet24Act, &QAction::triggered, this, &Window::chooseParapet24);
    parapet24Icon = new QIcon(":/graphics/graphics/parapet24.png");
    parapet24Button->setIcon(*parapet24Icon);
    elementBlock5->addWidget(parapet24Button, 2, 3);

    parapet25Button = new QToolButton();
    parapet25Button->setMaximumSize(QSize(32, 32));
    chooseParapet25Act = new QAction();
    parapet25Button->setDefaultAction(chooseParapet25Act);
    connect(chooseParapet25Act, &QAction::triggered, this, &Window::chooseParapet25);
    parapet25Icon = new QIcon(":/graphics/graphics/parapet25.png");
    parapet25Button->setIcon(*parapet25Icon);
    elementBlock5->addWidget(parapet25Button, 2, 5);

    parapet26Button = new QToolButton();
    parapet26Button->setMaximumSize(QSize(32, 32));
    chooseParapet26Act = new QAction();
    parapet26Button->setDefaultAction(chooseParapet26Act);
    connect(chooseParapet26Act, &QAction::triggered, this, &Window::chooseParapet26);
    parapet26Icon = new QIcon(":/graphics/graphics/parapet26.png");
    parapet26Button->setIcon(*parapet26Icon);
    elementBlock5->addWidget(parapet26Button, 2, 6);

    parapet27Button = new QToolButton();
    parapet27Button->setMaximumSize(QSize(32, 32));
    chooseParapet27Act = new QAction();
    parapet27Button->setDefaultAction(chooseParapet27Act);
    connect(chooseParapet27Act, &QAction::triggered, this, &Window::chooseParapet27);
    parapet27Icon = new QIcon(":/graphics/graphics/parapet27.png");
    parapet27Button->setIcon(*parapet27Icon);
    elementBlock5->addWidget(parapet27Button, 2, 7);

    parapet28Button = new QToolButton();
    parapet28Button->setMaximumSize(QSize(32, 32));
    chooseParapet28Act = new QAction();
    parapet28Button->setDefaultAction(chooseParapet28Act);
    connect(chooseParapet28Act, &QAction::triggered, this, &Window::chooseParapet28);
    parapet28Icon = new QIcon(":/graphics/graphics/parapet28.png");
    parapet28Button->setIcon(*parapet28Icon);
    elementBlock5->addWidget(parapet28Button, 2, 8);

    levelCrossingButton = new QToolButton();
    levelCrossingButton->setMaximumSize(QSize(32, 32));
    chooseLevelCrossingAct = new QAction();
    levelCrossingButton->setDefaultAction(chooseLevelCrossingAct);
    connect(chooseLevelCrossingAct, &QAction::triggered, this, &Window::chooseLevelCrossing);
    levelCrossingIcon = new QIcon(":/graphics/graphics/levelCrossingIcon.png");
    levelCrossingButton->setIcon(*levelCrossingIcon);
    //levelCrossingButton->setAutoRaise(true);
    elementBlock5->addWidget(levelCrossingButton, 0, 11);
}


void Window::createSetTrackLengthSpeedMenu()
{
    setTrackLengthSpeedMenu = new QWidget;
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::green);
    setTrackLengthSpeedMenu->setAutoFillBackground(true);
    setTrackLengthSpeedMenu->setPalette(pal);
    setTrackLengthSpeedLayout1 = new QHBoxLayout;
    keyGraphicImage = new QLabel;
    keyImage = new QImage(":/icons/icons/keyGraphic.png");
    keyGraphicImage->setPixmap(QPixmap::fromImage(*keyImage));
    keyGraphicImage->setScaledContents(true);
    keyGraphicImage->setMaximumHeight(120);
    keyGraphicImage->setMaximumWidth(500);
    setTrackLengthSpeedLayout1->addWidget(keyGraphicImage);

    convertorGrid = new QGridLayout;
    milesLabel = new QLabel;
    milesLabel->setText(tr("Miles"));
    milesEntry = new QLineEdit;
    milesEntry->setMaximumWidth(100);
    yardsLabel = new QLabel;
    yardsLabel->setText(tr("Yards"));
    yardsEntry = new QLineEdit;
    yardsEntry->setMaximumWidth(100);
    metresLabel = new QLabel;
    metresLabel->setText(tr("Metres"));
    actualMetres = new QLineEdit;
    actualMetres->setMaximumWidth(150);
    actualMetres->setReadOnly(true);
    actualMetres->setDisabled(true);

    connect(milesEntry, &QLineEdit::textChanged, this, &Window::convertMilesYardMetres);
    connect(yardsEntry, &QLineEdit::textChanged, this, &Window::convertMilesYardMetres);

    convertorGrid->addWidget(milesLabel,0,0);
    convertorGrid->addWidget(milesEntry,1,0);
    convertorGrid->addWidget(yardsLabel,2,0);
    convertorGrid->addWidget(yardsEntry,3,0);
    convertorGrid->addWidget(metresLabel,1,1);
    convertorGrid->addWidget(actualMetres,2,1);


    speedLabel1 = new QLabel;
    speedLabel1->setText(tr("mph"));
    speedEntry1 = new QLineEdit;

    speedEntry1->setMaximumWidth(150);
    swapLabelButton = new QPushButton;
    swapLabelButton->setText(tr("Swap"));
    swapLabelButton->setMinimumWidth(30);
    swapLabelButton->setMaximumWidth(75);
    connect(swapLabelButton, SIGNAL (released()),this, SLOT (swapSpeedLabel()));

    speedLabel2 = new QLabel;
    speedLabel2->setText(tr("km/h"));
    speedResult = new QLineEdit;
    speedResult->setMaximumWidth(150);
    speedResult->setDisabled(true);
    connect(speedEntry1, &QLineEdit::textChanged, this, &Window::convertMPHKMH);

    convertorGrid->addWidget(speedLabel1,0,2);
    convertorGrid->addWidget(speedEntry1,1,2);
    convertorGrid->addWidget(speedLabel2,2,2);
    convertorGrid->addWidget(swapLabelButton,2,3);
    convertorGrid->addWidget(speedResult,3,2);
    convertorGrid->setVerticalSpacing(1);


    setTrackLengthSpeedLayout1->addLayout(convertorGrid);
    setTrackLengthSpeedLayout1->setAlignment(convertorGrid, Qt::AlignLeft);

    setSpeedLengthLayout = new QGridLayout;
    lengthLabel = new QLabel;
    speedLabel = new QLabel;
    lengthLabel->setText(tr("Length (metres)"));
    speedLabel->setText(tr("Speed Limit (km/h)"));
    newLengthEntry = new QLineEdit;
    newLengthEntry->setMaximumWidth(150);
    newSpeedEntry = new QLineEdit;
    newSpeedEntry->setMaximumWidth(150);
    restoreAllDefaultButton = new QPushButton;
    restoreAllDefaultButton->setText(tr("Restore ALL defaults?"));
    restoreSelectionButton = new QPushButton;
    restoreSelectionButton->setText(tr("Restore selection defaults?"));
    cancelSetLengthSpeedButton = new QPushButton;
    cancelSetLengthSpeedButton->setText(tr("Cancel"));
    confirmNewLengthSpeedButton = new QPushButton;
    confirmNewLengthSpeedButton->setText(tr("Ok?"));

    setSpeedLengthLayout->addWidget(lengthLabel,0,0);
    setSpeedLengthLayout->addWidget(speedLabel,1,0);
    setSpeedLengthLayout->addWidget(newLengthEntry,0,1);
    setSpeedLengthLayout->addWidget(newSpeedEntry,1,1);
    setSpeedLengthLayout->addWidget(restoreAllDefaultButton,0,2);
    setSpeedLengthLayout->addWidget(restoreSelectionButton,1,2);
    setSpeedLengthLayout->addWidget(cancelSetLengthSpeedButton,0,3);
    setSpeedLengthLayout->addWidget(confirmNewLengthSpeedButton,1,3);

    setTrackLengthSpeedLayout1->addLayout(setSpeedLengthLayout);
    //setTrackLengthSpeedLayout1->setAlignment(setSpeedLengthLayout, Qt::AlignLeft);


    setTrackLengthSpeedMenu->setLayout(setTrackLengthSpeedLayout1);

}


void Window::createRightMenu()
{
    rightMenu = new QWidget;
    rightMenuLayout = new QVBoxLayout;

    rightButton = new QToolButton();
    rightButton->setMaximumSize(QSize(32, 32));
    rightAct = new QAction();
    rightButton->setDefaultAction(rightAct);
    connect(rightAct, &QAction::triggered, this, &Window::moveRight);
    rightIcon = new QIcon(":/icons/icons/right.png");
    rightButton->setIcon(*rightIcon);
    rightMenuLayout->addWidget(rightButton);

    leftButton = new QToolButton();
    leftButton->setMaximumSize(QSize(32, 32));
    leftAct = new QAction();
    leftButton->setDefaultAction(leftAct);
    connect(leftAct, &QAction::triggered, this, &Window::moveLeft);
    leftIcon = new QIcon(":/icons/icons/left.png");
    leftButton->setIcon(*leftIcon);
    rightMenuLayout->addWidget(leftButton);

    upButton = new QToolButton();
    upButton->setMaximumSize(QSize(32, 32));
    upAct = new QAction();
    upButton->setDefaultAction(upAct);
    connect(upAct, &QAction::triggered, this, &Window::moveUp);
    upIcon = new QIcon(":/icons/icons/up.png");
    upButton->setIcon(*upIcon);
    rightMenuLayout->addWidget(upButton);

    downButton = new QToolButton();
    downButton->setMaximumSize(QSize(32, 32));
    downAct = new QAction();
    downButton->setDefaultAction(downAct);
    connect(downAct, &QAction::triggered, this, &Window::moveDown);
    downIcon = new QIcon(":/icons/icons/down.png");
    downButton->setIcon(*downIcon);
    rightMenuLayout->addWidget(downButton);

    rightMenu->setLayout(rightMenuLayout);

}
