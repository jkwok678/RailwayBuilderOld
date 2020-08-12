#ifndef MAP_H
#define MAP_H
#include <vector>
#include <memory>
#include <QMessageBox>
#include <thread>
#include <chrono>
#include  "element.h"
#include "track.h"

class Map
{
private:
    int totalTrack{0};
    std::vector<std::shared_ptr<StraightTrack>> straightTrackList;
    std::vector<std::shared_ptr<DirectTrack>> directTrackList;
    std::vector<std::shared_ptr<CurvedTrack>> curvedTrackList;
    std::vector<std::shared_ptr<LinkedTrack>> linkedTrackList;
    std::vector<std::shared_ptr<ExitTrack>> exitTrackList;
    std::vector<std::shared_ptr<BufferTrack>> bufferTrackList;
    std::vector<std::shared_ptr<SignalTrack>> signalTrackList;
    std::vector<std::shared_ptr<BridgeUnderpassTrack>> bridgeUnderpassTrackList;
    std::vector<std::shared_ptr<SwitchTrack>> switchTrackList;
    std::vector<std::shared_ptr<CrossoverTrack>> crossoverTrackList;
    std::vector<std::shared_ptr<FlyoverTrack>> flyoverTrackList;
    std::vector<std::shared_ptr<NamedLocation>> namedLocationList;
    std::vector<std::shared_ptr<Concourse>> concourseList;
    std::vector<std::shared_ptr<Parapet>> parapetList;
    std::vector<std::shared_ptr<Text>> textList;

    std::vector<std::shared_ptr<Track>> trackList;

    std::shared_ptr<LinkedTrack> linkedTrack1{nullptr};
    std::shared_ptr<LinkedTrack> linkedTrack2{nullptr};




    std::shared_ptr<Track> findTopLeftTrack();

    void checkAllLinkTrackLinked();

    bool allLinkedTrackLinked;
    bool allConnected;

    std::shared_ptr<Track> start{nullptr};
    std::shared_ptr<Track> end{nullptr};
    std::vector<std::shared_ptr<Track>> setTrackSpeedLengthList;


    int setTrackSpeedLengthCounter{1000};


public:
    Map();

    int getTotalTrack() const;
    void setTotalTrack(int newTrackTotal);

    std::vector<std::shared_ptr<StraightTrack> > getStraightTrackList() const;
    void setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> >& newStraightTrackList);
    void addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack);
    std::shared_ptr<StraightTrack> getStraightTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<DirectTrack> > getDirectTrackList() const;
    void setDirectTrackList(const std::vector<std::shared_ptr<DirectTrack> >& newDirectTrackList);
    void addDirectTrack(std::shared_ptr<DirectTrack> newDirectTrack);
    std::shared_ptr<DirectTrack> getDirectTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<CurvedTrack> > getCurvedTrackList() const;
    void setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> >& newCurvedTrackList);
    void addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack);
    std::shared_ptr<CurvedTrack> getCurvedTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<LinkedTrack> > getLinkedTrackList() const;
    void setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> >& newLinkedTrackList);
    void addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack);
    std::shared_ptr<LinkedTrack> getLinkedTrackAt(int locationX,int locationY);
    bool haslinkTrackAt(int locationX, int locationY);

    std::vector<std::shared_ptr<ExitTrack> > getExitTrackList() const;
    void setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> >& newExitTrackList);
    void addExitTrack(std::shared_ptr<ExitTrack> newExitTrack);
    std::shared_ptr<ExitTrack> getExitTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<BufferTrack> > getBufferTrackList() const;
    void setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> >& newBufferTrackList);
    void addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack);
    std::shared_ptr<BufferTrack> getBufferTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<SignalTrack> > getSignalTrackList() const;
    void setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> >& newSignalTrackList);
    void addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack);
    std::shared_ptr<SignalTrack> getSignalTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<BridgeUnderpassTrack>> getBridgeUnderpassTrackList() const;
    void setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> >& newBridgeUnderpassTrackList);
    void addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack);
    std::shared_ptr<BridgeUnderpassTrack> getBridgeUnderpassTrack(int locationX,int locationY);

    std::vector<std::shared_ptr<SwitchTrack> > getSwitchTrackList() const;
    void setSwitchTrackList(const std::vector<std::shared_ptr<SwitchTrack> >& newSwitchTrackList);
    void addSwitchTrack(std::shared_ptr<SwitchTrack> newSwitchTrack);
    std::shared_ptr<SwitchTrack> getSwitchTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<CrossoverTrack> > getCrossoverTrackList() const;
    void setCrossoverTrackList(const std::vector<std::shared_ptr<CrossoverTrack> >& newCrossoverTrackList);
    void addCrossoverTrack(std::shared_ptr<CrossoverTrack> newCrossoverTrack);
    std::shared_ptr<CrossoverTrack> getCrossoverTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<FlyoverTrack> > getFlyoverTrackList() const;
    void setFlyoverTrackList(const std::vector<std::shared_ptr<FlyoverTrack> >& newFlyoverTrackList);
    void addFlyoverTrack(std::shared_ptr<FlyoverTrack> newFlyoverTrack);
    std::shared_ptr<FlyoverTrack> getFlyoverTrackAt(int locationX,int locationY);

    std::vector<std::shared_ptr<NamedLocation> > getNamedLocationList() const;
    void setNamedLocationList(const std::vector<std::shared_ptr<NamedLocation> >& newNamedLocationList);
    void addNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation);
    std::shared_ptr<NamedLocation> getNamedLocationAt(int locationX,int locationY);

    std::vector<std::shared_ptr<Concourse> > getConcourseList() const;
    void setConcourseList(const std::vector<std::shared_ptr<Concourse> >& newConcourseList);
    void addConcourse(std::shared_ptr<Concourse> newConcourseTrack);
    std::shared_ptr<Concourse> getConcourseAt(int locationX,int locationY);

    std::vector<std::shared_ptr<Parapet> > getParapetList() const;
    void setParapetList(const std::vector<std::shared_ptr<Parapet> >& newParapetList);
    void addParapet(std::shared_ptr<Parapet> newParapet);
    std::shared_ptr<Parapet> getParapetAt(int locationX,int locationY);

    std::vector<std::shared_ptr<Text> > getTextList() const;
    void setTextList(const std::vector<std::shared_ptr<Text> >& newTextList);
    void addText(std::shared_ptr<Text> newText);


    std::shared_ptr<Element> getElementAt( int locationX, int locationY);
    std::shared_ptr<NamedElement> getNamedElementAt( int locationX, int locationY);
    std::shared_ptr<Track> getTrackAt( int locationX, int locationY);
    std::shared_ptr<Text> getTextAt(int locationX, int locationY);
    bool checkElementExists(int locationX, int locationY);
    bool checkTextExists(int locationX, int locationY);
    bool deleteElement(int locationX, int locationY);
    bool deleteText (std::shared_ptr<Text> textToDelete);
    void deleteTextFromAllElement(std::shared_ptr<Text> textToDelete);

    void addPlatform(Platform side, int locationX, int locationY);
    void addLevelCrossing( int locationX, int locationY);
    void linkLocalText(int locationX, int LocationY, std::shared_ptr<Text> linkedText);
    void linkNewBlockToText(int locationX, int locationY);

    std::shared_ptr<LinkedTrack> getLinkedTrack1() const;
    void setLinkedTrack1(const std::shared_ptr<LinkedTrack> &newLinkedTrack1);
    std::shared_ptr<LinkedTrack> getLinkedTrack2() const;
    void setLinkedTrack2(const std::shared_ptr<LinkedTrack> &newLinkedTrack2);
    void connectLinkedTrack();

    std::vector<std::shared_ptr<Track> > getTrackList() const;
    std::vector<std::shared_ptr<Track>> makeTrackList();
    void setTrackList(const std::vector<std::shared_ptr<Track> > &value);
    void checkAllTracks();

    bool getAllLinkedTrackLinked() const;
    void setAllLinkedTrackLinked(bool newAllLinkedTrackLinked);
    bool getAllConnected() const;
    void setAllConnected(bool newAllConnected);


    std::vector<std::shared_ptr<Track> > getSetTrackSpeedLengthList() const;
    void setSetTrackSpeedLengthList(const std::vector<std::shared_ptr<Track> > &newSetTrackSpeedLengthList);
    void fillSetTrackSpeedLengthList(std::shared_ptr<Track> track);
    void setSectionSpeedLength();
    void addToSetTrackSpeedLengthList(std::shared_ptr<Track> track);
    void resetSetTrackSpeedLengthMechanics();
    void resetFoundForAllTrack();
    std::shared_ptr<Track> getStart() const;
    void setStart(const std::shared_ptr<Track> &value);
    std::shared_ptr<Track> getEnd() const;
    void setEnd(const std::shared_ptr<Track> &value);

    void setLengthSpeed(int newLength, int newSpeed);
    void restoreDefaultLengthSpeed(std::shared_ptr<Track> track);
    void clearSetTraclSpeedLengthList();
};

#endif // MAP_H
