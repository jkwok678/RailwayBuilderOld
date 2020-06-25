#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QInputDialog>
#include <QTimer>
#include <memory>
#include <string>
#include <iostream>
#include "element.h"
#include "map.h"
#include "track.h"



class Canvas : public QGraphicsView
{
	Q_OBJECT
public:

	Canvas();
	ElementType getElementType();
	void setElementType(ElementType& newChosen);

	Map getMap();
	void setMap(Map& map);

	int getImageSize() const;
	void setImageSize(int newImageSize);

	bool getModified() const;
	void setModified(bool newModified);

	int getOffsetX() const;
	void setOffsetX(int& newOffsetX);

	int getOffsetY() const;
	void setOffsetY(int& newOffsetY);

	int getAspect() const;
	void setAspect(int& newAspect);

    bool getCanvasShowTrackID() const;
    void setCanvasShowTrackID(bool& newShowTrackID);

    bool getCanvasShowMoreTrackInfo() const;
    void setCanvasShowMoreTrackInfo(bool& newShowMoreTrackInfo);

public slots:
    void redraw();

protected:
	void mousePressEvent(QMouseEvent* event) override;
    //void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


private:
	ElementType* canvasChosen;

    QGraphicsScene* scene;

	Map* drawnLayout;
	int imageSize;
	bool modified = false;
    int offsetX;
    int offsetY;
    int canvasSizeX;
    int canvasSizeY;
	int canvasAspect;
	QPoint lastPoint;
	int exactX;
	int exactY;
	int extraX;
	int extraY;
	int finalX;
	int finalY;
	int boundX;
	int boundY;

    bool canvasShowTrackID;
    bool canvasShowMoreTrackInfo;

    //ElementBlock1 Pixmap
    QPixmap* straightHPixmap;
    QPixmap* straightVPixmap;
    QPixmap* directLeftPixmap;
    QPixmap* directRightPixmap;
    QPixmap* directUpPixmap;
    QPixmap* directDownPixmap;
    QPixmap* straightRightUpPixmap;
    QPixmap* straightLeftUpPixmap;
    QPixmap* directRightUpPixmap;
    QPixmap* directLeftUpPixmap;
    QPixmap* directLeftDownPixmap;
    QPixmap* directRightDownPixmap;
    QPixmap* tightCurve1Pixmap;
    QPixmap* tightCurve2Pixmap;
    QPixmap* tightCurve3Pixmap;
    QPixmap* tightCurve4Pixmap;
    QPixmap* curve1Pixmap;
    QPixmap* curve2Pixmap;
    QPixmap* curve3Pixmap;
    QPixmap* curve4Pixmap;
    QPixmap* linkLeftPixmap;
    QPixmap* linkRightPixmap;
    QPixmap* linkDownPixmap;
    QPixmap* linkUpPixmap;
    QPixmap* linkLeftUpPixmap;
    QPixmap* linkRightUpPixmap;
    QPixmap* linkRightDownPixmap;
    QPixmap* linkLeftDownPixmap;
    QPixmap* exitLeftPixmap;
    QPixmap* exitRightPixmap;
    QPixmap* exitDownPixmap;
    QPixmap* exitUpPixmap;
    QPixmap* exitLeftUpPixmap;
    QPixmap* exitRightUpPixmap;
    QPixmap* exitLeftDownPixmap;
    QPixmap* exitRightDownPixmap;
    QPixmap* curve5Pixmap;
    QPixmap* curve6Pixmap;
    QPixmap* curve7Pixmap;
    QPixmap* curve8Pixmap;
    QPixmap* bufferLeftPixmap;
    QPixmap* bufferRightPixmap;
    QPixmap* bufferDownPixmap;
    QPixmap* bufferUpPixmap;
    QPixmap* bufferLeftUpPixmap;
    QPixmap* bufferRightUpPixmap;
    QPixmap* bufferLeftDownPixmap;
    QPixmap* bufferRightDownPixmap;
    QPixmap* signalLeftPixmap;
    QPixmap* signalRightPixmap;
    QPixmap* signalDownPixmap;
    QPixmap* signalUpPixmap;
    QPixmap* signalLeftUpPixmap;
    QPixmap* signalRightUpPixmap;
    QPixmap* signalLeftDownPixmap;
    QPixmap* signalRightDownPixmap;
    QPixmap* shuntLeftPixmap;
    QPixmap* shuntRightPixmap;
    QPixmap* shuntDownPixmap;
    QPixmap* shuntUpPixmap;
    QPixmap* shuntLeftUpPixmap;
    QPixmap* shuntRightUpPixmap;
    QPixmap* shuntLeftDownPixmap;
    QPixmap* shuntRightDownPixmap;
    QPixmap* bridgeUnset1Pixmap;
    QPixmap* bridgeUnset2Pixmap;
    QPixmap* underpassUnset1Pixmap;
    QPixmap* underpassUnset2Pixmap;
    QPixmap* bridgeSet1Pixmap;
    QPixmap* bridgeSet2Pixmap;
    QPixmap* underpassSet1Pixmap;
    QPixmap* underpassSet2Pixmap;

    //ElementBlock2 Pixmaps
    QPixmap* switchTight1Pixmap;
    QPixmap* switchTight2Pixmap;
    QPixmap* switchTight3Pixmap;
    QPixmap* switchTight4Pixmap;
    QPixmap* switchTight5Pixmap;
    QPixmap* switchTight6Pixmap;
    QPixmap* switchTight7Pixmap;
    QPixmap* switchTight8Pixmap;
    QPixmap* switchSplit1Pixmap;
    QPixmap* switchSplit2Pixmap;
    QPixmap* switchSplit3Pixmap;

    QPixmap* switch1Pixmap;
    QPixmap* switch2Pixmap;
    QPixmap* switch3Pixmap;
    QPixmap* switch4Pixmap;
    QPixmap* switch5Pixmap;
    QPixmap* switch6Pixmap;
    QPixmap* switch7Pixmap;
    QPixmap* switch8Pixmap;
    QPixmap* switchSplit4Pixmap;
    QPixmap* switchSplit5Pixmap;
    QPixmap* switchSplit6Pixmap;

    QPixmap* switch9Pixmap;
    QPixmap* switch10Pixmap;
    QPixmap* switch11Pixmap;
    QPixmap* switch12Pixmap;
    QPixmap* switch13Pixmap;
    QPixmap* switch14Pixmap;
    QPixmap* switch15Pixmap;
    QPixmap* switch16Pixmap;
    QPixmap* switchSplit7Pixmap;
    QPixmap* switchSplit8Pixmap;

    //ElementBlock3 Pixmaps
    QPixmap* crossover1Pixmap;
    QPixmap* crossover2Pixmap;
    QPixmap* flyover1Pixmap;
    QPixmap* flyover2Pixmap;
    QPixmap* flyover3Pixmap;
    QPixmap* flyover4Pixmap;

    QPixmap* crossover3Pixmap;
    QPixmap* crossover4Pixmap;
    QPixmap* flyover5Pixmap;
    QPixmap* flyover6Pixmap;
    QPixmap* flyover7Pixmap;
    QPixmap* flyover8Pixmap;

    QPixmap* crossover5Pixmap;
    QPixmap* crossover6Pixmap;
    QPixmap* flyover9Pixmap;
    QPixmap* flyover10Pixmap;
    QPixmap* flyover11Pixmap;
    QPixmap* flyover12Pixmap;

    //ElementBlock4 Pixmaps
    QPixmap* namedLocationUnsetPixmap;
    QPixmap* namedLocationSetPixmap;
    QPixmap* concourseUnsetPixmap;
    QPixmap* concourseSetPixmap;
    QPixmap* platformDownUnsetPixmap;
    QPixmap* platformDownSetPixmap;
    QPixmap* platformUpUnsetPixmap;
    QPixmap* platformUpSetPixmap;
    QPixmap* platformLeftUnsetPixmap;
    QPixmap* platformLeftSetPixmap;
    QPixmap* platformRightUnsetPixmap;
    QPixmap* platformRightSetPixmap;

    //ElementBlock5 Pixmaps;
    QPixmap* parapet1Pixmap;
    QPixmap* parapet2Pixmap;
    QPixmap* parapet3Pixmap;
    QPixmap* parapet4Pixmap;
    QPixmap* parapet5Pixmap;
    QPixmap* parapet6Pixmap;
    QPixmap* parapet7Pixmap;
    QPixmap* parapet8Pixmap;
    QPixmap* parapet9Pixmap;
    QPixmap* parapet10Pixmap;

    QPixmap* parapet11Pixmap;
    QPixmap* parapet12Pixmap;
    QPixmap* parapet13Pixmap;
    QPixmap* parapet14Pixmap;
    QPixmap* parapet15Pixmap;
    QPixmap* parapet16Pixmap;
    QPixmap* parapet17Pixmap;
    QPixmap* parapet18Pixmap;
    QPixmap* parapet19Pixmap;
    QPixmap* parapet20Pixmap;

    QPixmap* parapet21Pixmap;
    QPixmap* parapet22Pixmap;
    QPixmap* parapet23Pixmap;
    QPixmap* parapet24Pixmap;
    QPixmap* parapet25Pixmap;
    QPixmap* parapet26Pixmap;
    QPixmap* parapet27Pixmap;
    QPixmap* parapet28Pixmap;

    //ELementBlock6 Pixmap
    QPixmap* levelCrossingHPixmap;
    QPixmap* levelCrossingVPixmap;

};

#endif // CANVAS_H
