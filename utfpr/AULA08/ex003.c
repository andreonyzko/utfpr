#include <stdio.h>

int main(){
    int n, soma=0;
    scanf("%d", &n);

    int v[n];

    for(int i=0; i<n; i++){
        int value;
        scanf("%d", &value);
        v[i] = value;
        soma+= value;
    }

    float media = (float)soma/(float)n;
    printf("Valores abaixo da média (%.2f):\n", media);

    for(int i=0; i<n; i++){
        if(v[i] < media){
            printf("V[%d]:%d\n", i, v[i]);
        }
    }
}