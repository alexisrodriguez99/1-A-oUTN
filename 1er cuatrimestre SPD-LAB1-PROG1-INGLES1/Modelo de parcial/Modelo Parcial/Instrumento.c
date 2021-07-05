#include "Musico.h"

void hardcodearInstrumentos(eInstrumento lista[])
{
    int estado[TINSTRUMENTOS] = {1, 1, 1, 1};
    int ID[TINSTRUMENTOS] = {1, 2, 3, 4};
    char nombre[TINSTRUMENTOS][21] = {"guitarra", "violin", "timbal", "trompeta"};
    int tipo[TINSTRUMENTOS] = {1, 1, 3, 2};

    for(int i = 0; i < TINSTRUMENTOS; i++)
    {
        lista[i].estado = estado[i];
        lista[i].IDinstrumento = ID[i];
        strcpy(lista[i].nombreInstrumento, nombre[i]);
        lista[i].tipoInstrumento = tipo[i];
    }
}

void mostrarInstrumentos(eInstrumento Instrumentos)
{
    printf("\n%19s|", Instrumentos.nombreInstrumento);
    if(Instrumentos.tipoInstrumento == 1)
    {
        printf("\t\t       Cuerda|");
    }
    else if(Instrumentos.tipoInstrumento == 2)
    {
        printf("\t\tViento-Madera|");
    }
    else if(Instrumentos.tipoInstrumento == 3)
    {
        printf("\t\t Viento-Metal|");
    }
    else
    {
        printf("\t\t    Percusion|");
    }
}
void listarInstrumentos(eInstrumento lista[], int tam)
{
    printf("\n NOMBRE INSTRUMENTO|\t\t\t TIPO|");
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarInstrumentos(lista[i]);
        }
    }
}

int buscarInstrumentoLibre(eInstrumento lista[], int tam)
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

int agregarInstrumento(eInstrumento lista[], int tam, int* id)
{
    int indice;
    int retorno = 1;
    eInstrumento auxCarga;

    indice = buscarInstrumentoLibre(lista, tam);
    if(indice != -1 && cancelarOperacion("\nDesea llevar a cabo la operacion? s(si), n(no)") == 0)
    {
        if(cargarInstrumento(&auxCarga, &*id) == 0)
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

int inicializarInstrumento(eInstrumento lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
    return 0;
}

int cargarInstrumento(eInstrumento* auxiliar, int* id)
{
    int retorno = 1;

    if((getPalabra_Nombre(auxiliar->nombreInstrumento, "Nombre del instrumento", "error", 20) == 0) &&
            (ingresarNumero(&auxiliar->tipoInstrumento, "Tipo de instrumento\n1-Cuerda\n2-Viento-madera\n3-Viento-metal\n4-Percusion", "error", 1, 4) == 0))
    {
        *id = generarId(*id);
        auxiliar->IDinstrumento = *id;
        retorno = 0;
    }
    return retorno;
}
