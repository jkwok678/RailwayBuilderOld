#ifndef TRACK_H
#define TRACK_H
#include <string>
#include <iostream>
#include "element.h"

enum class StraightType
{
    STRAIGHTH, STRAIGHTV, STRAIGHTLEFTUP, STRIAGHTRIGHTUP
};

enum class DirectType
{
    DIRECTLEFT, DIRECTRIGHT, DIRECTUP, DIRECTDOWN, DIRECTRIGHTUP,
    DIRECTLEFTUP, DIRECTLEFTDOWN, DIRECTRIGHTDOWN
};

enum class CurvedType
{
    TIGHTCURVE1, TIGHTCURVE2, TIGHTCURVE3, TIGHTCURVE4, CURVE1, CURVE2, CURVE3,
    CURVE4, CURVE5, CURVE6, CURVE7, CURVE8
};

enum class LinkedType
{
    LINKLEFT, LINKRIGHT, LINKDOWN, LINKUP, LINKLEFTUP, LINKRIGHTUP, LINKLEFTDOWN,
    LINKRIGHTDOWN
};

enum class ExitType
{
    EXITLEFT, EXITRIGHT, EXITDOWN, EXITUP, EXITLEFTUP, EXITRIGHTUP, EXITLEFTDOWN, EXITRIGHTDOWN
};

enum class BufferType
{
    BUFFERLEFT, BUFFERRIGHT, BUFFERDOWN, BUFFERUP, BUFFERLEFTUP, BUFFERRIGHTUP, BUFFERLEFTDOWN, BUFFERRIGHTDOWN
};

enum class SignalType
{
    SIGNALLEFT, SIGNALRIGHT, SIGNALDOWN, SIGNALUP, SIGNALLEFTUP, SIGNALRIGHTUP, SIGNALLEFTDOWN, SIGNALRIGHTDOWN
};

enum class BridgeUnderpassType
{
    BRIDGE1, BRIDGE2, UNDERPASS1, UNDERPASS2
};

enum class SwitchType
{
    SWITCHTIGHT1, SWITCHTIGHT2, SWITCHTIGHT3, SWITCHTIGHT4, SWITCHTIGHT5, SWITCHTIGHT6, SWITCHTIGHT7, SWITCHTIGHT8, SWITCHSPLIT1, SWITCHSPLIT2,
    SWITCHSPLIT3, SWITCHSPLIT4, SWITCHSPLIT5, SWITCHSPLIT6, SWITCHSPLIT7, SWITCHSPLIT8, SWITCH1, SWITCH2, SWITCH3, SWITCH4, SWITCH5,
    SWITCH6, SWITCH7, SWITCH8, SWITCH9, SWITCH10, SWITCH11, SWITCH12, SWITCH13, SWITCH14, SWITCH15, SWITCH16
};

enum class CrossoverType
{
    CROSSOVER1, CROSSOVER2, CROSSOVER3, CROSSOVER4, CROSSOVER5, CROSSOVER6
};

enum class FlyoverType
{
    FLYOVER1, FLYOVER2, FLYOVER3, FLYOVER4, FLYOVER5, FLYOVER6, FLYOVER7, FLYOVER8, FLYOVER9, FLYOVER10, FLYOVER11, FLYOVER12
};

enum class Platform {
    LEFT, UP, RIGHT, DOWN
};

class Track : public NamedElement
{
private:


protected:
    int trackMainSpeed{ 200 };
    int trackMainLength{ 100 };
    int trackSecondarySpeed{-1};
    int trackSecondaryLength{-1};
	//For vertical tracks, platform1 is left, platform2 is right
    //For Horizontal tracks platform1 is up, platform2 is down
    bool platformAny{ false };
    bool platform1{ false };
    bool platform2{ false };
    bool links [9]{false, false, false, false, false, false, false, false, false};
    bool found;


public:
	Track();
    int getTrackMainSpeed() const;
    void setTrackMainSpeed(int value);
    int getTrackMainLength() const;
    void setTrackMainLength(int value);
    bool getPlatformAny() const;
    void setPlatformAny(bool value);
	bool getPlatform1() const;
	void setPlatform1(bool newPlatform);
	bool getPlatform2() const;
	void setPlatform2(bool newPlatform);

    bool getLink0();
    bool getLink1();
    bool getLink2();
    bool getLink3();
    bool getLink4();
    bool getLink5();
    bool getLink6();
    bool getLink7();
    bool getLink8();

    bool getFound() const;
    void setFound(bool newFound);
    int getTrackSecondarySpeed() const;
    void setTrackSecondarySpeed(int value);
    int getTrackSecondaryLength() const;
    void setTrackSecondaryLength(int value);
};

class StraightTrack : public Track
{
private:
    StraightType straightType;
    bool levelCrossing{ false };


protected:




public:
	StraightTrack();
    StraightTrack(StraightType newStraightType, int newLocationX, int newLocationY);
	~StraightTrack();
    StraightType getStraightType() const;
    void setStraightType(const StraightType &newStraightType);
	bool hasLevelCrossing() const;
	void addLevelCrossing();




};

class DirectTrack : public StraightTrack
{
private:
    DirectType directType;



protected:


public:
    DirectTrack(DirectType newDirectType, int newLocationX, int newLocationY);
    DirectType getDirectType() const;
    void setDirectType(const DirectType &newDirectType);
};

class CurvedTrack : public Track
{
private:
    CurvedType curvedType;



protected:


public:
    CurvedTrack(CurvedType newCurvedType, int newLocationX, int newLocationY);
    CurvedType getCurvedType() const;
    void setCurvedType(const CurvedType &newCurvedType);
};

class LinkedTrack : public Track
{
private:
    LinkedType linkedType;
    bool linked;
    std::shared_ptr<LinkedTrack> otherLinkTrack{nullptr};



protected:


public:
    LinkedTrack();
    LinkedTrack(LinkedType newLinkedType, int newLocationX, int newLocationY);
    LinkedType getLinkedType() const;
    void setLinkedType(const LinkedType &newLinkedType);
    bool getLinked() const;
    void setLinked(bool newLinked);


    std::shared_ptr<LinkedTrack> getOtherLinkTrack();
    void setOtherLinkTrack(std::shared_ptr<LinkedTrack> &newLinkedTrack);
};

class ExitTrack : public Track
{
private:
    ExitType exitType;



protected:


public:
    ExitTrack(ExitType newExitType, int newLocationX, int newLocationY);
    ExitType getExitType() const;
    void setExitType(const ExitType &newExitType);
};

class BufferTrack : public StraightTrack
{
private:
    BufferType bufferType;



protected:


public:
    BufferTrack(BufferType newBufferType, int newLocationX, int newLocationY);
    BufferType getBufferType() const;
    void setBufferType(const BufferType &newBufferType);
};

class SignalTrack : public StraightTrack
{
private:
    SignalType signalType;
	int aspect;




protected:


public:
    SignalTrack(SignalType newSignalType, int newAspect, int newLocationX, int newLocationY);
	int getAspect() const;
	void setAspect(int newAspect);
    SignalType getSignalType() const;
    void setSignalType(const SignalType &newSignalType);
};

class BridgeUnderpassTrack : public StraightTrack
{
private:
    BridgeUnderpassType bridgeUnderpassType;



protected:


public:
    BridgeUnderpassTrack(BridgeUnderpassType newBridgeUnderpassType, int newLocationX, int newLocationY);
    BridgeUnderpassType getBridgeUnderpassType() const;
    void setBridgeUnderpassType(const BridgeUnderpassType &newBridgeUnderpassType);
};

class SwitchTrack : public Track
{
private:
    SwitchType switchType;



protected:


public:
    SwitchTrack(SwitchType newSwitchType, int newLocationX, int newLocationY);
    SwitchType getSwitchType() const;
    void setSwitchType(const SwitchType &newSwitchType);
};

class CrossoverTrack : public Track
{
private:
    CrossoverType crossoverType;



protected:


public:
    CrossoverTrack(CrossoverType newCrossoverType, int newLocationX, int newLocationY);
    CrossoverType getCrossoverType() const;
    void setCrossoverType(const CrossoverType &newCrossoverType);
};

class FlyoverTrack : public Track
{
private:
    FlyoverType flyoverType;



protected:


public:
    FlyoverTrack(FlyoverType newFlyoverType, int newLocationX, int newLocationY);
    FlyoverType getFlyoverType() const;
    void setFlyoverType(const FlyoverType &newFlyoverType);
};

#endif // TRACK_H
