#include "camiones.h"

void hardCodearCamion(eCamion listado[],int tam)
{
  char patente[10][20]={"aaa-111","aab-111","aac-111","aad-111","aae-111","aaf-111","aag-111","aah-111","aai-111","aaj-111"};
  char marcas[10][20]={"ford","ford","fiat","fiat","wv","ford","ford","ford","ford","ford"};
  int anio[10]={2000,2000,2000,2010,2005,2005,2015,2000,2000,2000};
  float peso[10]={50,50,60,40,50,60,60,70,40,60};
  int cantidadRuedas[10]={4,4,4,4,4,4,4,4,4,4};
  char tipo[10][20]={"cortaDistancia","cortaDistancia","cortaDistancia","cortaDistancia","cortaDistancia","largaDistancia","largaDistancia","largaDistancia","largaDistancia","largaDistancia"};
  int estado[10]={1,1,1,1,1,1,1,1,1,1};
  int id[10]={1,2,3,4,5,6,7,8,9,10};
  int idChofer[10]={1,1,2,2,3,4,4,5,5,5};
  int i;
  for(i=0; i<tam; i++)
    {
        strcpy(listado[i].patente, patente[i]);
        strcpy(listado[i].marca, marcas[i]);

        listado[i].anio = anio[i];

        listado[i].peso = peso[i];

        listado[i].cantidadRuedas = cantidadRuedas[i];
         strcpy(listado[i].tipo, tipo[i]);

        listado[i].id = id[i];

        listado[i].estado = estado[i];
        listado[i].idChofer = idChofer[i];

    }
}
void mostrarUnCamion (eCamion listado,eChofer chofer[],int tamChofer)
{
    eChofer auxChofer;
    auxChofer=buscarChoferId(chofer,tamChofer,listado.idChofer);
    printf("%2d %15s %8s %10d\t %.2f %5d %18s ",listado.id,listado.patente,listado.marca,listado.anio,listado.peso,listado.cantidadRuedas,listado.tipo);
    mostrarNombreChofer(auxChofer);
}
void mostrarTodosLosCamiones (eCamion listado[], int tam,eChofer chofer[], int tamChofer)
{
    int i;

   for(i=0; i<tam; i++)
   {
        if(listado[i].estado==1)
            {
               mostrarUnCamion(listado[i],chofer,tamChofer);
           }
   }
}

void mostrarSoloCamion(eCamion listado)
{
    printf("%2d %15s %8s %10d\t %.2f %5d %18s \n",listado.id,listado.patente,listado.marca,listado.anio,listado.peso,listado.cantidadRuedas,listado.tipo);
}
void inicializarCamion(eCamion listado[], int tam)
{

    int i;

        for(i=0; i<tam; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].id=10;

        }
}
int buscarLibreCamion(eCamion listado[],int tam)
{
    int i;
    int indice=-1;


        for(i=0; i<tam; i++)
        {
            if( listado[i].estado==LIBRE)
            {
                indice=i;
                break;
            }
        }


    return indice;
}

int generadorDeIdCamion(eCamion listado[],int tam)
{
    int i;
    int idMayor;
    int flag=0;
    for(i=0; i<tam; i++)//ver con i==0
    {
        if(flag==0 || listado[i].id>idMayor)
        {
            idMayor=listado[i].id;


            flag=1;

        }
    }
    return idMayor;
}

int bajaCamion(eCamion listadoCamion[],int tamCamion,eChofer listadoChofer[],int tamChofer)
{
    int retorno=-1;
    int idBaja;
    int indice;


        mostrarTodosLosCamiones(listadoCamion,tamCamion,listadoChofer,tamChofer);
        idBaja=pedirEntero("Ingrese el id, del camion, que desea dar de baja: \n");
        indice=buscarCamion(listadoCamion,tamCamion,idBaja);
        if(indice!=-1)
        {
            listadoCamion[indice].estado=LIBRE;
            retorno=1;
        }



    return retorno;
}
int buscarCamion(eCamion listado[],int tam,int id)
{
    int retorno=-1;
    int i;

        for(i=0; i<tam; i++)
        {
            if(id==listado[i].id && listado[i].estado==OCUPADO)
            {
                retorno=i;
            }
        }




    return retorno;
}
/*int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;

}*/
int pedirMarca(eCamion listado[],int tam)
{
    char marca[20];
    int retorno=-1;
    int i;
    pedirCadena("ingrese una cadena: ","error, ingrese una cadena: ",marca);
    printf("CAMION:\n ID        PATENTE   MARCA       ANIO    PESO  C_RUEDAS     TIPO\n ");
    for(i=0;i<tam;i++)
    {
        if(strcmp(listado[i].marca,marca)==0)
        {
            mostrarSoloCamion(listado[i]);
            retorno=1;
        }
    }
   return retorno;
}
float promedioAnios(eCamion listado[],int tam)
{
    int i;
    int acumulador=0;
    int cantidad=0;
    float promedio=0;

    for(i=0;i<tam;i++)
    {
        if( listado[i].estado==OCUPADO)
        {
            acumulador=2020-listado[i].anio+acumulador;
            cantidad++;
        }

    }
    if(cantidad!=0)
    {
        promedio=acumulador/(float)cantidad;
    }
    return promedio;
}
void mostrarPromedioAnios(eCamion listado[],int tam)
{
    float promedio;
   promedio= promedioAnios(listado,tam);
    printf("el promedio de anios de antiguedad es: %f\n",promedio);
}
