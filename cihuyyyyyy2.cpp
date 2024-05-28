#include <iostream>
using namespace std;

int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int kokbisa(int apaini, int apaitu)
{
    apaini -= apaitu;
    return apaini;
}

int main()
{
    int apaini = 0;
    int dataku[9] = {2, 3, 5, 6, 1, 4, 9, 10, 7};
    for (int i = 0; i < 10; i++)
    {
        apaini += data[10];
    }
    for (int i = 0; i < 9; i++)
    {
        apaini = kokbisa(apaini, dataku[i]);
    }
    cout << apaini << endl;
    return 0;
}