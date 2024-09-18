#include <stdio.h>
#include <ctype.h>

int main(){
    char string1[100], string2[100];
    int iguais=1, i;
    scanf("%[^\n]s", string1);
    scanf(" %[^\n]s", string2);



    for(i=0; string1[i]!='\0' && string2[i]!='\0'; i++){
        if(tolower(string1[i]) != tolower(string2[i])){
            iguais = 0;
            break;
        }
        iguais++;
    }

    if(string1[i] != '\0' || string2[i] != '\0'){
        iguais=0;
    }
    
    if(iguais>0){
        printf("As frases sao iguais");
    }
    else{
        printf("As frases sao diferentes");
    }
}