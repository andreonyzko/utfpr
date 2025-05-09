#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noPilha{
    int key;
    struct noPilha* anterior;
} NoPilha;

typedef NoPilha* PtrNoP;

typedef struct noFila{
    int key;
    struct noFila* proximo;
} NoFila;

typedef NoFila* PtrNoF;

typedef struct {
    PtrNoF inicio;
    PtrNoF fim;
    int qtde;
} Fila;

typedef struct{
    PtrNoP topo;
    int qtde;
} Pilha;