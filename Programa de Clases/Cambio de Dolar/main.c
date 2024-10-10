#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precioED = 0.0;//valor del precio en dolares
    float precioEP = 0.0;//valor del precio en pesos
    const float cambio = 60.0;//valor del precio a pagar
    float precioAP = 0.0;//valor del precio a pagar
    float impuesto = 0.0;

    printf("Calculo impuesto!\n");
    printf("\nIngrese en costo articulo en dolares:");
    scanf("%f" , &precioED);

    precioEP = precioED * cambio;

    //en informatica el 0 es falso
    //todo lo demas es verdadero

    if(precioED > 200.0)
    {
        impuesto = precioEP *0.18;
        precioAP = PrecioEP + impuesto;

        }else
    {
        precioAP = precioEP;
    }

    printf("\nCosto del articulo RD$:%f",precioEP);
    printf("\nImpuesto del articulo RD$:%f",impuesto);
    printf("Debes de pagar RD$:%f",precioAP);

    return 0;
    }
