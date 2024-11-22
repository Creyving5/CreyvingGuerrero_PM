
#include <stdlib.h>  // Biblioteca funciones .
#include <string.h>  // Biblioteca de cadenas

main() // Inicia el programa
{
    char frase[100]; // Declaramos un arreglo de caracteres maximo 100.
    int key;         // Variable para almacenar la clave de cifrado.
    int i, salto=0;  // i es el del bucle. salto controla los ajustes en el cifrado.

    while(1) // Bucle infinito.
    {
        system("cls"); // Limpia la pantalla.

        printf("Ingresa la frase a cifrar: ");
        gets(frase); // Lee la frase ingresada por el usuario y la guarda en el arreglo frase.

        do {
            // Solicita al usuario la clave de cifrado.
            printf("Inserisci la chiave di cifratura: ");
            scanf("%d", &key); // Lee la clave ingresada y la almacena en key.

            // Valida que la clave este entre 1 y 10.
        } while(key < 1 || key > 10);

        // Imprime un encabezado antes de mostrar el resultado cifrado.
        printf("\n\n----------------------------------\nFrase cifrata:\n");

        // Recorre cada caracter de la frase.
        for(i = 0; i < strlen(frase); i++, salto = 0)
        {
            // Si el caracter actual supera el rango imprimible de ASCII (126). vuelve al principio
            if(frase[i] > 126 - key)
            {
                salto = 95; // Ajuste para volver al rango de caracteres imprimibles (32-126).
            }

            // Imprime el caracter cifrado sumando la clave y restando el ajuste si es necesario.
            printf("%c", frase[i] + key - salto);
        }

        // Deja dos lineas en blanco.
        printf("\n\n");

        system("pause"); // Pausa el programa para que el usuario vea el resultado antes de continuar.
    }
}
