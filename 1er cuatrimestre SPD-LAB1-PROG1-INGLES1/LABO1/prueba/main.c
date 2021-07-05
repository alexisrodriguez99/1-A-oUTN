#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTOS 4
typedef struct
{
    int numero[ELEMENTOS];
    float numero2[ELEMENTOS];
    char nombre[ELEMENTOS];
}eEstructura
void ordenamiento(char char1);
void mostrar();
int main()
{



    printf("\n\nLista ordenada por nombres");

    return 0;
}
void ordenamiento(char char1)
{   int i,j;
    char auxiliar[10];
    for(i=0; i< ELEMENTOS-1; i++)
    {
        for(j=i+1; j<ELEMENTOS; j++)
        {
            if(strcmp(nombre[i],nombre[j])>0)
            {
                strcpy(auxiliar,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j], auxiliar);

                strcpy(auxiliar,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j], auxiliar);
            }
        }
    }
}
void mostrar()
{
    for(i=0; i<ELEMENTOS; i++)
    {
        printf("\nla cadena es: %s ",nombre[i]);
    }
}

