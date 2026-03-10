#include <stdio.h>

double* max(double* v, int n){
    n--;
    double* vf = v+n;
    double* maior = v;
    for(v = v; v<=vf; v++){
        if(*v > *maior){
            maior = v;
        }
    }
    return maior;
}

int main(){
    double v[5]={2.6, 13.2, 1.65, 0.99, 11.9};
    double *p_max;
    p_max = max (v, 5);
    printf("%.2lf\n", *p_max);
}