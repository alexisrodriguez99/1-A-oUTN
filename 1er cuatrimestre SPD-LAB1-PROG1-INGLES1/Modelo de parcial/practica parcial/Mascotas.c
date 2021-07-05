#include "Mascotas.h"

void hardcodearMascotas(eMascota lista[])
{
    int idMascota[TMASCOTAS]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int idCliente[TMASCOTAS]= {1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5};
    char nombre[TMASCOTAS][21]= {"Nombre1", "Nombre2", "Nombre3", "Nombre4", "Nombre5", "Nombre6", "Nombre7", "Nombre8", "Nombre9", "Nombre10", "Nombre11"};
    char tipo[TMASCOTAS][21]= {"Gato", "Gato", "Perro", "Perro", "Gato", "Perro", "Raro", "Perro", "Gato", "Gato", "Perro"};
    char raza[TMASCOTAS][21]= {"Raza1", "Raza2", "Raza3", "Raza4", "Raza5", "Raza6", "Raza7", "Raza8", "Raza9", "Raza10", "Raza11"};
    int edad[TMASCOTAS]= {2, 3, 1, 5, 7, 4, 2, 8, 9, 2, 11};
    float peso[TMASCOTAS]= {20, 12, 11, 53, 23, 12, 87, 10, 22, 12, 11};
    char sexo[TMASCOTAS]= {'f', 'f', 'm', 'm', 'm', 'm', 'f', 'm', 'm', 'm', 'm'};
    int estado[TMASCOTAS]= {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for(int i = 0; i < TMASCOTAS; i++)
    {
        lista[i].idMascota = idMascota[i];
        lista[i].idCliente = idCliente[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].tipo, tipo[i]);
        strcpy(lista[i].raza, raza[i]);
        lista[i].edad = edad[i];
        lista[i].peso = peso[i];
        lista[i].sexo = sexo[i];
        lista[i].estado = estado[i];
    }
}

void mostrarMascota(eMascota mascota)
{
    printf("\n%15s|%15s|%15s|%8d|%10.2f|%9c|", mascota.nombre,
           mascota.tipo,
           mascota.raza,
           mascota.edad,
           mascota.peso,
           mascota.sexo);
}
void listarMascotas(eMascota lista[], int tamMascotas)
{
    printf("\nMASCOTAS:");
    printf("\n\t NOMBRE|\t   TIPO|\t   RAZA|    EDAD|      PESO|     SEXO|");

    for(int i = 0; i < tamMascotas; i++)
    {
        if(lista[i].estado == 1)
        {
             mostrarMascota(lista[i]);
        }
    }
}
int buscarMascota(eMascota lista[], int tamMascota, char cadena[])
{
    int retorno;

    do
    {
        listarMascotas(lista, tamMascota);
        retorno = getLetras_Numeros(cadena, "Nombre de mascota a borrar", "error", 20);
        if(retorno == 0)
        {

            for(int i = 0; i < tamMascota; i++)
            {
                if(stricmp(cadena, lista[i].nombre) == 0 && lista[i].estado == 1)
                {
                    retorno = i;
                    break;
                }
            }

            if(retorno < 0)
            {
                printf("\nNo se encontro el nombre");
                retorno = -1;
            }
        }
        else
        {
            retorno = -1;
        }
    }
    while(retorno == -1 && cancelarOperacion("Desea reintentar el ingreso? s(si), n(no)") == 0);
    return retorno;
}

int bajaMascota(eMascota lista[], int tamMascota)
{
    int retorno;
    char cadena[21];

    printf("\nBAJA DE MASCOTAS");

    retorno = buscarMascota(lista, tamMascota, cadena);

    if(retorno != -1)
    {
        lista[retorno].estado = 0;
    }
    return retorno;

}
int modificarMascota(eMascota lista[], int tamMascota)
{
    int retorno;
    char cadena[21];

    printf("\nMODIFICAR MASCOTA");
    retorno = buscarMascota(lista, tamMascota, cadena);

    if(retorno != -1)
    {
        retorno = modificarDatos(&lista[retorno]);
    }
    return retorno;
}

int modificarDatos(eMascota* auxiliar)
{
    int retorno = 1;

    if((getPalabra_Nombre(auxiliar->nombre, "Nombre de la mascota", "error", 20) == 0) &&
            (ingresarTipo(&*auxiliar) == 0) &&
            (getPalabra_Nombre(auxiliar->raza, "Raza de la mascota", "error", 20) == 0) &&
            (ingresarNumero(&auxiliar->edad, "Edad de la mascota", "Error", 1, 20) == 0) &&
            (ingresarDecimal(&auxiliar->peso, "Peso de la mascota", "Error", 1, 100) == 0) &&
            (ingresarCaracter(&auxiliar->sexo, "Sexo (f o m)", "Error", 1) == 0))
        {
            retorno = 0;
        }
    return retorno;
}

void ordenarMascotas(eMascota lista[], int tamMascota)
{
    eMascota aux;
    for(int i = 0; i < tamMascota -1; i++)
    {
        for(int j = i+1; j < tamMascota; j++)
        {
            if((strcmp(lista[i].tipo, lista[j].tipo) > 0) || ((strcmp(lista[i].tipo, lista[j].tipo) == 0) && (strcmp(lista[i].nombre, lista[j].nombre) > 0)))
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

