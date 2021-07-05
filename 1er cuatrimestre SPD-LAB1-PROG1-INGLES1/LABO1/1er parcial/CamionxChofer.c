
#include "CamionxChofer.h"
void mostrarCamionesYChoferes(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer)
{
    int i;
    int j;
    int flag;
    for(i=0;i<tamChofer;i++)
    {
        if(listaChofer[i].estado==1)
        {
            flag=0;
           printf("CHOFER:    NOMBRE    APELLIDO          DNI      LEGAJO   NACIONALIDAD    TELEFONO   EDAD   SEXO  \n\t");

            mostrarUnChofer(listaChofer[i]);
            printf("\nCAMION/ES: PATENTE   MARCA   ANIO    PESO   CANT_RUEDAS  TIPO \n");
            for(j=0;j<tamCamion;j++)
            {
                if(listaChofer[i].id==listaCamion[j].idChofer && listaCamion[i].estado==1)
                {
                    mostrarSoloCamion(listaCamion[j]);
                    flag=1;

                }
            }
            if(flag==0)
            {
                printf("\tNo tiene ningun camion\n");
            }
            printf("\n------------------------------------------------------------------------------------\n");
        }


    }
}
int cargarCamion(eCamion listadoCamion[],int tamCamion,eChofer listadoChofer[],int tamChofer)
{
  char patente[20];
  char marca[20];
  int anio;
  float peso;
  int cantidadRuedas;
  char tipo[20];
  int estado;
  int id;
  int idChofer;
  int retorno=0;
  int indice;
    indice=buscarLibreCamion(listadoCamion,tamCamion);
    if(indice!=LIBRE)
    {
        retorno=1;
        id=generadorDeIdCamion(listadoCamion,tamCamion);
        id++;
        pedirCadena("ingrese una patente: ","Error al ingresar una patente. Ingrese una patente: ",patente);
        pedirCadena("ingrese una marca: ","Error al ingresar una marca. Ingrese una marca: ",marca);
        anio=pedirEntero("ingrese un anio: ");
        peso=pedirFlotante("ingrese el peso: ");
        cantidadRuedas=pedirEntero("ingrese una cantidad de ruedas: ");
        pedirCadena("ingrese una tipo: ","Error al ingresar una tipo. Ingrese una tipo: ",tipo);
        //verificar luego
        idChofer=asignarChofer(listadoChofer,tamChofer);
        estado=OCUPADO;
        guardarCamion(listadoCamion, tamCamion  ,id,patente,marca,anio,peso,cantidadRuedas,tipo,idChofer,indice,estado);
    }
    return retorno;
}
int asignarChofer(eChofer listado[],int tam)
{
    int idChofer;
    int i;
    int flag=0;

    do
    {printf("CHOFER:    NOMBRE    APELLIDO          DNI      LEGAJO   NACIONALIDAD    TELEFONO   EDAD   SEXO  \n\t");
      mostrarTodosLosChofer(listado,tam);

    idChofer=pedirEntero("ingrese un id de un chofer");
        for(i=0;i<tam;i++)
        {
            if(listado[i].id==idChofer)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("ingrese un id valido\n");
        }
    }while(flag==0);

    return idChofer;
}
void guardarCamion(eCamion lista[], int tam, int id, char patente[],char marca[],int anio,float peso,int cantidadDeRuedas,char tipo[],int idChofer,int i,int estado)
{

    lista[i].id=id;
    strcpy(lista[i].patente,patente);
strcpy(lista[i].marca,marca);
    lista[i].anio=anio;
    lista[i].peso=peso;
    lista[i].cantidadRuedas=cantidadDeRuedas;
    strcpy(lista[i].tipo,tipo);
    lista[i].idChofer=idChofer;
    lista[i].estado=estado;

}

void pedirCadena(char mensaje[], char mensajeError[], char laCadena[])
{
    char auxCadena[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(auxCadena);
    while(strlen(auxCadena)>51)
    {
        char auxCadena[100];
        printf(mensajeError);
        fflush(stdin);
        gets(auxCadena);
    }
    strcpy(laCadena,auxCadena);
}
int pedirFlotante(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}
