#include "ClientesMascotas.h"

void mostrarClientesConMascotas(eCliente listaCliente[], eMascota ListaMascota[], int tamCliete, int tamMascota)
{
    for(int i = 0; i < tamCliete; i++)
    {
        if(listaCliente[i].estado == 1)
        {
            printf("\nCLIETNE:");
            printf("\n\t NOMBRE|       APELLIDO|      LOCALIDAD|       TELEFONO|     EDAD|     SEXO|");
            mostrarCliente(listaCliente[i]);

            printf("\nMASCOTAS:");
            printf("\n\t NOMBRE|\t   TIPO|\t   RAZA|    EDAD|      PESO|     SEXO|");
            for(int j = 0; j < tamMascota; j++)
            {
                if(listaCliente[i].ID == ListaMascota[j].idCliente && ListaMascota[j].estado == 1)
                {
                    mostrarMascota(ListaMascota[j]);
                }

            }
            printf("\n------------------------------------------------------------------------------------");
        }
    }
}

int altaMascotas(eMascota listaMascota[], eCliente listaCliente[], int tamMascota, int tamCliente, int* id)
{
    int indice;
    int retorno = 1;
    eMascota auxCarga;

    indice = buscarMascotaLibre(listaMascota, tamMascota);
    if(indice != -1 && cancelarOperacion("\nDesea llevar a cabo la operacion? s(si), n(no)") == 0)
    {
        if(cargarMascota(&auxCarga, &*id, listaCliente, tamCliente) == 0)
        {
            listaMascota[indice] = auxCarga;
            listaMascota[indice].estado = 1;
        }
        else
        {
            retorno = -1;
        }
    }
    else if(indice != -1)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int buscarMascotaLibre(eMascota lista[], int tam)
{
    int i;
    int retorno = -1;

    for(i = 0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}



int cargarMascota(eMascota* auxiliar, int * id, eCliente listaClientes[], int tamCliente)
{
    int retorno = 1;

    if((getPalabra_Nombre(auxiliar->nombre, "Nombre de la mascota", "error", 20) == 0) &&
            (ingresarTipo(&*auxiliar) == 0) &&
            (getPalabra_Nombre(auxiliar->raza, "Raza de la mascota", "error", 20) == 0) &&
            (ingresarNumero(&auxiliar->edad, "Edad de la mascota", "Error", 1, 20) == 0) &&
            (ingresarDecimal(&auxiliar->peso, "Peso de la mascota", "Error", 1, 100) == 0) &&
            (ingresarCaracter(&auxiliar->sexo, "Sexo (f o m)", "Error", 1) == 0) &&
            (asignarCliente(listaClientes, &*auxiliar, tamCliente) == 0))
    {
        *id = generarId(*id);
        auxiliar->idMascota = *id;
        retorno = 0;
    }
    return retorno;
}

int asignarCliente(eCliente listaClientes[], eMascota * auxiliar, int tamCliente)
{
    int retorno;
    int flag = 0;
    char cadena[21];

    do
    {
        listarCliente(listaClientes, tamCliente);
        retorno = getLetras_Numeros(cadena, " el nombre de un duenio para la mascota", "Error", 20);
        if(retorno == 0)
        {
            for(int i = 0; i < tamCliente; i++)
            {
                if(stricmp(listaClientes[i].nombre, cadena) == 0 && listaClientes[i].estado == 1)
                {
                    auxiliar->idCliente = listaClientes[i].ID;
                    flag = 1;
                    break;
                }

            }
            if(flag == 0)
            {
                printf("\nNo se encontro el cliente");
                retorno = 1;
            }
        }
    }
    while(retorno == 1 && cancelarOperacion("Desea reintentar el ingreso? s(si), n(no)") == 0);

    return retorno;
}

int ingresarTipo(eMascota * auxiliar)
{
    int retorno;
    char cadena[21];

    do
    {
        retorno = getPalabra_Nombre(cadena, "Tipo de mascota\n-Perro\n-Gato\n-Raro\n", "error", 20);
        if(retorno == 0)
        {

            if(stricmp("Perro", cadena) == 0 || stricmp("Gato", cadena) == 0 || stricmp("Raro", cadena) == 0)
            {
                strcpy(auxiliar->tipo, cadena);

            }
            else
            {
                printf("\nNo es un tipo valido");
                retorno = 1;
            }
        }
    }
    while(retorno == 1 && cancelarOperacion("Desea reintentar el ingreso? s(si), n(no)") == 0);

    return retorno;
}

