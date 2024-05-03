#include <stdio.h>
#include <string.h>

int main() {
    char num_conta[7]; // Para armazenar o número de conta de até seis dígitos
    int soma = 0, digito_verificador;

    printf("Digite o número da conta (até 6 dígitos): ");
    scanf("%6s", num_conta);

    int len = strlen(num_conta);

    // Move os dígitos para a direita para fazer espaço para os zeros à esquerda
    for (int i = len - 1; i >= 0; i--) {
        num_conta[i + (6 - len)] = num_conta[i];
    }

    // Preenche os dígitos restantes com zeros à esquerda
    for (int i = 0; i < 6 - len; i++) {
        num_conta[i] = '0';
    }

    // Calcula a soma dos dígitos do número da conta
    for (int i = 0; i < 6; i++) {
        soma += num_conta[i] - '0'; // Convertendo o caractere para o valor numérico
    }

    // Calcula o dígito verificador
    digito_verificador = soma % 10;

    // Exibe o número de conta completo com o dígito verificador
    printf("Número de conta completo: %s-%d\n", num_conta, digito_verificador);

    return 0;
}
