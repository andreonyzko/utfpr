#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noPilha{
    int key;
    struct noPilha* anterior;
} No;

typedef No* PtrNo;

typedef struct{
    PtrNo topo;
    int qtde;
} Pilha;

typedef Pilha* PtrPilha;

void inicializar(PtrPilha p);
void inserir(PtrPilha p, int value);

int main(){
    PtrPilha p = (PtrPilha)malloc(sizeof(Pilha));
    inicializar(p);
    printf("Digite os valores para colocar na pilha (-1 para sair): ");

    int value;
    while(1){
        scanf("%d", &value);
        if(value == -1) break;
        inserir(p, value);
    }

    printf("\nPilha: [ ");
    for(PtrNo i = p->topo; i != NULL; i = i->anterior) printf("%d ", i->key);
    printf("]");
}

void inicializar(PtrPilha p){
    p->topo= NULL;
    p->qtde= 0;
}

void inserir(PtrPilha p, int value){
    PtrNo no = (PtrNo)malloc(sizeof(No));
    no->key= value;
    no->anterior = p->topo;
    p->topo = no;
}