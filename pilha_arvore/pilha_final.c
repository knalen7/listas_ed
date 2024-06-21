#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // Para fabs()

#define MAX 100

struct Node {
    char nome[MAX];
    char cargo[MAX];
    int salario;
    struct Node *prox;
};
typedef struct Node node;

struct TreeNode {
    char nome[MAX];
    char cargo[MAX];
    int salario;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode treeNode;

int tam;

int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, treeNode **root, int op);
void exibe(node *PILHA);
void exibeArvore(treeNode *root);
void libera(node *PILHA);
void liberaArvore(treeNode *root);
void push(node *PILHA, treeNode **root);
node *pop(node *PILHA, char *nome, char *cargo, int salario);
int vazia(node *PILHA);
node *aloca();
treeNode* alocaTreeNode(char *nome, char *cargo, int salario);
void insereArvore(treeNode **root, char *nome, char *cargo, int salario);
int comparaCargo(char *cargo1, char *cargo2);
int validaCargo(char *cargo);

int main(void)
{
    node *PILHA = (node *) malloc(sizeof(node));
    treeNode *root = NULL;
    if(!PILHA){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } else {
        inicia(PILHA);
        int opt;

        do {
            opt = menu();
            opcao(PILHA, &root, opt);
        } while(opt != 0);

        free(PILHA);
        liberaArvore(root);
        return 0;
    }
}

void inicia(node *PILHA)
{
    PILHA->prox = NULL;
    tam = 0;
}

int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar PILHA\n");
    printf("2. Exibir PILHA\n");
    printf("3. Exibir Arvore\n");
    printf("4. PUSH\n");
    printf("5. POP\n");
    printf("Opcao: "); 
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, treeNode **root, int op)
{
    node *tmp;
    char nome[MAX];
    char cargo[MAX];
    int salario;

    switch(op){
        case 0:
            libera(PILHA);
            liberaArvore(*root);
            break;

        case 1:
            libera(PILHA);
            inicia(PILHA);
            // Não resetamos a árvore binária (*root = NULL) aqui
            break;

        case 2:
            exibe(PILHA);
            break;

        case 3:
            exibeArvore(*root);
            break;

        case 4:
            push(PILHA, root);
            break;

        case 5:
            printf("Nome: "); scanf("%s", nome);
            printf("Cargo: "); scanf("%s", cargo);
            printf("Salario: "); scanf("%d", &salario);
            tmp = pop(PILHA, nome, cargo, salario);
            if(tmp != NULL) {
                printf("Retirado:\n");
                printf("Nome: %s\n", tmp->nome);
                printf("Cargo: %s\n", tmp->cargo);
                printf("Salario: %d\n\n", tmp->salario);
                free(tmp); // Free memory after popping
            } else {
                printf("Elemento nao encontrado.\n\n");
            }
            break;

        default:
            printf("Comando invalido\n\n");
    }
}

int vazia(node *PILHA)
{
    return PILHA->prox == NULL;
}

int validaCargo(char *cargo)
{
    char *hierarquia[] = {"CEO", "Presidente", "Diretor", "Gerente", "Supervisor", "Coordenador", "Analista", "Assistente", "Auxiliar", "Estagiario"};
    for(int i = 0; i < 10; i++) {
        if(strcmp(cargo, hierarquia[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

node *aloca()
{
    node *novo = (node *) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } else {
        printf("Novo elemento:\n");
        printf("Nome: "); scanf("%s", novo->nome);
        do {
            printf("Cargo (CEO, Presidente, Diretor, Gerente, Supervisor, Coordenador, Analista, Assistente, Auxiliar, Estagiario): ");
            scanf("%s", novo->cargo);
            if (!validaCargo(novo->cargo)) {
                printf("Cargo invalido! Por favor, insira um cargo valido.\n");
            }
        } while (!validaCargo(novo->cargo));
        printf("Salario: "); scanf("%d", &novo->salario);
        return novo;
    }
}

void exibe(node *PILHA)
{
    if(vazia(PILHA)){
        printf("PILHA vazia!\n\n");
        return;
    }

    node *tmp = PILHA->prox;
    printf("PILHA:\n");
    while(tmp != NULL){
        printf("Nome: %s, Cargo: %s, Salario: %d\n", tmp->nome, tmp->cargo, tmp->salario);
        tmp = tmp->prox;
    }
    printf("\n");
}

void exibeArvore(treeNode *root)
{
    if(root != NULL){
        exibeArvore(root->left);
        printf("Nome: %s, Cargo: %s, Salario: %d\n", root->nome, root->cargo, root->salario);
        exibeArvore(root->right);
    }
}

void libera(node *PILHA)
{
    if(!vazia(PILHA)){
        node *proxNode, *atual;

        atual = PILHA->prox;
        while(atual != NULL){
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
        PILHA->prox = NULL; // Reset PILHA pointer
        tam = 0; // Reset size to zero
    } else {
        tam = 0; // Reset size to zero if PILHA is already empty
    }
}

void liberaArvore(treeNode *root)
{
    if(root != NULL){
        liberaArvore(root->left);
        liberaArvore(root->right);
        free(root);
    }
}

void push(node *PILHA, treeNode **root)
{
    node *novo = aloca();
    novo->prox = NULL;

    if(vazia(PILHA))
        PILHA->prox = novo;
    else{
        node *tmp = PILHA->prox;

        while(tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;

    // Inserir na árvore binária
    insereArvore(root, novo->nome, novo->cargo, novo->salario);
}

treeNode* alocaTreeNode(char *nome, char *cargo, int salario)
{
    treeNode *novo = (treeNode *) malloc(sizeof(treeNode));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    } else {
        strcpy(novo->nome, nome);
        strcpy(novo->cargo, cargo);
        novo->salario = salario;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }
}

void insereArvore(treeNode **root, char *nome, char *cargo, int salario)
{
    if(*root == NULL) {
        *root = alocaTreeNode(nome, cargo, salario);
    } else {
        int cmp = comparaCargo(cargo, (*root)->cargo);
        if(cmp < 0) {
            insereArvore(&(*root)->left, nome, cargo, salario);
        } else {
            insereArvore(&(*root)->right, nome, cargo, salario);
        }
    }
}

int comparaCargo(char *cargo1, char *cargo2)
{
    char *hierarquia[] = {"CEO", "Presidente", "Diretor", "Gerente", "Supervisor", "Coordenador", "Analista", "Assistente", "Auxiliar", "Estagiario"};
    int i, j;

    for(i = 0; i < 10; i++) {
        if(strcmp(cargo1, hierarquia[i]) == 0) break;
    }

    for(j = 0; j < 10; j++) {
        if(strcmp(cargo2, hierarquia[j]) == 0) break;
    }

    return i - j;
}

node *pop(node *PILHA, char *nome, char *cargo, int salario)
{
    if(vazia(PILHA)){
        printf("PILHA ja vazia\n\n");
        return NULL;
    } else {
        node *atual = PILHA->prox;
        node *anterior = PILHA;

        while(atual != NULL){
            // Comparar nome e cargo
            if(strcmp(atual->nome, nome) == 0 && strcmp(atual->cargo, cargo) == 0) {
                // Comparar salário com uma margem de tolerância devido a possíveis imprecisões
                if(fabs(atual->salario - salario) < 0.001) {
                    anterior->prox = atual->prox;
                    tam--;
                    return atual;
                }
            }
            anterior = atual;
            atual = atual->prox;
        }
        return NULL; // Elemento não encontrado
    }
}