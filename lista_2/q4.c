#include <stdio.h>
#include <string.h>
#include <locale.h>

int strpos(const char *s, char c) {
   int i = 0;
   
   while (s[i] != '\0') {
       if (s[i] == c) {
           return i; 
       }
       i++;
   }
   
   return -1; 
}


int main(){
setlocale(LC_ALL, "Portuguese");
	char str[50];
	char caractere;
	printf("insira uma string: ");
	fgets(str, 50, stdin);
	printf("insira o caractere que deseja saber: ");
	scanf("%c", &caractere);    
   
   int posicao = strpos(str, caractere);
   
   if (posicao != -1) {
       printf("O caractere '%c' foi encontrado na posicao %d.\n", caractere, posicao + 1);
   } else {
       printf("O caractere '%c' não foi encontrado na string.\n", caractere);
   }
}