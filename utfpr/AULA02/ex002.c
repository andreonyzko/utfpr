#include <stdio.h>

int main(){
    int X, Y, Z, W;
    scanf("%i%i%i%i", &X, &Y, &Z, &W);
    if(X == Y || Z != W){
        printf("Resultado: Ao menos uma expressão é VERDADEIRA");
    } else{
        printf("Resultado: Todas as expressões são FALSAS");
    }
}