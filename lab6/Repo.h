#pragma once
#include "Aplicatie.h" 
#include <vector>

using namespace std;

class Repo
{
private:
	vector<Aplicatie> elem;

public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	void addElem(Aplicatie);
	vector<Aplicatie> getAll();
	int getSize();
};
