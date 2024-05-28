#include <iostream>
using namespace std;

int pangkat(int angka, int eksponen) {
    if (eksponen == 0) {
        return 1;
    } else {
        return angka * pangkat(angka, eksponen - 1);
    }
}

int duarr(int angka) {
    if (angka == 0) {
        return 0;
    } else {
        return pangkat(angka, 2);
    }
}

int main() {
    int angka;
    cout << "Masukkan angka = ";
    cin >> angka;
    cout << angka << " pangkat 2 adalah " << duarr(angka);
    return 0;
}
