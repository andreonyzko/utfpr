#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int l, int c){
    int** m=(int**)calloc(c, sizeof(int *));
    for(int i=0; i<l; i++){
        m[i] = (int*)calloc(c, sizeof(int)); 
    }

    return m;
}

int main(){
    int **p;
    int m, n, i, j;
    scanf("%d %d",&m, &n);
    p = aloca_matriz(m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            p[i][j] = (i*m) + (j+1);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
            }
        printf("\n");
    }
}