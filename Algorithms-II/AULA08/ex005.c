#include <stdio.h>

void gravaNoArquivo(FILE *fp, char *v){
    for(int i=0; v[i] != '\0'; i++){
        fprintf(fp, "%c\n", v[i]);
    }
}

int encontrouCaractereArquivo(FILE* arq, char ch){
    fseek(arq, 0, SEEK_SET);
    char buffer;
    while(fscanf(arq, "%c\n", &buffer) != EOF){
        if(buffer == ch){
            return 1;
        }
    }
    return 0;
}

int main(){
    char v[10] = "Teste";
    FILE *fp = fopen("arquivo.txt","w+");
    gravaNoArquivo(fp,v);
    char ch = 'e';
    int encontrou = encontrouCaractereArquivo(fp, ch);
    if(encontrou)
        printf("Caractere = %c encontrado no arquivo.\n", ch);
    else
        printf("Caractere = %c nao foi encontrado no arquivo.\n", ch);
    fclose(fp);
}