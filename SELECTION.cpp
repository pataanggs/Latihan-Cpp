#include<iostream>

using namespace std;

void selection(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int idx = i;
        for (int j = i+1; j < size; j++) {
            if(arr[j] > arr[idx]) {
                idx = j;
            }
        }
        
        if (idx != i) {
            int temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
        }
    }
    
}

int main() {
    int arr[] = {6,33,5,1,26,10,69};

    selection(arr, 7);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " "; 
    }
    
    return 0;
}