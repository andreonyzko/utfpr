#include <stdio.h>
#include <ctype.h>

void* achar(void *ptr, char str[62]){
    int i= *(int *)ptr;
    for(i=i; str[i] != '\0'; i++){
        if(tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u'){
            return &str[i];
        }
    }
    return &str[i-1];
}

int main(){
    int n = 7;
    void* p = &n;
    char frase[62] = "ALGORITMOS";
    p = achar(p, frase);
    printf("%c", *(char*) p);
}