#include "Piloto.h"

void hardcodearPilotos(LinkedList* this)
{
    Piloto* piloto[5];

    int idPiloto[5] = {1, 2, 3, 4, 5};
    char nombre[5][100] = {"Alex Lifeson", "Richard Bach", "John Kerry", "Erwin Rommel", "Stephen Coonts"};

    for(int i = 0; i < 5; i++)
    {
        piloto[i] = Piloto_new();
        piloto[i]->idPiloto = idPiloto[i];
        strcpy(piloto[i]->nombre, nombre[i]);

        ll_add(this, piloto[i]);
    }
}
void* Piloto_new()
{
    return (Piloto*) malloc(sizeof(Piloto));
}
void Piloto_Mostrar(Piloto* this)
{
    int id;
    char nombre[129];

    if(this != NULL)
    {
        Piloto_getId(this, &id);
        Piloto_getNombre(this, nombre);

        printf("\n%4d|\t %14s|", id, nombre);
    }
}
void Piloto_listar(LinkedList* this)
{
    Piloto* aux;
    int size;

    if(this != NULL && !ll_isEmpty(this))
    {
        size = ll_len(this);
        if(size > 0)
        {
            for(int i = 0; i < size; i++)
            {
                aux = (Piloto*)ll_get(this, i);
                Piloto_Mostrar(aux);
            }
        }

    }
}
int Piloto_setNombre(Piloto* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int Piloto_setId(Piloto* this, int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idPiloto = id;
        retorno = 0;
    }
    return retorno;
}
int Piloto_getNombre(Piloto* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
int Piloto_getId(Piloto* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->idPiloto;
        retorno = 0;
    }
    return retorno;
}
int Piloto_buscarPorId(LinkedList* lista, int id)
{
    int retorno = -1;
    int idBuscar;
    Piloto* aux;
    if(lista != NULL && ll_len(lista) > 0)
    {
        retorno = -2;
        for(int i = 0; i < ll_len(lista); i++)
        {
            aux = ll_get(lista, i);
            Piloto_getId(aux, &idBuscar);
            if(idBuscar == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
