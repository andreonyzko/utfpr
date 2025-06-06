#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct noPilha{
    int chave;
    struct noPilha* proximo;
} NoPilha;

typedef NoPilha* PtrNo;

typedef struct pilhadinamica{
    PtrNo topo;
    int qntd;
} PilhaDinamica;

typedef PilhaDinamica* PtrPilha;

void inicializa(PtrPilha p);
void empilhar(PtrPilha p, int valor);
void desempilhar(PtrPilha p);
void imprimir(PtrPilha p);
bool estaVazia(PtrPilha p);
int tamanho(PtrPilha p);
int topo(PtrPilha p);
int pesquisar(PtrPilha p, int valor);
void destruir(PtrPilha p);

int main(){
    SetConsoleOutputCP(65001);

    PtrPilha pilha = (PtrPilha)malloc(sizeof(PilhaDinamica));
    inicializa(pilha);

    int escolha;
    do{
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("1- Empilhar\n");
        printf("2- Desempihar\n");
        printf("3- Imprimir pilha\n");
        printf("=-=-=-=-=-=-=-=-=-=\n");
        printf("4- Buscar valor\n");
        printf("5- Esta Vazia?\n");
        printf("6- Tamanho da pilha\n");
        printf("7- Valor do topo\n");
        printf("8- Destruir pilha\n");
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
            empilhar(pilha, value);
            break;
        
        case 2:
            desempilhar(pilha);
            break;

        case 3:
            imprimir(pilha);
            break;

        case 4:
            scanf("%d", &value);
            int pos = pesquisar(pilha, value);
            if(pos != -1) printf("O valor está na posição %d da pilha\n", pos);
            else printf("O valor não está na pilha!\n");
            break;

        case 5:
            if(estaVazia(pilha)) printf("A pilha está vazia!\n");
            else printf("A pilha não está vazia!\n");
            break;

        case 6:
            printf("A pilha tem %d elementos\n", tamanho(pilha));
            break;

        case 7:
            printf("O valor no topo da pilha é %d\n", topo(pilha));
            break;

        case 8:
            destruir(pilha);
            escolha = 0;
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
    p->topo = NULL;
    p->qntd = 0;
}

void empilhar(PtrPilha p, int valor){
    PtrNo no = (PtrNo)malloc(sizeof(NoPilha));
    no->chave = valor;
    no->proximo = p->topo;
    p->topo = no;
    p->qntd++;
}

void desempilhar(PtrPilha p){
    if(!estaVazia(p)){
        PtrNo aux = p->topo->proximo;
        free(p->topo);
        p->topo = aux;
        p->qntd--;
    }
    else{
        printf("A pilha está Vazia!\n");
    }
}

void imprimir(PtrPilha p){
    printf("Pilha: [ ");
    for(PtrNo i= p->topo; i != NULL; i = i->proximo){
        printf("%d ", i->chave);
    }
    printf("]\n");
}

bool estaVazia(PtrPilha p){
    return(p->qntd == 0);
}

int tamanho(PtrPilha p){
    return p->qntd;
}

int topo(PtrPilha p){
    if(!estaVazia(p)) return p->topo->chave;
    else{
        printf("A pilha está Vazia!\n");
        return 0;
    }
}

int pesquisar(PtrPilha p, int valor){
    int count=0;
    for(PtrNo i=p->topo; i != NULL; i = i->proximo){
        if(i->chave == valor){
            return count;
        }
        count++;
    }

    return -1;
}

void destruir(PtrPilha p){
    free(p);
}