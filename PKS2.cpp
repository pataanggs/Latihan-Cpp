#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, vector<float>> data_tinggi; // Untuk menyimpan tinggi badan berdasarkan 2 angka terakhir NIM
    
    int jumlah_mahasiswa;
    
    // Menerima input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;
    
    // Menerima input tinggi badan untuk setiap mahasiswa
    for (int i = 0; i < jumlah_mahasiswa; ++i) {
        int nim, nim_angka_terakhir;
        float tinggi_mahasiswa;
        
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";
        cin >> nim;
        
        // Mengambil dua angka terakhir dari NIM
        nim_angka_terakhir = nim % 100;
        
        cout << "Masukkan tinggi badan mahasiswa ke-" << i+1 << " (cm): ";
        cin >> tinggi_mahasiswa;
        
        // Menambahkan tinggi badan ke dalam data_tinggi
        data_tinggi[nim_angka_terakhir].push_back(tinggi_mahasiswa);
    }
    
    // Menghitung total tinggi badan dan jumlah mahasiswa untuk setiap dua angka terakhir NIM
    map<int, float> total_tinggi;
    map<int, int> jumlah_mahasiswa_per_nim;
    for (auto it = data_tinggi.begin(); it != data_tinggi.end(); ++it) {
        int nim_angka_terakhir = it->first;
        vector<float> tinggi_mahasiswa = it->second;
        
        for (float tinggi : tinggi_mahasiswa) {
            total_tinggi[nim_angka_terakhir] += tinggi;
            jumlah_mahasiswa_per_nim[nim_angka_terakhir]++;
        }
    }
    
    // Menghitung rata-rata tinggi badan untuk setiap dua angka terakhir NIM dan menampilkannya
    cout << "\nRata-rata tinggi badan berdasarkan dua angka terakhir NIM:\n";
    for (auto it = total_tinggi.begin(); it != total_tinggi.end(); ++it) {
        int nim_angka_terakhir = it->first;
        float total = it->second;
        int jumlah_mahasiswa = jumlah_mahasiswa_per_nim[nim_angka_terakhir];
        
        float rata_rata = total / jumlah_mahasiswa;
        cout << "Rata-rata tinggi badan untuk mahasiswa dengan dua angka terakhir NIM " << nim_angka_terakhir << ": " << rata_rata << " cm\n";
    }
    
    return 0;
}