#include <stdio.h>

void puts(char *s) {
   
    while (*s != '\0') {
        printf("%c", *s); 
        s++;
    }
    printf("\n"); 
}

int main() {
    char minhaString[] = "Exemplo de string";


    puts(minhaString);

    return 0;
}