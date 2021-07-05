#include "controller.h"
#include "linkedList.h"
#include "piloto.h"
int controller_Rodriguez_loadFromText(char* archivo, LinkedList* pArrayListVuelo)
{

    FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(archivo,"r");
    if(pFile!=NULL && pArrayListVuelo!=NULL)
    {
        vacio=ll_isEmpty(pArrayListVuelo);
        if(vacio==1)
        {
            retorno=parser_vuelo(pFile,pArrayListVuelo);
        }

    }
    fclose(pFile);
    return retorno;
}
int controller_Rodriguez_ListVuelo(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto)
{
    int retorno=-1;
    int i;
    int cantidad;
    Vuelo* vuelo;
    cantidad=ll_len(pArrayListVuelo);
    if(pArrayListVuelo!=NULL)
    {
        retorno=1;
        printf("%8s %8s %8s %16s %16s %16s %16s %16s\n","IdVuelo","IdAvion","IdPiloto","fecha","destino","catnPasajeros","horaDespegue","horaLlegada");

        for(i=0; i<cantidad; i++)
        {
            vuelo=ll_get(pArrayListVuelo,i);
            mostrarUnVuelo(vuelo,pArrayListPiloto);

        }
    }
    return retorno;
}
int controller_Rodriguez_guardarVuelosCortos(char* nombreArchivo,LinkedList* listaVuelo)
{
    FILE* pFile;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int i;
    int retorno=-1;
    Vuelo* vuelo;
    pFile=fopen(nombreArchivo,"w");

    if(listaVuelo!=NULL)
    {
        fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

        for(i=0;i<ll_len(listaVuelo);i++)
        {
            vuelo=ll_get(listaVuelo,i);
            vuelo_getId(vuelo,&idVuelo);
            vuelo_getIdAvion(vuelo,&idAvion);
            vuelo_getIdPiloto(vuelo,&idPiloto);
            vuelo_getFecha(vuelo,fecha);
            vuelo_getDestino(vuelo,destino);
            vuelo_getCantPasajeros(vuelo,&cantPasajeros);
            vuelo_getHoraDespegue(vuelo,&horaDespegue);
            vuelo_getHoraLlegada(vuelo,&horaLlegada);
            fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
         retorno=1;
        }

    }
    fclose(pFile);
    return retorno;
}
void controller_Rodriguez_mostrarListaPortugal(LinkedList* listaVuelo,LinkedList* listaPiloto)
{
    LinkedList* listaPortual;

    listaPortual=ll_newLinkedList();
    listaPortual=ll_filter(listaVuelo,filtrarVuelosPortugal);
    if(listaVuelo!=NULL)
    {
        controller_Rodriguez_ListVuelo(listaPortual,listaPiloto);

    }
}
void controller_Rodriguez_mostrarListaNoAlex(LinkedList* listaVuelo,LinkedList* listaPiloto)
{
    LinkedList* listaNoAlex;

    listaNoAlex=ll_newLinkedList();
    listaNoAlex=ll_filter(listaVuelo,filtrarVuelosNoAlex);
    if(listaVuelo!=NULL)
    {
        controller_Rodriguez_ListVuelo(listaNoAlex,listaPiloto);

    }
}
void controller_Rodriguez_mostrarListFilPil(LinkedList* listaPiloto)
{
    char nombrePiloto[50];
    LinkedList* listFilPiloto;
    printf("Ingrese un nombre:\n");
                    fflush(stdin);

    gets(nombrePiloto);
    if(listaPiloto!=NULL)
    {
        listFilPiloto=ll_newLinkedList();
        listFilPiloto=ll_filter_parametro(listaPiloto,filtrarPiloto,nombrePiloto);
        controller_Rodriguez_listPiloto(listFilPiloto);
        if(ll_len(listFilPiloto)==0)
        {
            printf("Ese piloto no existe\n");
        }
    }
}
int controller_Rodriguez_listPiloto(LinkedList* listaPiloto)
{
    int retorno=-1;
    int i;
    int cantidad;
    Piloto* piloto;
    cantidad=ll_len(listaPiloto);
    if(listaPiloto!=NULL)
    {
        retorno=1;
        printf("%4s%15s\n","Id","Nombre");

        for(i=0; i<cantidad; i++)
        {
            piloto=ll_get(listaPiloto,i);
            mostrarUnPiloto(piloto);

        }
    }
    return retorno;
}
/*void controller_Rodriguez_mostrarListFilVuelosNom(LinkedList* listaPiloto)
{
    char nombrePiloto[50];
    LinkedList* listaFilDeVuelosNom;
    printf("Ingrese un nombre:\n");
    gets(nombrePiloto);
    if(listaPiloto!=NULL)
    {
        listaFilDeVuelosNom=ll_newLinkedList();
        listaFilDeVuelosNom=ll_filter(listaPiloto,filtrarPiloto(listaFilDeVuelosNom,nombrePiloto));
        controller_Rodriguez_listPiloto(listaFilDeVuelosNom);
        if(ll_len(listaFilDeVuelosNom)==0)
        {
            printf("Ese piloto no existe\n");
        }
    }
}*/

int controller_Rodriguez_loadFromTextPiloto(char* archivo, LinkedList* listaPiloto)

{
     FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(archivo,"r");
    if(pFile!=NULL && listaPiloto!=NULL)
    {
        vacio=ll_isEmpty(listaPiloto);
        if(vacio==1)
        {
            retorno=parser_piloto(pFile,listaPiloto);
        }

    }
    fclose(pFile);
    return retorno;
}



/*int controller_Rodriguez_mostrarFiltVuelNomPil(LinkedList* listaVuelo,LinkedList* listaPiloto)
{
      char nombrePiloto[50];
    LinkedList* listFilVueloPilNom;
    printf("Ingrese un nombre:\n");
                    fflush(stdin);

    gets(nombrePiloto);
    if(listaPiloto!=NULL)
    {
        listFilVueloPilNom=ll_newLinkedList();
        listFilVueloPilNom=ll_filter_parametro2(listaVuelo,filtrarPiloto,nombrePiloto,listaPiloto);
        controller_Rodriguez_listPiloto(listFilVueloPilNom);
        if(ll_len(listFilVueloPilNom)==0)
        {
            printf("Ese piloto no existe\n");
        }
    }
}
*/
