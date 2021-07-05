typedef struct
{
   int id;
 char name[33];
 char email[65];

}Service;
Service* servise_new();
Service* servise_newParametros(char* id,char* name,char* email);

void service_delete(Service* this);




int service_setId(Service* this,int id);
int service_getId(Service* this,int* id);

int service_setName(Service* this,char* name);
int service_getName(Service* this,char* name);

int service_setEmail(Service* this,char* email);
int service_getEmail(Service* this,char* email);

