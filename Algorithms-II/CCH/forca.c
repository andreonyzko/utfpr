#include <stdio.h>
#include <string.h>
#include <ctype.h>

void menu(){
    printf("=-=-=-=-=-=-=- JOGO DA FORCA -=-=-=-=-=-=-=\n");
    printf("1- Novo Jogo\n");
    printf("2- Cadastrar Palavra\n");
    printf("3- Atualizar Palavra\n");
    printf("4- Apagar Palavra\n");
    printf("5- Sair\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

int main(){
    while(1){
        menu();
        char menu_opt[400];
        scanf(" %[^\n]s", menu_opt);
    }
}