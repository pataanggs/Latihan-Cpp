//RA_122140055_Fathan Andi Kartagama
#include<iostream>
using namespace std;
void printSegitigaKanan(int n) { //fungsi void
    for (int i = 1; i <= n; i++) { //increment
        for (int j = 1; j <= i; j++) { //increment
            cout << j << " "; //untuk menampilkan varibel j dan spasi pada variabel j
        }
        cout << endl;
    }

    for (int i = n; i >= 0; i--) { //decrement
        for(int j = i; j >= 0; j--) { //decrement
            cout << i << " ";  //untuk menampilkan variabel i dan spasi pada variabel i
        }
        cout << endl;
    }
}

int main() {
	int n;
    cout << "Masukan bilangan bulat : ";
	cin>> n; //di sini user akan diminta untuk memasukan sebuah nilai bilangan bulat
	
    printSegitigaKanan(n); //untuk memangil fungsi void yang sudah dideklarasikan di atas

return 0;
}