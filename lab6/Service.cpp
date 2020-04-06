#include "Service.h"
#include <iostream>
#include <algorithm>
using namespace std;

//constructor fara param
Service::Service() {
	this->r;
}

//destructor
Service::~Service() {
}

//adauga un element de tip Aplicatie
void Service::addAplicatie(Aplicatie& a) {
	map<int, Aplicatie> aplicatii = r.getAll();
	map<int, Aplicatie>::iterator itr;
	bool ok = true;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		Aplicatie aplic = itr->second;
		if (strstr(aplic.getName(), a.getName()) and (strlen(aplic.getName())==strlen(a.getName()))) {
			ok = false;
			cout << endl << "Exista deja o aplicatie cu acest nume! Incercati din nou." << endl;
		}
	}
	if (ok) r.addAplicatie(a);
}

//returneaza toate elementele de tip Aplicatie
map<int, Aplicatie> Service::getAll() {
	return r.getAll();
}

//sterge o aplicatie
void Service::delAplicatie(int pos)
{
	r.delAplicatie(pos);
}

//modifica un element de tip Aplicatie 
void Service::updateAplicatie(Aplicatie& a,int pos, char* name, int consumMemorieKb, char* status)
{
	r.updateAplicatie(a, pos,name, consumMemorieKb, status);
}

//returneaza dimensiunea repo-ului
int Service::getSize() {
	return r.getSize();
}