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
    void changeAspect();
    void chooseStraightH();
    void chooseStraightV();
    void chooseDirectLeft();
    void chooseDirectRight();
    void chooseDirectUp();
    void chooseDirectDown();
    void chooseStraightLeftUp();
    void chooseStraightRightUp();
    void chooseDirectLeftUp();
    void chooseDirectRightUp();
    void chooseDirectLeftDown();
    void chooseDirectRightDown();
    void chooseTightCurve1();
    void chooseTightCurve2();
    void chooseTightCurve3();
    void chooseTightCurve4();
    void chooseCurve1();
    void chooseCurve2();
    void chooseCurve3();
    void chooseCurve4();
    void chooseLinkLeft();
    void chooseLinkRight();
    void chooseLinkDown();
    void chooseLinkUp();

private:
    Map currentLayout;
    ElementType chosen;
    int aspect;


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

    QWidget *buildModifyMenu1;
    QHBoxLayout *buildModifyMenuLayout1;
    QToolButton *trackMenuButton;
    QAction *openTrackMenuAct;
    QIcon *trackIcon;
    QToolButton *aspectButton;
    QAction *changeAspectAct;
    QIcon *aspect4Icon;
    QIcon *aspect3Icon;
    QIcon *aspect2Icon;
    QIcon *aspectShuntIcon;


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

    //StraightLeftUpButton
    QToolButton *straightLeftUpButton;
    QAction *chooseStraightLeftUpAct;
    QIcon *straightLeftUpIcon;

    //StraightRightUpButton
    QToolButton *straightRightUpButton;
    QAction *chooseStraightRightUpAct;
    QIcon *straightRightUpIcon;

    //DirectLeftUpButton
    QToolButton *directLeftUpButton;
    QAction *chooseDirectLeftUpAct;
    QIcon *directLeftUpIcon;

    //DirectRightUpButton
    QToolButton *directRightUpButton;
    QAction *chooseDirectRightUpAct;
    QIcon *directRightUpIcon;

    //DirectLeftDownButton
    QToolButton *directLeftDownButton;
    QAction *chooseDirectLeftDownAct;
    QIcon *directLeftDownIcon;

    //DirectRightDownButton
    QToolButton *directRightDownButton;
    QAction *chooseDirectRightDownAct;
    QIcon *directRightDownIcon;

    //TightCurve1Button
    QToolButton *tightCurve1Button;
    QAction *chooseTightCurve1Act;
    QIcon *tightCurve1Icon;

    //TightCurve2Button
    QToolButton *tightCurve2Button;
    QAction *chooseTightCurve2Act;
    QIcon *tightCurve2Icon;

    //TightCurve3Button
    QToolButton *tightCurve3Button;
    QAction *chooseTightCurve3Act;
    QIcon *tightCurve3Icon;

    //Tightcurve4Button
    QToolButton *tightcurve4Button;
    QAction *chooseTightcurve4Act;
    QIcon *tightcurve4Icon;

    //Curve1Button
    QToolButton *curve1Button;
    QAction *chooseCurve1Act;
    QIcon *curve1Icon;

    //Curve2Button
    QToolButton *curve2Button;
    QAction *chooseCurve2Act;
    QIcon *curve2Icon;

    //Curve3Button
    QToolButton *curve3Button;
    QAction *chooseCurve3Act;
    QIcon *curve3Icon;

    //Curve4Button
    QToolButton *curve4Button;
    QAction *chooseCurve4Act;
    QIcon *curve4Icon;

    //LinkLeftButton
    QToolButton *linkLeftButton;
    QAction *chooseLinkLeftAct;
    QIcon *linkLeftIcon;

    //LinkRightButton
    QToolButton *linkRightButton;
    QAction *chooseLinkRightAct;
    QIcon *linkRightIcon;

    //LinkDownButton
    QToolButton *linkDownButton;
    QAction *chooseLinkDownAct;
    QIcon *linkDownIcon;

    //LinkUpButton
    QToolButton *linkUpButton;
    QAction *chooseLinkUpAct;
    QIcon *linkUpIcon;
};

#endif // WINDOW_H
