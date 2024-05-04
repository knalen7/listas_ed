#include <stdio.h>
#include <string.h>
#include <locale.h>

#define maximo 50
int main() {
   int matriz[maximo][maximo];
   int n;
   int i, j;

   printf("Digite a ordem da matriz quadrada: ");
   scanf("%d", &n);

   printf("Digite os elementos da matriz:\n");
   for (i= 0; i < n; i++) {
       for (j= 0; j < n; j++) {
           printf("Elemento [%d][%d]: ", i, j);
           scanf("%d", &matriz[i][j]);
       }
   }

   printf("Elementos da diagonal principal:\n");
   for (i = 0; i < n; i++) {
       printf("%d ", matriz[i][i]);
   }
   printf("\n");
}