#include <stdio.h>


typedef struct produtor_s{
    int cod;
    char grao;
    float quantidade;
} produtor;

void le_graos(produtor* entrada){
    scanf(" %d", &entrada->cod);
    scanf(" %c", &entrada->grao);
    scanf(" %f", &entrada->quantidade);
}

void imprime_totais(produtor* entrada, int tam){
    float f=0, m=0, s=0, t=0;
    for(int i=0; i<tam; i++){
        if(entrada[i].grao == 'F'){
            f+= entrada[i].quantidade;
        } else if(entrada[i].grao == 'M'){
            m+= entrada[i].quantidade;
        } else if(entrada[i].grao == 'S'){
            s+= entrada[i].quantidade;
        } else if(entrada[i].grao == 'T'){
            t+= entrada[i].quantidade;
        }
    }

    printf("Total de toneladas dos Produtos:\nFeijao: %.2f\nMilho: %.2f\nSoja: %.2f\nTrigo: %.2f", f, m, s, t);
}

int main(){
    int n;
    scanf("%d", &n);
    //Declaração da variável tipo struct
    produtor entrada[n];

    for(int i=0;i<n;i++){
    le_graos(&entrada[i]);
    }
    imprime_totais(entrada, n);
}