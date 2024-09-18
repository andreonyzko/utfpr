#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    double V[n], value;

    for(int i=0; i<n; i++){
        scanf("%lf", &value);
        V[i] = value;
    }

    for(int i=0; i<n; i++){
        printf("V[%d] = %.1lf\n", i, V[i]);
    }

    for(int i=n-1; i>=0; i--){
        printf("V[%d] = %.1lf\n", i, V[i]);
    }
}