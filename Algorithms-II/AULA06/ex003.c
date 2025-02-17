#include <stdio.h>
#include <stdlib.h>

int** matriz_irregular(int n, int* v){
    int** m = (int**)calloc(n, sizeof(int *));
    for(int i=0; i<n; i++){
        m[i]= (int*)calloc(v[i], sizeof(int));

        for(int j=0; j<v[i]; j++){
            m[i][j] = v[i];
        }
    }

    return m;
}

int main(){
    int **m, n;
	scanf("%d", &n);
	
	int vetor[n];
	for (int i=0; i<n; i++){
		scanf("%d", &vetor[i]);
	}
	
	m = matriz_irregular(n, vetor);
	
	for (int i=0; i<n; i++){
		for (int j=0; j<vetor[i]; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}