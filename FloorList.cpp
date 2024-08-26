#include "FloorList.h"

FloorList::FloorList()
{
	ini = nullptr;
}

void FloorList::insertFloor(Floor* newFloor)
{
	FloorNode* newNode = new FloorNode(newFloor);

	if (ini == nullptr) {
		ini = newNode;
		return;
	}


	FloorNode* aux = ini;
	FloorNode* prev = nullptr;

	while (aux->getFloor()->getName() < newFloor->getName() && aux->getNextFloor() != nullptr) {
		prev = aux;
		aux = aux->getNextFloor();
	}

	if (aux == ini) {
		newNode->setNextFloor(aux);
		aux->setPrevFloor(newNode);
		ini = newNode;
		return;
	}

	if (aux->getNextFloor() != nullptr) {
		prev->setNextFloor(newNode);
		newNode->setPrevFloor(prev);
		newNode->setNextFloor(aux);
		aux->setPrevFloor(newNode);
		return;
	}

	aux->setNextFloor(newNode);
	newNode->setPrevFloor(aux);
	return;
}

int FloorList::printList()
{
	int i = 0;
	FloorNode* aux = ini;
	if (aux == nullptr) {
		return -1;
	}

	while (aux != nullptr) {
		i++;
		std::cout << aux->getFloor()->getName() << "\n";
		aux = aux->getNextFloor();
	}


	std::cout << "tamano " << i;
	return i;
}

void FloorList::insertEmployee(int floor, Employee* employee)
{
	FloorNode* aux = ini;

	while (aux->getFloor()->getName() != floor && aux->getNextFloor() != nullptr) {
		aux = aux->getNextFloor();
	}

	if (aux->getFloor()->getName() == floor) {
		insertEmployee(aux->getFloor(), employee);
		return;
	}

	delete employee;
	std::cout << "piso no existe \n";
	return;
}

void FloorList::insertSale(int floor, std::string employee, int sale)
{
	FloorNode* aux = ini;

	while (aux->getFloor()->getName() != floor && aux->getNextFloor() != nullptr) {
		aux = aux->getNextFloor();
	}

	if (aux->getFloor()->getName() == floor) {
		Employee* ownerSale = searchEmployee(aux->getFloor(), employee);

		if (ownerSale != nullptr) {
			insertSale(ownerSale, sale);
		}

		return;
	}

	std::cout << "piso no existe \n";
	return;
}

void FloorList::insertEmployee(Floor* floor, Employee* employee)
{
	EmployeeNode* newNode = new EmployeeNode(employee);
	EmployeeNode* aux = floor->getEmployeeHead();
	if (aux == nullptr) {
		floor->setEmployeeHead(newNode);
		return;
	}
	
	EmployeeNode* prev =nullptr;
	while (aux->getEmployee()->getName() < employee->getName() && aux->getNextEmployee() != nullptr) {
		prev = aux;
		aux = aux->getNextEmployee();
	}

	if (aux == floor->getEmployeeHead()) {
		newNode->setNextEmployee(aux);
		floor->setEmployeeHead(newNode);
		return;
	}

	if (aux->getNextEmployee() != nullptr) { 
		prev->setNextEmployee(newNode);
		newNode->setNextEmployee(aux);
		return;
	}
	
	aux->setNextEmployee(newNode);
}

Employee* FloorList::searchEmployee(Floor* floor, std::string name)
{
	EmployeeNode* aux = floor->getEmployeeHead();

	while (aux->getEmployee()->getName() != name && aux != nullptr) {
		aux = aux->getNextEmployee();
	}

	if (aux != nullptr) {
		return aux->getEmployee();
	}

	return nullptr;
}

void FloorList::insertSale(Employee* employee, int sale)
{
	SalesNode* newNode = new SalesNode(sale);
	SalesNode* aux = employee->getSaleHead();
	if (aux == nullptr) {
		employee->setSaleHead(newNode);
		return;
	}

	SalesNode* prev = nullptr;

	while (aux->getSale() > sale && aux->getNextSale() != nullptr) {
		prev = aux;
		aux = aux->getNextSale();
	}

	if (aux == employee->getSaleHead()) {
		newNode->setNextSale(aux);
		employee->setSaleHead(newNode);
		return;
	}

	if (aux->getNextSale() != nullptr) {
		prev->setNextSale(newNode);
		newNode->setNextSale(aux);
		return;
	}

	aux->setNextSale(newNode);
	return;
}