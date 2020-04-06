#include "Service.h"
#include <iostream>
using namespace std;

//constructor implicit
Service::Service()
{
}

//construcor cu paramentru
Service::Service(const RepoFile&r)
{
	repo = r;
}

//destructor
Service::~Service()
{
}

void Service::setRepo(const RepoFile&r)
{
	repo = r;
}

//adauga aplicatie
void Service::addAplicatie(Aplicatie& a)
{
	map<int, Aplicatie> aplicatii = repo.getAll();
	map<int, Aplicatie>::iterator itr;
	bool ok = true;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		Aplicatie aplic = itr->second;
		if (strstr(aplic.getName(), a.getName()) and (strlen(aplic.getName()) == strlen(a.getName()))) {
			ok = false;
			cout << endl << "Exista deja o aplicatie cu acest nume! Incercati din nou." << endl;
		}
	}
	if (ok) {
		repo.addAplicatie(a);
		repo.saveToFile();
	}
}

//returneaza toate aplicatiile
map<int, Aplicatie> Service::getAll() {
	return repo.getAll();
}

//sterge o aplicatie
void Service::delAplicatie(int pos)
{
	repo.delAplicatie(pos);
	repo.saveToFile();
}

//update la o aplicatie
void Service::updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* status)
{
	repo.updateAplicatie(a, pos, name, consumMemorieKb, status);
	repo.saveToFile();
}

//diminsiune repo map
int Service::getSize()
{
	return repo.size();
}
