#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "SalesNode.h"
#include <algorithm>

class Employee
{
private: //Variable
	std::string name;
	int summatory;
	SalesNode* saleHead;

public: //public method
	Employee();
	Employee(std::string pName);
	std::string getName();
	int getSummatory();
	SalesNode* getSaleHead();
	void setName(std::string pName);
	void setSummatory(int quantity);
	void setSaleHead(SalesNode* head);



private: //private method
	

};
#endif



