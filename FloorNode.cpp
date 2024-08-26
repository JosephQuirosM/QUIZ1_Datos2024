#include "FloorNode.h"

FloorNode::FloorNode()
{
	nextNode = nullptr;
	prevNode = nullptr;
	floor = new Floor();
}

FloorNode::FloorNode(Floor* pFloor)
{
	this->floor = pFloor;
	prevNode = nullptr; 
	nextNode = nullptr;
}

FloorNode* FloorNode::getNextFloor()
{
	return nextNode;
}

FloorNode* FloorNode::getPrevFloor()
{
	return prevNode;
}

Floor* FloorNode::getFloor()
{
	return floor;
}

void FloorNode::setNextFloor(FloorNode* pNode)
{
	nextNode = pNode;
}

void FloorNode::setPrevFloor(FloorNode* pNode)
{
	prevNode = pNode;
}

void FloorNode::setFloor(Floor* pFloor)
{
	floor = pFloor;
}
