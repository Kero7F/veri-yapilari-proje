#include <stdio.h>
#include <stdlib.h>

// Selection Sort (küçükten büyüðe sýralama)
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

// Yeni sýralama algoritmasý (bir büyük, bir küçük)
void customSort(int arr[], int size, int result[]) {
    selectionSort(arr, size); // Önce küçükten büyüðe sýrala

    int left = 0;            // En küçük
    int right = size - 1;    // En büyük
    int i = 0;

    while (left <= right) {
        if (i % 2 == 0) {
            result[i++] = arr[right--]; // En büyük
        }
        else {
            result[i++] = arr[left++];  // En küçük
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
