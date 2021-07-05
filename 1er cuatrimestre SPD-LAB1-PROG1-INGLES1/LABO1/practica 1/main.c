
#include "orquesta.h"
#define TAM_ORQUESTA 50
#define TAM_INSTRUMENTOS 20
#define TAM_MUSICO 1000



int main()
{
    int opcion;
    eOrquesta listaOrquesta[TAM_ORQUESTA];
    inicializar(listaOrquesta,TAM_ORQUESTA);
    do
    {
        printf("1) Agregar Orquesta\n");
        printf("2) Eliminar Orquesta\n");
        printf("3) Imprimir Orquestas\n");
        printf("4) Agregar Musico\n");
        printf("5) Modificar Musico\n");
        printf("6) Eliminar Musico\n");
        printf("7) Imprimir Musicos\n");
        printf("8) Agregar Instrumento\n");
        printf("9) Imprimir instrumentos\n");
        printf("0) Salir\n");
        scanf("%d",&opcion);



        system("cls");
        switch(opcion)
        {
            case 1:
            {
                cargarUnaOrquesta(listaOrquesta,TAM_ORQUESTA);

                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                printf("ID\t\t NOMBRE\t\t LUGAR\t\t TIPO\n");

                mostrarOrquesta(listaOrquesta,TAM_ORQUESTA);
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 0:
                {
                    printf("Usted esta saliendo\n");
                }
            default:
            {
                printf("No ingreso una opcion valida. Intento de nuevo\n");
                break;
            }

        }
        system("pause");
        system("cls");
    }while(opcion!=0); //hardcodearOrquestas(listaOrquesta);
    // en el case 3
}
