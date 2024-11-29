/*
1.Como se estructura un archivo BMP?

Es un formato de imagen de mapa de bits que almacena datos de imagen de manera estructurada. Tiene una estructura específica que incluye varios encabezados y datos.

2.Que es el padding?

Son bytes extra que el compilador añade en estructuras para alinear los datos según las reglas del procesador, mejorando el acceso a la memoria pero aumentando el tamaño de la estructura.

3.Que son los #pragma?

Ofrecen instrucciones específicas al compilador. Estas instrucciones no afectan directamente el código fuente en términos de lógica o funcionalidad, pero controlan ciertos aspectos del comportamiento del compilador, como optimizaciones, alineación de datos o configuración de advertencias.
*/

//Este programa convierte una imagen BMP de 24 pixeles BGR y convierte cada pixel de color a un tono gris con la formula en el codigo y la guarda de nuevo en un formato BMP.

#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Para evitar padding
typedef struct {
    unsigned char  bfType[2];  // Tipo de archivo, debe ser "BM"
    unsigned int   bfSize;     // Tamaño del archivo en bytes
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;  // Offset hasta los datos de la imagen
} BITMAPFILEHEADER;

typedef struct {
    unsigned int   biSize;         // Tamaño de este encabezado
    int            biWidth;        // Ancho de la imagen
    int            biHeight;       // Alto de la imagen
    unsigned short biPlanes;       //Siempre 1 para BMP
    unsigned short biBitCount;     // Bits por píxel (debe ser 24 para este ejemplo)
    unsigned int   biCompression;   //Tipo de compresión (0 = sin compresión)
    unsigned int   biSizeImage;     //Tamaño de los datos de la imagen
    int            biXPelsPerMeter; //Resolución horizontal
    int            biYPelsPerMeter; //Resolución vertical
    unsigned int   biClrUsed;       // Número de colores usados (0 = todos)
    unsigned int   biClrImportant;  //Número de colores importantes (0 = todos)
} BITMAPINFOHEADER;
#pragma pack(pop)

// Función para convertir un píxel BGR a escala de grises
unsigned char convertirAGris(unsigned char b, unsigned char g, unsigned char r) {
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}

// Función para convertir la imagen BMP a escala de grises
void convertirBMPBlancoNegro(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "No se puede abrir el archivo %s\n", input_filename);
        return;
    }

    // Leer el encabezado del archivo BMP
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input_file);

    // Leer el encabezado de la información BMP
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input_file);

    // Verificar si es un archivo BMP de 24 bits
    if (fileHeader.bfType[0] != 'B' || fileHeader.bfType[1] != 'M' || infoHeader.biBitCount != 24) {
        fprintf(stderr, "El archivo no es un BMP de 24 bits\n");
        fclose(input_file);
        return;
    }

    // Crear el archivo de salida
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "No se puede crear el archivo %s\n", output_filename);
        fclose(input_file);
        return;
    }

    // Escribir los encabezados al archivo de salida
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, output_file);

    // Calcular el padding (relleno) de cada fila
    int padding = (4 - (infoHeader.biWidth * 3) % 4) % 4;

    // Leer, convertir y escribir cada fila de píxeles
    for (int i = 0; i < infoHeader.biHeight; i++) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            unsigned char bgr[3];  // Buffer para un píxel (B, G, R)
            fread(bgr, 3, 1, input_file);

            // Convertir el píxel a escala de grises
            unsigned char gris = convertirAGris(bgr[0], bgr[1], bgr[2]);

            // Escribir el píxel convertido en blanco y negro
            unsigned char gris_pixel[3] = {gris, gris, gris};
            fwrite(gris_pixel, 3, 1, output_file);
        }

        // Saltar el relleno (padding) en el archivo original
        fseek(input_file, padding, SEEK_CUR);

        // Añade el relleno al archivo de salida
        unsigned char padding_bytes[3] = {0, 0, 0};  // Máximo de 3 bytes de padding
        fwrite(padding_bytes, padding, 1, output_file);
    }

    // Cerrar los archivos
    fclose(input_file);
    fclose(output_file);

    printf("Imagen convertida a blanco y negro y guardada en %s\n", output_filename);
}

//Funcion principal del codigo
int main(int argc, char *argv[])
{
    const char *archivo_entrada = "avion.bmp";
    const char *archivo_salida = "avion_bn.bmp";

    convertirBMPBlancoNegro(archivo_entrada, archivo_salida);

    return 0;
}
