#include <stdio.h>

void soma(void *a, void *b, char tipo){
    switch (tipo)
    {
    case 'i':
        printf("Resultado: %d\n", *(int *)a+*(int *)b);
        break;

    case 'f':
        printf("Resultado: %.2f\n", *(float *)a+*(float *)b);
        break;

    case 'd':
        printf("Resultado: %.3lf\n", *(double *)a+*(double *)b);
        break;
    
    default:
        printf("Tipo inválido!\n");
        break;
    }
}

int main(){
    int a_int = 10, b_int = 20;
    float a_float = 1.5, b_float = 2.5;
    double a_double = 3.1415, b_double = 2.718;
    soma(&a_int, &b_int, 'i');
    soma(&a_float, &b_float, 'f');
    soma(&a_double, &b_double, 'd');
}