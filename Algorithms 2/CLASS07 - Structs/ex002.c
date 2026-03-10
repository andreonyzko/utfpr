#include <stdio.h>
#include <math.h>

typedef struct coordenada{
    double x;
    double y;
} Coordenada;

double calcDeslocamento(Coordenada* seq, int tam){
    double distancia=0;
    for(int i=1; i<tam; i++){
        double dx = seq[i].x - seq[i-1].x;
        double dy = seq[i].y - seq[i-1].y;
        distancia += sqrt(dx*dx + dy*dy);
    }

    return distancia;
}

int main(){
    int tam;
    double ds = 0;
    scanf("%d", &tam);
    Coordenada seq[tam];
    for(int i=0;i<tam;i++){
        scanf("%lf%lf", &(seq[i].x), &(seq[i].y));
    }
    ds = calcDeslocamento(seq, tam);
    printf("Deslocamento = %.2lf m\n", ds);
}