#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strsub(const char *s, int i, int n) {

    char *substring = (char*)malloc((n + 1) * sizeof(char)); 
    if (substring == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        exit(1);
    }

    strncpy(substring, s + i, n);
    substring[n] = '\0';

    return substring;
}
int main() {
    char s[100];
    int i, n;

    printf("Digite uma string: ");
    scanf("%s", s);

    printf("Digite a posicao inicial da substring: ");
    scanf("%d", &i);

    printf("Digite o numero maximo de caracteres na substring: ");
    scanf("%d", &n);

    char *substring = strsub(s, i, n);

    printf("Substring de s: %s\n", substring);

    free(substring);

    return 0;
}