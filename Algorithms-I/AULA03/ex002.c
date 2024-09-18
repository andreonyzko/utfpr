#include <stdio.h>

int main(){
    int codigo, quantidade;

    scanf("%d %d", &codigo, &quantidade);

    switch (codigo)
    {
    case 1:
        printf("Total: R$ %.2f", quantidade * 4.00);
        break;
    
    case 2:
        printf("Total: R$ %.2f", quantidade * 4.50);
        break;
    
    case 3:
        printf("Total: R$ %.2f", quantidade * 5.00);
        break;
    
    case 4:
        printf("Total: R$ %.2f", quantidade * 2.00);
        break;
    
    case 5:
        printf("Total: R$ %.2f", quantidade * 1.50);
        break;
    
    default:
        printf("Codigo invalido");
        break;
    }
}