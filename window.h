#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtCore>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QMenuBar>
#include <QToolButton>
#include "borderlayout.h"
#include "canvas.h"
#include "map.h"
#include "element.h"



class Window : public QWidget
{
public:
    Window();
    Map getCurrentLayout();
    void setCurrentLayout(Map currentLayout);

private slots:
    void openRailway();
    void openBuildModifyMenu();
    void openTrackMenu();
    void chooseStraightH();
    void chooseStraightV();
    void chooseDirectLeft();
    void chooseDirectRight();
    void chooseDirectUp();
    void chooseDirectDown();

private:
    Map currentLayout;
    ElementType chosen;


    void createMenuBar();
    void createFileMenu();
    void createModeMenu();
    void createFileActions();
    void createModeActions();
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *modeMenu;
    QAction *openRailwayAct;
    QAction *openBuildModifyAct;


    void createOverallMenu();
    void createBuildModifyMenu1();
    void createTrackMenu();
    void createTrackBlock1();

    QWidget *overallMenu;
    QVBoxLayout *overallMenuLayout;

    QHBoxLayout *buildModifyMenu1;
    QToolButton *trackMenuButton;
    QAction *openTrackMenuAct;
    QIcon *trackIcon;

    //QStackedWidget *allMenus;
    QWidget *trackMenu;
    QHBoxLayout *trackMenuLayout;
    QGridLayout *trackBlock1;

    //StraightHButton
    QToolButton *straightHButton;
    QAction *chooseStraightHAct;
    QIcon *straightHIcon;

    //StraightVButton
    QToolButton *straightVButton;
    QAction *chooseStraightVAct;
    QIcon *straightVIcon;

    //DirectLeftButton
    QToolButton *directLeftButton;
    QAction *chooseDirectLeftAct;
    QIcon *directLeftIcon;

    //DirectRightButton
    QToolButton *directRightButton;
    QAction *chooseDirectRightAct;
    QIcon *directRightIcon;

    //DirectUpButton
    QToolButton *directUpButton;
    QAction *chooseDirectUpAct;
    QIcon *directUpIcon;

    //DirectDownButton
    QToolButton *directDownButton;
    QAction *chooseDirectDownAct;
    QIcon *directDownIcon;




};

#endif // WINDOW_H
