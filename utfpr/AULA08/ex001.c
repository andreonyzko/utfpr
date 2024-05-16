#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int v1[N], v2[N], contador=0;

    for(int i=0; i<N; i++){
        int value;
        scanf("%d", &value);
        v1[i] = value;
    }

    for(int i=0; i<N; i++){
        int value;
        scanf("%d", &value);
        v2[i] = value;
    }

    for(int i=0; i<N; i++){
        for(int y=0; y<N; y++){
            if(v2[y] == v1[i]){
                contador++;
            }
        }
    }
    printf("Quantidade de elementos iguais: %d", contador);
}