#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    int nilai[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    sort(nilai, nilai + n);

    cout << "Nilai tertinggi berada di posisi paling bawah dan nilai terendah di posisi paling atas:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nilai = " << nilai[i] << endl;
    }

    int jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        jumlah += nilai[i];
    }

    float rata_rata = (float)jumlah / n;
    cout << "Jumlah nilai total: " << jumlah << endl;
    cout << "Nilai Rata-rata: " << rata_rata << endl;

    return 0;
}
