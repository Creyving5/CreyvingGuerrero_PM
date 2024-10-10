#include <stdio.h>

/* Superficie del triangulo.
El programa, al recibir como datos la base y la altura de un triangulo, calcula su superficie.
Bas, ALT y SUP: variable de tipo real. */

void main(void)
{
    float BAS, ALT, SUP;
    printf("Ingrese la base y la altura del triangulo: ");
    scanf("%f %f", &BAS, &ALT);
    SUP = BAS * ALT / 2;
    printf("\nLs superficie del triangulo es : %5.2f", SUP);

}
