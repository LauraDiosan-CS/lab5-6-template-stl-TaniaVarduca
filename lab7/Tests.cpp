#include "Tests.h"
#include "Aplicatie.h"
#include "RepoFile.h"
#include"Service.h"
#include <iostream>
#include <assert.h>
#include "tests.h"
using namespace std;

//teste constructori
void testConstructors() {
	Aplicatie a1; //constructor implicit
	assert((a1.getName() == NULL) && (a1.getConsumMemorieKb() == 0) && (a1.getStatus() == NULL));
	char a[5] = "a"; char s[5] = "ram";
	Aplicatie a2(a, 5, s); //constructor cu param
	assert((strstr(a2.getName(), "a")) && (a2.getConsumMemorieKb() == 5) && (strstr(a2.getStatus(), "ram")));
	Aplicatie a3(a2); //constructor de copiere
	assert(a3 == a2);
}

//teste setteri, getteri
void testSetGet() {
	Aplicatie a; char b[5] = "a"; char s[5] = "ram";
	a.setName(b);
	a.setConsumMemorieKb(1);
	a.setStatus(s);
	assert((strstr(a.getName(), "a")) && (a.getConsumMemorieKb() == 1) && (strstr(a.getStatus(), "ram")));
}

//test operator de egalitate
void testEqual() {
	char a[5] = "a"; char b[5] = "b"; char s1[5] = "ram"; char s2[5] = "swap";
	Aplicatie a1(a, 3, s1);
	Aplicatie a2(b, 12, s2);
	a1 = a2;
	assert((strstr(a1.getName(), "b")) && (a1.getConsumMemorieKb() == 12) && (strstr(a1.getStatus(), "swap")));
}

//teste repository
void testRepoFile() {
	RepoFile r;
	assert(r.size() == 0); //dimensiune
	
	r.loadFromFile("aplicatiiTest.txt"); //citire din fisier
	assert(r.size() == 2);

	r.loadFromFile("aplicatiiTest.txt");
	r.addAplicatie(Aplicatie("Aplic3", 3, "swap")); //adaugare
	assert(r.size() == 3);
	r.saveToFile();

	r.loadFromFile("aplicatiiTest.txt");
	/*map<int, Aplicatie> aplicatii = r.getAll();
	map<int, Aplicatie>::iterator itr;
	cout << endl << "Aplicatiile sunt: " << endl;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		cout << "cheia: " << itr->first << ", aplicatia: " << itr->second;
		cout << endl;
	}*/
	r.delAplicatie(7); //stergere
	assert(r.size() == 2);
	r.saveToFile();

	r.loadFromFile("aplicatiiTest.txt");
	map<int, Aplicatie> res; res = r.getAll(); //getAll
	assert(res.size() == 2);

	char nume[10] = "nume", status[10] = "status";
	r.loadFromFile("aplicatiiTest.txt");
	//r.updateAplicatie(res.at(8), 12, nume, 500, status); //update
	Aplicatie a = res.at(8);
	//assert(strstr(res.at(8).getName(), "nume") && res.at(8).getConsumMemorieKb() == 500 && strstr(res.at(8).getStatus(), "swap"));

	r.loadFromFile("aplicatiiTest.txt");
	int n = r.size();
	r.addAplicatie(Aplicatie("Aplic4", 4, "ram"));
	r.saveToFile(); //save to file
	r.loadFromFile("aplicatiiTest.txt");
	assert(r.getAll().size() == (n + 1));

	r.delAplicatie(17);
	r.saveToFile();
}

void tests()
{
	cout << "first tests ..." << endl;
	testConstructors();
	testSetGet();
	testEqual();
	testRepoFile();
	cout << "all tests are ok ... good job!" << endl << endl;
}
