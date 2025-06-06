#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define TAM 10

typedef struct {
    int vetor[TAM];
    int inicio;
    int fim;
    int qntd;
} FilaEstatica;

typedef FilaEstatica* PtrFila;

void inicializar(PtrFila f);
void enfilerar(PtrFila f, int valor);
void desenfilerar(PtrFila f);
void imprimir(PtrFila f);
int incrementaIndice(int indice);
int tamanho(PtrFila f);
bool estaCheia(PtrFila f);
bool estaVazia(PtrFila f);
int primeiro(PtrFila f);
int ultimo(PtrFila f);

int main(){
    SetConsoleOutputCP(65001);

    FilaEstatica fila;
    inicializar(&fila);

    int escolha;
    do{
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("1- Enfilerar\n");
        printf("2- Desenfilerar\n");
        printf("3- Imprimir fila\n");
        printf("4- Tamanho da fila\n");
        printf("5- Primeiro elemento da fila\n");
        printf("6- Ultimo elemento da fila\n");
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("0- Sair\n");
        printf("\n");
        printf("Digite uma opção: ");
        scanf("%d", &escolha);

        int value;

        switch (escolha)
        {
        case 0:
            break;

        case 1:
            scanf("%d", &value);
            enfilerar(&fila, value);
            break;
        
        case 2:
            desenfilerar(&fila);
            break;

        case 3:
            imprimir(&fila);
            break;

        case 4:
            printf("A fila tem %d elementos\n", tamanho(&fila));
            break;

        case 5:
            printf("%d\n", primeiro(&fila));
            break;

        case 6:
            printf("%d\n", ultimo(&fila));
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }
    }while(escolha != 0);
}

void inicializar(PtrFila f){
    f->inicio= 0;
    f->fim = -1;
    f->qntd = 0;
}

void enfilerar(PtrFila f, int valor){
    if(!estaCheia(f)){
        f->fim = incrementaIndice(f->fim);
        f->vetor[f->fim] = valor;
        f->qntd++;
    }
    else{
        printf("A fila está cheia!\n");
    }
}

void desenfilerar(PtrFila f){
    if(!estaVazia(f)){
        f->inicio = incrementaIndice(f->inicio);
        f->qntd--;
    }
    else{
        printf("A Fila está vazia!\n");
    }
}

void imprimir(PtrFila f){
    if(!estaVazia(f)){
        printf("Fila: [ ");
        int i=f->inicio;
        for(i = i; i != f->fim; i = incrementaIndice(i)){
            printf("%d ", f->vetor[i]);
        }
        printf("%d ", f->vetor[i]);
        printf("]\n");
    }
    else{
        printf("A Fila está vazia!\n");
    }
}

int incrementaIndice(int indice){
    if(indice == (TAM-1)){
        return 0;
    }
    else{
        indice++;
        return indice;
    }
}

int tamanho(PtrFila f){
    return f->qntd;
}

bool estaCheia(PtrFila f){
    return (f->qntd == TAM);
}

bool estaVazia(PtrFila f){
    return (f->qntd == 0);
}

int primeiro(PtrFila f){
    return (f->vetor[f->inicio]);
}

int ultimo(PtrFila f){
    return (f->vetor[f->fim]);
}