#include <stdio.h>

int main(){
    int n, i=0;
    scanf("%d", &n);

    int v[n];
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    
    char s[60];
    scanf(" %[^\n]s", s);

    for(i=0;i<n;i++){
        char letra = s[v[i]];
        printf("%c", letra);
    }
}