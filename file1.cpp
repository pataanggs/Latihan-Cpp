// RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;
int deretmatematika(int n)
{
    int awal = 5, jarak = 10;
    for (int i = 1; i < n; i++)
    {
        awal = awal + jarak;
    }
    return awal;
}
int main()
{
    int n;
    cout << "Masukan nilai deret yang mau diketahui : ";
    cin >> n;

    cout << "Nilainya adalah : ";
    cout << deretmatematika(n);
    return 0;
}