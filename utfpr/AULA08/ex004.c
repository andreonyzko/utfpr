#include <stdio.h>

int main(){
    char frase[100], frase2[100];
    scanf(" %[^\n]s", frase);
    int i=0;

    for(i=0; frase[i] != '\0'; i++){
        if (frase[i] == ' '){
            frase2[i] = ' ';
        }
        else if (frase[i] == 'z'){
            frase2[i] = 'A';
        }
        else{
            int letra = (int)frase[i];
            letra++;
            letra -= 32;
            frase2[i] = (char)letra;
        }
    }
    frase2[i] = '\0';
    printf("%s", frase2);
}