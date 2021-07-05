#include "CamionxChofer.h"
#define TAM_CHOFERES_HARDCODEADO 6
#define TAM_CHOFERES 12
#define TAM_CAMIONES_HARDCODEADO 10
#define TAM_CAMIONES 25

int main()
{
    int opcion;
    eChofer listaChoferes[TAM_CHOFERES];
    eCamion listaCamiones[TAM_CAMIONES];
    inicializarChofer(listaChoferes,TAM_CHOFERES);
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
        printf("6) modificar un camion\n");
        printf("7) cargar chofer\n");
        printf("8) baja chofer en cascada\n");
        printf("9) ordenar camiones por tipo\n");
        printf("10) modificar chofer\n");
        printf("11) listar choferes con mas un camion\n");
        printf("12) listar camiones con mas de 10 años de antiguedad\n");
        printf("13) mostrar marca que quieras\n");
        printf("14) ordenar choferes por cantidad de camiones\n");
        printf("15) ordenar choferes por cantidad de camiones y por nombre\n");
        printf("16) promedio de las edades de los choferes\n");
        printf("17) promedio de los anios de antiguedad de los camiones\n");
        printf("17) promedio de los varones \n");//y mujeres de los choferes

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
                mostrarChoferesConCamiones(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
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
                modificarCamion(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
                break;
            }
            case 7:
            {
                cargarChofer(listaChoferes,TAM_CHOFERES);
                break;
            }
            case 8:
            {
                bajaChofer(listaChoferes,TAM_CHOFERES,listaCamiones,TAM_CAMIONES);
                break;
            }
            case 9:
            {
                mostrarCamionesConChoferes(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
                break;
            }
             case 10:
            {
                modificarChofer(listaChoferes,TAM_CHOFERES);
                break;
            }
             case 11:
            {
                choferesConMasUnCamiones(listaChoferes,TAM_CHOFERES,listaCamiones,TAM_CAMIONES);
                break;
            }
             case 12:
            {
                camionesConMasAntiguedad(listaCamiones,TAM_CAMIONES,listaChoferes,TAM_CHOFERES);
                break;
            }
            case 13:
                {
                    pedirMarca(listaCamiones,TAM_CAMIONES);
                    break;
                }
                 case 14:
                {
                    mostrarChoferMCCamion(listaChoferes,TAM_CHOFERES,listaCamiones,TAM_CAMIONES);
                    break;
                }
                 case 15:
                {
                    mostrarChoferFullOrden(listaChoferes,TAM_CHOFERES,listaCamiones,TAM_CAMIONES);
                    break;
                }
                 case 16:
                {
                    mostrarPromedio(listaChoferes,TAM_CHOFERES);
                    break;
                }
                 case 17:
                {
                    mostrarPromedioAnios(listaCamiones,TAM_CAMIONES);
                    break;

                }
                case 18:
                {
                    mostrarPromedioMyF(listaChoferes,TAM_CHOFERES);

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
