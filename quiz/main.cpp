#include <iostream>
#include "pytanie.h"
using namespace std;

int main()
{
	Pytanie p1;
	p1.nrPytania=1;
	p1.wczytaj();
	p1.zadaj();
	p1.sprawdz();
	return 0;
}
