#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas();


public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    int imageSize;
    bool modified = false;
    QPoint lastPoint;
    int exactX;
    int exactY;
    int extraX;
    int extraY;
    int finalX;
    int finalY;
    int boundX;
    int boundY;
    QImage *straightHImage;


};

#endif // CANVAS_H
