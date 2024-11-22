#include <stdio.h>  // Biblioteca funciones de entrada y salida.
#include <stdlib.h> // Biblioteca funciones del sistema.
#include <string.h> // Biblioteca manipular cadenas.

main()
{
    char frase[100]; // arreglo de caracteres para almacenar máximo 99 caracteres.
    int key;         // Variable para guardar la clave de descifrado.
    int i, salto = 0; // i se utiliza como indice en los bucles. salto ajusta valores.

    while(1) // Inicia un bucle infinito para permitir multiples descifrados.
    {
        system("cls"); // Limpia la pantalla de la consola.

        printf("Ingresa la frase a decifrar: ");
        gets(frase); // Lee una linea de texto ingresada.


        do {
            // Solicita al usuario la clave de descifrado.
            printf("Inserisci la chiave di cifratura: ");
            scanf("%d", &key); // Lee la clave ingresada y la almacena en key.

            // Repite la solicitud si la clave no esta entre 1 y 10.
        } while(key < 1 || key > 10);

        // Imprime un encabezado antes de mostrar el resultado descifrado.
        printf("\n\n----------------------------------\nFrase decifrata:\n");

        // Recorre cada caracter de la frase para descifrarla.
        for(i = 0; i < strlen(frase); i++, salto = 0)
        {
            // rango imprimible menor a 32.
            if(frase[i] < 32 + key)
            {
                salto = 95; // Ajuste para que el descifrado regrese al rango de caracteres imprimibles (32-126).
            }

            // Imprime el caracter descifrado, restando la clave y sumando el ajuste si es necesario.
            printf("%c", frase[i] - key + salto);
        }

        // Imprime dos lineas en blanco
        printf("\n\n");

        system("pause"); // Pausa el programa para ver el resultado.
    }
}
