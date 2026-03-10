#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. Crie uma estrutura que represente uma árvore binária. Apenas os tipos de dados.
typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int key){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Inserção de nós
Node* insert(Node* root, int key){
    if(root == NULL) root = createNode(key);
    if(key > root->key) root->right = insert(root->right, key);
    else if(key < root->key) root->left = insert(root->left, key);
    return root;
}

// Busca por um valor específico
bool find(Node* root, int key){
    if(root == NULL) return false;
    if(root->key == key) return true;
    if(key < root->key) return find(root->left, key);
    else return find(root->right, key);
}

// Percurso em ordem para imprimir os nós em ordem de crescente.
void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d -> ", root->key);
        inOrder(root->right);
    }
}

int main(){
    // Inserção de nós: insira 10 valores na árvore (pode inserir na ordem que mantenha a árvore balanceada)
    int keys[] = {4, 8, 1, 3, 7, 9, 0, 2, 6, 5};
    Node* tree = NULL;
    for(int i=0; i<10; i++) tree = insert(tree, keys[i]);

    // Busca por um valor específico
    printf("Enter a number to find: ");
    int number;
    scanf("%d", &number);
    if(find(tree, number)) printf("Number found!\n");
    else printf("Number not found!\n");

    // Percurso em ordem para imprimir os nós em ordem de crescente.
    inOrder(tree);
}