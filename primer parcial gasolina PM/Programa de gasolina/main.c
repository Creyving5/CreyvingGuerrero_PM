#include <stdio.h>
#include <stdlib.h>

// 1 galon = 3.78541 litros

void main(void)
{

    float min, max, costo;
    float costo_por_km;
    float l = 3.78541;

    printf("ponga consumo minimo de l/100km: ");
    scanf("%f", &min);
    printf("Ponga consumo maximo de l/100km: ");
    scanf("%f", &max);
    printf("Ponga costo de la gasolina: ");
    scanf("%f", &costo);

    if(min >= max)
    {
       printf("No esta correcto el valor\n");
        return;
    }

    for (float consumo = min; consumo <= max; consumo++)

    {
      costo_por_km = (consumo / 100) * (costo / l);
      printf("\n--------------------------------------\n");
      printf("|Consumo: %-5.2f | costo por km: %-5.2f|",consumo,costo_por_km);
      printf("\n--------------------------------------\n");

    }
}
