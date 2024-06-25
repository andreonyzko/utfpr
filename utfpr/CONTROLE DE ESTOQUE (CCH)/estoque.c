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
        printf("\n1- Adicionar novo produto.");
        printf("\n2- Consultar informacoes do produto.");
        printf("\n3- Registrar venda.");
        printf("\n4- Exibir relatorio do estoque.");
        printf("\n5- Sair.");
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
            printf("\n-------------------------------");

            printf("\nNome do produto: ");
            scanf(" %[^\n]s", &produto[qnt_produtos]);

            printf("Codigo do produto: ");
            int cod_add;
            scanf(" %d", &cod_add);
            if(qnt_produtos == 0){
                cod[qnt_produtos] = cod_add;
            }
            else{
                char searchreturn_add = 'F';
                for (int i=0; i<qnt_produtos; i++){
                    if (cod[i] == cod_add){
                        printf("\nEste codigo ja foi cadastrado anteriormente.");
                        searchreturn_add = 'T';
                        break;
                    }
                }

                if(searchreturn_add == 'T'){
                    searchreturn_add = 'F';
                    break;
                }
                else{
                    cod[qnt_produtos] = cod_add;
                }
            }

            printf("Preco do produto: ");
            scanf(" %f", &price[qnt_produtos]);

            printf("Quantidade do produto: ");
            scanf(" %d", &quantidade[qnt_produtos]);

            printf("\nProduto adicionado com sucesso.");
            qnt_produtos++;
            break;
        case 2:

            if(qnt_produtos == 0){
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nConsultar produto");
            printf("\n-------------------------------");

            int searchcod;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcod);
            char searchreturn_consult= 'F';
            for (int i=0; i<qnt_produtos; i++){
                if (cod[i] == searchcod){
                    printf("\n%s\nCodigo: %d\nPreco: R$%.2f\nEstoque: %d", produto[i], cod[i], price[i], quantidade[i]);
                    searchreturn_consult = 'T';
                    break;
                }
            }
            if(searchreturn_consult== 'F'){
                printf("\nNenhum produto encontrado com este codigo.");
            }

            break;

        case 3:
            if(qnt_produtos == 0){
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nRegistrar Venda");
            printf("\n-------------------------------");

            int searchcodsell;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcodsell);
            int searchreturn_sell= 'F';
            for(int i=0; i<qnt_produtos; i++){
                if(cod[i] == searchcodsell){
                    searchreturn_sell = 'T';
                }
            }
            if(searchreturn_sell == 'F'){
                printf("\nNenhum produto encontrado com este codigo.");
                break;
            }

            int qntd_vendida;
            printf("Quantidade do produto: ");
            scanf("%d", &qntd_vendida);
            for (int i=0; i<qnt_produtos; i++){
                if (cod[i] == searchcodsell){
                    if (quantidade[i] < qntd_vendida){
                        printf("So ha %d unidades no estoque!", quantidade[i]);
                    }
                    else{
                        quantidade[i] -= qntd_vendida;
                        printf("\nVenda realizada!");
                        break;
                    }
                }
            }

            break;

        case 4:
            if(qnt_produtos == 0){
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nEstoque");
            printf("\n-------------------------------");
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