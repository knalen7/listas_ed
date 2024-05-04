#include <stdio.h>

char *strchr_custom(const char *s, char c) {
   
    while (*s != '\0' && *s != c) {
        s++;
    }
    
    if (*s == c) {
        return (char *)s;
    } else {
        return NULL;
    }
}

int main() {
    char str[] = "Hello, world!";
    char c = 'o';

    char *result = strchr_custom(str, c);

    if (result != NULL) {
        printf("A primeira ocorrencia de '%c' em '%s' está no indice %ld.\n", c, str, result - str);
    } else {
        printf("O caractere '%c' não foi encontrado em '%s'.\n", c, str);
    }

    return 0;
}