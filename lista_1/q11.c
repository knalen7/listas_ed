#include <stdio.h>

int fat(num, fator){
    if (num < 0)
    {
        printf("nao existe fatorial de numero negativo");
        return 1;
    }
    
    for (int i = num; i > 0; i--)
    {
        fator *= i;
  
    }
    
    return fator;

}
int main(){
    int num, fator = 1, fatorial;
    
    printf("digite o numero: ");
    scanf("%d", &num);

    fatorial = fat(num, fator);

    printf("o fatorial de %d e %d", num, fatorial);
    return 0;
}