#include <stdio.h>
#include <string.h>

void selectionSortStrings(char *arr[], int n) {
    int i, j, minIdx;
    char *temp;
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[minIdx]) < 0)
                minIdx = j;
        }
        // Troca arr[i] e arr[minIdx]
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void printArrayStrings(char *arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

int main() {
    char *arr[] = {"banana", "apple", "orange", "grape", "pear"};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array de strings nÃ£o ordenado: \n");
    printArrayStrings(arr, n);
    selectionSortStrings(arr, n);
    printf("Array de strings ordenado: \n");
    printArrayStrings(arr, n);
    return 0;
}