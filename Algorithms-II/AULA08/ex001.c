#include <stdio.h>

int contaCaracteresArquivo(FILE *file){
    int count=0;
    char c;
    while((c = fgetc(file)) != EOF ){
        if(c== ' ' || c=='\n'){
            continue;
        }
        else{
            count++;
        }
    }

    return count;
}

int main(){
    FILE* fp = fopen("teste.txt","w+");
    char *s = "teste";
    fputs(s,fp);
    rewind(fp);
    printf("%d\n",contaCaracteresArquivo(fp));
    fclose(fp);
}