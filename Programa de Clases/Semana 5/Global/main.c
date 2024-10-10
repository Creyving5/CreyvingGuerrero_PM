#include <stdio.h>
#include <stdlib.h>

int a = 199;

void printa (void);
void printaglobal (void);

int main ()
{
    int a = 10;
    printf ("Valor de a: %i\n", a);

    printa ();
    printaglobal ();
    return 0;
}

void printa (void)
{
    int a = 1024;
    printf ("Valor de a: %i\n", a);
}

void printaglobal (void)
{
    printf ("Valor de a: %i\n", a);
}
