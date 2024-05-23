#include <stdio.h>

int main(){
    char string[100];
    scanf("%[^\n]s", string);
    int contador=0;

    for(int i=0; string[i]!='\0'; i++){
        contador++;
    }

    printf("A string digitada tem %d caracteres", contador);
}