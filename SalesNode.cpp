#include "SalesNode.h"

SalesNode::SalesNode()
{
	nextSale = nullptr;
	sale = 0;
}

SalesNode::SalesNode(int pSale)
{
	nextSale = nullptr;
	sale = pSale;
}

SalesNode* SalesNode::getNextSale()
{
	return nextSale;
}

int SalesNode::getSale()
{
	return sale;
}

void SalesNode::setSale(int pSale)
{
	sale = pSale;
}

void SalesNode::setNextSale(SalesNode* pNode)
{
	nextSale = pNode;
}
