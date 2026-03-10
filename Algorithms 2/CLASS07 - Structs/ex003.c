#include <stdio.h>

typedef struct endereco{
    char rua[64], cidade[64], estado[64];
    int numero;
} Endereco;

typedef struct Cliente{
    int id;
    char nome[64], telefone[64];
    Endereco ender;
} cliente;

void ler_cliente(cliente* pessoas, int tam){
    for(int i=0; i<tam; i++){
        scanf("%d", &pessoas[i].id);
        scanf(" %[^\n]s", pessoas[i].nome);
        scanf(" %[^\n]s", pessoas[i].ender.rua);
        scanf(" %[^\n]s", pessoas[i].ender.estado);
        scanf(" %[^\n]s", pessoas[i].ender.cidade);
        scanf("%d", &pessoas[i].ender.numero);
        scanf(" %[^\n]s", pessoas[i].telefone);
    }
}

void buscar_cliente(cliente* pessoas, int tam){
    int cod;
    scanf("%d", &cod);
    for(int i=0; i<tam; i++){
        if(pessoas[i].id == cod){
            printf("%d - %s\n%s, %d\n%s - %s\nTel: %s", pessoas[i].id, pessoas[i].nome, pessoas[i].ender.rua, pessoas[i].ender.numero, pessoas[i].ender.cidade, pessoas[i].ender.estado, pessoas[i].telefone);
        }
    }
}

int main(){
    cliente pessoas[3];
    ler_cliente(pessoas, 3);
    buscar_cliente(pessoas, 3);
}