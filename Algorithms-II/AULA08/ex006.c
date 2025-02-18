#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char descr[31];
    char tipo[10]; // Debito ou Credito
    float vlr;
}rgDados;

rgDados *lerLancamentos(FILE *arq, int tam) {
    rgDados buffer;
    rgDados *vetor = (rgDados *) calloc(tam, sizeof(rgDados));
    for(int i=0; i<tam; i++){
        fread(&buffer, sizeof(rgDados), 1, arq);
        printf("%s R$ %.2f %c\n", buffer.descr, buffer.vlr, buffer.tipo[0]);
        vetor[i] = buffer;
    }

    return vetor;
}

void mostrarLancamentos(rgDados lanctos[], int tam) {
    float debitos=0, creditos=0, saldo=0;
    for(int i=0; i<tam; i++){
        if(lanctos[i].tipo[0] == 'C'){
            creditos += lanctos[i].vlr;
        }
        else if(lanctos[i].tipo[0] == 'D'){
            debitos += lanctos[i].vlr;
        }
    }

    char resultado;
    if (creditos > debitos){
        saldo = creditos - debitos;
        resultado = 'C';
    }
    else{
        saldo = debitos-creditos;
        resultado = 'D';
    }

    printf("\nCreditos = R$ %.2f\n", creditos);
    printf("Debitos  = R$ %.2f\n", debitos);
    printf("Saldo    = R$ %.2f %c\n", saldo, resultado);
}

int main(){
	int tam= 4;
  	FILE *arq;
  	arq = fopen("lanctos.bin", "a+b");
  	rgDados lanc;

    // 1o. lançamento
  	strcpy(lanc.descr, "Salario");
  	strcpy(lanc.tipo, "Credito");
  	lanc.vlr = 2000.50; 
    fwrite(&lanc, sizeof(rgDados), 1,arq);

    // 2o. lançamento
  	strcpy(lanc.descr, "Supermercado");
  	strcpy(lanc.tipo, "Debito");
  	lanc.vlr = 250.44; 
    fwrite(&lanc, sizeof(rgDados), 1,arq);

    // 3o. lançamento
  	strcpy(lanc.descr, "Gasolina");
  	strcpy(lanc.tipo, "Debito");
  	lanc.vlr = 371.33; 
  	fwrite(&lanc, sizeof(rgDados), 1,arq);

    // 4o. lançamento
  	strcpy(lanc.descr, "Aluguel");
  	strcpy(lanc.tipo, "Debito");
  	lanc.vlr = 1400.00; 
  	fwrite(&lanc, sizeof(rgDados), 1,arq); 

  	rewind(arq);

  	rgDados *lanctos;
  	lanctos = lerLancamentos(arq, tam);
  	mostrarLancamentos(lanctos, tam);
  	fclose(arq);
}