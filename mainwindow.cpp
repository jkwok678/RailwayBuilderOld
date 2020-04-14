#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow()
{


}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenus()
{
       fileMenu = menuBar()->addMenu(tr("&File"));
       fileMenu->addAction(openRailwayAct);
}
