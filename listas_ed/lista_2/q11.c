#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_TELEFONE 15

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
} PESSOA;

#define MAX_PESSOAS 5

typedef struct {
    PESSOA pessoas[MAX_PESSOAS];
    int tamanho;
} AGENDA;

// Função para preencher a agenda com os dados de 5 pessoas
void preencher_agenda(AGENDA *agenda) {
    printf("Preenchendo a agenda com os dados de 5 pessoas:\n");
    for (int i = 0; i < MAX_PESSOAS; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        fgets(agenda->pessoas[i].nome, MAX_NOME, stdin);
        strtok(agenda->pessoas[i].nome, "\n");
        printf("Telefone: ");
        fgets(agenda->pessoas[i].telefone, MAX_TELEFONE, stdin);
        strtok(agenda->pessoas[i].telefone, "\n");
        agenda->tamanho++;
    }
}

// Função para procurar na agenda o telefone de uma determinada pessoa
void procurar_telefone(AGENDA *agenda, const char *nome) {
    int encontrado = 0;
    for (int i = 0; i < agenda->tamanho; i++) {
        if (strcmp(agenda->pessoas[i].nome, nome) == 0) {
            printf("O telefone de %s é: %s\n", nome, agenda->pessoas[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Pessoa não encontrada na agenda.\n");
    }
}

int main() {
    AGENDA agenda = { .tamanho = 0 };
    
    preencher_agenda(&agenda);

    char nome[MAX_NOME];
    printf("\nDigite o nome da pessoa para buscar o telefone: ");
    fgets(nome, MAX_NOME, stdin);
    strtok(nome, "\n");

    procurar_telefone(&agenda, nome);

    return 0;
}
