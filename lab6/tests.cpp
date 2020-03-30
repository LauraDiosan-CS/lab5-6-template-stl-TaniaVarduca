#include "Aplicatie.h"
#include "Repo.h"
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
void testRepo() {
	Repo r;
	char x[10] = "a"; char b[10] = "b"; char s1[5] = "ram"; char s2[5] = "swap";
	Aplicatie a(x, 10, s1);
	r.addElem(a); //adaugare
	assert(r.getSize() == 1); //dimensiune
	Aplicatie a1(b, 11, s2);
	r.addElem(a1);
	assert(r.getSize() == 2);
	vector<Aplicatie> res; res = r.getAll(); //getAll
	assert(res[0] == a && res[1] == a1);
}

//apelare teste si mesaje de succes
void tests() {
	cout << "first tests ..." << endl;
	testConstructors();
	testSetGet();
	testEqual();
	testRepo();
	cout << "all tests are ok ... good job!" << endl << endl;
}