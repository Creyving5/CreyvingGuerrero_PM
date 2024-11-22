//Torres de Hanoi 2

#include <stdio.h>  // Biblioteca de entrada y salida.
#include <stdlib.h> // Biblioteca funciones.

// Declaramos la funcion moverDiscos
void moverDiscos(int n, int origen, int destino, int aux);

int main()
{
    // almacena la cantidad de discos.
    int cantDiscos;

    //  usuario ingrese la cantidad de discos.
    printf("Ingrese la cantidad de discos a utilizar: ");
    scanf("%d", &cantDiscos);

    // la cantidad de discos no sea mayor a 25.
    if (cantDiscos > 25)
    {
        // Si supera 25 marca error.
        printf("\n\nPor favor, ingrese 5 discos o menos para su correcto funcionamiento\n\n\n");
        system("PAUSE");
        return 0;
    }

    // Si el número de discos es válido, dejamos una línea en blanco para separar la salida.
    printf("\n");

    // Llamamos a la funcion moverDiscos
    // parmetros:
    // - cantDiscos (cantidad de discos).
    // - 1 como la torre origen.
    // - 2 como la torre destino.
    // - 3 como la torre auxiliar.
    moverDiscos(cantDiscos, 1, 2, 3);

    // pausa y nuevas lineas
    printf("\n\n");
    system("PAUSE");


    return 0;
}

//  funcion moverDiscos.
// Recursion.
void moverDiscos(int n, int origen, int destino, int aux)
{
    // Si hay discos por mover (n > 0).
    if (n > 0)
    {
        // los n-1 discos de la torre oringen a uxiliar usando  la torre destino.
        moverDiscos(n - 1, origen, aux, destino);

        // movemos un disco de la torre origen a la torre destino.
        printf("Muevo un disco de %d a %d\n", origen, destino);

        //  n-1 discos de la torre auxiliar a la torre destino usando la torre origen.
        moverDiscos(n - 1, aux, destino, origen);
    }
}
