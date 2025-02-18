#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void Gravar_Itens(void);
void Ler_Lista(void);
void Limpar_Lista(void);


int main() {  
	int opcao;
	do {
        printf("-----------------------------\n");
		printf("MENU:\n");
    	printf("1 - Gravar itens de compra\n");
    	printf("2 - Ler lista de compras\n");
    	printf("3 - Limpar a lista de compras\n");
    	printf("0 - Encerrar o Programa\n");
    	printf("\n");
    	printf("Informe a opcao desejada: ");
    	do {
      		scanf("%d", &opcao);
      		if((opcao < 0) || (opcao > 3))
      			printf("Opcao invalida! Tente novamente.\n");
    	} while ((opcao < 0) || (opcao > 3));

        printf("-----------------------------\n");
    
    		switch (opcao) {
				case 1: Gravar_Itens(); break;
      			case 2: Ler_Lista(); break;
      			case 3: Limpar_Lista(); break;
    		}
  	} while (opcao != 0);
}

void Gravar_Itens(void) {
	FILE *arq = fopen("lista_compras.bin", "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    char item[100];
    printf("Digite o item a ser adicionado: ");
    scanf(" %[^\n]s", item);
    fwrite(item, sizeof(char), strlen(item) + 1, arq);
    fclose(arq);
    printf("Item gravado com sucesso!\n");
}

void Ler_Lista(void) {
    FILE *arq = fopen("lista_compras.bin", "rb");
    if (!arq) {
        printf("Lista vazia ou erro ao abrir o arquivo!\n");
        return;
    }
    char item[100];
    printf("Lista de Compras:\n");
    while (fread(item, sizeof(char), sizeof(item), arq)) printf("- %s\n", item);
    fclose(arq);
    printf("\n");
}


void Limpar_Lista(void){
	FILE *arq = fopen("lista_compras.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao limpar a lista!\n");
        return;
    }
    fclose(arq);
    printf("Lista de compras apagada com sucesso!\n");
}
