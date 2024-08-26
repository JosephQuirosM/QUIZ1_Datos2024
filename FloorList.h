#ifndef FLOORLIST_H
#define FLOORLIST_H
#include "FloorNode.h"
#include <iostream>

class FloorList
{
private://variables
	FloorNode* ini;

public://public methods
	FloorList();
	void insertFloor(Floor* newFloor);
	int printList();
	void insertEmployee(int floor, Employee* employee);
	void insertSale(int floor, std::string employee, int sale);

private://private methods
	
	void insertEmployee(Floor* floor, Employee* employee);
	Employee* searchEmployee(Floor* floor, std::string name);
	void insertSale(Employee* employee, int sale);


	

};

#endif



