#include <stdio.h>

int main(){
    int h2o;
    float tarifah2o, tarifaesg, tributosf, h2oesg, total;

    scanf("%d %f %f %f", &h2o, &tarifah2o, &tarifaesg, &tributosf);

    tarifah2o = h2o*tarifah2o;
    tarifaesg= h2o*tarifaesg/100;
    h2oesg = tarifah2o+tarifaesg;
    tributosf = h2oesg*tributosf/100;
    total= h2oesg+tributosf;

    printf("%f %f %f %f %f", tarifah2o, tarifaesg, h2oesg, tributosf, total);
}