#include <stdio.h>
#include <math.h>

/* Calculo de P.
El programa obtiene el valor de P aplicando una serie determinada.

I, B, C: variables de tipo entero.
RES: variable de tipo real de doble precision. */

void main(void)
{
    int I = 1, B = 0, C;
    double RES;
    RES = 4.0 / I; // primer termino
    C = 1;
    while ((fabs (3.1415 - RES)) > 0.0005)
    {
        I += 2 ;
        if (B)
        {
            RES += (double) (4.0 / I); //suma si b es 1
            B = 0;
        }
        else
        {
            RES -+ (double) (4.0 / I); // si b es 0 resta el siguiente
                    B = 1;

        }
        C++;
}

printf("\nNumero de terminos: %d", C);
// resultado

}

