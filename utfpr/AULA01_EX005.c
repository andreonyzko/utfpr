#include <stdio.h>

int main(){
    int entire;
    float real;
    char letter;
    scanf("%i",&entire);
    scanf("%f",&real);
    scanf(" %c",&letter);
    printf("%i %.4f %c",entire,real,letter);
}