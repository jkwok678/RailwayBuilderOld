#ifndef MODE_H
#define MODE_H

#endif // MODE_H


enum class Mode
{
    NONE, STRAIGHTH, STRAIGHTV, STRAIGHTLEFTUP, STRIAGHTRIGHTUP, DIRECTLEFT, DIRECTRIGHT, DIRECTUP, DIRECTDOWN, DIRECTRIGHTUP,
    DIRECTLEFTUP, DIRECTLEFTDOWN, DIRECTRIGHTDOWN, TIGHTCURVE1, TIGHTCURVE2, TIGHTCURVE3, TIGHTCURVE4, CURVE1, CURVE2, CURVE3,
    CURVE4, CURVE5, CURVE6, CURVE7, CURVE8, LINKLEFT, LINKRIGHT, LINKDOWN, LINKUP, LINKLEFTUP, LINKRIGHTUP, LINKLEFTDOWN,
    LINKRIGHTDOWN, EXITLEFT, EXITRIGHT, EXITDOWN, EXITUP, EXITLEFTUP, EXITRIGHTUP, EXITLEFTDOWN, EXITRIGHTDOWN, BUFFERLEFT, BUFFERRIGHT,
    BUFFERDOWN, BUFFERUP, BUFFERLEFTUP, BUFFERRIGHTUP, BUFFERLEFTDOWN, BUFFERRIGHTDOWN, SIGNALLEFT, SIGNALRIGHT, SIGNALDOWN, SIGNALUP,
    SIGNALLEFTUP, SIGNALRIGHTUP, SIGNALLEFTDOWN, SIGNALRIGHTDOWN, BRIDGE1, BRIDGE2, UNDERPASS1, UNDERPASS2, SWITCHTIGHT1,
    SWITCHTIGHT2, SWITCHTIGHT3, SWITCHTIGHT4, SWITCHTIGHT5, SWITCHTIGHT6, SWITCHTIGHT7, SWITCHTIGHT8, SWITCHSPLIT1, SWITCHSPLIT2,
    SWITCHSPLIT3, SWITCHSPLIT4, SWITCHSPLIT5, SWITCHSPLIT6, SWITCHSPLIT7, SWITCHSPLIT8, SWITCH1, SWITCH2, SWITCH3, SWITCH4, SWITCH5,
    SWITCH6, SWITCH7, SWITCH8, SWITCH9, SWITCH10, SWITCH11, SWITCH12, SWITCH13, SWITCH14, SWITCH15, SWITCH16, CROSSOVER1,
    CROSSOVER2, CROSSOVER3, CROSSOVER4, CROSSOVER5, CROSSOVER6, FLYOVER1, FLYOVER2, FLYOVER3, FLYOVER4, FLYOVER5, FLYOVER6,
    FLYOVER7, FLYOVER8, FLYOVER9, FLYOVER10, FLYOVER11, FLYOVER12, NAMEDLOCATION, CONCOURSE, PLATFORMLEFT, PLATFORMRIGHT,
    PLATFORMDOWN, PLATFORMUP, PARAPET1, PARAPET2, PARAPET3, PARAPET4, PARAPET5, PARAPET6, PARAPET7, PARAPET8, PARAPET9,
    PARAPET10, PARAPET11, PARAPET12, PARAPET13, PARAPET14, PARAPET15, PARAPET16, PARAPET17, PARAPET18, PARAPET19, PARAPET20,
    PARAPET21, PARAPET22, PARAPET23, PARAPET24, PARAPET25, PARAPET26, PARAPET27, PARAPET28, LEVELCROSSING, ADDCHANGETEXT, MOVETEXT,
    SETCHANGENAMEDLOCATION, CONNECTLINKEDTRACK, SETTRACKLENGTHSPEED

};

enum class Colour
{
    LIGHT, DARKBLUE, BLACK
};
