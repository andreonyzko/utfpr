#include <stdio.h>

int main(){
    int N;
    float pagar=0, receber=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        float valor=0;
        scanf("%f", &valor);
        if(valor > 0){
            receber += valor;
        } else if(valor < 0){
            pagar += valor;
        } else{
            continue;
        }
    }
    printf("Pagar: R$ %.2f\nReceber: R$ %.2f\nSaldo: R$ %.2f", pagar, receber, pagar+receber);
}