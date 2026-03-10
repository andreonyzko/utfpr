#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode{
  int key;
  struct TreeNode* right;
  struct TreeNode* left;
} TreeNode;
typedef TreeNode* TreePtr;

void start(TreePtr* tree){
  *tree = NULL;
}

bool isEmpty(TreePtr* tree){
  return *tree == NULL;
}

bool add(TreePtr* tree, int key){
  if(*tree == NULL){
    *tree = (TreePtr)malloc(sizeof(TreeNode));
    (*tree)->key = key;
    (*tree)->left = (*tree)->right = NULL;
    return true;
  }

  else if(key < (*tree)->key) return add(&(*tree)->left, key);
  else if(key > (*tree)->key) return add(&(*tree)->right, key);
  else{ return false; }
}

bool search(TreePtr* tree, int key){
  if(*tree == NULL) return false;
  if((*tree)->key == key) return true;
  else if(key < (*tree)->key) search(&(*tree)->left, key);
  else search(&(*tree)->right, key);
}

void PreOrdem(TreePtr* tree){
  if(*tree == NULL) return;
  printf("%d ", (*tree)->key);
  PreOrdem(&(*tree)->left);
  PreOrdem(&(*tree)->right);
}

void PosOrdem(TreePtr* tree){
  if(*tree == NULL) return;
  PosOrdem(&(*tree)->left);
  PosOrdem(&(*tree)->right);
  printf("%d ", (*tree)->key);
}

void EmOrdem(TreePtr* tree){
  if(*tree == NULL) return;
  EmOrdem(&(*tree)->left);
  printf("%d ", (*tree)->key);
  EmOrdem(&(*tree)->right);
}

int main(){
  TreePtr raiz;
  start(&raiz);

  add(&raiz, 5);
  add(&raiz, 4);
  add(&raiz, 3);
  add(&raiz, 2);
  add(&raiz, 7);
  add(&raiz, 6);
  add(&raiz, 8);
  add(&raiz, 9);

  printf("Pre-Ordem: ");
  PreOrdem(&raiz);
  printf("\nEm Ordem: ");
  EmOrdem(&raiz);
  printf("\nPos-Ordem: ");
  PosOrdem(&raiz);
  printf("\n");

  while(true){
    int num;
    printf("\nEnter a number (0 to exit): ");
    scanf("%d", &num);

    if(num == 0) break;

    if(search(&raiz, num)) printf("It's in tree");
    else printf("It's not in tree");
  }
}