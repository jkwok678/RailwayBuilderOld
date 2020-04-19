#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow()
{
    createActions();
    createMenus();
    setWindowTitle(tr("Railway Builder"));
    setMinimumSize(1280, 800);

}

MainWindow::~MainWindow()
{

}

void MainWindow::openRailway()
{

}

void MainWindow::createActions()
{
    openRailwayAct = new QAction(tr("&Open Railway"), this);
    connect(openRailwayAct,&QAction::triggered, this, &MainWindow::openRailway);

}


void MainWindow::createMenus()
{
       fileMenu = menuBar()->addMenu(tr("&File"));
       fileMenu->addAction(openRailwayAct);
}


