#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int ejemplo1;
    char ejemplo2;
    float ejemplo3;

}Estructura;
Estructura* estructura_new();
Estructura* estructura_newParametros(int ejemplo1,char ejemplo2, float ejemplo3);
void mostrar(Estructura* estructura);


void escribirTexto();
void leerTexto();
int main()
{
    Estructura* estructura;
    estructura=estructura_newParametros(1,'d',34.2);
    mostrar(estructura);


    escribirTexto();
    leerTexto();
    return 0;
}
Estructura* estructura_new()
{
    return (Estructura*)malloc(sizeof(Estructura));
}

Estructura* estructura_newParametros(int ejemplo1,char ejemplo2, float ejemplo3)
{

    Estructura* estructura;
    estructura=estructura_new();

    estructura->ejemplo1=ejemplo1;
    estructura->ejemplo2=ejemplo2;
     estructura->ejemplo3=ejemplo3;

     return estructura;
}
void mostrar(Estructura* estructura)
{
    printf("%d,%c,%f\n",estructura->ejemplo1,estructura->ejemplo2,estructura->ejemplo3);
}

void escribirTexto()
{
    FILE* pFile;
    char nombre[50];
    char apellido[50];
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese su apellido: ");
    fflush(stdin);
    gets(apellido);

    pFile=fopen("Examen.txt","w");
    fprintf(pFile,"%s,%s\n",nombre,apellido);

    fclose(pFile);
}
void leerTexto()
{
    FILE* pfile;
    pfile=fopen("Examen.txt","r");
    char nombre[50];
    char apellido[50];

    fscanf(pfile,"%[^,],%[^\n]\n",nombre,apellido);//lee hasta la ","/*[^,]*/ excluyendo la ","/*","*/
    printf("%s %s\n",nombre,apellido);

}
