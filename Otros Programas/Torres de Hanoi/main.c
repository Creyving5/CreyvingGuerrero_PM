//Programa torres de Hanoi
/*

Se debe ofrecer la solución que da el programa a este problema paso a paso, mostrando el resultado de una forma gráfica. El inicio podría ser algo así:

     *

    ***

   *****

  *******

 *********

    ===========		==========		==========

O				A				D


Formula para calcular movimientos mínimos necesarios:

m = 2^n -1

*/

#include <string.h> // Biblioteca.
#include <stdio.h>  // Biblioteca para entrada y salida.
#include <stdlib.h> // Biblioteca para funciones.

void imprime( int *tab, int fil, int col, int ultNum )
{
    // Recibe un puntero a la matriz numero de filas, columnas y el valor del disco mas grande.

    int f, c;     // Variables para filas y columnas.
    int i, esp;   // Variables para bucle y los espacios.

    for( c=col-1; c >= 0; c-- )  // Recorre las columnas de derecha a izquierda.
    {
        for( f=0; f < fil; f++ ) // Recorre cada fila.
        {
            esp = ( ultNum - tab[col*f+c] )/2; // Calcula espacios a la izquierda del disco.

            for( i=0; i < esp; i++ ) // Imprime espacios a la izquierda.
                printf( " " );

            for( i=0; i < tab[col*f+c]; i++ ) // Imprime el disco.
                printf( "*" );

            for( i=0; i < esp; i++ ) // Imprime espacios a la derecha.
                printf( " " );

            printf( "\t" ); // Agrega un tabulador horizontal a columnas.
        };
        printf( "\n" ); // Salto de linea al finalizar una fila.
    };
};

void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
    int cO=col-1, cD=col-1; // Variables para buscar posiciones en las filas origen y destino.

    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 ) // Busca el disco mas pequeno en la fila origen.
        cO--;

    if( cO < 0 ) cO = 0; // Si no encuentra discos 0.

    while( cD >= 0  &&  tab[col*filDest+cD] == 0 ) // Busca la posicin mas alta en la fila destino.
        cD--;

    tab[col*filDest+cD+1] = tab[col*filOrig+cO]; // Mueve el disco de origen a destino.
    tab[col*filOrig+cO] = 0;                     // Elimina el disco de la posicion original.

    imprime( tab, fil, col, ultNum ); // actualizacion.
};

void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
    if( disc==1 ) // si queda un disco se mueve.
    {
        system("cls"); // Limpia la pantalla.
        mueveDisco( tab, fil, col, ultNum, O, D ); // Mueve el disco.

        if(col<=5) delay(4);   // Ajusta la pausa segun el numero de discos.
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
    }
    else // descompone el problema en pasos mas pequenos.
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A ); // Mueve discos a la torre auxiliar.
        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );       // Mueve el disco mas grande al destino.
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
        hanoi( tab, fil, col, disc-1, ultNum, A, O, D ); // Mueve los discos restantes al destino.
    };
};

void delay(int tiempo)
{
    int c, d; // Variables auxiliares.

    while(tiempo >= 0) // Cuenta regresiva para simular el retraso.
    {
        for (c = 1; c <= 10000; c++) // Bucle para consumir tiempo.
            for (d = 1; d <= 10000; d++)
                {}
        tiempo--;
    }
}

main()
{
    int fil=3, col, *tablero = NULL; // Inicializa variables filas, columnas y puntero al tablero.
    int f, c, disc=1, ultNum;        // Variables para el bucle y discos.

    printf( "Indique el numero de discos: " ); // Pide el numero de discos.
    scanf( "%i", &col );

    tablero = (int *)malloc( sizeof(int)*fil*col ); // Reserva memoria para el tablero.

    for( f=0; f < fil; f++ ) // Inicializa el tablero.
        for( c=col-1; c >= 0; c-- )
            if( f==0 ) // Coloca discos en la primera fila.
            {
                tablero[col*f+c] = disc;
                disc+=2; // Los discos incrementan de tamano en 2.
            }
            else
                tablero[col*f+c] = 0; // Las otras filas empiezan vacias.

    ultNum = disc; // Guarda el tamano del disco mas grande.

    system("cls"); // Limpia la pantalla.
    imprime( tablero, fil, col, ultNum ); // Imprime el tablero inicial.
    delay(6); // Pausa inicial.

    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 ); // Resuelve el problema de Hanoi.
};
