#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int v[n];

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    for(int i=0; i<n; i++){
        if(v[i]%2==0){
            printf("V[%d] = %d\n", i, v[i]);
        }
    }
}