#include<iostream>

using namespace std;

typedef struct Node* NodePtr;

struct Node {
	int value;
	bool isChecked;
	NodePtr next;
};

NodePtr firstNode, lastNode, current1, current2;
int totalDuplicates;

void resetCheck() {
    current1 = firstNode;
    while(current1->next != firstNode) {
        current1->isChecked = false;
        current1 = current1->next;
    }
    current1->isChecked = false;
}

NodePtr allocateNode(int n) {
	NodePtr newNode = new Node();
	newNode->isChecked = false;
	newNode->next = NULL;
	newNode->value = n;
	return newNode;
}

void insertFirst(int n) {
	NodePtr newNode = allocateNode(n);
	if(firstNode == NULL) {
		firstNode = newNode;
		newNode->next = firstNode;
	} else {
		current1 = firstNode;
		while (current1->next != firstNode) {
			current1 = current1->next;
		}
		newNode->next = firstNode;
		firstNode = newNode;
		current1->next = firstNode;
	}
    cout << "Berhasil Menambahkan " << n << " ke dalam list!\n";
}

void insertLast(int n) {
	NodePtr newNode = allocateNode(n);
	if(firstNode == NULL) {
		firstNode = newNode;
		newNode->next = firstNode;
	} else {
		current1 = firstNode;
		while (current1->next != firstNode) {
			current1 = current1->next;
		}
		current1->next = newNode;
		newNode->next = firstNode;
	}
    cout << "Berhasil Menambahkan " << n << " ke dalam list!\n";
}

void findDuplicates(NodePtr currentNode) {
    if(currentNode->isChecked == true) {
        return;
    }

	int n, count;
	currentNode->isChecked = true;
	current2 = currentNode->next;
	count = 1;
	n = currentNode->value;
	
	while(current2 != firstNode) {
		if(current2->isChecked == false && current2->value == n) {
			count++;
			current2->isChecked = true;
		}
		current2 = current2->next;
	}
	
	if(count > 1) {
		cout << n << " = " << count << endl;	
		totalDuplicates += count;
	}
}

void printDuplicates() {
	if (firstNode != NULL) {
		totalDuplicates = 0;
		cout << "Ini Angka Duplikat:\n";
		current1 = firstNode;
		while(current1->next != firstNode) {
			if(current1->isChecked == false) {
				findDuplicates(current1);
			}
			current1 = current1->next;
		}	

		cout << "Total angka duplikat: " << totalDuplicates << endl;
        resetCheck();
	} else {
        cout << "Bro, Listnya masih kosong!!\n";
    }

}

void deleteDuplicates() {
    if (firstNode != NULL) {
        current1 = firstNode;
        NodePtr del = NULL, forwardHead, forwardTail;

        while(current1->next != firstNode) {
            forwardHead = current1->next;
            forwardTail = current1;
            while(forwardHead != firstNode) {
                if(forwardHead->value == current1->value) {
                    forwardTail->next = forwardHead->next;
                    del = forwardHead;
                } else {
                    forwardTail = forwardTail->next;
                }
                forwardHead = forwardHead->next;
            }

            if(del != NULL) {
                delete del;
                del = NULL;
            }

            current1 = current1->next;
        }
    } else {
        cout << "Bro, Listnya masih kosong!!\n";
    }
}

void printList() {
	if (firstNode != NULL) {
		current1 = firstNode;
		while(current1->next != firstNode) {
			cout << current1->value << " -> ";
			current1 = current1->next;
		}	
		cout << current1->value << "X" << endl;
	} else {
        cout << "Bro, Listnya masih kosong!!\n";
    }
}

int main() {
    char choice;
    int n;

    do {
        cout << endl;
        cout << "=====================\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Tampilkan List\n";
        cout << "4. Check angka yang duplikat\n";
        cout << "5. Hapus semua angka duplikat\n";
        cout << "x. Keluar\n";
        cout << "=====================\n";
        cout << "Select: ";
        cin  >> choice; 

        switch (choice) {
        case '1':
            cout << "Masukan sebuah angka: ";
            cin >> n;
            insertFirst(n);
            break;
        case '2':
            cout << "Masukan Sebuah Angka: ";
            cin >> n;
            insertLast(n);
            break;
        case '3':
            printList();
            break; 
        case '4':
            printDuplicates();
            break;
        case '5':
            deleteDuplicates();
            break;
        case 'x':
            cout << "Terima kasih, semoga datang kembali :)\n";
            break;
        default:
            cout << "Salah woi salah, ulang lagi!\n";
            break;
        }

    } while (choice != 'x');
	return 0;
}
