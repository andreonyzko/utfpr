#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *findAlphabeticFile(FILE *f){
    char c;
    char result[100];
    char *point = result;
    int count=0;
    while((c= fgetc(f)) != '\0'){
        if(isalpha(c)){
            result[count] = c;
            count++;
        }
    }
    result[count] = '\0';
    printf("%s", result);

    return point;
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