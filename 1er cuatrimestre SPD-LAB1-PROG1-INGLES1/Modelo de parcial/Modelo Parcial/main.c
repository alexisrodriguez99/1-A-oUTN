#include <stdio.h>
#include <stdlib.h>
#include "Musico.h"

int main()
{
    int idOrquesta = 0;
    int idMusico = 0;
    int idInstrumento = 0;
    int opcionMenu;
    int retornoFuncion;
    eOrquesta listaOrquesta[TORQUESTA];
    eInstrumento listaInstrumento[TINSTRUMENTOS];
    eMusico listaMusicos[TMUSICOS];

    hardcodearOrquestas(listaOrquesta);
    //listarOrquesta(listaOrquesta, TORQUESTA);

    hardcodearMusicos(listaMusicos);
    //listarMusicos(listaMusicos, TMUSICOS);

    hardcodearInstrumentos(listaInstrumento);
    //listarInstrumentos(listaInstrumento, TINSTRUMENTOS);

    //inicializarOrquesta(listaOrquesta, TORQUESTA);
    //inicializarMusicos(listaMusicos, TMUSICOS);
    //inicializarInstrumento(listaInstrumento, TINSTRUMENTOS);

    do
    {
        printf("\n---Bienvenido al menu de opciones---\n\n1- Agregar Orquesta\n2- Eliminar Orquesta\n3- Imprimir Orquesta\n4- Agregar musico\n5- modificar musico\n6- eliminar musico\n7- Imprimir musico\n8- agregar instrumento\n9- Imprimir instrumento\n10- Listar\n11-Salir");
        printf("\nSingrese opcion para el menu: ");
        scanf("%d", &opcionMenu);

        switch (opcionMenu)
        {
        case 1:
            retornoFuncion = agregarOrquesta(listaOrquesta, TORQUESTA, &idOrquesta);
            if(retornoFuncion == -1)
            {
                printf("\nSe cancelo la operacion");
            }
            else if(retornoFuncion == 0)
            {
                printf("\nNo hay mas espacio");
            }
            else
            {
                printf("\nLa orquesta se cargo con exito");
            }

            break;
        case 2:
            retornoFuncion = bajaOrquesta(listaOrquesta, TORQUESTA, listaMusicos, TMUSICOS);
            if(retornoFuncion == 1)
            {
                printf("\nSe cancelo la operacion");
            }
            else
            {
                printf("\nLa orquesta y todos los musicos que tocaban en ella se eliminaron exitosamente");
            }
            break;
        case 3:
            listarOrquesta(listaOrquesta, TORQUESTA);
            break;
        case 4:
            retornoFuncion = agregarMusico(listaMusicos, TMUSICOS, &idMusico, listaOrquesta, TORQUESTA, listaInstrumento, TINSTRUMENTOS);
            if(retornoFuncion == -1)
            {
                printf("\nSe cancelo la operacion");
            }
            else if(retornoFuncion == 0)
            {
                printf("\nNo hay mas espacio");
            }
            else
            {
                printf("\nEl musico se cargo con exito");
            }
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            listarMusicos(listaMusicos, TMUSICOS, listaInstrumento, TINSTRUMENTOS);
            break;
        case 8:
            retornoFuncion = agregarInstrumento(listaInstrumento, TINSTRUMENTOS, &idInstrumento);
            if(retornoFuncion == -1)
            {
                printf("\nSe cancelo la operacion");
            }
            else if(retornoFuncion == 0)
            {
                printf("\nNo hay mas espacio");
            }
            else
            {
                printf("\nEl instrumento se cargo con exito");
            }
            break;
        case 9:
            listarInstrumentos(listaInstrumento, TINSTRUMENTOS);
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
