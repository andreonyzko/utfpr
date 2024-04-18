#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);

    while(number != -101){
        if(number >= -101 && number <= 100){
            if(number != 0){
                    if(number % 2 ==0){
                    printf("EVEN");
                } else{
                    printf("ODD");
                }
                if(number > 0){
                    printf(" POSITIVE\n");
                } else{
                    printf(" NEGATIVE\n");
                }
            } else{
                printf("NULL\n");
            }
        }
        else
            printf("Valor invalido! Tente novamente!\n");
        scanf("%d", &number);
    }
}