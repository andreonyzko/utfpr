#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    float matriz[n][n];
    float medias[n];
    int menorvalor, maiorvalor;
    for (int l=0; l<n; l++){
        medias[l] = 0;
        for (int c=0; c<n; c++){
            float n2;
            scanf("%f", &n2);
            matriz[l][c] = n2;
            if (l==0 && c ==0){
                menorvalor= n2;
                maiorvalor = n2;
            }
            else if (n2 > maiorvalor){
                maiorvalor = n2;
            }
            else if (n2 < menorvalor){
                menorvalor = n2;
            }
            medias[l] += matriz[l][c];
        }
    }

    for (int l=0; l<n; l++){
        printf("Media da linha %d: %.2f\n", l+1, medias[l]/n);
    }
    printf("Menor valor: %d\n", menorvalor);
    printf("Maior valor: %d", maiorvalor);
}