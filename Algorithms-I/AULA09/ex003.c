#include <stdio.h>

int main(){
    int matriz[3][3];
    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            scanf("%d", &matriz[l][c]);
        }
    }

    for(int l=0; l<3; l++){
        for(int c=0; c<3; c++){
            printf("%d ", matriz[c][l]);
        }
        printf("\n");
    }
}