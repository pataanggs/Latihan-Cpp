//RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;
int main() {
    int ukuran = 3;
    char operasi;
    int matriksA[ukuran][ukuran], matriksB[ukuran][ukuran];
    cout << "Masukkan matriks A dengan ukuran 3 x 3: \n";
    for (int baris = 0; baris < ukuran; baris++) {
        for (int kolom = 0; kolom < ukuran; kolom++) {
            cin >> matriksA[baris][kolom];
        }
    }
    cout << "\nMasukkan matriks B dengan ukuran 3 x 3: \n";
    for (int baris = 0; baris < ukuran; baris++) {
        for (int kolom = 0; kolom < ukuran; kolom++) {
            cin >> matriksB[baris][kolom];
        }
    }
    cout << "Masukkan operasi [+-*]: "; cin >> operasi;
    if (operasi == '+') {
        for (int baris = 0; baris < ukuran; baris++) {
            for (int kolom = 0; kolom < ukuran; kolom++) {
                if(kolom > 0) {
                    cout << " ";
                }
                cout << matriksA[baris][kolom] + matriksB[baris][kolom];
            }
            cout << endl;
        }
    } else if (operasi == '-') {
        for (int baris = 0; baris < ukuran; baris++) {
            for (int kolom = 0; kolom < ukuran; kolom++) {
                if(kolom > 0) {
                    cout << " ";
                }
                cout << matriksA[baris][kolom] - matriksB[baris][kolom];
            }
            cout << endl;
        }
    } else if (operasi == '*') {
        for (int baris = 0; baris < ukuran; baris++) {
            for (int kolom = 0; kolom < ukuran; kolom++) {
                int result = 0;
                for (int i = 0; i < ukuran; i++) {
                    result += matriksA[baris][i] * matriksB[i][kolom];
                }
                if(kolom > 0) {
                    cout << " ";
                }
                cout << result;
            }
            cout << endl;
        }
    }
    return 0;
}