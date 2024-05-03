#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c;
    float x1 = 0, x2 = 0;
    float delta = 0;

    printf("Digite os valores das variaveis\n");

    printf("a: ");
    scanf("%f", &a);
    
    printf("b: ");
    scanf("%f",&b);
    
    printf("c: ");
    scanf("%f", &c);

    // Verifica se 'a' é diferente de zero
    if (a == 0) {
        printf("Coeficiente 'a' nao pode ser zero\n");
        return 1; // Retorna 1 para indicar erro
    }

    delta = pow(b, 2) - (4*a*c);
    printf("\nDelta e %f\n", delta);

    if (delta < 0) {
        printf("A equacao nao possui raizes reais\n");
    } else {
        x1 = (-b + sqrt(delta)) / (2*a); 
        x2 = (-b - sqrt(delta)) / (2*a); 

        printf("O valor de x1 e %f\n", x1);
        printf("O valor de x2 e %f\n", x2);
    }

    return 0;   
}
