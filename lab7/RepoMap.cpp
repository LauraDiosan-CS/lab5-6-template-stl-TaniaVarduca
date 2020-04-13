#include "RepoMap.h"
#include "Aplicatie.h"
#include <iostream>
using namespace std;

////constructor fara param
//template <class T>  Repo<T>::Repo() {
//}
//
////constuctor de copiere
//template <class T> Repo<T>::Repo(const Repo& r) {
//	this->aplicatii = r.aplicatii;
//	this->contor = r.contor;
//}
////destructorul
//template <class T> Repo<T>::~Repo() {
//}
//
////adaugarea unui aplicatii
//template <class T> void Repo<T>::addAplicatie(T& a) {
//	aplicatii.insert(pair<int, Aplicatie>(contor++, a));
//}
//
////returnarea tuturor aplicatiilor
//template <class T> map<int, T> Repo<T>::getAll() {
//	return aplicatii;
//}
//
////stergerea unei aplicatii
//template <class T> void Repo<T>::delAplicatie(int pos)
//{
//	aplicatii.erase(pos);
//}
//
////update la o aplicatie
//template <class T> void Repo<T>::updateAplicatie(T& a, int pos, char* name, int consumMemorieKb, char* status)
//{
//	a.setName(name);
//	a.setConsumMemorieKb(consumMemorieKb);
//	a.setStatus(status);
//	aplicatii.at(pos) = a;
//}
//
////dimensiune map
//template <class T> int Repo<T>::getSize() {
//	return aplicatii.size();
//}