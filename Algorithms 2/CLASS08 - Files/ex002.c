#include <stdio.h>
#include <string.h>

void lerItensDaLista(FILE *file){
    // char line[100];
    // while(strcmp(fgets(line, 100, file),)){
    //     printf("%s", line);
    // }

    char palavra[100];

    while(fscanf(file, "%s", palavra) == 1){
        printf("%s\n", palavra);
    }
}

int main(){
    FILE *arq;
    arq = fopen("ListaCompras.txt", "w+");
        
    // 1o. item
    fprintf(arq, "%s\n", "Leite");
    // 2o. item
    fprintf(arq, "%s\n", "Pao");
    // 3o. item
    fprintf(arq, "%s\n", "Presunto");
    // 4o. item
    fprintf(arq, "%s\n", "Manteiga");
        
    rewind(arq);
        
    lerItensDaLista(arq);
    fclose(arq);
}