#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;

//constructor implicit
RepoFile::RepoFile(){
	this->aplicatii;
	this->contor = 0;
}

//construcor cu paramentru
RepoFile::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int consumMemorieKb;
	char* status = new char[10];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb >> status;
		if (nume != "") {
			Aplicatie a(nume, consumMemorieKb, status);
			addAplicatie(a);
		}
	}
	delete[] nume; delete[] status;
	f.close();
}

//citire din fisier
void RepoFile::loadFromFile(const char* fileName)
{
	aplicatii.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	int consumMemorieKb;
	char* status = new char[10];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb>>status;
		if (strcmp(nume, "") != 0) {
			Aplicatie a(nume, consumMemorieKb, status);
			addAplicatie(a);
		}
	}
	delete[] nume; delete[] status;
	f.close();
}

//adauga o aplicatie
void RepoFile::addAplicatie(Aplicatie a)
{
	aplicatii.insert(pair<int, Aplicatie>(contor++, a));
}

//update la o aplicatie
void RepoFile::updateAplicatie(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* status)
{
	a.setName(name);
	a.setConsumMemorieKb(consumMemorieKb);
	a.setStatus(status);
	aplicatii.at(pos) = a;
}


//stergerea unei aplicatii
void RepoFile::delAplicatie(int pos)
{
	aplicatii.erase(pos);
}


//returnarea tuturor aplicatiilor
map<int, Aplicatie> RepoFile::getAll() {
	return aplicatii;
}

//dimensiune map
int RepoFile::size()
{
	return aplicatii.size();
}

//scriere in fisier
void RepoFile::saveToFile()
{
	ofstream f(fis);
	map<int, Aplicatie>::iterator itr;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		f << itr->second.getName() << " " << itr->second.getConsumMemorieKb() << " " << itr->second.getStatus() << endl;
	}
	f.close();
}

//destructor
RepoFile::~RepoFile()
{
}