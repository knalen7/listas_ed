#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {82, 50, 71, 63, 85, 43, 39, 97, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array nÃ£o ordenado: \n");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}