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



class Window : public QWidget
{
public:
    Window();

private slots:
    void openRailway();
    void openBuildModifyMenu();

private:
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
    QWidget *overallMenu;
    QVBoxLayout *buildModifyMenu;
    QHBoxLayout *buildModifyMenu1;
    QPushButton *trackMenuButton;
    QAction *openTrackMenuAct;



};

#endif // WINDOW_H
