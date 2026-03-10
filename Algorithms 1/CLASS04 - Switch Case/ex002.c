#include <stdio.h>

int main(){
    float salario, reajuste;

    scanf("%f %f", &salario, &reajuste);

    salario += salario*reajuste/100;

    printf("R$ %.2f", salario);
}