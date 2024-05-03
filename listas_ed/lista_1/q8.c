#include <stdio.h>

int main() {
    int n;
    long long int primeiro = 1, segundo = 1, proximo;

    printf("Digite o valor de n (deve ser maior ou igual a 3): ");
    scanf("%d", &n);

    // Se n é 1 ou 2, o n-ésimo termo é 1
    if (n == 1 || n == 2) {
        printf("O %d-ésimo termo da sequência de Fibonacci é: 1\n", n);
    } else {
        for (int i = 3; i <= n; i++) {
            proximo = primeiro + segundo;
            primeiro = segundo;
            segundo = proximo;
        }
        printf("O %d-ésimo termo da sequência de Fibonacci é: %lld\n", n, proximo);
    }

    return 0;
}
