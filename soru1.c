#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

// Insertion Sort algoritmasi
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        // Elemani dogru pozisyona yerlestirme
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort algoritmasi
void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;

        // En küçük elemani bul
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Yer degistir
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Diziyi kopyalamak için yardimci fonksiyon
void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

int main() {
    int original[SIZE], arr1[SIZE], arr2[SIZE];

    // Rastgele sayilar için baslangiç noktasi
    srand(time(NULL));

    // Diziye 0-1000 arasinda rastgele sayilar ata
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1001;
    }

    // Diziyi kopyala (ayni veriyi her iki algoritma da kullansin)
    copyArray(original, arr1, SIZE);
    copyArray(original, arr2, SIZE);

    // Insertion Sort zaman ölçümü
    clock_t start1 = clock();
    insertionSort(arr1, SIZE);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    // Selection Sort zaman ölçümü
    clock_t start2 = clock();
    selectionSort(arr2, SIZE);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    // Sonuçlari ekrana yazdir
    printf("Insertion Sort islemi tamamlandi. Süre: %f saniye\n", time1);
    printf("Selection Sort islemi tamamlandi. Süre: %f saniye\n", time2);

    return 0;
}

