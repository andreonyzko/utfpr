#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    double v[N];
    for(int i=0; i<N; i++){
        scanf("%lf", &v[i]);
    }
    for(int i=0; i<N; i++){
        printf("V[%d] = %.1lf\n", i, v[i]);
    }
    for(int i=N-1; i>=0; i--){
        printf("V[%d] = %.1lf\n", i, v[i]);
    }
}