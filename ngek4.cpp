#include <iostream>
using namespace std;

int main()
{
    int nilai[100];                     // membuat array untuk menyimpan nilai
    int n = 0, input, hapus, count = 0; // variabel untuk menyimpan input dari user dan jumlah data yang dihapus

    cout << "Masukkan seluruh nilai (akhiri dengan angka 0): " <<endl;
    while (cin >> input && input != 0)
    {                       // meminta input dari user selama nilai yang dimasukkan bukan 0
        nilai[n++] = input; // menambahkan nilai ke dalam array
    }

    cout << "Masukkan nilai yang ingin dihapus: ";
    cin >> hapus; // meminta input nilai yang ingin dihapus

    for (int i = 0; i < n; i++)
    {
        if (nilai[i] == hapus)
        {            // jika nilai sama dengan nilai yang ingin dihapus
            count++; // menambah jumlah data yang dihapus
            for (int j = i; j < n - 1; j++)
            { // memindahkan semua data setelah data yang dihapus
                nilai[j] = nilai[j + 1];
            }
            n--; // mengurangi jumlah data dalam array
            i--; // memastikan bahwa data yang sama dapat dihapus jika ada
        }
    }

    cout << "Nilai " << hapus << " dihapus sebanyak " << count << " kali." << endl;
    cout << "Nilai terbaru: [";
    for (int i = 0; i < n; i++)
    { // menampilkan nilai terbaru
        cout << nilai[i] << (i == n - 1 ? "]\n" : ", ");
    }

    return 0;
}
