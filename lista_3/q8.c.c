#include <stdio.h>
#include <stdlib.h>

float calcular(float valor1, char operador, float valor2) {
    switch(operador) {
        case '+':
            return valor1 + valor2;
        case '-':
            return valor1 - valor2;
        case '*':
            return valor1 * valor2;
        case '/':
            if (valor2 != 0)
                return valor1 / valor2;
            else {
                printf("Erro: divisão por zero!\n");
                exit(1);
            }
        default:
            printf("Operador inválido!\n");
            exit(1);
    }
}

int main() {
    char operador;
    float valor1, valor2, resultado;

    printf("Digite a expressão aritmética no formato 'CALC <valor1> <operador> <valor2>': ");
    scanf(" CALC %f %c %f", &valor1, &operador, &valor2);

    resultado = calcular(valor1, operador, valor2);

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
