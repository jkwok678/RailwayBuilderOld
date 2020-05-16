#include "window.h"

//Constructor
Window::Window()
{

    //Set default chosen track to nothing.
    windowChosen = ElementType::NONE;
    drawingSurface = new Canvas;
    drawingSurface->setElementType(windowChosen);
    windowOffsetX = 0;
    windowOffsetY = 0;
    drawingSurface->setOffsetX(windowOffsetX);
    drawingSurface->setOffsetY(windowOffsetY);
    aspect = 4;
    drawingSurface->setAspect(aspect);
    createOverallMenu();
    createFileActions();
    createModeActions();
    createRightMenu();
    createMenuBar();
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(drawingSurface, BorderLayout::Center);
    layout->addWidget(menuBar,BorderLayout::North);
    layout->addWidget(overallMenu,BorderLayout::North);
    layout->addWidget(rightMenu,BorderLayout::East);

    setLayout(layout);


}



void Window::openRailway()
{

}

void Window::openBuildModifyMenu()
{

}

void Window::openTrackMenu()
{

}

void Window::changeAspect()
{
    if (aspect==4){
        aspect = 3;
        aspectButton->setIcon(*aspect3Icon);
    } else if (aspect==3){
        aspect = 2;
        aspectButton->setIcon(*aspect2Icon);
    } else if (aspect==2) {
        aspect = 1;
        aspectButton->setIcon(*aspectShuntIcon);
        signalLeftButton->setIcon(*shuntLeftIcon);
        signalRightButton->setIcon(*shuntRightIcon);
        signalDownButton->setIcon(*shuntDownIcon);
        signalUpButton->setIcon(*shuntUpIcon);
        signalLeftUpButton->setIcon(*shuntLeftUpIcon);
        signalRightUpButton->setIcon(*shuntRightUpIcon);
        signalLeftDownButton->setIcon(*shuntLeftDownIcon);
        signalRightDownButton->setIcon(*shuntRightDownIcon);
    } else if (aspect==1) {
        aspect =4;
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

void Window::moveRight()
{

    drawingSurface->setOffsetX(++windowOffsetX);
    drawingSurface->update();
    //std::cout << windowOffsetX <<std::flush;
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

void Window::createMenuBar()
{
    menuBar = new QMenuBar();
    fileMenu = new QMenu("File");
    modeMenu = new QMenu("Mode");
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(modeMenu);
    createFileMenu();
    createModeMenu();

}

void Window::createFileMenu()
{
    fileMenu->addAction(openRailwayAct);
}

void Window::createModeMenu()
{
    modeMenu->addAction(openBuildModifyAct);
}

void Window::createFileActions()
{
    openRailwayAct = new QAction(tr("&Open Railway"), this);
    openRailwayAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openRailwayAct->setStatusTip(tr("Open an existing railway"));
    connect(openRailwayAct, &QAction::triggered, this, &Window::openRailway);
}

void Window::createModeActions()
{
    openBuildModifyAct = new QAction(tr("&Build/Modify Menu"), this);
    openBuildModifyAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));

    connect(openBuildModifyAct, &QAction::triggered, this, &Window::openBuildModifyMenu);
    //openBuildModifyAct ->setShortcut()
}

void Window::createOverallMenu()
{
    overallMenu = new QWidget;
    QPalette pal = palette();

    pal.setColor(QPalette::Background, Qt::blue);
    overallMenu->setAutoFillBackground(true);
    overallMenu->setPalette(pal);

    overallMenuLayout = new QVBoxLayout;
    buildModifyMenuLayout1 = new QHBoxLayout;

    //Create top half of Menu.
    createBuildModifyMenu1();
    buildModifyMenu1 = new QWidget;
    QPalette pal2 = palette();

    pal2.setColor(QPalette::Background, Qt::red);
    buildModifyMenu1->setAutoFillBackground(true);
    buildModifyMenu1->setPalette(pal2);
    buildModifyMenu1->setLayout(buildModifyMenuLayout1);
    overallMenuLayout->addWidget(buildModifyMenu1);

    //Create second half of Menu.
    // allMenus = new QStackedWidget;
    createTrackMenu();
    //allMenus->addWidget(trackMenu);
    //allMenus->show();
    //overallMenuLayout->addWidget(allMenus);
    overallMenuLayout->addWidget(trackMenu);
    overallMenu->setLayout(overallMenuLayout);
}

void Window::createBuildModifyMenu1()
{
    trackMenuButton = new QToolButton();
    trackMenuButton->setMaximumSize(QSize(32,32));
    openTrackMenuAct = new QAction();
    connect(openTrackMenuAct, &QAction::triggered, this, &Window::openTrackMenu);
    trackIcon = new QIcon(":/icons/icons/buildMenuIcon.png");
    trackMenuButton->setIcon(*trackIcon);
    buildModifyMenuLayout1->addWidget(trackMenuButton);

    aspectButton = new QToolButton();
    aspectButton->setMaximumSize(QSize(32,32));
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

void Window::createTrackMenu()
{

    trackMenu = new QWidget;
    QPalette pal = palette();

    pal.setColor(QPalette::Background, Qt::green);
    trackMenu->setAutoFillBackground(true);
    trackMenu->setPalette(pal);
    trackMenuLayout = new QHBoxLayout;
    createTrackBlock1();
    trackMenuLayout->addLayout(trackBlock1);
    trackMenu->setLayout(trackMenuLayout);
    overallMenuLayout->addWidget(trackMenu);




}

void Window::chooseStraightH()
{
   if (windowChosen!=ElementType::STRAIGHTH)
        {
        windowChosen = ElementType::STRAIGHTH;

        }
   else
       windowChosen = ElementType::NONE;

}

void Window::chooseStraightV()
{
    if (windowChosen!=ElementType::STRAIGHTV)
        {
         windowChosen = ElementType::STRAIGHTV;

        }
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectLeft()
{
    if (windowChosen!=ElementType::DIRECTLEFT)
         windowChosen = ElementType::DIRECTLEFT;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectRight()
{
    if (windowChosen!=ElementType::DIRECTRIGHT)
         windowChosen = ElementType::DIRECTRIGHT;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectUp()
{
    if (windowChosen!=ElementType::DIRECTUP)
         windowChosen = ElementType::DIRECTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectDown()
{
    if (windowChosen!=ElementType::DIRECTDOWN)
         windowChosen = ElementType::DIRECTDOWN;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseStraightLeftUp()
{
    if (windowChosen!=ElementType::STRAIGHTLEFTUP)
         windowChosen = ElementType::STRAIGHTLEFTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseStraightRightUp()
{
    if (windowChosen!=ElementType::STRIAGHTRIGHTUP)
         windowChosen = ElementType::STRIAGHTRIGHTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectLeftUp()
{
    if (windowChosen!=ElementType::DIRECTLEFTUP)
         windowChosen = ElementType::DIRECTLEFTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectRightUp()
{
    if (windowChosen!=ElementType::DIRECTRIGHTUP)
         windowChosen = ElementType::DIRECTRIGHTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectLeftDown()
{
    if (windowChosen!=ElementType::DIRECTLEFTDOWN)
         windowChosen = ElementType::DIRECTLEFTDOWN;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseDirectRightDown()
{
    if (windowChosen!=ElementType::DIRECTRIGHTDOWN)
         windowChosen = ElementType::DIRECTRIGHTDOWN;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve1()
{
    if (windowChosen!=ElementType::TIGHTCURVE1)
         windowChosen = ElementType::TIGHTCURVE1;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve2()
{
    if (windowChosen!=ElementType::TIGHTCURVE2)
         windowChosen = ElementType::TIGHTCURVE2;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve3()
{
    if (windowChosen!=ElementType::TIGHTCURVE3)
         windowChosen = ElementType::TIGHTCURVE3;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve4()
{
    if (windowChosen!=ElementType::TIGHTCURVE4)
         windowChosen = ElementType::TIGHTCURVE4;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseCurve1()
{
    if (windowChosen!=ElementType::CURVE1)
         windowChosen = ElementType::CURVE1;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseCurve2()
{
    if (windowChosen!=ElementType::CURVE2)
         windowChosen = ElementType::CURVE2;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseCurve3()
{
    if (windowChosen!=ElementType::CURVE3)
         windowChosen = ElementType::CURVE3;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseCurve4()
{
    if (windowChosen!=ElementType::CURVE4)
         windowChosen = ElementType::CURVE4;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkLeft()
{
    if (windowChosen!=ElementType::LINKLEFT)
         windowChosen = ElementType::LINKLEFT;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkRight()
{
    if (windowChosen!=ElementType::LINKRIGHT)
         windowChosen = ElementType::LINKRIGHT;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkDown()
{
    if (windowChosen!=ElementType::LINKDOWN)
         windowChosen = ElementType::LINKDOWN;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkUp()
{
    if (windowChosen!=ElementType::LINKUP)
         windowChosen = ElementType::LINKUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkLeftUp()
{
    if (windowChosen!=ElementType::LINKLEFTUP)
         windowChosen = ElementType::LINKLEFTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkRightUp()
{
    if (windowChosen!=ElementType::LINKRIGHTUP)
         windowChosen = ElementType::LINKRIGHTUP;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkLeftDown()
{
    if (windowChosen!=ElementType::LINKLEFTDOWN)
         windowChosen = ElementType::LINKLEFTDOWN;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseLinkRightDown()
{
    if (windowChosen!=ElementType::LINKRIGHTDOWN)
         windowChosen = ElementType::LINKRIGHTDOWN;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseExitLeft()
{
    if (windowChosen!=ElementType::EXITLEFT)
         windowChosen = ElementType::EXITLEFT;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitRight()
{
    if (windowChosen!=ElementType::EXITRIGHT)
         windowChosen = ElementType::EXITRIGHT;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitDown()
{
    if (windowChosen!=ElementType::EXITDOWN)
         windowChosen = ElementType::EXITDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitUp()
{
    if (windowChosen!=ElementType::EXITUP)
         windowChosen = ElementType::EXITUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitLeftUp()
{
    if (windowChosen!=ElementType::EXITLEFTUP)
         windowChosen = ElementType::EXITLEFTUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitRightUp()
{
    if (windowChosen!=ElementType::EXITRIGHTUP)
         windowChosen = ElementType::EXITRIGHTUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitLeftDown()
{
    if (windowChosen!=ElementType::EXITLEFTDOWN)
         windowChosen = ElementType::EXITLEFTDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseExitRightDown()
{
    if (windowChosen!=ElementType::EXITRIGHTDOWN)
         windowChosen = ElementType::EXITRIGHTDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCurve5()
{
    if (windowChosen!=ElementType::CURVE5)
         windowChosen = ElementType::CURVE5;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCurve6()
{
    if (windowChosen!=ElementType::CURVE6)
         windowChosen = ElementType::CURVE6;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseCurve7()
{
    if (windowChosen!=ElementType::CURVE7)
         windowChosen = ElementType::CURVE7;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCurve8()
{
    if (windowChosen!=ElementType::CURVE8)
         windowChosen = ElementType::CURVE8;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferLeft()
{
    if (windowChosen!=ElementType::BUFFERLEFT)
         windowChosen = ElementType::BUFFERLEFT;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferRight()
{
    if (windowChosen!=ElementType::BUFFERRIGHT)
         windowChosen = ElementType::BUFFERRIGHT;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferDown()
{
    if (windowChosen!=ElementType::BUFFERDOWN)
         windowChosen = ElementType::BUFFERDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferUp()
{
    if (windowChosen!=ElementType::BUFFERUP)
         windowChosen = ElementType::BUFFERUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferLeftUp()
{
    if (windowChosen!=ElementType::BUFFERLEFTUP)
         windowChosen = ElementType::BUFFERLEFTUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferRightUp()
{
    if (windowChosen!=ElementType::BUFFERRIGHTUP)
         windowChosen = ElementType::BUFFERRIGHTUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferLeftDown()
{
    if (windowChosen!=ElementType::BUFFERLEFTDOWN)
         windowChosen = ElementType::BUFFERLEFTDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBufferRightDown()
{
    if (windowChosen!=ElementType::BUFFERRIGHTDOWN)
         windowChosen = ElementType::BUFFERRIGHTDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalLeft()
{
    if (windowChosen!=ElementType::SIGNALLEFT)
         windowChosen = ElementType::SIGNALLEFT;
    else
        windowChosen = ElementType::NONE;


}

void Window::chooseSignalRight()
{
    if (windowChosen!=ElementType::SIGNALRIGHT)
         windowChosen = ElementType::SIGNALRIGHT;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalDown()
{
    if (windowChosen!=ElementType::SIGNALDOWN)
         windowChosen = ElementType::SIGNALDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalUp()
{
    if (windowChosen!=ElementType::SIGNALUP)
         windowChosen = ElementType::SIGNALUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalLeftUp()
{
    if (windowChosen!=ElementType::SIGNALLEFTUP)
         windowChosen = ElementType::SIGNALLEFTUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalRightUp()
{
    if (windowChosen!=ElementType::SIGNALRIGHTUP)
         windowChosen = ElementType::SIGNALRIGHTUP;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalLeftDown()
{
    if (windowChosen!=ElementType::SIGNALLEFTDOWN)
         windowChosen = ElementType::SIGNALLEFTDOWN;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSignalRightDown()
{
    if (windowChosen!=ElementType::SIGNALRIGHTDOWN)
         windowChosen = ElementType::SIGNALRIGHTDOWN;
    else
        windowChosen = ElementType::NONE;

}





void Window::createTrackBlock1()
{
    trackBlock1 = new QGridLayout;
    trackBlock1->setContentsMargins(2,2,2,2);

    straightHButton = new QToolButton();
    straightHButton->setMaximumSize(QSize(32,32));
    chooseStraightHAct = new QAction();
    straightHButton->setDefaultAction(chooseStraightHAct);
    connect(chooseStraightHAct, &QAction::triggered, this, &Window::chooseStraightH);
    straightHIcon = new QIcon(":/graphics/graphics/straightH.png");
    straightHButton->setIcon(*straightHIcon);
    trackBlock1->addWidget(straightHButton,0,0);

    straightVButton = new QToolButton();
    straightVButton->setMaximumSize(QSize(32,32));
    chooseStraightVAct = new QAction();
    straightVButton->setDefaultAction(chooseStraightVAct);
    connect(chooseStraightVAct, &QAction::triggered, this, &Window::chooseStraightV);
    straightVIcon = new QIcon(":/graphics/graphics/straightV.png");
    straightVButton->setIcon(*straightVIcon);
    trackBlock1->addWidget(straightVButton,0,1);

    directLeftButton = new QToolButton();
    directLeftButton->setMaximumSize(QSize(32,32));
    chooseDirectLeftAct = new QAction();
    directLeftButton->setDefaultAction(chooseDirectLeftAct);
    connect(chooseDirectLeftAct, &QAction::triggered, this, &Window::chooseDirectLeft);
    directLeftIcon= new QIcon(":/graphics/graphics/directLeft.png");
    directLeftButton->setIcon(*directLeftIcon);
    trackBlock1->addWidget(directLeftButton,0,2);

    directRightButton = new QToolButton();
    directRightButton->setMaximumSize(QSize(32,32));
    chooseDirectRightAct = new QAction();
    directRightButton->setDefaultAction(chooseDirectRightAct);
    connect(chooseDirectRightAct, &QAction::triggered, this, &Window::chooseDirectRight);
    directRightIcon = new QIcon(":/graphics/graphics/directRight.png");
    directRightButton->setIcon(*directRightIcon);
    trackBlock1->addWidget(directRightButton,0,3);

    directUpButton = new QToolButton();
    directUpButton->setMaximumSize(QSize(32,32));
    chooseDirectUpAct = new QAction();
    directUpButton->setDefaultAction(chooseDirectUpAct);
    connect(chooseDirectUpAct, &QAction::triggered, this, &Window::chooseDirectUp);
    directUpIcon = new QIcon(":/graphics/graphics/directUp.png");
    directUpButton->setIcon(*directUpIcon);
    trackBlock1->addWidget(directUpButton,0,4);

    directDownButton = new QToolButton();
    directDownButton->setMaximumSize(QSize(32,32));
    chooseDirectDownAct = new QAction();
    directDownButton->setDefaultAction(chooseDirectDownAct);
    connect(chooseDirectDownAct, &QAction::triggered, this, &Window::chooseDirectDown);
    directDownIcon = new QIcon(":/graphics/graphics/directDown.png");
    directDownButton->setIcon(*directDownIcon);
    trackBlock1->addWidget(directDownButton,0,5);

    straightRightUpButton = new QToolButton();
    straightRightUpButton->setMaximumSize(QSize(32,32));
    chooseStraightRightUpAct = new QAction();
    straightRightUpButton->setDefaultAction(chooseStraightRightUpAct);
    connect(chooseStraightRightUpAct, &QAction::triggered, this, &Window::chooseStraightRightUp);
    straightRightUpIcon = new QIcon(":/graphics/graphics/straightRightUp.png");
    straightRightUpButton->setIcon(*straightRightUpIcon);
    trackBlock1->addWidget(straightRightUpButton,0,6);

    straightLeftUpButton = new QToolButton();
    straightLeftUpButton->setMaximumSize(QSize(32,32));
    chooseStraightLeftUpAct = new QAction();
    straightLeftUpButton->setDefaultAction(chooseStraightLeftUpAct);
    connect(chooseStraightLeftUpAct, &QAction::triggered, this, &Window::chooseStraightLeftUp);
    straightLeftUpIcon = new QIcon(":/graphics/graphics/straightLeftUp.png");
    straightLeftUpButton->setIcon(*straightLeftUpIcon);
    trackBlock1->addWidget(straightLeftUpButton,0,7);

    directRightUpButton = new QToolButton();
    directRightUpButton->setMaximumSize(QSize(32,32));
    chooseDirectRightUpAct = new QAction();
    directRightUpButton->setDefaultAction(chooseDirectRightUpAct);
    connect(chooseDirectRightUpAct, &QAction::triggered, this, &Window::chooseDirectRightUp);
    directRightUpIcon = new QIcon(":/graphics/graphics/directRightUp.png");
    directRightUpButton->setIcon(*directRightUpIcon);
    trackBlock1->addWidget(directRightUpButton,0,8);

    directLeftUpButton = new QToolButton();
    directLeftUpButton->setMaximumSize(QSize(32,32));
    chooseDirectLeftUpAct = new QAction();
    directLeftUpButton->setDefaultAction(chooseDirectLeftUpAct);
    connect(chooseDirectLeftUpAct, &QAction::triggered, this, &Window::chooseDirectLeftUp);
    directLeftUpIcon = new QIcon(":/graphics/graphics/directLeftUp.png");
    directLeftUpButton->setIcon(*directLeftUpIcon);
    trackBlock1->addWidget(directLeftUpButton,0,9);

    directLeftDownButton = new QToolButton();
    directLeftDownButton->setMaximumSize(QSize(32,32));
    chooseDirectLeftDownAct = new QAction();
    directLeftDownButton->setDefaultAction(chooseDirectLeftDownAct);
    connect(chooseDirectLeftDownAct, &QAction::triggered, this, &Window::chooseDirectLeftDown);
    directLeftDownIcon = new QIcon(":/graphics/graphics/directLeftDown.png");
    directLeftDownButton->setIcon(*directLeftDownIcon);
    trackBlock1->addWidget(directLeftDownButton,0,10);

    directRightDownButton = new QToolButton();
    directRightDownButton->setMaximumSize(QSize(32,32));
    chooseDirectRightDownAct = new QAction();
    directRightDownButton->setDefaultAction(chooseDirectRightDownAct);
    connect(chooseDirectRightDownAct, &QAction::triggered, this, &Window::chooseDirectRightDown);
    directRightDownIcon = new QIcon(":/graphics/graphics/directRightDown.png");
    directRightDownButton->setIcon(*directRightDownIcon);
    trackBlock1->addWidget(directRightDownButton,0,11);

    tightCurve1Button = new QToolButton();
    tightCurve1Button->setMaximumSize(QSize(32,32));
    chooseTightCurve1Act = new QAction();
    tightCurve1Button->setDefaultAction(chooseTightCurve1Act);
    connect(chooseTightCurve1Act, &QAction::triggered, this, &Window::chooseTightCurve1);
    tightCurve1Icon = new QIcon(":/graphics/graphics/tightCurve1.png");
    tightCurve1Button->setIcon(*tightCurve1Icon);
    trackBlock1->addWidget(tightCurve1Button,0,12);

    tightCurve2Button = new QToolButton();
    tightCurve2Button->setMaximumSize(QSize(32,32));
    chooseTightCurve2Act = new QAction();
    tightCurve2Button->setDefaultAction(chooseTightCurve2Act);
    connect(chooseTightCurve2Act, &QAction::triggered, this, &Window::chooseTightCurve2);
    tightCurve2Icon = new QIcon(":/graphics/graphics/tightCurve2.png");
    tightCurve2Button->setIcon(*tightCurve2Icon);
    trackBlock1->addWidget(tightCurve2Button,0,13);

    tightCurve3Button = new QToolButton();
    tightCurve3Button->setMaximumSize(QSize(32,32));
    chooseTightCurve3Act = new QAction();
    tightCurve3Button->setDefaultAction(chooseTightCurve3Act);
    connect(chooseTightCurve3Act, &QAction::triggered, this, &Window::chooseTightCurve3);
    tightCurve3Icon = new QIcon(":/graphics/graphics/tightCurve3.png");
    tightCurve3Button->setIcon(*tightCurve3Icon);
    trackBlock1->addWidget(tightCurve3Button,0,14);

    tightCurve4Button = new QToolButton();
    tightCurve4Button->setMaximumSize(QSize(32,32));
    chooseTightCurve4Act = new QAction();
    tightCurve4Button->setDefaultAction(chooseTightCurve4Act);
    connect(chooseTightCurve4Act, &QAction::triggered, this, &Window::chooseTightCurve4);
    tightCurve4Icon = new QIcon(":/graphics/graphics/tightCurve4.png");
    tightCurve4Button->setIcon(*tightCurve4Icon);
    trackBlock1->addWidget(tightCurve4Button,0,15);

    curve1Button = new QToolButton();
    curve1Button->setMaximumSize(QSize(32,32));
    chooseCurve1Act = new QAction();
    curve1Button->setDefaultAction(chooseCurve1Act);
    connect(chooseCurve1Act, &QAction::triggered, this, &Window::chooseCurve1);
    curve1Icon = new QIcon(":/graphics/graphics/curve1.png");
    curve1Button->setIcon(*curve1Icon);
    trackBlock1->addWidget(curve1Button,0,16);

    curve2Button = new QToolButton();
    curve2Button->setMaximumSize(QSize(32,32));
    chooseCurve2Act = new QAction();
    curve2Button->setDefaultAction(chooseCurve2Act);
    connect(chooseCurve2Act, &QAction::triggered, this, &Window::chooseCurve2);
    curve2Icon = new QIcon(":/graphics/graphics/curve2.png");
    curve2Button->setIcon(*curve2Icon);
    trackBlock1->addWidget(curve2Button,0,17);

    curve3Button = new QToolButton();
    curve3Button->setMaximumSize(QSize(32,32));
    chooseCurve3Act = new QAction();
    curve3Button->setDefaultAction(chooseCurve3Act);
    connect(chooseCurve3Act, &QAction::triggered, this, &Window::chooseCurve3);
    curve3Icon = new QIcon(":/graphics/graphics/curve3.png");
    curve3Button->setIcon(*curve3Icon);
    trackBlock1->addWidget(curve3Button,0,18);

    curve4Button = new QToolButton();
    curve4Button->setMaximumSize(QSize(32,32));
    chooseCurve4Act = new QAction();
    curve4Button->setDefaultAction(chooseCurve4Act);
    connect(chooseCurve4Act, &QAction::triggered, this, &Window::chooseCurve4);
    curve4Icon = new QIcon(":/graphics/graphics/curve4.png");
    curve4Button->setIcon(*curve4Icon);
    trackBlock1->addWidget(curve4Button,0,19);

    linkLeftButton = new QToolButton();
    linkLeftButton->setMaximumSize(QSize(32,32));
    chooseLinkLeftAct = new QAction();
    linkLeftButton->setDefaultAction(chooseLinkLeftAct);
    connect(chooseLinkLeftAct, &QAction::triggered, this, &Window::chooseLinkLeft);
    linkLeftIcon = new QIcon(":/graphics/graphics/linkLeftSet.png");
    linkLeftButton->setIcon(*linkLeftIcon);
    trackBlock1->addWidget(linkLeftButton,1,0);

    linkRightButton = new QToolButton();
    linkRightButton->setMaximumSize(QSize(32,32));
    chooseLinkRightAct = new QAction();
    linkRightButton->setDefaultAction(chooseLinkRightAct);
    connect(chooseLinkRightAct, &QAction::triggered, this, &Window::chooseLinkRight);
    linkRightIcon = new QIcon(":/graphics/graphics/linkRightSet.png");
    linkRightButton->setIcon(*linkRightIcon);
    trackBlock1->addWidget(linkRightButton,1,1);

    linkDownButton = new QToolButton();
    linkDownButton->setMaximumSize(QSize(32,32));
    chooseLinkDownAct = new QAction();
    linkDownButton->setDefaultAction(chooseLinkDownAct);
    connect(chooseLinkDownAct, &QAction::triggered, this, &Window::chooseLinkDown);
    linkDownIcon = new QIcon(":/graphics/graphics/linkDownSet.png");
    linkDownButton->setIcon(*linkDownIcon);
    trackBlock1->addWidget(linkDownButton,1,2);

    linkUpButton = new QToolButton();
    linkUpButton->setMaximumSize(QSize(32,32));
    chooseLinkUpAct = new QAction();
    linkUpButton->setDefaultAction(chooseLinkUpAct);
    connect(chooseLinkUpAct, &QAction::triggered, this, &Window::chooseLinkUp);
    linkUpIcon = new QIcon(":/graphics/graphics/linkUpSet.png");
    linkUpButton->setIcon(*linkUpIcon);
    trackBlock1->addWidget(linkUpButton,1,3);

    linkLeftUpButton = new QToolButton();
    linkLeftUpButton->setMaximumSize(QSize(32,32));
    chooseLinkLeftUpAct = new QAction();
    linkLeftUpButton->setDefaultAction(chooseLinkLeftUpAct);
    connect(chooseLinkLeftUpAct, &QAction::triggered, this, &Window::chooseLinkLeftUp);
    linkLeftUpIcon = new QIcon(":/graphics/graphics/linkLeftUpSet.png");
    linkLeftUpButton->setIcon(*linkLeftUpIcon);
    trackBlock1->addWidget(linkLeftUpButton,1,4);

    linkRightUpButton = new QToolButton();
    linkRightUpButton->setMaximumSize(QSize(32,32));
    chooseLinkRightUpAct = new QAction();
    linkRightUpButton->setDefaultAction(chooseLinkRightUpAct);
    connect(chooseLinkRightUpAct, &QAction::triggered, this, &Window::chooseLinkRightUp);
    linkRightUpIcon = new QIcon(":/graphics/graphics/linkRightUpSet.png");
    linkRightUpButton->setIcon(*linkRightUpIcon);
    trackBlock1->addWidget(linkRightUpButton,1,5);

    linkRightDownButton = new QToolButton();
    linkRightDownButton->setMaximumSize(QSize(32,32));
    chooseLinkRightDownAct = new QAction();
    linkRightDownButton->setDefaultAction(chooseLinkRightDownAct);
    connect(chooseLinkRightDownAct, &QAction::triggered, this, &Window::chooseLinkRightDown);
    linkRightDownIcon = new QIcon(":/graphics/graphics/linkRightDownSet.png");
    linkRightDownButton->setIcon(*linkRightDownIcon);
    trackBlock1->addWidget(linkRightDownButton,1,6);

    linkLeftDownButton = new QToolButton();
    linkLeftDownButton->setMaximumSize(QSize(32,32));
    chooseLinkLeftDownAct = new QAction();
    linkLeftDownButton->setDefaultAction(chooseLinkLeftDownAct);
    connect(chooseLinkLeftDownAct, &QAction::triggered, this, &Window::chooseLinkLeftDown);
    linkLeftDownIcon = new QIcon(":/graphics/graphics/linkLeftDownSet.png");
    linkLeftDownButton->setIcon(*linkLeftDownIcon);
    trackBlock1->addWidget(linkLeftDownButton,1,7);

    exitLeftButton = new QToolButton();
    exitLeftButton->setMaximumSize(QSize(32,32));
    chooseExitLeftAct = new QAction();
    exitLeftButton->setDefaultAction(chooseExitLeftAct);
    connect(chooseExitLeftAct, &QAction::triggered, this, &Window::chooseExitLeft);
    exitLeftIcon = new QIcon(":/graphics/graphics/exitLeft.png");
    exitLeftButton->setIcon(*exitLeftIcon);
    trackBlock1->addWidget(exitLeftButton,1,8);

    exitRightButton = new QToolButton();
    exitRightButton->setMaximumSize(QSize(32,32));
    chooseExitRightAct = new QAction();
    exitRightButton->setDefaultAction(chooseExitRightAct);
    connect(chooseExitRightAct, &QAction::triggered, this, &Window::chooseExitRight);
    exitRightIcon = new QIcon(":/graphics/graphics/exitRight.png");
    exitRightButton->setIcon(*exitRightIcon);
    trackBlock1->addWidget(exitRightButton,1,9);

    exitDownButton = new QToolButton();
    exitDownButton->setMaximumSize(QSize(32,32));
    chooseExitDownAct = new QAction();
    exitDownButton->setDefaultAction(chooseExitDownAct);
    connect(chooseExitDownAct, &QAction::triggered, this, &Window::chooseExitDown);
    exitDownIcon = new QIcon(":/graphics/graphics/exitDown.png");
    exitDownButton->setIcon(*exitDownIcon);
    trackBlock1->addWidget(exitDownButton,1,10);

    exitUpButton = new QToolButton();
    exitUpButton->setMaximumSize(QSize(32,32));
    chooseExitUpAct = new QAction();
    exitUpButton->setDefaultAction(chooseExitUpAct);
    connect(chooseExitUpAct, &QAction::triggered, this, &Window::chooseExitUp);
    exitUpIcon = new QIcon(":/graphics/graphics/exitUp.png");
    exitUpButton->setIcon(*exitUpIcon);
    trackBlock1->addWidget(exitUpButton,1,11);

    exitLeftUpButton = new QToolButton();
    exitLeftUpButton->setMaximumSize(QSize(32,32));
    chooseExitLeftUpAct = new QAction();
    exitLeftUpButton->setDefaultAction(chooseExitLeftUpAct);
    connect(chooseExitLeftUpAct, &QAction::triggered, this, &Window::chooseExitLeftUp);
    exitLeftUpIcon = new QIcon(":/graphics/graphics/exitLeftUp.png");
    exitLeftUpButton->setIcon(*exitLeftUpIcon);
    trackBlock1->addWidget(exitLeftUpButton,1,12);

    exitRightUpButton = new QToolButton();
    exitRightUpButton->setMaximumSize(QSize(32,32));
    chooseExitRightUpAct = new QAction();
    exitRightUpButton->setDefaultAction(chooseExitRightUpAct);
    connect(chooseExitRightUpAct, &QAction::triggered, this, &Window::chooseExitRightUp);
    exitRightUpIcon = new QIcon(":/graphics/graphics/exitRightUp.png");
    exitRightUpButton->setIcon(*exitRightUpIcon);
    trackBlock1->addWidget(exitRightUpButton,1,13);

    exitLeftDownButton = new QToolButton();
    exitLeftDownButton->setMaximumSize(QSize(32,32));
    chooseExitLeftDownAct = new QAction();
    exitLeftDownButton->setDefaultAction(chooseExitLeftDownAct);
    connect(chooseExitLeftDownAct, &QAction::triggered, this, &Window::chooseExitLeftDown);
    exitLeftDownIcon = new QIcon(":/graphics/graphics/exitLeftDown.png");
    exitLeftDownButton->setIcon(*exitLeftDownIcon);
    trackBlock1->addWidget(exitLeftDownButton,1,14);

    exitRightDownButton = new QToolButton();
    exitRightDownButton->setMaximumSize(QSize(32,32));
    chooseExitRightDownAct = new QAction();
    exitRightDownButton->setDefaultAction(chooseExitRightDownAct);
    connect(chooseExitRightDownAct, &QAction::triggered, this, &Window::chooseExitRightDown);
    exitRightDownIcon = new QIcon(":/graphics/graphics/exitRightDown.png");
    exitRightDownButton->setIcon(*exitRightDownIcon);
    trackBlock1->addWidget(exitRightDownButton,1,15);

    curve5Button = new QToolButton();
    curve5Button->setMaximumSize(QSize(32,32));
    chooseCurve5Act = new QAction();
    curve5Button->setDefaultAction(chooseCurve5Act);
    connect(chooseCurve5Act, &QAction::triggered, this, &Window::chooseCurve5);
    curve5Icon = new QIcon(":/graphics/graphics/curve5.png");
    curve5Button->setIcon(*curve5Icon);
    trackBlock1->addWidget(curve5Button,1,16);

    curve6Button = new QToolButton();
    curve6Button->setMaximumSize(QSize(32,32));
    chooseCurve6Act = new QAction();
    curve6Button->setDefaultAction(chooseCurve6Act);
    connect(chooseCurve6Act, &QAction::triggered, this, &Window::chooseCurve6);
    curve6Icon = new QIcon(":/graphics/graphics/curve6.png");
    curve6Button->setIcon(*curve6Icon);
    trackBlock1->addWidget(curve6Button,1,17);

    curve7Button = new QToolButton();
    curve7Button->setMaximumSize(QSize(32,32));
    chooseCurve7Act = new QAction();
    curve7Button->setDefaultAction(chooseCurve7Act);
    connect(chooseCurve7Act, &QAction::triggered, this, &Window::chooseCurve7);
    curve7Icon = new QIcon(":/graphics/graphics/curve7.png");
    curve7Button->setIcon(*curve7Icon);
    trackBlock1->addWidget(curve7Button,1,18);

    curve8Button = new QToolButton();
    curve8Button->setMaximumSize(QSize(32,32));
    chooseCurve8Act = new QAction();
    curve8Button->setDefaultAction(chooseCurve8Act);
    connect(chooseCurve8Act, &QAction::triggered, this, &Window::chooseCurve8);
    curve8Icon = new QIcon(":/graphics/graphics/curve8.png");
    curve8Button->setIcon(*curve8Icon);
    trackBlock1->addWidget(curve8Button,1,19);

    bufferLeftButton = new QToolButton();
    bufferLeftButton->setMaximumSize(QSize(32,32));
    chooseBufferLeftAct = new QAction();
    bufferLeftButton->setDefaultAction(chooseBufferLeftAct);
    connect(chooseBufferLeftAct, &QAction::triggered, this, &Window::chooseBufferLeft);
    bufferLeftIcon = new QIcon(":/graphics/graphics/bufferLeft.png");
    bufferLeftButton->setIcon(*bufferLeftIcon);
    trackBlock1->addWidget(bufferLeftButton,2,0);

    bufferRightButton = new QToolButton();
    bufferRightButton->setMaximumSize(QSize(32,32));
    chooseBufferRightAct = new QAction();
    bufferRightButton->setDefaultAction(chooseBufferRightAct);
    connect(chooseBufferRightAct, &QAction::triggered, this, &Window::chooseBufferRight);
    bufferRightIcon = new QIcon(":/graphics/graphics/bufferRight.png");
    bufferRightButton->setIcon(*bufferRightIcon);
    trackBlock1->addWidget(bufferRightButton,2,1);

    bufferDownButton = new QToolButton();
    bufferDownButton->setMaximumSize(QSize(32,32));
    chooseBufferDownAct = new QAction();
    bufferDownButton->setDefaultAction(chooseBufferDownAct);
    connect(chooseBufferDownAct, &QAction::triggered, this, &Window::chooseBufferDown);
    bufferDownIcon = new QIcon(":/graphics/graphics/bufferDown.png");
    bufferDownButton->setIcon(*bufferDownIcon);
    trackBlock1->addWidget(bufferDownButton,2,2);

    bufferUpButton = new QToolButton();
    bufferUpButton->setMaximumSize(QSize(32,32));
    chooseBufferUpAct = new QAction();
    bufferUpButton->setDefaultAction(chooseBufferUpAct);
    connect(chooseBufferUpAct, &QAction::triggered, this, &Window::chooseBufferUp);
    bufferUpIcon = new QIcon(":/graphics/graphics/bufferUp.png");
    bufferUpButton->setIcon(*bufferUpIcon);
    trackBlock1->addWidget(bufferUpButton,2,3);

    bufferLeftUpButton = new QToolButton();
    bufferLeftUpButton->setMaximumSize(QSize(32,32));
    chooseBufferLeftUpAct = new QAction();
    bufferLeftUpButton->setDefaultAction(chooseBufferLeftUpAct);
    connect(chooseBufferLeftUpAct, &QAction::triggered, this, &Window::chooseBufferLeftUp);
    bufferLeftUpIcon = new QIcon(":/graphics/graphics/bufferLeftUp.png");
    bufferLeftUpButton->setIcon(*bufferLeftUpIcon);
    trackBlock1->addWidget(bufferLeftUpButton,2,4);

    bufferRightUpButton = new QToolButton();
    bufferRightUpButton->setMaximumSize(QSize(32,32));
    chooseBufferRightUpAct = new QAction();
    bufferRightUpButton->setDefaultAction(chooseBufferRightUpAct);
    connect(chooseBufferRightUpAct, &QAction::triggered, this, &Window::chooseBufferRightUp);
    bufferRightUpIcon = new QIcon(":/graphics/graphics/bufferRightUp.png");
    bufferRightUpButton->setIcon(*bufferRightUpIcon);
    trackBlock1->addWidget(bufferRightUpButton,2,5);

    bufferLeftDownButton = new QToolButton();
    bufferLeftDownButton->setMaximumSize(QSize(32,32));
    chooseBufferLeftDownAct = new QAction();
    bufferLeftDownButton->setDefaultAction(chooseBufferLeftDownAct);
    connect(chooseBufferLeftDownAct, &QAction::triggered, this, &Window::chooseBufferLeftDown);
    bufferLeftDownIcon = new QIcon(":/graphics/graphics/bufferLeftDown.png");
    bufferLeftDownButton->setIcon(*bufferLeftDownIcon);
    trackBlock1->addWidget(bufferLeftDownButton,2,6);

    bufferRightDownButton = new QToolButton();
    bufferRightDownButton->setMaximumSize(QSize(32,32));
    chooseBufferRightDownAct = new QAction();
    bufferRightDownButton->setDefaultAction(chooseBufferRightDownAct);
    connect(chooseBufferRightDownAct, &QAction::triggered, this, &Window::chooseBufferRightDown);
    bufferRightDownIcon = new QIcon(":/graphics/graphics/bufferRightDown.png");
    bufferRightDownButton->setIcon(*bufferRightDownIcon);
    trackBlock1->addWidget(bufferRightDownButton,2,7);

    signalLeftButton = new QToolButton();
    signalLeftButton->setMaximumSize(QSize(32,32));
    chooseSignalLeftAct = new QAction();
    signalLeftButton->setDefaultAction(chooseSignalLeftAct);
    connect(chooseSignalLeftAct, &QAction::triggered, this, &Window::chooseSignalLeft);
    signalLeftIcon = new QIcon(":/graphics/graphics/signalLeft.png");
    shuntLeftIcon = new QIcon(":/graphics/graphics/shuntLeftRed.png");
    signalLeftButton->setIcon(*signalLeftIcon);
    trackBlock1->addWidget(signalLeftButton,2,8);

    signalRightButton = new QToolButton();
    signalRightButton->setMaximumSize(QSize(32,32));
    chooseSignalRightAct = new QAction();
    signalRightButton->setDefaultAction(chooseSignalRightAct);
    connect(chooseSignalRightAct, &QAction::triggered, this, &Window::chooseSignalRight);
    signalRightIcon = new QIcon(":/graphics/graphics/signalRight.png");
    shuntRightIcon = new QIcon(":/graphics/graphics/shuntRightRed.png");
    signalRightButton->setIcon(*signalRightIcon);
    trackBlock1->addWidget(signalRightButton,2,9);

    signalDownButton = new QToolButton();
    signalDownButton->setMaximumSize(QSize(32,32));
    chooseSignalDownAct = new QAction();
    signalDownButton->setDefaultAction(chooseSignalDownAct);
    connect(chooseSignalDownAct, &QAction::triggered, this, &Window::chooseSignalDown);
    signalDownIcon = new QIcon(":/graphics/graphics/signalDown.png");
    shuntDownIcon = new QIcon(":/graphics/graphics/shuntDownRed.png");
    signalDownButton->setIcon(*signalDownIcon);
    trackBlock1->addWidget(signalDownButton,2,10);

    signalUpButton = new QToolButton();
    signalUpButton->setMaximumSize(QSize(32,32));
    chooseSignalUpAct = new QAction();
    signalUpButton->setDefaultAction(chooseSignalUpAct);
    connect(chooseSignalUpAct, &QAction::triggered, this, &Window::chooseSignalUp);
    signalUpIcon = new QIcon(":/graphics/graphics/signalUp.png");
    shuntUpIcon = new QIcon(":/graphics/graphics/shuntUpRed.png");
    signalUpButton->setIcon(*signalUpIcon);
    trackBlock1->addWidget(signalUpButton,2,11);

    signalLeftUpButton = new QToolButton();
    signalLeftUpButton->setMaximumSize(QSize(32,32));
    chooseSignalLeftUpAct = new QAction();
    signalLeftUpButton->setDefaultAction(chooseSignalLeftUpAct);
    connect(chooseSignalLeftUpAct, &QAction::triggered, this, &Window::chooseSignalLeftUp);
    signalLeftUpIcon = new QIcon(":/graphics/graphics/signalLeftUp.png");
    shuntLeftUpIcon = new QIcon(":/graphics/graphics/shuntLeftUpRed.png");
    signalLeftUpButton->setIcon(*signalLeftUpIcon);
    trackBlock1->addWidget(signalLeftUpButton,2,12);

    signalRightUpButton = new QToolButton();
    signalRightUpButton->setMaximumSize(QSize(32,32));
    chooseSignalRightUpAct = new QAction();
    signalRightUpButton->setDefaultAction(chooseSignalRightUpAct);
    connect(chooseSignalRightUpAct, &QAction::triggered, this, &Window::chooseSignalRightUp);
    signalRightUpIcon = new QIcon(":/graphics/graphics/signalRightUp.png");
    shuntRightUpIcon = new QIcon(":/graphics/graphics/shuntRightUpRed.png");
    signalRightUpButton->setIcon(*signalRightUpIcon);
    trackBlock1->addWidget(signalRightUpButton,2,13);

    signalLeftDownButton = new QToolButton();
    signalLeftDownButton->setMaximumSize(QSize(32,32));
    chooseSignalLeftDownAct = new QAction();
    signalLeftDownButton->setDefaultAction(chooseSignalLeftDownAct);
    connect(chooseSignalLeftDownAct, &QAction::triggered, this, &Window::chooseSignalLeftDown);
    signalLeftDownIcon = new QIcon(":/graphics/graphics/signalLeftDown.png");
    shuntLeftDownIcon = new QIcon(":/graphics/graphics/shuntLeftDownRed.png");
    signalLeftDownButton->setIcon(*signalLeftDownIcon);
    trackBlock1->addWidget(signalLeftDownButton,2,14);

    signalRightDownButton = new QToolButton();
    signalRightDownButton->setMaximumSize(QSize(32,32));
    chooseSignalRightDownAct = new QAction();
    signalRightDownButton->setDefaultAction(chooseSignalRightDownAct);
    connect(chooseSignalRightDownAct, &QAction::triggered, this, &Window::chooseSignalRightDown);
    signalRightDownIcon = new QIcon(":/graphics/graphics/signalRightDown.png");
    shuntRightDownIcon = new QIcon(":/graphics/graphics/shuntRightDownRed.png");
    signalRightDownButton->setIcon(*signalRightDownIcon);
    trackBlock1->addWidget(signalRightDownButton,2,15);




}

void Window::createRightMenu()
{
    rightMenu = new QWidget;
    rightMenuLayout = new QVBoxLayout;

    rightButton = new QToolButton();
    rightButton->setMaximumSize(QSize(32,32));
    rightAct = new QAction();
    rightButton->setDefaultAction(rightAct);
    connect(rightAct, &QAction::triggered, this, &Window::moveRight);
    rightIcon = new QIcon(":/icons/icons/right.png");
    rightButton->setIcon(*rightIcon);
    rightMenuLayout->addWidget(rightButton);

    leftButton = new QToolButton();
    leftButton->setMaximumSize(QSize(32,32));
    leftAct = new QAction();
    leftButton->setDefaultAction(leftAct);
    connect(leftAct, &QAction::triggered, this, &Window::moveLeft);
    leftIcon = new QIcon(":/icons/icons/left.png");
    leftButton->setIcon(*leftIcon);
    rightMenuLayout->addWidget(leftButton);

    upButton = new QToolButton();
    upButton->setMaximumSize(QSize(32,32));
    upAct = new QAction();
    upButton->setDefaultAction(upAct);
    connect(upAct, &QAction::triggered, this, &Window::moveUp);
    upIcon = new QIcon(":/icons/icons/up.png");
    upButton->setIcon(*upIcon);
    rightMenuLayout->addWidget(upButton);

    downButton = new QToolButton();
    downButton->setMaximumSize(QSize(32,32));
    downAct = new QAction();
    downButton->setDefaultAction(downAct);
    connect(downAct, &QAction::triggered, this, &Window::moveDown);
    downIcon = new QIcon(":/icons/icons/down.png");
    downButton->setIcon(*downIcon);
    rightMenuLayout->addWidget(downButton);

    rightMenu->setLayout(rightMenuLayout);

}
