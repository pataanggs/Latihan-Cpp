#include <iostream>
using namespace std;

int main() {
    int jumlah_mahasiswa;
    float total_tinggi = 0;

    // Menerima input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;

    // Menerima input tinggi badan untuk setiap mahasiswa
    for (int i = 1; i <= jumlah_mahasiswa; ++i) {
        int nim_angka_terakhir;
        float tinggi_mahasiswa;

        cout << "Masukkan 2 angka terakhir dari NIM mahasiswa ke-" << i << ": ";
        cin >> nim_angka_terakhir;

        cout << "Masukkan tinggi badan mahasiswa ke-" << i << " (cm): ";
        cin >> tinggi_mahasiswa;

        // Menambahkan tinggi badan ke total
        total_tinggi += tinggi_mahasiswa;
    }

    // Menghitung rata-rata tinggi badan
    float rata_rata = total_tinggi / jumlah_mahasiswa;

    // Menampilkan rata-rata tinggi badan
    cout << "Rata-rata tinggi badan dari " << jumlah_mahasiswa << " mahasiswa adalah: " << rata_rata << " cm" << endl;

    return 0;
}
