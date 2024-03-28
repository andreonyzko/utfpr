#include <stdio.h>

int main(){
    int age;
    scanf("%i", &age);
    if(age >= 17 && age <=65){
        printf("Idade valida");
    } else {
        printf("Idade invalida");
    }
}