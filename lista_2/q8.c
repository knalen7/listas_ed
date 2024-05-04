#include <stdio.h>
#include <string.h>
#include <locale.h>

void exibirTabuleiro(char tabuleiro[3][3]) {
   printf("Tabuleiro do Jogo da Velha:\n");
   int i,j;
   for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
           printf(" %c ", tabuleiro[i][j]);
           if (j < 3 - 1) {
               printf("|");
           }
       }
       printf("\n");
       if (i < 3 - 1) {
           printf("---|---|---\n");
       }
   }
}

int main() {
   char tabuleiro[3][3] = {
       {'1', '2', '3'},
       {'4', '5', '6'},
       {'7', '8', '9'}
   };

   exibirTabuleiro(tabuleiro);

}