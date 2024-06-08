#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    float matriz[n][n];
    for(int l=0; l<n; l++){
        for(int c=0; c<n; c++){
            float n2;
            scanf("%f", &n2);
            n2 += n2;
            matriz[l][c] = n2;
        }
    }

    for(int l=0; l<n; l++){
        for(int c=0; c<n; c++){
            printf("%.1f ", matriz[l][c]);
        }
        printf("\n");
    }
}