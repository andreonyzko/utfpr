#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoArvore {
  int key;
  struct NoArvore* right;
  struct NoArvore* left;
} NoArvore;
typedef NoArvore* PtrNoArvore;

void iniciaArvoreBinaria(PtrNoArvore* PtrRaiz) {
  *PtrRaiz = NULL;
}

bool estaVazia(PtrNoArvore raiz){
  return (raiz == NULL);
}


bool inserir(PtrNoArvore* no, int key){
  if(*no == NULL){
    PtrNoArvore new = (PtrNoArvore)malloc(sizeof(NoArvore));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    *no = new;
    return true;
  }

  else if(key < (*no)->key) return inserir(&(*no)->left, key);
  else if(key > (*no)->key) return inserir(&(*no)->right, key);
  else return false;
}

void PreOrdem(PtrNoArvore* no){
  if(*no == NULL) return;
  printf("%d ", (*no)->key);
  PreOrdem(&(*no)->left);
  PreOrdem(&(*no)->right);
}

void Ordem(PtrNoArvore* no){
  if(*no == NULL) return;
  Ordem(&(*no)->left);
  printf("%d ", (*no)->key);
  Ordem(&(*no)->right);
}

void OrdemDesc(PtrNoArvore* no){
  if(*no == NULL) return;
  OrdemDesc(&(*no)->right);
  printf("%d ", (*no)->key);
  OrdemDesc(&(*no)->left);
}

void PosOrdem(PtrNoArvore* no){
  if(*no == NULL) return;
  PosOrdem(&(*no)->left);
  PosOrdem(&(*no)->right);
  printf("%d ", (*no)->key);
}

void ImprimirPre(PtrNoArvore* raiz){
  printf("Pre-Ordem : { ");
  PreOrdem(raiz);
  printf("}\n");
}

void ImprimirOrdem(PtrNoArvore* raiz){
  printf("Em Ordem : { ");
  Ordem(raiz);
  printf("}\n");
}

void ImprimirOrdemDesc(PtrNoArvore* raiz){
  printf("Em Ordem Decrescente: { ");
  OrdemDesc(raiz);
  printf("}\n");
}

void ImprimirPos(PtrNoArvore* raiz){
  printf("Pos-Ordem : { ");
  PosOrdem(raiz);
  printf("}\n");
}

int NoAmount(PtrNoArvore* no){
  if(*no == NULL) return 0;
  return 1 + NoAmount(&(*no)->left) + NoAmount(&(*no)->right);
}

int LeafAmount(PtrNoArvore* no){
  if(*no == NULL) return 0;
  if((*no)->left == NULL && (*no)->right == NULL ) return 1;
  return LeafAmount(&(*no)->left) + LeafAmount(&(*no)->right);
}

int main(){
  PtrNoArvore raiz;
  iniciaArvoreBinaria(&raiz);

  if(estaVazia(raiz)) printf("Arvore vazia!\n");

  inserir(&raiz, 23);
  inserir(&raiz, 12);
  inserir(&raiz, 45);
  inserir(&raiz, 11);
  inserir(&raiz, 18);
  inserir(&raiz, 27);
  inserir(&raiz, 71);
  inserir(&raiz, 53);

  ImprimirPre(&raiz);


  printf("Quantidade de nos: %d\n", NoAmount(&raiz));
  printf("Quantidade de nos folha: %d\n", LeafAmount(&raiz));
}

