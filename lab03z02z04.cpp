#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;
//g++ -Wwszyst -pedantic -g -o lab03z02 lab03z02.cpp
//valgrind --leak-sprawdz=yes ./lab03z02
//ZESTAW II
void pamiecNew(int* t, const unsigned int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		t[i]=0;
	}
}
void pamiecDel(int *t, const unsigned int n)
{
	delete [] t;
	t = nullptr;
}
void wypelnij_losowo(int* t, const unsigned int n, int a, int b)
{
    int range = b - a + 1;
    srand(time(NULL));
    for (unsigned int i = 0; i < n; ++i)
		t[i] = rand() % range + a;
}
int* liczby_uzyt(const unsigned int n)
{
	int *t=new int [n];
	cout<<"Podaj "<<n<<" typów: ";
	for(unsigned int i=0;i<n;i++)
	{
		cin>>t[i];
	}
	return t;
}
void wypisz(const int* t, const unsigned int n)
{
	for(unsigned int i=0; i<n; ++i)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
unsigned int sprawdz(const int* t1, const int* t2, const unsigned int s1, const unsigned int s2)
{
	unsigned int n=0;
	for (unsigned int i = 0;i < s1;i++)
	{
		for (unsigned int j = 0;j < s2;j++)
		{
			if (t1[i] == t2[j])
			{
				n++;
			}
		}
	}
	if (n > 0)
	{
		return n;
	}
	return 0;
}

int main(){
	cout<<"Podaj min i max losowanych liczb: ";
	unsigned int min, max, s1 = 49, s2 = 6;
	cin>>min>>max;
	int *wszyst= new int [s1];
	pamiecNew(wszyst,s1);
	wypelnij_losowo(wszyst,s1,min,max);
	int *uzyt=liczby_uzyt(s2);
	cout<<"Trafiłeś: "<<sprawdz(wszyst,uzyt,s1,s2)<<" liczby" << endl;
	wypisz(wszyst,s1);
	pamiecDel(uzyt,s2);
	pamiecDel(wszyst,s1);
	return 0;
}
