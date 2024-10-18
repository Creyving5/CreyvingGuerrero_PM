#include <stdio.h>
#include <stdlib.h>
#define CANT 5
//Cuenta-numeros.
//El programa, al recibir como datos  un arreglo unidimensional de tipo entero y un numero entero, determina cuantas veces se encuentra el numero en el arreglo.

void main(void)
{
    int I,NUM, CUE = 0;
    int ARRE[CANT];
    for (I=0; I< CANT; I++)                   //Declaracion del arreglo.
{
    printf("Ingrese el elemento %d del arreglo: ", I+1);
    scanf("%d", &ARRE[I]);          //Lectura - asignacion - del arreglo
}
printf("\n\nIngrese el numero que se va abuscar en el arreglo: ");
scanf("%d", &NUM);
for(I=0; I< CANT; I++)
    if(ARRE[I]== NUM)              //Comparacion del numero con los elementos del arreglo.

    CUE++;
printf("\n\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);

for(I=0; I< CANT; I++)
{
    printf("\nARRE[%i]=%i",I,ARRE[I]);
}

}




