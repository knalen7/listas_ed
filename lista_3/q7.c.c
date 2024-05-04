#include <stdio.h>
#include <dos.h>

void cronometro(int segundos) {
    printf("Contagem regressiva iniciada!\n");

    for (int i = segundos; i > 0; i--) {
        printf("%d\n", i);
        sleep(1);
    }

    printf("ding-dong!! (Campainha)\a\n"); 
}

int main() {
    int segundos;

    printf("Digite o número de segundos para a contagem regressiva: ");
    scanf("%d", &segundos);

    cronometro(segundos);

    return 0;
}
