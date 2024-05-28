#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua subarray terurut menjadi satu array terurut
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Buat array sementara untuk menyimpan subarray kiri dan kanan
    int L[n1], R[n2];

    // Salin data ke array sementara L[] dan R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Gabungkan subarray sementara ke array utama
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin elemen tersisa dari L[], jika ada
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin elemen tersisa dari R[], jika ada
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk melakukan Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Temukan indeks tengah untuk membagi array menjadi dua bagian
        int middle = left + (right - left) / 2;

        // Panggil rekursif mergeSort() untuk dua bagian array yang lebih kecil
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Gabungkan dua bagian array yang terurut
        merge(arr, left, middle, right);
    }
}

// Fungsi untuk mencari indeks dari key dalam array yang telah terurut
int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Jika key ditemukan, kembalikan indeksnya
        if (arr[mid] == key)
            return mid;

        // Jika key lebih kecil, cari di subarray kiri
        if (arr[mid] > key)
            right = mid - 1;

        // Jika key lebih besar, cari di subarray kanan
        else
            left = mid + 1;
    }

    // Jika key tidak ditemukan, kembalikan -1
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    // Panggil fungsi mergeSort untuk mengurutkan array
    mergeSort(arr, 0, n - 1);

    // Cetak array yang telah terurut
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Cari indeks key dalam array yang telah terurut menggunakan binarySearch
    int index = binarySearch(arr, 0, n - 1, key);

    // Jika key ditemukan, cetak indeksnya
    if (index != -1)
        cout << "Array found at index-" << index << endl;
    else
        cout << "Array not found" << endl;

    return 0;
}