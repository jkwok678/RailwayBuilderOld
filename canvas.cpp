#include "canvas.h"

Canvas::Canvas()
{
	setMinimumSize(1280, 800);
	QPalette pal = palette();
	imageSize = 15;
	// set black background
	drawnLayout = new Map;
	pal.setColor(QPalette::Window, Qt::white);

    //TrackBlock1 images
	straightHImage = new QImage(":/graphics/graphics/straightH.png");
	straightVImage = new QImage(":/graphics/graphics/straightV.png");
	directLeftImage = new QImage(":/graphics/graphics/directLeft.png");
	directRightImage = new QImage(":/graphics/graphics/directRight.png");
	directUpImage = new QImage(":/graphics/graphics/directUp.png");
	directDownImage = new QImage(":/graphics/graphics/directDown.png");
	straightLeftUpImage = new QImage(":/graphics/graphics/straightLeftUp.png");
	straightRightUpImage = new QImage(":/graphics/graphics/straightRightUp.png");
	directLeftUpImage = new QImage(":/graphics/graphics/directLeftUp.png");
	directRightUpImage = new QImage(":/graphics/graphics/directRightUp.png");
	directRightDownIamge = new QImage(":/graphics/graphics/directRightDown.png");
	directLeftDownImage = new QImage(":/graphics/graphics/directLeftDown.png");
	tightCurve1Image = new QImage(":/graphics/graphics/tightCurve1.png");
	tightCurve2Image = new QImage(":/graphics/graphics/tightCurve2.png");
	tightCurve3Image = new QImage(":/graphics/graphics/tightCurve3.png");
	tightCurve4Image = new QImage(":/graphics/graphics/tightCurve4.png");
	curve1Image = new QImage(":/graphics/graphics/curve1.png");
	curve2Image = new QImage(":/graphics/graphics/curve2.png");
	curve3Image = new QImage(":/graphics/graphics/curve3.png");
	curve4Image = new QImage(":/graphics/graphics/curve4.png");

	linkLeftImage = new QImage(":/graphics/graphics/linkLeftUnset.png");
	linkRightImage = new QImage(":/graphics/graphics/linkRightUnset.png");
	linkDownImage = new QImage(":/graphics/graphics/linkDownUnset.png");
	linkUpImage = new QImage(":/graphics/graphics/linkUpUnset.png");
	linkLeftUpImage = new QImage(":/graphics/graphics/linkLeftUpUnset.png");
	linkRightUpImage = new QImage(":/graphics/graphics/linkRightUpUnset.png");
	linkRightDownImage = new QImage(":/graphics/graphics/linkRightDownUnset.png");
	linkLeftDownImage = new QImage(":/graphics/graphics/linkLeftDownUnset.png");
	exitLeftImage = new QImage(":/graphics/graphics/exitLeft.png");
	exitRightImage = new QImage(":/graphics/graphics/exitRight.png");
	exitDownImage = new QImage(":/graphics/graphics/exitDown.png");
	exitUpImage = new QImage(":/graphics/graphics/exitUp.png");
	exitLeftUpImage = new QImage(":/graphics/graphics/exitLeftUp.png");
	exitRightUpImage = new QImage(":/graphics/graphics/exitRightUp.png");
	exitLeftDownImage = new QImage(":/graphics/graphics/exitLeftDown.png");
	exitRightDownImage = new QImage(":/graphics/graphics/exitRightDown.png");
	curve5Image = new QImage(":/graphics/graphics/curve5.png");
	curve6Image = new QImage(":/graphics/graphics/curve6.png");
	curve7Image = new QImage(":/graphics/graphics/curve7.png");
	curve8Image = new QImage(":/graphics/graphics/curve8.png");

	bufferLeftImage = new QImage(":/graphics/graphics/bufferLeft.png");
	bufferRightImage = new QImage(":/graphics/graphics/bufferRight.png");
	bufferDownImage = new QImage(":/graphics/graphics/bufferDown.png");
	bufferUpImage = new QImage(":/graphics/graphics/bufferUp.png");
	bufferLeftUpImage = new QImage(":/graphics/graphics/bufferLeftUp.png");
	bufferRightUpImage = new QImage(":/graphics/graphics/bufferRightUp.png");
	bufferLeftDownImage = new QImage(":/graphics/graphics/bufferLeftDown.png");
	bufferRightDownImage = new QImage(":/graphics/graphics/bufferRightDown.png");
	signalLeftImage = new QImage(":/graphics/graphics/signalLeft.png");
	signalRightImage = new QImage(":/graphics/graphics/signalRight.png");
	signalDownImage = new QImage(":/graphics/graphics/signalDown.png");
	signalUpImage = new QImage(":/graphics/graphics/signalUp.png");
	signalLeftUpImage = new QImage(":/graphics/graphics/signalLeftUp.png");
	signalRightUpImage = new QImage(":/graphics/graphics/signalRightUp.png");
	signalLeftDownImage = new QImage(":/graphics/graphics/signalLeftDown.png");
	signalRightDownImage = new QImage(":/graphics/graphics/signalRightDown.png");
	shuntLeftImage = new QImage(":/graphics/graphics/shuntLeftRed.png");
	shuntRightImage = new QImage(":/graphics/graphics/shuntRightRed.png");
	shuntDownImage = new QImage(":/graphics/graphics/shuntDownRed.png");
	shuntUpImage = new QImage(":/graphics/graphics/shuntUpRed.png");
	shuntLeftUpImage = new QImage(":/graphics/graphics/shuntLeftUpRed.png");
	shuntRightUpImage = new QImage(":/graphics/graphics/shuntRightUpRed.png");
	shuntLeftDownImage = new QImage(":/graphics/graphics/shuntLeftDownRed.png");
	shuntRightDownImage = new QImage(":/graphics/graphics/shuntRightDownRed.png");
    bridgeUnset1Image = new QImage(":/graphics/graphics/bridgeUnset1.png");
    bridgeUnset2Image = new QImage(":/graphics/graphics/bridgeUnset2.png");
    underpassUnset1Image = new QImage(":/graphics/graphics/underpassUnset1.png");
    underpassUnset2Image = new QImage(":/graphics/graphics/underpassUnset2.png");
    bridgeSet1Image = new QImage(":/graphics/graphics/brdigeSet1.png");
    bridgeSet2Image = new QImage(":/graphics/graphics/bridgeSet2.png");
    underpassSet1Image = new QImage(":/graphics/graphics/underpassSet1.png");
    underpassSet2Image = new QImage(":/graphics/graphics/underpassSet2.png");

    //TrackBlock2 images
    switchTight1Image = new QImage(":/graphics/graphics/switchTight1.png");
    switchTight2Image = new QImage(":/graphics/graphics/switchTight2.png");
    switchTight3Image = new QImage(":/graphics/graphics/switchTight3.png");
    switchTight4Image = new QImage(":/graphics/graphics/switchTight4.png");
    switchTight5Image = new QImage(":/graphics/graphics/switchTight5.png");
    switchTight6Image = new QImage(":/graphics/graphics/switchTight6.png");
    switchTight7Image = new QImage(":/graphics/graphics/switchTight7.png");
    switchTight8Image = new QImage(":/graphics/graphics/switchTight8.png");
    switchSplit1Image = new QImage(":/graphics/graphics/switchSplit1.png");
    switchSplit2Image = new QImage(":/graphics/graphics/switchSplit2.png");
    switchSplit3Image = new QImage(":/graphics/graphics/switchSplit3.png");

    switch1Image = new QImage(":/graphics/graphics/switch1.png");
    switch2Image = new QImage(":/graphics/graphics/switch2.png");
    switch3Image = new QImage(":/graphics/graphics/switch3.png");
    switch4Image = new QImage(":/graphics/graphics/switch4.png");
    switch5Image = new QImage(":/graphics/graphics/switch5.png");
    switch6Image = new QImage(":/graphics/graphics/switch6.png");
    switch7Image = new QImage(":/graphics/graphics/switch7.png");
    switch8Image = new QImage(":/graphics/graphics/switch8.png");
    switchSplit4Image = new QImage(":/graphics/graphics/switchSplit4.png");
    switchSplit5Image = new QImage(":/graphics/graphics/switchSplit5.png");
    switchSplit6Image = new QImage(":/graphics/graphics/switchSplit6.png");

    switch9Image = new QImage(":/graphics/graphics/switch9.png");
    switch10Image = new QImage(":/graphics/graphics/switch10.png");
    switch11Image = new QImage(":/graphics/graphics/switch11.png");
    switch12Image = new QImage(":/graphics/graphics/switch12.png");
    switch13Image = new QImage(":/graphics/graphics/switch13.png");
    switch14Image = new QImage(":/graphics/graphics/switch14.png");
    switch15Image = new QImage(":/graphics/graphics/switch15.png");
    switch16Image = new QImage(":/graphics/graphics/switch16.png");
    switchSplit7Image = new QImage(":/graphics/graphics/switchSplit7.png");
    switchSplit8Image = new QImage(":/graphics/graphics/switchSplit8.png");

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
			std::cout << offsetX << std::flush;

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
            std::cout << "Hiii" << std::flush;
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



		}
        update();

	}
	else

		update();


}

void Canvas::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	for (auto& currentElement : drawnLayout->getStraightTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {

			switch (currentElement->getElementType()) {

			case ElementType::STRAIGHTH:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightHImage);
				break;

			case ElementType::STRAIGHTV:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightVImage);
				break;

			case ElementType::STRIAGHTRIGHTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightRightUpImage);
				break;

			case ElementType::STRAIGHTLEFTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *straightLeftUpImage);
				break;
			}

		}



	}
	for (auto& currentElement : drawnLayout->getDirectTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {

			switch (currentElement->getElementType()) {
			case ElementType::DIRECTLEFT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directLeftImage);
				break;

			case ElementType::DIRECTRIGHT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directRightImage);
				break;
			case ElementType::DIRECTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directUpImage);
				break;
			case ElementType::DIRECTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directDownImage);
				break;
			case ElementType::DIRECTRIGHTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directRightUpImage);
				break;
			case ElementType::DIRECTLEFTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directLeftUpImage);
				break;
			case ElementType::DIRECTLEFTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directLeftDownImage);
				break;
			case ElementType::DIRECTRIGHTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *directRightDownIamge);
				break;
			}

		}

	}
	for (auto& currentElement : drawnLayout->getCurvedTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {

			switch (currentElement->getElementType()) {
			case ElementType::TIGHTCURVE1:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *tightCurve1Image);
				break;

			case ElementType::TIGHTCURVE2:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *tightCurve2Image);
				break;
			case ElementType::TIGHTCURVE3:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *tightCurve3Image);
				break;

			case ElementType::TIGHTCURVE4:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *tightCurve4Image);
				break;
			case ElementType::CURVE1:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve1Image);
				break;

			case ElementType::CURVE2:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve2Image);
				break;
			case ElementType::CURVE3:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve3Image);
				break;

			case ElementType::CURVE4:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve4Image);
				break;
			case ElementType::CURVE5:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve5Image);
				break;

			case ElementType::CURVE6:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve6Image);
				break;
			case ElementType::CURVE7:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve7Image);
				break;

			case ElementType::CURVE8:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *curve8Image);
				break;
			}

		}
	}
	for (auto& currentElement : drawnLayout->getLinkedTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {
			switch (currentElement->getElementType()) {

			case ElementType::LINKLEFT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkLeftImage);
				break;

			case ElementType::LINKRIGHT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkRightImage);
				break;
			case ElementType::LINKDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkDownImage);
				break;

			case ElementType::LINKUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkUpImage);
				break;

			case ElementType::LINKLEFTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkLeftUpImage);
				break;

			case ElementType::LINKRIGHTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkRightUpImage);
				break;
			case ElementType::LINKRIGHTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkRightDownImage);
				break;

			case ElementType::LINKLEFTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *linkLeftDownImage);
				break;


			}

		}
	}
	for (auto& currentElement : drawnLayout->getExitTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {
			switch (currentElement->getElementType()) {
			case ElementType::EXITLEFT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitLeftImage);
				break;

			case ElementType::EXITRIGHT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitRightImage);
				break;
			case ElementType::EXITDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitDownImage);
				break;

			case ElementType::EXITUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitUpImage);
				break;

			case ElementType::EXITLEFTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitLeftUpImage);
				break;

			case ElementType::EXITRIGHTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitRightUpImage);
				break;

			case ElementType::EXITLEFTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitLeftDownImage);
				break;

			case ElementType::EXITRIGHTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *exitRightDownImage);
				break;

			}


		}

	}

	for (auto& currentElement : drawnLayout->getBufferTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {
			switch (currentElement->getElementType()) {
			case ElementType::BUFFERLEFT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferLeftImage);
				break;

			case ElementType::BUFFERRIGHT:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferRightImage);
				break;
			case ElementType::BUFFERDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferDownImage);
				break;

			case ElementType::BUFFERUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferUpImage);
				break;

			case ElementType::BUFFERLEFTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferLeftUpImage);
				break;

			case ElementType::BUFFERRIGHTUP:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferRightUpImage);
				break;
			case ElementType::BUFFERLEFTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferLeftDownImage);
				break;

			case ElementType::BUFFERRIGHTDOWN:
				painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bufferRightDownImage);
				break;
			}
		}
	}

	for (auto& currentElement : drawnLayout->getSignalTrackList()) {

		if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {

			switch (currentElement->getElementType()) {
			case ElementType::SIGNALLEFT:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntLeftImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalLeftImage);
				}
				break;

			case ElementType::SIGNALRIGHT:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntRightImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalRightImage);
				}break;
			case ElementType::SIGNALDOWN:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntDownImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalDownImage);
				}break;

			case ElementType::SIGNALUP:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntUpImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalUpImage);
				}break;

			case ElementType::SIGNALLEFTUP:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntLeftUpImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalLeftUpImage);
				}break;

			case ElementType::SIGNALRIGHTUP:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntRightUpImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalRightUpImage);
				}break;
			case ElementType::SIGNALLEFTDOWN:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntLeftDownImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalLeftDownImage);
				}break;

			case ElementType::SIGNALRIGHTDOWN:
				if (currentElement->getAspect() == 1)
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *shuntRightDownImage);
				}
				else
				{
					painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *signalRightDownImage);
				}break;

			}



		}

	}
    for (auto& currentElement : drawnLayout->getBridgeUnderpassTrackList()) {

        if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {

            switch (currentElement->getElementType()) {
            case ElementType::BRIDGE1:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bridgeUnset1Image);
                break;

            case ElementType::BRIDGE2:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *bridgeUnset2Image);
                break;
            case ElementType::UNDERPASS1:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *underpassUnset1Image);
                break;

            case ElementType::UNDERPASS2:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *underpassUnset2Image);
                break;
            }
        }
    }

    for (auto& currentElement : drawnLayout->getSwitchTrackList()) {

        if (offsetX == currentElement->getOffsetX() && offsetY == currentElement->getOffsetY()) {

            switch (currentElement->getElementType()) {
            case ElementType::SWITCHTIGHT1:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight1Image);
                break;

            case ElementType::SWITCHTIGHT2:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight2Image);
                break;
            case ElementType::SWITCHTIGHT3:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight3Image);
                break;

            case ElementType::SWITCHTIGHT4:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight4Image);
                break;

            case ElementType::SWITCHTIGHT5:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight5Image);
                break;

            case ElementType::SWITCHTIGHT6:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight6Image);
                break;
            case ElementType::SWITCHTIGHT7:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight7Image);
                break;

            case ElementType::SWITCHTIGHT8:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchTight8Image);
                break;

            case ElementType::SWITCHSPLIT1:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit1Image);
                break;

            case ElementType::SWITCHSPLIT2:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit2Image);
                break;
            case ElementType::SWITCHSPLIT3:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit3Image);
                break;
            case ElementType::SWITCH1:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch1Image);
                break;

            case ElementType::SWITCH2:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch2Image);
                break;
            case ElementType::SWITCH3:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch3Image);
                break;

            case ElementType::SWITCH4:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch4Image);
                break;

            case ElementType::SWITCH5:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch5Image);
                break;

            case ElementType::SWITCH6:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch6Image);
                break;
            case ElementType::SWITCH7:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch7Image);
                break;

            case ElementType::SWITCH8:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch8Image);
                break;
            case ElementType::SWITCHSPLIT4:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit4Image);
                break;

            case ElementType::SWITCHSPLIT5:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit5Image);
                break;
            case ElementType::SWITCHSPLIT6:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit6Image);
                break;
            case ElementType::SWITCH9:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch9Image);
                break;

            case ElementType::SWITCH10:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch10Image);
                break;
            case ElementType::SWITCH11:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch11Image);
                break;

            case ElementType::SWITCH12:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch12Image);
                break;

            case ElementType::SWITCH13:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch13Image);
                break;

            case ElementType::SWITCH14:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch14Image);
                break;
            case ElementType::SWITCH15:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch15Image);
                break;

            case ElementType::SWITCH16:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switch16Image);
                break;
            case ElementType::SWITCHSPLIT7:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit7Image);
                break;

            case ElementType::SWITCHSPLIT8:
                painter.drawImage(currentElement->getLocationX(), currentElement->getLocationY(), *switchSplit8Image);
                break;
            }
        }
    }
}







