#include <stdio.h>

void main(void)
{
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    float CAL = 0.0;


    printf("Ingresa la Calificacion del Alumno: ");
    scanf("%f", &CAL);
    while (CAL != -1)
    {
        if(CAL >= 0)
        {
            if (CAL < 4)
                R1++;
            else if (CAL < 6)
                R2++;
            else if (CAL < 8)
                R3++;
            else if (CAL < 9)
                R4++;
            else if (CAL <= 10)
                R5++;
            else
                printf("\nN�meros No V�lidos");

        }

        printf("\nIngresa la Calificaci�n del Alumno: ");
        scanf("%f", &CAL);

    }


    printf("\n0..3.99 = %d", R1);
    printf("\n4..5.99 = %d", R2);
    printf("\n6..7.99 = %d", R3);
    printf("\n8..8.99 = %d", R4);
    printf("\n9..10 = %d", R5);

}