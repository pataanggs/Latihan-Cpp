#include<iostream>

using namespace std;

const int maxAntrian = 10;
int f = 0, b = 0;
int arr[maxAntrian], nim[3];

bool isFull() {
    if(b == maxAntrian) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if(b == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int n) {
    if(isFull()) {
        cout << "Queue is full brodi!\n";
    } else {
        if((n != -1) && (n == nim[0] || n == nim[1] || n == nim[2])) {
            if(isEmpty()) {
                arr[0] = n;
                f++;
                b++;
            } else {
                arr[b] = n;
                b++;
            }

            if(nim[0] == n) {
                nim[0] = -1;
            } else if(nim[1] == n) {
                nim[1] = -1;
            } else if(nim[2] == n) {
                nim[2] = -1;
            }
        }
    }
}

void dequeue() {
    if(isEmpty()) {
        cout << "Queue kosong ngabs!\n";
    } else {
        for(int i = 0; i < b; i++) {
            arr[i] = arr[i+1];
        }
        b--;
    }
}

int countQueue() {
    return b;
}

void destroyQueue() {
    if(isEmpty()) {
        cout << "Queue kosong ngabs!\n";
    } else {
        f = 0;
        b = 0;
    }
}

void viewQueue() {
    cout << "\nQueue total element(s): " << b << endl;
    cout << "Queue data(s):\n";
    if(isEmpty()) {
        cout << "Queue Kosong ngabs!";
    } else {
        for(int i = 0; i < b; i++) {
            cout << arr[i] << endl;
        }

        cout << endl;
    }
}

int main() {
    string inputNim;
    int wow;
    cout << "Masukkan NIM: ";
    cin >> inputNim;
    cout << "Berapa kali anda ingin enqueue?: ";
    cin >> wow;

    nim[0] = inputNim[6] - 48;
    nim[1] = inputNim[7] - 48;
    nim[2] = inputNim[8] - 48;

    for (int i = 0; i < wow; i ++) {
        int anjay;
        cout << "Masukkan enqueue ke-" << i+1 << ": ";
        cin >> anjay;
        enqueue(anjay);
    }

    viewQueue();

    return 0;
}