#include <stdio.h>
#include <string.h>

int main(){
    char matriz[3][100] = {"ANDRE", "ANDREONYZ", "ANDREONYSZKO"};
    printf("%s\n", matriz[0]);
    printf("%s\n", matriz[1]);
    printf("%s\n", matriz[2]);
    printf("------------------------------");
    strcpy(matriz[1],"TES");
    printf("%s\n", matriz[0]);
    printf("%s\n", matriz[1]);
    printf("%s\n", matriz[2]);
}