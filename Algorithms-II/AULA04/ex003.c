#include <stdio.h>

void troca(int *a, int *b){
    int memory = *a;
    *a = *b;
    *b = memory;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    troca(&a, &b);
    printf("%d %d", a, b);
}