#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
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

public slots:

protected:
	void mousePressEvent(QMouseEvent* event) override;
    //void paintEvent(QPaintEvent* event) override;

    void redraw();

private:
	ElementType* canvasChosen;

    QGraphicsScene* scene;

	Map* drawnLayout;
	int imageSize;
	bool modified = false;
	int offsetX;
	int offsetY;
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


    //ElementBlock1 images
    QPixmap* straightHImage;
    QPixmap* straightVImage;
    QPixmap* directLeftImage;
    QPixmap* directRightImage;
    QPixmap* directUpImage;
    QPixmap* directDownImage;
    QPixmap* straightRightUpImage;
    QPixmap* straightLeftUpImage;
    QPixmap* directRightUpImage;
    QPixmap* directLeftUpImage;
    QPixmap* directLeftDownImage;
    QPixmap* directRightDownIamge;
    QPixmap* tightCurve1Image;
    QPixmap* tightCurve2Image;
    QPixmap* tightCurve3Image;
    QPixmap* tightCurve4Image;
    QPixmap* curve1Image;
    QPixmap* curve2Image;
    QPixmap* curve3Image;
    QPixmap* curve4Image;
    QPixmap* linkLeftImage;
    QPixmap* linkRightImage;
    QPixmap* linkDownImage;
    QPixmap* linkUpImage;
    QPixmap* linkLeftUpImage;
    QPixmap* linkRightUpImage;
    QPixmap* linkRightDownImage;
    QPixmap* linkLeftDownImage;
    QPixmap* exitLeftImage;
    QPixmap* exitRightImage;
    QPixmap* exitDownImage;
    QPixmap* exitUpImage;
    QPixmap* exitLeftUpImage;
    QPixmap* exitRightUpImage;
    QPixmap* exitLeftDownImage;
    QPixmap* exitRightDownImage;
    QPixmap* curve5Image;
    QPixmap* curve6Image;
    QPixmap* curve7Image;
    QPixmap* curve8Image;
    QPixmap* bufferLeftImage;
    QPixmap* bufferRightImage;
    QPixmap* bufferDownImage;
    QPixmap* bufferUpImage;
    QPixmap* bufferLeftUpImage;
    QPixmap* bufferRightUpImage;
    QPixmap* bufferLeftDownImage;
    QPixmap* bufferRightDownImage;
    QPixmap* signalLeftImage;
    QPixmap* signalRightImage;
    QPixmap* signalDownImage;
    QPixmap* signalUpImage;
    QPixmap* signalLeftUpImage;
    QPixmap* signalRightUpImage;
    QPixmap* signalLeftDownImage;
    QPixmap* signalRightDownImage;
    QPixmap* shuntLeftImage;
    QPixmap* shuntRightImage;
    QPixmap* shuntDownImage;
    QPixmap* shuntUpImage;
    QPixmap* shuntLeftUpImage;
    QPixmap* shuntRightUpImage;
    QPixmap* shuntLeftDownImage;
    QPixmap* shuntRightDownImage;
    QPixmap* bridgeUnset1Image;
    QPixmap* bridgeUnset2Image;
    QPixmap* underpassUnset1Image;
    QPixmap* underpassUnset2Image;
    QPixmap* bridgeSet1Image;
    QPixmap* bridgeSet2Image;
    QPixmap* underpassSet1Image;
    QPixmap* underpassSet2Image;

    //ElementBlock2 images
    QPixmap* switchTight1Image;
    QPixmap* switchTight2Image;
    QPixmap* switchTight3Image;
    QPixmap* switchTight4Image;
    QPixmap* switchTight5Image;
    QPixmap* switchTight6Image;
    QPixmap* switchTight7Image;
    QPixmap* switchTight8Image;
    QPixmap* switchSplit1Image;
    QPixmap* switchSplit2Image;
    QPixmap* switchSplit3Image;

    QPixmap* switch1Image;
    QPixmap* switch2Image;
    QPixmap* switch3Image;
    QPixmap* switch4Image;
    QPixmap* switch5Image;
    QPixmap* switch6Image;
    QPixmap* switch7Image;
    QPixmap* switch8Image;
    QPixmap* switchSplit4Image;
    QPixmap* switchSplit5Image;
    QPixmap* switchSplit6Image;

    QPixmap* switch9Image;
    QPixmap* switch10Image;
    QPixmap* switch11Image;
    QPixmap* switch12Image;
    QPixmap* switch13Image;
    QPixmap* switch14Image;
    QPixmap* switch15Image;
    QPixmap* switch16Image;
    QPixmap* switchSplit7Image;
    QPixmap* switchSplit8Image;

    //ElementBlock3Images
    QPixmap* crossover1Image;
    QPixmap* crossover2Image;
    QPixmap* flyover1Image;
    QPixmap* flyover2Image;
    QPixmap* flyover3Image;
    QPixmap* flyover4Image;

    QPixmap* crossover3Image;
    QPixmap* crossover4Image;
    QPixmap* flyover5Image;
    QPixmap* flyover6Image;
    QPixmap* flyover7Image;
    QPixmap* flyover8Image;

    QPixmap* crossover5Image;
    QPixmap* crossover6Image;
    QPixmap* flyover9Image;
    QPixmap* flyover10Image;
    QPixmap* flyover11Image;
    QPixmap* flyover12Image;

    //ElementBlock4Images
    QPixmap* namedLocationUnsetImage;
    QPixmap* namedLocationSetImage;
    QPixmap* concourseUnsetImage;
    QPixmap* concourseSetImage;
    QPixmap* platformDownUnsetImage;
    QPixmap* platformDownSetImage;
    QPixmap* platformUpUnsetImage;
    QPixmap* platformUpSetImage;
    QPixmap* platformLeftUnsetImage;
    QPixmap* platformLeftSetImage;
    QPixmap* platformRightUnsetImage;
    QPixmap* platformRightSetImage;

    //ElementBlock5Images;
    QPixmap* parapet1Image;
    QPixmap* parapet2Image;
    QPixmap* parapet3Image;
    QPixmap* parapet4Image;
    QPixmap* parapet5Image;
    QPixmap* parapet6Image;
    QPixmap* parapet7Image;
    QPixmap* parapet8Image;
    QPixmap* parapet9Image;
    QPixmap* parapet10Image;

    QPixmap* parapet11Image;
    QPixmap* parapet12Image;
    QPixmap* parapet13Image;
    QPixmap* parapet14Image;
    QPixmap* parapet15Image;
    QPixmap* parapet16Image;
    QPixmap* parapet17Image;
    QPixmap* parapet18Image;
    QPixmap* parapet19Image;
    QPixmap* parapet20Image;

    QPixmap* parapet21Image;
    QPixmap* parapet22Image;
    QPixmap* parapet23Image;
    QPixmap* parapet24Image;
    QPixmap* parapet25Image;
    QPixmap* parapet26Image;
    QPixmap* parapet27Image;
    QPixmap* parapet28Image;

    //ELementBlock6Image
    QPixmap* levelCrossingHImage;
    QPixmap* levelCrossingVImage;



};

#endif // CANVAS_H
