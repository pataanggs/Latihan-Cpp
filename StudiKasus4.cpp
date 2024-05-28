// RA_Fathan Andi Kartagama_122140055
#include <iostream>
using namespace std;

int main()
{
    int angka, i = 1, deret;

    cout << "Masukkan angka awal deret: ";
    cin >> angka;
    cout << "Masukkan jumlah deret yang ingin ditampilkan: ";
    cin >> deret;

    while (i < deret && angka % 2 == 0)
    {
        cout << angka << " ";
        i++;
        angka = angka / 2;
    }

    while (i < deret && angka % 2 == 1)
    {
        angka = angka + 1;
        while (angka % 2 == 0)
        {
            cout << angka << " ";
            i++;
            angka = angka / 2;
        }
    }

    cout << angka << " ";

    return 0;
}