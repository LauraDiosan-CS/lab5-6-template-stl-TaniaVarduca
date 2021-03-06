#include "UI.h"
#include "ValidareDate.h"
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
	s.exceptieRAM(consumMemorieKb, newMemo);
	consumMemorieKb = newMemo;

	Aplicatie a(name, consumMemorieKb, "ram", "ram");
	s.addAplicatie(a);
}

//afisare toate elementele de tip Aplicatie
void UI::getAll(Service& s)
{
	map<int, Aplicatie> aplicatii = s.getAll();
	map<int, Aplicatie>::iterator itr;
	cout << endl << "Aplicatiile sunt: " << endl;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		cout << "cheia: " << itr->first << ", aplicatia: " << itr->second;
		cout << endl;
	}
	cout << "Total memorie RAM consumata: " << s.getTotalMemorie() << endl << endl;
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
	char newStatusN[5] = "";

	cout << "new consumMemorieKb: "; int newConsumMemorieKb;  cin >> newConsumMemorieKb;
	int memo = newConsumMemorieKb;
	exceptieMemorie(newConsumMemorieKb, memo);
	newConsumMemorieKb = memo;

	map<int, Aplicatie> aplicatii = s.getAll();
	Aplicatie a = aplicatii.at(nr);
	s.updateAplicatie(a, nr, newName, newConsumMemorieKb, newStatusN);
}

void UI::run()
{
	bool k = true;
	Service s; 
	s.citireRAM();
	s.initServ();
	printMenu();
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			addAplicatie(s);
			printMenu();
			continue;
		}
		if (option == 2)
		{
			getAll(s);
			printMenu();
			continue;
		}
		if (option == 3)
		{
			updateAplicatie(s);
			getAll(s);
			printMenu();
			continue;
		}
		if (option == 4)
		{
			delAplicatie(s);
			getAll(s);
			printMenu();
			continue;
		}
		if (option == 5)
			k = false;
	}
}

