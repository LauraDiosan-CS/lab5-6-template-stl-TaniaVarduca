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
	this->status = NULL;
}

//constructor cu param
Aplicatie::Aplicatie(const char* name, int consumMemorieKb, const char* status)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, 1 + strlen(status), status);
}

//constructor de copiere
Aplicatie::Aplicatie(const Aplicatie& a) {
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(this->name, 1 + strlen(a.name), a.name);
	}
	this->consumMemorieKb = a.consumMemorieKb;
	if (a.status) {
		this->status = new char[strlen(a.status) + 1];
		strcpy_s(this->status, 1 + strlen(a.status), a.status);
	}
}

//destructor
Aplicatie::~Aplicatie() {
	if (name) delete[]name;
	name = NULL;
	consumMemorieKb = -1;
	status = NULL;
}

//getter pentru nume
char* Aplicatie::getName() {
	return this->name;
}

//getter pentru consumMemorieKb
int Aplicatie::getConsumMemorieKb() {
	return this->consumMemorieKb;
}

//getter pentru status
char* Aplicatie::getStatus() {
	return this->status;
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

//setter pentru status
void Aplicatie::setStatus(const char* status)
{
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
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
	if (status) delete[] status;
	if (a.status) {
		this->status = new char[strlen(a.status) + 1];
		strcpy_s(status, strlen(a.status) + 1, a.status);
	}
	return *this;
}

//operatorul de egalitate
bool Aplicatie:: operator==(const Aplicatie& a) {
	return strcmp(this->name, a.name) == 0 && this->consumMemorieKb == a.consumMemorieKb && strcmp(this->status, a.status) == 0;
}

//pt afisare
ostream& operator<<(ostream& os, const Aplicatie& a)
{
	os << "Nume - " << a.name << ", consumMemorieKb - " << a.consumMemorieKb << ", status - " << a.status;
	return os;
}