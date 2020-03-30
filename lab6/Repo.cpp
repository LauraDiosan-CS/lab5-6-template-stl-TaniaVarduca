#include "Repo.h"
#include <iostream>
using namespace std;

//constructor fara param
Repo::Repo() {
	this->elem;
}

//constuctor de copiere
Repo::Repo(const Repo& r) {
	this->elem = r.elem;
}
//destructorul
Repo::~Repo(){
}

//adaugarea unui element
void Repo::addElem(Aplicatie a) {
	elem.push_back(a);
}

//returnarea tuturor elementelor
vector<Aplicatie> Repo::getAll() {
	return elem;
}

//dimensiunea vectorului
int Repo::getSize() {
	return elem.size();
}