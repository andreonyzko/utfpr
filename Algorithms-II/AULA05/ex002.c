#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Solicita ao usuário que insira uma string
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha do final da string
    str[strcspn(str, "\n")] = '\0';

    // Declara um ponteiro de caractere para a string
    char* pstr= str;
    char* pistr = str;

    // Encontra o final da string usando o ponteiro
    for(pstr = pstr; *pstr !='\0'; pstr++){}
    pstr--;

    // Imprime a string invertida usando o ponteiro
    for(pstr = pstr; pstr != pistr-1; pstr--){
        printf("%c", *pstr);
    }

    return 0;
}