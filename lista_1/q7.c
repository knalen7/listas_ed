#include <stdio.h>
int main(){
int num, i, quad, termo;
quad=0;
termo =1;
printf("Entre com um número: ");
scanf("%d",&num);
for(i=1;i<=num;i++){
termo = 1 + (i-1)*2;
quad = quad + termo;
}
printf("O quadrado do número %d é %d", num, quad);
}