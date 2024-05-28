//122140055_Fathan Andi Kartagama_RB
#include <iostream>
#include <climits> // Include for INT_MIN and INT_MAX
using namespace std;
 
// Fungsi untuk menukar dua elemen
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 
// Kelas untuk merepresentasikan max heap
class MaxHeap
{
    int *arr;     // pointer untuk array elemen
    int capacity; // kapasitas maksimum heap
    int size;     // jumlah elemen saat ini di heap
 
public:
    // Konstruktor untuk membuat heap kosong dengan kapasitas tertentu
    MaxHeap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }
 
    // Fungsi untuk mendapatkan indeks parent dari simpul i
    int parent(int i)
    {
        return (i - 1) / 2;
    }
 
    // Fungsi untuk mendapatkan indeks anak kiri dari simpul i
    int left(int i)
    {
        return (2 * i + 1);
    }
 
    // Fungsi untuk mendapatkan indeks anak kanan dari simpul i
    int right(int i)
    {
        return (2 * i + 2);
    }
 
    // Fungsi untuk mengembalikan elemen maksimum dari heap
    int getMax()
    {
        return arr[0];
    }
 
    // Fungsi untuk menghapus dan mengembalikan elemen maksimum dari heap
    int extractMax()
    {
        if (size == 0)
            return INT_MIN; // mengembalikan nilai minimum integer jika heap kosong
        if (size == 1)
        {
            size--;
            return arr[0]; // mengembalikan elemen tunggal jika heap hanya memiliki satu elemen
        }
 
        // menyimpan elemen maksimum dan menggantinya dengan elemen terakhir
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
 
        // memanggil heapify pada simpul akar untuk mempertahankan sifat heap
        heapify(0);
 
        // mengembalikan elemen maksimum
        return max;
    }
 
    // Fungsi untuk mengurangi nilai elemen di indeks i menjadi new_val
    // diasumsikan bahwa new_val lebih besar dari arr[i]
    void increaseKey(int i, int new_val)
    {
        arr[i] = new_val; // mengganti nilai elemen dengan new_val
 
        // menggeser elemen ke atas sampai sifat heap terpenuhi
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
 
    // Fungsi untuk menambahkan elemen baru di heap
    void insertKey(int k)
    {
        if (size == capacity)
        {
            cout << "Wuaduh heapnya penuh jadi gabisa nambah elemen baru\n";
            return;
        }
 
        // menambahkan elemen di posisi terakhir
        size++;
        int i = size - 1;
        arr[i] = k;
 
        // menggeser elemen ke atas sampai sifat heap terpenuhi
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
 
    // Fungsi untuk menghapus elemen di indeks i dari heap
    void deleteKey(int i)
    {
        // mengganti elemen dengan nilai maksimum integer
        increaseKey(i, INT_MAX);
 
        // menghapus elemen maksimum
        extractMax();
    }
 
    // Fungsi untuk mengatur ulang elemen di indeks i agar mempertahankan sifat heap
    // mengikuti pendekatan top-down
    void heapify(int i)
    {
        int l = left(i);  // mendapatkan indeks anak kiri
        int r = right(i); // mendapatkan indeks anak kanan
        int largest = i;  // menyimpan indeks elemen terbesar
 
        // memeriksa apakah anak kiri lebih besar dari elemen saat ini
        if (l < size && arr[l] > arr[i])
            largest = l;
 
        // memeriksa apakah anak kanan lebih besar dari elemen terbesar saat ini
        if (r < size && arr[r] > arr[largest])
            largest = r;
 
        // jika elemen terbesar bukan elemen saat ini, menukar elemen dan memanggil heapify pada anak terbesar
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
 
    // Fungsi untuk mendapatkan jumlah elemen saat ini di heap
    int getSize()
    {
        return size;
    }
 
    // Fungsi untuk mencetak elemen heap
    void printHeap()
    {
        cout << "Elemen heap: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
 
// Fungsi utama untuk menguji program
int main()
{
    // membuat heap dengan kapasitas 10
    MaxHeap h(10);
 
    // menambahkan beberapa elemen di heap
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(15);
    h.insertKey(30);
    h.insertKey(40);
 
    // mencetak elemen heap
    h.printHeap();
 
    // menghapus elemen di indeks 1
    h.deleteKey(1);
 
    // mencetak elemen heap setelah penghapusan
    h.printHeap();
 
    // mengurangi nilai elemen di indeks 2 menjadi 5
    h.increaseKey(2, 5);
 
    // mencetak elemen heap setelah pengurangan
    h.printHeap();
 
    // mengembalikan dan menghapus elemen maksimum dari heap
    cout << "Elemen maksimum: " << h.extractMax() << "\n";
 
    // mencetak elemen heap setelah ekstraksi
    h.printHeap();
 
    return 0;
}
 