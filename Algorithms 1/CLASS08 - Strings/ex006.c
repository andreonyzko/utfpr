#include <stdio.h>

int main(){
    char frase[29];
    scanf(" %[^\n]s", frase);
    for(int i=0; frase[i]!='\0'; i++){
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
            frase[i] = '_';
        }
    }

    printf("%s", frase);
}