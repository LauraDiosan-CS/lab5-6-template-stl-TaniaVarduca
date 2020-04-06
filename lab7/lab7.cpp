#include "UI.h"
#include"Tests.h"
#include <iostream>
using namespace std;

int main() {
	tests();
	bool k = true;
	Service s; UI ui;
	RepoFile r;
	r.loadFromFile("Aplicatii.txt");
	s.setRepo(r);
	ui.printMenu();
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			ui.addAplicatie(s);
			ui.printMenu();
			continue;
		}
		if (option == 2)
		{
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 3)
		{
			ui.updateAplicatie(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 4)
		{
			ui.delAplicatie(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 5)
			k = false;
	}
	return 0;
}
