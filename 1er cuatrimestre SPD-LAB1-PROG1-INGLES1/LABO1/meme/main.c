#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[30];
    char apellido[30];
    int i;
    char apellidoYNombre[60]="";
    int largo;
    printf("ingrese su nombre: ");
    fgets(nombre, 30, stdin);
    printf("ingrese su apellido: ");
    fgets(apellido, 30, stdin);
    strcat(apellidoYNombre,apellido);
    strcat(apellidoYNombre,", ");
    strcat(apellidoYNombre,nombre);

    strlwr(apellidoYNombre);
    largo=strlen(apellidoYNombre);
    apellidoYNombre[0]=toupper(apellidoYNombre[0]);

    for(i=0;i<largo;i++)
    {
        if(apellidoYNombre[i]==' ')
        {
           apellidoYNombre[i+1]= toupper(apellidoYNombre[i+1]);


        }

    }

    printf("\nsu apellido y nombre es: %s",apellidoYNombre);

    return 0;
}
