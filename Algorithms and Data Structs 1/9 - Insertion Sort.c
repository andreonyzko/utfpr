#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int array[], int size){
    for(int i=1; i < size; i++){
        int temp = array[i];
        int j;

        for(j = i-1; j >= 0 && array[j] > temp; j--) array[j+1] = array[j];

        array[j+1] = temp;
    }
}

int main(){
    int array[] = {23, 4, 67, -8, 90, 54, 21};
    int size = 7;

    insertionSort(array, size);

    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
}