#include <stdio.h>

int main()
{
    int A, B, C, D;
    scanf("%i%i%i%i", &A, &B, &C, &D);
    if(A>B && C<D){
        printf("Valores aprovados");
    } else {
        printf("Valores reprovados");
    }
    return 0;
}
