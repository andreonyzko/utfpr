#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selectionSort(int array[], int size){
    for(int i=0 ; i<size; i++){
        int minPos = i;
        for(int j=i; j < size; j++) if(array[j] < array[minPos]) minPos = j;

        int temp = array[i];
        array[i] = array[minPos];
        array[minPos] = temp; 
    }
}

int main(){
    int array[] = {23, 4, 67, -8, 90, 54, 21};
    int size = 7;

    selectionSort(array, size);

    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
}