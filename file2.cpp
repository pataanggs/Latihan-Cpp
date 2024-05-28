//RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;
//Fungsi deret matematika
int jumlahderet (int n){
    int awal = 5, jarak = 10, total = awal;
    for (int i = 1;i < n; i++){
        if (awal == 5){
            cout <<awal;
        }
        awal = awal + jarak;
        total += awal;

        cout << "+" << awal;
    }
    cout << "=";
    return total;
}

int main(){
    int n;
    cout << "Masukan nilai deret yang mau diketahui : ";
    cin >> n;
    jumlahderet(n);

    return 0;
}