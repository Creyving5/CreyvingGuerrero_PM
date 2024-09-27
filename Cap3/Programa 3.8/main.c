#include <stdio.h>
#include <stdlib.h>

/* Factorial.
El programa calcula el factorial de un numero entero.

FAC, I, NUM: variables de tipo entero. */

void main(void)
{
    int I, NUM;
    long FAC;
    printf("\nIngrese el numero: ");
    scanf("%d", &NUM);
    if (NUM >= 0) //Que sea igual o mas alto
    {
        FAC = 1;
        for (I=1; I <= NUM; I++)
            FAC *= I;
        printf("\n El factorial de %d es: %ld", NUM, FAC);
        // busca el factorial
    }
    else
        printf("\nError en el dato ingresado");
        // si es falso pondra esto
}

