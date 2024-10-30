#include <stdio.h>

int main(){
    int x, *p;
    scanf("%d", &x);
    p = &x;
    printf("Valor de p: %d\n", *p);
}