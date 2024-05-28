#include <iostream>
using namespace std;

int main() {
    int n, i, temp;
    cin >> n;
    
    int arr[n];
    for(i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int* ptr1 = arr; // pointer untuk elemen pertama
    int* ptr2 = arr + n - 1; // pointer untuk elemen terakhir
    
    // loop untuk menukar nilai elemen array
    while(ptr1 < ptr2) {
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }
    
    // mencetak array yang sudah dibalik
    cout << "Array yang sudah dibalik\n";
    for(i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
