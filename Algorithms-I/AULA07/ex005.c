#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    float v1[n];
    int v2[n];

    for(int i=0; i<n; i++){
        scanf("%f", &v1[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &v2[i]);
    }

    for(int i=0; i<n; i++){
        printf("%.2f * %d = %.2f\n", v1[i], v2[i], v1[i]*v2[i]);
    }
}