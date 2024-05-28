#include <iostream>
using namespace std;

int collatz(int n, int step) {
    // basis rekursif
    if (n == 1) {
        return step;
    }

    // rekursi
    if (n % 2 == 0) {
        return collatz(n / 2, step + 1);
    } else {
        return collatz(3 * n + 1, step + 1);
    }
}

int main() {
    int n;
    cin >> n;
    int steps = collatz(n, 0);
    cout << "Nilai yang dibutuhkan untuk mencapai 1: " << steps << endl;
    return 0;
}
