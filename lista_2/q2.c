#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
	 setlocale(LC_ALL, "Portuguese");
	char string[50];
	printf("insira uma string que deseja deixar em maiusculo: ");
   fgets(string, 50, stdin);
   printf("%s",  strupr(string));
}