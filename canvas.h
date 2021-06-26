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


/**
 * @brief The Canvas that is used to draw the tracks on.
 * @author Jonathan Kwok.
 *
 * A class based on QWidget for drawing the layout, by adding the images to the screen.
 */
class Canvas : public QWidget
{
	Q_OBJECT
public:

    /**
     * @brief Canvas constructor.
     */
	Canvas();
    /**
     * @brief A method to load all normal track images from storage.
     */
    void loadAllTrackImages();
    /**
     * @brief A method to load all red track images from storage.
     */
    void loadAllRedTrackImages();
    /**
     * @brief A method to load all green track images from storage.
     */
    void loadAllGreenTrackImages();
    /**
     * @brief A method to load all blue track images from storage.
     */
    void loadAllBlueTrackImages();
    /**
     * @brief A method to load all track images with multiple colours from storage.
     */
    void loadMixColourTrackImages();
    /**
     * @brief A method to add all track images onto a vector.
     */
    void fillImageList();

    /**
     * @brief getMode
     * @return
     */
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

    void checkAllTracks();

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
    QImage* directRightDownImage;
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

    //Red images
    //ElementBlock1 images
    QImage* straightHRedImage;
    QImage* straightVRedImage;
    QImage* directLeftRedImage;
    QImage* directRightRedImage;
    QImage* directUpRedImage;
    QImage* directDownRedImage;
    QImage* straightRightUpRedImage;
    QImage* straightLeftUpRedImage;
    QImage* directRightUpRedImage;
    QImage* directLeftUpRedImage;
    QImage* directLeftDownRedImage;
    QImage* directRightDownRedImage;
    QImage* tightCurve1RedImage;
    QImage* tightCurve2RedImage;
    QImage* tightCurve3RedImage;
    QImage* tightCurve4RedImage;
    QImage* curve1RedImage;
    QImage* curve2RedImage;
    QImage* curve3RedImage;
    QImage* curve4RedImage;
    QImage* linkLeftUnsetRedImage;
    QImage* linkRightUnsetRedImage;
    QImage* linkDownUnsetRedImage;
    QImage* linkUpUnsetRedImage;
    QImage* linkLeftUpUnsetRedImage;
    QImage* linkRightUpUnsetRedImage;
    QImage* linkRightDownUnsetRedImage;
    QImage* linkLeftDownUnsetRedImage;
    QImage* linkLeftSetRedImage;
    QImage* linkRightSetRedImage;
    QImage* linkDownSetRedImage;
    QImage* linkUpSetRedImage;
    QImage* linkLeftUpSetRedImage;
    QImage* linkRightUpSetRedImage;
    QImage* linkRightDownSetRedImage;
    QImage* linkLeftDownSetRedImage;
    QImage* exitLeftRedImage;
    QImage* exitRightRedImage;
    QImage* exitDownRedImage;
    QImage* exitUpRedImage;
    QImage* exitLeftUpRedImage;
    QImage* exitRightUpRedImage;
    QImage* exitLeftDownRedImage;
    QImage* exitRightDownRedImage;
    QImage* curve5RedImage;
    QImage* curve6RedImage;
    QImage* curve7RedImage;
    QImage* curve8RedImage;
    QImage* bufferLeftRedImage;
    QImage* bufferRightRedImage;
    QImage* bufferDownRedImage;
    QImage* bufferUpRedImage;
    QImage* bufferLeftUpRedImage;
    QImage* bufferRightUpRedImage;
    QImage* bufferLeftDownRedImage;
    QImage* bufferRightDownRedImage;
    QImage* signalLeftRedImage;
    QImage* signalRightRedImage;
    QImage* signalDownRedImage;
    QImage* signalUpRedImage;
    QImage* signalLeftUpRedImage;
    QImage* signalRightUpRedImage;
    QImage* signalLeftDownRedImage;
    QImage* signalRightDownRedImage;
    QImage* shuntLeftRedImage;
    QImage* shuntRightRedImage;
    QImage* shuntDownRedImage;
    QImage* shuntUpRedImage;
    QImage* shuntLeftUpRedImage;
    QImage* shuntRightUpRedImage;
    QImage* shuntLeftDownRedImage;
    QImage* shuntRightDownRedImage;
    QImage* bridgeUnset1RedImage;
    QImage* bridgeUnset2RedImage;
    QImage* underpassUnset1RedImage;
    QImage* underpassUnset2RedImage;
    QImage* bridgeSet1RedImage;
    QImage* bridgeSet2RedImage;
    QImage* underpassSet1RedImage;
    QImage* underpassSet2RedImage;

    //ElementBlock2 images
    QImage* switchTight1RedImage;
    QImage* switchTight2RedImage;
    QImage* switchTight3RedImage;
    QImage* switchTight4RedImage;
    QImage* switchTight5RedImage;
    QImage* switchTight6RedImage;
    QImage* switchTight7RedImage;
    QImage* switchTight8RedImage;
    QImage* switchSplit1RedImage;
    QImage* switchSplit2RedImage;
    QImage* switchSplit3RedImage;

    QImage* switch1RedImage;
    QImage* switch2RedImage;
    QImage* switch3RedImage;
    QImage* switch4RedImage;
    QImage* switch5RedImage;
    QImage* switch6RedImage;
    QImage* switch7RedImage;
    QImage* switch8RedImage;
    QImage* switchSplit4RedImage;
    QImage* switchSplit5RedImage;
    QImage* switchSplit6RedImage;

    QImage* switch9RedImage;
    QImage* switch10RedImage;
    QImage* switch11RedImage;
    QImage* switch12RedImage;
    QImage* switch13RedImage;
    QImage* switch14RedImage;
    QImage* switch15RedImage;
    QImage* switch16RedImage;
    QImage* switchSplit7RedImage;
    QImage* switchSplit8RedImage;

    //ElementBlock3Images
    QImage* crossover1RedImage;
    QImage* crossover2RedImage;
    QImage* flyover1RedImage;
    QImage* flyover2RedImage;
    QImage* flyover3RedImage;
    QImage* flyover4RedImage;

    QImage* crossover3RedImage;
    QImage* crossover4RedImage;
    QImage* flyover5RedImage;
    QImage* flyover6RedImage;
    QImage* flyover7RedImage;
    QImage* flyover8RedImage;

    QImage* crossover5RedImage;
    QImage* crossover6RedImage;
    QImage* flyover9RedImage;
    QImage* flyover10RedImage;
    QImage* flyover11RedImage;
    QImage* flyover12RedImage;

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
    QImage* directRightDownGreenImage;
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


    //Blue images
    //ElementBlock1 images
    QImage* straightHBlueImage;
    QImage* straightVBlueImage;
    QImage* directLeftBlueImage;
    QImage* directRightBlueImage;
    QImage* directUpBlueImage;
    QImage* directDownBlueImage;
    QImage* straightRightUpBlueImage;
    QImage* straightLeftUpBlueImage;
    QImage* directRightUpBlueImage;
    QImage* directLeftUpBlueImage;
    QImage* directLeftDownBlueImage;
    QImage* directRightDownBlueImage;
    QImage* tightCurve1BlueImage;
    QImage* tightCurve2BlueImage;
    QImage* tightCurve3BlueImage;
    QImage* tightCurve4BlueImage;
    QImage* curve1BlueImage;
    QImage* curve2BlueImage;
    QImage* curve3BlueImage;
    QImage* curve4BlueImage;
    QImage* linkLeftUnsetBlueImage;
    QImage* linkRightUnsetBlueImage;
    QImage* linkDownUnsetBlueImage;
    QImage* linkUpUnsetBlueImage;
    QImage* linkLeftUpUnsetBlueImage;
    QImage* linkRightUpUnsetBlueImage;
    QImage* linkRightDownUnsetBlueImage;
    QImage* linkLeftDownUnsetBlueImage;
    QImage* linkLeftSetBlueImage;
    QImage* linkRightSetBlueImage;
    QImage* linkDownSetBlueImage;
    QImage* linkUpSetBlueImage;
    QImage* linkLeftUpSetBlueImage;
    QImage* linkRightUpSetBlueImage;
    QImage* linkRightDownSetBlueImage;
    QImage* linkLeftDownSetBlueImage;
    QImage* exitLeftBlueImage;
    QImage* exitRightBlueImage;
    QImage* exitDownBlueImage;
    QImage* exitUpBlueImage;
    QImage* exitLeftUpBlueImage;
    QImage* exitRightUpBlueImage;
    QImage* exitLeftDownBlueImage;
    QImage* exitRightDownBlueImage;
    QImage* curve5BlueImage;
    QImage* curve6BlueImage;
    QImage* curve7BlueImage;
    QImage* curve8BlueImage;
    QImage* bufferLeftBlueImage;
    QImage* bufferRightBlueImage;
    QImage* bufferDownBlueImage;
    QImage* bufferUpBlueImage;
    QImage* bufferLeftUpBlueImage;
    QImage* bufferRightUpBlueImage;
    QImage* bufferLeftDownBlueImage;
    QImage* bufferRightDownBlueImage;
    QImage* signalLeftBlueImage;
    QImage* signalRightBlueImage;
    QImage* signalDownBlueImage;
    QImage* signalUpBlueImage;
    QImage* signalLeftUpBlueImage;
    QImage* signalRightUpBlueImage;
    QImage* signalLeftDownBlueImage;
    QImage* signalRightDownBlueImage;
    QImage* shuntLeftBlueImage;
    QImage* shuntRightBlueImage;
    QImage* shuntDownBlueImage;
    QImage* shuntUpBlueImage;
    QImage* shuntLeftUpBlueImage;
    QImage* shuntRightUpBlueImage;
    QImage* shuntLeftDownBlueImage;
    QImage* shuntRightDownBlueImage;
    QImage* bridgeUnset1BlueImage;
    QImage* bridgeUnset2BlueImage;
    QImage* underpassUnset1BlueImage;
    QImage* underpassUnset2BlueImage;
    QImage* bridgeSet1BlueImage;
    QImage* bridgeSet2BlueImage;
    QImage* underpassSet1BlueImage;
    QImage* underpassSet2BlueImage;

    //ElementBlock2 images
    QImage* switchTight1BlueImage;
    QImage* switchTight2BlueImage;
    QImage* switchTight3BlueImage;
    QImage* switchTight4BlueImage;
    QImage* switchTight5BlueImage;
    QImage* switchTight6BlueImage;
    QImage* switchTight7BlueImage;
    QImage* switchTight8BlueImage;
    QImage* switchSplit1BlueImage;
    QImage* switchSplit2BlueImage;
    QImage* switchSplit3BlueImage;

    QImage* switch1BlueImage;
    QImage* switch2BlueImage;
    QImage* switch3BlueImage;
    QImage* switch4BlueImage;
    QImage* switch5BlueImage;
    QImage* switch6BlueImage;
    QImage* switch7BlueImage;
    QImage* switch8BlueImage;
    QImage* switchSplit4BlueImage;
    QImage* switchSplit5BlueImage;
    QImage* switchSplit6BlueImage;

    QImage* switch9BlueImage;
    QImage* switch10BlueImage;
    QImage* switch11BlueImage;
    QImage* switch12BlueImage;
    QImage* switch13BlueImage;
    QImage* switch14BlueImage;
    QImage* switch15BlueImage;
    QImage* switch16BlueImage;
    QImage* switchSplit7BlueImage;
    QImage* switchSplit8BlueImage;

    //ElementBlock3Images
    QImage* crossover1BlueImage;
    QImage* crossover2BlueImage;
    QImage* flyover1BlueImage;
    QImage* flyover2BlueImage;
    QImage* flyover3BlueImage;
    QImage* flyover4BlueImage;

    QImage* crossover3BlueImage;
    QImage* crossover4BlueImage;
    QImage* flyover5BlueImage;
    QImage* flyover6BlueImage;
    QImage* flyover7BlueImage;
    QImage* flyover8BlueImage;

    QImage* crossover5BlueImage;
    QImage* crossover6BlueImage;
    QImage* flyover9BlueImage;
    QImage* flyover10BlueImage;
    QImage* flyover11BlueImage;
    QImage* flyover12BlueImage;
};

#endif // CANVAS_H
