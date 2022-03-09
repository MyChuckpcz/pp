#include <iostream>

using namespace std;

class Pytanie
{
	public:
	string tresc;
	string a,b,c,d;
	int nrPytania;
	string poprawna;
	string odpowiedz;
	int punkt;
	void wczytaj();
	void zadaj();
	void sprawdz();
};
