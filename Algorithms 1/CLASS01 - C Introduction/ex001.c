#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int consume=0;
    double value=0, taxas=0, services=0, valueconsume= 0, total=0;
    scanf("%i", &consume);
    scanf("%lf", &value);
    scanf("%lf", &taxas);
    scanf("%lf", &services);
    valueconsume= consume*value;
    total= valueconsume+taxas+services;
    printf("Dados do faturamento:\nConsumo............:%i kWh\nTarifa (R$)........:%.3lf\nValor consumo (R$).:%.2lf\nTaxas e impostos...:%.2lf\nServicos...........:%.2lf\nTOTAL (R$).........:%.2lf", consume, value, valueconsume, taxas, services, total);
}
