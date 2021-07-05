#include "proveedor.h"
#include <stdio.h>
#include <string.h>

void hardCodearProveedor(eProveedor listado[], int tam)
{
    int id[4]={100,101,102,103};
    char nombre[4][20]={"proveedor1","proveedor2","proveedor3","proveedor4"};
    char localidad[4][30]={"localidad1","localidad2","localidad3","localidad4"};
    int i;
    for(i=0;i<4;i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombre,nombre[i]);
       strcpy (listado[i].localidad,localidad[i]);
    }
}
void mostrarTodosLosProveedores (eProveedor listado[], int tam)
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("el ID es: %4d\tel nombre es: %4s\tla localidad es: %4s\t",listado[i].id,listado[i].nombre,listado[i].localidad);
    }
}


