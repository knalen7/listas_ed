#include <stdio.h>

void minimax(float v[], int n, float *a, float *b) {
 
    *a = v[0];
    *b = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] < *a) {
            *a = v[i];
        } else if (v[i] > *b) {
            *b = v[i];
        }
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    float vetor[tamanho];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    float minimo, maximo;
    minimax(vetor, tamanho, &minimo, &maximo);

    printf("O valor minimo e: %.2f\n", minimo);
    printf("O valor maximo e: %.2f\n", maximo);

    return 0;
}
