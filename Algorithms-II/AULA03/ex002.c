#include <stdio.h>

void printMatriz(int l, int c, int matriz[l][c]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int processaMatriz(int l, int c, int x, int matriz[l][c]){
    int alt=0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[i][j] > x){
                matriz[i][j]= 0;
                alt++;
            }
        }
    }

    return alt;
}

int main(){
    int x, alteracoes=0;
	int matriz[3][3];
	scanf("%d",&x);
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
    
    alteracoes = processaMatriz(3, 3, x, matriz);
    printMatriz(3, 3, matriz);
    printf("Alteracoes=%d", alteracoes);
}