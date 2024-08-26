#ifndef FLOORNODE_H
#define FLOORNODE_H

#include "Floor.h"
class FloorNode
{
private: //Variable
	FloorNode* nextNode;
	FloorNode* prevNode;
	Floor* floor;

public: //public methods
	FloorNode();
	FloorNode(Floor* pFloor);
	FloorNode* getNextFloor();
	FloorNode* getPrevFloor();
	Floor* getFloor();
	void setNextFloor(FloorNode* pNode);
	void setPrevFloor(FloorNode* pNode);
	void setFloor(Floor* pFloor);

private: //private methods



};
#endif



