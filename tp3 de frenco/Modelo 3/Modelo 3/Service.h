#include "LinkedList.h"
typedef struct
{
    int id;
    char name[33];
    char mail[65];
}Service;

Service* Service_new();
Service* Service_newParametros(char* id, char* name, char* mail);

int Service_setId(Service* this, char* id);
int Service_setName(Service* this, char* nombre);
int Service_setMail(Service* this, char* mail);

int Service_getId(Service* this, int* id);
int Service_getName(Service* this, char* nombre);
int Service_getMail(Service* this, char* mail);

void Service_mostrar(void* this, LinkedList* );

int Service_buscarPorId(LinkedList* lista, int id);
