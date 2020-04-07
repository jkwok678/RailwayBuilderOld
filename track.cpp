#include "track.h"
#include "element.h"

Track::Track()
{

};


StraightTrack :: StraightTrack(bool isElectrified, std :: string newElectrificationMethod)
{
    electrified = isElectrified;
    electrificationMethod = newElectrificationMethod;
};
