#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct noFila{
  int chave;
  struct noFila* proximo;
} NoFila;

typedef NoFila* PtrNo;

typedef struct{
  PtrNo inicio;
  PtrNo fim;
  int qtde;
} Fila;

typedef Fila* PtrFila;

void inicializar(PtrFila f);
void enfileirar(PtrFila f, int valor);
void desenfileirar(PtrFila f);
void imprimir(PtrFila f);
int tamanho(PtrFila f);
bool estaVazia(PtrFila f);
int primeiro(PtrFila f);
int ultimo(PtrFila f);
void destruir(PtrFila f);

int main(){
  SetConsoleOutputCP(65001);

  PtrFila fila = (PtrFila)malloc(sizeof(Fila));
  inicializar(fila);

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
      printf("7- Destruir\n");
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
          enfileirar(fila, value);
          break;
      
      case 2:
          desenfileirar(fila);
          break;

      case 3:
          imprimir(fila);
          break;

      case 4:
          printf("A fila tem %d elementos\n", tamanho(fila));
          break;

      case 5:
          printf("%d\n", primeiro(fila));
          break;

      case 6:
          printf("%d\n", ultimo(fila));
          break;
      
      case 7:
        destruir(fila);
        escolha = 0;
        break;
      
      default:
          printf("Opção inválida!\n");
          break;
      }
  }while(escolha != 0);
}

void inicializar(PtrFila f){
  f->inicio = NULL;
  f->fim = NULL;
  f->qtde = 0;
}

void enfileirar(PtrFila f, int valor){
  PtrNo no = (PtrNo)malloc(sizeof(NoFila));
  no->chave = valor;
  no->proximo = NULL;
  
  if(f->fim == NULL){
    f->inicio = no;
  } else{
    f->fim->proximo = no;
  }

  f->fim = no;
  f->qtde++;
}

void desenfileirar(PtrFila f){
  if(!estaVazia(f)){
    PtrNo aux = f->inicio;
    f->inicio = f->inicio->proximo;
    free(aux);
    f->qtde--;

    if(f->inicio == NULL) f->fim = NULL;
  } else printf("A Fila está vazia!\n");
}

void imprimir(PtrFila f){
  printf("Fila: [ ");

  for(PtrNo i= f->inicio; i != NULL; i = i->proximo){
    printf("%d ", i->chave);
  }

  printf("]\n");
}

int tamanho(PtrFila f){
  return f->qtde;
}

bool estaVazia(PtrFila f){
  return (f->inicio == NULL);
}

int primeiro(PtrFila f){
  if (!estaVazia(f)) return (f->inicio->chave);
  else return -1;
}

int ultimo(PtrFila f){
  if (!estaVazia(f)) return(f->fim->chave);
  else return -1;
}

void destruir(PtrFila f){
  free(f);
}