#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    float v[n];

    for(int i=0; i<n; i++){
        scanf("%f", &v[i]);
    }

    float media;
    scanf("%f", &media);

    for(int i=0; i<n; i++){
        if(v[i] < media){
            printf("V[%d] = %.2f\n", i, v[i]);
        }
    }
}