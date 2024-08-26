#ifndef SALESNODE_H
#define SALESNODE_H

class SalesNode
{
private: //variables
	SalesNode* nextSale;
	int sale;

public: //public methods
	SalesNode();
	SalesNode(int pSale);
	SalesNode* getNextSale();
	int getSale();
	void setSale(int pSale);
	void setNextSale(SalesNode* pNode);

private: //private methods

};
#endif



