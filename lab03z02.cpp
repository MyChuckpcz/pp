#include <iostream>
using namespace std;

int* utworz1(const unsigned int n)
{
	int* t=new int[n];
	for(unsigned int i=0;i<n;i++)
	{
		t[i]=i;
		cout<<t[i]<<endl;
	}
	delete [] t;
	t=nullptr;
	return t;
}

int main()
{
	unsigned int n;
	cin>>n;
	cout<<utworz1(n)<<"<-"<<endl;
	
	return 0;
}
