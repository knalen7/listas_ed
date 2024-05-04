#include <stdio.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
} Livro;

void preencherLivro(Livro *livro) {
    printf("Digite o título do livro: ");
    fgets(livro->titulo, sizeof(livro->titulo), stdin);
    printf("Digite o autor do livro: ");
    fgets(livro->autor, sizeof(livro->autor), stdin);
    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &livro->ano_publicacao);
}

int main() {
    Livro livro;

    preencherLivro(&livro);

    printf("\nDados do livro:\n");
    printf("Título: %s", livro.titulo);
    printf("Autor: %s", livro.autor);
    printf("Ano de Publicação: %d\n", livro.ano_publicacao);

    return 0;
}