#pragma once
#include "Aplicatie.h"
#include <map>
using namespace std;

class RepoFile
{
private:
	map<int, Aplicatie> aplicatii;
	int contor;
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void addAplicatie(Aplicatie);
	void delAplicatie(int pos);
	void updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* status);
	map<int, Aplicatie> getAll();
	int size();
	void saveToFile();
	~RepoFile();
};
