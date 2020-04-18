#include "window.h"

//Constructor
Window::Window()
{
    chosen = ElementType::NONE;
    Canvas *centralWidget = new Canvas;
    createOverallMenu();
    createFileActions();
    createModeActions();
    createMenuBar();
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(centralWidget, BorderLayout::Center);
    layout->addWidget(menuBar,BorderLayout::North);
    layout->addWidget(overallMenu,BorderLayout::North);

    setLayout(layout);


}

Map Window::getCurrentLayout()
{
    return currentLayout;
}

void Window::setCurrentLayout(Map newLayout)
{
    currentLayout = newLayout;
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
    overallMenuLayout = new QVBoxLayout;
    buildModifyMenu1 = new QHBoxLayout;
    //Create top half of Menu.
    createBuildModifyMenu1();
    overallMenuLayout->addLayout(buildModifyMenu1);
    //Create second half of Menu.
    allMenus = new QStackedWidget;
    createTrackMenu();
    allMenus->addWidget(trackMenu);
    allMenus->show();
    overallMenuLayout->addWidget(allMenus);
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
    buildModifyMenu1->addWidget(trackMenuButton);
}

void Window::createTrackMenu()
{

    trackMenu = new QWidget;
    trackMenuLayout = new QHBoxLayout;
    createTrackBlock1();
    trackMenuLayout->addLayout(trackBlock1);
    trackMenu->setLayout(trackMenuLayout);
    overallMenuLayout->addWidget(trackMenu);




}

void Window::chooseStraightH()
{

}

void Window::chooseStraightV()
{

}

void Window::createTrackBlock1()
{
    trackBlock1 = new QGridLayout;
    straightHButton = new QToolButton();
    straightHButton->setMaximumSize(QSize(32,32));
    chooseStraightHAct = new QAction();
    connect(chooseStraightHAct, &QAction::triggered, this, &Window::chooseStraightH);
    straightHIcon = new QIcon(":/graphics/graphics/straightH.png");
    straightHButton->setIcon(*straightHIcon);
    trackBlock1->addWidget(straightHButton,0,0);


}
