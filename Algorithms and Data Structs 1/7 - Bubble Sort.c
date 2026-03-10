#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort(int array[], int size){
    bool traded = true;

    while(traded){
        traded = false;
        for(int i=0; i < size-1; i++){
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                traded = true;
            }
        }
    }
}

int main(){
    int array[] = {23, 4, 67, -8, 90, 54, 21};
    int size = 7;


    bubblesort(array, size);

    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
}