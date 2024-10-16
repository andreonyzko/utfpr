#include <stdio.h>
#include <string.h>

int main(){
    char string[100];
    scanf("%[^\n]s", string);

    for(int i=strlen(string)-1; i>=0; i--){
        printf("%c", string[i]);
    }
}