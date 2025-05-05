#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct noLista
{
    int key;
    struct noLista *proximo;
} NoLista;
typedef NoLista *PtrNo;

typedef struct
{
    PtrNo inicio;
    int qtde;
} Lista;
typedef Lista *PtrLista;

void inicializar(PtrLista l);
void inserir(PtrLista l, int valor);
void remover(PtrLista l, int key);
void imprimir(PtrLista l);
int pesquisar(PtrLista l, int key);
bool estaVazia(PtrLista l);
int tamanho(PtrLista l);

int main()
{
    SetConsoleOutputCP(65001);

    PtrLista l = (PtrLista)malloc(sizeof(Lista));
    inicializar(l);

    int opt, key;
    do
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("1- Inserir na lista\n");
        printf("2- Remover key da lista\n");
        printf("3- Imprimir lista\n");
        printf("4- Obter tamanho da lista\n");
        printf("5- Pesquisar key\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("0- Sair");
        printf("\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            break;

        case 1:
            scanf("%d", &key);
            inserir(l, key);
            break;

        case 2:
            scanf("%d", &key);
            remover(l, key);
            break;
        
        case 3:
            imprimir(l);
            break;

        case 4:
            printf("A lista tem %d elementos\n", tamanho(l));
            break;

        case 5:
            scanf("%d", &key);
            if(pesquisar(l, key) != -1) printf("Valor encontrado na lista!\n");
            else printf("Valor não encontrado na lista!\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opt != 0);
}

void inicializar(PtrLista l)
{
    l->inicio = NULL;
    l->qtde = 0;
}

void inserir(PtrLista l, int valor)
{
    PtrNo no = (PtrNo)malloc(sizeof(NoLista));
    no->key = valor;
    l->qtde++;

    if (l->inicio == NULL || valor < l->inicio->key)
    {
        no->proximo = l->inicio;
        l->inicio = no;
    }
    else
    {
        for (PtrNo i = l->inicio; i != NULL; i = i->proximo)
        {
            if (i->proximo == NULL || (i->proximo->key >= valor && i->key <= valor))
            {
                no->proximo = i->proximo;
                i->proximo = no;
                break;
            }
        }
    }
}

void imprimir(PtrLista l)
{
    printf("Lista: [ ");

    for (PtrNo i = l->inicio; i != NULL; i = i->proximo)
    {
        printf("%d ", i->key);
    }

    printf("]\n");
}

void remover(PtrLista l, int key){
    if(!estaVazia(l)){
        int pos = pesquisar(l, key);
        if(pos != -1){
            PtrNo aux = l->inicio;
            l->qtde--;
            if(pos == 1){
                l->inicio = l->inicio->proximo;
                free(aux);
            }
            else{
                for(int i=1; i!=pos-1; i++){
                    aux = aux->proximo;
                }

                PtrNo noToRemove = aux->proximo;
                aux->proximo = aux->proximo->proximo;
                free(noToRemove);
            }
        } else printf("A key não está na lista!\n");
    } else printf("A lista está vazia!\n");
}

int pesquisar(PtrLista l, int key)
{
    int pos=0;
    for (PtrNo i = l->inicio; i != NULL; i = i->proximo)
    {
        pos++;
        if (i->key == key)
        {
            return pos;
        }
    }
    return -1;
}


bool estaVazia(PtrLista l)
{
    return (l->qtde == 0);
}

int tamanho(PtrLista l)
{
    return l->qtde;
}