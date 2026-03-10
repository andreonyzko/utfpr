#include <stdio.h>

int main(){
    int valores[10];

    for(int i=0; i<10; i++){
        scanf("%d", &valores[i]);
    }
    for(int i=0; i<10; i++){
        if(valores[i] >= 0 && valores[i]<=25){
            printf("Intervalo [0,25]: x = %d\n", valores[i]);
        } else if(valores[i] > 25 && valores[i]<=50){
            printf("Intervalo (25,50]: x = %d\n", valores[i]);
        } else if(valores[i] > 50 && valores[i]<=75){
            printf("Intervalo (50,75]: x = %d\n", valores[i]);
        } else if(valores[i] > 75 && valores[i]<=100){
            printf("Intervalo (75,100]: x = %d\n", valores[i]);
        } else{
            printf("Fora de intervalo: x = %d\n", valores[i]);
        }
    }
}