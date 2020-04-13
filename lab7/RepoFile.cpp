#include "RepoFile.h"
#include <fstream>
#include <string>
using namespace std;

//constructor implicit
RepoFile<Aplicatie>::RepoFile():Repo(){
	fis = "";
}

//construcor cu paramentru
RepoFile<Aplicatie>::RepoFile(const char* fileName):Repo()
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int consumMemorieKb;
	char* statusV = new char[10];
	char* statusN = new char[10];
	while (!f.eof()) {
		f >> nume >> consumMemorieKb;
		if (nume != "") {
			Aplicatie a(nume, consumMemorieKb, statusV, statusN);
			aplicatii.insert(pair<int, Aplicatie>(contor++, a));
		}
	}
	delete[] nume; delete[] statusV; delete[] statusN;
	f.close();
}

//citire din fisier
void RepoFile<Aplicatie>::loadFromFile(const char* fileName, int& totalRAM)
{
	aplicatii.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	int consumMemorieKb;
	char statusV[5] = "ram";
	char statusN[5] = "ram";
	while (!f.eof()) {
		f >> nume >> consumMemorieKb;
		if (strcmp(nume, "") != 0) {
			Aplicatie a(nume, consumMemorieKb, statusV, statusN);
			aplicatii.insert(pair<int, Aplicatie>(contor++, a));
			totalRAM += a.getConsumMemorieKb();
		}
	}
	delete[] nume; 
	f.close();
}


//scriere in fisier
void RepoFile<Aplicatie>::saveToFile()
{
	ofstream f(fis);
	map<int, Aplicatie>::iterator itr;
	//map<int, Aplicatie> res = r.getAll();
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		f << itr->second.getName() << " " << itr->second.getConsumMemorieKb() << endl;
		//f << itr->second.getName() << " " << itr->second.getConsumMemorieKb() << " " << itr->second.getStatusV() << " " << itr->second.getStatusN() << endl;
	}
	f.close();
}

//destructor
RepoFile<Aplicatie>::~RepoFile()
{
}
