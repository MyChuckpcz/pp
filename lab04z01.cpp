#include <iostream>

using namespace std;

int dlugosc(const char* zrodlo)
{
	int dlugosc=0;
	
	while(zrodlo[dlugosc]!='\0')
	{
		dlugosc++;
	}
	return dlugosc;
}

char* wstaw(const char* zrodlo, char symbol)
{
	cout<<"char* wstaw"<<endl;
	int d=dlugosc(zrodlo);
	char* a = new char[d];
	for(int i=0;i<d;i++)
	{
		if(i%3==0)
		{
			a[i]=symbol;
		}
		else
		{
			a[i]=zrodlo[i];
		}
	}
	for(int i=0;i<d;i++)
	{
		cout<<a[i]<<'\t';
	}
	cout<<endl<<endl;
	return a;
}
/*
void wstaw(char* cel, const char* zrodlo,char symbol)
{
	cout<<"void wstaw"<<endl;
	int d=dlugosc(zrodlo);
	//cel=new char[d];
	for(int i=0;i<d;i++)
	{
		if(i%3==0)
		{
			cel[i]=symbol;
		}
		else
		{
			cel[i]=zrodlo[i];
		}
	}
	for(int i=0;i<d;i++)
	{
		cout<<cel[i]<<'\t';
	}
	cout<<endl<<endl;
	//delete[]cel;
	//cel=nullptr;
}
*/
/*
void wstaw1(char*& cel, const char* zrodlo, char symbol)
{
	cout<<"void wstaw1"<<endl;
	int d=dlugosc(zrodlo);
	cel=new char[d];
	for(int i=0;i<d;i++)
	{
		if(i%3==0)
		{
			cel[i]=symbol;
		}
		else
		{
			cel[i]=zrodlo[i];
		}
	}
	for(int i=0;i<d;i++)
	{
		cout<<cel[i]<<'\t';
	}
	cout<<endl<<endl;
	delete[]cel;
	cel=nullptr;
}
*/

/*
int szukaj(const char* a,char znak)
{
	int d=dlugosc(a);
	int c=0;
	for(int i=0;i<d;i++)
	{
		if(a[i]==znak)
		{
			c++;
		}
	}
	return c;
}
*/
int main(int argc, char* argv[])
{
	if(argc !=3)
	{
		cerr<<"nie poprawna ilosc argumetnow"<<endl;
		cerr<<"./nazwa tablica znak"<<endl;
		return 1;
	}
	int d=dlugosc(argv[1]);
	//pkt1
	char* a=wstaw(argv[1],argv[2][0]);
	
	char* b, *c;
	//b=new char[d];
	
	//pk2
	//wstaw(b,argv[1],argv[2][0]);
	
	//pkt3
	//wstaw1(c,argv[1],argv[2][0]);
	
	//pkt4
	cout<<a<<endl;
	//cout<<szukaj(a,'s')<<endl;
	
	delete[]a;
	a=nullptr;
	//delete[]b;
	//b=nullptr;
	
	
	return 0;
}
