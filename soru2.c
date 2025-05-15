#include <stdio.h>
#include <stdlib.h>

// Selection Sort (k���kten b�y��e s�ralama)
void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Yeni s�ralama algoritmas� (bir b�y�k, bir k���k)
void customSort(int arr[], int size, int result[]) {
    selectionSort(arr, size); // �nce k���kten b�y��e s�rala

    int left = 0;            // En k���k
    int right = size - 1;    // En b�y�k
    int i = 0;

    while (left <= right) {
        if (i % 2 == 0) {
            result[i++] = arr[right--]; // En b�y�k
        }
        else {
            result[i++] = arr[left++];  // En k���k
        }
    }
}

int main() {
    int arr[] = { 60, 80, 3, 9, 57, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int result[100]; // Yeterli boyutta yeni dizi

    customSort(arr, size, result);

    printf("Yeni siralama: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
