#include <iostream>
#include "tests.h"
#include "Service.h"
#include "UI.h"
using namespace std;

int main()
{
	tests();
	bool k = true;
	Service s; UI ui;
	ui.printMenu();
	char a[10] = "aplic1", b[10] = "aplic2", c[10] = "aplic3";
	char x[5] = "swap", y[5] = "ram", z[5] = "swap";
	Aplicatie a1(a, 200, x), a2(b, 100, y), a3(c, 800, z);
	s.addAplicatie(a1); s.addAplicatie(a2); s.addAplicatie(a3);
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
}

