#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int stringint[n];
    char stringchar[n+1];

    for(int i=0; i<n; i++){
        scanf("%d", &stringint[i]);
    }
    for(int i=0; i<n; i++){
        stringchar[i] = (char)stringint[i];
    }
    stringchar[n] = '\0';
    printf("%s", stringchar);
}