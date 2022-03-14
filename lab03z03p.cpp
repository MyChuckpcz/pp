#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;


int** utworz1(const unsigned int n,const unsigned int m)
{
	int **t = new int* [m];
	for (unsigned int i=0;i<m;++i)
    {
        t[i] = new int [n];
    }
    for (unsigned int i=0;i<m; ++i)
    {
        for (unsigned int j = 0;j < n; ++j)
        {
            t[i][j] = 0;
        }
    }
	return t;
}
void utworz2(int**& t,const unsigned int n,const unsigned int m)
{
    t = new int* [m];
    for (unsigned int i=0;i<m;++i)
    {
        t[i] = new int[n];
	}
    for (unsigned int i = 0;i < m; ++i)
    {
        for (unsigned int j = 0;j < n; ++j)
        {
            t[i][j] = 0;
        }
    }
}
void usun(int**& b, const int& m, const int& n)
{
    for (int i = 0; i < m; ++i)
    {
        delete[]b[i];
    }
    delete []b;
}
int wypelnij(int**& b, const int& m, const int& n, const int& minZ, const int& maxZ)
{
    int zakres = maxZ - minZ + 1;
    srand(time(NULL));
    for (int i = 0;i < m; ++i)
    {
        for (int j = 0;j < n; ++j)
        {
            b[i][j] = rand() % zakres + minZ;
        }
    }
    return 0;
}
int suma(const int** &a, const int& m1,const int &n1, const int** &b , const int& m2,const int &n2, const int** &c)
{
    for(int i=0; i<m2; i++)
    {
        for(int j=0; j<n1; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    return 0;
}
int roznica(const int** &a, const int& m1,const int &n1, const int** &b , const int& m2,const int &n2, const int** &c)
{
    for(int i=0; i<m2; i++)
    {
        for(int j=0; j<n1; j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    return 0;
}
int iloczyn(const int** &a, const int& m1,const int &n1, const int** &b , const int& m2,const int &n2, const int** &c)
{
    int suma;
    for(int i=0; i<m1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            suma=0;
            for(int s=0; s<n1; s++)
            {
                suma+=a[i][s]*b[s][j];
            }
            c[i][j]=suma;
        }
    }
    return 0;
}
int transponowanie(const int** &a, const int& m1,const int &n1, const int** &b)
{
    for(int i=0; i<m1; i++)
    {
        for(int j=0; j<n1; j++)
        {
            b[i][j]=a[j][i];
        }
    }
    return 0;
}
int tabliczka(const int** &a, const int& m1,const int &n1)
{
	for(int i=0; i<m1; i++)
    {
		a[i][0]=i;
        for(int j=0; j<n1; j++)
        {
			a[0][j]=j;
        }
    }
    for(int i=1; i<m1; i++)
    {
        for(int j=1; j<n1; j++)
        {
			a[i][j]=i*j;
        }
    }
    return 0;
}
int wypisz(const int**& c, const int& m, const int& n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "\t" << c[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
int main(){
	unsigned int m1,n1,m2,n2,m3,n3,x;
	cout<<"Zadanie 2"<<endl;
	cin>>m1>>n1;
	//zadanie 2 - start
	int **a = utworz1(m1,n1);
	int**b;
	utworz2(b,m1,n1);
	wypisz(a,m1,n1);
	wypisz(b,m1,n1);
	usun(b,m1,n1);
	usun(a,m1,n1);
	//zadanie 2 - end
	cout<<"Podaj rozmiar macierzy A: ";
	cin>>m1>>n1;
	cout << "Macierz A" << endl;
	int** A;
    utworz2(A, m1, n1);
    wypelnij(A,m1,n1,0,100);
    wypisz(A,m1,n1);
    cout<<"Podaj rozmiar macierzy B: ";
	cin>>m2>>n2;
	cout << "Macierz B" << endl;
    int** B;
    utworz2(B, m2, n2);
    wypelnij(B,m2,n2,0,100);
    wypisz(B,m2,n2);
    for(;;){
		cout<<"0) Exit"<<endl<<"5) Zadanie 5" << endl << "6) Zadanie 6" << endl << "7) Zadanie 7" << endl << "8) Zadanie 8" << endl << "9) Zadanie 9" << endl;
		cin>>x;
		switch(x){
			case 0:
                break;
			case 5:
				cout << "Suma A + B" << endl << "(Macierz A - "<<m1<<"x"<<n1<<")" << endl << "(Macierz B - "<<m2<<"x"<<n2<<")" << endl << "Podaj rozmiar macierzy wynikowej: ";
				cin>>m3>>n3;
				int** C;
				utworz2(C, m3, n3);
				suma(A,m1,n1,B,m2,n2,C);
				wypisz(C,m3,n3);
				usun(C, m2, n2);
				break;
			case 6:
				cout << "Suma A - B" << endl << "(Macierz A - "<<m1<<"x"<<n1<<")" << endl << "(Macierz B - "<<m2<<"x"<<n2<<")" << endl << "Podaj rozmiar macierzy wynikowej: ";
				cin>>m3>>n3;
				utworz2(C, m3, n3);
				roznica(A,m1,n1,B,m2,n2,C);
				wypisz(C,m3,n3);
				usun(C, m2, n2);
				break;
			case 7:
				cout << "Suma A * B" << endl << "(Macierz A - "<<m1<<"x"<<n1<<")" << endl << "(Macierz B - "<<m2<<"x"<<n2<<")" << endl << "Podaj rozmiar macierzy wynikowej: ";
				cin>>m3>>n3;
				utworz2(C, m3, n3);
				iloczyn(A,m1,n1,B,m2,n2,C);
				wypisz(C,m3,n3);
				usun(C, m2, n2);
				break;
			case 8:
				cout << "Suma A^T" << endl << "(Macierz A - "<<m1<<"x"<<n1<<")" << endl << "Podaj rozmiar macierzy wynikowej: ";
				cin>>m3>>n3;
				utworz2(C, m3, n3);
				transponowanie(A,m1,n1,C);
				wypisz(C,n1,m1);
				usun(C, m2, n2);
				break;
			case 9:
				cout << "Tabliczka mnożenia" << endl << "Podaj rozmiar macierzy wynikowej: ";
				cin>>m3>>n3;
				utworz2(C,m3,n3);
				tabliczka(C,m3,n3);
				wypisz(C,n3,m3);
				usun(C,m3,n3);
				break;
		}	
	}
	
    usun(A,m1,n1);
    usun(B,m2,n2);
    return 0;
}
