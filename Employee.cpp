#include "Employee.h"

Employee::Employee()
{
	name = "";
	summatory = 0;
}

Employee::Employee(std::string pName)
{
	name = pName;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	summatory = 0;
}

std::string Employee::getName()
{
	return name;
}

int Employee::getSummatory()
{
	return summatory;
}

SalesNode* Employee::getSaleHead()
{
	return saleHead;
}

void Employee::setName(std::string pName)
{
	name = pName;
}

void Employee::setSummatory(int quantity)
{
	summatory = quantity;
}

void Employee::setSaleHead(SalesNode* head)
{
	saleHead = head;
}

void Employee::increaseSummatory(int pSale)
{
	summatory += pSale;
}

