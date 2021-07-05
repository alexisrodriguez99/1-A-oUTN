typedef struct
{
    char date[11];
 char time[6];
 int serviceId;
 int gravedad;
 char msg[65];
}LogEntry;
LogEntry* log_new();
LogEntry* log_newParametros(char* date,char* time,char* serviceId,char* gravedad,char* msg);

void log_delete(LogEntry* this);

int logEntry_setDate(LogEntry* this,char* date);
int logEntry_getDate(LogEntry* this,char* date);

int logEntry_setTime(LogEntry* this,char* time);
int logEntry_getTime(LogEntry* this,char* time);

int logEntry_setServiceId(LogEntry* this,int serviceId);
int logEntry_getServiceId(LogEntry* this,int* serviceId);

int logEntry_setGravedad(LogEntry* this,int gravedad);
int logEntry_getGravedad(LogEntry* this,int* gravedad);

int logEntry_setMsg(LogEntry* this,char* msg);
int logEntry_getMsg(LogEntry* this,char* msg);

