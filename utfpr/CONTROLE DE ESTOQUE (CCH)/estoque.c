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
        printf("\n2- Gerenciar estoque de um produto.");
        printf("\n3- Consultar informacoes do produto.");
        printf("\n4- Registrar venda.");
        printf("\n5- Exibir relatorio do estoque.");
        printf("\n6- Sair.");
        printf("\n\nEscolha: ");
        scanf("%d", &choice);
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        if (choice == 6){ // Verifica se o usuario deseja sair do programa, entao da um break
            break;
        }

        switch (choice) // Verifica a escolha do usuario
        {
        case 1: // Escolha 1: Adicionar produto
            printf("\nAdicionar produto");
            printf("\n-------------------------------");

            printf("\nCodigo do produto: ");
            int cod_add;
            scanf(" %d", &cod_add);
            if(qnt_produtos == 0){ // Verifica se é o primeiro produto sendo cadastrado.
                cod[qnt_produtos] = cod_add;
            }
            else{ // Se nao for o primeiro produto cadastrado, verifica se o codigo inserido ja esta em uso.
                char searchreturn_add = 'F';
                for (int i=0; i<qnt_produtos; i++){ // Vare o vetor em busca do codigo similar ao informado.
                    if (cod[i] == cod_add){
                        searchreturn_add = 'T';
                        break;
                    }
                }

                if(searchreturn_add == 'T'){ // Se a ja existencia do codigo for T (True), ele exibe a mensagem de erro break.
                    printf("\nEste codigo ja foi cadastrado anteriormente.");
                    break;
                }
                else{ // Se nao houver a ja existencia do codigo, ele adiciona e continua o cadastrado.
                    cod[qnt_produtos] = cod_add;
                }
            }

            printf("Nome do produto: ");
            scanf(" %[^\n]s", &produto[qnt_produtos]);

            printf("Preco do produto: ");
            scanf(" %f", &price[qnt_produtos]);

            printf("Quantidade do produto: ");
            scanf(" %d", &quantidade[qnt_produtos]);

            printf("\nProduto adicionado com sucesso.");
            qnt_produtos++;
            break;

        case 2: // Escolha 2: Gerenciar estoque
            if(qnt_produtos == 0){ // Verifica se há produtos cadastrados.
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nGerenciar estoque");
            printf("\n-------------------------------");
            int searchcod_estoque;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcod_estoque);
            char searchreturn_estoque= 'F';
            for (int i=0; i<qnt_produtos; i++){  // Varre o vetor de codigos.
                if (cod[i] == searchcod_estoque){ // Acha o produto com o referido código.
                    searchreturn_estoque = 'T';
                    printf("Quantidade: ");
                    int qnt_add_estoque;
                    scanf("%d", &qnt_add_estoque);
                    quantidade[i] += qnt_add_estoque;
                    printf("\nEstoque de \"%s\" alterado.", produto[i]);
                    break;
                }
            }
            if(searchreturn_estoque== 'F'){ // Da mensagem de erro se nao achou nenhum produto com o codigo.
                printf("\nNenhum produto encontrado com este codigo.");
            }
            break;

        case 3: // Escolha 3: Consultar produto
            if(qnt_produtos == 0){ // Verifica se a algum produto cadastrado.
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nConsultar produto");
            printf("\n-------------------------------");

            int searchcod;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcod);
            char searchreturn_consult= 'F';
            for (int i=0; i<qnt_produtos; i++){ // Varre o vetor de codigos.
                if (cod[i] == searchcod){ // Acha o produto com o codigo informado.
                    printf("\n%s\nCodigo: %d\nPreco: R$%.2f\nEstoque: %d", produto[i], cod[i], price[i], quantidade[i]);
                    searchreturn_consult = 'T';
                    break;
                }
            }
            if(searchreturn_consult== 'F'){ // Retorna mensagem de erro se o produto nao foi encontrado.
                printf("\nNenhum produto encontrado com este codigo.");
            }
            break;

        case 4: // Escolha 4: Registrar venda
            if(qnt_produtos == 0){ // Verifica se ha algum produto cadastrado.
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nRegistrar Venda");
            printf("\n-------------------------------");

            int searchcodsell;
            printf("\nCodigo do produto: ");
            scanf("%d", &searchcodsell);
            int searchreturn_sell= 'F';
            int indiceproduto=-1;
            for(int i=0; i<qnt_produtos; i++){ // Varre o vetor de codigos.
                if(cod[i] == searchcodsell){ // Verifica a existencia o produto com o codigo informado.
                    searchreturn_sell = 'T';
                    indiceproduto= i;
                }
            }
            if(searchreturn_sell == 'F'){ // Retorna mensagem de erro se nao foi encontrado, e da break.
                printf("\nNenhum produto encontrado com este codigo.");
                break;
            }

            int qntd_vendida;
            printf("Quantidade do produto: ");
            scanf("%d", &qntd_vendida);

            if (quantidade[indiceproduto] < qntd_vendida){ // Verifica a quantidade no estoque.
                printf("\nSo ha %d unidades no estoque!", quantidade[indiceproduto]);
            }
            else{ // Faz a venda se houver a quantidade necessaria no estoque, e desconta do estoque.
                quantidade[indiceproduto] -= qntd_vendida;
                printf("\nVenda realizada!");
            }

            break;

        case 5: // Escolha 5: Exibir estoque.
            if(qnt_produtos == 0){ // Verifica se ha algum produto cadastrado.
                printf("\nNao ha produtos cadastrados ainda.");
                break;
            }

            printf("\nEstoque");
            printf("\n-------------------------------");
            for(int i=0; i<qnt_produtos; i++){ // Varre os vetores/matriz, e printa na tela.
            printf("\n[%d] %s: R$%.2f (%d)", cod[i], produto[i], price[i], quantidade[i]);
            }
            break;
        
        default: // Escolha Invalída: mensagem de erro e volta pro menu.
            printf("\nEscolha invalida. Redirecionando para o menu novamente...");
            break;
        }
    }
}