 #ifndef FLOOR_H
#define FLOOR_H
#include <string>
#include "EmployeeNode.h"

class Floor
{
private: //Variables
	int name;
	int sales;
	EmployeeNode* employeeHead;


public: //public Methods
	Floor();
	Floor(int pName);
	int getName();
	int getSales();
	EmployeeNode* getEmployeeHead();
	void setEmployeeHead(EmployeeNode* head);
	void setName(int pName);
	void setSales(int pSales);

private: //private methods





};
#endif

