#include <iostream>
#include <string>

using namespace std;

const int MAX_UKURAN = 100; //mendefinisika konstanta MAX_UKURAN sebagai 100 batas maksimal jumlah mahasiswa

//fungsi yang digunakan untuk memasukkan data mahasiswa, yaitu nama, nilai UTS, dan nilai UAS
int inputData(string Nama[], int UTS[], int UAS[], int ukuran) {
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> ukuran;

    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan Nama mahasiswa: ";
        cin >> Nama[i];
        cout << "Masukkan nilai UTS: ";
        cin >> UTS[i];
        cout << "Masukkan nilai UAS: ";
        cin >> UAS[i];
    }

    return ukuran;
}

//fungsi yang digunakan untuk menampilkan seluruh data mahasiswa, yaitu nama, nilai UTS, dan nilai UAS.
void displayData(string Nama[], int UTS[], int UAS[], int ukuran) {
    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < ukuran; i++) {
        cout << "Nama: " << Nama[i] << endl;
        cout << "Nilai UTS: " << UTS[i] << endl;
        cout << "Nilai UAS: " << UAS[i] << endl;
        cout << endl;
    }
}

//fungsi yang digunakan untuk menampilkan nilai rata-rata setiap mahasiswa.
void displayAverage(string Nama[], int UTS[], int UAS[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        float ratarata = (UTS[i] + UAS[i]) / 2.0f;
        cout << "Nama: " << Nama[i] << endl;
        cout << "Nilai Rata-rata: " << ratarata << endl;
        cout << endl;
    }
}

//fungsi yang digunakan untuk menampilkan grade setiap mahasiswa berdasarkan nilai rata-rata yang dicapai.
void displayGrade(string Nama[], int UTS[], int UAS[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        float ratarata = (UTS[i] + UAS[i]) / 2.0f;
        cout << "Nama: " << Nama[i] << endl;
        if (ratarata >= 80) {
            cout << "Grade: A" << endl;
        } else if (ratarata >= 70) {
            cout << "Grade: B" << endl;
        } else if (ratarata >= 60) {
            cout << "Grade: C" << endl;
        } else {
            cout << "Grade: D" << endl;
        }
        cout << endl;
    }
}

//fungsi utama yang digunakan untuk memanggil fungsi inputData, displayData, displayAverage, dan displayGrade.
int main() {
    string Nama[MAX_UKURAN];
    int UTS[MAX_UKURAN];
    int UAS[MAX_UKURAN];
    int ukuran = 0;

    ukuran = inputData(Nama, UTS, UAS, ukuran);
    displayData(Nama, UTS, UAS, ukuran);
    displayAverage(Nama, UTS, UAS, ukuran);
    displayGrade(Nama, UTS, UAS, ukuran);
return 0;
}