#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;
typedef int** matrix;

matrix utworz1(const unsigned int n, const unsigned int m)
{
    matrix t = new int* [m];
    for (unsigned int i = 0;i < m;++i)
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
    return t;
}
void utworz2(matrix& t, const unsigned int n, const unsigned int m)
{
    t = new int* [m];
    for (unsigned int i = 0;i < m;++i)
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
void usun(matrix& B, const int& m, const int& n)
{
    for (int i = 0; i < m; ++i)
    {
        delete[]B[i];
    }
    delete[]B;
}
int wypelnij(matrix& B, const int& m, const int& n, const int& minZ, const int& maxZ)
{
    int zakres = maxZ - minZ + 1;
    srand(time(NULL));
    for (int i = 0;i < m; ++i)
    {
        for (int j = 0;j < n; ++j)
        {
            B[i][j] = rand() % zakres + minZ;
        }
    }
    return 0;
}
void suma(matrix& A, matrix& B, matrix& C, const int& m_, const int& n_)
{
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < n_;j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

}


void roznica(matrix& A, matrix& B, matrix& C, const int& m_, const int& n_)
{
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < n_;j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

}
void iloczyn(matrix& A, matrix& B, matrix& C, const int& m_, const int& n_, const int& k_)
{
    int suma = 0;
    for (int i = 0;i < m_;i++)
    {
        for (int j = 0;j < k_;j++)
        {
            suma = 0;
            for (int s = 0;s < n_;s++)
            {
                //cout << suma << " + " << A[i][s] << " * " << B[s][j];
                suma = suma + A[i][s] * B[s][j];
                //cout << " = " << suma << endl;
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
int tabliczka(matrix& A, const int& m1, const int& n1)
{
    for (int i = 0; i < m1; i++) {
        A[i][0] = i;
        for (int j = 0; j < n1; j++) {
            A[0][j] = j;
        }
    }
    for (int i = 1; i < m1; i++) {
        for (int j = 1; j < n1; j++) {
            A[i][j] = i * j;
        }
    }
    
    return 0;
}
int wypisz(const matrix& A, const int& m, const int& n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "\t" << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
int main() {
    unsigned int m1, n1, m2, n2, m3, n3, x;
    cout << "Zadanie 2" << endl;
    cin >> m1 >> n1;
    //zadanie 2 - start
    matrix a = utworz1(m1, n1);
    matrix b;
    utworz2(b, m1, n1);
    wypisz(a, m1, n1);
    wypisz(b, m1, n1);
    usun(b, m1, n1);
    usun(a, m1, n1);
    //zadanie 2 - end
    cout << "Podaj rozmiar macierzy A: ";
    cin >> m1 >> n1;
    cout << "Macierz A" << endl;
    matrix A;
    utworz2(A, m1, n1);
    wypelnij(A, m1, n1, 0, 100);
    wypisz(A, m1, n1);
    cout << "Podaj rozmiar macierzy B: ";
    cin >> m2 >> n2;
    cout << "Macierz B" << endl;
    matrix B;
    utworz2(B, m2, n2);
    wypelnij(B, m2, n2, 0, 100);
    wypisz(B, m2, n2);
    for (;;) {
        cout << "0 - Zakoncz" << endl << "5 - Zadanie 5" << endl << "6 - Zadanie 6" << endl << "7 - Zadanie 7" << endl << "8 - Zadanie 8" << endl << "9 - Zadanie 9" << endl;
        cin >> x;
        switch (x) {
        case 0:

            goto koniec;
            break;

        case 5:

            cout << "A + B" << endl << "(Macierz A - " << m1 << "x" << n1 << ")" << endl << "(Macierz B - " << m2 << "x" << n2 << ")" << endl << "Podaj rozmiar macierzy wynikowej: ";
            cin >> m3 >> n3;
            matrix C;
            utworz2(C, m3, n3);
            suma(A, B, C,m1, n1);
            wypisz(C, m3, n3);
            usun(C, m2, n2);
            break;

        case 6:

            cout << " A - B" << endl << "(Macierz A - " << m1 << "x" << n1 << ")" << endl << "(Macierz B - " << m2 << "x" << n2 << ")" << endl << "Podaj rozmiar macierzy wynikowej: ";
            cin >> m3 >> n3;
            utworz2(C, m3, n3);
            roznica(A, B, C, m1, n1);
            wypisz(C, m3, n3);
            usun(C, m2, n2);
            break;

        case 7:

            cout << "A * B" << endl << "(Macierz A - " << m1 << "x" << n1 << ")" << endl << "(Macierz B - " << m2 << "x" << n2 << ")" << endl << "Podaj rozmiar macierzy wynikowej : ";
            cin >> m3 >> n3;
            utworz2(C, m3, n3);
            iloczyn(A, B, C, m1, n1, n2);
            wypisz(C, m3, n3);
            usun(C, m2, n2);
            break;

        case 8:

            cout << "A^T" << endl << "(Macierz A - " << m1 << "x" << n1 << ")" << endl << "Podaj rozmiar macierzy wynikowej: ";
            cin >> m3 >> n3;
            utworz2(C, m3, n3);
            transponowanie(A, C, m1, n1);
            wypisz(C, n1, m1);
            usun(C, m2, n2);
            break;

        case 9:

            cout << "Tabliczka mnozenia" << endl << "Podaj rozmiar macierzy wynikowej: ";
            cin >> m3 >> n3;
            utworz2(C, m3, n3);
            tabliczka(C, m3, n3);
            wypisz(C, n3, m3);
            usun(C, m3, n3);

            break;
        }
    }
    koniec:
    usun(A, m1, n1);
    usun(B, m2, n2);
    return 0;
}
