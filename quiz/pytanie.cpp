#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void Pytanie::wczytaj()
{
	fstream plik;
	plik.open("quiz.txt",ios::in);
	
	if(plik.good()==false)
	{
		cout<<"blad"<<endl;
		exit(0);
	}
	int nrLinii=(nrPytania-1)*6+1;
	int aktualnyNr=1;
	string linia;
	while(getline(plik,linia))
	{
		if(aktualnyNr==nrLinii) tresc=linia;
		if(aktualnyNr==nrLinii+1) a=linia;
		if(aktualnyNr==nrLinii+2) b=linia;
		if(aktualnyNr==nrLinii+3) c=linia;
		if(aktualnyNr==nrLinii+4) d=linia;
		if(aktualnyNr==nrLinii+5) poprawna=linia;
		
		aktualnyNr++;
	}
	plik.close();
}
void Pytanie::zadaj()
{
	cout<<tresc<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<endl;
	cout<<"Odpowiedz: ";
	cin>>odpowiedz;
}
void Pytanie::sprawdz()
{
	if(odpowiedz==poprawna)
	{
		punkt=1;
	}
	else punkt=0;
}
