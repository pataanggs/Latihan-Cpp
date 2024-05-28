//RA_122140055_Fathan Andi Kartagama
#include <iostream>
using namespace std;
/*Kamus
X = nilai minimum
Y = nilai maksimum*/
int main()
{
    int nilai[6], x = 0, y = 0;
    for (int i = 0; i < 6; i++)
    {
        cout << "Masukan nilai indeks ke-" << i << " : ";
        cin >> nilai[i];
        if (i == 0)
        {
            x = nilai[i];
        }
        if (nilai[i] > y)
        {
            y = nilai[i];
        }
        if (x > nilai[i])
        {
            x = nilai[i];
        }
    }
    cout << "Nilai maksimum :" << y << endl;
    cout << "Nilai minimum :" << x;
    return 0;
}