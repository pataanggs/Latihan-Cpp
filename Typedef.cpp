#include <iostream>

using namespace std;

// Contoh menggunakan typedef
typedef int Data;

struct Node {
    Data data;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* newNode = new Node;
    newNode->data = 10;
    newNode->next = nullptr;
    head = newNode;

    // Sekarang Anda dapat menggunakan 'Data' sebagai tipe data
    Data value = head->data;
    cout << "Data: " << value << endl;

    delete head;
    return 0;
}