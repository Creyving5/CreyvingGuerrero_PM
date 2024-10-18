#include <stdio.h>
#include <stdlib.h>

int main()
{
     //Cuantas veces aparece una mayucula

     char p;
     int cnt_mayusculas = 0;
     int i = 0;
     char cad[50] = "Hola Mundo Hermoso";

     for (i=0; i<50; i++)
     {
         p = cad[i];
         if(p > 64 && p<= 90)
         {
             cnt_mayusculas++;
         }


         if(p == '\0')
         {
             break;
         }
     }
     puts(cad);
     printf("\nLa de mayusculas es: %i ", cnt_mayusculas);
     return 0;
}
