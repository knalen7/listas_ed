#include <stdio.h>

// Função recursiva para calcular o n-ésimo termo da sequência de Fibonacci
long long int fibonacci(int n) {
    // Casos base: se n for 1 ou 2, o n-ésimo termo é 1
    if (n == 1 || n == 2)
        return 1;
    // Caso geral: o n-ésimo termo é a soma dos dois termos anteriores
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Digite o valor de n (deve ser maior ou igual a 1): ");
    scanf("%d", &n);

    // Verifica se n é válido
    if (n < 1) {
        printf("Valor inválido para n. Deve ser maior ou igual a 1.\n");
        return 1; // Retornar 1 indica um erro
    }

    // Calcula o n-ésimo termo da sequência de Fibonacci usando a função recursiva
    long long int termo = fibonacci(n);

    printf("O %d-ésimo termo da sequência de Fibonacci é: %lld\n", n, termo);

    return 0;
}
