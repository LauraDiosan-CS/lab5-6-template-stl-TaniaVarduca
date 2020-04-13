#include "Service.h"
#include <iostream>
using namespace std;

//constructor implicit
Service::Service()
{
	capacitateRAM = 0;
	totalRAM = 0;
}

//construcor cu paramentru
Service::Service(Repo<Aplicatie>*&repo)
{
	r = repo;
	capacitateRAM = 0;
	totalRAM = 0;
}

//destructor
Service::~Service()
{
}

void Service::setRepo(Repo<Aplicatie>*&repo)
{
	r = repo;
}

void Service::initServ()
{
	setRepo(r);
	r->loadFromFile("Aplicatii.txt", totalRAM);
	if (totalRAM > capacitateRAM) {
		addRAM(totalRAM, capacitateRAM);
	}
}

//adauga aplicatie
void Service::addAplicatie(Aplicatie& a)
{
	map<int, Aplicatie> aplicatii = r->getAll();
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
		totalRAM += a.getConsumMemorieKb();
		addRAM(totalRAM, capacitateRAM);
		r->addAplicatie(a);
		r->saveToFile();
		cout << "Total memorie RAM consumata: " << totalRAM << endl << endl;
	}
}

//returneaza toate aplicatiile
map<int, Aplicatie> Service::getAll() {
	//rf.loadFromFile();
	return r->getAll();
}

int Service::getTotalMemorie() {
	return totalRAM;
 }

//sterge o aplicatie
void Service::delAplicatie(int pos)
{
	map<int, Aplicatie> aplicatii = r->getAll();
	totalRAM -= aplicatii.at(pos).getConsumMemorieKb();
	delRAM(totalRAM, capacitateRAM, aplicatii.at(pos).getConsumMemorieKb());
	r->delAplicatie(pos);
	r->saveToFile();
}

//update la o aplicatie
void Service::updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* statusN)
{
	r->updateAplicatie(a, pos, name, consumMemorieKb, statusN);
	r->saveToFile();
}

//diminsiune repo map
int Service::getSize()
{
	return r->getSize();
}

void Service::exceptieRAM(int consum, int& newConsum) {
	int k = 0;
	if (consum <= capacitateRAM) k++;
	while (k == 0) {
		cout << "Consumul este mai mare decat capacitatea! Incercati din nou: ";
		cin >> newConsum;
		if (newConsum <= capacitateRAM) k++;
	}
}

void Service::addRAM(int& totalRAM, int capacitateRAM) {
	int k = 0; char c[5] = "swap";
	map<int, Aplicatie> aplicatii = r->getAll();
	map<int, Aplicatie>::iterator itr;
	if (totalRAM <= capacitateRAM) k++;
	while (k == 0) {
		cout << "Totalul memoriei a depasit capacitatea RAM! Se muta aplicatii in swap..." << endl;
		for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
			if (totalRAM > capacitateRAM) {
				Aplicatie a = itr->second;
				r->updateAplicatie(itr->second, itr->first, a.getName(), a.getConsumMemorieKb(), c);
				if(strcmp(a.getStatusN(), c)!=0) totalRAM -= a.getConsumMemorieKb();
			}
			if (totalRAM <= capacitateRAM) k++;
		}
	}
}

void Service::delRAM(int&totalRAM, int capacitateRAM, int consum)
{
	int k = 0; 
	char c[5] = "ram";
	map<int, Aplicatie> aplicatii = r->getAll();
	map<int, Aplicatie>::iterator itr;
	if (totalRAM +consum > capacitateRAM) k++;
	while (k == 0) {
		cout << "Se muta aplicatii in ram..." << endl;
		for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
			if (totalRAM + itr->second.getConsumMemorieKb() <= capacitateRAM) {
				Aplicatie a = itr->second;
				if (strcmp(a.getStatusN(), c) != 0)
					totalRAM += a.getConsumMemorieKb();
				r->updateAplicatie(itr->second, itr->first, a.getName(), a.getConsumMemorieKb(), c);
			}
			if (totalRAM <= capacitateRAM) k++;
		}
	}
}

void Service::citireRAM()
{
	cout << "Dati capacitatea RAM: " << endl; cin >> capacitateRAM;
	cout << endl;
}
