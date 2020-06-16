#ifndef TRACK_H
#define TRACK_H
#include <string>
#include <iostream>
#include "element.h"

enum class Platform {
	LEFT, UP, RIGHT, DOWN, LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN
};

class Track : public Element
{
private:


protected:
	int trackSpeed{ 200 };
	int trackLength{ 100 };
	bool trackLinks[9];
	//For vertical tracks, platform1 is left, platform2 is right
	//For Horizontal tracks platform1 is up, platform2 is down
	bool platform1;
	bool platform2;




public:
	Track();
	bool getPlatform1() const;
	void setPlatform1(bool newPlatform);
	bool getPlatform2() const;
	void setPlatform2(bool newPlatform);
};

class StraightTrack : public Track
{
private:
	bool levelCrossing;


protected:




public:
	StraightTrack();
	StraightTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);
	~StraightTrack();
	bool hasLevelCrossing() const;
	void addLevelCrossing();



};

class DirectTrack : public StraightTrack
{
private:




protected:


public:
	DirectTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class CurvedTrack : public Track
{
private:




protected:


public:
	CurvedTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class LinkedTrack : public Track
{
private:




protected:


public:
	LinkedTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class ExitTrack : public Track
{
private:




protected:


public:
	ExitTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class BufferTrack : public StraightTrack
{
private:




protected:


public:
	BufferTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class SignalTrack : public StraightTrack
{
private:
	int aspect;




protected:


public:
	SignalTrack(ElementType newElementType, int newAspect, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);
	int getAspect() const;
	void setAspect(int newAspect);

};

class BridgeUnderpassTrack : public StraightTrack
{
private:




protected:


public:
	BridgeUnderpassTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class SwitchTrack : public Track
{
private:




protected:


public:
	SwitchTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class CrossoverTrack : public Track
{
private:




protected:


public:
	CrossoverTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class FlyoverTrack : public Track
{
private:




protected:


public:
	FlyoverTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

#endif // TRACK_H
