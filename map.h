#ifndef MAP_H
#define MAP_H
#include <vector>
#include <memory>
#include <QMessageBox>
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
	std::vector<std::shared_ptr<BridgeUnderpassTrack>> bridgeUnderpassTrackList;
	std::vector<std::shared_ptr<SwitchTrack>> switchTrackList;
	std::vector<std::shared_ptr<CrossoverTrack>> crossoverTrackList;
	std::vector<std::shared_ptr<FlyoverTrack>> flyoverTrackList;
	std::vector<std::shared_ptr<NamedLocation>> namedLocationList;
	std::vector<std::shared_ptr<Concourse>> concourseList;
	std::vector<std::shared_ptr<Parapet>> parapetList;
	std::vector<std::shared_ptr<Text>> textList;





public:
	Map();

	std::vector<std::shared_ptr<StraightTrack> > getStraightTrackList() const;
	void setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> >& newStraightTrackList);
	void addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack);

	std::vector<std::shared_ptr<DirectTrack> > getDirectTrackList() const;
	void setDirectTrackList(const std::vector<std::shared_ptr<DirectTrack> >& newDirectTrackList);
	void addDirectTrack(std::shared_ptr<DirectTrack> newDirectTrack);

	std::vector<std::shared_ptr<CurvedTrack> > getCurvedTrackList() const;
	void setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> >& newCurvedTrackList);
	void addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack);

	std::vector<std::shared_ptr<LinkedTrack> > getLinkedTrackList() const;
	void setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> >& newLinkedTrackList);
	void addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack);

	std::vector<std::shared_ptr<ExitTrack> > getExitTrackList() const;
	void setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> >& newExitTrackList);
	void addExitTrack(std::shared_ptr<ExitTrack> newExitTrack);

	std::vector<std::shared_ptr<BufferTrack> > getBufferTrackList() const;
	void setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> >& newBufferTrackList);
	void addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack);

	std::vector<std::shared_ptr<SignalTrack> > getSignalTrackList() const;
	void setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> >& newSignalTrackList);
	void addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack);

	std::vector<std::shared_ptr<BridgeUnderpassTrack>> getBridgeUnderpassTrackList() const;
	void setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> >& newBridgeUnderpassTrackList);
	void addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack);

	std::vector<std::shared_ptr<SwitchTrack> > getSwitchTrackList() const;
	void setSwitchTrackList(const std::vector<std::shared_ptr<SwitchTrack> >& newSwitchTrackList);
	void addSwitchTrack(std::shared_ptr<SwitchTrack> newSwitchTrack);

	std::vector<std::shared_ptr<CrossoverTrack> > getCrossoverTrackList() const;
	void setCrossoverTrackList(const std::vector<std::shared_ptr<CrossoverTrack> >& newCrossoverTrackList);
	void addCrossoverTrack(std::shared_ptr<CrossoverTrack> newCrossoverTrack);

	std::vector<std::shared_ptr<FlyoverTrack> > getFlyoverTrackList() const;
	void setFlyoverTrackList(const std::vector<std::shared_ptr<FlyoverTrack> >& newFlyoverTrackList);
	void addFlyoverTrack(std::shared_ptr<FlyoverTrack> newFlyoverTrack);

	std::vector<std::shared_ptr<NamedLocation> > getNamedLocationList() const;
	void setNamedLocationList(const std::vector<std::shared_ptr<NamedLocation> >& newNamedLocationList);
	void addNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation);

	std::vector<std::shared_ptr<Concourse> > getConcourseList() const;
	void setConcourseList(const std::vector<std::shared_ptr<Concourse> >& newConcourseList);
	void addConcourse(std::shared_ptr<Concourse> newConcourseTrack);

	std::vector<std::shared_ptr<Parapet> > getParapetList() const;
	void setParapetList(const std::vector<std::shared_ptr<Parapet> >& newParapetList);
	void addParapet(std::shared_ptr<Parapet> newParapet);

	std::vector<std::shared_ptr<Text> > getTextList() const;
	void setTextList(const std::vector<std::shared_ptr<Text> >& newTextList);
	void addText(std::shared_ptr<Text> newText);

	std::shared_ptr<Element> getElementAt(int offsetX, int offsetY, int locationX, int locationY);
	bool checkElementExists(int offsetX, int offsetY, int locationX, int locationY);
	bool deleteElement(int locationX, int locationY);

	void addPlatform(Platform side, int offsetX, int offsetY, int locationX, int locationY);
	void addLevelCrossing(int offsetX, int offsetY, int locationX, int locationY);
};

#endif // MAP_H
