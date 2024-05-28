#include<iostream>

using namespace std;

const int maxArr = 10;
int front = 0, back = 0, arr[maxArr], nim1, nim2, nim3;
bool n1 = true, n2 = true, n3 = true;

bool isFull() {
    if(back == maxArr) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if(back == 0) {
        return true;
    } else {
        return false;
    }
}

int passData(int n) {
    if(n == nim1 && n1) {
        n1 = false;
    } else if(n == nim2 && n2) {
        n2 = false;
    } else if(n == nim3 && n3) {
        n3 = false;
    }

    return n;
}

bool isValueOfThreeNim(int n) {
    return ((n == nim1 && n1) || (n == nim2 && n2) || (n == nim3 && n3));
}

void enqueue(int n) {
    if(isFull()) {
        cout << "Queue is full brodi!\n";
    } else {
        if(isValueOfThreeNim(n)) {
            if(isEmpty()) {
                arr[0] = passData(n);
                front++;
                back++;
            } else {
                arr[back] = passData(n);
                back++;
            }
        }
    }
}

void dequeue() {
    if(isEmpty()) {
        cout << "Queue kosong ngabs!\n";
    } else {
        for(int i = 0; i < back; i++) {
            arr[i] = arr[i+1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void destroyQueue() {
    if(isEmpty()) {
        cout << "Queue kosong ngabs!\n";
    } else {
        front = 0;
        back = 0;
    }
}

void viewQueue() {
    cout << "Queue total element(s): " << back << endl;
    cout << "Queue data(s):\n";
    if(isEmpty()) {
        cout << "Queue Kosong ngabs!";
    } else {
        for(int i = 0; i < back; i++) {
            cout << arr[i] << endl;
        }

        cout << endl;
    }
}

int main() {
    string nim;

    cout << "Masukkan nim: ";
    cin >> nim;
    nim1 = nim[6] - 48;
    nim2 = nim[7] - 48;
    nim3 = nim[8] - 48;
    
    int wleo;
    cout << "Memasukkan angka (Masukkan -1 untuk berhenti!)\n";

    while(wleo != -1) {
        cout << "Masukkan angka: ";
        cin >> wleo;
        enqueue(wleo);
    }

    viewQueue();

    return 0;
}