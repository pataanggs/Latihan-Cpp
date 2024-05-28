#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Masukkan bilangan bulat a: ";
    cin >> a;
    cout << "Masukan bilangan bulat b: ";
    cin >> b;
    cout << "Masukan bilangan bulat c: ";
    cin >> c;

    while (a == b || a == c || b == c)
    {
        cout << "Bilangan yang dimasukkan harus berbeda-beda\n";
        cout << "Masukkan bilangan bulat a: ";
        cin >> a;
        cout << "Masukan bilangan bulat b: ";
        cin >> b;
        cout << "Masukan bilangan bulat c: ";
        cin >> c;
    }

    cout << "Bilangan yang dimasukkan adalah: " << a << ", " << b << ", " << c << endl;
    return 0;
}
