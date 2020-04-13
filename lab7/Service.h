#pragma once
#include "Aplicatie.h"
#include "RepoFile.h"
#include <map>

class Service {
private:
	RepoFile<Aplicatie> rf;
	Repo<Aplicatie>* r=&rf;
	int capacitateRAM, totalRAM;
public:
	Service();
	Service(Repo<Aplicatie>*&);
	~Service();
	void setRepo(Repo<Aplicatie>*&);
	void initServ();
	void addAplicatie(Aplicatie& a);
	map<int, Aplicatie> getAll();
	void delAplicatie(int pos);
	void updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* statusN);
	int getSize();
	void exceptieRAM(int, int&);
	void addRAM(int&, int);
	void delRAM(int&, int, int);
	void citireRAM();
	int getTotalMemorie();
};
