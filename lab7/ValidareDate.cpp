#include "ValidareDate.h"
#include <iostream>
using namespace std;

//exceptie pentru memorie
void exceptieMemorie(int consumMemorieKb, int& newMemo) {
	int k = 0;
	if (consumMemorieKb > 0) k++;
	while (k == 0) {
		cout << "consumMemorieKb trebuie sa fie un nr pozitiv! Incercati din nou: ";
		cin >> newMemo;
		if (newMemo > 0) k++;
	}

}

//exceptie pentru status
void exceptieStatus(char* status)
{
	char statusuri[2][5] = { "ram","swap" };
	int k = 0;
	for (int i = 0; i < sizeof statusuri; i++)
		if (strcmp(status, statusuri[i]) == 0)
			k++;
	while (k == 0)
	{
		cout << "Status invalid! Incercati din nou: ";
		cin >> status;
		for (int i = 0; i < sizeof statusuri; i++)
			if (strcmp(status, statusuri[i]) == 0)
				k++;
	}
}