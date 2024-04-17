#include <stdio.h>

int main(){
    int h2o;
    float tarifah2o, tarifaesg, tributosf, h2oesg, total;

    scanf("%d %f %f %f", &h2o, &tarifah2o, &tarifaesg, &tributosf);

    tarifah2o = h2o*tarifah2o;
    tarifaesg= tarifah2o*tarifaesg/100;
    h2oesg = tarifah2o+tarifaesg;
    tributosf = h2oesg*tributosf/100;
    total= h2oesg+tributosf;

    printf("Total Agua: %.2f\nTotal Esgoto: %.2f\nTotal: %.2f\nTributos Federais: %.2f\nVALOR DA FATURA: %.2f", tarifah2o, tarifaesg, h2oesg, tributosf, total);
}