#include <stdio.h>

int main(){
    float number, decimal;
    int inteiro;
    scanf("%f",&number);
    inteiro = number;
    decimal = number - inteiro;
    printf("%i %.5f", inteiro, decimal);
}