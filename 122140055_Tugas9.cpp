//RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;
int main(){
    int n, i, j, k; //Variabel
    cout << "Masukan jumlah bilangan bulat : ";
    cin >> n;

    for(int i = 1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout << " "; //Menggunakan " " supaya lambang * yang membentuk pola berlian tepat berada di tengah
        }
        for(int j = 1;j<=i;j++){
            cout << "* "; //Untuk mencetak tanda *
        }
        //Garis akhir setelah setiap baris
        cout << endl;
    }    
    for(int i = n;i>=0;i--){
        for(int j=i;j<=n;j++){
            cout << " "; //Sama dengan yang di atas, supaya lambang * yang membentuk pola berlian tepat berada di tengah
        }
        for(int j = 1;j<=i;j++){
            cout << "* "; //Untuk mencetak tanda *
        }
        //Garis akhir setelah setiap baris
        cout << endl;
    }
return 0;
}