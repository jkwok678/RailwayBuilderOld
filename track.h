#ifndef TRACK_H
#define TRACK_H
#include <string>
#include <iostream>
#include "element.h"




class Track : public Element
{
private:


protected:
    int trackSpeed{200};
    int trackLength{100};
    bool trackLinks [9];



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

#endif // TRACK_H
