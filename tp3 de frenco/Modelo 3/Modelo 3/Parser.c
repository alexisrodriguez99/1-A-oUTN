#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Service.h"
#include "Log.h"

int Parser_Service(FILE* pFile, LinkedList* lista)
{
    int retorno;
    int r;
    int i = -1;

    char id[10];
    char name[33];
    char mail[65];

    Service* auxCarga;

    ll_clear(lista);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^;];%[^;];%[^\n]\n", id, name, mail);
        if(i >= 0 && r == 3)
        {
            auxCarga = Service_newParametros(id, name, mail);
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
        else if(r != 3)
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
int Parser_LogEntry(FILE* pFile, LinkedList* lista)
{
    int retorno;
    int r;
    int i = -1;

    char fecha[11];
    char hora[6];
    char ServiceId[10];
    char gravedad[10];
    char msg[65];

    LogEntry* auxCarga;

    ll_clear(lista);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n", fecha, hora, ServiceId, gravedad, msg);
        if(i >= 0 && r == 5)
        {
            auxCarga = LogEntry_newParametros(fecha, hora, ServiceId, gravedad, msg);
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
        else if(r != 5)
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
