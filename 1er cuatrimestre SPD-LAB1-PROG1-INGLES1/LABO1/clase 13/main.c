#include <stdio.h>
#include <stdlib.h>
#include "productos.h"
#include "proveedor.h"
#define TPRODUCTO 10
#define TPROVEEDOR 4

int main()
{
    eProducto listadoDeProdectos[TPRODUCTO];
    eProveedor  listadoDeProveedor[TPROVEEDOR];

    hardCodearProducto(listadoDeProdectos,TPRODUCTO);
    hardCodearProveedor(listadoDeProdectos,TPROVEEDOR);
    mostrarTodosLosProductos (listadoDeProdectos,TPRODUCTO);

}
