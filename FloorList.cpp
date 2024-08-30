#include "FloorList.h"
using namespace std;

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

	while (aux->getFloor()->getName() > newFloor->getName() && aux->getNextFloor() != nullptr) {
		prev = aux;
		aux = aux->getNextFloor();
	}

	if (aux == ini && aux->getFloor()->getName() < newFloor->getName()) {
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

void FloorList::printFloors(bool showSales)
{
	FloorNode* aux = ini;
	if (aux == nullptr) {
		cout << "El edificio esta vacio\n";
		return;
	}

	if (showSales)
	{
		while (aux != nullptr) {
			cout << aux->getFloor()->getName() << "\n";
			cout << "ventas: " << aux->getFloor()->getSales() << "\n\n";

			aux = aux->getNextFloor();
		}
		return;
	}

	while (aux != nullptr) {
		cout <<"piso " << aux->getFloor()->getName() << "\n";
		aux = aux->getNextFloor();
	}
	return;
}

void FloorList::printEmployees(int floor, bool showSales)
{
	FloorNode* aux = ini;
	if (aux == nullptr) {
		cout << "El edificio esta vacio\n";
		return;
	}

	while (aux->getFloor()->getName() != floor && aux->getNextFloor() != nullptr) {
		aux = aux->getNextFloor();
	}

	if (aux->getFloor()->getName() != floor)
	{
		cout << "El piso no existe\n";
		return;
	}

	if (showSales)
	{
		cout << "\n\npiso " << floor << "\n";
		EmployeeNode* head = aux->getFloor()->getEmployeeHead();
		while (head != nullptr)
		{
			cout << head->getEmployee()->getName() << "\n";
			cout << head->getEmployee()->getSummatory()<<"\n\n";
			head = head->getNextEmployee();
		}
		cout << "\n\n";
		return;
	}

	cout << "\n\npiso " << floor << "\n";
	EmployeeNode* head = aux->getFloor()->getEmployeeHead();
	while (head != nullptr)
	{
		cout << head->getEmployee()->getName() << "\n";
		head = head->getNextEmployee();
	}
	cout << "\n\n";
	return;
	
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

	while (aux->getFloor()->getName() != floor && aux->getNextFloor()->getNextFloor() != nullptr) {
		aux = aux->getNextFloor();
	}

	if (aux->getFloor()->getName() == floor) {
		Employee* ownerSale = searchEmployee(aux->getFloor(), employee);

		if (ownerSale != nullptr) {
			insertSale(ownerSale, sale);
			aux->getFloor()->increaseSales(sale);
			ownerSale->increaseSummatory(sale);
			return;
		}
		cout << "El empleado " << employee << " no existe\n";
		return;
	}

	std::cout << "piso no existe \n";
	return;
}

void FloorList::deleteFloor(int floor)
{
	FloorNode* aux = ini;
	FloorNode* prev = nullptr;

	if (aux == nullptr)
	{
		cout << "el edificio esta vacio\n";
		return;
	}

	while (aux->getFloor()->getName() != floor && aux->getNextFloor() != nullptr)
	{
		prev = aux;
		aux = aux->getNextFloor();
	}

	if (aux->getFloor()->getName() == floor)
	{
		if (aux->getNextFloor() == nullptr)
		{
			prev->setNextFloor(nullptr);
			return;
		}

		if (prev == nullptr)
		{
			deleteFloor(aux->getFloor(), aux->getNextFloor()->getFloor());
			recountSummatory(aux->getNextFloor()->getFloor());
			aux->getNextFloor()->setPrevFloor(nullptr);
			ini = aux->getNextFloor();
			aux->getFloor()->setEmployeeHead(nullptr);
			return;
		}

		deleteFloor(aux->getFloor(), aux->getNextFloor()->getFloor());
		recountSummatory(aux->getNextFloor()->getFloor());
		prev->setNextFloor(aux->getNextFloor());
		aux->getNextFloor()->setPrevFloor(prev);
		aux->getFloor()->setEmployeeHead(nullptr);
		return;
	}

	cout << "este edificio no existe\n";
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

	if (aux == floor->getEmployeeHead() && aux->getEmployee()->getName() > employee->getName()) {
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

	while (aux->getEmployee()->getName() != name && aux->getNextEmployee() != nullptr) {
		aux = aux->getNextEmployee();
	}

	if (aux->getEmployee()->getName() == name) {
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

void FloorList::deleteFloor(Floor* actual, Floor* next)
{
	EmployeeNode* head = actual->getEmployeeHead();

	while (head != nullptr)
	{
		insertEmployee(next, head->getEmployee());
		head->setEmployee(nullptr);
		head = head->getNextEmployee();
	}
}

void FloorList::recountSummatory(Floor* floor)
{
	EmployeeNode* aux = floor->getEmployeeHead();
	floor->setSales(0);

	while (aux != nullptr)
	{
		floor->increaseSales(aux->getEmployee()->getSummatory());
		aux = aux->getNextEmployee();
	}
}
