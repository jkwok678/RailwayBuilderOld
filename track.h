#ifndef TRACK_H
#define TRACK_H
#include <string>
#include <iostream>
#include "element.h"

class Track : public Element
{
private:


protected:
	int trackSpeed{ 200 };
	int trackLength{ 100 };
	bool trackLinks[9];



public:
	Track();
};

class StraightTrack : public Track
{
private:




protected:


public:
	StraightTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);
	~StraightTrack();
};

class DirectTrack : public Track
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

class BufferTrack : public Track
{
private:




protected:


public:
	BufferTrack(ElementType newElementType, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);

};

class SignalTrack : public Track
{
private:
	int aspect;




protected:


public:
	SignalTrack(ElementType newElementType, int newAspect, int newOffsetX, int newOffsetY, int newLocationX, int newLocationY);
	int getAspect() const;
	void setAspect(int newAspect);

};

class BridgeUnderpassTrack : public Track
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
#endif // TRACK_H
