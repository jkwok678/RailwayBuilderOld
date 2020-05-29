#include "window.h"

//Constructor
Window::Window()
{

    //Set default chosen Element to nothing.
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
	BorderLayout* layout = new BorderLayout;
	layout->addWidget(drawingSurface, BorderLayout::Center);
	layout->addWidget(menuBar, BorderLayout::North);
	layout->addWidget(overallMenu, BorderLayout::North);
	layout->addWidget(rightMenu, BorderLayout::East);

	setLayout(layout);


}



void Window::openRailway()
{

}

void Window::openBuildModifyMenu()
{

}

void Window::openElementMenu()
{

}

void Window::changeAspect()
{
	if (aspect == 4) {
		aspect = 3;
		drawingSurface->setAspect(aspect);
		aspectButton->setIcon(*aspect3Icon);
	}
	else if (aspect == 3) {
		aspect = 2;
		drawingSurface->setAspect(aspect);
		aspectButton->setIcon(*aspect2Icon);
	}
	else if (aspect == 2) {
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
	else if (aspect == 1) {
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
    createElementMenu();
	//allMenus->addWidget(trackMenu);
	//allMenus->show();
	//overallMenuLayout->addWidget(allMenus);
    overallMenuLayout->addWidget(elementMenu);

	overallMenu->setLayout(overallMenuLayout);
}

void Window::createBuildModifyMenu1()
{
    elementMenuButton = new QToolButton();
    elementMenuButton->setMaximumSize(QSize(32, 32));
    openElementMenuAct = new QAction();
    connect(openElementMenuAct, &QAction::triggered, this, &Window::openElementMenu);
	trackIcon = new QIcon(":/icons/icons/buildMenuIcon.png");
    elementMenuButton->setIcon(*trackIcon);
    buildModifyMenuLayout1->addWidget(elementMenuButton);

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

	pal.setColor(QPalette::Background, Qt::green);
    elementMenu->setAutoFillBackground(true);
    elementMenu->setPalette(pal);
    elementMenuLayout = new QHBoxLayout;
    createElementBlock1();
    createElementBlock2();
    createElementBlock3();
    createElementBlock4();

    //createElementBlock5();

    elementMenuLayout->addLayout(elementBlock1);
    elementMenuLayout->addLayout(elementBlock2);
    elementMenuLayout->addLayout(elementBlock3);
    elementMenuLayout->addLayout(elementBlock4);
    //elementMenuLayout->addLayout(elementBlock5);

    elementMenu->setLayout(elementMenuLayout);
    overallMenuLayout->addWidget(elementMenu);




}

void Window::chooseStraightH()
{
    if (windowChosen != ElementType::STRAIGHTH)
        windowChosen = ElementType::STRAIGHTH;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseStraightV()
{
	if (windowChosen != ElementType::STRAIGHTV)
		windowChosen = ElementType::STRAIGHTV;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectLeft()
{
	if (windowChosen != ElementType::DIRECTLEFT)
		windowChosen = ElementType::DIRECTLEFT;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectRight()
{
	if (windowChosen != ElementType::DIRECTRIGHT)
		windowChosen = ElementType::DIRECTRIGHT;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectUp()
{
	if (windowChosen != ElementType::DIRECTUP)
		windowChosen = ElementType::DIRECTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectDown()
{
	if (windowChosen != ElementType::DIRECTDOWN)
		windowChosen = ElementType::DIRECTDOWN;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseStraightLeftUp()
{
	if (windowChosen != ElementType::STRAIGHTLEFTUP)
		windowChosen = ElementType::STRAIGHTLEFTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseStraightRightUp()
{
	if (windowChosen != ElementType::STRIAGHTRIGHTUP)
		windowChosen = ElementType::STRIAGHTRIGHTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectLeftUp()
{
	if (windowChosen != ElementType::DIRECTLEFTUP)
		windowChosen = ElementType::DIRECTLEFTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectRightUp()
{
	if (windowChosen != ElementType::DIRECTRIGHTUP)
		windowChosen = ElementType::DIRECTRIGHTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectLeftDown()
{
	if (windowChosen != ElementType::DIRECTLEFTDOWN)
		windowChosen = ElementType::DIRECTLEFTDOWN;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseDirectRightDown()
{
	if (windowChosen != ElementType::DIRECTRIGHTDOWN)
		windowChosen = ElementType::DIRECTRIGHTDOWN;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve1()
{
	if (windowChosen != ElementType::TIGHTCURVE1)
		windowChosen = ElementType::TIGHTCURVE1;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve2()
{
	if (windowChosen != ElementType::TIGHTCURVE2)
		windowChosen = ElementType::TIGHTCURVE2;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve3()
{
	if (windowChosen != ElementType::TIGHTCURVE3)
		windowChosen = ElementType::TIGHTCURVE3;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseTightCurve4()
{
	if (windowChosen != ElementType::TIGHTCURVE4)
		windowChosen = ElementType::TIGHTCURVE4;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseCurve1()
{
	if (windowChosen != ElementType::CURVE1)
		windowChosen = ElementType::CURVE1;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseCurve2()
{
	if (windowChosen != ElementType::CURVE2)
		windowChosen = ElementType::CURVE2;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseCurve3()
{
	if (windowChosen != ElementType::CURVE3)
		windowChosen = ElementType::CURVE3;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseCurve4()
{
	if (windowChosen != ElementType::CURVE4)
		windowChosen = ElementType::CURVE4;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkLeft()
{
	if (windowChosen != ElementType::LINKLEFT)
		windowChosen = ElementType::LINKLEFT;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkRight()
{
	if (windowChosen != ElementType::LINKRIGHT)
		windowChosen = ElementType::LINKRIGHT;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkDown()
{
	if (windowChosen != ElementType::LINKDOWN)
		windowChosen = ElementType::LINKDOWN;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkUp()
{
	if (windowChosen != ElementType::LINKUP)
		windowChosen = ElementType::LINKUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkLeftUp()
{
	if (windowChosen != ElementType::LINKLEFTUP)
		windowChosen = ElementType::LINKLEFTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkRightUp()
{
	if (windowChosen != ElementType::LINKRIGHTUP)
		windowChosen = ElementType::LINKRIGHTUP;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkLeftDown()
{
	if (windowChosen != ElementType::LINKLEFTDOWN)
		windowChosen = ElementType::LINKLEFTDOWN;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseLinkRightDown()
{
	if (windowChosen != ElementType::LINKRIGHTDOWN)
		windowChosen = ElementType::LINKRIGHTDOWN;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseExitLeft()
{
	if (windowChosen != ElementType::EXITLEFT)
		windowChosen = ElementType::EXITLEFT;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitRight()
{
	if (windowChosen != ElementType::EXITRIGHT)
		windowChosen = ElementType::EXITRIGHT;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitDown()
{
	if (windowChosen != ElementType::EXITDOWN)
		windowChosen = ElementType::EXITDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitUp()
{
	if (windowChosen != ElementType::EXITUP)
		windowChosen = ElementType::EXITUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitLeftUp()
{
	if (windowChosen != ElementType::EXITLEFTUP)
		windowChosen = ElementType::EXITLEFTUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitRightUp()
{
	if (windowChosen != ElementType::EXITRIGHTUP)
		windowChosen = ElementType::EXITRIGHTUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitLeftDown()
{
	if (windowChosen != ElementType::EXITLEFTDOWN)
		windowChosen = ElementType::EXITLEFTDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseExitRightDown()
{
	if (windowChosen != ElementType::EXITRIGHTDOWN)
		windowChosen = ElementType::EXITRIGHTDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseCurve5()
{
	if (windowChosen != ElementType::CURVE5)
		windowChosen = ElementType::CURVE5;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseCurve6()
{
	if (windowChosen != ElementType::CURVE6)
		windowChosen = ElementType::CURVE6;
	else
		windowChosen = ElementType::NONE;
}

void Window::chooseCurve7()
{
	if (windowChosen != ElementType::CURVE7)
		windowChosen = ElementType::CURVE7;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseCurve8()
{
	if (windowChosen != ElementType::CURVE8)
		windowChosen = ElementType::CURVE8;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferLeft()
{
	if (windowChosen != ElementType::BUFFERLEFT)
		windowChosen = ElementType::BUFFERLEFT;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferRight()
{
	if (windowChosen != ElementType::BUFFERRIGHT)
		windowChosen = ElementType::BUFFERRIGHT;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferDown()
{
	if (windowChosen != ElementType::BUFFERDOWN)
		windowChosen = ElementType::BUFFERDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferUp()
{
	if (windowChosen != ElementType::BUFFERUP)
		windowChosen = ElementType::BUFFERUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferLeftUp()
{
	if (windowChosen != ElementType::BUFFERLEFTUP)
		windowChosen = ElementType::BUFFERLEFTUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferRightUp()
{
	if (windowChosen != ElementType::BUFFERRIGHTUP)
		windowChosen = ElementType::BUFFERRIGHTUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferLeftDown()
{
	if (windowChosen != ElementType::BUFFERLEFTDOWN)
		windowChosen = ElementType::BUFFERLEFTDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBufferRightDown()
{
	if (windowChosen != ElementType::BUFFERRIGHTDOWN)
		windowChosen = ElementType::BUFFERRIGHTDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalLeft()
{
	if (windowChosen != ElementType::SIGNALLEFT)
		windowChosen = ElementType::SIGNALLEFT;
	else
		windowChosen = ElementType::NONE;


}

void Window::chooseSignalRight()
{
	if (windowChosen != ElementType::SIGNALRIGHT)
		windowChosen = ElementType::SIGNALRIGHT;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalDown()
{
	if (windowChosen != ElementType::SIGNALDOWN)
		windowChosen = ElementType::SIGNALDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalUp()
{
	if (windowChosen != ElementType::SIGNALUP)
		windowChosen = ElementType::SIGNALUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalLeftUp()
{
	if (windowChosen != ElementType::SIGNALLEFTUP)
		windowChosen = ElementType::SIGNALLEFTUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalRightUp()
{
	if (windowChosen != ElementType::SIGNALRIGHTUP)
		windowChosen = ElementType::SIGNALRIGHTUP;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalLeftDown()
{
	if (windowChosen != ElementType::SIGNALLEFTDOWN)
		windowChosen = ElementType::SIGNALLEFTDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseSignalRightDown()
{
	if (windowChosen != ElementType::SIGNALRIGHTDOWN)
		windowChosen = ElementType::SIGNALRIGHTDOWN;
	else
		windowChosen = ElementType::NONE;

}

void Window::chooseBridge1()
{
    if (windowChosen != ElementType::BRIDGE1)
        windowChosen = ElementType::BRIDGE1;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseBridge2()
{
    if (windowChosen != ElementType::BRIDGE2)
        windowChosen = ElementType::BRIDGE2;
    else
        windowChosen = ElementType::NONE;


}

void Window::chooseUnderpass1()
{
    if (windowChosen != ElementType::UNDERPASS1)
    {
        windowChosen = ElementType::UNDERPASS1;
        std::cout <<"hi " <<std::flush;
    }
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseUnderpass2()
{
    if (windowChosen != ElementType::UNDERPASS2)
        windowChosen = ElementType::UNDERPASS2;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight1()
{
    if (windowChosen != ElementType::SWITCHTIGHT1)
        windowChosen = ElementType::SWITCHTIGHT1;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight2()
{
    if (windowChosen != ElementType::SWITCHTIGHT2)
        windowChosen = ElementType::SWITCHTIGHT2;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight3()
{
    if (windowChosen != ElementType::SWITCHTIGHT3)
        windowChosen = ElementType::SWITCHTIGHT3;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight4()
{
    if (windowChosen != ElementType::SWITCHTIGHT4)
        windowChosen = ElementType::SWITCHTIGHT4;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight5()
{
    if (windowChosen != ElementType::SWITCHTIGHT5)
        windowChosen = ElementType::SWITCHTIGHT5;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight6()
{
    if (windowChosen != ElementType::SWITCHTIGHT6)
        windowChosen = ElementType::SWITCHTIGHT6;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight7()
{
    if (windowChosen != ElementType::SWITCHTIGHT7)
        windowChosen = ElementType::SWITCHTIGHT7;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchTight8()
{
    if (windowChosen != ElementType::SWITCHTIGHT8)
        windowChosen = ElementType::SWITCHTIGHT8;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit1()
{
    if (windowChosen != ElementType::SWITCHSPLIT1)
        windowChosen = ElementType::SWITCHSPLIT1;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit2()
{
    if (windowChosen != ElementType::SWITCHSPLIT2)
        windowChosen = ElementType::SWITCHSPLIT2;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit3()
{
    if (windowChosen != ElementType::SWITCHSPLIT3)
        windowChosen = ElementType::SWITCHSPLIT3;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch1()
{
    if (windowChosen != ElementType::SWITCH1)
        windowChosen = ElementType::SWITCH1;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch2()
{
    if (windowChosen != ElementType::SWITCH2)
        windowChosen = ElementType::SWITCH2;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch3()
{
    if (windowChosen != ElementType::SWITCH3)
        windowChosen = ElementType::SWITCH3;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch4()
{
    if (windowChosen != ElementType::SWITCH4)
        windowChosen = ElementType::SWITCH4;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch5()
{
    if (windowChosen != ElementType::SWITCH5)
        windowChosen = ElementType::SWITCH5;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch6()
{
    if (windowChosen != ElementType::SWITCH6)
        windowChosen = ElementType::SWITCH6;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch7()
{
    if (windowChosen != ElementType::SWITCH7)
        windowChosen = ElementType::SWITCH7;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch8()
{
    if (windowChosen != ElementType::SWITCH8)
        windowChosen = ElementType::SWITCH8;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit4()
{
    if (windowChosen != ElementType::SWITCHSPLIT4)
        windowChosen = ElementType::SWITCHSPLIT4;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit5()
{
    if (windowChosen != ElementType::SWITCHSPLIT5)
        windowChosen = ElementType::SWITCHSPLIT5;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit6()
{
    if (windowChosen != ElementType::SWITCHSPLIT6)
        windowChosen = ElementType::SWITCHSPLIT6;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch9()
{
    if (windowChosen != ElementType::SWITCH9)
        windowChosen = ElementType::SWITCH9;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch10()
{
    if (windowChosen != ElementType::SWITCH10)
        windowChosen = ElementType::SWITCH10;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch11()
{
    if (windowChosen != ElementType::SWITCH11)
        windowChosen = ElementType::SWITCH11;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch12()
{
    if (windowChosen != ElementType::SWITCH12)
        windowChosen = ElementType::SWITCH12;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch13()
{
    if (windowChosen != ElementType::SWITCH13)
        windowChosen = ElementType::SWITCH13;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch14()
{
    if (windowChosen != ElementType::SWITCH14)
        windowChosen = ElementType::SWITCH14;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch15()
{
    if (windowChosen != ElementType::SWITCH15)
        windowChosen = ElementType::SWITCH15;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitch16()
{
    if (windowChosen != ElementType::SWITCH16)
        windowChosen = ElementType::SWITCH16;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit7()
{
    if (windowChosen != ElementType::SWITCHSPLIT7)
        windowChosen = ElementType::SWITCHSPLIT7;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseSwitchSplit8()
{
    if (windowChosen != ElementType::SWITCHSPLIT8)
        windowChosen = ElementType::SWITCHSPLIT8;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCrossover1()
{
    if (windowChosen != ElementType::CROSSOVER1)
        windowChosen = ElementType::CROSSOVER1;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCrossover2()
{
    if (windowChosen != ElementType::CROSSOVER2)
        windowChosen = ElementType::CROSSOVER2;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover1()
{
    if (windowChosen != ElementType::FLYOVER1)
        windowChosen = ElementType::FLYOVER1;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover2()
{
    if (windowChosen != ElementType::FLYOVER2)
        windowChosen = ElementType::FLYOVER2;
    else
        windowChosen = ElementType::NONE;
}

void Window::chooseFlyover3()
{
    if (windowChosen != ElementType::FLYOVER3)
        windowChosen = ElementType::FLYOVER3;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover4()
{
    if (windowChosen != ElementType::FLYOVER4)
        windowChosen = ElementType::FLYOVER4;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCrossover3()
{
    if (windowChosen != ElementType::CROSSOVER3)
        windowChosen = ElementType::CROSSOVER3;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCrossover4()
{
    if (windowChosen != ElementType::CROSSOVER4)
        windowChosen = ElementType::CROSSOVER4;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover5()
{
    if (windowChosen != ElementType::FLYOVER5)
        windowChosen = ElementType::FLYOVER5;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover6()
{
    if (windowChosen != ElementType::FLYOVER6)
        windowChosen = ElementType::FLYOVER6;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover7()
{
    if (windowChosen != ElementType::FLYOVER7)
        windowChosen = ElementType::FLYOVER7;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover8()
{
    if (windowChosen != ElementType::FLYOVER8)
        windowChosen = ElementType::FLYOVER8;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCrossover5()
{
    if (windowChosen != ElementType::CROSSOVER5)
        windowChosen = ElementType::CROSSOVER5;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseCrossover6()
{
    if (windowChosen != ElementType::CROSSOVER6)
        windowChosen = ElementType::CROSSOVER6;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover9()
{
    if (windowChosen != ElementType::FLYOVER9)
        windowChosen = ElementType::FLYOVER9;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover10()
{
    if (windowChosen != ElementType::FLYOVER10)
        windowChosen = ElementType::FLYOVER10;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover11()
{
    if (windowChosen != ElementType::FLYOVER11)
        windowChosen = ElementType::FLYOVER11;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseFlyover12()
{
    if (windowChosen != ElementType::FLYOVER12)
        windowChosen = ElementType::FLYOVER12;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseNamedLocation()
{
    if (windowChosen != ElementType::NAMEDLOCATION)
        windowChosen = ElementType::NAMEDLOCATION;
    else
        windowChosen = ElementType::NONE;

}

void Window::chooseConcourse()
{
    if (windowChosen != ElementType::CONCOURSE)
        windowChosen = ElementType::CONCOURSE;
    else
        windowChosen = ElementType::NONE;

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
    elementBlock4= new QGridLayout;
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
