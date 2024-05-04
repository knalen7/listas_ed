#include <stdio.h>
#include <string.h>
#include <locale.h>

void strdel(char *str, int pos) {
   int len = strlen(str);

   if (pos < 0 || pos >= len){}

   int i; 
   
   for (i = pos; i < len - 1; i++) {
       str[i] = str[i + 1];
   }
   
   str[len - 1] = '\0';
}
int main() {
setlocale(LC_ALL, "Portuguese");
   char string[50];
   int posicao;

   printf("Digite uma string: ");
   fgets(string, 50, stdin);

   printf("Digite a posição do caractere a ser removido: ");
   scanf("%d", &posicao);

   string[strcspn(string, "\n")] = '\0';

   printf("String original: %s\n", string);
   
   strdel(string, posicao);
   
   printf("String após remoção: %s\n", string);

}