#include "MascotasClientes.h"
#define TAM_CLIENTE 10
#define TAM_CLIENTE_HARDCODEADO 5
#define TAM_MASCOTAS_HARCODEADO 11
#define TAM_MASCOTAS 20

int main()
{
    int opcion;
    eCliente listaCliente[TAM_CLIENTE];
    eMascota listaMascota[TAM_MASCOTAS];
    inicializarCliente(listaCliente,TAM_CLIENTE);
    hardCodearCliente(listaCliente,TAM_CLIENTE_HARDCODEADO);
    hardCodearMascota(listaMascota,TAM_MASCOTAS_HARCODEADO);
    do
    {
        printf("1) Listado Cliente\n");
        printf("2) listado de mascotas\n");
        printf("3) listado de clientes con mascota\n");
        /*printf("4) Agregar Musico\n");
        printf("5) Modificar Musico\n");
        printf("6) Eliminar Musico\n");
        printf("7) Imprimir Musicos\n");
        printf("8) Agregar Instrumento\n");
        printf("9) Imprimir instrumentos\n");*/
        printf("0) Salir\n");
        scanf("%d",&opcion);



        system("cls");
        switch(opcion)
        {
            case 1:
            {
                mostrarTodosLosCliente(listaCliente,TAM_CLIENTE);
                break;
            }
            case 2:
            {
                mostarTodasLasMascotas(listaMascota,TAM_MASCOTAS_HARCODEADO,listaCliente,TAM_CLIENTE);
                break;
            }
            case 3:
            {
                mostrarMascotasConClientes(listaMascota,TAM_MASCOTAS,listaCliente,TAM_CLIENTE);
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
