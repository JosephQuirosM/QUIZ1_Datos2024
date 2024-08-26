#include "EmployeeNode.h"

EmployeeNode::EmployeeNode()
{
	nextEmployee = nullptr;
	employee = nullptr;
}

EmployeeNode::EmployeeNode(Employee* pEmployee)
{
	employee = pEmployee;
	nextEmployee = nullptr;
}

EmployeeNode* EmployeeNode::getNextEmployee()
{
	return nextEmployee;
}

Employee* EmployeeNode::getEmployee()
{
	return employee;
}

void EmployeeNode::setNextEmployee(EmployeeNode* node)
{
	nextEmployee = node;
}

void EmployeeNode::setEmployee(Employee* employee)
{
	this->employee = employee;
}


