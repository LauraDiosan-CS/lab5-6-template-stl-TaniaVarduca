#pragma once
#include "Aplicatie.h"
#include "RepoFile.h"
#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	~UI();
	void printMenu();
	void addAplicatie(Service& s);
	void getAll(Service& s);
	void delAplicatie(Service& s);
	void updateAplicatie(Service& s);
};
