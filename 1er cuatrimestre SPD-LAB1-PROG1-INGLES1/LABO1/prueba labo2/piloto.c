#include "piloto.h"
void hardCodearPiloto(LinkedList* this)
{
    Piloto* piloto[5];
    int i;
    int id[5]={1,2,3,4,5};
    char nombre[5][30]={"Alex Lifeson","Richard Bach","John Kerry","Erwin Rommel","Stephen Coonts"};
    for(i=0;i<5;i++)
    {
        piloto[i]=piloto_new();
        piloto[i]->id=id[i];
        strcpy(piloto[i]->nombre,nombre[i]);
        ll_add(this,piloto[i]);
    }
}
Piloto* piloto_new()
{
    return (Piloto*) malloc(sizeof(Piloto));
}
int piloto_getNombre(Piloto* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
int piloto_getId(Piloto* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
int buscarPiltoId(LinkedList* this, int idPiloto)
{
    int i;
    int retorno;
    Piloto* piloto;
    int idComparar;
    if(this!=NULL)
    {
        retorno=-1;
        for(i=0;i<ll_len(this);i++)
        {
            piloto=ll_get(this,i);
            piloto_getId(piloto,&idComparar);
            if(idComparar==idPiloto)
            {
                retorno=i;// retorna la posicion de donde se encuentra el id (0-4)
                break;
            }
        }
    }
    return retorno;
}
int filtrarPiloto(void* pElemento,char* nombre)
{
    char nombrePiloto[50];
    int retorno=0;
    if(pElemento!=NULL)
    {
        piloto_getNombre(pElemento,nombrePiloto);
        if(strcmp(nombre,nombrePiloto)!=0)
        {
            retorno=1;
        }

    }
    return retorno;
}
void mostrarUnPiloto(Piloto* piloto)
{
    int id;
    char nombre[50];
    if(piloto!=NULL)
    {
        piloto_getId(piloto,&id);
        piloto_getNombre(piloto,nombre);

        printf("%4d %10s",id,nombre);
    }
}
int piloto_setId(Piloto* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int piloto_setNombre(Piloto* this,char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre!= NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }

    return retorno;
}
void piloto_delete(Piloto* this)
{
    free(this);
}
Piloto* piloto_newParametros(char* id,char* nombre)
{
    Piloto* this;
    this=piloto_new();
    if( !piloto_setId(this,atoi(id)) &&

        !piloto_setNombre(this,nombre)
       )
    {
        return this;
    }
    piloto_delete(this);
    return NULL;
}
/*int filtrarPiloto2(void* pElemento,char* nombre)
{
    char nombrePiloto[50];
    int retorno=0;
    if(pElemento!=NULL)
    {
        piloto_getNombre(pElemento,nombrePiloto);
        if(strcmp(nombre,nombrePiloto)==0)
        {
            retorno=1;
        }

    }
    return retorno;
}
*/
