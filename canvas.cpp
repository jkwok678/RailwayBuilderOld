#include "canvas.h"

Canvas::Canvas()
{
	setMinimumSize(1280, 800);
	QPalette pal = palette();
	imageSize = 15;
	// set black background
	drawnLayout = new Map;
	pal.setColor(QPalette::Window, Qt::white);

        scene = new QGraphicsScene;
        setScene(scene);

        //ElementBlock1 images
        straightHImage = new QPixmap(":/graphics/graphics/straightH.png");
        straightVImage = new QPixmap(":/graphics/graphics/straightV.png");
        directLeftImage = new QPixmap(":/graphics/graphics/directLeft.png");
        directRightImage = new QPixmap(":/graphics/graphics/directRight.png");
        directUpImage = new QPixmap(":/graphics/graphics/directUp.png");
        directDownImage = new QPixmap(":/graphics/graphics/directDown.png");
        straightLeftUpImage = new QPixmap(":/graphics/graphics/straightLeftUp.png");
        straightRightUpImage = new QPixmap(":/graphics/graphics/straightRightUp.png");
        directLeftUpImage = new QPixmap(":/graphics/graphics/directLeftUp.png");
        directRightUpImage = new QPixmap(":/graphics/graphics/directRightUp.png");
        directRightDownIamge = new QPixmap(":/graphics/graphics/directRightDown.png");
        directLeftDownImage = new QPixmap(":/graphics/graphics/directLeftDown.png");
        tightCurve1Image = new QPixmap(":/graphics/graphics/tightCurve1.png");
        tightCurve2Image = new QPixmap(":/graphics/graphics/tightCurve2.png");
        tightCurve3Image = new QPixmap(":/graphics/graphics/tightCurve3.png");
        tightCurve4Image = new QPixmap(":/graphics/graphics/tightCurve4.png");
        curve1Image = new QPixmap(":/graphics/graphics/curve1.png");
        curve2Image = new QPixmap(":/graphics/graphics/curve2.png");
        curve3Image = new QPixmap(":/graphics/graphics/curve3.png");
        curve4Image = new QPixmap(":/graphics/graphics/curve4.png");

        linkLeftImage = new QPixmap(":/graphics/graphics/linkLeftUnset.png");
        linkRightImage = new QPixmap(":/graphics/graphics/linkRightUnset.png");
        linkDownImage = new QPixmap(":/graphics/graphics/linkDownUnset.png");
        linkUpImage = new QPixmap(":/graphics/graphics/linkUpUnset.png");
        linkLeftUpImage = new QPixmap(":/graphics/graphics/linkLeftUpUnset.png");
        linkRightUpImage = new QPixmap(":/graphics/graphics/linkRightUpUnset.png");
        linkRightDownImage = new QPixmap(":/graphics/graphics/linkRightDownUnset.png");
        linkLeftDownImage = new QPixmap(":/graphics/graphics/linkLeftDownUnset.png");
        exitLeftImage = new QPixmap(":/graphics/graphics/exitLeft.png");
        exitRightImage = new QPixmap(":/graphics/graphics/exitRight.png");
        exitDownImage = new QPixmap(":/graphics/graphics/exitDown.png");
        exitUpImage = new QPixmap(":/graphics/graphics/exitUp.png");
        exitLeftUpImage = new QPixmap(":/graphics/graphics/exitLeftUp.png");
        exitRightUpImage = new QPixmap(":/graphics/graphics/exitRightUp.png");
        exitLeftDownImage = new QPixmap(":/graphics/graphics/exitLeftDown.png");
        exitRightDownImage = new QPixmap(":/graphics/graphics/exitRightDown.png");
        curve5Image = new QPixmap(":/graphics/graphics/curve5.png");
        curve6Image = new QPixmap(":/graphics/graphics/curve6.png");
        curve7Image = new QPixmap(":/graphics/graphics/curve7.png");
        curve8Image = new QPixmap(":/graphics/graphics/curve8.png");

        bufferLeftImage = new QPixmap(":/graphics/graphics/bufferLeft.png");
        bufferRightImage = new QPixmap(":/graphics/graphics/bufferRight.png");
        bufferDownImage = new QPixmap(":/graphics/graphics/bufferDown.png");
        bufferUpImage = new QPixmap(":/graphics/graphics/bufferUp.png");
        bufferLeftUpImage = new QPixmap(":/graphics/graphics/bufferLeftUp.png");
        bufferRightUpImage = new QPixmap(":/graphics/graphics/bufferRightUp.png");
        bufferLeftDownImage = new QPixmap(":/graphics/graphics/bufferLeftDown.png");
        bufferRightDownImage = new QPixmap(":/graphics/graphics/bufferRightDown.png");
        signalLeftImage = new QPixmap(":/graphics/graphics/signalLeft.png");
        signalRightImage = new QPixmap(":/graphics/graphics/signalRight.png");
        signalDownImage = new QPixmap(":/graphics/graphics/signalDown.png");
        signalUpImage = new QPixmap(":/graphics/graphics/signalUp.png");
        signalLeftUpImage = new QPixmap(":/graphics/graphics/signalLeftUp.png");
        signalRightUpImage = new QPixmap(":/graphics/graphics/signalRightUp.png");
        signalLeftDownImage = new QPixmap(":/graphics/graphics/signalLeftDown.png");
        signalRightDownImage = new QPixmap(":/graphics/graphics/signalRightDown.png");
        shuntLeftImage = new QPixmap(":/graphics/graphics/shuntLeftRed.png");
        shuntRightImage = new QPixmap(":/graphics/graphics/shuntRightRed.png");
        shuntDownImage = new QPixmap(":/graphics/graphics/shuntDownRed.png");
        shuntUpImage = new QPixmap(":/graphics/graphics/shuntUpRed.png");
        shuntLeftUpImage = new QPixmap(":/graphics/graphics/shuntLeftUpRed.png");
        shuntRightUpImage = new QPixmap(":/graphics/graphics/shuntRightUpRed.png");
        shuntLeftDownImage = new QPixmap(":/graphics/graphics/shuntLeftDownRed.png");
        shuntRightDownImage = new QPixmap(":/graphics/graphics/shuntRightDownRed.png");
    bridgeUnset1Image = new QPixmap(":/graphics/graphics/bridgeUnset1.png");
    bridgeUnset2Image = new QPixmap(":/graphics/graphics/bridgeUnset2.png");
    underpassUnset1Image = new QPixmap(":/graphics/graphics/underpassUnset1.png");
    underpassUnset2Image = new QPixmap(":/graphics/graphics/underpassUnset2.png");
    bridgeSet1Image = new QPixmap(":/graphics/graphics/brdigeSet1.png");
    bridgeSet2Image = new QPixmap(":/graphics/graphics/bridgeSet2.png");
    underpassSet1Image = new QPixmap(":/graphics/graphics/underpassSet1.png");
    underpassSet2Image = new QPixmap(":/graphics/graphics/underpassSet2.png");

    //ElementBlock2 images
    switchTight1Image = new QPixmap(":/graphics/graphics/switchTight1.png");
    switchTight2Image = new QPixmap(":/graphics/graphics/switchTight2.png");
    switchTight3Image = new QPixmap(":/graphics/graphics/switchTight3.png");
    switchTight4Image = new QPixmap(":/graphics/graphics/switchTight4.png");
    switchTight5Image = new QPixmap(":/graphics/graphics/switchTight5.png");
    switchTight6Image = new QPixmap(":/graphics/graphics/switchTight6.png");
    switchTight7Image = new QPixmap(":/graphics/graphics/switchTight7.png");
    switchTight8Image = new QPixmap(":/graphics/graphics/switchTight8.png");
    switchSplit1Image = new QPixmap(":/graphics/graphics/switchSplit1.png");
    switchSplit2Image = new QPixmap(":/graphics/graphics/switchSplit2.png");
    switchSplit3Image = new QPixmap(":/graphics/graphics/switchSplit3.png");

    switch1Image = new QPixmap(":/graphics/graphics/switch1.png");
    switch2Image = new QPixmap(":/graphics/graphics/switch2.png");
    switch3Image = new QPixmap(":/graphics/graphics/switch3.png");
    switch4Image = new QPixmap(":/graphics/graphics/switch4.png");
    switch5Image = new QPixmap(":/graphics/graphics/switch5.png");
    switch6Image = new QPixmap(":/graphics/graphics/switch6.png");
    switch7Image = new QPixmap(":/graphics/graphics/switch7.png");
    switch8Image = new QPixmap(":/graphics/graphics/switch8.png");
    switchSplit4Image = new QPixmap(":/graphics/graphics/switchSplit4.png");
    switchSplit5Image = new QPixmap(":/graphics/graphics/switchSplit5.png");
    switchSplit6Image = new QPixmap(":/graphics/graphics/switchSplit6.png");

    switch9Image = new QPixmap(":/graphics/graphics/switch9.png");
    switch10Image = new QPixmap(":/graphics/graphics/switch10.png");
    switch11Image = new QPixmap(":/graphics/graphics/switch11.png");
    switch12Image = new QPixmap(":/graphics/graphics/switch12.png");
    switch13Image = new QPixmap(":/graphics/graphics/switch13.png");
    switch14Image = new QPixmap(":/graphics/graphics/switch14.png");
    switch15Image = new QPixmap(":/graphics/graphics/switch15.png");
    switch16Image = new QPixmap(":/graphics/graphics/switch16.png");
    switchSplit7Image = new QPixmap(":/graphics/graphics/switchSplit7.png");
    switchSplit8Image = new QPixmap(":/graphics/graphics/switchSplit8.png");

    //ElementBlock3 images
    crossover1Image = new QPixmap(":/graphics/graphics/crossover1.png");
    crossover2Image = new QPixmap(":/graphics/graphics/crossover2.png");
    flyover1Image = new QPixmap(":/graphics/graphics/flyover1.png");
    flyover2Image = new QPixmap(":/graphics/graphics/flyover2.png");
    flyover3Image = new QPixmap(":/graphics/graphics/flyover3.png");
    flyover4Image = new QPixmap(":/graphics/graphics/flyover4.png");

    crossover3Image = new QPixmap(":/graphics/graphics/crossover3.png");
    crossover4Image = new QPixmap(":/graphics/graphics/crossover4.png");
    flyover5Image = new QPixmap(":/graphics/graphics/flyover5.png");
    flyover6Image = new QPixmap(":/graphics/graphics/flyover6.png");
    flyover7Image = new QPixmap(":/graphics/graphics/flyover7.png");
    flyover8Image = new QPixmap(":/graphics/graphics/flyover8.png");

    crossover5Image = new QPixmap(":/graphics/graphics/crossover5.png");
    crossover6Image = new QPixmap(":/graphics/graphics/crossover6.png");
    flyover9Image = new QPixmap(":/graphics/graphics/flyover9.png");
    flyover10Image = new QPixmap(":/graphics/graphics/flyover10.png");
    flyover11Image = new QPixmap(":/graphics/graphics/flyover11.png");
    flyover12Image = new QPixmap(":/graphics/graphics/flyover12.png");

    //ElementBlock4 images
    namedLocationUnsetImage = new QPixmap(":/graphics/graphics/namedLocationUnset.png");
    namedLocationSetImage = new QPixmap(":/graphics/graphics/namedLocationSet.png");
    concourseUnsetImage = new QPixmap(":/graphics/graphics/concourseUnset.png");
    concourseSetImage = new QPixmap(":/graphics/graphics/concourseSet.png");
    platformDownUnsetImage = new QPixmap(":/graphics/graphics/platformDownUnset.png");
    platformDownSetImage = new QPixmap(":/graphics/graphics/platformDownSet.png");
    platformUpUnsetImage = new QPixmap(":/graphics/graphics/platformUpUnset.png");
    platformUpSetImage = new QPixmap(":/graphics/graphics/platformUpSet.png");
    platformLeftUnsetImage = new QPixmap(":/graphics/graphics/platformLeftUnset.png");
    platformLeftSetImage = new QPixmap(":/graphics/graphics/platformLeftSet.png");
    platformRightUnsetImage = new QPixmap(":/graphics/graphics/platformRightUnset.png");
    platformRightSetImage = new QPixmap(":/graphics/graphics/platformRightSet.png");

    //ElementBlock5 images
    parapet1Image = new QPixmap(":/graphics/graphics/parapet1.png");
    parapet2Image = new QPixmap(":/graphics/graphics/parapet2.png");
    parapet3Image = new QPixmap(":/graphics/graphics/parapet3.png");
    parapet4Image = new QPixmap(":/graphics/graphics/parapet4.png");
    parapet5Image = new QPixmap(":/graphics/graphics/parapet5.png");
    parapet6Image = new QPixmap(":/graphics/graphics/parapet6.png");
    parapet7Image = new QPixmap(":/graphics/graphics/parapet7.png");
    parapet8Image = new QPixmap(":/graphics/graphics/parapet8.png");
    parapet9Image = new QPixmap(":/graphics/graphics/parapet9.png");
    parapet10Image = new QPixmap(":/graphics/graphics/parapet10.png");

    parapet11Image = new QPixmap(":/graphics/graphics/parapet11.png");
    parapet12Image = new QPixmap(":/graphics/graphics/parapet12.png");
    parapet13Image = new QPixmap(":/graphics/graphics/parapet13.png");
    parapet14Image = new QPixmap(":/graphics/graphics/parapet14.png");
    parapet15Image = new QPixmap(":/graphics/graphics/parapet15.png");
    parapet16Image = new QPixmap(":/graphics/graphics/parapet16.png");
    parapet17Image = new QPixmap(":/graphics/graphics/parapet17.png");
    parapet18Image = new QPixmap(":/graphics/graphics/parapet18.png");
    parapet19Image = new QPixmap(":/graphics/graphics/parapet19.png");
    parapet20Image = new QPixmap(":/graphics/graphics/parapet20.png");

    parapet21Image = new QPixmap(":/graphics/graphics/parapet21.png");
    parapet22Image = new QPixmap(":/graphics/graphics/parapet22.png");
    parapet23Image = new QPixmap(":/graphics/graphics/parapet23.png");
    parapet24Image = new QPixmap(":/graphics/graphics/parapet24.png");
    parapet25Image = new QPixmap(":/graphics/graphics/parapet25.png");
    parapet26Image = new QPixmap(":/graphics/graphics/parapet26.png");
    parapet27Image = new QPixmap(":/graphics/graphics/parapet27.png");
    parapet28Image = new QPixmap(":/graphics/graphics/parapet28.png");

    //ElementBlock6Image
    levelCrossingHImage = new QPixmap(":/graphics/graphics/levelCrossingH.png");
    levelCrossingVImage = new QPixmap(":/graphics/graphics/levelCrossingV.png");

    setAutoFillBackground(true);
	setPalette(pal);
}

ElementType Canvas::getElementType()
{
	return *canvasChosen;
}

void Canvas::setElementType(ElementType& newChosen)
{
	canvasChosen = &newChosen;
}

Map Canvas::getMap()
{
	return *drawnLayout;
}

void Canvas::setMap(Map& map)
{
	drawnLayout = &map;
}

int Canvas::getImageSize() const
{
	return imageSize;
}

void Canvas::setImageSize(int newImageSize)
{
	imageSize = newImageSize;
}
bool Canvas::getModified() const
{
	return modified;
}

void Canvas::setModified(bool newModified)
{
	modified = newModified;
}

int Canvas::getOffsetX() const
{
	return offsetX;
}

void Canvas::setOffsetX(int& newOffsetX)
{
	offsetX = newOffsetX;
}

int Canvas::getOffsetY() const
{
	return offsetY;
}

void Canvas::setOffsetY(int& newOffsetY)
{
	offsetY = newOffsetY;
}

int Canvas::getAspect() const
{
	return canvasAspect;
}

void Canvas::setAspect(int& newAspect)
{
	canvasAspect = newAspect;
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
	lastPoint = event->pos();
	exactX = event->pos().x();
	exactY = event->pos().y();
	extraX = exactX % 16;
	extraY = exactY % 16;
	finalX = exactX - extraX;
	finalY = exactY - extraY;


	if (event->button() == Qt::LeftButton) {

		boundX = finalX + imageSize;
		boundY = finalY + imageSize;

		switch (*canvasChosen) {
		case ElementType::NONE:
		{
            QMessageBox noELementSelected;
            noELementSelected.setIcon(QMessageBox::Critical);
            noELementSelected.setText("No element has been selected.");
            noELementSelected.exec();
			break;
		}
		case ElementType::STRAIGHTH:
		{
			std::shared_ptr<StraightTrack> straightH(new StraightTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addStraightTrack(straightH);

			break;
		}
		case ElementType::STRAIGHTV:
		{
			std::shared_ptr<StraightTrack> straightV(new StraightTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addStraightTrack(straightV);
			break;
		}
		case ElementType::DIRECTLEFT:
		{
			std::shared_ptr<DirectTrack> directLeft(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directLeft);
			break;
		}
		case ElementType::DIRECTRIGHT:
		{
			std::shared_ptr<DirectTrack> directRight(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directRight);
			break;
		}
		case ElementType::DIRECTUP:
		{
			std::shared_ptr<DirectTrack> directUp(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directUp);
			break;
		}
		case ElementType::DIRECTDOWN:
		{
			std::shared_ptr<DirectTrack> directDown(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directDown);
			break;
		}
		case ElementType::STRIAGHTRIGHTUP:
		{
			std::shared_ptr<StraightTrack> straightRightUp(new StraightTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addStraightTrack(straightRightUp);
			break;
		}
		case ElementType::STRAIGHTLEFTUP:
		{
			std::shared_ptr<StraightTrack> straightLeftUp(new StraightTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addStraightTrack(straightLeftUp);
			break;
		}
		case ElementType::DIRECTRIGHTUP:
		{
			std::shared_ptr<DirectTrack> directRightUp(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directRightUp);
			break;
		}
		case ElementType::DIRECTLEFTUP:
		{
			std::shared_ptr<DirectTrack> directLeftUp(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directLeftUp);
			break;
		}
		case ElementType::DIRECTLEFTDOWN:
		{
			std::shared_ptr<DirectTrack> directLeftDown(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directLeftDown);
			break;
		}
		case ElementType::DIRECTRIGHTDOWN:
		{
			std::shared_ptr<DirectTrack> directRightDown(new DirectTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addDirectTrack(directRightDown);
			break;
		}

        case ElementType::TIGHTCURVE1:
		{
            std::shared_ptr<CurvedTrack> tightCurve1(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(tightCurve1);
			break;
		}
		case ElementType::TIGHTCURVE2:
		{
			std::shared_ptr<CurvedTrack> tightCurve2(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(tightCurve2);
			break;
		}
		case ElementType::TIGHTCURVE3:
		{
			std::shared_ptr<CurvedTrack> tightCurve3(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(tightCurve3);
			break;
		}
		case ElementType::TIGHTCURVE4:
		{
			std::shared_ptr<CurvedTrack> tightCurve4(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(tightCurve4);
			break;
		}
		case ElementType::CURVE1:
		{
			std::shared_ptr<CurvedTrack> curve1(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve1);
			break;
		}
		case ElementType::CURVE2:
		{
			std::shared_ptr<CurvedTrack> curve2(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve2);
			break;
		}
		case ElementType::CURVE3:
		{
			std::shared_ptr<CurvedTrack> curve3(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve3);
			break;
		}
		case ElementType::CURVE4:
		{
			std::shared_ptr<CurvedTrack> curve4(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve4);
			break;
		}

		case ElementType::LINKLEFT:
		{
			std::shared_ptr<LinkedTrack> linkLeft(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkLeft);
			break;
		}
		case ElementType::LINKRIGHT:
		{
			std::shared_ptr<LinkedTrack> linkRight(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkRight);
			break;
		}
		case ElementType::LINKDOWN:
		{
			std::shared_ptr<LinkedTrack> linkDown(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkDown);
			break;
		}
		case ElementType::LINKUP:
		{
			std::shared_ptr<LinkedTrack> linkUp(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkUp);
			break;
		}
		case ElementType::LINKLEFTUP:
		{
			std::shared_ptr<LinkedTrack> linkLeftUp(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkLeftUp);
			break;
		}
		case ElementType::LINKRIGHTUP:
		{
			std::shared_ptr<LinkedTrack> linkRightUp(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkRightUp);
			break;
		}
		case ElementType::LINKRIGHTDOWN:
		{
			std::shared_ptr<LinkedTrack> linkRightDown(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkRightDown);
			break;
		}
		case ElementType::LINKLEFTDOWN:
		{
			std::shared_ptr<LinkedTrack> linkLeftDown(new LinkedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addLinkedTrack(linkLeftDown);
			break;
		}

		case ElementType::EXITLEFT:
		{
			std::shared_ptr<ExitTrack> exitLeft(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitLeft);
			break;
		}
		case ElementType::EXITRIGHT:
		{
			std::shared_ptr<ExitTrack> exitRight(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitRight);
			break;
		}
		case ElementType::EXITDOWN:
		{
			std::shared_ptr<ExitTrack> exitDown(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitDown);
			break;
		}
		case ElementType::EXITUP:
		{
			std::shared_ptr<ExitTrack> exitUp(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitUp);
			break;
		}

		case ElementType::EXITLEFTUP:
		{
			std::shared_ptr<ExitTrack> exitLeftUp(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitLeftUp);
			break;
		}
		case ElementType::EXITRIGHTUP:
		{
			std::shared_ptr<ExitTrack> exitRightUp(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitRightUp);
			break;
		}

		case ElementType::EXITLEFTDOWN:
		{
			std::shared_ptr<ExitTrack> exitLeftDown(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitLeftDown);
			break;
		}
		case ElementType::EXITRIGHTDOWN:
		{
			std::shared_ptr<ExitTrack> exitRightDown(new ExitTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addExitTrack(exitRightDown);
			break;
		}

		case ElementType::CURVE5:
		{
			std::shared_ptr<CurvedTrack> curve5(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve5);
			break;
		}
		case ElementType::CURVE6:
		{
			std::shared_ptr<CurvedTrack> curve6(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve6);
			break;
		}
		case ElementType::CURVE7:
		{
			std::shared_ptr<CurvedTrack> curve7(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve7);
			break;
		}
		case ElementType::CURVE8:
		{
			std::shared_ptr<CurvedTrack> curve8(new CurvedTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addCurvedTrack(curve8);
			break;
		}

		case ElementType::BUFFERLEFT:
		{
			std::shared_ptr<BufferTrack> bufferLeft(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferLeft);
			break;
		}
		case ElementType::BUFFERRIGHT:
		{
			std::shared_ptr<BufferTrack> bufferRight(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferRight);
			break;
		}
		case ElementType::BUFFERDOWN:
		{
			std::shared_ptr<BufferTrack> bufferDown(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferDown);
			break;
		}
		case ElementType::BUFFERUP:
		{
			std::shared_ptr<BufferTrack> bufferUp(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferUp);
			break;
		}
		case ElementType::BUFFERLEFTUP:
		{
			std::shared_ptr<BufferTrack> bufferLeftUp(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferLeftUp);
			break;
		}
		case ElementType::BUFFERRIGHTUP:
		{
			std::shared_ptr<BufferTrack> bufferRightUp(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferRightUp);
			break;
		}
		case ElementType::BUFFERLEFTDOWN:
		{
			std::shared_ptr<BufferTrack> bufferLeftDown(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferLeftDown);
			break;
		}
		case ElementType::BUFFERRIGHTDOWN:
		{
			std::shared_ptr<BufferTrack> bufferRightDown(new BufferTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
			drawnLayout->addBufferTrack(bufferRightDown);
			break;
		}
		case ElementType::SIGNALLEFT:
		{
			std::shared_ptr<SignalTrack> signalLeft(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalLeft);
			break;
		}
		case ElementType::SIGNALRIGHT:
		{
			std::shared_ptr<SignalTrack> signalRight(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalRight);
			break;
		}
		case ElementType::SIGNALDOWN:
		{
			std::shared_ptr<SignalTrack> signalDown(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalDown);
			break;
		}
		case ElementType::SIGNALUP:
		{
			std::shared_ptr<SignalTrack> signalUp(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalUp);
			break;
		}

		case ElementType::SIGNALLEFTUP:
		{
			std::shared_ptr<SignalTrack> signalLeftUp(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalLeftUp);
			break;
		}
		case ElementType::SIGNALRIGHTUP:
		{
			std::shared_ptr<SignalTrack> signalRightUp(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalRightUp);
			break;
		}

		case ElementType::SIGNALLEFTDOWN:
		{
			std::shared_ptr<SignalTrack> signalLeftDown(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalLeftDown);
			break;
		}
		case ElementType::SIGNALRIGHTDOWN:
		{
			std::shared_ptr<SignalTrack> signalRightDown(new SignalTrack(*canvasChosen, canvasAspect, offsetX, offsetY, finalX, finalY));
			drawnLayout->addSignalTrack(signalRightDown);
			break;
		}

        case ElementType::BRIDGE1:
        {
            std::shared_ptr<BridgeUnderpassTrack> bridge1(new BridgeUnderpassTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addBridgeUnderpassTrack(bridge1);
            break;
        }
        case ElementType::BRIDGE2:
        {
            std::shared_ptr<BridgeUnderpassTrack> bridge2(new BridgeUnderpassTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addBridgeUnderpassTrack(bridge2);
            break;
        }
        case ElementType::UNDERPASS1:
        {
            std::shared_ptr<BridgeUnderpassTrack> underpass1(new BridgeUnderpassTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addBridgeUnderpassTrack(underpass1);
            break;
        }
        case ElementType::UNDERPASS2:
        {
            std::shared_ptr<BridgeUnderpassTrack> underpass2(new BridgeUnderpassTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addBridgeUnderpassTrack(underpass2);
            break;
        }
        case ElementType::SWITCHTIGHT1:
        {
            std::shared_ptr<SwitchTrack> switchTight1(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight1);
            break;
        }
        case ElementType::SWITCHTIGHT2:
        {
            std::shared_ptr<SwitchTrack> switchTight2(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight2);
            break;
        }
        case ElementType::SWITCHTIGHT3:
        {
            std::shared_ptr<SwitchTrack> switchTight3(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight3);
            break;
        }
        case ElementType::SWITCHTIGHT4:
        {
            std::shared_ptr<SwitchTrack> switchTight4(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight4);
            break;
        }
        case ElementType::SWITCHTIGHT5:
        {
            std::shared_ptr<SwitchTrack> switchTight5(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight5);
            break;
        }
        case ElementType::SWITCHTIGHT6:
        {
            std::shared_ptr<SwitchTrack> switchTight6(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight6);
            break;
        }
        case ElementType::SWITCHTIGHT7:
        {
            std::shared_ptr<SwitchTrack> switchTight7(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight7);
            break;
        }
        case ElementType::SWITCHTIGHT8:
        {
            std::shared_ptr<SwitchTrack> switchTight8(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchTight8);
            break;
        }

        case ElementType::SWITCHSPLIT1:
        {
            std::shared_ptr<SwitchTrack> switchSplit1(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit1);
            break;
        }
        case ElementType::SWITCHSPLIT2:
        {
            std::shared_ptr<SwitchTrack> switchSplit2(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit2);
            break;
        }
        case ElementType::SWITCHSPLIT3:
        {
            std::shared_ptr<SwitchTrack> switchSplit3(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit3);
            break;
        }
        case ElementType::SWITCH1:
        {
            std::shared_ptr<SwitchTrack> switch1(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch1);
            break;
        }
        case ElementType::SWITCH2:
        {
            std::shared_ptr<SwitchTrack> switch2(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch2);
            break;
        }
        case ElementType::SWITCH3:
        {
            std::shared_ptr<SwitchTrack> switch3(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch3);
            break;
        }
        case ElementType::SWITCH4:
        {
            std::shared_ptr<SwitchTrack> switch4(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch4);
            break;
        }
        case ElementType::SWITCH5:
        {
            std::shared_ptr<SwitchTrack> switch5(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch5);
            break;
        }
        case ElementType::SWITCH6:
        {
            std::shared_ptr<SwitchTrack> switch6(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch6);
            break;
        }
        case ElementType::SWITCH7:
        {
            std::shared_ptr<SwitchTrack> switch7(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch7);
            break;
        }
        case ElementType::SWITCH8:
        {
            std::shared_ptr<SwitchTrack> switch8(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch8);
            break;
        }
        case ElementType::SWITCHSPLIT4:
        {
            std::shared_ptr<SwitchTrack> switchSplit4(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit4);
            break;
        }
        case ElementType::SWITCHSPLIT5:
        {
            std::shared_ptr<SwitchTrack> switchSplit4(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit4);
            break;
        }
        case ElementType::SWITCHSPLIT6:
        {
            std::shared_ptr<SwitchTrack> switchSplit5(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit5);
            break;
        }
        case ElementType::SWITCH9:
        {
            std::shared_ptr<SwitchTrack> switch9(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch9);
            break;
        }
        case ElementType::SWITCH10:
        {
            std::shared_ptr<SwitchTrack> switch10(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch10);
            break;
        }
        case ElementType::SWITCH11:
        {
            std::shared_ptr<SwitchTrack> switch11(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch11);
            break;
        }
        case ElementType::SWITCH12:
        {
            std::shared_ptr<SwitchTrack> switch12(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch12);
            break;
        }
        case ElementType::SWITCH13:
        {
            std::shared_ptr<SwitchTrack> switch13(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch13);
            break;
        }
        case ElementType::SWITCH14:
        {
            std::shared_ptr<SwitchTrack> switch14(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch14);
            break;
        }
        case ElementType::SWITCH15:
        {
            std::shared_ptr<SwitchTrack> switch15(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch15);
            break;
        }
        case ElementType::SWITCH16:
        {
            std::shared_ptr<SwitchTrack> switch16(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switch16);
            break;
        }
        case ElementType::SWITCHSPLIT7:
        {
            std::shared_ptr<SwitchTrack> switchSplit7(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit7);
            break;
        }
        case ElementType::SWITCHSPLIT8:
        {
            std::shared_ptr<SwitchTrack> switchSplit8(new SwitchTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addSwitchTrack(switchSplit8);
            break;
        }
        case ElementType::CROSSOVER1:
        {
            std::shared_ptr<CrossoverTrack> crossover1(new CrossoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addCrossoverTrack(crossover1);
            break;
        }
        case ElementType::CROSSOVER2:
        {
            std::shared_ptr<CrossoverTrack> crossover2(new CrossoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addCrossoverTrack(crossover2);
            break;
        }
        case ElementType::FLYOVER1:
        {
            std::shared_ptr<FlyoverTrack> flyover1(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover1);
            break;
        }
        case ElementType::FLYOVER2:
        {
            std::shared_ptr<FlyoverTrack> flyover2(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover2);
            break;
        }
        case ElementType::FLYOVER3:
        {
            std::shared_ptr<FlyoverTrack> flyover3(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover3);
            break;
        }
        case ElementType::FLYOVER4:
        {
            std::shared_ptr<FlyoverTrack> flyover4(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover4);
            break;
        }
        case ElementType::CROSSOVER3:
        {
            std::shared_ptr<CrossoverTrack> crossover3(new CrossoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addCrossoverTrack(crossover3);
            break;
        }
        case ElementType::CROSSOVER4:
        {
            std::shared_ptr<CrossoverTrack> crossover4(new CrossoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addCrossoverTrack(crossover4);
            break;
        }
        case ElementType::FLYOVER5:
        {
            std::shared_ptr<FlyoverTrack> flyover5(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover5);
            break;
        }
        case ElementType::FLYOVER6:
        {
            std::shared_ptr<FlyoverTrack> flyover6(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover6);
            break;
        }
        case ElementType::FLYOVER7:
        {
            std::shared_ptr<FlyoverTrack> flyover7(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover7);
            break;
        }
        case ElementType::FLYOVER8:
        {
            std::shared_ptr<FlyoverTrack> flyover8(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover8);
            break;
        }
        case ElementType::CROSSOVER5:
        {
            std::shared_ptr<CrossoverTrack> crossover5(new CrossoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addCrossoverTrack(crossover5);
            break;
        }
        case ElementType::CROSSOVER6:
        {
            std::shared_ptr<CrossoverTrack> crossover6(new CrossoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addCrossoverTrack(crossover6);
            break;
        }
        case ElementType::FLYOVER9:
        {
            std::shared_ptr<FlyoverTrack> flyover9(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover9);
            break;
        }
        case ElementType::FLYOVER10:
        {
            std::shared_ptr<FlyoverTrack> flyover10(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover10);
            break;
        }
        case ElementType::FLYOVER11:
        {
            std::shared_ptr<FlyoverTrack> flyover11(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover11);
            break;
        }
        case ElementType::FLYOVER12:
        {
            std::shared_ptr<FlyoverTrack> flyover12(new FlyoverTrack(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addFlyoverTrack(flyover12);
            break;
        }
        case ElementType::NAMEDLOCATION:
        {
            std::shared_ptr<NamedLocation> namedLocation(new NamedLocation(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addNamedLocation(namedLocation);
            break;
        }
        case ElementType::CONCOURSE:
        {
            std::shared_ptr<Concourse> concourse(new Concourse(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addConcourse(concourse);
            break;
        }
        case ElementType::PLATFORMUP:
        {
            drawnLayout->addPlatform(Platform::UP,offsetX, offsetY,finalX, finalY);
            break;
        }

        case ElementType::PLATFORMDOWN:
        {
            drawnLayout->addPlatform(Platform::DOWN,offsetX, offsetY,finalX, finalY);
            break;
        }
        case ElementType::PLATFORMLEFT:
        {
            drawnLayout->addPlatform(Platform::LEFT,offsetX, offsetY,finalX, finalY);
            break;
        }
        case ElementType::PLATFORMRIGHT:
        {
            drawnLayout->addPlatform(Platform::RIGHT,offsetX, offsetY,finalX, finalY);
            break;
        }
        case ElementType::PARAPET1:
        {
            std::shared_ptr<Parapet> parapet1(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet1);
            break;
        }
        case ElementType::PARAPET2:
        {
            std::shared_ptr<Parapet> parapet2(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet2);
            break;
        }
        case ElementType::PARAPET3:
        {
            std::shared_ptr<Parapet> parapet3(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet3);
            break;
        }
        case ElementType::PARAPET4:
        {
            std::shared_ptr<Parapet> parapet4(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet4);
            break;
        }
        case ElementType::PARAPET5:
        {
            std::shared_ptr<Parapet> parapet5(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet5);
            break;
        }
        case ElementType::PARAPET6:
        {
            std::shared_ptr<Parapet> parapet6(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet6);
            break;
        }
        case ElementType::PARAPET7:
        {
            std::shared_ptr<Parapet> parapet7(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet7);
            break;
        }
        case ElementType::PARAPET8:
        {
            std::shared_ptr<Parapet> parapet8(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet8);
            break;
        }
        case ElementType::PARAPET9:
        {
            std::shared_ptr<Parapet> parapet9(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet9);
            break;
        }
        case ElementType::PARAPET10:
        {
            std::shared_ptr<Parapet> parapet10(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet10);
            break;
        }
        case ElementType::PARAPET11:
        {
            std::shared_ptr<Parapet> parapet11(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet11);
            break;
        }
        case ElementType::PARAPET12:
        {
            std::shared_ptr<Parapet> parapet12(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet12);
            break;
        }
        case ElementType::PARAPET13:
        {
            std::shared_ptr<Parapet> parapet13(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet13);
            break;
        }
        case ElementType::PARAPET14:
        {
            std::shared_ptr<Parapet> parapet14(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet14);
            break;
        }
        case ElementType::PARAPET15:
        {
            std::shared_ptr<Parapet> parapet15(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet15);
            break;
        }
        case ElementType::PARAPET16:
        {
            std::shared_ptr<Parapet> parapet16(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet16);
            break;
        }
        case ElementType::PARAPET17:
        {
            std::shared_ptr<Parapet> parapet17(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet17);
            break;
        }
        case ElementType::PARAPET18:
        {
            std::shared_ptr<Parapet> parapet18(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet18);
            break;
        }
        case ElementType::PARAPET19:
        {
            std::shared_ptr<Parapet> parapet19(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet19);
            break;
        }
        case ElementType::PARAPET20:
        {
            std::shared_ptr<Parapet> parapet20(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet20);
            break;
        }
        case ElementType::PARAPET21:
        {
            std::shared_ptr<Parapet> parapet21(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet21);
            break;
        }
        case ElementType::PARAPET22:
        {
            std::shared_ptr<Parapet> parapet22(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet22);
            break;
        }
        case ElementType::PARAPET23:
        {
            std::shared_ptr<Parapet> parapet23(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet23);
            break;
        }
        case ElementType::PARAPET24:
        {
            std::shared_ptr<Parapet> parapet24(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet24);
            break;
        }
        case ElementType::PARAPET25:
        {
            std::shared_ptr<Parapet> parapet25(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet25);
            break;
        }
        case ElementType::PARAPET26:
        {
            std::shared_ptr<Parapet> parapet26(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet26);
            break;
        }
        case ElementType::PARAPET27:
        {
            std::shared_ptr<Parapet> parapet27(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet27);
            break;
        }
        case ElementType::PARAPET28:
        {
            std::shared_ptr<Parapet> parapet28(new Parapet(*canvasChosen, offsetX, offsetY, finalX, finalY));
            drawnLayout->addParapet(parapet28);
            break;
        }
        case ElementType::LEVELCROSSING:
        {
            drawnLayout->addLevelCrossing(offsetX, offsetY, finalX, finalY);
        }

        }
        update();
        redraw();
	}
	else

		update();


}



void Canvas::redraw()
{
    scene->clear();
    for (std::shared_ptr<StraightTrack> currentElement : drawnLayout->getStraightTrackList()) {
        if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {
            switch (currentElement->getElementType()) {
                case ElementType::STRAIGHTH:
                    QGraphicsPixmapItem *a = scene->addPixmap(*straightHImage);
                    a->setPos(currentElement->getLocationX(), currentElement->getLocationY());
                    /*if (currentElement->getPlatform1()) {
                        painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *platformUpUnsetImage);
                    }
                    if (currentElement->getPlatform2()) {
                        painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *platformDownUnsetImage);
                    }
                    if (currentElement->hasLevelCrossing()) {
                        painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *levelCrossingHImage);
                    }
                    break;

                case ElementType::STRAIGHTV:
                    painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightVImage);
                    if (currentElement->getPlatform1()==true) {
                        painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *platformLeftUnsetImage);
                    }
                    if (currentElement->getPlatform2()==true) {
                        painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *platformRightUnsetImage);
                    }
                    if (currentElement->hasLevelCrossing()) {
                        painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *levelCrossingVImage);
                    }
                    break;

                        case ElementType::STRIAGHTRIGHTUP:
                                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightRightUpImage);
                                break;

                        case ElementType::STRAIGHTLEFTUP:
                                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightLeftUpImage);
                                break;
                        }

                }*/
    viewport()->update();
            }
        }
    }
}







