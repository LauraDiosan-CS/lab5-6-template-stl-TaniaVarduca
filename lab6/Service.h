#pragma once
#include "Aplicatie.h"
#include "Repo.h"
#include <map>

class Service {
private:
	Repo r;
public:
	Service();
	~Service();
	void addAplicatie(Aplicatie& a);
	map<int, Aplicatie> getAll();
	void delAplicatie(int pos);
	void updateAplicatie(Aplicatie& a,int pos, char* name, int consumMemorieKb, char* status);
	int getSize();
};
