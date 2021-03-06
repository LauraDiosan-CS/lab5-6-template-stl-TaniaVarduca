#pragma once
#include "Aplicatie.h" 
#include <map>

using namespace std;

class Repo
{
private:
	map<int, Aplicatie> aplicatii;
	int contor;
public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	void addAplicatie(Aplicatie a);
	map<int, Aplicatie> getAll();
	void delAplicatie(int pos);
	void updateAplicatie(Aplicatie& a,int pos, char* name, int consumMemorieKb, char* status);
	int getSize();
};
