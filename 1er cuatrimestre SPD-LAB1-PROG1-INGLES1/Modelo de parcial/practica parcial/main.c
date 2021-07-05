#include <stdio.h>
#include <stdlib.h>
#include "ClientesMascotas.h"


int main()
{
    int idMascota = 0;
    //int idCliente = 0;
    int retornoFuncion;
    int opcionMenu;
    eCliente listaClientes[TCLIENTES];
    eMascota listaMascotas[TMASCOTAS];


    hardcodearClientes(listaClientes);
    hardcodearMascotas(listaMascotas);




    do
    {
        printf("\n---Bienvenido al menu de opciones---\n\n1- Listar Clientes\n2- Listar mascotas\n3- Listar clientes con sus mascotas\n4- Alta mascotas\n5- Baja mascotas\n6- Modificar Mascotas\n7- Ordenar\n11-Salir");
        printf("\nSingrese opcion para el menu: ");
        scanf("%d", &opcionMenu);

        switch (opcionMenu)
        {
        case 1:
            listarCliente(listaClientes, TCLIENTES);
            break;
        case 2:
            listarMascotas(listaMascotas, TMASCOTAS);
            break;
        case 3:
            mostrarClientesConMascotas(listaClientes, listaMascotas, TCLIENTES, TMASCOTAS);
            break;
        case 4:
            retornoFuncion = altaMascotas(listaMascotas, listaClientes, TMASCOTAS, TCLIENTES, &idMascota);
            if(retornoFuncion == -1)
            {
                printf("\nSe cancelo el alta");
            }
            else if(retornoFuncion == 0)
            {
                printf("\nLa lista esta llena");
            }
            else
            {
                printf("\nEl alta se realizo con exito");
            }
            break;
        case 5:
            retornoFuncion = bajaMascota(listaMascotas, TMASCOTAS);
            if(retornoFuncion == -1)
            {
                printf("\nSe cancelo la baja");
            }
            else
            {
                printf("\nLa mascota se elimino con exito");
            }
            break;
        case 6:
            retornoFuncion = modificarMascota(listaMascotas, TMASCOTAS);
            if(retornoFuncion == -1 || retornoFuncion == 1)
            {
                printf("\nSe cancelo la modificacion");
            }
            else
            {
                printf("\nLa mascota se modifico con exito");
            }
            break;
        case 7:
            ordenarClientes(listaClientes, TCLIENTES);
            ordenarMascotas(listaMascotas, TMASCOTAS);
            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        }
        printf("\n");
        system("pause");
        system("cls");

    }
    while(opcionMenu != 11);

    return 0;
}
