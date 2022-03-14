#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;
//g++ -Wall -pedantic -g -o lab03z01 lab03z01.cpp
//valgrind --leak-check=yes ./lab03z01

void wypisz(const int* t, const unsigned int n)
{
	for(unsigned int i=0; i<n; ++i)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
int* utworz1(const unsigned int n){
	int *t = new int [n];
	return t;
}
void utworz2(int*& t, const unsigned int n)
{
	t = new int [n];
	for(unsigned int i=0;i<n;i++)
	{
		t[i]=0;
	}
}
void utworz3(int* t, const unsigned int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		t[i]=0;
	}
}
int usun(int *t, const unsigned int n)
{
	delete [] t;
	t = nullptr;
	return 0;
}
void zadanie4(int* t, const unsigned int n)
{
	unsigned int m=n/2;
	for (unsigned int i = 0;i < m;i++)
	{
		t[i] = 0;
	}
	for (unsigned int i = m;i < n;i++)
	{
		t[i] = i + 1;
	}
}
void wypelnij_losowo(int* t, const unsigned int n, int a, int b)
{
    int zakres = b - a + 1;
    srand(time(NULL));
	for (unsigned int i = 0; i < n; ++i)
	{
		t[i] = rand() % zakres + a;
	}
}
int* suma1(const int* t1, const int* t2, const unsigned int n)
{
	int *t3=new int [n];
	for (unsigned int i = 0;i < n;i++)
	{
		t3[i] = t1[i] + t2[i];
	}
	return t3;
}
void suma2(const int* t1, const int* t2, int*& t3, const unsigned int n)
{
	t3 = new int[n];
	for(unsigned int i=0;i<n;i++)
		t3[i]=t1[i]+t2[i];
	cout<<"Suma 2: ";
	for(unsigned int i=0;i<n;i++)
		cout<<t3[i]<<" ";
	cout<<"\n";
}
void suma3(const int* t1, const int* t2, int* t3, const unsigned int n)
{
	for (unsigned int i = 0;i < n;i++)
	{
		t3[i] = t1[i] + t2[i];
	}
	cout<<"Suma 3: ";
	for (unsigned int i = 0;i < n;i++)
	{
		cout << t3[i] << " ";
	}
	cout<<"\n";
}
int* zadanie8(const int* t, const unsigned int n,const unsigned int m)
{
	int *t2=new int [n];
	unsigned int j=0;
	for(unsigned int i=0;i<n;i++)
	{
		if(i==m){
			j++;
		}
		t2[i]=t[j];
		j++;
	}
	return t2;
}
int* zadanie9(const int* t, const unsigned int n,const unsigned int m)
{
	int *t2=new int [n];
	t2[0]=m;
	for(unsigned int i=1;i<n;i++)
	{
		t2[i]=t[i];
	}
	return t2;
}
int main()
{
	unsigned int n=7,m;
	int T[]={1,2,3,4,5,6,7};
	wypisz(T, n);
	cout<<"Podaj wielkość tablicy: ";
	cin>>n;
	int *tt=nullptr;
	int *t = new int [n];
	int *w = utworz1(n);
	utworz2(tt,n);
	utworz3(t,n);
	usun(t,n);
	usun(w,n);
	usun(tt,n);
	//zadanie 4
	cout<<"zadanie 4"<<endl;
	int *zad4=nullptr;
	utworz2(zad4,n);
	zadanie4(zad4,n);
	wypisz(zad4,n);
	usun(zad4,n);
	//zadanie 5
	cout<<"zadanie 5" << endl;
	int *zad5=nullptr;
	utworz2(zad5,n);
	wypelnij_losowo(zad5,n,0,100);
	wypisz(zad5,n);
	usun(zad5,n);
	//zadanie 6
	cout<<"zadanie 6" << endl;
	int *zad6=nullptr;
	utworz2(zad6,n);
	int a,b;
	cout<<"Podaj min i max: ";
	cin>>a>>b;
	wypelnij_losowo(zad6,n,a,b);
	wypisz(zad6,n);
	usun(zad6,n);
	//zadanie 7
	cout<<"zadanie 7"<<endl<<"Podaj rozmiar tablicy: ";
	cin>>n;
	int *zad7_suma1_1=utworz1(n);
	int *zad7_suma1_2=utworz1(n);
	wypelnij_losowo(zad7_suma1_1,n,0,100);
	wypelnij_losowo(zad7_suma1_2,n,100,200);
	int *zad7_suma1_3=suma1(zad7_suma1_1,zad7_suma1_2,n);
	cout<<"Suma 1: "; wypisz(zad7_suma1_3,n);
	usun(zad7_suma1_1,n);
	usun(zad7_suma1_2,n);
	usun(zad7_suma1_3,n);
	int *zad7_suma2_1=nullptr;
	int *zad7_suma2_2=nullptr;
	int *zad7_suma2_3;
	utworz2(zad7_suma2_1,n);
	utworz2(zad7_suma2_2,n);
	wypelnij_losowo(zad7_suma2_1,n,0,100);
	wypelnij_losowo(zad7_suma2_2,n,100,300);
	suma2(zad7_suma2_1,zad7_suma2_2,zad7_suma2_3,n);
	usun(zad7_suma2_1,n);
	usun(zad7_suma2_2,n);
	usun(zad7_suma2_3,n);
	int *zad7_suma3_1=nullptr;
	int *zad7_suma3_2=nullptr;
	int *zad7_suma3_3=nullptr;
	utworz2(zad7_suma3_1,n);
	utworz2(zad7_suma3_2,n);
	utworz2(zad7_suma3_3,n);
	wypelnij_losowo(zad7_suma3_1,n,0,100);
	wypelnij_losowo(zad7_suma3_2,n,100,400);
	suma3(zad7_suma3_1,zad7_suma3_2,zad7_suma3_3,n);
	usun(zad7_suma3_1,n);
	usun(zad7_suma3_2,n);
	usun(zad7_suma3_3,n);
	//zadanie 8
	cout<<"zadanie 8" << endl<<"Podaj rozmiar tablicy: ";
	cin>>n;
	int *zad8=utworz1(n);
	wypelnij_losowo(zad8,n,0,100);
	wypisz(zad8,n);
	cout<<"Podaj nr indeksu do usuniecia z tablicy: ";
	cin>>m;
	unsigned int k=n-1;
	int *zad8_new=zadanie8(zad8,k,m);
	wypisz(zad8_new,k);
	usun(zad8,n);
	usun(zad8_new,k);
	//zadanie 9
	cout<<"zadanie 9" << endl"Podaj rozmiar tablicy: ";
	cin>>n;
	int *zad9=utworz1(n);
	wypelnij_losowo(zad9,n,0,100);
	wypisz(zad9,n);
	cout<<"Podaj liczbę do wpisania pod indeks nr 0: ";
	cin>>m;
	int *zad9_new=zadanie9(zad9,n,m);
	wypisz(zad9_new,n);
	usun(zad9,n);
	usun(zad9_new,n);
	return 0;
}


