#include <stdio.h>

void bubbleSortDescending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                // Troca arr[j] e arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {92, 80, 71, 63, 55, 41, 39, 27, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array nÃ£o ordenado: \n");
    printArray(arr, n);
    bubbleSortDescending(arr, n);
    printf("Array ordenado de forma decrescente: \n");
    printArray(arr, n);
    return 0;
}