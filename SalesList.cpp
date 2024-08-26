#include "SalesList.h"

SalesList::SalesList()
{
	head = nullptr;
}

void SalesList::insertDecendent(int newSale)
{
	SalesNode* newNode = new SalesNode(newSale);

	if (head == nullptr){
		head = newNode;
		return;
	}


	SalesNode* aux = head;
	SalesNode* prev = nullptr;

	while (aux->getSale() > newSale && aux->getNextSale() != nullptr ) {
		prev = aux;
		aux = aux->getNextSale();
	}

	if (aux == head && aux->getSale() <= newSale) {
		newNode->setNextSale(aux);
		head = newNode;                                           
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

int SalesList::getSize()
{
	int i = 0;
	SalesNode* aux = head;
	if (aux == nullptr) {
		return 0;
	}

	while (aux != nullptr) {
		i++;
		std::cout << aux->getSale() << "\n";
		aux = aux->getNextSale();
	}


	std::cout << "tamano " << i;
	return i;

}


