#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int a;
    int b;
    int suma;
    printf("\nSuma de linea de comando");
    if(argc < 2 || argc > 2)
    {
        printf("\nNumero de parametros incompletos");
        printf("\nejemplo: lc1 5 6\n");
    }

    printf("\nargv[0]: %s\n", argv[0]);
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    suma = a+b;

    printf("La suma de %d mas %d es: %d", a, b, suma);

    return 0;
}
