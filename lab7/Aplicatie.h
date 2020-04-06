#pragma once
#include <ostream>
using namespace std;

class Aplicatie {
private:
	char* name;
	int consumMemorieKb;
	char* status;
public:
	Aplicatie();
	Aplicatie(const char* name, int consumMemorieKb, const char* status);
	Aplicatie(const Aplicatie& a);
	~Aplicatie();
	char* getName();
	int getConsumMemorieKb();
	char* getStatus();
	void setName(const char* name);
	void setConsumMemorieKb(int consumMemorieKb);
	void setStatus(const char* status);
	Aplicatie& operator=(const Aplicatie& a);
	bool operator==(const Aplicatie& a);
	friend ostream& operator<<(ostream& os, const Aplicatie& a);
};
