#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char cidade_origem[30];
    char cidade_destino[30];
    
    char data_origem[11]; 
    char horario_origem[6];//25/07/aaaa
    
    char data_destino[11];
    char horario_destino[6];
}voo;
int main(){
    voo voo1;

    strcpy(voo1.cidade_origem, "Sao Paulo");
    strcpy(voo1.cidade_destino, "Rio de Janeiro");
    strcpy(voo1.data_origem, "10/05/2024");
    strcpy(voo1.horario_origem, "08:30");
    strcpy(voo1.data_destino, "10/05/2024");
    strcpy(voo1.horario_destino, "10:00");

    voo voo2 = {"New York", "London", "15/05/2024", "14:00", "15/05/2024", "18:30"};

    printf("Voo 1:\n");
    printf("Origem: %s\n", voo1.cidade_origem);
    printf("Destino: %s\n", voo1.cidade_destino);
    printf("Data de Partida: %s\n", voo1.data_origem);
    printf("Hora de Partida: %s\n", voo1.horario_origem);
    printf("Data de Chegada: %s\n", voo1.data_destino);
    printf("Hora de Chegada: %s\n", voo1.horario_destino);
    printf("\n");

    printf("Voo 2:\n");
    printf("Origem: %s\n", voo2.cidade_origem);
    printf("Destino: %s\n", voo2.cidade_destino);
    printf("Data de Partida: %s\n", voo2.data_origem);
    printf("Hora de Partida: %s\n", voo2.horario_origem);
    printf("Data de Chegada: %s\n", voo2.data_destino);
    printf("Hora de Chegada: %s\n", voo2.horario_destino);



}