#ifndef SALESLIST_H
#define SALESLIST_H

#include "SalesNode.h"
#include <iostream>
class SalesList
{
private: //Variables
	SalesNode* head;

public: //public method
	SalesList();
	void insertDecendent(int newSale);
	int getSize();

private: //private method
	
};
#endif



