#include "choferes.h"
#include <stdio.h>
#include <stdlib.h>
void hardCodearChofer(eChofer listado[],int tam)
{
    char nombre[6][20]={"Lucrecia","Jorge","Natalia","Matias","Jeremias","Juan"};
    char apellido[6][20]={"apellido1","apellido2","apellido3","apellido4","apellido5","apellido6"};
  char dni[6][20]={"11111111","22222222","33333333","44444444","55555555","666666666"};
  int legajo[6]={1,2,3,4,5,6};
  char nacionalidad[6][20]={"Nacionalidad1","Nacionalidad2","Nacionalidad3","Nacionalidad4","Nacionalidad5","Nacionalidad6"};
  char telefono[6][20]={"13414325","54314325","13416665","5554325","9874325","99014325"};
  int edad[6]={30,35,40,38,39,30};
  char sexo[6]={'f','m','f','m','m','m'};
  int estado[6]={1,1,1,1,1,1};
  int id[6]={1,2,3,4,5,6};
  int i;
  for(i=0; i<tam; i++)
    {
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].apellido, apellido[i]);

        strcpy(listado[i].dni, dni[i]);
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nacionalidad, nacionalidad[i]);
        strcpy(listado[i].telefono, telefono[i]);
        listado[i].edad = edad[i];
        listado[i].sexo= sexo[i];
        listado[i].id = id[i];

        listado[i].estado = estado[i];

    }
}
void mostrarUnChofer (eChofer listado)
{
    printf("%10s %10s %15s %5d %18s %10s %5d %5c \n",listado.nombre,listado.apellido,listado.dni,listado.legajo,listado.nacionalidad,listado.telefono,listado.edad,listado.sexo);
}
void mostrarTodosLosChofer (eChofer listado[], int tam)
{
    int i;

   for(i=0; i<tam; i++)
   {
        if(listado[i].estado==1){
               mostrarUnChofer(listado[i]);
           }
   }
}
eChofer buscarChoferId(eChofer lista[],int tam, int idChofer)
{
    eChofer auxChofer={"no existe","no existe","no existe",1,"no existe","no existe",2222,'s',3,4};
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].id==idChofer)
        {
            auxChofer=lista[i];
            break;
        }
    }
    return auxChofer;
}
void mostrarNombreChofer(eChofer listado)
{
        printf("%15s\n",listado.nombre);
}
int cargarChofer(eChofer listado[],int tam)
{
    char nombre[20];
    char apellido[20];
  char dni[20];
  int legajo;
  char nacionalidad[20];
  char telefono[20];
  int edad;
  char sexo;
  int estado;
  int id;
  int retorno=-1;
  int indice;

  indice=buscarLibreChofer(listado,tam);
  if(indice!=LIBRE)
  {
      id=generadorDeIdChofer(listado,tam);
        id++;
        pedirCadena("ingrese un nombre","Error, ingrese un nombre",nombre);
        pedirCadena("ingrese un apellido","Error, ingrese un apellido",apellido);
        pedirCadena("ingrese un dni","Error, ingrese un dni",dni);
        legajo=pedirEntero("ingrese un legajo");
        pedirCadena("ingrese una nacionalidad","Error, ingrese una nacionalidad",nacionalidad);
        pedirCadena("ingrese un telefono","Error, ingrese un telefono",telefono);
        edad=pedirEntero("ingrese una edad");
        sexo=pedirCaracter("ingrese un sexo 'f'(femenino) o 'm' (masculino)");
        estado=OCUPADO;
        guardarChofer(listado,nombre,apellido,dni,legajo,nacionalidad,telefono,edad,sexo,estado,indice);
        retorno=1;

  }
    return retorno;

}
void guardarChofer(eChofer listado[],char nombre[],char apellido[],char dni[],int legajo, char nacionalidad[],char telefono[],int edad,char sexo,int estado,int indice)
{
 strcpy(listado[indice].nombre,nombre );
 strcpy(listado[indice].apellido,apellido );
 strcpy(listado[indice].dni,dni );
 listado[indice].legajo=legajo;
 strcpy(listado[indice].nacionalidad,nacionalidad );
  strcpy(listado[indice].telefono,telefono );
 listado[indice].edad=edad;
 listado[indice].sexo=sexo;
 listado[indice].estado=estado;


}
int buscarLibreChofer(eChofer listado[],int tam)
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
int inicializarChofer(eChofer listado[], int tam)
{
    int i;
    int retorno=-1;

        for(i=0; i<tam; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].id=6;

        }
        retorno=1;

    return retorno;
}
int generadorDeIdChofer(eChofer listado[],int tam)
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
}*/
/*int pedirFlotante(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}*/
/*int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;

}*/
char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}

