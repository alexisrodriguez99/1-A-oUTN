#include "parse.h"
#include "log.h"
#include "service.h"

int parser_logFromText(FILE* pFile , LinkedList* listaLog)
{
    LogEntry* log;
    char date[40];
    char time[40];
    char serviceId[40];
    char gravedad[40];
        char msg[40];

    int retorno=0;
    if(pFile!=NULL && listaLog!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",date,time,serviceId,gravedad,msg);

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",date,time,serviceId,gravedad,msg)==5)
        {
            log=log_newParametros(date,time,serviceId,gravedad,msg);
            ll_add(listaLog,log);
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
int parser_serviceFromText(FILE* pFile , LinkedList* listaService)
{
    Service* service;
    char id[40];
    char name[40];
    char email[40];


    int retorno=0;
    if(pFile!=NULL && listaService!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,name,email);

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,name,email)==3)
        {
            service=servise_newParametros(id,name,email);
            ll_add(listaService,service);
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

