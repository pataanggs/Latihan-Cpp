#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int n; // Jumlah mahasiswa
  double sum = 0; // Jumlah total tinggi badan
  double avg; // Rata-rata tinggi badan

  // Minta input NIM
  cout << "Masukkan NIM: ";
  cin >> n;

  // Validasi NIM
  if (n < 100000000 || n > 999999999) {
    cout << "NIM tidak valid\n";
    return 0;
  }

  // Ambil dua angka terakhir dari NIM
  n = n % 100;

  // Minta input tinggi badan untuk setiap mahasiswa
  for (int i = 1; i <= n; i++) {
    double height; // Tinggi badan mahasiswa ke-i
    cout << "Masukkan tinggi badan mahasiswa ke-" << i << " (dalam cm): ";
    cin >> height;

    // Validasi tinggi badan
    if (height < 0) {
      cout << "Tinggi badan tidak valid\n";
      return 0;
    }

    // Tambahkan tinggi badan ke jumlah total
    sum += height;
  }

  // Hitung rata-rata tinggi badan
  avg = sum / n;

  // Tampilkan hasil
  cout << "Rata-rata tinggi badan mahasiswa adalah " << avg << " cm\n";

  return 0;
}
