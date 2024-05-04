#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
	 setlocale(LC_ALL, "Portuguese");
	char str1[50];
	char str2[50];
	printf("insira duas strings para concatena-las: ");
	
	fgets(str1, 50, stdin);
	fgets(str2, 50, stdin);
	
	str1[strcspn(str1, "\n")] = '\0';
   
   strcat(str1, str2);
   
   printf("String concatenada: %s\n", str1);
	
}