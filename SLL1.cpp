#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Data {
  string nama;
  string nim;
  string kelas;
  int nilai;
};

// Struktur data untuk menyimpan informasi hasil UTS
struct UTSResult {
    Data data;
    UTSResult* next;
};

int size;

// Fungsi untuk memasukkan data baru ke akhir linked list
void InsertLast(UTSResult*& head, string nama, string nim, string kelas, int nilai) {
    UTSResult* newNode = new UTSResult;
    newNode->data.nama = nama;
    newNode->data.nim = nim;
    newNode->data.kelas = kelas;
    newNode->data.nilai = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        UTSResult* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menyisipkan data baru pada bagian tengah linked list (pembulatan ke bawah)
void InsertMiddle(UTSResult*& head, string nama, string nim, string kelas, int nilai) {
    UTSResult* newNode = new UTSResult;
    newNode->data.nama = nama;
    newNode->data.nim = nim;
    newNode->data.kelas = kelas;
    newNode->data.nilai = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        UTSResult* current = head;
        int length = 0;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        int middleIndex = length / 2;
        current = head;
        for (int i = 0; i < middleIndex - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Fungsi untuk mencari dan menampilkan data hasil UTS berdasarkan NIM
void SearchByNIM(UTSResult* head, string nim) {
    UTSResult* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data.nim == nim) {
            found = true;
            cout << "Nama: " << current->data.nama << endl;
            cout << "NIM: " << current->data.nim << endl;
            cout << "Kelas: " << current->data.kelas << endl;
            cout << "Nilai: " << current->data.nilai << endl;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengurutkan data nilai dari terbesar hingga terkecil (pengurutan bubble sort)
void SortByNilai(UTSResult** head) {
    UTSResult* current = *head;
    UTSResult* index = NULL;
    Data temp;

    if (*head == NULL) {
      cout << "mang eak\n";
      return;
    }
  
    while(current != NULL) {  
      //Node index will point to node next to current  
      index = current->next;  
        
      while(index != NULL) {  
          //If current node's data is greater than index's node data, swap the data between them  
          if(current->data.nilai < index->data.nilai) {  
              temp = current->data;  
              current->data = index->data;  
              index->data = temp;  
          }  
          index = index->next;  
      }  
      current = current->next;  
  }      
}


// Fungsi untuk menghapus data tengah dengan nilai UTS di bawah 50
void yaHapus(UTSResult** head, int* size) {
    if (*head == nullptr) {
      cout << "gabole\n";
      return;
    } else if((*head)->next == nullptr) {
      UTSResult* tmp = *head;
      *head = nullptr;
      delete tmp;
    }

    UTSResult* current = *head;
    UTSResult* prev = NULL;
    int idx = 0;
    int delIdx = *size/2;
  
    // get size
    while(current != NULL && current->data.nilai >= 50) {
      current = current->next;
    }

    cout << "test: "<< *size << endl;

    if (current != NULL) {
      current = *head;
  
      while(current != NULL && idx != delIdx) {
        prev = current;
        current = current->next;
        idx++;
      }
  
      prev->next = current->next;
      delete current;
  
      (*size)--;
    }
}

// Fungsi untuk menampilkan isi linked list
void DisplayList(UTSResult* head) {
    UTSResult* current = head;
    while (current != nullptr) {
        cout << endl;
        cout << "=============================" << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "NIM: " << current->data.nim << endl;
        cout << "Kelas: " << current->data.kelas << endl;
        cout << "Nilai: " << current->data.nilai << endl;
        cout << "=============================" << endl;
        cout << endl;
        current = current->next;
    }
}

int main() {
    UTSResult* head = NULL;
    int choice;
    size = 0;

    do {
        cout << endl;
        cout << "=============================" << endl;
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Urutkan Data\n";
        cout << "4. Cari Data\n";
        cout << "5. Hapus Data di Bawah 50\n";
        cout << "6. Keluar\n";
        cout << "=============================" << endl;
        cout << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string nama, nim, kelas;
                    int nilai;

                    cout << "Masukkan Nama: ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "Masukkan NIM: ";
                    getline(cin, nim);
                    cout << "Masukkan Kelas: ";
                    getline(cin, kelas);
                    cout << "Masukkan Nilai: ";
                    cin >> nilai;

                    InsertLast(head, nama, nim, kelas, nilai);
                    cout << "Data berhasil ditambahkan.\n";
                    size++;
                    break;
                }
            case 2:
                cout << "Isi linked list:\n";
                DisplayList(head);
                break;
            case 3:
                SortByNilai(&head);
                cout << "Data berhasil diurutkan.\n";
                break;
            case 4:
                {
                    string searchNIM;
                    cout << "Masukkan NIM yang ingin dicari: ";
                    cin.ignore();
                    getline(cin, searchNIM);
                    SearchByNIM(head, searchNIM);
                    break;
                }
            case 5:
                yaHapus(&head, &size);
                cout << "Data dengan nilai di bawah 50 telah dihapus.\n";
                break;
            case 6:
                cout << "Terima kasih! Sampai berjumpa lagi.\n";
                break;
            default:
                cout << "Jangan pilih yang gaada. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}