#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int array[], int start, int middle, int end) {
    int size = end - start + 1;
    int arrayAux[size];
    int index= 0;

    int p1 = start;
    int p2 = middle+1;

    while(p1 <= middle && p2 <= end){
        int menor = p1;
        if(array[p2] < array[p1]) menor = p2;
        arrayAux[index] = array[menor];
        index++;

        if(menor == p1) p1++;
        else p2++;
    }

    if(p1 > middle){
        while(p2 <= end){
            arrayAux[index] = array[p2];
            index++;
            p2++;
        }
    }

    else{
        while(p1 <= middle){
            arrayAux[index] = array[p1];
            index++;
            p1++;
        }
    }

    for(int i = 0; i < size; i++){
        array[start + i] = arrayAux[i];
    }
}

void mergeSort(int array[], int start, int end){

    if(start >= end) return;

    int middle = (start + end)/2;

    // vetor esquerda
    mergeSort(array, start, middle);

    // vetor da direita
    mergeSort(array, middle+1, end);
    merge(array, start, middle, end);
}

int main(){
    int array[] = {23, 4, 67, -8, 90, 54, 21};

    mergeSort(array, 0, 6);

    for(int i=0; i<=6; i++){
        printf("%d ", array[i]);
    }
}