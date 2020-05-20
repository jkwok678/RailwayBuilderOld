#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QtCore>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QMenuBar>
#include <QToolButton>
#include <string>
#include <iostream>
#include "borderlayout.h"
#include "canvas.h"
#include "element.h"



class Window : public QWidget
{
public:
	Window();

private slots:
	void openRailway();
	void openBuildModifyMenu();
	void openTrackMenu();
	void changeAspect();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

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
	void chooseLinkLeftUp();
	void chooseLinkRightUp();
	void chooseLinkLeftDown();
	void chooseLinkRightDown();
	void chooseExitLeft();
	void chooseExitRight();
	void chooseExitDown();
	void chooseExitUp();
	void chooseExitLeftUp();
	void chooseExitRightUp();
	void chooseExitLeftDown();
	void chooseExitRightDown();
	void chooseCurve5();
	void chooseCurve6();
	void chooseCurve7();
	void chooseCurve8();
	void chooseBufferLeft();
	void chooseBufferRight();
	void chooseBufferDown();
	void chooseBufferUp();
	void chooseBufferLeftUp();
	void chooseBufferRightUp();
	void chooseBufferLeftDown();
	void chooseBufferRightDown();
	void chooseSignalLeft();
	void chooseSignalRight();
	void chooseSignalDown();
	void chooseSignalUp();
	void chooseSignalLeftUp();
	void chooseSignalRightUp();
	void chooseSignalLeftDown();
	void chooseSignalRightDown();

private:

	ElementType windowChosen;
	int aspect;
	int windowOffsetX;
	int windowOffsetY;
	Canvas* drawingSurface;

	void createMenuBar();
	void createFileMenu();
	void createModeMenu();
	void createFileActions();
	void createModeActions();
	QMenuBar* menuBar;
	QMenu* fileMenu;
	QMenu* modeMenu;
	QAction* openRailwayAct;
	QAction* openBuildModifyAct;




	void createOverallMenu();
	void createBuildModifyMenu1();
	void createTrackMenu();
	void createTrackBlock1();

	QWidget* overallMenu;
	QVBoxLayout* overallMenuLayout;

	QWidget* buildModifyMenu1;
	QHBoxLayout* buildModifyMenuLayout1;
	QToolButton* trackMenuButton;
	QAction* openTrackMenuAct;
	QIcon* trackIcon;
	QToolButton* aspectButton;
	QAction* changeAspectAct;
	QIcon* aspect4Icon;
	QIcon* aspect3Icon;
	QIcon* aspect2Icon;
	QIcon* aspectShuntIcon;


	void createRightMenu();
	QWidget* rightMenu;
	QVBoxLayout* rightMenuLayout;
	QToolButton* rightButton;
	QAction* rightAct;
	QIcon* rightIcon;
	QToolButton* leftButton;
	QAction* leftAct;
	QIcon* leftIcon;
	QToolButton* upButton;
	QAction* upAct;
	QIcon* upIcon;
	QToolButton* downButton;
	QAction* downAct;
	QIcon* downIcon;



	//QStackedWidget *allMenus;
	QWidget* trackMenu;
	QHBoxLayout* trackMenuLayout;
	QGridLayout* trackBlock1;

	//StraightHButton
	QToolButton* straightHButton;
	QAction* chooseStraightHAct;
	QIcon* straightHIcon;

	//StraightVButton
	QToolButton* straightVButton;
	QAction* chooseStraightVAct;
	QIcon* straightVIcon;

	//DirectLeftButton
	QToolButton* directLeftButton;
	QAction* chooseDirectLeftAct;
	QIcon* directLeftIcon;

	//DirectRightButton
	QToolButton* directRightButton;
	QAction* chooseDirectRightAct;
	QIcon* directRightIcon;

	//DirectUpButton
	QToolButton* directUpButton;
	QAction* chooseDirectUpAct;
	QIcon* directUpIcon;

	//DirectDownButton
	QToolButton* directDownButton;
	QAction* chooseDirectDownAct;
	QIcon* directDownIcon;

	//StraightLeftUpButton
	QToolButton* straightLeftUpButton;
	QAction* chooseStraightLeftUpAct;
	QIcon* straightLeftUpIcon;

	//StraightRightUpButton
	QToolButton* straightRightUpButton;
	QAction* chooseStraightRightUpAct;
	QIcon* straightRightUpIcon;

	//DirectLeftUpButton
	QToolButton* directLeftUpButton;
	QAction* chooseDirectLeftUpAct;
	QIcon* directLeftUpIcon;

	//DirectRightUpButton
	QToolButton* directRightUpButton;
	QAction* chooseDirectRightUpAct;
	QIcon* directRightUpIcon;

	//DirectLeftDownButton
	QToolButton* directLeftDownButton;
	QAction* chooseDirectLeftDownAct;
	QIcon* directLeftDownIcon;

	//DirectRightDownButton
	QToolButton* directRightDownButton;
	QAction* chooseDirectRightDownAct;
	QIcon* directRightDownIcon;

	//TightCurve1Button
	QToolButton* tightCurve1Button;
	QAction* chooseTightCurve1Act;
	QIcon* tightCurve1Icon;

	//TightCurve2Button
	QToolButton* tightCurve2Button;
	QAction* chooseTightCurve2Act;
	QIcon* tightCurve2Icon;

	//TightCurve3Button
	QToolButton* tightCurve3Button;
	QAction* chooseTightCurve3Act;
	QIcon* tightCurve3Icon;

	//Tightcurve4Button
	QToolButton* tightCurve4Button;
	QAction* chooseTightCurve4Act;
	QIcon* tightCurve4Icon;

	//Curve1Button
	QToolButton* curve1Button;
	QAction* chooseCurve1Act;
	QIcon* curve1Icon;

	//Curve2Button
	QToolButton* curve2Button;
	QAction* chooseCurve2Act;
	QIcon* curve2Icon;

	//Curve3Button
	QToolButton* curve3Button;
	QAction* chooseCurve3Act;
	QIcon* curve3Icon;

	//Curve4Button
	QToolButton* curve4Button;
	QAction* chooseCurve4Act;
	QIcon* curve4Icon;

	//LinkLeftButton
	QToolButton* linkLeftButton;
	QAction* chooseLinkLeftAct;
	QIcon* linkLeftIcon;

	//LinkRightButton
	QToolButton* linkRightButton;
	QAction* chooseLinkRightAct;
	QIcon* linkRightIcon;

	//LinkDownButton
	QToolButton* linkDownButton;
	QAction* chooseLinkDownAct;
	QIcon* linkDownIcon;

	//LinkUpButton
	QToolButton* linkUpButton;
	QAction* chooseLinkUpAct;
	QIcon* linkUpIcon;

	//LinkLeftUpButton
	QToolButton* linkLeftUpButton;
	QAction* chooseLinkLeftUpAct;
	QIcon* linkLeftUpIcon;

	//LinkRightUpButton
	QToolButton* linkRightUpButton;
	QAction* chooseLinkRightUpAct;
	QIcon* linkRightUpIcon;

	//LinkLeftDownButton
	QToolButton* linkLeftDownButton;
	QAction* chooseLinkLeftDownAct;
	QIcon* linkLeftDownIcon;

	//LinkRightDownButton
	QToolButton* linkRightDownButton;
	QAction* chooseLinkRightDownAct;
	QIcon* linkRightDownIcon;

	//ExitLeftButton
	QToolButton* exitLeftButton;
	QAction* chooseExitLeftAct;
	QIcon* exitLeftIcon;

	//ExitRightButton
	QToolButton* exitRightButton;
	QAction* chooseExitRightAct;
	QIcon* exitRightIcon;

	//ExitDownButton
	QToolButton* exitDownButton;
	QAction* chooseExitDownAct;
	QIcon* exitDownIcon;

	//ExitUpButton
	QToolButton* exitUpButton;
	QAction* chooseExitUpAct;
	QIcon* exitUpIcon;

	//ExitLeftUpButton
	QToolButton* exitLeftUpButton;
	QAction* chooseExitLeftUpAct;
	QIcon* exitLeftUpIcon;

	//ExitRightUpButton
	QToolButton* exitRightUpButton;
	QAction* chooseExitRightUpAct;
	QIcon* exitRightUpIcon;

	//ExitLeftDownButton
	QToolButton* exitLeftDownButton;
	QAction* chooseExitLeftDownAct;
	QIcon* exitLeftDownIcon;

	//ExitRightDownButton
	QToolButton* exitRightDownButton;
	QAction* chooseExitRightDownAct;
	QIcon* exitRightDownIcon;

	//Curve5Button
	QToolButton* curve5Button;
	QAction* chooseCurve5Act;
	QIcon* curve5Icon;

	//Curve6Button
	QToolButton* curve6Button;
	QAction* chooseCurve6Act;
	QIcon* curve6Icon;

	//Curve7Button
	QToolButton* curve7Button;
	QAction* chooseCurve7Act;
	QIcon* curve7Icon;

	//Curve8Button
	QToolButton* curve8Button;
	QAction* chooseCurve8Act;
	QIcon* curve8Icon;

	//BufferLeftButton
	QToolButton* bufferLeftButton;
	QAction* chooseBufferLeftAct;
	QIcon* bufferLeftIcon;

	//BufferRightButton
	QToolButton* bufferRightButton;
	QAction* chooseBufferRightAct;
	QIcon* bufferRightIcon;

	//BufferDownButton
	QToolButton* bufferDownButton;
	QAction* chooseBufferDownAct;
	QIcon* bufferDownIcon;

	//BufferUpButton
	QToolButton* bufferUpButton;
	QAction* chooseBufferUpAct;
	QIcon* bufferUpIcon;

	//BufferLeftUpButton
	QToolButton* bufferLeftUpButton;
	QAction* chooseBufferLeftUpAct;
	QIcon* bufferLeftUpIcon;

	//BufferRightUpButton
	QToolButton* bufferRightUpButton;
	QAction* chooseBufferRightUpAct;
	QIcon* bufferRightUpIcon;

	//BufferLeftDownButton
	QToolButton* bufferLeftDownButton;
	QAction* chooseBufferLeftDownAct;
	QIcon* bufferLeftDownIcon;

	//BufferRightDownButton
	QToolButton* bufferRightDownButton;
	QAction* chooseBufferRightDownAct;
	QIcon* bufferRightDownIcon;

	//SignalLeftButton
	QToolButton* signalLeftButton;
	QAction* chooseSignalLeftAct;
	QIcon* signalLeftIcon;
	QIcon* shuntLeftIcon;

	//SignalRightButton
	QToolButton* signalRightButton;
	QAction* chooseSignalRightAct;
	QIcon* signalRightIcon;
	QIcon* shuntRightIcon;

	//SignalDownButton
	QToolButton* signalDownButton;
	QAction* chooseSignalDownAct;
	QIcon* signalDownIcon;
	QIcon* shuntDownIcon;

	//SignalUpButton
	QToolButton* signalUpButton;
	QAction* chooseSignalUpAct;
	QIcon* signalUpIcon;
	QIcon* shuntUpIcon;

	//SignalLeftUpButton
	QToolButton* signalLeftUpButton;
	QAction* chooseSignalLeftUpAct;
	QIcon* signalLeftUpIcon;
	QIcon* shuntLeftUpIcon;

	//SignalRightUpButton
	QToolButton* signalRightUpButton;
	QAction* chooseSignalRightUpAct;
	QIcon* signalRightUpIcon;
	QIcon* shuntRightUpIcon;

	//SignalLeftDownButton
	QToolButton* signalLeftDownButton;
	QAction* chooseSignalLeftDownAct;
	QIcon* signalLeftDownIcon;
	QIcon* shuntLeftDownIcon;

	//SignalRightDownButton
	QToolButton* signalRightDownButton;
	QAction* chooseSignalRightDownAct;
	QIcon* signalRightDownIcon;
	QIcon* shuntRightDownIcon;



};

#endif // WINDOW_H
