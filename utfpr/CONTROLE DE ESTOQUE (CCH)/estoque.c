#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int cod[50];
    char produto[50][100];
    float price[50];
    int quantidade[50];
    int qnt_produtos = 0;

    while(1){
        int choice;
        printf("\n\n=-=-=-=-=-=- MENU -=-=-=-=-=-=-=\n");
        printf("\n1- Adicionar novo produto;");
        printf("\n2- Consultar informacoes do produto;");
        printf("\n3- Registrar venda");
        printf("\n4- Exibir relatorio do estoque");
        printf("\n5- Sair");
        printf("\n\nEscolha: ");
        scanf("%d", &choice);
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        if (choice == 5){
            break;
        }

        switch (choice)
        {
        case 1:
            printf("\nAdicionar produto");
            printf("\n-----------------");
            printf("\nNome do produto: ");
            scanf(" %[^\n]s", &produto[qnt_produtos]);
            printf("Codigo do produto: ");
            scanf(" %d", &cod[qnt_produtos]);
            printf("Preco do produto: ");
            scanf(" %f", &price[qnt_produtos]);
            printf("Quantidade do produto: ");
            scanf(" %d", &quantidade[qnt_produtos]);
            qnt_produtos++;
            break;
        case 2:
            printf("\nConsultar produto");
            printf("\n-----------------");
            int searchcod;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcod);
            for (int i=0; i<qnt_produtos; i++){
                if (cod[i] == searchcod){
                    printf("\n%s\nCodigo: %d\nPreco: R$%.2f\nEstoque: %d\n", produto[i], cod[i], price[i], quantidade[i]);
                    break;
                }
            }
            break;
        case 3:
            printf("\nRegistrar Venda");
            printf("\n-----------------");
            int searchcodsell;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcodsell);
            int qntd_vendida;
            printf("\nQuantidade do produto: ");
            scanf("%d", &qntd_vendida);
            for (int i=0; i<qnt_produtos; i++){
                if (cod[i] == searchcodsell){
                    if (quantidade[i] < qntd_vendida){
                        printf("So ha %d unidades no estoque!", quantidade[i]);
                    }
                    else{
                        quantidade[i] -= qntd_vendida;
                        printf("\nVenda realizada!\n");
                        break;
                    }
                }
            }

            break;

        case 4:
            printf("\nExibir estoque");
            printf("\n-----------------");
            for(int i=0; i<qnt_produtos; i++){
            printf("\n[%d] %s: R$%.2f (%d)", cod[i], produto[i], price[i], quantidade[i]);
            }
            break;
        
        default:
            printf("\nEscolha invalida. Redirecionando para o menu novamente...");
            break;
        }
    }
}