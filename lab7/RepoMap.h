#pragma once
#pragma once
#include "Aplicatie.h" 
#include <map>
using namespace std;

template <class T> class Repo
{
protected:
	map<int, T> aplicatii;
	int contor;
public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	void addAplicatie(T& a);
	map<int, T> getAll();
	void delAplicatie(int pos);
	void updateAplicatie(T& a, int pos, char* name, int consumMemorieKb, char* statusN);
	int getSize();
	virtual void loadFromFile(const char* fileName, int&);
	virtual void saveToFile();
};

//constructor fara param
template <class T>  Repo<T>::Repo() {
}

//constuctor de copiere
template <class T> Repo<T>::Repo(const Repo& r) {
	this->aplicatii = r.aplicatii;
	this->contor = r.contor;
}

//destructorul
template <class T> Repo<T>::~Repo() {
}

//adaugarea unui aplicatii
template <class T> void Repo<T>::addAplicatie(T& a) {
	aplicatii.insert(pair<int, T>(contor++, a));
}

//returnarea tuturor aplicatiilor
template <class T> map<int, T> Repo<T>::getAll() {
	return aplicatii;
}

//stergerea unei aplicatii
template <class T> void Repo<T>::delAplicatie(int pos)
{
	aplicatii.erase(pos);
}

//update la o aplicatie
template <class T> void Repo<T>::updateAplicatie(T& a, int pos, char* name, int consumMemorieKb, char* statusN)
{
	a.setName(name);
	a.setConsumMemorieKb(consumMemorieKb);
	a.setStatusN(statusN);
	aplicatii.at(pos) = a;
}

//dimensiune map
template <class T> int Repo<T>::getSize() {
	return aplicatii.size();
}

template<class T>
inline void Repo<T>::loadFromFile(const char* fileName, int&)
{
}

template<class T>
inline void Repo<T>::saveToFile()
{
}
