#include <iostream>
using namespace std;
int main()
{

    int A[8], max = A[0], min = A[0];
    for (int i = 1; i < 7; i++)
    {

        cout << "A[" << i << "] : " << A[i] << endl;
    }
    cout << endl;
    for (int i = 1; i < 7; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    for (int i = 1; i < 7; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << "Nilai maksimum : " << max << endl;
    cout << "Nilai minimum : " << min << endl;
}