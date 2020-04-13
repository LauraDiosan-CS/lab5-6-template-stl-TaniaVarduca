#include "Aplicatie.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Aplicatie::Aplicatie() {
	this->name = NULL;
	this->consumMemorieKb = 0;
	this->statusV = NULL;
	this->statusN = NULL;
}

//constructor cu param
Aplicatie::Aplicatie(const char* name, int consumMemorieKb, const char* statusV, const char* statusN)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->consumMemorieKb = consumMemorieKb;
	this->statusV = new char[strlen(statusV) + 1];
	strcpy_s(this->statusV, 1 + strlen(statusV), statusV);
	this->statusN = new char[strlen(statusN) + 1];
	strcpy_s(this->statusN, 1 + strlen(statusN), statusN);
}

//constructor de copiere
Aplicatie::Aplicatie(const Aplicatie& a) {
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(this->name, 1 + strlen(a.name), a.name);
	}
	this->consumMemorieKb = a.consumMemorieKb;
	if (a.statusV) {
		this->statusV = new char[strlen(a.statusV) + 1];
		strcpy_s(this->statusV, 1 + strlen(a.statusV), a.statusV);
	}
	if (a.statusN) {
		this->statusN = new char[strlen(a.statusN) + 1];
		strcpy_s(this->statusN, 1 + strlen(a.statusN), a.statusN);
	}
}

//destructor
Aplicatie::~Aplicatie() {
	if (name) delete[]name;
	name = NULL;
	consumMemorieKb = -1;
	statusV = NULL;
	statusV = NULL;
}

//getter pentru nume
char* Aplicatie::getName() {
	return this->name;
}

//getter pentru consumMemorieKb
int Aplicatie::getConsumMemorieKb() {
	return this->consumMemorieKb;
}

//getter pentru statusV
char* Aplicatie::getStatusV() {
	return this->statusV;
}

//getter pentru statusul nou
char* Aplicatie::getStatusN() {
	return this->statusN;
}

//setter pentru nume
void Aplicatie::setName(const char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

//setter pentru consumMemorieKb
void Aplicatie::setConsumMemorieKb(int consumMemorieKb) {
	this->consumMemorieKb = consumMemorieKb;
}

//setter pentru statusV
void Aplicatie::setStatusV(const char* statusV)
{
	if (this->statusV) {
		delete[] this->statusV;
	}
	this->statusV = new char[strlen(statusV) + 1];
	strcpy_s(this->statusV, strlen(statusV) + 1, statusV);
}

//setter pentru statusul nou
void Aplicatie::setStatusN(const char* statusN)
{
	if (this->statusN) {
		delete[] this->statusN;
	}
	this->statusN = new char[strlen(statusN) + 1];
	strcpy_s(this->statusN, strlen(statusN) + 1, statusN);
}

//suprascrie operatorul "=" pentru un element de tip Aplicatie
Aplicatie& Aplicatie::operator=(const Aplicatie& a) {
	if (this == &a) return *this; //self-assignment
	if (name) delete[] name;
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(name, strlen(a.name) + 1, a.name);
	}
	consumMemorieKb = a.consumMemorieKb;
	if (statusV) delete[] statusV;
	if (a.statusV) {
		this->statusV = new char[strlen(a.statusV) + 1];
		strcpy_s(statusV, strlen(a.statusV) + 1, a.statusV);
	}
	if (statusN) delete[] statusN;
	if (a.statusN) {
		this->statusN = new char[strlen(a.statusN) + 1];
		strcpy_s(statusN, strlen(a.statusN) + 1, a.statusN);
	}
	return *this;
}

//operatorul de egalitate
bool Aplicatie:: operator==(const Aplicatie& a) {
	return strcmp(this->name, a.name) == 0 && this->consumMemorieKb == a.consumMemorieKb && strcmp(this->statusV, a.statusV) == 0 && strcmp(this->statusN, a.statusN) == 0;
}

//pt afisare
ostream& operator<<(ostream& os, const Aplicatie& a)
{
	os << "Nume - " << a.name << ", consumMemorieKb - " << a.consumMemorieKb << ", statusV - " << a.statusV << ", statusN - " << a.statusN;
	return os;
}