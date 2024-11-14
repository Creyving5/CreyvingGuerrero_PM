#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras-2.
//El programa muestra la manera en que se declara una estructura, asi como la forma en que se tiene acceso a los campos de los apuntadores de tipo estructura tanto para lectura como para escritura. Se utiliza ademas una funcion que recibe como parametro un apuntador de tipo estructura.

struct alumno                //Declaracion de alumnos.
{
    int matricula;
    char nombre[20];
    char carrera[20];               //Campos de estructura alumno.
    float promedio;
    char direccion[20];
};

void Lectura (struct alumno*);     //Prototipo de funcion.

int main()
{
   struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
   struct alumno *a3, *a4, *a5, a6, a7;
   //Observa que las variables *a3, *a4 y *a5 se declaran como apuntadores de tipo estructura alumno. a6 es una variable de tipo estructura alumno.
   a3 = &a0;    //En este caso al apuntador de tipo estructura alumno a3 se le asigna la direccion de la variable de tipo estructura alumno, a0.
   a4 = &a6 ;
   //Nota que al apuntador a4 es necesario asignarle una direccion de memoria. Para tener acceso a los campos de un apuntador de tipo estructura, utiliza uno de los dos formatos siguientes:
  //apuntador->campo
  //o bien
  //(*apuntador).campo
 //En la lectura de los campos de la variable a4 se utilizan como ejemplo ambos formatos.
 printf("\nIngrese la matricula del alumno 4: ");
 scanf("%d", &(*a4).matricula);
 fflush(stdin);
 printf("\nIngrese la matricula del alumno 4: ");
 gets(a4-> nombre);
 printf("\nIngrese la matricula del alumno 4: ");
 gets((*a4).carrera);
 printf("\nIngrese la matricula del alumno 4: ");
 scanf("%f", &a4->promedio);
 fflush(stdin);
 printf("\nIngrese la matricula del alumno 4: ");
 gets(a4->direccion);

 a5 = &a7;
 Lectura(a5);       //En este caso se pasa el apuntador de tipo estructura alumno a5 a la funcion Lectura.
 Lectura(&a6);   //En este caso se pasa la variable de tipo estructura alumno a6, a la funcion Lectura. Observa que en este caso debemos utilizar el operador de direccion para preceder a la variable.
 printf("\nDatos del alumno 3\n");
 //Observa la forma de escribir los campos de los apuntadores de tipo estructura.
 printf("%d\t%s\t%s\t%.2f\t%s", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);

 printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);

 printf("%d\t%s\t%s\t%.2f\t%s", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);

 //Observa la forma de escribir los campos de la variable tipo estructura.
 printf("%d\t%s\t%s\t%.2f\t%s", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);
}

void Lectura(struct alumno *a)
//Esta funcion permite leer los campos de un apuntador de tipo estructura alumno.
{
    printf("\nIngrese la matricula del alumno: ");
    scanf("%d", &(*a).matricula);
    fflush(stdin);
    printf("\nIngrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);
    printf("\nIngrese la carrera del alumno: ");
    gets((*a).carrera);
    printf("\nIngrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    fflush(stdin);
    printf("\nIngrese la direccion del alumno: ");
    gets(a->direccion);
}

