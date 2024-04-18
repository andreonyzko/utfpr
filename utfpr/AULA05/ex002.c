#include <stdio.h>

int main(){
    int n;
    while(1){
        scanf("%d", &n);

        if(n < 1000 && n > 2){
            break;
        } else{
            printf("Valor invalido! Tente novamente!\n");
        }
    }

    for(int i=1; i<=10; i++){
        printf("%d X %d = %d\n", i, n, i*n);
    }
}