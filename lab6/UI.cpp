#include "UI.h"
#include "Exceptii.h"
#include <iostream>
using namespace std;

//constructor
UI::UI()
{
	this->s;
}

//destructor
UI::~UI()
{
}

//afisare meniu
void UI::printMenu()
{
	cout << "1. Adaugare." << endl;
	cout << "2. Afisare" << endl;
	cout << "3. Update" << endl;
	cout << "4. Stergere" << endl;
	cout << "5. Iesire." << endl;
}

//adaugare element de tip Aplicatie
void UI::addAplicatie(Service& s)
{	
	char name[10], status[5];
	int consumMemorieKb, n = 0;

	cout << "Dati numele: ";
	cin >> name;

	cout << "Dati consumMemorieKb (>0): ";
	cin >> consumMemorieKb;
	int newMemo = consumMemorieKb;
	exceptieMemorie(consumMemorieKb, newMemo);
	consumMemorieKb = newMemo;

	cout << "Dati status in [ram, swap]: ";
	cin >> status;
	exceptieStatus(status);

	Aplicatie a(name, consumMemorieKb, status);
	s.addAplicatie(a);
	cout << endl;
}

//afisare toate elementele de tip Aplicatie
void UI::getAll(Service& s)
{
	map<int, Aplicatie> aplicatii = s.getAll();
	map<int, Aplicatie>::iterator itr;
	cout << endl << "Aplicatiile sunt: " << endl;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		cout << "cheia: "<< itr->first << ", aplicatia: " << itr->second;
		cout << endl;
	}
	cout << endl;
}

//stergere element de tip Aplicatie
void UI::delAplicatie(Service& s)
{
	cout << "Sterge aplicatia cu cheia: ";
	map<int, Aplicatie> aplicatii = s.getAll();
	int nr; cin >> nr; int n = s.getSize(), i = 0;
	map<int, Aplicatie>::iterator itr;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		if (itr->first == nr) {
			s.delAplicatie(nr);
			n -= 1;
		}
	}
}

//stergere element de tip Aplicatie
void UI::updateAplicatie(Service& s)
{
	cout << "Update la exercitiul cu cheia: "; int nr; cin >> nr;
	cout << "new name: "; char  newName[10];  cin >> newName;

	cout << "new consumMemorieKb: "; int newConsumMemorieKb;  cin >> newConsumMemorieKb; 
	int memo = newConsumMemorieKb;
	exceptieMemorie(newConsumMemorieKb, memo);
	newConsumMemorieKb = memo;

	cout << "new status: "; char newStatus[10];  cin >> newStatus;
	exceptieStatus(newStatus);

	map<int, Aplicatie> aplicatii = s.getAll();
	Aplicatie a = aplicatii.at(nr);
	s.updateAplicatie(a, nr, newName, newConsumMemorieKb, newStatus);
}
