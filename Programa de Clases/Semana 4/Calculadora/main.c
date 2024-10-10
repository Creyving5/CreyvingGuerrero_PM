#include <stdio.h>

#include <stdlib.h>

#define SALIR 0

#define SUM   1

#define DIV   2

#define ERR_OK 0

#define ERR_DBZ 1

int suma(int primer sumando, int segundo sumando, int);

int dividir( int numerador, int denominador, int *r);

int ERR = 0;

int main()

{

    int menu = 0;

    int num1 = 0;

    int num2 = 0;

    int r_int = 0;

    printf("Calculadora en C!\n");

    do

    {

        printf("\nSelecciona una opcion");

        printf("\n0-Salir\n1-Sumar\n2-DIV\n");

        scanf("%i",&menu);

        if(menu == SUM)

        {

            printf("\nIngresa el primer sumando:");

            scanf("%i",&num1);

            printf("\nIngresa el segundo sumando:");

            scanf("%i",&num2);

            ERR = suma(num1,num2, &r_int);
            {
                printf(" numero muy grande");

            }
            else
            {
                printf(" Resultado %i",r_int);
            }



        }

        if(menu == DIV)

        {

            printf("\nIngresa el numerado:");

            scanf("%i",&num1);

            printf("\nIngresa el denominador:");

            scanf("%i",&num2);

            ERR = dividir(num1,num2,&r_int);

            if(ERR)

            {

                printf("\nDivision por zero no valida");

            }

            else

            {

                printf("\nResultado= %i",r_int);

            }

        }

    }

    while(menu != SALIR);

    return 0;

}

int suma(int a,int b)

{

    int temp = 0;

    temp = a+b;

    return temp;

}

int dividir( int numerador, int denominador, int *r)

{

    if(denominador != 0)

    {

        *r = numerador / denominador;

        return ERR_OK;

    }

    else

    {

        return ERR_DBZ;

    }

}


