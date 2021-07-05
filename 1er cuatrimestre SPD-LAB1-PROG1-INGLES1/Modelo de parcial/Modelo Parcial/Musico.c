#include "Musico.h"

void hardcodearMusicos(eMusico lista[])
{
    int estado[TMUSICOS] = {1, 1, 1, 1};
    int ID[TMUSICOS] = {1, 2, 3, 4};
    char apellido[TMUSICOS][21] = {"asasd", "fffde", "vvvvv", "bbbbb"};
    char nombre[TMUSICOS][21] = {"qqqq", "wwwww", "eeeee","rrrrr"};
    int IDorquesta[TMUSICOS] = {1, 2, 3, 1};
    int IDinstrumento[TMUSICOS] = {1, 2, 3, 1};
    int edad[TMUSICOS] = {20, 23,21,44};
    for(int i = 0; i < TMUSICOS; i++)
    {
        lista[i].estado = estado[i];
        lista[i].IDorquesta = IDorquesta[i];
        strcpy(lista[i].apellido, apellido[i]);
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].IDinstrumento = IDinstrumento[i];
        lista[i].edad = edad[i];
        lista[i].IDMusico = ID[i];
    }
}

void mostrarMusico(eMusico musico, eInstrumento listaInstrum[], int tamInstrumento)
{
    int retornoFuncion;
    char nombre[20];
    printf("\n%3d|\t%14s|\t%15s|\t%4d|",musico.IDMusico,musico.nombre, musico.apellido, musico.edad);
    mostrarNombreInstrumento(nombre, musico.IDinstrumento, listaInstrum, tamInstrumento);
    printf("\t%15s|", nombre);
    retornoFuncion = mostrarTipoInstrumento(musico.IDinstrumento, listaInstrum, tamInstrumento);

    if(retornoFuncion == 1)
    {
        printf("\t       Cuerda|");
    }
    else if(retornoFuncion == 2)
    {
        printf("\t Viento-Madera|");
    }
    else if(retornoFuncion == 3)
    {
        printf("\t Viento-Metal|");
    }
    else
    {
        printf("\t    Percusion|");
    }

}

int mostrarTipoInstrumento(int idInstrum, eInstrumento lista[], int tam)
{
    int retorno = -1;
    for(int i = 0; i < tam; i++)
    {
        if(idInstrum == lista[i].IDinstrumento)
        {
            retorno = lista[i].tipoInstrumento;
            break;
        }
    }
    return retorno;
}

int mostrarNombreInstrumento(char cadenaNombre[], int idInstrum, eInstrumento lista[], int tam)
{
    int retorno = -1;
    for(int i = 0; i < tam; i++)
    {
        if(idInstrum == lista[i].IDinstrumento)
        {
            strcpy(cadenaNombre, lista[i].nombreInstrumento);
            retorno = 0;
            break;
        }
    }
    return retorno;
}
void listarMusicos(eMusico lista[], int tam, eInstrumento listaInstrum[], int tamInstrumento)
{
    printf("\nMUSICOS:");
    printf("\n ID|\t\tNOMBRE|\t\tAPELLIO|\tEDAD|\t    INSTRUMENTO|\t\t TIPO|");
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarMusico(lista[i], listaInstrum, tamInstrumento);
        }
    }
}


int buscarMusicoLibre(eMusico lista[], int tam)
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

int agregarMusico(eMusico lista[], int tam, int* id, eOrquesta listaOrquesta[], int tamOrquesta, eInstrumento listaInstrumento[], int tamInstrumento)
{
    int indice;
    int retorno = 1;
    eMusico auxCarga;

    indice = buscarMusicoLibre(lista, tam);
    if(indice != -1 && cancelarOperacion("\nDesea llevar a cabo la operacion? s(si), n(no)") == 0)
    {
        if(cargarMusico(&auxCarga, &*id, listaOrquesta, tamOrquesta, listaInstrumento, tamInstrumento) == 0)
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

int inicializarMusicos(eMusico lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
    return 0;
}

int cargarMusico(eMusico* auxiliar,  int* id, eOrquesta listaOrquesta[], int tamOrquesta, eInstrumento listaInstrumento[], int tamInstrumento)
{
    int retorno = 1;

    if((getPalabra_Nombre(auxiliar->nombre, "Nombre del musico", "error", 20) == 0) &&
            (getPalabra_Nombre(auxiliar->apellido, "Apellido del musico", "error", 20) == 0) &&
            (ingresarNumero(&auxiliar->edad, "Edad del musico", "error", 1, 150) == 0) &&
            (ingresarIDOrquesta(&auxiliar->IDorquesta, listaOrquesta, tamOrquesta) != 0) &&
            (ingresarIDInstrumento(&auxiliar->IDinstrumento, listaInstrumento, tamInstrumento) != 0))
    {
        *id = generarId(*id);
        auxiliar->IDMusico = *id;
        retorno = 0;
    }
    return retorno;
}

int ingresarIDOrquesta(int* idDeOrquesta, eOrquesta lista[], int tam)
{
    char aux[200];
    int retorno;


    do
    {
        listarOrquesta(lista, tam);
        retorno = -1;

        if(getLetras_Numeros(aux, "Nombre de laorquesta en la que va a tocar", "Error", 20) == 0)
        {
            for(int i = 0; i < tam; i++)
            {
                if(stricmp(aux, lista[i].nombreOrquesta) == 0)
                {
                    retorno = lista[i].IDorquesta;
                    *idDeOrquesta = retorno;
                    break;
                }
            }
        }
        if(retorno == -1)
        {
            printf("\nNo se encontro la orquesta");
            if(cancelarOperacion("\nQuiere volver a ingresar?") == 1)
            {
                retorno = 0;
            }
        }
    }
    while(retorno == -1);
    return retorno;
}


int ingresarIDInstrumento(int* idInstrumento, eInstrumento lista[], int tam)
{
    char aux[200];
    int retorno;

    do
    {
        listarInstrumentos(lista, tam);
        retorno = -1;

        if(getLetras_Numeros(aux, "Nombre del instrumento en la que va a tocar", "Error", 20) == 0)
        {
            for(int i = 0; i < tam; i++)
            {
                if(stricmp(aux, lista[i].nombreInstrumento) == 0)
                {
                    retorno = lista[i].IDinstrumento;
                    *idInstrumento = retorno;
                    break;
                }
            }
        }
        if(retorno == -1)
        {
            printf("\nNo se encontro el instrumento");
            if(cancelarOperacion("\nQuiere volver a ingresar?") == 1)
            {
                retorno = 0;
            }
        }
    }
    while(retorno == -1);
    return retorno;
}

int bajaOrquesta(eOrquesta lista[], int tam, eMusico listaMusicos[], int tamMusicos)
{
    int idAuxiliar;
    int retorno = 1;
    listarOrquesta(lista, tam);

    if(ingresarNumero(&idAuxiliar, "ID de la oquesta a eliminar(Se eliminaran tambien todos los musicos que toquen en ella)", "Error", 1, tam) == 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].IDorquesta == idAuxiliar)
            {
                lista[i].estado = 0;
                for(int j = 0; j < tamMusicos; j++)
                {
                    if(listaMusicos[j].IDorquesta == idAuxiliar)
                    {
                        listaMusicos[j].estado = 0;
                    }
                }
                break;
            }
        }
        retorno = 0;
    }
    return retorno;
}
