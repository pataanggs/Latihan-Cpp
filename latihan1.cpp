#include <iostream>
using namespace std;

const int MAX_N = 10; // ukuran maksimum array

struct Mahasiswa {
    int nim;
    string nama;
    string mata_kuliah;
    int sks;
    char nilai_mutu;
};

int main() {
    Mahasiswa data[MAX_N]; // array dari record Mahasiswa
    int n; // jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "NIM: ";
        cin >> data[i].nim;
        cin.ignore();
        cout << "Nama: ";
        getline(cin, data[i].nama);
        cout << "Nama Mata Kuliah: ";
        getline (cin, data[i].mata_kuliah);
        cout << "SKS: ";
        cin >> data[i].sks;
        cin.ignore();
        cout << "Nilai Mutu: ";
        cin >> data[i].nilai_mutu;
    }
    // Output data mahasiswa
    cout << endl << "Data mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "NIM: " << data[i].nim << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Nama Mata Kuliah: " << data[i].mata_kuliah << endl;
        cout << "SKS: " << data[i].sks << endl;
        cout << "Nilai Mutu: " << data[i].nilai_mutu << endl;
    }
    return 0;
}
