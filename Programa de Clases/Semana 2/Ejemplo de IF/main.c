#include <stdio.h>
#include <stdlib.h>

//programa que me informa enbase  a la edad
//categoria de edad de una persona
//bebe 0-3
//nino 3 a 9
//-adolescente 10 a 17
//mayor de edad 18 a 40
//adulto mayor 41 a 60
// envejeciente 61 a 80
//viviendo deposito 81 a 120
//else error de edad

int main()
{
    int edad = -1;
    printf("\nIndicar su edad: ");
    scanf("%i",&edad);



    if(edad >= 0)
    {
        if(edad <= 3)
        {
            printf("\nUsted es un bebe");
        }
        else if(edad > 3 && edad <= 9)
        {
            printf("\nUsted es un nino");



        }
        else if(edad > 9 && edad <= 17)
        {
            printf("\nUsted es un adolecente");



        }
        else if(edad > 17 && edad <= 40)
        {
            printf("\nUsted es un adulto");
        }
        else if(edad > 40 && edad <= 60)
        {
            printf("\nUsted es un adulto mayor");
        }
        else if(edad > 60 && edad <= 80)
        {
            printf("\nUsted es un envejeciente");



        }
        else if(edad > 80 && edad <= 120)
        {
            printf("\nUsted esta pago");
            if(edad > 84)printf("\nUsted ha vivido mucho");
            if(edad > 94)printf("\nDebe cuidar su salud!");
            if(edad > 104)printf("\nPorque usted se puede morir en cualquier momento");





        }
        else if(edad > 120)
        {
            printf("\nEdad mayor de 120 no valida");
        }
    }
    else
    {
        printf("\nNumeros negativos no validos");
    }





    return 0;
}

