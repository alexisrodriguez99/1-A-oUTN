#include "Vuelo.h"
void* Vuelo_new()
{
    return (Vuelo*) malloc(sizeof(Vuelo));
}
void* Vuelo_newParametro(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
    Vuelo* vueloAux = Vuelo_new();
    if(vueloAux != NULL)
    {
        Vuelo_setCantPasajeros(vueloAux, cantPasajeros);
        Vuelo_setDestino(vueloAux, destino);
        Vuelo_setFecha(vueloAux, fecha);
        Vuelo_setHoraDespegue(vueloAux, horaDespegue);
        Vuelo_setHoraLlegada(vueloAux, horaLlegada);
        Vuelo_setIdAvion(vueloAux, idAvion);
        Vuelo_setIdPiloto(vueloAux, idPiloto);
        Vuelo_setIdVuelo(vueloAux, idVuelo);
    }
    return vueloAux;
}
void Vuelo_mostrarVuelo(Vuelo* this, LinkedList* listaPilotos)
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[11];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    char nombrePiloto[100];
    Piloto* aux;

    if(this != NULL)
    {
        Vuelo_getIdVuelo(this, &idVuelo);
        Vuelo_getIdAvion(this, &idAvion);
        Vuelo_getIdPiloto(this, &idPiloto);
        Vuelo_getFecha(this, fecha);
        Vuelo_getDestino(this, destino);
        Vuelo_getCantPasajeros(this, &cantPasajeros);
        Vuelo_getHoraDespegue(this, &horaDespegue);
        Vuelo_getHoraLlegada(this, &horaLlegada);

        aux = (Piloto*) ll_get(listaPilotos, Piloto_buscarPorId(listaPilotos, idPiloto));
        //Cargo en el aux de Piloto el piloto que esta en el indice cuyo id
        //coincide con el idPiloto del vuelo, eso lo consigo con la funcion Piloto_buscarPorId
        if(aux != NULL)
        {
            Piloto_getNombre(aux, nombrePiloto);
            printf("\n%4d|\t %4d|\t %14s|\t %10s|\t %10s|\t %4d|\t %4d|\t %4d|", idVuelo, idAvion, nombrePiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        }
    }
}
void Vuelo_listar(LinkedList* lista, LinkedList* listaPilotos)
{
    Vuelo* aux;
    int size;

    if(lista != NULL && !ll_isEmpty(lista))
    {
        size = ll_len(lista);
        if(size > 0)
        {
            for(int i = 0; i < size; i++)
            {
                aux = (Vuelo*)ll_get(lista, i);
                Vuelo_mostrarVuelo(aux, listaPilotos);
            }
        }

    }
}
int Vuelo_cargarDeTexto(LinkedList* lista)
{
    int retorno = -1;
    FILE* pArchivo;

    if(!cancelarOperacion("\nSe sobreescribiran los datos, desea continuar con la carga? (s - n)"))
    {
        pArchivo = fopen("Vuelos.csv", "r");

        if(pArchivo != NULL && lista != NULL)
        {
            retorno = parser_VueloFromText(pArchivo, lista);
        }

        fclose(pArchivo);
    }
    else
    {
        retorno = -2;
    }

    return retorno;
}
int parser_VueloFromText(FILE* pFile, LinkedList* lista)
{
    int retorno;
    int r;
    int i = -1;
    char idVuelo[10];
    char idAvion[10];
    char idPiloto[10];
    char destino[129];
    char fecha[20];
    char cantPasajeros[10];
    char horaDespegue[20];
    char horaLlegada[20];
    Vuelo* auxCarga;

    ll_clear(lista);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        if(i >= 0 && r == 8)
        {
            auxCarga = Vuelo_newParametro(idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            if(auxCarga != NULL)
            {
                ll_add(lista, auxCarga);
            }
            else
            {
                i = -1;
                break;
            }
        }
        else if(r != 8)
        {
            ll_clear(lista);
            i = -1;
            break;
        }
        i++;
    }
    retorno = i;
    return retorno;
}

int Vuelo_setDestino(Vuelo* this, char* destino)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->destino, destino);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setFecha(Vuelo* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->fecha, fecha);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setIdVuelo(Vuelo* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idVuelo = atoi(id);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setIdAvion(Vuelo* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idAvion = atoi(id);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setIdPiloto(Vuelo* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idPiloto = atoi(id);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setCantPasajeros(Vuelo* this, char* num)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->cantPasajeros = atoi(num);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setHoraDespegue(Vuelo* this, char* num)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->horaDespegue = atoi(num);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_setHoraLlegada(Vuelo* this, char* num)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->horaLlegada = atoi(num);
        retorno = 0;
    }
    return retorno;
}


int Vuelo_getDestino(Vuelo* this, char* destino)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(destino, this->destino);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getFecha(Vuelo* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(fecha, this->fecha);
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getIdVuelo(Vuelo* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->idVuelo;
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getIdAvion(Vuelo* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->idAvion;
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getIdPiloto(Vuelo* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->idPiloto;
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getCantPasajeros(Vuelo* this, int* num)
{
    int retorno = -1;
    if(this != NULL)
    {
        *num = this->cantPasajeros;
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getHoraDespegue(Vuelo* this, int* num)
{
    int retorno = -1;
    if(this != NULL)
    {
        *num = this->horaDespegue;
        retorno = 0;
    }
    return retorno;
}
int Vuelo_getHoraLlegada(Vuelo* this, int* num)
{
    int retorno = -1;
    if(this != NULL)
    {
        *num = this->horaLlegada;
        retorno = 0;
    }
    return retorno;
}

int contarPasajeros(void* pElement)
{
    int cantPasajeros = -1;

    if(pElement != NULL)
    {
        Vuelo_getCantPasajeros(pElement, &cantPasajeros);
    }
    return cantPasajeros;
}

int filtrarIrlanda(void* pElement)
{
    int returnAux = 0;
    char destino[100];

    Vuelo_getDestino(pElement, destino);
    if(stricmp(destino, "Irlanda") == 0)
    {
        returnAux = 1;
    }
    return returnAux;
}
int filtrarPortugal(void* pElement)
{
    int returnAux = 0;
    char destino[100];

    Vuelo_getDestino(pElement, destino);
    if(stricmp(destino, "Portugal") == 0)
    {
        returnAux = 1;
    }
    return returnAux;
}

int filtrarMenos3Horas(void* pelement)
{
    int returnAux = 0;
    int horaDespegue;
    int horaLlegada;

    Vuelo_getHoraDespegue(pelement, &horaDespegue);
    Vuelo_getHoraLlegada(pelement, &horaLlegada);

    if(horaLlegada - horaDespegue < 3)
    {
        returnAux = 1;
    }
    return returnAux;
}

int filtrarPiloto(void* pelement)
{
    int returnAux = 0;
    int idPiloto;

    Vuelo_getIdPiloto(pelement, &idPiloto);

    if(idPiloto != 1)
    {
        returnAux = 1;
    }
    return returnAux;
}

int Vuelo_guardar(LinkedList* lista)
{
    int retorno = -1;
    FILE* pArchivo;
    Vuelo* auxVuelo;
    int len;

    int idVuelo;
    int idAvion;
    int idPiloto;
    char destino[129];
    char fecha[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    pArchivo = fopen("VuelosMenos3Horas.csv", "w");

    if(pArchivo != NULL && lista != NULL)
    {
        len = ll_len(lista);

        fprintf(pArchivo, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
        for(int i = 0; i < len; i++)
        {
            auxVuelo = ll_get(lista, i);
            if(auxVuelo != NULL)
            {
                Vuelo_getIdVuelo(auxVuelo, &idVuelo);
                Vuelo_getIdAvion(auxVuelo, &idAvion);
                Vuelo_getIdPiloto(auxVuelo, &idPiloto);
                Vuelo_getFecha(auxVuelo, fecha);
                Vuelo_getDestino(auxVuelo, destino);
                Vuelo_getCantPasajeros(auxVuelo, &cantPasajeros);
                Vuelo_getHoraDespegue(auxVuelo, &horaDespegue);
                Vuelo_getHoraLlegada(auxVuelo, &horaLlegada);

                fprintf(pArchivo, "%d,%d,%d,%s,%s,%d,%d,%d\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
            }
        }
        retorno = 0;
    }

    fclose(pArchivo);
    return retorno;
}
