#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz_quadrada(int n){
    int **m = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        m[i] = (int*)malloc(n*sizeof(int));
    }

    return m;
}

int main(){
    int n, i, j, **p;
    scanf("%d", &n);        
    p = aloca_matriz_quadrada(n);  
        
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = (i*n) + (j+1);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
}
}