#include <stdio.h>
#include <stdlib.h>

/* Nomina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la nomina de la universidad.

I: variable de tipo entero.
SAL y NOM: varaible de tipo real. */

void main(void)
{
    int I;
    float SAL, NOM;
    NOM = 0;// ponme el valor en 0.
    for (I=1; I<=15; I++) //pone el valor I en 0.  Es la funcion que designa el numero de profesores y suma el numero .
    {
        printf("\Ingrese el salario del profesor:\t", I);
        scanf("%f", &SAL); //   para poder poner caracteres.
        NOM = NOM + SAL; // suma sal al total de nom.

    }
    printf("\nEl total de la nonima es: %.2f", NOM); //imprimir eso con el caracter.
}
