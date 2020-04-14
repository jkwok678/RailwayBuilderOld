#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);

protected:


private slots:
    void openRailway();



private:


    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QAction *openRailwayAct;
};
#endif // MAINWINDOW_H
