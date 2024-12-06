//Bibliotecas de Codeblocks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicion de la estructura Alumno.

typedef struct {
    char nombre[50];  // Cadena para guardar el nombre del alumno.
    float promedio;   // Numero flotante para guardar el promedio del alumno.
    char carrera[50]; // Cadena para guardar la carrera del alumno.
} Alumno;

// Declaracion de funciones.

void nuevoArchivo(FILE **archivo, char *nombreArchivo);      // Crea un nuevo archivo.
void abrirConNombre(FILE **archivo, char *nombreArchivo);   // Abre un archivo existente.
void guardarConNombre(FILE **archivo, char *nombreArchivo); // Guarda el archivo con un nombre.
void buscarEnArchivo(FILE *archivo); // Busca informacion en el archivo.
void agregarRegistro(FILE *archivo); // Agrega un registro de alumno al archivo.

int main() {

    FILE *archivo = NULL; // Puntero para el archivo.
    int opcion; // Variable para guardar la opcion del menu seleccionada por el usuario.
    char nombreArchivo[50] = "Archivo.txt"; // Nombre predeterminado del archivo.

    //Bucle del menu para elejir.
    while (1) {
        printf("\nMenu\n");
        printf("1. Nuevo Archivo\n");
        printf("2. Abrir con nombre\n");
        printf("3. Guardar con nombre\n");
        printf("4. Agregar registro\n");
        printf("5. Buscar\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); //Analiza las opciones entradas.
        getchar(); // Limpia el buffer

        // Selecciona una accion segun la opcion del usuario.
        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del nuevo archivo (terminado en .txt): ");
                fgets(nombreArchivo, sizeof(nombreArchivo), stdin); // Lee el nombre del archivo.
                nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0'; // Eliminar salto de linea
                nuevoArchivo(&archivo, nombreArchivo); //Llama a la funcion para crear el archivo.
                break;
            case 2:
                printf("Ingrese el nombre del archivo a abrir: "); //Abre un archivo existente
                fgets(nombreArchivo, sizeof(nombreArchivo), stdin);
                nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0';
                abrirConNombre(&archivo, nombreArchivo);
                break;
            case 3:
                printf("Ingrese el nombre del archivo para guardar: ");  //Guarda el archivo con un nuevo nombre
                fgets(nombreArchivo, sizeof(nombreArchivo), stdin);
                nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0';
                guardarConNombre(&archivo, nombreArchivo);
                break;
            case 4:
                agregarRegistro(archivo); // Llama a la funcion que agrega un nuevo alumno.
                break;
            case 5:
                buscarEnArchivo(archivo); // Busca un registro en el archivo.
                break;
            case 6:                     //Sale del programa
                if (archivo != NULL) {
                    fclose(archivo);
                }
                printf("Programa finalizado.\n");
                return 0;
            default:       //Opcion invalida
                printf("Opcion no valida.\n");
        }
    }
}

// Funcion para crear un nuevo archivo
void nuevoArchivo(FILE **archivo, char *nombreArchivo) {
    if (*archivo != NULL) {
        fclose(*archivo); // Cierra el archivo actual si esta abierto.
    }
    *archivo = fopen(nombreArchivo, "w+");  // Crea un archivo nuevo para lectura/escritura.
    if (*archivo == NULL) {
        printf("Error al crear el archivo.\n"); // Si hay error no funciona.
    } else {
        printf("Archivo '%s' creado exitosamente.\n", nombreArchivo);
    }
}

// Funcion para abrir un archivo existente
void abrirConNombre(FILE **archivo, char *nombreArchivo) {
    if (*archivo != NULL) {
        fclose(*archivo);
    }
    *archivo = fopen(nombreArchivo, "r+");
    if (*archivo == NULL) {
        printf("No se pudo abrir el archivo '%s'.\n", nombreArchivo);
    } else {
        printf("Archivo '%s' abierto correctamente.\n", nombreArchivo);
    }
}

// Funcion para guardar el archivo
void guardarConNombre(FILE **archivo, char *nombreArchivo) {
    if (*archivo == NULL) {
        printf("No hay archivo abierto para guardar.\n");
        return;
    }
    fclose(*archivo);
    *archivo = fopen(nombreArchivo, "a+"); // Abre el archivo para guardar datos.
    if (*archivo != NULL) {
        printf("Archivo guardado como '%s'.\n", nombreArchivo);
    } else {
        printf("Error al guardar el archivo.\n");
    }
}

// Funcion para agregar un nuevo registro al archivo
void agregarRegistro(FILE *archivo) {
    if (archivo == NULL) {
        printf("No hay un archivo abierto para agregar registros.\n");
        return;
    }

    Alumno nuevo;  // Se define un nuevo alumno.
    printf("Ingrese el nombre del alumno: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin); // Lee el nombre del alumno.
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &nuevo.promedio); // Lee el promedio del alumno.
    getchar();

    printf("Ingrese la carrera del alumno: ");
    fgets(nuevo.carrera, sizeof(nuevo.carrera), stdin);
    nuevo.carrera[strcspn(nuevo.carrera, "\n")] = '\0';

    fprintf(archivo, "%s,%.2f,%s\n", nuevo.nombre, nuevo.promedio, nuevo.carrera);  // Escribe los datos al archivo.
    printf("Registro agregado correctamente.\n");
}

// Funcion para buscar en el archivo por nombre
void buscarEnArchivo(FILE *archivo) {
    if (archivo == NULL) {
        printf("No hay un archivo abierto para buscar.\n");
        return;
    }

    char nombreBuscado[50];// Cadena para el nombre a buscar.
    char buffer[256]; // Linea leida del archivo.
    int encontrado = 0;// Si se encontro algo.

    printf("Ingrese el nombre a buscar: ");
    fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    rewind(archivo); // Regresa al inicio del archivo.
    while (fgets(buffer, sizeof(buffer), archivo)) {  // Lee linea por linea.
        if (strstr(buffer, nombreBuscado)) {   // Busca coincidencias en la linea.
            printf("Registro encontrado: %s", buffer);  // Muestra el registro encontrado.
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontro el nombre '%s' en el archivo.\n", nombreBuscado); //Si no se encuentra.
    }
}
