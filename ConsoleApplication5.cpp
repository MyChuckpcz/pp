#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
typedef double** matrix;
void pamiecNew(matrix& b, const int& m_, const int& n_)
{
    b = new double* [m_];
    for (int i = 0; i < m_; ++i)
        b[i] = new double[n_];
}




void pamiecDel(matrix& b, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
        delete[]b[i];

    delete[]b;
}
int wypelnij(matrix& b, const int& m_, const int& n_, const int& w)
{
    for (int i = 0; i < m_; ++i)
        for (int j = 0; j < n_; ++j)
            b[i][j] = w;
    return 0;
}
int wyswietl(const matrix& c, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
    {
        for (int j = 0; j < n_; ++j)
            cout << "\t" << c[i][j];
        cout << endl;
    }
    return 0;
}
int wypelnij_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ)
{
    int zakres = maxZ - minZ + 1;
    srand(time(NULL));
    for (int i = 0; i < m_; ++i)
        for (int j = 0; j < n_; ++j)
            b[i][j] = rand() % zakres + minZ;
    return 0;
}
int zapiszDoPliku(string nazwaPliku, const matrix& c, const int& m_, const int& n_)
{
    ofstream plik;
    plik.open(nazwaPliku.c_str());
    for (int i = 0; i < m_; ++i)
    {
        for (int j = 0; j < n_; ++j)
            plik << "\t" << c[i][j];
        plik << endl;
    }
    plik.close();
    return 0;
}
int wypelnij_los_sym(matrix& b, const int& m_, const int& n_, const int& startZ, const int& endZ)
{
    int zakres = endZ - startZ + 1;
    srand(time(NULL));
    for (int i = 0; i < m_; ++i)
        for (int j = i; j < n_; ++j)
            b[i][j] = b[j][i] = rand() % zakres + startZ;
    return 0;
}
bool czySymetryczna(const matrix& c, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
    {
        for (int j = i + 1; j < n_; ++j)
            if (c[i][j] != c[j][i])
                return false;
    }
    return true;

}

int czytajZpliku(string nazwaPliku, matrix& b, const int& m_, const int& n_)
{
    ifstream plikA;
    plikA.open(nazwaPliku.c_str());
    for (int i = 0; i < m_; ++i)
        for (int j = 0; j < n_; ++j)
            plikA >> b[i][j];
    plikA.close();
    return 0;
}

void dodawanie(matrix& A, matrix& B, matrix& C, const int& m_, const int& n_)
{
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < n_;j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
}


void odejmowanie(matrix& A, matrix& B, matrix& C, const int& m_, const int& n_)
{
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < n_;j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    
}

void mnozenie(matrix& A, matrix& B, matrix& C, const int& m_, const int& n_, const int& k_)
{
    int suma = 0;
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < k_;j++)
        {
            suma = 0;
            for (int s = 0;s < n_;s++)
            {
                suma = suma + A[i][s] * B[s][j];
            }
            C[i][j] = suma;
        }
    }
   
}

void transponowanie(matrix& A, matrix& B, const int& m_, const int& n_)
{
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < n_;j++)
        {
            B[j][i] = A[i][j];
        }
    }
}
double wyznacznik(matrix& A, const int& n_)
{
    double det=A[0][0];
    for (int s = 0;s < n_ - 1;s++)
    {
        for (int i = s + 1;i < n_;i++)
        {
            for (int j = s + 1;j < n_;j++)
            { 
                A[i][j] = A[i][j] - A[i][s] / A[s][s] * A[s][j];
            }
        }
        det = det * A[s + 1][s + 1];
    }
    return det;
}

void odwracanie(matrix& A,const int& m_, const int& n_)
{

    double c, d;
    cout << m_;
    for (int i = 0;i < m_;i++)
    {
        for (int j = m_;j < n_;j++)
        {
            A[i][j] = 0;
        }
    }
    for (int i = 0;i < m_;i++)
    {
        A[i][i + m_] = 1;
    }

    wyswietl(A, m_, n_);

    for (int s = 0;s < m_;s++)
    {
        c = A[s][s];
        A[s][s] = A[s][s] - 1;
        for (int j = s + 1;j < n_;j++)
        {
            d = A[s][j] / c;
            for (int i = 1;i < m_;i++)
            {
                A[i][j] = A[i][j] - d * A[i][s];
            }
        }
    }
    for (int i = 0;i < m_;i++)
    {
        for (int j = m_ + 1;j < n_;j++)
        {
            cout << " " << A[i][j];
        }
    }
}

int main()
{
    
    int mA = 4, nA = 3;
    matrix A;
    pamiecNew(A, mA, nA);
    czytajZpliku("mA.txt", A, mA, nA);
    cout << "macierz A" << endl;
    wyswietl(A, mA, nA);
    
    int mB = 4, nB = 3;
    matrix B;
    pamiecNew(B, mB, nB);
    czytajZpliku("mB.txt", B, mB, nB);
    cout << "macierz B" << endl;
    wyswietl(B, mB, nB);
    
    int mC = 4, nC = 3;
    matrix C;
    pamiecNew(C, mC, nC);
    czytajZpliku("mC.txt", C, mC, nC);
    cout << "macierz C" << endl;
    wyswietl(C, mC, nC);

    int mD = 4, nD = 4;
    matrix D;
    pamiecNew(D, mD, nD);
    czytajZpliku("mD.txt", D, mD, nD);
    cout << "macierz D" << endl;
    wyswietl(D, mD, nD);

    int mE = 4, nE = 4;
    matrix E;
    pamiecNew(E, mE, nE);
    czytajZpliku("mE.txt", E, mE, nE);
    cout << "macierz E" << endl;
    wyswietl(E, mE, nE);

    int mF = 4, nF = 1;
    matrix F;
    pamiecNew(F, mF, nF);
    czytajZpliku("mF.txt", F, mF, nF);
    cout << "macierz F" << endl;
    wyswietl(F, mF, nF);



    //a)
    int mW1 = 4, nW1 = 3;
    matrix W1;
    pamiecNew(W1, mW1, nW1);
    cout << "macierz W1" << endl;
    dodawanie(A, B, W1, mW1, nW1);
    odejmowanie(W1,C,W1,mW1,nW1);
    wyswietl(W1, mW1, nW1);
    zapiszDoPliku("L1a.txt", W1, mW1, nW1);

    //b)
    int mW2p = 3, nW2p = 4;
    matrix W2p;
    pamiecNew(W2p, mW2p, nW2p);
    transponowanie(B, W2p, mB, nB);

    int mW2 = 4, nW2 = 4;
    matrix W2;
    pamiecNew(W2, mW2, nW2);
    cout << "macierz W2" << endl;
    mnozenie(A, W2p, W2, mA, nA, nW2p);
    wyswietl(W2, mW2, nW2);
    zapiszDoPliku("L2a.txt", W2, mW2, nW2);

    //c)
    int mW3 = 4, nW3 = 4;
    matrix W3;
    pamiecNew(W3, mW3, nW3);
    cout << "macierz W3" << endl;
    mnozenie(E, D, W3, mE, nE, nD);
    wyswietl(W3, mW3, nW3);
    zapiszDoPliku("L3a.txt", W3, mW3, nW3);

    //d)
    double W4 = wyznacznik(D, nD);
    cout << "W4: wyznacznik macierzy D" << endl << "\t" << W4 << endl;

    //e)
    double W5 = wyznacznik(E, nE);
    cout << "W5: wyznacznik macierzy E" << endl << "\t" << W5 << endl;

    //f)
    int mW6 = mE, nW6 = nF;
    matrix W6;
    pamiecNew(W6, mW6, nW6);
    cout << "macierz W6" << endl;
    mnozenie(E,F,W6,mE,nE,nF);
    wyswietl(W6, mW6, nW6);
    zapiszDoPliku("L6a.txt", W6, mW6, nW6);

    //g)
    int mW7 = mE, nW7 = 2 * nE;
    matrix W7;
    pamiecNew(W7, mW7, nW7);
    czytajZpliku("mE.txt", W7, mE, nE);
    cout << "E^-1" << endl;
    wyswietl(W7, mW7, nW7);
    odwracanie(W7, mW7, nW7);


    pamiecDel(A, mA, nA);
    pamiecDel(B, mB, nB);
    pamiecDel(C, mC, nC);
    pamiecDel(D, mD, nD);
    pamiecDel(E, mE, nE);
    pamiecDel(F, mF, nF);
    

    pamiecDel(W1, mW1, nW1);
    pamiecDel(W2, mW2, nW2);
    pamiecDel(W2p, mW2p, nW2p);
    pamiecDel(W3, mW3, nW3);
    pamiecDel(W6, mW6, nW6);
    pamiecDel(W7, mW7, nW7);
    return 0;
}