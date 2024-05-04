#include <stdio.h>
#include <string.h>
#include <locale.h>

void strins(char *str, char caracter, int pos) {
   int len = strlen(str);

   if (pos < 0 || pos > len)
       pos = len; 
   
   int i;
   
   for (i = len; i > pos; i--) {
       str[i] = str[i - 1];
   }
   
   str[pos] = caracter;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
   char string[50];
   char caracter;
   int posicao;

   printf("Digite uma string: ");
   fgets(string, 50, stdin);

   printf("Digite um caractere para inserir: ");
   scanf("%c", &caracter);

   printf("Digite a posição para inserir o caractere: ");
   scanf("%d", &posicao);

   string[strcspn(string, "\n")] = '\0';

   printf("String original: %s\n", string);
   
   strins(string, caracter, posicao);
   
   printf("String após inserção: %s\n", string);
}