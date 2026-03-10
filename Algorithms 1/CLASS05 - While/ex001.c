#include <stdio.h>

int main(){
    char letter;
    int a=0,e=0,i=0,o=0,u=0, letters=0;

    while(letter != 'x'){
        scanf("%c", &letter);
        letters++;
        if(letter == 'a' || letter == 'A')
            a++;
        if(letter == 'e' || letter == 'E')
            e++;
        if(letter == 'i' || letter == 'I')
            i++;
        if(letter == 'o' || letter == 'O')
            o++;
        if(letter == 'u' || letter == 'U')
            u++;
    }

    printf("a: %d, e: %d, i: %d, o: %d, u: %d, total de letras: %d", a, e, i, o, u, letters);
}