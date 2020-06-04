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
    void openElementMenu();
	void changeAspect();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();


    //ElementBlock1 slots
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
    void chooseBridge1();
    void chooseBridge2();
    void chooseUnderpass1();
    void chooseUnderpass2();

    //ElementBlock2 slots
    void chooseSwitchTight1();
    void chooseSwitchTight2();
    void chooseSwitchTight3();
    void chooseSwitchTight4();
    void chooseSwitchTight5();
    void chooseSwitchTight6();
    void chooseSwitchTight7();
    void chooseSwitchTight8();
    void chooseSwitchSplit1();
    void chooseSwitchSplit2();
    void chooseSwitchSplit3();

    void chooseSwitch1();
    void chooseSwitch2();
    void chooseSwitch3();
    void chooseSwitch4();
    void chooseSwitch5();
    void chooseSwitch6();
    void chooseSwitch7();
    void chooseSwitch8();
    void chooseSwitchSplit4();
    void chooseSwitchSplit5();
    void chooseSwitchSplit6();

    void chooseSwitch9();
    void chooseSwitch10();
    void chooseSwitch11();
    void chooseSwitch12();
    void chooseSwitch13();
    void chooseSwitch14();
    void chooseSwitch15();
    void chooseSwitch16();
    void chooseSwitchSplit7();
    void chooseSwitchSplit8();

    //ElementBlock3 slots

    void chooseCrossover1();
    void chooseCrossover2();
    void chooseFlyover1();
    void chooseFlyover2();
    void chooseFlyover3();
    void chooseFlyover4();

    void chooseCrossover3();
    void chooseCrossover4();
    void chooseFlyover5();
    void chooseFlyover6();
    void chooseFlyover7();
    void chooseFlyover8();

    void chooseCrossover5();
    void chooseCrossover6();
    void chooseFlyover9();
    void chooseFlyover10();
    void chooseFlyover11();
    void chooseFlyover12();

    //ElementBlock4 slots
    void chooseNamedLocation();
    void chooseConcourse();
    void choosePlatformLeft();
    void choosePlatformRight();
    void choosePlatformDown();
    void choosePlatformUp();

    //ElementBlock5 slots

    void chooseParapet1();
    void chooseParapet2();
    void chooseParapet3();
    void chooseParapet4();
    void chooseParapet5();
    void chooseParapet6();
    void chooseParapet7();
    void chooseParapet8();
    void chooseParapet9();
    void chooseParapet10();

    void chooseParapet11();
    void chooseParapet12();
    void chooseParapet13();
    void chooseParapet14();
    void chooseParapet15();
    void chooseParapet16();
    void chooseParapet17();
    void chooseParapet18();
    void chooseParapet19();
    void chooseParapet20();

    void chooseParapet21();
    void chooseParapet22();
    void chooseParapet23();
    void chooseParapet24();
    void chooseParapet25();
    void chooseParapet26();
    void chooseParapet27();
    void chooseParapet28();


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
    void createElementMenu();
    void createElementBlock1();
    void createElementBlock2();
    void createElementBlock3();
    void createElementBlock4();
    void createElementBlock5();

	QWidget* overallMenu;
	QVBoxLayout* overallMenuLayout;

	QWidget* buildModifyMenu1;
	QHBoxLayout* buildModifyMenuLayout1;
    QToolButton* elementMenuButton;
    QAction* openElementMenuAct;
	QIcon* trackIcon;
	QToolButton* aspectButton;
	QAction* changeAspectAct;
	QIcon* aspect4Icon;
	QIcon* aspect3Icon;
	QIcon* aspect2Icon;
	QIcon* aspectShuntIcon;

    //QStackedWidget *allMenus;
    QWidget* elementMenu;
    QHBoxLayout* elementMenuLayout;
    QGridLayout* elementBlock1;
    QGridLayout* elementBlock2;
    QGridLayout* elementBlock3;
    QGridLayout* elementBlock4;
    QGridLayout* elementBlock5;

    /*
     * ElementBlock1 buttons
     * START HERE
     */

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

    //Bridge2Button
    QToolButton* bridge1Button;
    QAction* chooseBridge1Act;;
    QIcon* bridge1Icon;

    //Bridge2Button
    QToolButton* bridge2Button;
    QAction* chooseBridge2Act;
    QIcon* bridge2Icon;

    //Underpass1Button
    QToolButton* underpass1Button;
    QAction* chooseUnderpass1Act;;
    QIcon* underpass1Icon;

    //Underpass2Button
    QToolButton* underpass2Button;
    QAction* chooseUnderpass2Act;
    QIcon* underpass2Icon;

    /*
     * ElementBlock2 buttons
     * START HERE
     */

    //SwitchTight1Button
    QToolButton* switchTight1Button;
    QAction* chooseSwitchTight1Act;
    QIcon* switchTight1Icon;

    //SwitchTight2Button
    QToolButton* switchTight2Button;
    QAction* chooseSwitchTight2Act;
    QIcon* switchTight2Icon;

    //SwitchTight3Button
    QToolButton* switchTight3Button;
    QAction* chooseSwitchTight3Act;
    QIcon* switchTight3Icon;

    //SwitchTight4Button
    QToolButton* switchTight4Button;
    QAction* chooseSwitchTight4Act;
    QIcon* switchTight4Icon;

    //SwitchTight5Button
    QToolButton* switchTight5Button;
    QAction* chooseSwitchTight5Act;
    QIcon* switchTight5Icon;

    //SwitchTight6Button
    QToolButton* switchTight6Button;
    QAction* chooseSwitchTight6Act;
    QIcon* switchTight6Icon;

    //SwitchTight7Button
    QToolButton* switchTight7Button;
    QAction* chooseSwitchTight7Act;
    QIcon* switchTight7Icon;

    //SwitchTight8Button
    QToolButton* switchTight8Button;
    QAction* chooseSwitchTight8Act;
    QIcon* switchTight8Icon;

    //SwitchSplit1Button
    QToolButton* switchSplit1Button;
    QAction* chooseSwitchSplit1Act;
    QIcon* switchSplit1Icon;

    //SwitchSplit2Button
    QToolButton* switchSplit2Button;
    QAction* chooseSwitchSplit2Act;
    QIcon* switchSplit2Icon;

    //SwitchSplit3Button
    QToolButton* switchSplit3Button;
    QAction* chooseSwitchSplit3Act;
    QIcon* switchSplit3Icon;

    //Switch1Button
    QToolButton* switch1Button;
    QAction* chooseSwitch1Act;
    QIcon* switch1Icon;

    //Switch2Button
    QToolButton* switch2Button;
    QAction* chooseSwitch2Act;
    QIcon* switch2Icon;

    //Switch3Button
    QToolButton* switch3Button;
    QAction* chooseSwitch3Act;
    QIcon* switch3Icon;

    //Switch4Button
    QToolButton* switch4Button;
    QAction* chooseSwitch4Act;
    QIcon* switch4Icon;

    //Switch5Button
    QToolButton* switch5Button;
    QAction* chooseSwitch5Act;
    QIcon* switch5Icon;

    //Switch6Button
    QToolButton* switch6Button;
    QAction* chooseSwitch6Act;
    QIcon* switch6Icon;

    //Switch7Button
    QToolButton* switch7Button;
    QAction* chooseSwitch7Act;
    QIcon* switch7Icon;

    //Switch8Button
    QToolButton* switch8Button;
    QAction* chooseSwitch8Act;
    QIcon* switch8Icon;

    //SwitchSplit4Button
    QToolButton* switchSplit4Button;
    QAction* chooseSwitchSplit4Act;
    QIcon* switchSplit4Icon;

    //SwitchSplit5Button
    QToolButton* switchSplit5Button;
    QAction* chooseSwitchSplit5Act;
    QIcon* switchSplit5Icon;

    //SwitchSplit6Button
    QToolButton* switchSplit6Button;
    QAction* chooseSwitchSplit6Act;
    QIcon* switchSplit6Icon;

    //Switch9Button
    QToolButton* switch9Button;
    QAction* chooseSwitch9Act;
    QIcon* switch9Icon;

    //Switch10Button
    QToolButton* switch10Button;
    QAction* chooseSwitch10Act;
    QIcon* switch10Icon;

    //Switch11Button
    QToolButton* switch11Button;
    QAction* chooseSwitch11Act;
    QIcon* switch11Icon;

    //Switch12Button
    QToolButton* switch12Button;
    QAction* chooseSwitch12Act;
    QIcon* switch12Icon;

    //Switch13Button
    QToolButton* switch13Button;
    QAction* chooseSwitch13Act;
    QIcon* switch13Icon;

    //Switch14Button
    QToolButton* switch14Button;
    QAction* chooseSwitch14Act;
    QIcon* switch14Icon;

    //Switch15Button
    QToolButton* switch15Button;
    QAction* chooseSwitch15Act;
    QIcon* switch15Icon;

    //Switch16Button
    QToolButton* switch16Button;
    QAction* chooseSwitch16Act;
    QIcon* switch16Icon;

    //SwitchSplit7Button
    QToolButton* switchSplit7Button;
    QAction* chooseSwitchSplit7Act;
    QIcon* switchSplit7Icon;

    //SwitchSplit8Button
    QToolButton* switchSplit8Button;
    QAction* chooseSwitchSplit8Act;
    QIcon* switchSplit8Icon;

    /*
     * ElementBlock3 buttons
     * START HERE
     */

    //Crossover1Button
    QToolButton* crossover1Button;
    QAction* chooseCrossover1Act;
    QIcon* crossover1Icon;

    //Crossover2Button
    QToolButton* crossover2Button;
    QAction* chooseCrossover2Act;
    QIcon* crossover2Icon;

    //Flyover1Button
    QToolButton* flyover1Button;
    QAction* chooseFlyover1Act;
    QIcon* flyover1Icon;

    //Flyover2Button
    QToolButton* flyover2Button;
    QAction* chooseFlyover2Act;
    QIcon* flyover2Icon;

    //Flyover3Button
    QToolButton* flyover3Button;
    QAction* chooseFlyover3Act;
    QIcon* flyover3Icon;

    //Flyover4Button
    QToolButton* flyover4Button;
    QAction* chooseFlyover4Act;
    QIcon* flyover4Icon;

    //Crossover3Button
    QToolButton* crossover3Button;
    QAction* chooseCrossover3Act;
    QIcon* crossover3Icon;

    //Crossover4Button
    QToolButton* crossover4Button;
    QAction* chooseCrossover4Act;
    QIcon* crossover4Icon;

    //Flyover5Button
    QToolButton* flyover5Button;
    QAction* chooseFlyover5Act;
    QIcon* flyover5Icon;

    //Flyover6Button
    QToolButton* flyover6Button;
    QAction* chooseFlyover6Act;
    QIcon* flyover6Icon;

    //Flyover7Button
    QToolButton* flyover7Button;
    QAction* chooseFlyover7Act;
    QIcon* flyover7Icon;

    //Flyover8Button
    QToolButton* flyover8Button;
    QAction* chooseFlyover8Act;
    QIcon* flyover8Icon;

    //Crossover5Button
    QToolButton* crossover5Button;
    QAction* chooseCrossover5Act;
    QIcon* crossover5Icon;

    //Crossover6Button
    QToolButton* crossover6Button;
    QAction* chooseCrossover6Act;
    QIcon* crossover6Icon;

    //Flyover9Button
    QToolButton* flyover9Button;
    QAction* chooseFlyover9Act;
    QIcon* flyover9Icon;

    //Flyover10Button
    QToolButton* flyover10Button;
    QAction* chooseFlyover10Act;
    QIcon* flyover10Icon;

    //Flyover11Button
    QToolButton* flyover11Button;
    QAction* chooseFlyover11Act;
    QIcon* flyover11Icon;

    //Flyover12Button
    QToolButton* flyover12Button;
    QAction* chooseFlyover12Act;
    QIcon* flyover12Icon;

    //ElementBlock4

    //NamedLocation1Button
    QToolButton* namedLocationButton;
    QAction* chooseNamedLocationAct;
    QIcon* namedLocationIcon;

    //ConcourseButton
    QToolButton* concourseButton;
    QAction* chooseConcourseAct;
    QIcon* concourseIcon;

    //PlatformUpButton
    QToolButton* platformUpButton;
    QAction* choosePlatformUpAct;
    QIcon* platformUpIcon;

    //PlatformDownButton
    QToolButton* platformDownButton;
    QAction* choosePlatformDownAct;
    QIcon* platformDownIcon;

    //PlatformLeftButton
    QToolButton* platformLeftButton;
    QAction* choosePlatformLeftAct;
    QIcon* platformLeftIcon;

    //PlatformRightButton
    QToolButton* platformRightButton;
    QAction* choosePlatformRightAct;
    QIcon* platformRightIcon;

    //ElementBlock5

    //Parapet1Button
    QToolButton* parapet1Button;
    QAction* chooseParapet1Act;
    QIcon* parapet1Icon;

    //Parapet2Button
    QToolButton* parapet2Button;
    QAction* chooseParapet2Act;
    QIcon* parapet2Icon;

    //Parapet3Button
    QToolButton* parapet3Button;
    QAction* chooseParapet3Act;
    QIcon* parapet3Icon;

    //Parapet4Button
    QToolButton* parapet4Button;
    QAction* chooseParapet4Act;
    QIcon* parapet4Icon;

    //Parapet5Button
    QToolButton* parapet5Button;
    QAction* chooseParapet5Act;
    QIcon* parapet5Icon;

    //Parapet6Button
    QToolButton* parapet6Button;
    QAction* chooseParapet6Act;
    QIcon* parapet6Icon;

    //Parapet7Button
    QToolButton* parapet7Button;
    QAction* chooseParapet7Act;
    QIcon* parapet7Icon;

    //Parapet8Button
    QToolButton* parapet8Button;
    QAction* chooseParapet8Act;
    QIcon* parapet8Icon;

    //Parapet9Button
    QToolButton* parapet9Button;
    QAction* chooseParapet9Act;
    QIcon* parapet9Icon;

    //Parapet10Button
    QToolButton* parapet10Button;
    QAction* chooseParapet10Act;
    QIcon* parapet10Icon;

    //Parapet11Button
    QToolButton* parapet11Button;
    QAction* chooseParapet11Act;
    QIcon* parapet11Icon;

    //Parapet12Button
    QToolButton* parapet12Button;
    QAction* chooseParapet12Act;
    QIcon* parapet12Icon;

    //Parapet13Button
    QToolButton* parapet13Button;
    QAction* chooseParapet13Act;
    QIcon* parapet13Icon;

    //Parapet14Button
    QToolButton* parapet14Button;
    QAction* chooseParapet14Act;
    QIcon* parapet14Icon;

    //Parapet15Button
    QToolButton* parapet15Button;
    QAction* chooseParapet15Act;
    QIcon* parapet15Icon;

    //Parapet16Button
    QToolButton* parapet16Button;
    QAction* chooseParapet16Act;
    QIcon* parapet16Icon;

    //Parapet17Button
    QToolButton* parapet17Button;
    QAction* chooseParapet17Act;
    QIcon* parapet17Icon;

    //Parapet18Button
    QToolButton* parapet18Button;
    QAction* chooseParapet18Act;
    QIcon* parapet18Icon;

    //Parapet19Button
    QToolButton* parapet19Button;
    QAction* chooseParapet19Act;
    QIcon* parapet19Icon;

    //Parapet20Button
    QToolButton* parapet20Button;
    QAction* chooseParapet20Act;
    QIcon* parapet20Icon;

    //Parapet21Button
    QToolButton* parapet21Button;
    QAction* chooseParapet21Act;
    QIcon* parapet21Icon;

    //Parapet22Button
    QToolButton* parapet22Button;
    QAction* chooseParapet22Act;
    QIcon* parapet22Icon;

    //Parapet23Button
    QToolButton* parapet23Button;
    QAction* chooseParapet23Act;
    QIcon* parapet23Icon;

    //Parapet24Button
    QToolButton* parapet24Button;
    QAction* chooseParapet24Act;
    QIcon* parapet24Icon;

    //Parapet25Button
    QToolButton* parapet25Button;
    QAction* chooseParapet25Act;
    QIcon* parapet25Icon;

    //Parapet26Button
    QToolButton* parapet26Button;
    QAction* chooseParapet26Act;
    QIcon* parapet26Icon;

    //Parapet27Button
    QToolButton* parapet27Button;
    QAction* chooseParapet27Act;
    QIcon* parapet27Icon;

    //Parapet28Button
    QToolButton* parapet28Button;
    QAction* chooseParapet28Act;
    QIcon* parapet28Icon;



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







};

#endif // WINDOW_H
