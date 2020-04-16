#include "window.h"

Window::Window()
{

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

void Window::openRailway()
{

}

void Window::openBuildModifyMenu()
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
    buildModifyMenu = new QVBoxLayout;
    buildModifyMenu1 = new QHBoxLayout;
    createBuildModifyMenu1();
    buildModifyMenu->addLayout(buildModifyMenu1);
    overallMenu->setLayout(buildModifyMenu);
}

void Window::createBuildModifyMenu1()
{
    trackMenuButton = new QToolButton();
    trackMenuButton->setMaximumSize(QSize(32,32));
    QIcon *icon1 = new QIcon(":/icons/icons/buildMenuIcon.png");
    trackMenuButton->setIcon(*icon1);
    buildModifyMenu1->addWidget(trackMenuButton);
}
