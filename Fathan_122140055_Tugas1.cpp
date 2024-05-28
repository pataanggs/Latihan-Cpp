#include <iostream>
using namespace std;
int cekBilangan(int angka1, int angka2)
{
    if (angka1 % angka2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void angkaDicariBukan(int angka)
{
    int status = 0, pembanding;
    if (angka % 2 != 0)
    {
        pembanding = angka - 2;
        while (pembanding > 2)
        {
            if (cekBilangan(angka, pembanding))
            {
                status = 1;
                break;
            }
            pembanding -= 2;
        }
    }
    if (angka == 1)
    {
        cout << "Bukan bilangan yang dicari" << endl;
    }
    else if (angka == 2)
    {
        cout << "Merupakan bilangan yang dicari" << endl;
    }
    else if ((angka % 2 != 0) && (status == 0))
    {
        cout << "Merupakan bilangan yang dicari" << endl;
    }
    else
    {
        cout << "Bukan bilangan yang dicari" << endl;
    }
}
int main()
{
    angkaDicariBukan(23);
    return 0;
}