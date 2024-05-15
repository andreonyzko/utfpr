#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int V[n], value;

    for(int i=0; i<n; i++){
        scanf("%d", &value);
        V[i] = value;
    }
    for(int i=0; i<n; i++){
        if(V[i] % 2 ==0)
            printf("V[%d] = %d\n", i, V[i]);
    }
}