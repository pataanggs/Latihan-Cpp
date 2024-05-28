#include <iostream>
using namespace std;

// Definisi tipe data untuk node dalam linked list
typedef struct Node *NodePtr;

struct Node {
    string data;
    NodePtr next;
    NodePtr prev;
};

// Definisi tipe data untuk linked list
struct LinkedList {
    NodePtr first;
    NodePtr last;
};

// Fungsi untuk mengalokasikan dan membuat node baru
NodePtr createNode(LinkedList *list, string data) {
    NodePtr newNode = new Node;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->data = data;
    return newNode;
}

// Fungsi untuk menyisipkan node di awal linked list
void insertFirst(LinkedList *list, NodePtr newNode) {
    if (!list->first) {
        newNode->next = list->first;
        list->first = newNode;
        list->last = newNode; // Jika daftar awalnya kosong, maka first dan last adalah newNode
    } else {
        newNode->next = list->first;
        list->first->prev = newNode;
        list->first = newNode;
    }
}

// Fungsi untuk menyisipkan node di akhir linked list
void insertLast(LinkedList *list, NodePtr newNode) {
    if (!list->first) {
        insertFirst(list, newNode);
    } else {
        newNode->prev = list->last;
        list->last->next = newNode;
        list->last = newNode;
    }
}

// Fungsi untuk mencetak isi linked list dari awal hingga akhir, kemudian dari akhir hingga awal
void print(LinkedList list) {
    NodePtr currentNode = list.first;
    
    // Cetak dari awal hingga akhir
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        if (currentNode->next) {
            currentNode = currentNode->next->next;
        } else {
            break;
        }
    }

    // Cetak dari akhir hingga awal
    currentNode = list.last->prev;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->prev;
    }
    
    cout << endl;
}

int main() {
    LinkedList list;
    NodePtr newNode = nullptr;
    list.first = newNode;
    list.last = newNode;

    // Mengalokasikan dan menyisipkan node-node baru ke dalam linked list
    newNode = createNode(&list, "1");
    insertLast(&list, newNode);
    newNode = createNode(&list, "2");
    insertLast(&list, newNode);
    newNode = createNode(&list, "3");
    insertLast(&list, newNode);
    newNode = createNode(&list, "4");
    insertLast(&list, newNode);
    newNode = createNode(&list, "5");
    insertLast(&list, newNode);

    // Mencetak isi linked list
    print(list);

    return 0;
}
