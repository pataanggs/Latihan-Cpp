#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 100; // ukuran maksimum array

struct Mahasiswa
{
    string nim;
    string nama;
    string mata_kuliah;
    int sks;
    float nilai_mutu;
    float nilai_ksm; // field untuk Nilai KSM
};

// Fungsi untuk mengonversi nilai huruf mutu menjadi nilai mutu
float nilaiMutu(char huruf_mutu) {
    float nilai_mutu;
int main()
{
    Mahasiswa data[MAX_N]; // array dari record Mahasiswa
    int n;                 // jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // mengabaikan karakter newline pada input sebelumnya
    // Input data mahasiswa
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "NIM: ";
        getline(cin, data[i].nim);
        cout << "Nama: ";
        getline(cin, data[i].nama);
        cout << "Nama Mata Kuliah: ";
        getline(cin, data[i].mata_kuliah);
        cout << "SKS: ";
        cin >> data[i].sks;
        cout << "Nilai Mutu: ";
        cin >> data[i].nilai_mutu;
        cin.ignore(); // mengabaikan karakter newline pada input sebelumnya
        // Hitung nilai KSM
        float nilai_m = nilaiMutu(data[i].nilai_mutu);
        data[i].nilai_ksm = nilai_m * data[i].sks;
    }
    switch (nilai_mutu[0]) {
        case 'A':
            nilai_angka = 4.0;
            break;
        case 'B':
            nilai_angka = 3.0;
            if (nilai_mutu[1] == 'C') {
                nilai_angka = 2.5;
            } else if (nilai_mutu[1] == '\0') {
                // nilai_mutu valid (tidak ada karakter setelah B)
            } else {
                // nilai_mutu tidak valid (karakter setelah B salah)
            }
            break;
        case 'C':
            nilai_angka = 2.0;
            if (nilai_mutu[1] == '\0') {
                // nilai_mutu valid (tidak ada karakter setelah C)
            } else {
                // nilai_mutu tidak valid (karakter setelah C salah)
            }
            break;
        case 'D':
            nilai_angka = 1.0;
            if (nilai_mutu[1] == '\0') {
                // nilai_mutu valid (tidak ada karakter setelah D)
            } else {
                // nilai_mutu tidak valid (karakter setelah D salah)
            }
            break;
        case 'E':
            nilai_angka = 0.0;
            if (nilai_mutu[1] == '\0') {
                // nilai_mutu valid (tidak ada karakter setelah E)
            } else {
                // nilai_mutu tidak valid (karakter setelah E salah)
            }
            break;
        default:
            // nilai_mutu tidak valid (tidak sesuai dengan karakter A, B, C, D, atau E)
            break;
    }



    // Output data mahasiswa
    cout << endl
         << "Data mahasiswa:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "NIM: " << data[i].nim << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Nama Mata Kuliah: " << data[i].mata_kuliah << endl;
        cout << "SKS: " << data[i].sks << endl;
        cout << "Nilai Mutu: " << data[i].nilai_mutu << endl;
        cout << "Nilai KSM: " << data[i].nilai_ksm << endl;
    }
    // Pencarian data mahasiswa berdasarkan NIM
    string nim_cari;
    cout << endl
         << "Masukkan NIM yang ingin dicari: ";
    getline(cin, nim_cari);
    bool found = false;
    float total_nilai = 0; // inisialisasi
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i].nim == nim_cari)
        {
            found = true;
            cout << "NIM ditemukan atas nama " << data[i].nama << endl;
            total_nilai += data[i].nilai_ksm;
            count++;
        }
    }
    if (found)
    {
        float nr = total_nilai / count;
        cout << "Nilai rata-rata: " << nr << endl;
    }
    else
    {
        cout << "NIM tidak ditemukan." << endl;
    }

}