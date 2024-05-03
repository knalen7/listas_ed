#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_TELEFONE 15
#define MAX_EMAIL 50
#define MAX_ANIVERSARIO 15

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char aniversario[MAX_ANIVERSARIO];
    char email[MAX_EMAIL];
    int apagado; // Novo campo para indicar se o contato foi apagado
} Contato;

typedef struct {
    Contato *contatos;
    int tamanho;
} Agenda;

void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int valida_telefone(const char *telefone) {
    if (strlen(telefone) != 11)
        return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(telefone[i]))
            return 0;
    }
    return 1;
}

int valida_aniversario(const char *aniversario) {
    if (strlen(aniversario) != 8)
        return 0;
    
    for (int i = 0; i < 8; i++) {
        if (!isdigit(aniversario[i]))
            return 0;
    }
    return 1;
} 

int valida_email(const char *email) {
    int at = 0, dot = 0;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@')
            at++;
        if (email[i] == '.')
            dot++;
    }
    if (at == 1 && dot >= 1)
        return 1;
    return 0;
}

void grava_arquivo(const Contato *contato, FILE *arquivo) {
    fprintf(arquivo, "%s;%s;%s;%s;%d\n", contato->nome, contato->telefone, contato->aniversario, contato->email, contato->apagado);
}

void grava(Agenda *agenda, Contato contato) {    
    // Realoca memória para o novo contato
    agenda->contatos = realloc(agenda->contatos, (agenda->tamanho + 1) * sizeof(Contato));
    
    if (agenda->contatos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    
    // Inicializa o campo apagado como falso
    contato.apagado = 0;

    // Adiciona o novo contato
    agenda->contatos[agenda->tamanho] = contato;
    agenda->tamanho++;
    printf("Contato gravado com sucesso.\n");

    // Escreve no arquivo contatos.txt
    FILE *arquivo = fopen("contatos.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo contatos.txt\n");
        return;
    }
    grava_arquivo(&contato, arquivo);
    fclose(arquivo);
}

void apaga(Agenda *agenda, const char *nome, const char *telefone, const char *aniversario, const char *email) {
    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo contatos.txt\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char linha[200];
    int contato_encontrado = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char temp_nome[MAX_NOME], temp_telefone[MAX_TELEFONE], temp_aniversario[MAX_ANIVERSARIO], temp_email[MAX_EMAIL];
        int temp_apagado;
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%d\n", temp_nome, temp_telefone, temp_aniversario, temp_email, &temp_apagado);

        if (strcmp(temp_nome, nome) == 0 &&
            strcmp(temp_telefone, telefone) == 0 &&
            strcmp(temp_aniversario, aniversario) == 0 &&
            strcmp(temp_email, email) == 0) {
            contato_encontrado = 1;
            agenda -> tamanho--;
            printf("Contato apagado com sucesso.\n");
        } else {
            fprintf(temp, "%s;%s;%s;%s;%d\n", temp_nome, temp_telefone, temp_aniversario, temp_email, temp_apagado);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (!contato_encontrado) {
        printf("Contato nao encontrado.\n");
        remove("temp.txt"); // remove o arquivo temporário se nenhum contato foi encontrado
    } else {
        remove("contatos.txt");
        rename("temp.txt", "contatos.txt");
    }
}

void entrada(Contato *contato) {
    printf("Nome: ");
    fgets(contato->nome, MAX_NOME, stdin);
    strtok(contato->nome, "\n");
    printf("Telefone (DD*********): ");
    fgets(contato->telefone, MAX_TELEFONE, stdin);
    strtok(contato->telefone, "\n");
    while (!valida_telefone(contato->telefone)) {
        printf("Telefone invalido. Digite novamente: ");
        fgets(contato->telefone, MAX_TELEFONE, stdin);
        strtok(contato->telefone, "\n");
    }
    printf("Data de aniversario (formato: DDMMYYYY): ");
    fgets(contato->aniversario, MAX_ANIVERSARIO, stdin);
    strtok(contato->aniversario, "\n");
    while (!valida_aniversario(contato->aniversario)) {
        printf("Data de aniversario invalida. Digite novamente: ");
        fgets(contato->aniversario, MAX_ANIVERSARIO, stdin);
        strtok(contato->aniversario, "\n");
    }
    printf("Email: ");
    fgets(contato->email, MAX_EMAIL, stdin);
    strtok(contato->email, "\n");
    while (!valida_email(contato->email)) {
        printf("Email invalido. Digite novamente: ");
        fgets(contato->email, MAX_EMAIL, stdin);
        strtok(contato->email, "\n");
    }
}

void edita(Agenda *agenda, const char *nome, const char *telefone, const char *aniversario, const char *email) {
    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo contatos.txt\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char linha[200];
    int contato_editado = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char temp_nome[MAX_NOME], temp_telefone[MAX_TELEFONE], temp_aniversario[MAX_ANIVERSARIO], temp_email[MAX_EMAIL];
        int temp_apagado;
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];\n", temp_nome, temp_telefone, temp_aniversario, temp_email);

        if (strcmp(temp_nome, nome) == 0 &&
            strcmp(temp_telefone, telefone) == 0 &&
            strcmp(temp_aniversario, aniversario) == 0 &&
            strcmp(temp_email, email) == 0) {
            // Se o contato for encontrado, edita-o
            Contato novo_contato;
            novo_contato.apagado = temp_apagado; // mantém o status de apagado do contato original
            entrada(&novo_contato);
            grava_arquivo(&novo_contato, temp);
            printf("Contato editado com sucesso.\n");
            contato_editado = 1;
        } else {
            // Se não for o contato a ser editado, escreve-o sem modificação
            fprintf(temp, "%s;%s;%s;%s;%d\n", temp_nome, temp_telefone, temp_aniversario, temp_email, temp_apagado);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("contatos.txt");
    rename("temp.txt", "contatos.txt");

    if (!contato_editado)
        printf("Contato nao encontrado.\n");
}

void ordena_nomes(Agenda *agenda) {
    for (int i = 0; i < agenda->tamanho - 1; i++) {
        for (int j = i + 1; j < agenda->tamanho; j++) {
            if (strcmp(agenda->contatos[i].nome, agenda->contatos[j].nome) > 0) {
                Contato temp = agenda->contatos[i];
                agenda->contatos[i] = agenda->contatos[j];
                agenda->contatos[j] = temp;
            }
        }
    }
    printf("Agenda ordenada por nomes.\n");

    // Atualiza o arquivo contatos.txt com a nova ordem
    FILE *arquivo = fopen("contatos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo contatos.txt\n");
        return;
    }

    for (int i = 0; i < agenda->tamanho; i++) {
        if (!agenda->contatos[i].apagado)
            grava_arquivo(&agenda->contatos[i], arquivo);
    }

    fclose(arquivo);
}

int main() {
    Agenda agenda;
    agenda.tamanho = 0;
    agenda.contatos = NULL;
    int opcao;

    do {
        printf("\n--- Agenda ---\n");
        printf("1. Adicionar contato\n");
        printf("2. Apagar contato\n");
        printf("3. Alterar contato\n");
        printf("4. Ordenar por nome\n");
        printf("5. Tamanho da agenda\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch(opcao) {
            case 1: {
                Contato contato;
                entrada(&contato);
                grava(&agenda, contato);
                break;
            }
            case 2: {
                char nome[MAX_NOME], telefone[MAX_TELEFONE], aniversario[MAX_ANIVERSARIO], email[MAX_EMAIL];
                printf("Nome: ");
                fgets(nome, MAX_NOME, stdin);
                strtok(nome, "\n");
                printf("Telefone: ");
                fgets(telefone, MAX_TELEFONE, stdin);
                strtok(telefone, "\n");
                printf("Data de aniversario: ");
                fgets(aniversario, MAX_ANIVERSARIO, stdin);
                strtok(aniversario, "\n");
                printf("Email: ");
                fgets(email, MAX_EMAIL, stdin);
                strtok(email, "\n");
                apaga(&agenda, nome, telefone, aniversario, email);
                break;
            }
            case 3: {
                char nome[MAX_NOME], telefone[MAX_TELEFONE], aniversario[MAX_ANIVERSARIO], email[MAX_EMAIL];
                printf("Nome: ");
                fgets(nome, MAX_NOME, stdin);
                strtok(nome, "\n");
                printf("Telefone: ");
                fgets(telefone, MAX_TELEFONE, stdin);
                strtok(telefone, "\n");
                printf("Data de aniversario: ");
                fgets(aniversario, MAX_ANIVERSARIO, stdin);
                strtok(aniversario, "\n");
                printf("Email: ");
                fgets(email, MAX_EMAIL, stdin);
                strtok(email, "\n");
                edita(&agenda, nome, telefone, aniversario, email);
                break;
            }
            case 4:
                ordena_nomes(&agenda);
                break;
            case 5:
                printf("A agenda possui: %d contatos\n", agenda.tamanho);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);

    // Libera a memória alocada para os contatos
    free(agenda.contatos);

    return 0;
}
