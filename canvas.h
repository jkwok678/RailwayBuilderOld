#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QInputDialog>
#include <QTimer>
#include <QColor>
#include <memory>
#include <string>
#include <iostream>
#include "element.h"
#include "map.h"
#include "track.h"
#include "mode.h"



class Canvas : public QWidget
{
	Q_OBJECT
public:

	Canvas();

    void loadAllTrackImages();
    void loadAllRedTrackImages();
    void loadAllGreenTrackImages();
    void loadAllBlueTrackImages();
    void loadMixColourTrackImages();
    void fillImageList();

    Mode getMode();
    void setMode(Mode newChosen);

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

    Colour getCanvasColour() const;
    void setCanvasColour(const Colour & newColour);

    void canvasChangeColour();
    void trackChangeColour();

    bool getGrid() const;
    void setGrid(bool value);

signals:
    void moreTracksAdded();

public slots:

    void stopSetTrackSpeedLength();
    void setTrackSpeedLength(int length, int speed);
    void resetAllTrackSpeedLength();
    void resetSelectedTrackSpeedLength();


protected:
    void mousePressEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


private:
    QPalette pal;
    Colour canvasColour{Colour::LIGHT};
    Mode canvasChosen;

    std::vector<QImage*> imageList;
	Map* drawnLayout;
	int imageSize;
    bool modified{false};
    int offsetX;
    int offsetY;
    int canvasSizeX;
    int canvasSizeY;
	int canvasAspect;
    bool canvasShowTrackID;
    bool canvasShowMoreTrackInfo;
    QFont currentFont;
    std::shared_ptr<Text> moveText;
    bool grid{false};



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
    QImage* linkLeftUnsetImage;
    QImage* linkRightUnsetImage;
    QImage* linkDownUnsetImage;
    QImage* linkUpUnsetImage;
    QImage* linkLeftUpUnsetImage;
    QImage* linkRightUpUnsetImage;
    QImage* linkRightDownUnsetImage;
    QImage* linkLeftDownUnsetImage;
    QImage* linkLeftSetImage;
    QImage* linkRightSetImage;
    QImage* linkDownSetImage;
    QImage* linkUpSetImage;
    QImage* linkLeftUpSetImage;
    QImage* linkRightUpSetImage;
    QImage* linkRightDownSetImage;
    QImage* linkLeftDownSetImage;
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

    //Hints
    QImage* selectRed;
    QImage* selectGreen;
    QImage* selectBlue;

    //Green images
    //ElementBlock1 images
    QImage* straightHGreenImage;
    QImage* straightVGreenImage;
    QImage* directLeftGreenImage;
    QImage* directRightGreenImage;
    QImage* directUpGreenImage;
    QImage* directDownGreenImage;
    QImage* straightRightUpGreenImage;
    QImage* straightLeftUpGreenImage;
    QImage* directRightUpGreenImage;
    QImage* directLeftUpGreenImage;
    QImage* directLeftDownGreenImage;
    QImage* directRightDownGreenIamge;
    QImage* tightCurve1GreenImage;
    QImage* tightCurve2GreenImage;
    QImage* tightCurve3GreenImage;
    QImage* tightCurve4GreenImage;
    QImage* curve1GreenImage;
    QImage* curve2GreenImage;
    QImage* curve3GreenImage;
    QImage* curve4GreenImage;
    QImage* linkLeftUnsetGreenImage;
    QImage* linkRightUnsetGreenImage;
    QImage* linkDownUnsetGreenImage;
    QImage* linkUpUnsetGreenImage;
    QImage* linkLeftUpUnsetGreenImage;
    QImage* linkRightUpUnsetGreenImage;
    QImage* linkRightDownUnsetGreenImage;
    QImage* linkLeftDownUnsetGreenImage;
    QImage* linkLeftSetGreenImage;
    QImage* linkRightSetGreenImage;
    QImage* linkDownSetGreenImage;
    QImage* linkUpSetGreenImage;
    QImage* linkLeftUpSetGreenImage;
    QImage* linkRightUpSetGreenImage;
    QImage* linkRightDownSetGreenImage;
    QImage* linkLeftDownSetGreenImage;
    QImage* exitLeftGreenImage;
    QImage* exitRightGreenImage;
    QImage* exitDownGreenImage;
    QImage* exitUpGreenImage;
    QImage* exitLeftUpGreenImage;
    QImage* exitRightUpGreenImage;
    QImage* exitLeftDownGreenImage;
    QImage* exitRightDownGreenImage;
    QImage* curve5GreenImage;
    QImage* curve6GreenImage;
    QImage* curve7GreenImage;
    QImage* curve8GreenImage;
    QImage* bufferLeftGreenImage;
    QImage* bufferRightGreenImage;
    QImage* bufferDownGreenImage;
    QImage* bufferUpGreenImage;
    QImage* bufferLeftUpGreenImage;
    QImage* bufferRightUpGreenImage;
    QImage* bufferLeftDownGreenImage;
    QImage* bufferRightDownGreenImage;
    QImage* signalLeftGreenImage;
    QImage* signalRightGreenImage;
    QImage* signalDownGreenImage;
    QImage* signalUpGreenImage;
    QImage* signalLeftUpGreenImage;
    QImage* signalRightUpGreenImage;
    QImage* signalLeftDownGreenImage;
    QImage* signalRightDownGreenImage;
    QImage* shuntLeftGreenImage;
    QImage* shuntRightGreenImage;
    QImage* shuntDownGreenImage;
    QImage* shuntUpGreenImage;
    QImage* shuntLeftUpGreenImage;
    QImage* shuntRightUpGreenImage;
    QImage* shuntLeftDownGreenImage;
    QImage* shuntRightDownGreenImage;
    QImage* bridgeUnset1GreenImage;
    QImage* bridgeUnset2GreenImage;
    QImage* underpassUnset1GreenImage;
    QImage* underpassUnset2GreenImage;
    QImage* bridgeSet1GreenImage;
    QImage* bridgeSet2GreenImage;
    QImage* underpassSet1GreenImage;
    QImage* underpassSet2GreenImage;

    //ElementBlock2 images
    QImage* switchTight1GreenImage;
    QImage* switchTight2GreenImage;
    QImage* switchTight3GreenImage;
    QImage* switchTight4GreenImage;
    QImage* switchTight5GreenImage;
    QImage* switchTight6GreenImage;
    QImage* switchTight7GreenImage;
    QImage* switchTight8GreenImage;
    QImage* switchSplit1GreenImage;
    QImage* switchSplit2GreenImage;
    QImage* switchSplit3GreenImage;

    QImage* switch1GreenImage;
    QImage* switch2GreenImage;
    QImage* switch3GreenImage;
    QImage* switch4GreenImage;
    QImage* switch5GreenImage;
    QImage* switch6GreenImage;
    QImage* switch7GreenImage;
    QImage* switch8GreenImage;
    QImage* switchSplit4GreenImage;
    QImage* switchSplit5GreenImage;
    QImage* switchSplit6GreenImage;

    QImage* switch9GreenImage;
    QImage* switch10GreenImage;
    QImage* switch11GreenImage;
    QImage* switch12GreenImage;
    QImage* switch13GreenImage;
    QImage* switch14GreenImage;
    QImage* switch15GreenImage;
    QImage* switch16GreenImage;
    QImage* switchSplit7GreenImage;
    QImage* switchSplit8GreenImage;

    //ElementBlock3Images
    QImage* crossover1GreenImage;
    QImage* crossover2GreenImage;
    QImage* flyover1GreenImage;
    QImage* flyover2GreenImage;
    QImage* flyover3GreenImage;
    QImage* flyover4GreenImage;

    QImage* crossover3GreenImage;
    QImage* crossover4GreenImage;
    QImage* flyover5GreenImage;
    QImage* flyover6GreenImage;
    QImage* flyover7GreenImage;
    QImage* flyover8GreenImage;

    QImage* crossover5GreenImage;
    QImage* crossover6GreenImage;
    QImage* flyover9GreenImage;
    QImage* flyover10GreenImage;
    QImage* flyover11GreenImage;
    QImage* flyover12GreenImage;

};

#endif // CANVAS_H
