#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int campo1;
    char campo2;
    float campo3;
}Estructura;

Estructura* newEstructura();
Estructura* newEstructuraParametrizada(int campo1, char campo2, float campo3);
void mostrar(Estructura* miEstructura);

int escribirEnArchivo();
int leerArchivo();

int main()
{
    Estructura* miEstructura = newEstructuraParametrizada(15, 'A', 10.5);

    mostrar(miEstructura);

    escribirEnArchivo();
    leerArchivo();

    return 0;
}
Estructura* newEstructura()
{
    return (Estructura*) malloc(sizeof(Estructura));
}
Estructura* newEstructuraParametrizada(int campo1, char campo2, float campo3)
{
    Estructura* aux = newEstructura();

    aux->campo1 = campo1;
    aux->campo2 = campo2;
    aux->campo3 = campo3;

    return aux;
}
void mostrar(Estructura* miEstructura)
{
    printf("\n%d - %c - %f", miEstructura->campo1, miEstructura->campo2, miEstructura->campo3);
}

int escribirEnArchivo()
{
    int retorno = -1;
    FILE* pArchivo;

    char nombre[50];
    char apellido[50];

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(apellido);

    pArchivo = fopen("Archivo.txt", "w");

    if(pArchivo != NULL)
    {
        retorno = 0;
        fprintf(pArchivo, "%s\n%s\n", nombre, apellido);
    }

    fclose(pArchivo);

    return retorno;
}
int leerArchivo()
{
    int retorno = -1;
    FILE* pArchivo;

    char nombre[50];
    char apellido[50];

    pArchivo = fopen("Archivo.txt", "r");

    if(pArchivo != NULL)
    {
        retorno = 0;
        fscanf(pArchivo,"%[^\n]\n%[^\n]", nombre, apellido);
        printf("\n%s\n%s", nombre, apellido);
    }

    fclose(pArchivo);


    return retorno;
}


La memoria se divide en diferentes segmentos, uno de estos segmentos es el stack, donde se
guardan o apilan las llamadas a funciones y variables locales, otro segmento es el heap,
que se usa cuando queremos almacenar espacios de memoria dinamica, permitiendo que,
 variables declaradas
como punteros (que guarden direcciones de memoria) en el stack apunten a
espacios de memoria dinamica en el heap

