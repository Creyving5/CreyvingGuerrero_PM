#include <stdio.h>
#include <stdlib.h>

//Cambio de caracteres de minusculas a mayusculas o de mayusculas a minusculas.

void main(void)
{
 char p1;

 printf("\nIngrese un caracter: ");
 p1=getchar();

 if(p1 > 64 && p1 <90)
 {
     p1 += 32;
     putchar(p1);
     }
     else if(p1 > 96 && p1 <= 122)
     {

                p1 -= 32;
            putchar(p1);
 }
 else
 {


    printf("\nLetra no valida");

 }
 return;


}
