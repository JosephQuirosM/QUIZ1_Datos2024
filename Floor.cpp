#include "Floor.h"

Floor::Floor()
{
	employeeHead = nullptr;
	name = 0;
	sales = 0;
}

Floor::Floor(int pName)
{
	name = pName;
	employeeHead = nullptr;
	this->name = name;
	sales = 0;
}

int Floor::getName()
{
	return name;
}

int Floor::getSales()
{
	return sales;
}

EmployeeNode* Floor::getEmployeeHead()
{
	return employeeHead;
}

void Floor::setEmployeeHead(EmployeeNode* head)
{
	employeeHead = head;
}

void Floor::setName(int pName)
{
	name = pName;
}

void Floor::setSales(int pSales)
{
	sales = pSales;
}

void Floor::increaseSales(int pSales)
{
	sales += pSales;
}
