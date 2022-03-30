#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int* tablica(string a)
{
	
	if(a=="maly_lotek_5")
	{
		int *t=new int[5];
		for(int i=0;i<5;i++)
		{
			srand(time(NULL));
			t[i]=rand() % 42 + 1;
		}
		return t;
	}
	else if(a=="duzy_lotek_6")
	{
		int *t=new int[6];
		for(int i=0;i<6;i++)
		{
			t[i]=rand() % 49 + 1;
		}
		return t;
	}
	else if(a=="multilotek_10")
	{
		int *t=new int[10];
		for(int i=0;i<5;i++)
		{
			t[i]=rand() % 80 + 1;
		}
		return t;
	}
	else
	{
		cout<<"Blad"<<endl;
		return 0;
	}
}

int main()
{
	string a="maly_lotek_5";
	
	int *t=tablica(a);
	
	for(int i=0;i<5;i++)
	{
		cout<<t[i]<<'\t';
	}
	cout<<endl;
	
	delete [] t;
	t=nullptr;
	return 0;
}
