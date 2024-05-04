#include <stdio.h>
#include <stdlib.h>

char* monet(double v) {
    char *monetario = (char*)malloc(20 * sizeof(char)); 
    if (monetario == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        exit(1);
    }

   
    sprintf(monetario, "R$ %.2lf", v);

    return monetario;
}
int main() {
    double valor;

    printf("Digite um valor real: ");
    scanf("%lf", &valor);

    char *representacao = monet(valor);

    printf("Representacao monetaria: %s\n", representacao);

    free(representacao);

    return 0;
}