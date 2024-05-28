#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int n;
    cout << "Masukkan n: ";
    cin >> n;
    cout << "Jumlah deret S = 1+2+3+...+" << n << " adalah " << sum(n) << endl;
    return 0;
}
