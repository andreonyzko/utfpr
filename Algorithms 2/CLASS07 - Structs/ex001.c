#include <stdio.h>

typedef struct data_s{
    int dia;
    int mes;
    int ano;
} data_t;

typedef struct pessoa_s{
    int cod;
    char nome[64];
    data_t data;
} pessoa_t;

void read_person(pessoa_t* p){
    scanf("%d", &p->cod);
    scanf(" %[^\n]s", &p->nome);
    scanf("%d %d %d", &p->data.dia, &p->data.mes, &p->data.ano);
}

void print_person(pessoa_t p){
    printf("%d - %s\nNascimento: %d/%d/%d", p.cod, p.nome, p.data.dia, p.data.mes, p.data.ano);
}

int main(){
    pessoa_t p;
    read_person(&p);
    print_person(p);
}