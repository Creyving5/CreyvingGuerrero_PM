#include <stdio.h>
#include <stdlib.h>

/* Fibonacci.
El programa calcula y escribe los prinmeros 50 numeros de Fibonacci.

I, PRI, SEG, SIG: variables de tipo entero. */


void main(void)
{
    int I, PRI = 0, SEG =1, SIG;
    printf("\t  %d\t %d", PRI, SEG);
    for (I = 3; I <= 50; I++) //rango de hasta donde dara los numeros.
    {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;
        printf("\t %d", SIG);
        // suma de numero hasta los 50 digitos
    }

}
