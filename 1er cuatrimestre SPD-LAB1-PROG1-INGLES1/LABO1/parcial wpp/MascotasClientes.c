#include "mascotas.h"
void mostrarMascotasConClientes(eMascota listaMascota[],int tamMascota, eCliente listaCliente[],int tamCliente)
{
    int i;
    int j;

    for(i=0;i<tamCliente;i++)
    {
        if(listaCliente[i].estado==1)
        {
           printf("CLIENTES: \n");
            printf("\n\t    NOMBRE       APELLIDO       LOCALIDAD         TELEFONO     EDAD   SEXO\n\n\t");

            mostrarUnCliente(listaCliente[i]);
            printf("\nMASCOTAS: \n");
        for(j=0;j<tamMascota;j++)
        {
            if(listaCliente[i].id==listaMascota[j].idCliente)
            {
                            mostrarSoloMascota(listaMascota[j]);


            }
        }
        }


    }
}

