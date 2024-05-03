#include <stdio.h>
#include <math.h>

int main(){
    int fator(int x);
    int num, fatorial;

    printf("digite um numero: ");
    scanf("%d", &num);

    fatorial = fator(num);
    printf("O fatorial de %d eh %d", num, fatorial);

    return 0;
}

int fator(int x){
    int fatorial;

    if (x == 0)
    {
        fatorial = 1;
    }else{
        fatorial = x * fator(x - 1); 
    }

    return fatorial;


    
}