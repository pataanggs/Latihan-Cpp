#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    int bilangan, ganjil, genap;
    
    cout << "Masukan bilangan bulat" << endl;
    cin >> bilangan;
    if (bilangan % 2 == 0) {
        cout << "Bilangan anda genap" << endl;
    } else {
        cout << "Bilangan anda ganjil" << endl;
    }
    return 0;
}