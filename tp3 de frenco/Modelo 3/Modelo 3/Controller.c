#include "Controller.h"
#include "LinkedList.h"
#include "Log.h"
#include "Service.h"
#include "Input.h"

int controller_load(LinkedList* lista, int (*pFunc)(FILE*, LinkedList*), char* path)
{
    int retorno = -1;
    FILE* pArchivo;

    if(!cancelarOperacion("\nSe sobreescribiran los datos, desea continuar con la carga? (s - n)") && pFunc != NULL)
    {
        pArchivo = fopen(path, "r");

        if(pArchivo != NULL && lista != NULL)
        {
            retorno = pFunc(pArchivo, lista);
        }

        fclose(pArchivo);
    }
    else
    {
        retorno = -2;
    }

    return retorno;
}
int controller_list(LinkedList* lista, LinkedList* lista2, void (*pFunc)(void*, LinkedList*))
{
    int retorno = -1;//Error en la lista
    void* aux;
    int size;

    if(lista != NULL && !ll_isEmpty(lista) && pFunc != NULL)
    {
        size = ll_len(lista);
        if(size > 0)
        {
            retorno = 0;
            for(int i = 0; i < size; i++)
            {
                aux = ll_get(lista, i);
                pFunc(aux, lista2);
            }
        }
    }
    return retorno;
}
int controller_escribirLista(LinkedList* listaLog, LinkedList* listaService, char* path)
{
    int retorno = -1;
    FILE* pArchivo;
    LogEntry* auxLog;
    int len;

    char fecha[11];
    char hora[6];
    int ServiceId;
    char msg[65];

    Service* aux;
    char servicio[33];
    char mail[65];

    pArchivo = fopen(path, "w");

    if(pArchivo != NULL && listaLog != NULL && listaService != NULL && path != NULL)
    {

        len = ll_len(listaLog);

        fprintf(pArchivo, "Fecha;Hora;Nombre;servicio;Mensajedeerror;E-mailsoporte\n");
        for(int i = 0; i < len; i++)
        {
            auxLog = ll_get(listaLog, i);
            if(auxLog != NULL)
            {
                LogEntry_getFecha(auxLog, fecha);
                LogEntry_getHora(auxLog, hora);
                LogEntry_getServiceId(auxLog, &ServiceId);
                LogEntry_getMsg(auxLog, msg);

                aux = (Service*) ll_get(listaService, Service_buscarPorId(listaService, ServiceId));
                if(aux != NULL)
                {
                    Service_getName(aux, servicio);
                    Service_getMail(aux, mail);
                    fprintf(pArchivo, "%s;%s;%s;%s;%s\n", fecha, hora, servicio, msg, mail);
                }
            }
        }
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}
int controller_procesarInfo(LinkedList* listaLog, LinkedList* listaService)
{
    int retorno = -1;
    LinkedList* listaAux = NULL;

    if(listaLog != NULL && listaService != NULL && !ll_isEmpty(listaLog) && !ll_isEmpty(listaService))
    {
        retorno = 0;
        listaAux = ll_newLinkedList();

        if(listaAux != NULL)
        {
            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadIgual3);
            controller_escribirLista(listaAux, listaService, "warnings.txt");
            ll_clear(listaAux);

            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadDe4a7);
            controller_list(listaAux, listaService, LogEntry_mostrar);
            ll_clear(listaAux);

            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadMayor7);
            controller_escribirLista(listaAux, listaService, "errors.txt");
            ll_clear(listaAux);

        }
    }
    return retorno;
}
int controller_mostrarEstadistica(LinkedList* listaLog, LinkedList* listaService)
{
    int retorno = -1;
    int cont;
    int cant = 0;
    Service* auxService;
    Service* servicioMasError;
    LogEntry* auxLog;
    LinkedList* listaAux = NULL;

    if(listaLog != NULL && listaService != NULL && !ll_isEmpty(listaLog) && !ll_isEmpty(listaService))
    {
        retorno = 0;
        listaAux = ll_newLinkedList();

        if(listaAux != NULL)
        {
            for(int i = 0; i < ll_len(listaService); i++)
            {
                cont = 0;
                auxService = ll_get(listaService, i);
                for(int j = 0; j < ll_len(listaLog); j++)
                {
                    auxLog = ll_get(listaLog, j);
                    if(auxService->id == auxLog->ServiceId)
                    {
                        cont++;
                    }
                }
                if(cont >= cant)
                {
                    servicioMasError = auxService;
                    cant = cont;
                }
            }
            printf("\nEl servicio con mas errores es:");
            Service_mostrar(servicioMasError, listaService);

            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadMenor3);
            printf("\nLa cantidad de servicios con errores de gravedad menor 3: %d", ll_len(listaAux));
            ll_clear(listaAux);

            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadIgual3);
            printf("\nLa cantidad de servicios con errores de gravedad 3: %d", ll_len(listaAux));
            ll_clear(listaAux);

            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadDe4a7);
            printf("\nLa cantidad de servicios con errores de gravedad entre 4 y 7: %d", ll_len(listaAux));
            ll_clear(listaAux);

            listaAux = ll_filter(listaLog, LogEntry_filtrarGravedadMayor7);
            printf("\nLa cantidad de servicios con errores de gravedad mayor a 7: %d", ll_len(listaAux));
            ll_clear(listaAux);

        }
    }
    return retorno;
}
