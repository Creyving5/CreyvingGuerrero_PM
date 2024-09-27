#include <stdio.h>
#include <stdlib.h>

/* Numeros perffectos.
El programa, al recibir como dato un numero entero positivos como limite, obtiene los numeros perfectos que hay entre 1 y ese numero, y ademas imprime cuantos numeros perfectos hay en el intervalo.

I, J, NUM, SUM , C: variables de tipo entero. */

void main(void)
{
 int I, J, NUM, SUM, C = 0;
 printf("\nIngrese el numero limite: ");
 scanf("%d", &NUM);
 for (I = 1; I <= NUM; I++) // revisa cada numero hasta 1
 {
     SUM = 0;
     for (J = 1; J <= (I / 2); J++) //  para encontar I
        if ((I % J) == 0)
        SUM += J;
     if (SUM == I) // Si los divisores son iguales a I es un numero perfecto
     {
         printf("\n%d es un numero perfecto", I);
         C++;
     }
 }
 printf("\nEntre 1 y %d hay %d numeros perfectos", NUM, C);



}
