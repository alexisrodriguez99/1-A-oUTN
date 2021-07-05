/*
#include "proveedoresxproducto.h"
void mostrarProveedoresXProducto(eProveedor listadoProveedor[],int cantidadProveedor, eProducto listoProducto[],int cantidadProdructo)
{
    int i;
    int j;
    int flag;
    for(i=0;i<cantidadProveedor;i++)
    {
        mostrarTodosLosProveedores(listadoProveedor[i]);
        flag=0;
        for(i=0;j<cantidadProdructo;j++)
        {
            if(listadoProveedor[i].id==listadoProducto[j].idPoveedor)
            {
                flag=1;
                mostrarTodosLosProductos(listoProducto[j]);
            }
        }
        if(flag==0)
        {
            printf("no tiene productos");
        }
    }

}
*/

