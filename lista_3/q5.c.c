#include <stdio.h>

int strlen_custom(const char *s) {
    const char *inicio = s;
    
    while (*s != '\0') {
        s++;
    }

    return s - inicio;
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    int tamanho = strlen_custom(str);

    printf("O tamanho da string e: %d\n", tamanho);

    return 0;
}