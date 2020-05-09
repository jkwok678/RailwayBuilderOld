#include "window.h"

//Constructor
Window::Window()
{

    //Set default chosen track to nothing.
    windowChosen = ElementType::NONE;
    drawingSurface = new Canvas;
    drawingSurface->setElementType(windowChosen);
    aspect = 4;
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
    } else if (aspect==1) {
        aspect =4;
        aspectButton->setIcon(*aspect4Icon);
    }

}

void Window::moveRight()
{

}

void Window::moveLeft()
{

}

void Window::moveUp()
{

}

void Window::moveDown()
{

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
    connect(chooseDirectRightUpAct, &QAction::triggered, this, &Window::chooseDirectRightUp);
    directRightUpIcon = new QIcon(":/graphics/graphics/directRightUp.png");
    directRightUpButton->setIcon(*directRightUpIcon);
    trackBlock1->addWidget(directRightUpButton,0,8);

    directLeftUpButton = new QToolButton();
    directLeftUpButton->setMaximumSize(QSize(32,32));
    chooseDirectLeftUpAct = new QAction();
    connect(chooseDirectLeftUpAct, &QAction::triggered, this, &Window::chooseDirectLeftUp);
    directLeftUpIcon = new QIcon(":/graphics/graphics/directLeftUp.png");
    directLeftUpButton->setIcon(*directLeftUpIcon);
    trackBlock1->addWidget(directLeftUpButton,0,9);

    directLeftDownButton = new QToolButton();
    directLeftDownButton->setMaximumSize(QSize(32,32));
    chooseDirectLeftDownAct = new QAction();
    connect(chooseDirectLeftDownAct, &QAction::triggered, this, &Window::chooseDirectLeftDown);
    directLeftDownIcon = new QIcon(":/graphics/graphics/directLeftDown.png");
    directLeftDownButton->setIcon(*directLeftDownIcon);
    trackBlock1->addWidget(directLeftDownButton,0,10);

    directRightDownButton = new QToolButton();
    directRightDownButton->setMaximumSize(QSize(32,32));
    chooseDirectRightDownAct = new QAction();
    connect(chooseDirectRightDownAct, &QAction::triggered, this, &Window::chooseDirectRightDown);
    directRightDownIcon = new QIcon(":/graphics/graphics/directRightDown.png");
    directRightDownButton->setIcon(*directRightDownIcon);
    trackBlock1->addWidget(directRightDownButton,0,11);

    tightCurve1Button = new QToolButton();
    tightCurve1Button->setMaximumSize(QSize(32,32));
    chooseTightCurve1Act = new QAction();
    connect(chooseTightCurve1Act, &QAction::triggered, this, &Window::chooseTightCurve1);
    tightCurve1Icon = new QIcon(":/graphics/graphics/tightCurve1.png");
    tightCurve1Button->setIcon(*tightCurve1Icon);
    trackBlock1->addWidget(tightCurve1Button,0,12);

    tightCurve2Button = new QToolButton();
    tightCurve2Button->setMaximumSize(QSize(32,32));
    chooseTightCurve2Act = new QAction();
    connect(chooseTightCurve2Act, &QAction::triggered, this, &Window::chooseTightCurve2);
    tightCurve2Icon = new QIcon(":/graphics/graphics/tightCurve2.png");
    tightCurve2Button->setIcon(*tightCurve2Icon);
    trackBlock1->addWidget(tightCurve2Button,0,13);

    tightCurve3Button = new QToolButton();
    tightCurve3Button->setMaximumSize(QSize(32,32));
    chooseTightCurve3Act = new QAction();
    connect(chooseTightCurve3Act, &QAction::triggered, this, &Window::chooseTightCurve3);
    tightCurve3Icon = new QIcon(":/graphics/graphics/tightCurve3.png");
    tightCurve3Button->setIcon(*tightCurve3Icon);
    trackBlock1->addWidget(tightCurve3Button,0,14);

    tightcurve4Button = new QToolButton();
    tightcurve4Button->setMaximumSize(QSize(32,32));
    chooseTightcurve4Act = new QAction();
    connect(chooseTightcurve4Act, &QAction::triggered, this, &Window::chooseTightCurve4);
    tightcurve4Icon = new QIcon(":/graphics/graphics/tightcurve4.png");
    tightcurve4Button->setIcon(*tightcurve4Icon);
    trackBlock1->addWidget(tightcurve4Button,0,15);

    curve1Button = new QToolButton();
    curve1Button->setMaximumSize(QSize(32,32));
    chooseCurve1Act = new QAction();
    connect(chooseCurve1Act, &QAction::triggered, this, &Window::chooseCurve1);
    curve1Icon = new QIcon(":/graphics/graphics/curve1.png");
    curve1Button->setIcon(*curve1Icon);
    trackBlock1->addWidget(curve1Button,0,16);

    curve2Button = new QToolButton();
    curve2Button->setMaximumSize(QSize(32,32));
    chooseCurve2Act = new QAction();
    connect(chooseCurve2Act, &QAction::triggered, this, &Window::chooseCurve2);
    curve2Icon = new QIcon(":/graphics/graphics/curve2.png");
    curve2Button->setIcon(*curve2Icon);
    trackBlock1->addWidget(curve2Button,0,17);

    curve3Button = new QToolButton();
    curve3Button->setMaximumSize(QSize(32,32));
    chooseCurve3Act = new QAction();
    connect(chooseCurve3Act, &QAction::triggered, this, &Window::chooseCurve3);
    curve3Icon = new QIcon(":/graphics/graphics/curve3.png");
    curve3Button->setIcon(*curve3Icon);
    trackBlock1->addWidget(curve3Button,0,18);

    curve4Button = new QToolButton();
    curve4Button->setMaximumSize(QSize(32,32));
    chooseCurve4Act = new QAction();
    connect(chooseCurve4Act, &QAction::triggered, this, &Window::chooseCurve4);
    curve4Icon = new QIcon(":/graphics/graphics/curve4.png");
    curve4Button->setIcon(*curve4Icon);
    trackBlock1->addWidget(curve4Button,0,19);

    linkLeftButton = new QToolButton();
    linkLeftButton->setMaximumSize(QSize(32,32));
    chooseLinkLeftAct = new QAction();
    connect(chooseLinkLeftAct, &QAction::triggered, this, &Window::chooseLinkLeft);
    linkLeftIcon = new QIcon(":/graphics/graphics/linkLeftSet.png");
    linkLeftButton->setIcon(*linkLeftIcon);
    trackBlock1->addWidget(linkLeftButton,1,0);

    linkRightButton = new QToolButton();
    linkRightButton->setMaximumSize(QSize(32,32));
    chooseLinkRightAct = new QAction();
    connect(chooseLinkRightAct, &QAction::triggered, this, &Window::chooseLinkRight);
    linkRightIcon = new QIcon(":/graphics/graphics/linkRightSet.png");
    linkRightButton->setIcon(*linkRightIcon);
    trackBlock1->addWidget(linkRightButton,1,1);

    linkDownButton = new QToolButton();
    linkDownButton->setMaximumSize(QSize(32,32));
    chooseLinkDownAct = new QAction();
    connect(chooseLinkDownAct, &QAction::triggered, this, &Window::chooseLinkDown);
    linkDownIcon = new QIcon(":/graphics/graphics/linkDownSet.png");
    linkDownButton->setIcon(*linkDownIcon);
    trackBlock1->addWidget(linkDownButton,1,2);

    linkUpButton = new QToolButton();
    linkUpButton->setMaximumSize(QSize(32,32));
    chooseLinkUpAct = new QAction();
    connect(chooseLinkUpAct, &QAction::triggered, this, &Window::chooseLinkUp);
    linkUpIcon = new QIcon(":/graphics/graphics/linkUpSet.png");
    linkUpButton->setIcon(*linkUpIcon);
    trackBlock1->addWidget(linkUpButton,1,3);

    linkLeftUpButton = new QToolButton();
    linkLeftUpButton->setMaximumSize(QSize(32,32));
    chooseLinkLeftUpAct = new QAction();
    connect(chooseLinkLeftUpAct, &QAction::triggered, this, &Window::chooseLinkLeftUp);
    linkLeftUpIcon = new QIcon(":/graphics/graphics/linkLeftUpSet.png");
    linkLeftUpButton->setIcon(*linkLeftUpIcon);
    trackBlock1->addWidget(linkLeftUpButton,1,4);

    linkRightUpButton = new QToolButton();
    linkRightUpButton->setMaximumSize(QSize(32,32));
    chooseLinkRightUpAct = new QAction();
    connect(chooseLinkRightUpAct, &QAction::triggered, this, &Window::chooseLinkRightUp);
    linkRightUpIcon = new QIcon(":/graphics/graphics/linkRightUpSet.png");
    linkRightUpButton->setIcon(*linkRightUpIcon);
    trackBlock1->addWidget(linkRightUpButton,1,5);

    linkRightDownButton = new QToolButton();
    linkRightDownButton->setMaximumSize(QSize(32,32));
    chooseLinkRightDownAct = new QAction();
    connect(chooseLinkRightDownAct, &QAction::triggered, this, &Window::chooseLinkRightDown);
    linkRightDownIcon = new QIcon(":/graphics/graphics/linkRightDownSet.png");
    linkRightDownButton->setIcon(*linkRightDownIcon);
    trackBlock1->addWidget(linkRightDownButton,1,6);

    linkLeftDownButton = new QToolButton();
    linkLeftDownButton->setMaximumSize(QSize(32,32));
    chooseLinkLeftDownAct = new QAction();
    connect(chooseLinkLeftDownAct, &QAction::triggered, this, &Window::chooseLinkLeftDown);
    linkLeftDownIcon = new QIcon(":/graphics/graphics/linkLeftDownSet.png");
    linkLeftDownButton->setIcon(*linkLeftDownIcon);
    trackBlock1->addWidget(linkLeftDownButton,1,7);



}

void Window::createRightMenu()
{
    rightMenu = new QWidget;
    rightMenuLayout = new QVBoxLayout;
    rightButton = new QToolButton();
    rightButton->setMaximumSize(QSize(32,32));
    rightAct = new QAction();
    connect(rightAct, &QAction::triggered, this, &Window::moveRight);
    rightIcon = new QIcon(":/icons/icons/right.png");
    rightButton->setIcon(*rightIcon);
    rightMenuLayout->addWidget(rightButton);
    rightMenu->setLayout(rightMenuLayout);

}
