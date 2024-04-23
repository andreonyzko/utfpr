#include <stdio.h>

int main(){
    int year;
    scanf("%i", &year);
    if(year%4 == 0 && year%100 != 0){
        printf("Ano bissexto");
    } else if(year%100 == 0 && year%400 == 0){
        printf("Ano bissexto");
    } else{
        printf("Ano regular");
    }
}