#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
int main()
{
    int opcion;
    char nombre[50];
    LinkedList* pArrayListVuelo;
    LinkedList* pArrayListPiloto;
    LinkedList* listaFiltrada;
    pArrayListVuelo=ll_newLinkedList();
    pArrayListPiloto=ll_newLinkedList();
    listaFiltrada=ll_newLinkedList();
    hardCodearPiloto(pArrayListPiloto);

      do
    {
        printf("1. Cargar archivo:\n");
        printf("2. Imprimir vuelos:\n");
        printf("3. Cantidad de pasajeros:\n");
        printf("4. Cantidad de pasajeros a Irlanda:\n");
        printf("5. Filtrar vuelos cortos:\n");
        printf("6. Listar vuelos a Portugal:\n");
        printf("7. Filtrar a Alex Lifeson:\n");

        printf("8. Salir\n");

        scanf("%d",&opcion);



        system("cls");
        switch(opcion)
        {
            case 1:
            {
                printf("Ingrese el nombre del archivo(el unico que existe es Vuelos.csv):\n");
                fflush(stdin);
                gets(nombre);
                if(strcmp(nombre,"Vuelos.csv")==0)
                {controller_Rodriguez_loadFromTextPiloto("Pilotos.csv",pArrayListPiloto);
                   if(controller_Rodriguez_loadFromText(nombre,pArrayListVuelo)==1)
                   {
                       printf("Se cargo correctamente\n");
                   }
                   else
                   {
                       printf("Uppss error a cargar la lista");
                   }
                }
                else
                {
                    printf("Error al ingresar el archivo");
                }
                break;
            }
            case 2:
            {
                controller_Rodriguez_loadFromText(pArrayListVuelo,pArrayListPiloto);

                break;
            }
            case 3:
            {

                mostrarCantPasajeros(pArrayListVuelo);
                break;
            }
            case 4:
            {
                mostrarCantPasIrlanda(pArrayListVuelo);

                break;
            }
            case 5:
            {
                listaFiltrada=ll_filter(pArrayListVuelo,filtrarVueloCorto);
                controller_Rodriguez_guardarVuelosCortos("vuelosCortos.csv",listaFiltrada);


                break;
            }
            case 6:
            {
                controller_Rodriguez_mostrarListaPortugal(pArrayListVuelo,pArrayListPiloto);

                break;
            }
            case 7:
            {
                controller_Rodriguez_mostrarListaNoAlex(pArrayListVuelo,pArrayListPiloto);

                break;
            }


            case 8:
                {
            controller_Rodriguez_mostrarListFilPil(pArrayListPiloto);
                    break;
                }case 9:
                {

                    break;
                }
                case 10:
                {

                    break;
                }
            default:
            {
                printf("No ingreso una opcion valida. Intento de nuevo\n");
                break;
            }

        }
        system("pause");
        system("cls");
    }while(opcion!=10);
}
