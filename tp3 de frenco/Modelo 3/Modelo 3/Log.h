#include "LinkedList.h"
typedef struct
{
    char fecha[11];
    char hora[6];
    int ServiceId;
    int gravedad;
    char msg[65];
}LogEntry;

LogEntry* LogEntry_new();
LogEntry* LogEntry_newParametros(char* fecha, char* hora, char* serviceId, char* gravedad, char* msg);

int LogEntry_setServiceId(LogEntry* this, char* id);
int LogEntry_setGravedad(LogEntry* this, char* gravedad);
int LogEntry_setFecha(LogEntry* this, char* fecha);
int LogEntry_setHora(LogEntry* this, char* hora);
int LogEntry_setMsg(LogEntry* this, char* msg);

int LogEntry_getServiceId(LogEntry* this, int* id);
int LogEntry_getGravedad(LogEntry* this, int* gravedad);
int LogEntry_getFecha(LogEntry* this, char* fecha);
int LogEntry_getHora(LogEntry* this, char* hora);
int LogEntry_getMsg(LogEntry* this, char* msg);

void LogEntry_mostrar(void* this, LinkedList* listaServicios);

int LogEntry_filtrarGravedadMenor3(void* pElement);
int LogEntry_filtrarGravedadIgual3(void* pElement);
int LogEntry_filtrarGravedadDe4a7(void* pElement);
int LogEntry_filtrarGravedadMayor7(void* pElement);
