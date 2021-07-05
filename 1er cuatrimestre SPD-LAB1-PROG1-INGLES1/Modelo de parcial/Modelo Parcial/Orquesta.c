#include "Musico.h"

void hardcodearOrquestas(eOrquesta lista[])
{
    int estado[TORQUESTA] = {1, 1, 1, 1};
    int IDorquesta[TORQUESTA] = {1, 2, 3, 4};
    char lugarOrquesta[TORQUESTA][21] = {"LUGAR1", "LUGAR2", "LUGAR3", "LUGAR4"};
    char nombreOrquesta[TORQUESTA][21] = {"orquesta1", "orquesta2", "orquesta3","orquesta4"};
    int tipoOrquesta[TORQUESTA] = {1, 2, 3, 1};  //1 filarmonica, 2 sinfonica, 3 camara

    for(int i = 0; i < TORQUESTA; i++)
    {
        lista[i].estado = estado[i];
        lista[i].IDorquesta = IDorquesta[i];
        strcpy(lista[i].lugarOrquesta, lugarOrquesta[i]);
        strcpy(lista[i].nombreOrquesta, nombreOrquesta[i]);
        lista[i].tipoOrquesta = tipoOrquesta[i];
    }
}

void mostrarOrquesta(eOrquesta orquesta)
{
    printf("\n%16s|\t%22s|", orquesta.nombreOrquesta, orquesta.lugarOrquesta);

    if(orquesta.tipoOrquesta == 1)
    {
        printf("\t\t   Filarmonica|");
    }
    else if(orquesta.tipoOrquesta == 2)
    {
        printf("\t\t     Sinfonica|");
    }
    else
    {
        printf("\t\t        Camara|");
    }
    printf("\t\t%3d|", orquesta.IDorquesta);

}
void listarOrquesta(eOrquesta lista[], int tam)
{
    printf("\nORQUESTAS");
    printf("\n NOMBRE ORQUESTA|\t\tLUGAR ORQUESTA|\t\t TIPO ORQUESTA|\t\t ID|");
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarOrquesta(lista[i]);
        }
    }
}


int buscarOrquestaLibre(eOrquesta lista[], int tam)
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

int agregarOrquesta(eOrquesta lista[], int tam, int* id)
{
    int indice;
    int retorno = 1;
    eOrquesta auxCarga;

    indice = buscarOrquestaLibre(lista, tam);
    if(indice != -1 && cancelarOperacion("\nDesea llevar a cabo la operacion? s(si), n(no)") == 0)
    {
        if(cargarOrquesta(&auxCarga, &*id) == 0)
        {
            lista[indice] = auxCarga;
            lista[indice].estado = 1;
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

int inicializarOrquesta(eOrquesta lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
    return 0;
}

int cargarOrquesta(eOrquesta* auxiliar, int* id)
{
    int retorno = 1;

    if((getPalabra_Nombre(auxiliar->nombreOrquesta, "Nombre de la orquesta", "error", 20) == 0) &&
            (getPalabra_Nombre(auxiliar->lugarOrquesta, "Lugar de la orquesta", "error", 20) == 0) &&
            (ingresarNumero(&auxiliar->tipoOrquesta, "Tipo de orquesta\n1-Filarmonica\n2-Sinfonica\n3-De Camara", "error", 1, 3) == 0))
        {
            *id = generarId(*id);
            auxiliar->IDorquesta = *id;
            retorno = 0;
        }
    return retorno;
}
