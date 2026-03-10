#include <stdio.h>
#include <stdlib.h>

int* aloca_vetor(int n){
    return malloc(n*sizeof(int));
}

void le_elementos(int* v, int n){
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
}

void print_vetor(int* v, int n){
    float media=0;
    for(int i=0; i<n; i++){
        printf("v[%d]=%d\n", i, v[i]);
        media += v[i];
    }

    media /= n;
    printf("Media=%.2f", media);
}

int main(){
    int n, *p;    
    scanf("%d", &n);
    p = aloca_vetor(n);
    le_elementos(p, n);
    print_vetor(p, n);
}