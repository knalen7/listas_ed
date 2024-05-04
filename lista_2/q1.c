#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
     setlocale(LC_ALL, "Portuguese");
   char palavra[50];
   printf("insira a string que deseja saber quantos caracteres possui: ");
   fgets(palavra, 50, stdin);
	palavra[strcspn(palavra, "\n")] = '\0';
	int tamanhoDaString = strlen(palavra);	
   printf("Tamanho da string: %d\n", tamanhoDaString);
}