#include <iostream>
#include <string>


using namespace std;

typedef struct Node *alamat;

struct Node {
    string nim;
    string nama;
    alamat next;
};

struct Hash {
    alamat daftar[10] = {NULL};
};

// Function declarations
alamat alokasi(string nama, string nim);
void sisipkanNode(alamat* kepala, alamat simpulBaru);
void cetakDaftar(alamat kepala);
void sisipkan(Hash& hash, string nama, string nim);
void sisipkanKeHash(Hash* hash, string nama, string nim, int index);
void sisipkanKeDaftar(Hash* hash, alamat simpulBaru, int index);
void modulus(Hash* hash, string nama, int nim);
void pemotongan(Hash* hash, string nama, string nim);
void pelipatan(Hash* hash, string nama, string nim);
void tanganiTabrakan(Hash* hash, string nama, int nim);

int main() {
    Hash hashTable;
    string nim = "555228";

    int k1 = (nim[0] - 48) * 10 + (nim[1] - 48);
    int k2 = (nim[2] - 48) * 10 + (nim[3] - 48);
    int k3 = (nim[4] - 48) * 10 + (nim[5] - 48);
    int h = (k1 + k2 + k3) % 100;
    cout << k1 << " " << k2 << " " << k3 << endl;
    return 0;
}

// Implementations of the other functions
alamat alokasi(string nama, string nim) {
    alamat simpulBaru = new Node;
    simpulBaru->nim = nim;
    simpulBaru->nama = nama;
    simpulBaru->next = NULL;
    return simpulBaru;
}

void sisipkanNode(alamat* kepala, alamat simpulBaru) {
    if (*kepala == NULL) {
        *kepala = simpulBaru;
        return;
    }

    alamat saatIni = *kepala;

    while (saatIni->next != NULL) {
        saatIni = saatIni->next;
    }

    saatIni->next = simpulBaru;
}

void cetakDaftar(alamat kepala) {
    alamat saatIni = kepala;

    while (saatIni != NULL) {
        cout << saatIni->nama << " ";
        saatIni = saatIni->next;
    }

    cout << endl;
}

void sisipkan(Hash& hash, string nama, string nim) {
    ::modulus(  &hash, nama, stoi(nim));
}


void sisipkanKeHash(Hash* hash, string nama, string nim, int index) {
    alamat simpulBaru = alokasi(nama, nim);
    sisipkanNode(&hash->daftar[index], simpulBaru);
}

void sisipkanKeDaftar(Hash* hash, alamat simpulBaru, int index) {
    sisipkanNode(&hash->daftar[index], simpulBaru);
}

void modulus(Hash* hash, string nama, int nim) {
    int k = nim % 10; // mendapatkan angka satuan
    sisipkanKeHash(hash, nama, to_string(nim), k); // memasukkan data ke hash pada indeks k
}

void pemotongan(Hash* hash, string nama, string nim) {
    int a = (nim[1] - 48) * 100; // mendapatkan angka ratusan
    int b = (nim[4] - 48) * 10; // mendapatkan angka puluhan
    int c = (nim[6] - 48) * 1; // mendapatkan angka satuan
    int k = a + b + c; // menjumlahkan angka ratusan, puluhan, dan satuan
    sisipkanKeHash(hash, nama, nim, k); // memasukkan data ke hash pada indeks k
}

void pelipatan(Hash* hash, string nama, string nim) {
    // mendapatkan potongan digit 1 dan 2
    int k1 = (nim[0] - 48) * 10 + (nim[1] - 48);
    // mendapatkan potongan digit 3 dan 4
    int k2 = (nim[2] - 48) * 10 + (nim[3] - 48);
    // mendapatkan potongan digit 5 dan 6
    int k3 = (nim[4] - 48) * 10 + (nim[5] - 48);
    // menjumlahkan semua 2 digit tadi dan mendapatkan 2 digit terakhir
    int h = (k1 + k2 + k3) % 100;
    sisipkanKeHash(hash, nama, nim, h); // memasukkan data ke hash pada indeks h
}

void tanganiTabrakan(Hash* hash, string nama, int nim) {
    int k = nim % 10; // mendapatkan angka satuan
    alamat simpulBaru = alokasi(nama, to_string(nim)); // alokasi simpul baru untuk daftar
    sisipkanKeDaftar(hash, simpulBaru, k); // memasukkan simpul baru pada daftar di indeks hash k
}