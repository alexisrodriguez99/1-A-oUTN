#include <stdio.h>
#include <string.h>
#include "productos.h"

void hardCodearProducto(eProducto listado[], int tam)
{
    int id[10]={1,2,3,4,5,6,7,8,9,10};
    char nombre[10][20]={"ejemplo1","ejemplo2","ejemplo3","ejemplo4","ejemplo5","ejemplo6","ejemplo7","ejemplo8","ejemplo9","ejemplo10"};
    float precio[10]={33,10,30,5,6,70,39,42,66,71};
    int stock[10]={30,50,45,65,20,60,30,25,40,90};
    int idProveedor[10]={100,102,101,101,101,100,102,102,101,101};
    int i;
    for(i=0;i<10;i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombre,nombre[i]);
        listado[i].precio=precio[i];
        listado[i].stock=stock[i];
        listado[i].idProveedor=idProveedor[i];
    }
}
void mostrarTodosLosProductos (eProducto listado[], int tam)
{
    int i;
    for(i=0;i<10;i++)
    {


    printf("\nel ID del producto es: %d\tel nombre del producto es: %s\tel precio es: %f\tel stock es: %d\tel ID del proveedor es: %d\t",listado[i].id,listado[i].nombre,listado[i].precio,listado[i].stock,listado[i].idProveedor);
    }
}
