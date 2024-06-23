#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        // Troca arr[i] e arr[minIdx]
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}