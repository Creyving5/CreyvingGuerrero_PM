#include <stdio.h>

int main ()
{
    int a = 5;
    int b = 10;
    int *p;

    p = &a;
    printf ("\nValor de a: %i", *p);
    //printf ("\nValor de p: %p", p);

    p = &b;
    printf ("\nValor de b: %i", *p);
    //printf ("\nValor de p: %p", p);

    return 0;
}
