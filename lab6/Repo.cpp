#include "Repo.h"
#include "Aplicatie.h"
#include <iostream>
using namespace std;

//constructor fara param
Repo::Repo() {
	this->aplicatii;
	this->contor = 0;
}

//constuctor de copiere
Repo::Repo(const Repo& r) {
	this->aplicatii = r.aplicatii;
	this->contor = r.contor;
}
//destructorul
Repo::~Repo(){
}

//adaugarea unui aplicatii
void Repo::addAplicatie(Aplicatie a) {
	aplicatii.insert(pair<int, Aplicatie>(contor++, a));
}

//returnarea tuturor aplicatiilor
map<int, Aplicatie> Repo::getAll() {
	return aplicatii;
}

//stergerea unei aplicatii
void Repo::delAplicatie(int pos)
{
	aplicatii.erase(pos);
}

//update la o aplicatie
void Repo::updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* status)
{
	a.setName(name);
	a.setConsumMemorieKb(consumMemorieKb);
	a.setStatus(status);
	aplicatii.at(pos) = a;
}

//dimensiune map
int Repo::getSize() {
	return aplicatii.size();
}