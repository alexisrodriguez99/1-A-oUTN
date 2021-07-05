#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Log.h"
#include "Service.h"
#include "Parser.h"

int main()
{
    LinkedList* Log = ll_newLinkedList();
    LinkedList* Service = ll_newLinkedList();
    int ret;
    int opcion;
    do
    {
        printf("\n---MENU---\n1- Leer Log\n2- Procesar informacion\n3- Mostrar estadisticas\n4- Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(controller_load(Log, Parser_LogEntry, "log.txt") != -1 &&
               controller_load(Service, Parser_Service, "services.txt") != -1)
            {
                printf("\nSe cargo con exito");
            }
            break;
        case 2:
            controller_procesarInfo(Log, Service);
            break;
        case 3:
            controller_mostrarEstadistica(Log, Service);
            break;
        case 4:
            break;
        }
    }
    while(opcion != 4);
    return 0;
}
