#include <stdio.h>

int main(){
    int l1, c1, maior=0, menor, lmenor;
    scanf("%d %d", &l1, &c1);
    int matriz[l1][c1];

    for(int l=0; l<l1; l++){
        for(int c=0; c<c1; c++){
            scanf("%d", &matriz[l][c]);
        }
    }

    menor= matriz[0][0];
    lmenor=0;

    for(int l=0; l<l1; l++){
        for(int c=0; c<c1; c++){
            if(matriz[l][c] < menor){
                menor = matriz[l][c];
                lmenor = l;
            }
        }
    }

    for(int c=0; c<c1; c++){
        if(matriz[lmenor][c] > maior){
            maior = matriz[lmenor][c];
        }
    }

    printf("MinMax = %d", maior);
}