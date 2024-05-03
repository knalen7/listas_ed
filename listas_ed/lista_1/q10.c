#include <stdio.h>

int main() {
    int num, i, primo = 1; // assume que num é primo

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

    // Verifica se num é divisível por algum número além de 1 e ele mesmo
    for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            primo = 0; // se n é divisível por i, então n não é primo
            break;
        }
    }

    // Se is_prime ainda for 1, então n é primo, caso contrário, não é primo
    if (primo)
        printf("%d é um número primo.\n", num);
    else
        printf("%d não é um número primo.\n", num);

    return 0;
}
