#include <stdio.h>

int main(){
    int num, fator = 1;
    
    printf("digite o numero: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("nao existe fatorial de numero negativo");
        return 1;
    }
    
    for (int i = num; i > 0; i--)
    {
        fator *= i;
  
    }
    printf("o fatorial de %d e %d", num, fator);
    
    return 0;
}