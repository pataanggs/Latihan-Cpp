//RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;
int main()
{
    int i, n, j;
    int matriks[3][3];
    cout << "Masukkan Elemen Array 3x3" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> matriks[i][j];
        }
    }
    cout << "Elemen Pada Array" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hasil" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << matriks[j][i] << " ";
        }
        cout << endl;
    }
}