#ifndef MAP_H
#define MAP_H
#include <vector>
#include <memory>
#include  "element.h"
#include "track.h"

class Map
{
private:
    std::vector<std::shared_ptr<StraightTrack>> straightTrackList;
    std::vector<std::shared_ptr<DirectTrack>> directTrackList;
    std::vector<std::shared_ptr<CurvedTrack>> curvedTrackList;
    std::vector<std::shared_ptr<LinkedTrack>> linkedTrackList;
    std::vector<std::shared_ptr<ExitTrack>> exitTrackList;
    std::vector<std::shared_ptr<BufferTrack>> bufferTrackList;
    std::vector<std::shared_ptr<SignalTrack>> signalTrackList;


public:
    Map();

    void addElement(std::shared_ptr<Element> newElement);



    std::vector<std::shared_ptr<StraightTrack> > getStraightTrackList() const;
    void setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> > &newStraightTrackList);
    void addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack);


    std::vector<std::shared_ptr<DirectTrack> > getDirectTrackList() const;
    void setDirectTrackList(const std::vector<std::shared_ptr<DirectTrack> > &newDirectTrackList);
    void addDirectTrack(std::shared_ptr<DirectTrack> newDirectTrack);


    std::vector<std::shared_ptr<CurvedTrack> > getCurvedTrackList() const;
    void setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> > &newCurvedTrackList);
    void addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack);

    std::vector<std::shared_ptr<LinkedTrack> > getLinkedTrackList() const;
    void setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> > &newLinkedTrackList);
    void addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack);

    std::vector<std::shared_ptr<ExitTrack> > getExitTrackList() const;
    void setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> > &newExitTrackList);
    void addExitTrack(std::shared_ptr<ExitTrack> newExitTrack);

    std::vector<std::shared_ptr<BufferTrack> > getBufferTrackList() const;
    void setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> > &newBufferTrackList);
    void addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack);

    std::vector<std::shared_ptr<SignalTrack> > getSignalTrackList() const;
    void setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> > &newSignalTrackList);
    void addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack);

    std::shared_ptr<Element> getElementAt(int offsetX, int offsetY, int locationX, int locationY);
    bool checkElementExists(int offsetX, int offsetY, int locationX, int locationY);
    bool deleteElement(int locationX, int locationY);
};

#endif // MAP_H
