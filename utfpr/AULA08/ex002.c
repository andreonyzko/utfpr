#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    float v1[n];
    int v2[n];

    for(int i=0; i<n; i++){
        float value;
        scanf("%f", &value);
        v1[i]= value;
    }

    for(int i=0; i<n; i++){
        int value;
        scanf("%d", &value);
        v2[i] = value;
    }

    for(int i=0; i<n; i++){
        printf("%.2f * %d = %.2f\n", v1[i], v2[i], v1[i]*v2[i]);
    }
}