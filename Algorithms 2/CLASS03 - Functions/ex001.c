#include <stdio.h>

int multiplica(int x1, int x2){
    return x1*x2;
}

int quadrado(int x){
    return x*x;
}

int cubo(int x){
    return x*x*x;
}

int pol_cubo(int a, int b, int c, int d, int x){
    int xcubo = cubo(x), xquadrado = quadrado(x);
    return a*xcubo+ b*xquadrado+c*x+d;
}

int main(){
    int n, a, b, c, d, x;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &x);
        printf("%d %d %d %d\n", cubo(x), quadrado(x), multiplica(c,x), pol_cubo(a,b,c,d,x));
    }
}