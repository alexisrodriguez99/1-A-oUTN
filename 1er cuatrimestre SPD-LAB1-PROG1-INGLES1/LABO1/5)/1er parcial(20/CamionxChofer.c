
#include "CamionxChofer.h"
void mostrarChoferesConCamiones(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer)
{
    int i;
    int j;
    int flag;
    for(i=0;i<tamChofer;i++)
    {
        if(listaChofer[i].estado==1)
        {
            flag=0;
           printf("CHOFER:  ID   NOMBRE    APELLIDO          DNI      LEGAJO   NACIONALIDAD    TELEFONO   EDAD   SEXO  \n\t");

            mostrarUnChofer(listaChofer[i]);
            printf("\nCAMION/ES: PATENTE   MARCA       ANIO  PESO  CANT_RUEDAS     TIPO \n");
            for(j=0;j<tamCamion;j++)
            {
                if(listaChofer[i].id==listaCamion[j].idChofer && listaCamion[j].estado==1)
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
        printf("las marcas disponibles son:\nford de eeuu\nfiat de italia\nvw de alemania");
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
    {printf("CHOFER:\n ID   NOMBRE    APELLIDO          DNI      LEGAJO   NACIONALIDAD    TELEFONO   EDAD   SEXO  \n");
      mostrarTodosLosChofer(listado,tam);

    idChofer=pedirEntero("ingrese un id de un chofer: ");
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

/*void pedirCadena(char mensaje[], char mensajeError[], char laCadena[])
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
}*/
int modificarCamion(eCamion listaCamion[],int tamCamion,eChofer listaChofer[],int tamChofer)
{
    char tipo[20];
    int idChofer;
    int idModificar;
    int indice;
    char confirmar;
    eCamion auxCam;
    int opcion;
    int flag=0;
    int retorno=-1;

        mostrarTodosLosCamiones(listaCamion,tamCamion,listaChofer,tamChofer);
        idModificar=pedirEntero("ingrese el id del camion que desea modificar: ");
        indice=buscarCamion(listaCamion,tamCamion,idModificar);
        auxCam=listaCamion[indice];
        if(indice!=-1)
        {
      /*        do
        {*/
        printf("___________MODIFICAR_____________\n");

        opcion=pedirEntero("1) tipo\n2) chofer\n3) Salir\n");



        system("cls");
        switch(opcion)
        {
            case 1:
            {
                pedirCadena("Ingrese el nuevo tipo: \n","Error. Ingrese un nuevo tipo",tipo);
                strcpy(auxCam.tipo,tipo);
                flag=1;
                break;
            }
            case 2:
            {   printf("DATOS ACTUALES:\n");
                mostrarTodosLosCamiones(listaCamion,tamCamion,listaChofer,tamChofer);
                printf("LISTA DE CHOFERES DISPONIBLES A CAMBIAR\n");
                idChofer=asignarChofer(listaChofer,tamChofer);
                auxCam.idChofer=idChofer;
                flag=1;
                break;
            }
            case 3:
            {
                printf("usted esta saliond de la opcion de modificar un camion....\n");
                flag=0;
                break;
            }
            default:
            {
                printf("No ingreso una opcion valida. Intento de nuevo\n");
                flag=0;
                break;
            }


        }
            if(flag==1);
            {
                 confirmar =pedirCaracter("Esta seguro que desea guardar los  cambios? Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               while(!(confirmar=='s'||confirmar=='n'||confirmar=='N'||confirmar=='S'))
               {
                   confirmar =pedirCaracter("Error.Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               }
                if(confirmar=='s'||confirmar=='S')
                {
                    listaCamion[indice]=auxCam;
                    printf("Se guardaron los datos correctamente\n");
                    retorno=1;
                }
                else
                {
                    printf("No se han realizado las modificaciones\n");
                    retorno=1;
                }
            }
         /*if (flag==2);
            {
                 confirmar =pedirCaracter("Esta seguro que desea guardar los  cambios? Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               while(!(confirmar=='s'||confirmar=='n'||confirmar=='N'||confirmar=='S'))
               {
                   confirmar =pedirCaracter("Error.Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               }
                if(confirmar=='s'||confirmar=='S')
                {
                    listaCamion[indice]=auxCamion;
                    printf("Se guardaron los datos correctamente\n");
                }
                else
                {
                    printf("No se han realizado las modificaciones\n");

                }
            }*/
        system("pause");
        system("cls");
   /* }while(opcion!=3);*/
        }
return retorno;
}
int bajaChofer(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion)
{
    int retorno=-1;
    int idBaja;
    int indice;
    int j;
    //int flag=0;

        mostrarTodosLosChofer(listadoChofer,tamChofer);
        idBaja=pedirEntero("Ingrese el id, del chofer, que desea dar de baja: \n");
        indice=buscarChofer(listadoChofer,tamChofer,idBaja);
        if(indice!=-1)
        {
            // printf("");
            //pedirCaracter("Estas seguro kpo?\n Ingrese s")
            listadoChofer[indice].estado=LIBRE;
            //if(listadoCamion[indice].idChofer==idBaja)
            //printf("Se dio de baja correctament\n");

            for(j=0;j<tamCamion;j++)
            {
                if(idBaja==listadoCamion[j].idChofer && listadoCamion[j].estado==1)
                {
                    listadoCamion[j].estado=LIBRE;
                  //  flag=1;

                }
            }
            retorno=1;
        }



    return retorno;
}
void ordenarPorTipo(eCamion listado[], int tam)
{

    int i;
    int j;
    eCamion auxCamion;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].tipo,listado[j].tipo)>0)
            {
                auxCamion = listado[i];
                listado[i] = listado[j];
                listado[j] = auxCamion;
            }
        }

    }


}

void  mostrarCamionesConChoferes(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer)
{
    ordenarPorTipo(listaCamion,tamCamion);
    mostrarTodosLosCamiones(listaCamion,tamCamion,listaChofer,tamChofer);
}
void choferesConMasUnCamiones(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion)
{
    int i;
    int j;
    int contador;
    printf("CHOFER:\n ID   NOMBRE    APELLIDO          DNI      LEGAJO   NACIONALIDAD    TELEFONO   EDAD   SEXO  \n");

    for(i=0;i<tamChofer;i++)
    {
        if(listadoChofer[i].estado==1)
        {
            contador=0;

            for(j=0;j<tamCamion;j++)
            {
                if(listadoChofer[i].id==listadoCamion[j].idChofer && listadoCamion[j].estado==1)
                {
                    contador++;
                }
            }
            if(contador>1)
            {
            mostrarUnChofer(listadoChofer[i]);
            printf("\ntiene %d camiones",contador);
            printf("\n---------------------------------------------------------------------------------------\n");
            }

        }


    }
}
void camionesConMasAntiguedad(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer)

{
    int i;
    printf("CAMION:\n ID        PATENTE   MARCA       ANIO    PESO  C_RUEDAS     TIPO                 DUNIO\n");

    for(i=0;i<tamCamion;i++)
    {
        if(listaCamion[i].estado==1)
        {
            if(2020-listaCamion[i].anio>10)
            {
                mostrarUnCamion(listaCamion[i],listaChofer,tamChofer);
                printf("\n------------------------------------------------------------------------------------\n");
            }

        }


    }
}
void ordenarChoferMasCamiones(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion)
{
     int i;
    int j;
    int cantidadI;
    int cantidadJ;
    eChofer auxChofer;

     for(i=0; i<tamChofer-1; i++)
    {
        cantidadI=cantidadDeCamiones(listadoChofer,tamChofer,listadoCamion,tamCamion,i);
        for(j=i+1; j<tamChofer; j++)
        {
            cantidadJ=cantidadDeCamiones(listadoChofer,tamChofer,listadoCamion,tamCamion,j);

            if(cantidadI<cantidadJ)
            {
                auxChofer = listadoChofer[i];
                listadoChofer[i] = listadoChofer[j];
                listadoChofer[j] = auxChofer;
            }

        }

    }
}

int cantidadDeCamiones(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion,int indice)
{
    int j;
    int contador;

        if(listadoChofer[indice].estado==1)
        {
            contador=0;

            for(j=0;j<tamCamion;j++)
            {
                if(listadoChofer[indice].id==listadoCamion[j].idChofer && listadoCamion[j].estado==1)
                {
                    contador++;
                }
            }


        }


   return contador;
}
void mostrarChoferMCCamion(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion)
{
    ordenarChoferMasCamiones(listadoChofer,tamChofer,listadoCamion,tamCamion);
    printf("ORDENADO DE MAYOR CANTIDAD A MENOR CANTIDAD\n");
    mostrarTodosLosChofer(listadoChofer,tamCamion);
}
void ordenarChoferCant_Nom(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion)
{
    int i;
    int j;
    int cantidadI;
    int cantidadJ;
    eChofer auxChofer;

     for(i=0; i<tamChofer-1; i++)
    {
        cantidadI=cantidadDeCamiones(listadoChofer,tamChofer,listadoCamion,tamCamion,i);
        for(j=i+1; j<tamChofer; j++)
        {
            cantidadJ=cantidadDeCamiones(listadoChofer,tamChofer,listadoCamion,tamCamion,j);

            if(cantidadI<cantidadJ)
            {
                auxChofer = listadoChofer[i];
                listadoChofer[i] = listadoChofer[j];
                listadoChofer[j] = auxChofer;
            }
            else if(cantidadI==cantidadJ)
            {
                if(stricmp(listadoChofer[i].nombre,listadoChofer[j].nombre)<0)
                {
                    auxChofer = listadoChofer[i];
                    listadoChofer[i] = listadoChofer[j];
                    listadoChofer[j] = auxChofer;
                }
            }
        }

    }
}
void mostrarChoferFullOrden(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion)

{

    ordenarChoferCant_Nom(listadoChofer,tamChofer,listadoCamion,tamCamion);
        printf("ORDENADO DE MAYOR CANTIDAD A MENOR CANTIDAD Y ALFABETICAMENTE\n");

    mostrarTodosLosChofer(listadoChofer,tamChofer);
}
