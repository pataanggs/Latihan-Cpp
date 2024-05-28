// RA_Fathan Andi Kartagama_122140055
#include <iostream>
using namespace std;

int main()
{
    int angka, max = 0, min = 99999, ganjil = 0, genap = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> angka;

        if (angka > max)
        {
            max = angka;
        }

        if (angka < min)
        {
            min = angka;
        }

        if (angka % 2 == 0)
        {
            genap++;
        }
        else
        {
            ganjil++;
        }
    }

    cout << "Bilangan terbesar adalah: " << max << endl;
    cout << "Bilangan terkecil adalah: " << min << endl;
    cout << "Jumlah bilangan ganjil adalah: " << ganjil << endl;
    cout << "Jumlah bilangan genap adalah: " << genap << endl;

    return 0;
}
