#include "canvas.h"

Canvas::Canvas()
{
    setMinimumSize(1280,800);
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage *image = new QImage(":/graphics/graphics/straightH.png");

    painter.drawImage(*image);
}
