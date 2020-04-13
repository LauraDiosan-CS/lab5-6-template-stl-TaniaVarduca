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
	assert((a1.getName() == NULL) && (a1.getConsumMemorieKb() == 0) && (a1.getStatusV() == NULL) && (a1.getStatusN() == NULL));
	char a[5] = "a"; char s[5] = "ram"; char s1[5] = "ram";
	Aplicatie a2(a, 5, s, s1); //constructor cu param
	assert((strstr(a2.getName(), "a")) && (a2.getConsumMemorieKb() == 5) && (strstr(a2.getStatusV(), "ram")) && (strstr(a2.getStatusN(), "ram")));
	Aplicatie a3(a2); //constructor de copiere
	assert(a3 == a2);
}

//teste setteri, getteri
void testSetGet() {
	Aplicatie a; char b[5] = "a"; char s[5] = "ram"; char s1[5] = "swap";
	a.setName(b);
	a.setConsumMemorieKb(1);
	a.setStatusV(s);
	a.setStatusN(s1);
	assert((strstr(a.getName(), "a")) && (a.getConsumMemorieKb() == 1) && (strstr(a.getStatusV(), "ram")) && (strstr(a.getStatusN(), "swap")));
}

//test operator de egalitate
void testEqual() {
	char a[5] = "a"; char b[5] = "b"; char s1[5] = "ram"; char s2[5] = "swap";
	Aplicatie a1(a, 3, s1, s1);
	Aplicatie a2(b, 12, s2, s2);
	a1 = a2;
	assert((strstr(a1.getName(), "b")) && (a1.getConsumMemorieKb() == 12) && (strstr(a1.getStatusV(), "swap")) && (strstr(a1.getStatusN(), "swap")));
}

//teste repository
void testRepoFile() {
	RepoFile<Aplicatie> rf;
	assert(rf.getSize() == 0); //dimensiune
	
	int ram = 0;
	rf.loadFromFile("aplicatiiTest.txt", ram); //citire din fisier
	assert(rf.getSize() == 2);

	Aplicatie a = Aplicatie("Aplic3", 3, "swap", "ram");
	rf.addAplicatie(a); //adaugare
	rf.saveToFile();
	assert(rf.getSize() == 3);
	
	/*map<int, Aplicatie> aplicatii = r.getAll();
	map<int, Aplicatie>::iterator itr;
	cout << endl << "Aplicatiile sunt: " << endl;
	for (itr = aplicatii.begin(); itr != aplicatii.end(); ++itr) {
		cout << "cheia: " << itr->first << ", aplicatia: " << itr->second;
		cout << endl;
	}*/
	rf.delAplicatie(2); //stergere
	rf.saveToFile();
	assert(rf.getSize() == 2);
	
	map<int, Aplicatie> res; res = rf.getAll(); //getAll
	assert(res.size() == 2);

	char nume[10] = "nume", status[10] = "ram";
	rf.updateAplicatie(res.at(0), 0, nume, 500, status); //update
	Aplicatie c = res.at(0);
	assert(strstr(res.at(0).getName(), "nume") && res.at(0).getConsumMemorieKb() == 500 && strstr(res.at(0).getStatusN(), "ram"));

	int n = rf.getSize();
	Aplicatie b = Aplicatie("Aplic4", 4, "ram", "swap");
	rf.addAplicatie(b);
	rf.saveToFile(); //save to file
	assert(rf.getAll().size() == (n + 1));

	rf.delAplicatie(3);
	char ch[2] = "a";
	rf.updateAplicatie(res.at(0), 0, ch, 1, status);
	rf.saveToFile();
}

void testService() {
	Service s;
	assert(s.getSize() == 0);

	RepoFile<Aplicatie> rf;
	Repo<Aplicatie>* r = &rf; int ram = 0;;
	s.setRepo(r);
	r->loadFromFile("aplicatiiTest.txt", ram);
	assert(s.getSize() == 2);
	assert(ram == 3);
	
	char w[5] = "swap"; 
	int capacitate = 10; 
	ram += 9;
	s.addRAM(ram, capacitate);  // test ram la adaugarea unei aplicatii
	assert(ram == 9 && strcmp(s.getAll().at(0).getStatusN(), w) == 0 && strcmp(s.getAll().at(1).getStatusN(), w) == 0);

	ram -= 9;
	s.delRAM(ram, capacitate, 9); //test ram la stergerea unei aplicatii
	assert(ram == 3 && strcmp(s.getAll().at(0).getStatusN(), w) != 0 && strcmp(s.getAll().at(1).getStatusN(), w) != 0);
}


void tests()
{
	cout << "first tests ..." << endl;
	testConstructors();
	testSetGet();
	testEqual();
	testRepoFile();
	testService();
	cout <<endl<< "all tests are ok ... good job!" << endl << endl;
}
