//RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;

int main()
{
    int i, n, data[50];
    float rata, jumlah;

    cout << "Input ukuran array = ";
    cin >> n;
    cout << endl;

    for (i = 0; i < n; i++)
    {
        cout << "Elemen array ke-" << i + 1 << " = ";
        cin >> data[i];
        jumlah += data[i];
    }

    rata = jumlah / n;

    cout << endl;
    cout << "Nilai Rata-rata = " << rata << "%" << endl;
}