#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *findAlphabeticFile(FILE *f){
    char* letras = (char *)calloc(3,sizeof(char));
    letras = NULL;
    char buffer;
    int contador=0;
    for(int i=0; fread(&buffer, sizeof(char), 1, f); i++){
        if(isalpha(buffer)){
            letras = realloc(letras, contador+2);
            letras[contador] = buffer;
            letras[contador+1] = '\0';
            contador++;
        }
    }
    return letras;
}

int main(){
    FILE *f = fopen("arquivo.txt","w+");
    char frase[] = "Teste 123 Teste 123";
    fprintf(f,"%s",frase);
    rewind(f);
    char *s = findAlphabeticFile(f);
    printf("%s\n",s);
    fclose(f);
    free(s);
}