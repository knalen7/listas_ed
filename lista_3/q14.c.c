#include <stdio.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano_publicacao;
} Livro;

void preencherTabelaLivros(Livro *tabela, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Digite o título do livro: ");
        fgets(tabela[i].titulo, sizeof(tabela[i].titulo), stdin);
        printf("Digite o autor do livro: ");
        fgets(tabela[i].autor, sizeof(tabela[i].autor), stdin);
        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &tabela[i].ano_publicacao);
        getchar();
    }
}

int main() {
    int tamanho = 3;
    Livro tabelaLivros[tamanho];

    preencherTabelaLivros(tabelaLivros, tamanho);

    printf("\nTabela de Livros Preenchida:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s", tabelaLivros[i].titulo);
        printf("Autor: %s", tabelaLivros[i].autor);
        printf("Ano de Publicação: %d\n", tabelaLivros[i].ano_publicacao);
    }

    return 0;
}
