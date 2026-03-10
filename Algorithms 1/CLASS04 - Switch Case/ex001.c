#include <stdio.h>

int main(){
    char user;
    int pass;

    scanf("%c %i", &user, &pass);

    switch (user)
    {
    case 'A':
    case 'D':
        if(pass == 555){
            printf("Acesso ADMIN");
        }else{
            printf("Acesso NEGADO");
        }
        break;

    case 'U':
        if(pass == 123){
            printf("Acesso USER");
        } else{
            printf("Acesso NEGADO");
        }
        break;
    
    default:
        printf("Acesso NEGADO");
        break;
    }
}