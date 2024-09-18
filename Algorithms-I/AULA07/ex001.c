#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    float vetor[n], value;
    for(int i=0; i<n; i++){
        scanf("%f", &value);
        vetor[i] = value;
    }
    scanf("%f", &value);
    for(int i=0; i<n; i++){
        if(vetor[i] < value){
            printf("V[%d] = %.2f\n", i, vetor[i]);
        }
    }
}