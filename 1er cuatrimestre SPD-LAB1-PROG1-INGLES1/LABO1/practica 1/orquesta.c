#include "orquesta.h"
#include "input.h"


void hardcodearOrquestas(eOrquesta lista[])
{
    char nombre[3][20]={"nombre1","nombre2","nombre3"};
    char lugar[3][20]={"lugar1","lugar2","lugar3"};
    int tipo[3]={1,2,3};
    int id[3]={1,2,3};
    int estado[3]={1,1,1};
    int i;
    for(i=0;i<3;i++)
    {
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].lugar,lugar[i]);
        lista[i].tipo=tipo[i];
        lista[i].id=id[i];
        lista[i].estado=estado[i];

    }
}
void mostrarOrquesta(eOrquesta lista[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            mostrarUnaOrquesta(lista[i]);
        }
    }
}
void mostrarUnaOrquesta(eOrquesta lista)
{

    if(lista.tipo==1)
    {

    printf("%d\t\t %s\t\t %s\t \t sinfonica\n",lista.id,lista.nombre,lista.lugar);

    }
    else if(lista.tipo==2)
    {
    printf("%d\t\t %s\t\t %s\t \t filarmonica\n",lista.id,lista.nombre,lista.lugar);

    }
    else
    {
    printf("%d\t\t %s\t\t %s\t \t camara\n",lista.id,lista.nombre,lista.lugar);

    }


}
/*eOrquesta crearOrquesta(void)
{
    eOrquesta unaOrquesta;
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s",unaOrquesta.nombre);

    printf("Lugar: ");
    fflush(stdin);
    scanf("%s",unaOrquesta.lugar);

    printf("Tipo: ");
    scanf("%d",&unaOrquesta.tipo);
    unaOrquesta.estado=1;
    return unaOrquesta;


}*/
int buscarLibre(eOrquesta lista[],int tam)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==-1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int cargarUnaOrquesta(eOrquesta lista[],int tam)
{
    char nombre[20];
    char lugar[20];
    int tipo;
    int id;
    int indice;
    int estado;
    int retorno;
    indice=buscarLibre(lista,tam);
    if(indice!=-1)
    {
        id=dameMayorID(lista,tam);
            id++;
        pedirString("ingrese el nombre de la orquesta: ",nombre," error, ingrese un nombre valido");
        pedirString("ingrese el nombre del lugar: ",lugar," error, ingrese un nombre valido");
        tipo=pedirEntero("ingrese el tipo: ");

        estado=1;
        guardarOrquesta( lista,nombre,lugar,tipo,id,indice,estado);

        /*lista[indice]=crearOrquesta();*/
        retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}
void inicializar(eOrquesta lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado=-1;
        lista[i].id=0;
    }
}
void guardarOrquesta(eOrquesta lista[], char nombre[], char lugar[], int tipo, int id, int indice,int estado)
{

    strcpy(lista[indice].nombre,nombre);
        strcpy(lista[indice].lugar,lugar);
        lista[indice].tipo=tipo;
        lista[indice].id=id;
        lista[indice].estado=estado;
}

int dameMayorID (eOrquesta lista[],int tam)
{
    int i;
    int flag=0;
    int idMayor;
    for(i=0; i<tam; i++)
    {
        if(flag==0||lista[i].id>idMayor)
        {
            idMayor=lista[i].id;
            flag=1;
        }
    }
    return idMayor;
}
