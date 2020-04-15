#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas();
    void paintEvent(QPaintEvent *event);

signals:

};

#endif // CANVAS_H
