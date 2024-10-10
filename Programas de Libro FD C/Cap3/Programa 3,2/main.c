#include <stdio.h>
#include <stdlib.h>

/* Suma positiva.
El programa, al recibir como datos N numeros enteros, obtiene la suma de los enteros psoitivos.

I,  N, NUM, SUM: variable de tipo entero. */


void main(void)
{
    int I, N, NUM, SUM;
    SUM = 0; // pone la variable en 0.
    printf("Ingrese el numero de datos:\t ");
    scanf("%d", &N);
    for (I=1; I<=N; I++)// se repetira hasta que se cumpla y sume los positivos.
    {
        printf("Ingrese el dato numero %d:\t", I);
        scanf("%d", &NUM);
        if (NUM > 0) //aqui es si es menor que 0 se suma los dos positivos.
        SUM = SUM + NUM;
    }
    printf("\nLa suma de los numeros positivos es: %d", SUM); //digita el resultado.
}
