#include <iostream>
using namespace std;

void wypisz(const int* t, const unsigned int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		cout<<t[i]<<endl;
	}
}

int main()
{
	const unsigned int n=10;
	int A[n];
	for(unsigned int i=0; i<n; i++)
	{
		A[i] = -5+i;
	}
	wypisz(A,n);
	return 0;
}
