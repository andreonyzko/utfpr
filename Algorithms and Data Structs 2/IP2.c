#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// mplemente uma Definição do Nó
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Implemente os métodos para as seguintes operações: insert(value), init() e inorder() (travessia em ordem)
Node *insert(Node *root, int key)
{
    if (root == NULL)
        root = createNode(key);
    if (key > root->key)
        root->right = insert(root->right, key);
    else if (key < root->key)
        root->left = insert(root->left, key);
    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d -> ", root->key);
        inOrder(root->right);
    }
}

// Implemente um método search(value)
bool find(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    if (key < root->key)
        return find(root->left, key);
    else
        return find(root->right, key);
}

// Meça o tempo de processamento para buscar cada um dos valores em cada árvore
double timingSearch(Node *root, int key)
{
    clock_t start = clock();

    for (int i = 0; i < 1000000; i++)
    {
        find(root, key);
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
    Node *A = NULL;
    int keysA[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        A = insert(A, keysA[i]);

    Node *B = NULL;
    int keysB[] = {10, 20, 30, 40, 60, 70, 80};
    for (int i = 0; i < 7; i++)
        B = insert(B, keysB[i]);

    int keysSearch[] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (int i = 0; i < 8; i++)
    {
        printf("Number %d (A): %fs\n", keysSearch[i], timingSearch(A, keysSearch[i]));
        printf("Number %d (B): %fs\n", keysSearch[i], timingSearch(B, keysSearch[i]));
    }
}