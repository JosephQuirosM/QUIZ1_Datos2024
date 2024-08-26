#include <iostream>
#include "FloorList.h"

int main()
{
	FloorList list;

	list.insertFloor(new Floor(1));
	list.insertEmployee(1, new Employee("Juan"));
	list.insertSale(1, "juan", 123);
	list.printList();

	//prueba commit
	//prueba commit
	return 0;
}

