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
void zad4(int* t, const unsigned int n)
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
int* zad8(const int* t, const unsigned int n,const unsigned int m)
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
int* zad9(const int* t, const unsigned int n,const unsigned int m)
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
	int *z4=nullptr;
	utworz2(z4,n);
	zad4(z4,n);
	wypisz(z4,n);
	usun(z4,n);
	//zadanie 5
	cout<<"zadanie 5" << endl;
	int *z5=nullptr;
	utworz2(z5,n);
	wypelnij_losowo(z5,n,0,100);
	wypisz(z5,n);
	usun(z5,n);
	//zadanie 6
	cout<<"zadanie 6" << endl;
	int *z6=nullptr;
	utworz2(z6,n);
	int a,b;
	cout<<"Podaj min i max: ";
	cin>>a>>b;
	wypelnij_losowo(z6,n,a,b);
	wypisz(z6,n);
	usun(z6,n);
	//zadanie 7
	cout<<"zadanie 7"<<endl<<"Podaj rozmiar tablicy: ";
	cin>>n;
	int *z7_s1_1=utworz1(n);
	int *z7_s1_2=utworz1(n);
	wypelnij_losowo(z7_s1_1,n,0,100);
	wypelnij_losowo(z7_s1_2,n,100,200);
	int *z7_s1_3=suma1(z7_s1_1,z7_s1_2,n);
	cout<<"Suma 1: "; wypisz(z7_s1_3,n);
	usun(z7_s1_1,n);
	usun(z7_s1_2,n);
	usun(z7_s1_3,n);
	int *z7_s2_1=nullptr;
	int *z7_s2_2=nullptr;
	int *z7_s2_3;
	utworz2(z7_s2_1,n);
	utworz2(z7_s2_2,n);
	wypelnij_losowo(z7_s2_1,n,0,100);
	wypelnij_losowo(z7_s2_2,n,100,300);
	suma2(z7_s2_1,z7_s2_2,z7_s2_3,n);
	usun(z7_s2_1,n);
	usun(z7_s2_2,n);
	usun(z7_s2_3,n);
	int *z7_s3_1=nullptr;
	int *z7_s3_2=nullptr;
	int *z7_s3_3=nullptr;
	utworz2(z7_s3_1,n);
	utworz2(z7_s3_2,n);
	utworz2(z7_s3_3,n);
	wypelnij_losowo(z7_s3_1,n,0,100);
	wypelnij_losowo(z7_s3_2,n,100,400);
	suma3(z7_s3_1,z7_s3_2,z7_s3_3,n);
	usun(z7_s3_1,n);
	usun(z7_s3_2,n);
	usun(z7_s3_3,n);
	//zadanie 8
	cout<<"zadanie 8" << endl<<"Podaj rozmiar tablicy: ";
	cin>>n;
	int *z8=utworz1(n);
	wypelnij_losowo(z8,n,0,100);
	wypisz(z8,n);
	cout<<"Podaj nr indeksu do usuniecia z tablicy: ";
	cin>>m;
	unsigned int k=n-1;
	int *z8_new=zad8(z8,k,m);
	wypisz(z8_new,k);
	usun(z8,n);
	usun(z8_new,k);
	//zadanie 9
	cout<<"zadanie 9" << endl<<"Podaj rozmiar tablicy: ";
	cin>>n;
	int *z9=utworz1(n);
	wypelnij_losowo(z9,n,0,100);
	wypisz(z9,n);
	cout<<"Podaj liczbę do wpisania pod indeks nr 0: ";
	cin>>m;
	int *z9_new=zad9(z9,n,m);
	wypisz(z9_new,n);
	usun(z9,n);
	usun(z9_new,n);
	return 0;
}


