#include "parser.h"
#include "piloto.h"
int parser_vuelo(FILE* pFile , LinkedList* pArrayListVuelo)
{
     Vuelo* vuelo;
    char idVuelo[40];
    char idAvion[40];
    char idPiloto[40];
    char fecha[40];
    char destino[40];
    char cantPasajeros[40];
    char horaDespegue[40];
    char horaLlegada[40];

    int retorno=0;
    if(pFile!=NULL && pArrayListVuelo!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada)==8)
        {
            vuelo=vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
            ll_add(pArrayListVuelo,vuelo);
                            retorno=1;

        }
        else
        {
            break;
        }
    }while(!feof(pFile));

    }

    return retorno;
}
int parser_piloto(FILE* pFile , LinkedList* listaPiloto)
{
     Piloto* Piloto;
    char id[40];
    char nombre[40];


    int retorno=0;
    if(pFile!=NULL && listaPiloto!=NULL)
    {

    do
    {
        if(fscanf(pFile,"%[^,],%[^\n]\n",id,nombre)==2)
        {
            Piloto=piloto_newParametros(id,nombre);
            ll_add(listaPiloto,Piloto);
                            retorno=1;

        }
        else
        {
            break;
        }
    }while(!feof(pFile));

    }

    return retorno;
}
