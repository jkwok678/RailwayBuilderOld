#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtCore>
#include <QVBoxLayout>
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

    void createTrackBlock1();

    QWidget *overallMenu;
    QVBoxLayout *buildModifyMenu;
    QHBoxLayout *buildModifyMenu1;
    QToolButton *trackMenuButton;
    QAction *openTrackMenuAct;
    QIcon *buildMenuIcon;
    QHBoxLayout *trackMenu;
    QGridLayout *trackBlock1;
    QToolButton *straightHButton;
    QAction *chooseStraightHAct;
    QIcon *straightHIcon;
    QToolButton *chooseStraightVAct;





};

#endif // WINDOW_H
