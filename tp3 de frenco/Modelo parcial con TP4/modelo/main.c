#include <stdio.h>
#include <stdlib.h>
#include "Vuelo.h"


int main()
{
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    LinkedList* listaFiltrada;
    int opcion;
    int ret;

    hardcodearPilotos(listaPilotos);
    //Piloto_listar(listaPilotos);

    do
    {
        printf("\n\tMENU\n1- Cargar archivo\n2- Imprimir vuelos\n3- Cantidad de pasajeros\n4- Cantidad de pasajeros a Irlanda\n5- Filtrar vuelos cortos\n6- Listar vuelos a Portigal\n7- Filtrar a Alex Lifeson\n8- Salir\nElija opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            ret = Vuelo_cargarDeTexto(listaVuelos);
            printf("%d", ret);
            break;
        case 2:
            Vuelo_listar(listaVuelos, listaPilotos);
            break;
        case 3:
            ret = ll_count(listaVuelos, contarPasajeros);
            if(ret != -1)
            {
                printf("\nLa cantidad total de pasajeros es: %d", ret);
            }
            else
            {
                printf("\nNo se conto ningun pasajero");
            }

            break;
        case 4:
            listaFiltrada = ll_filter(listaVuelos, filtrarIrlanda);
            if(listaFiltrada != NULL)
            {
                printf("\nLa cantidad de pasajeros en vuelos a Irlanda es: %d", ll_count(listaFiltrada, contarPasajeros));
                ll_deleteLinkedList(listaFiltrada);
            }

            break;
        case 5:
            listaFiltrada = ll_filter(listaVuelos, filtrarMenos3Horas);
            if(listaFiltrada != NULL)
            {
                Vuelo_listar(listaFiltrada, listaPilotos);
                if(!Vuelo_guardar(listaFiltrada))
                {
                    printf("\nSe guardo con exito");
                }
                ll_deleteLinkedList(listaFiltrada);
            }

            break;
        case 6:
            listaFiltrada = ll_filter(listaVuelos, filtrarPortugal);
            if(listaFiltrada != NULL)
            {
                Vuelo_listar(listaFiltrada, listaPilotos);
                ll_deleteLinkedList(listaFiltrada);
            }

            break;
        case 7:
            listaFiltrada = ll_filter(listaVuelos, filtrarPiloto);
            if(listaFiltrada != NULL)
            {
                Vuelo_listar(listaFiltrada, listaPilotos);
                ll_deleteLinkedList(listaFiltrada);
            }

            break;
        }
    }
    while(opcion != 8);
    return 0;
}
