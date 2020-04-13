#pragma once
#include "Aplicatie.h"
#include <map>
#include "RepoMap.h"
using namespace std;

template <class T> class RepoFile:public Repo<Aplicatie>
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName, int& totalRAM);
	void saveToFile();
	~RepoFile();
};


