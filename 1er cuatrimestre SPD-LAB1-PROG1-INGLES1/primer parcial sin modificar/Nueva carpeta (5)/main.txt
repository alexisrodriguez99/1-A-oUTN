#include "CamionxChofer.h"
#define TAM_CHOFERES_HARDCODEADO 6
#define TAM_CHOFERES 12
#define TAM_CAMIONES_HARDCODEADO 10
#define TAM_CAMIONES 20

int main()
{
    int opcion;
    eChofer listaChoferes[TAM_CHOFERES];
    eCamion listaCamiones[TAM_CAMIONES];
    inicializarCamion(listaCamiones,TAM_CAMIONES);


    hardCodearChofer(listaChoferes,TAM_CHOFERES_HARDCODEADO);
    hardCodearCamion(listaCamiones,TAM_CAMIONES_HARDCODEADO);
    do
    {
        printf("1) Listado de choferes\n");
        printf("2) listado de camiones\n");
        printf("3) listado de choferes con camiones\n");
        printf("4) cargar un camion\n");
        printf("5) dar de baja un camion\n");

        printf("0) Salir\n");
        scanf("%d",&opcion);



        system("cls");
        switch(opcion)
        {
            case 1:
            {
                mostrarTodosLosChofer(listaChoferes,TAM_CHOFERES);
                break;
            }
            case 2:
            {
                mostrarTodosLosCamiones(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
                break;
            }
            case 3:
            {
                mostrarCamionesYChoferes(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
                break;
            }
            case 4:
            {
                cargarCamion(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
                break;
            }
            case 5:
            {
                bajaCamion(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
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
    }while(opcion!=0);
}
