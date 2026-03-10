#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Crie uma estrutura de dados Trie
typedef struct node {
    char letter;
    struct node* children[26];
    bool end;
} Node;

Node* createNode(char letter){
    Node* node = (Node*)malloc(sizeof(Node));
    node->letter = letter;
    for(int i=0; i<26; i++) node->children[i] = NULL;
    node->end = false;
    return node;
}

// Insira palavras na Trie
void insert(Node* root, char* keyword){
    Node* node = root;
    for(int i=0; keyword[i] != '\0'; i++){
        int index = keyword[i] - 'a';
        if(node->children[index] == NULL) node->children[index] = createNode(keyword[i]);
        node = node->children[index];
    }
    node->end = true;
}

// Busca se uma palavra específica existe na Trie
bool find(Node* root, char* keyword){
    Node* node = root;
    for(int i=0; keyword[i] != '\0'; i++){
        int index = keyword[i] - 'a';
        if(node->children[index] == NULL) return false;
        node = node->children[index];
    }
    return node->end;
}

int main(){
    Node* tree = createNode('\0');

    // Insira palavras na Trie
    insert(tree, "andre");
    insert(tree, "computador");
    insert(tree, "programacao");
    insert(tree, "estrutura de dados");

    // Busca se uma palavra específica existe na Trie
    printf("Enter a keyword to find: ");
    char keyword[100];
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    if(find(tree, keyword)) printf("Keyword founded");
    else printf("Keyword not founded");
}