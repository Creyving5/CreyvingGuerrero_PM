#include <stdio.h>
#include <stdlib.h>

//Paso de una funcion como parametro por referencia.

int Suma(int X, int Y)
//La funcion Suma regresa la suma de los parametros de tipo entero X y Y.
{
    return (X+Y);
}

int Resta(int X, int Y)
//Esta funcion regresa la resta de los parametros de tipo entero X y Y.
{
    return (X-Y);
}

int Contol(int (*apf)(int,int),int X,int Y)
// Esta funcion recibe como parametro otra funcion _la direccion_ y dependiendo de cual sea esta, llama a la funcion Suma o Resta.
{
    int RES;
    RES = (*apf) (X, Y);      //Se llama a la funcion Suma o Resta.
    return (RES);
}

void main(void)
{
    int R1, R2;
    R1 = Contol(Suma, 15, 5); //Se pasa parametro la funcion Suma.
    R2 = Contol(Resta, 10, 4);  //Se pasa parametro la funcion Resta.
    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2 : %d", R2);

}
