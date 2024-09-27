#include <stdio.h>
#include <stdlib.h>

/* Nomina de profesores.
El programa, al recibir como datos los salarios de los profesores de una universidad, obtiene la nomina y el promedio de los salarios.

I: variable de tipo entero.
SAL, NOM y PRO: variable de tipo real. */

void main(void)
{
    int I = 0;
    float SAL, PRO, NOM = 0;
    printf("Ingrese el salario del profesor:\t");
    /* Observa que al menos necesita ingresar el salario de un  profesor para que no ocurra un error de ejecuccion del programa. */
    //0 para qe termine de ejecutarse despues del primero.
    scanf("%f", &SAL);
    do
    {
        NOM = NOM +SAL;
        I = I + 1;
        printf("Ingrese el salario del profesor -0 para terminar - :\t");
        scanf("%f", &SAL);
        //suma

    }
    while (SAL);
    PRO = NOM / I;
    printf("\nNomina: %.2f \t Promedio de salarios: %.2f", NOM, PRO);
// division y resultado
}
