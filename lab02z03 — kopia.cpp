#include <iostream>

using namespace std;

double dodawanie(double a, double b)
{
	cout<<"podaj pierwsza liczbe: ";
	cin>>a;
	cout<<"podaj druga liczbe: ";
	cin>>b;
	return a+b;
}
int kalkulator()
{
	double a=0, b=0;
	int n;
	cout<<"1 - dodawanie"<<endl<<"0 - wyjscie"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		cout<<dodawanie(a,b)<<"<--- wynik"<<endl;
		break;
		
		case 0:
		break;
	}
	return 0;
}


int main()
{
	while(kalkulator());
	return 0;
}
