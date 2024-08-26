#ifndef EMPLOYEENODE_H
#define EMPLOYEENODE_H
#include "Employee.h"

class EmployeeNode
{
private: //Variable
	EmployeeNode* nextEmployee;
	Employee* employee;

public: //public Method
	EmployeeNode();
	EmployeeNode(Employee* pEmployee);
	EmployeeNode* getNextEmployee();
	Employee* getEmployee();
	void setNextEmployee(EmployeeNode* node);
	void setEmployee(Employee* employee);
private: //private Method

};
#endif



