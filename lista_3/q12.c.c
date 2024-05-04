#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float salario;
} Funcionario;

int compara_id(const void *a, const void *b) {
    const Funcionario *func1 = (const Funcionario *)a;
    const Funcionario *func2 = (const Funcionario *)b;
    return func1->id - func2->id;
}

int compara_nome(const void *a, const void *b) {
    const Funcionario *func1 = (const Funcionario *)a;
    const Funcionario *func2 = (const Funcionario *)b;
    return strcmp(func1->nome, func2->nome);
}

int compara_salario(const void *a, const void *b) {
    const Funcionario *func1 = (const Funcionario *)a;
    const Funcionario *func2 = (const Funcionario *)b;
    if (func1->salario < func2->salario) return -1;
    if (func1->salario > func2->salario) return 1;
    return 0;
}

int main() {
    
    Funcionario funcionarios[] = {
        {101, "Alice", 2500.0},
        {102, "Bob", 3000.0},
        {103, "Charlie", 2000.0},
        {104, "David", 3500.0}
    };
    int tamanho = sizeof(funcionarios) / sizeof(funcionarios[0]);

    qsort(funcionarios, tamanho, sizeof(Funcionario), compara_id);
    printf("Ordenado por ID:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d: %s - R$ %.2f\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].salario);
    }
    printf("\n");

    qsort(funcionarios, tamanho, sizeof(Funcionario), compara_nome);
    printf("Ordenado por Nome:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d: %s - R$ %.2f\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].salario);
    }
    printf("\n");

    qsort(funcionarios, tamanho, sizeof(Funcionario), compara_salario);
    printf("Ordenado por Salário:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d: %s - R$ %.2f\n", funcionarios[i].id, funcionarios[i].nome, funcionarios[i].salario);
    }
    printf("\n");

    return 0;
}
