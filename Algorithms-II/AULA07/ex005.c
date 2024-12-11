#include <stdio.h>

typedef struct component{
    int x, y;
    float altura, largura;
} Component;

int onComponent(int mx, int my, Component* c){
    if((mx > c->x && mx < (c->x + c->altura)) && (my > c->y && mx < (c->y + c->largura))){
        return 1;
    } else{
        return 0;
    }
}


int main(){
    int mx, my;
    int on = 0;
    Component c;
    scanf("%d%d", &mx, &my);
    scanf("%d%d", &(c.x), &(c.y));
    scanf("%f%f", &(c.altura), &(c.largura));
    on = onComponent(mx, my, &c);
    if(on){
    printf("Sobre Componente!\n");
    }else{
    printf("Fora do Componente!\n");
}
}