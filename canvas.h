#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QInputDialog>
#include <QTimer>
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

    QFont getCurrentFont() const;
    void setCurrentFont(QFont& newFont);


public slots:

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


private:
	ElementType* canvasChosen;

	Map* drawnLayout;
	int imageSize;
	bool modified = false;
    int offsetX;
    int offsetY;
    int canvasSizeX;
    int canvasSizeY;
	int canvasAspect;
    bool canvasShowTrackID;
    bool canvasShowMoreTrackInfo;
    QFont currentFont;
    std::shared_ptr<Text> moveText;



	//ElementBlock1 images
	QImage* straightHImage;
	QImage* straightVImage;
	QImage* directLeftImage;
	QImage* directRightImage;
	QImage* directUpImage;
	QImage* directDownImage;
	QImage* straightRightUpImage;
	QImage* straightLeftUpImage;
	QImage* directRightUpImage;
	QImage* directLeftUpImage;
	QImage* directLeftDownImage;
	QImage* directRightDownIamge;
	QImage* tightCurve1Image;
	QImage* tightCurve2Image;
	QImage* tightCurve3Image;
	QImage* tightCurve4Image;
	QImage* curve1Image;
	QImage* curve2Image;
	QImage* curve3Image;
	QImage* curve4Image;
	QImage* linkLeftImage;
	QImage* linkRightImage;
	QImage* linkDownImage;
	QImage* linkUpImage;
	QImage* linkLeftUpImage;
	QImage* linkRightUpImage;
	QImage* linkRightDownImage;
	QImage* linkLeftDownImage;
	QImage* exitLeftImage;
	QImage* exitRightImage;
	QImage* exitDownImage;
	QImage* exitUpImage;
	QImage* exitLeftUpImage;
	QImage* exitRightUpImage;
	QImage* exitLeftDownImage;
	QImage* exitRightDownImage;
	QImage* curve5Image;
	QImage* curve6Image;
	QImage* curve7Image;
	QImage* curve8Image;
	QImage* bufferLeftImage;
	QImage* bufferRightImage;
	QImage* bufferDownImage;
	QImage* bufferUpImage;
	QImage* bufferLeftUpImage;
	QImage* bufferRightUpImage;
	QImage* bufferLeftDownImage;
	QImage* bufferRightDownImage;
	QImage* signalLeftImage;
	QImage* signalRightImage;
	QImage* signalDownImage;
	QImage* signalUpImage;
	QImage* signalLeftUpImage;
	QImage* signalRightUpImage;
	QImage* signalLeftDownImage;
	QImage* signalRightDownImage;
	QImage* shuntLeftImage;
	QImage* shuntRightImage;
	QImage* shuntDownImage;
	QImage* shuntUpImage;
	QImage* shuntLeftUpImage;
	QImage* shuntRightUpImage;
	QImage* shuntLeftDownImage;
	QImage* shuntRightDownImage;
	QImage* bridgeUnset1Image;
	QImage* bridgeUnset2Image;
	QImage* underpassUnset1Image;
	QImage* underpassUnset2Image;
	QImage* bridgeSet1Image;
	QImage* bridgeSet2Image;
	QImage* underpassSet1Image;
	QImage* underpassSet2Image;

	//ElementBlock2 images
	QImage* switchTight1Image;
	QImage* switchTight2Image;
	QImage* switchTight3Image;
	QImage* switchTight4Image;
	QImage* switchTight5Image;
	QImage* switchTight6Image;
	QImage* switchTight7Image;
	QImage* switchTight8Image;
	QImage* switchSplit1Image;
	QImage* switchSplit2Image;
	QImage* switchSplit3Image;

	QImage* switch1Image;
	QImage* switch2Image;
	QImage* switch3Image;
	QImage* switch4Image;
	QImage* switch5Image;
	QImage* switch6Image;
	QImage* switch7Image;
	QImage* switch8Image;
	QImage* switchSplit4Image;
	QImage* switchSplit5Image;
	QImage* switchSplit6Image;

	QImage* switch9Image;
	QImage* switch10Image;
	QImage* switch11Image;
	QImage* switch12Image;
	QImage* switch13Image;
	QImage* switch14Image;
	QImage* switch15Image;
	QImage* switch16Image;
	QImage* switchSplit7Image;
	QImage* switchSplit8Image;

	//ElementBlock3Images
	QImage* crossover1Image;
	QImage* crossover2Image;
	QImage* flyover1Image;
	QImage* flyover2Image;
	QImage* flyover3Image;
	QImage* flyover4Image;

	QImage* crossover3Image;
	QImage* crossover4Image;
	QImage* flyover5Image;
	QImage* flyover6Image;
	QImage* flyover7Image;
	QImage* flyover8Image;

	QImage* crossover5Image;
	QImage* crossover6Image;
	QImage* flyover9Image;
	QImage* flyover10Image;
	QImage* flyover11Image;
	QImage* flyover12Image;

	//ElementBlock4Images
	QImage* namedLocationUnsetImage;
	QImage* namedLocationSetImage;
	QImage* concourseUnsetImage;
	QImage* concourseSetImage;
	QImage* platformDownUnsetImage;
	QImage* platformDownSetImage;
	QImage* platformUpUnsetImage;
	QImage* platformUpSetImage;
	QImage* platformLeftUnsetImage;
	QImage* platformLeftSetImage;
	QImage* platformRightUnsetImage;
	QImage* platformRightSetImage;

	//ElementBlock5Images;
	QImage* parapet1Image;
	QImage* parapet2Image;
	QImage* parapet3Image;
	QImage* parapet4Image;
	QImage* parapet5Image;
	QImage* parapet6Image;
	QImage* parapet7Image;
	QImage* parapet8Image;
	QImage* parapet9Image;
	QImage* parapet10Image;

	QImage* parapet11Image;
	QImage* parapet12Image;
	QImage* parapet13Image;
	QImage* parapet14Image;
	QImage* parapet15Image;
	QImage* parapet16Image;
	QImage* parapet17Image;
	QImage* parapet18Image;
	QImage* parapet19Image;
	QImage* parapet20Image;

	QImage* parapet21Image;
	QImage* parapet22Image;
	QImage* parapet23Image;
	QImage* parapet24Image;
	QImage* parapet25Image;
	QImage* parapet26Image;
	QImage* parapet27Image;
	QImage* parapet28Image;

	//ELementBlock6Image
	QImage* levelCrossingHImage;
	QImage* levelCrossingVImage;

};

#endif // CANVAS_H
