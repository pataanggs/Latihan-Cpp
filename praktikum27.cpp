#include<iostream>

using namespace std;

typedef struct Node* address;
typedef struct Node {
    char c;
    address next;
    address prev;
}Node;

struct List {
    address head;
    address tail;
    int count = 0;
};

void changeKey(List* passList, address* key) {
    address tmp;

    (*key)->prev = (*passList).tail; 
    (*passList).tail->prev->next = *key;

    tmp = (*passList).tail;
    tmp->prev = NULL;
    *key = tmp;

    (*passList).tail = *key;
}

List initList() {
    List l;
    l.head = NULL;
    l.tail = NULL;
    return l;
}

address allocation(char n) {
    address newNode = new Node();
    newNode->c = n;
    newNode->next=NULL; 
    newNode->prev=NULL;
    return newNode;
} 

bool isListEmpty(List l) {
    if (l.head == NULL && l.tail == NULL) {
        return true;
    } else {
        return false;
    }
}

void insertLast(List* l, char n) {
    address newNode = allocation(n);

    if(isListEmpty(*l)) {
        (*l).head = newNode;
        (*l).tail = newNode;
    } else {
        (*l).tail->next = newNode;
        newNode->prev = (*l).tail;
        (*l).tail = newNode;
    }

    (*l).count++;
}

void encrypt(List *passList, address* key) {
    (*passList).head->prev = (*passList).tail;
    (*passList).tail->next = (*passList).head;

    (*passList).tail = (*passList).head->next->next;
    (*passList).head = (*passList).tail->next;

    (*passList).head->prev  = NULL;
    (*passList).tail->next = NULL;

    changeKey(passList, key);
}

void decrypt(List* passList, address* key) {
    changeKey(passList, key);

     (*passList).tail->next = (*passList).head;
     (*passList).head->prev = (*passList).tail;

     (*passList).tail = (*passList).head->next->next;
     (*passList).head = (*passList).tail->next;

     (*passList).head->prev = NULL;
     (*passList).tail->next = NULL;
}

void printList(List l) {
    address curr = l.head;
    while (curr != NULL) {
        cout << curr->c << " ";
        curr = curr->next;
    }
    
    cout << endl;
}

int main() {
    List passwordList = initList();
    address key = allocation('X');

    insertLast(&passwordList, 'q');
    insertLast(&passwordList, 'w');
    insertLast(&passwordList, 'e');
    insertLast(&passwordList, 'r');
    insertLast(&passwordList, 't');
    insertLast(&passwordList, 'y');
    encrypt(&passwordList, &key);
    printList(passwordList);
    cout << passwordList.tail->c << endl;
    decrypt(&passwordList, &key);
    printList(passwordList);
    return 0;
}