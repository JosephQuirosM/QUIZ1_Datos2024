#include <iostream>
#include "FloorList.h"
using namespace std;
FloorList list;

void insertFloor() 
{
	int floor;
	cout << "Digite el numero que desea asignar al piso\n";
	cout << "numero: "; cin >> floor;
	list.insertFloor(new Floor(floor));
}

void insertEmployee()
{
	int floor;
	string name;
	list.printFloors(false);
	cout << "Digite el numero de piso\n";
	cout << "numero: "; cin >> floor;
	cout << "Digite el nombre del empleado\n";
	cout << "nombre: "; cin >> name;
	list.insertEmployee(floor, new Employee(name));
}

void insertSale()
{
	int floor;
	string name;
	int sale;

	list.printFloors(false);
	cout << "Digite el numero de piso\n";
	cout << "numero: "; cin >> floor;
	list.printEmployees(floor, false);
	cout << "Digite el nombre del empleado\n";
	cout << "nombre: "; cin >> name;
	cout << "Digite la venta del empleado " << name <<"\n";
	cout << "venta: "; cin >> sale;
	list.insertSale(floor, name, sale);
}

void initList()
{
	//Primer Piso
	list.insertFloor(new Floor(1));
	list.insertEmployee(1, new Employee("Carlos"));
	list.insertSale(1, "carlos", 200);
	list.insertSale(1, "carlos", 50);
	list.insertSale(1, "carlos", 100);
	list.insertEmployee(1, new Employee("Karla"));
	list.insertSale(1, "karla", 300);
	list.insertSale(1, "karla", 500);

	//Segundo piso
	list.insertFloor(new Floor(2));
	list.insertEmployee(2, new Employee("Mario"));
	
	//Tercer piso
	list.insertFloor(new Floor(3));
	list.insertEmployee(3, new Employee("Ana"));
	list.insertSale(3, "ana", 100);
	list.insertSale(3, "ana", 200);
	list.insertEmployee(3, new Employee("Jose"));
	list.insertSale(3, "jose", 500);
	list.insertEmployee(3, new Employee("Sonia"));

	//Cuarto piso
	list.insertFloor(new Floor(4));
	list.insertEmployee(4, new Employee("Pedro"));
	list.insertSale(4, "pedro", 100);
	list.insertSale(4, "pedro", 1000);
	list.insertSale(4, "pedro", 500);

}

void menu() 
{
	int opt = 0;
	int floor = 0;

	do
	{
		cout << "1. Mirar informacion del Edificio\n";
		cout << "2. Mirar Empleados por piso\n";
		cout << "3. Mirar las Ventas de los Empleados de un piso\n";
		cout << "4. Insertar nuevo Piso\n";
		cout << "5. Insertar nuevo Empleado\n";
		cout << "6. Insertar nueva Venta\n";
		cout << "7. Eliminar Piso\n";
		cout << "0. Salir\n\n";

		cout << "opt: ";  cin >> opt;

		system("cls");
		switch (opt)
		{
		case 0:
			cout << "Hasta luego!\n";
			system("pause");
			break;
		case 1:
			list.printFloors(true);
			system("pause");
			break;
		case 2:
			list.printFloors(false);
			cout << "piso: "; cin >> floor;
			system("cls");
			list.printEmployees(floor, false);
			system("pause");
			break;
		case 3:
			list.printFloors(false);
			cout << "piso: "; cin >> floor;
			system("cls");
			list.printEmployees(floor, true);
			system("pause");
			break;
		case 4:
			insertFloor();
			system("pause");
			break;
		case 5:
			insertEmployee();
			system("pause");
			break;
		case 6:
			insertSale();
			system("pause");
			break;
		case 7:
			list.printFloors(false);
			cout << "Digite el piso que desea eliminar\n";
			cout << "piso: "; cin >> floor;
			list.deleteFloor(floor);
			system("pause");
			break;
		default:
			cout << "Opcion no disponible\n";
			system("pause");
			break;
		}
		system("cls");

	} while (opt != 0);
}

int main()
{
	

	initList();
	menu();
	return 0;
}

