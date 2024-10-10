#include <stdio.h>
#include <stdlib.h>

int main ()

{
    float x = 0.0;
    float b = 0.0;
    int cont = 0;
    printf ("Calculo de Raiz Cuadrada\n");
    scanf("%f", &x);
    b = x;

    while (! (b==(x/b)))
    {
        cont++;
        b = 0.5 * ((x/b) + b);
        printf ("\nValor de b[%i]=%f", cont,b);
    }

    printf ("\nRaiz Cuadrada de %f es: %f", x,b);
    return 0;
}
