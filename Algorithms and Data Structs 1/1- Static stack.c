#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#define TAM 10

typedef struct {
    int vetor[TAM];
    int qntd;
} PilhaEstatica;

typedef PilhaEstatica* PtrPilha;

void inicializa(PtrPilha p);
void empilhar(PtrPilha p, int valor);
void desempilhar(PtrPilha p);
bool estaCheia(PtrPilha p);
bool estaVazia(PtrPilha p);
int tamanho(PtrPilha p);
int topo(PtrPilha p);
void imprimir(PtrPilha p);


int main(){
    SetConsoleOutputCP(65001);

    PilhaEstatica pilha;
    inicializa(&pilha);

    int escolha;
    do{
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("1- Empilhar\n");
        printf("2- Desempihar\n");
        printf("3- Imprimir pilha\n");
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("4- Esta Cheia?\n");
        printf("5- Esta Vazia?\n");
        printf("6- Tamanho da pilha\n");
        printf("7- Valor do topo\n");
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("0- Sair\n");
        printf("\n");
        printf("Digite uma opção: ");
        scanf("%d", &escolha);

        int value;

        switch (escolha)
        {
        case 1:
            scanf("%d", &value);
            empilhar(&pilha, value);
            break;
        
        case 2:
            desempilhar(&pilha);
            break;

        case 3:
            imprimir(&pilha);
            break;

        case 4:
            if(estaCheia(&pilha)) printf("A pilha está cheia!\n");
            else printf("A pilha não está cheia!\n");
            break;
            
        case 5:
            if(estaVazia(&pilha)) printf("A pilha está vazia!\n");
            else printf("A pilha não está vazia!\n");
            break;

        case 6:
            printf("A pilha tem %d elementos\n", tamanho(&pilha));
            break;

        case 7:
            printf("O valor no topo da pilha é %d\n", topo(&pilha));
            break;
        
        case 0:
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }
    }while(escolha != 0);
}

void inicializa(PtrPilha p){
    p->qntd = 0;
}

void empilhar(PtrPilha p, int valor){
    if(!estaCheia(p)){
        p->vetor[p->qntd] = valor;
        p->qntd++;
    }
    else{
        printf("A pilha está cheia!\n");
    }
}

void desempilhar(PtrPilha p){
    if(!estaVazia(p)){
        p->qntd--;
    }
    else{
        printf("A pilha está vazia!\n");
    }
}

bool estaCheia(PtrPilha p){
    return (p->qntd == TAM);
}

bool estaVazia(PtrPilha p){
    return (p->qntd == 0);
}

int tamanho(PtrPilha p){
    return p->qntd;
}

int topo(PtrPilha p){
    return p->vetor[p->qntd-1];
}

void imprimir(PtrPilha p){
    printf("Pilha : [ ");
    for(int i=0; i<p->qntd; i++){
        printf("%d ", p->vetor[i]);
    }
    printf("]\n");
}
