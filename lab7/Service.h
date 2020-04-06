#pragma once
#include "Aplicatie.h"
#include "RepoFile.h"
#include <map>

class Service {
private:
	RepoFile repo;
public:
	Service();
	Service(const RepoFile&);
	~Service();
	void setRepo(const RepoFile&);
	void addAplicatie(Aplicatie& a);
	map<int, Aplicatie> getAll();
	void delAplicatie(int pos);
	void updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* status);
	int getSize();
};
