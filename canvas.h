#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <memory>
#include <string>
#include <iostream>
#include "element.h"
#include "map.h"
#include "track.h"



class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas();
    ElementType getElementType();
    void setElementType(ElementType &newChosen);

    Map getMap();
    void setMap(Map &map);

    int getImageSize() const;
    void setImageSize(int newImageSize);

    bool getModified() const;
    void setModified(bool newModified);

    int getOffsetX() const;
    void setOffsetX(int &newOffsetX);

    int getOffsetY() const;
    void setOffsetY(int &newOffsetY);

public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    ElementType *canvasChosen;

    Map *drawnLayout;
    int imageSize;
    bool modified = false;
    int offsetX;
    int offsetY;
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
    QImage *straightVImage;
    QImage *directLeftImage;
    QImage *directRightImage;
    QImage *directUpImage;
    QImage *directDownImage;
    QImage *straightRightUpImage;
    QImage *straightLeftUpImage;
    QImage *directRightUpImage;
    QImage *directLeftUpImage;
    QImage *directLeftDownImage;
    QImage *directRightDownIamge;


};

#endif // CANVAS_H
