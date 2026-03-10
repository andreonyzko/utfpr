#include <stdio.h>

int main(){
    char letter;
    int cons=0, vog=0;

    do{
        scanf("%c", &letter);
        if(letter == '!')
            break;
        if(letter  == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' || letter == 'I' || letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U')
            vog++;
        else
            cons++;
    }while(letter != '!');

    if(vog > cons)
        printf("Ha mais vogais que consoantes.");
    if(cons > vog)
        printf("Ha mais consoantes que vogais.");
    if(cons == vog)
        printf("Empate!");
}