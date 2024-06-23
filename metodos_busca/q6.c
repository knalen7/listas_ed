#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int size);
void fillRandomArray(int arr[], int size);

int main() {
    int size = 1000;
    int arr1[size], arr2[size], arr3[size];
    fillRandomArray(arr1, size);
    
    // Copia arr1 para arr2 e arr3
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    clock_t start, end;
    double cpu_time_used;

    // Bubble Sort
    start = clock();
    bubbleSort(arr1, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo Bubble Sort: %f segundos\n", cpu_time_used);

    // Selection Sort
    start = clock();
    selectionSort(arr2, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo Selection Sort: %f segundos\n", cpu_time_used);

    // Insertion Sort
    start = clock();
    insertionSort(arr3, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo Insertion Sort: %f segundos\n", cpu_time_used);

    return 0;
}

void fillRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Número aleatório entre 0 e 9999
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca arr[j] e arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

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