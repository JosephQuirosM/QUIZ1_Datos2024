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
	void printFloors(bool showSales);
	void printEmployees(int floor, bool showSales);
	void insertEmployee(int floor, Employee* employee);
	void insertSale(int floor, std::string employee, int sale);
	void deleteFloor(int floor);

private://private methods
	void insertEmployee(Floor* floor, Employee* employee);
	Employee* searchEmployee(Floor* floor, std::string name);
	void insertSale(Employee* employee, int sale);
	void deleteFloor(Floor* actual, Floor* next);
	void recountSummatory(Floor* floor);

	

};

#endif



