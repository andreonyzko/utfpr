#include <stdio.h>

void gravaNoArquivo(FILE *fp, int v[], int n){
    for(int i=0; i < n; i++){
        fprintf(fp, "%d ", v[i]);
    }
}

int somaArquivo(FILE *fp){
    fseek(fp, 0, SEEK_SET);
    int buffer, soma=0;
    while(fscanf(fp, "%d", &buffer) != EOF){
        soma += buffer;
    }
    return soma;
}

int main(){
    int v[] = {1,2,3,4,5};
    FILE *fp = fopen("arquivo.txt","w+");
    gravaNoArquivo(fp,v,5);
    printf("Soma = %d\n",somaArquivo(fp));
    fclose(fp);
}