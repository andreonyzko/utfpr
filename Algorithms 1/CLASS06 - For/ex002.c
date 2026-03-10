#include <stdio.h>

int main(){
    int A, B, soma=0;
    scanf("%d %d", &A, &B);
    if(A < B){
        for(int i=A; i<=B; i++){
            printf("%d ",i);
            soma += i;
        }
        } else{
            for(int i=B; i<=A; i++){
            printf("%d ",i);
            soma += i;
        }
    }
    printf("\nSoma = %d", soma);
}