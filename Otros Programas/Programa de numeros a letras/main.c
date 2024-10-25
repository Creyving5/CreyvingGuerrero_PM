#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Programa para cambiar numero a palabras.

char *unidades[] = { "", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
char *excepciones[] = { "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve" };
char *decenas[] = { "", "", "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
char *centenas[] = { "", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos" };


// Esta función convierte un número en palabras.
void convertirNumero(int numero, char* resultado) {
    char temp[100];

    if (numero == 0) {
        strcpy(resultado, "cero");
        return;
    }

    if (numero == 100) {
        strcpy(resultado, "cien");
        return;
    }


    if (numero == 1000) {
        strcpy(resultado, "mil");
        return;
    }


    if (numero < 10) {
        strcpy(resultado, unidades[numero]);
        return;
    }


    if (numero < 20) {
        strcpy(resultado, excepciones[numero - 10]);
        return;
    }


    if (numero < 100) {
        if (numero < 30) {

            strcpy(resultado, decenas[numero / 10]);
            strcat(resultado, unidades[numero % 10]);
        } else {

            strcpy(resultado, decenas[numero / 10]);
            if (numero % 10 != 0) {
                strcat(resultado, " y ");
                strcat(resultado, unidades[numero % 10]);
            }
        }
        return;
    }


    if (numero < 1000) {
        strcpy(resultado, centenas[numero / 100]);
        if (numero % 100 != 0) {
            strcat(resultado, " ");
            convertirNumero(numero % 100, temp);
            strcat(resultado, temp);
        }
        return;
    }


    if (numero < 10000) {
        if (numero / 1000 == 1) {
            strcpy(resultado, "mil");
        } else {
            convertirNumero(numero / 1000, resultado);
            strcat(resultado, " mil");
        }
        if (numero % 1000 != 0) {
            strcat(resultado, " ");
            convertirNumero(numero % 1000, temp);
            strcat(resultado, temp);
        }
        return;
    }
}

int main() {
    int opcion;
    double numero;
    char resultado[1000];
    int parteEntera, parteDecimal;


    do {

        printf("\nMenu:\n");
        printf("1. Convertir numero a letras\n");
        printf("2. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);


        switch (opcion) {
            case 1:
                printf("\nIngrese un numero entre 0 y 9999.99: ");
                scanf("%lf", &numero);


                if (numero > 9999) {
                    printf("El numero excede el limite de 9999. Intente de nuevo.\n");
                    break;
                }


                parteEntera = (int)numero;
                parteDecimal = round((numero - parteEntera) * 100);


                convertirNumero(parteEntera, resultado);
                resultado[0] = toupper(resultado[0]);


                printf("\nEl numero en palabras es: %s", resultado);
                if (parteDecimal > 0) {
                    printf(" con %d centavos", parteDecimal);
                }
                printf("\n");
                break;

            case 2:
                printf("Saliendo...\n");
                break;

            default:
                printf("Error!!! Numero invalido.\n");
        }


    } while (opcion != 2);

    return 0;
}
