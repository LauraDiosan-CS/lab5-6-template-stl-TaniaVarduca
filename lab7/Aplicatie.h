#pragma once
#include <ostream>
using namespace std;

class Aplicatie {
private:
	char* name;
	int consumMemorieKb;
	char* statusV;
	char* statusN;
public:
	Aplicatie();
	Aplicatie(const char* name, int consumMemorieKb, const char* statusV, const char* statusN);
	Aplicatie(const Aplicatie& a);
	~Aplicatie();
	char* getName();
	int getConsumMemorieKb();
	char* getStatusV();
	char* getStatusN();
	void setName(const char* name);
	void setConsumMemorieKb(int consumMemorieKb);
	void setStatusV(const char* statusV);
	void setStatusN(const char* statusN);
	Aplicatie& operator=(const Aplicatie& a);
	bool operator==(const Aplicatie& a);
	friend ostream& operator<<(ostream& os, const Aplicatie& a);
};
