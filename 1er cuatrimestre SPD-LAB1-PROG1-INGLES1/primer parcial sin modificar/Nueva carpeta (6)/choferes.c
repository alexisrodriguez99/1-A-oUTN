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
    printf("%2d %10s %10s %15s %5d %18s %10s %5d %5c \n",listado.id,listado.nombre,listado.apellido,listado.dni,listado.legajo,listado.nacionalidad,listado.telefono,listado.edad,listado.sexo);
}
void mostrarTodosLosChofer (eChofer listado[], int tam)
{
    int i;
    printf(" ID    NOMBRE  APELLIDO          DNI      LEGAJO     NACIONALIDAD   TELEFONO   EDAD SEXO\n");
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

        guardarCadenaSoloLetras(nombre,"Ingrese un nombre: ","Error al ingresar el nombre. ",20);
        guardarCadenaSoloLetras(apellido,"Ingrese un apellido: ","Error al ingresar el apellido. ",20);
        guardarCadenaSoloNumeros(dni,"Ingrese un dni: ","Error al ingresar el dni. ",8);

        guardarNumero(&legajo,"Ingrese un legajo: ","Error al ingresar un legajo. ",0,999);
        guardarCadenaSoloLetras(nacionalidad,"Ingrese una nacionalidad: ","Error al ingresar una nacionalidad. ",20);
        guardarCadenaSoloNumeros(telefono,"Ingrese un telefono: ","Error al ingresar el telefono. ",8);
           // pedirCadena("telefono: ","ere",telefono);
   // edad=pedirEntero("edad");
        guardarNumero(&edad,"Ingrese una edad: ","Error al ingresar una edad. ",0,150);
        listado[indice].edad=edad;

        guardarSexo(&sexo,"ingrese un sexo 'f'(femenino) o 'm' (masculino): ","Error al ingresar el sexo. ");
        estado=OCUPADO;
        guardarChofer(listado,nombre,apellido,dni,legajo,nacionalidad,telefono,edad,sexo,estado,indice,id);


        retorno=1;

  }
    return retorno;

}
void guardarChofer(eChofer listado[],char nombre[],char apellido[],char dni[],int legajo, char nacionalidad[],char telefono[],int edad,char sexo,int estado,int indice,int id)
{
   // printf("%d",edad);
listado[indice].id=id;
 strcpy(listado[indice].nombre,nombre );
 strcpy(listado[indice].apellido,apellido );
 strcpy(listado[indice].dni,dni );
 // listado[indice].edad=*edad;

 listado[indice].legajo=legajo;
 strcpy(listado[indice].nacionalidad,nacionalidad );
  strcpy(listado[indice].telefono,telefono );

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
int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;

}
char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}
int buscarChofer(eChofer listado[],int tam,int id)
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
int modificarChofer(eChofer listado[],int tam)
{
    char nombre[20];
    char apellido[20];
  char dni[20];
  int legajo;
  char nacionalidad[20];
  char telefono[20];
  int edad;
  char sexo;
  int retorno=-1;
  int opcion;
  char confirmar;
  int idModificar;
  int indice;
  eChofer auxChofer;
        mostrarTodosLosChofer(listado,tam);
        idModificar=pedirEntero("ingrese el id del chofer que desea modificar: ");
        //guardarNumero(&idModificar,"Ingrese el id, del chofer, que desea modificar: ","Error al ingresar el id del chofer. ",0,90);
        indice=buscarChofer(listado,tam,idModificar);
        auxChofer=listado[indice];
        if(indice!=-1)
        {

            opcion= pedirEntero("¡Que desea modificar!\n1) Nombre:\n2) Apellido\n3) DNI\n4) Legajo\n5) Nacionalidad\n6) Telefono\n7) Edad\n8) Sexo\n9) Salir\n");
            switch(opcion)
            {            retorno=1;

            case 1:
            {
                //pedirCadena("Ingrese el nuevo nombre: ","Error. Ingrese un nuevo nombre",nombre);
                guardarCadenaSoloLetras(nombre,"Ingrese el nuevo nombre: ","Error al ingresar el nombre. ",20);
                strcpy(auxChofer.nombre,nombre);
                 retorno=1;
                break;
            }
            case 2:
            {
                //pedirCadena("Ingrese el nuevo apellido: ","Error. Ingrese un nuevo apellido",apellido);
                guardarCadenaSoloLetras(apellido,"Ingrese el nuevo apellido: ","Error al ingresar el apellido. ",20);
                strcpy(auxChofer.apellido,apellido);
                 retorno=1;
                break;
            }
            case 3:

            {
                //pedirCadena("Ingrese el nuevo dni: ","Error. Ingrese un nuevo dni",dni);
                guardarCadenaSoloNumeros(dni,"Ingrese el nuevo dni: ","Error al ingresar el dni. ",8);
                strcpy(auxChofer.dni,dni);
                 retorno=1;
                break;

            }
            case 4:
            {
                //legajo=pedirEntero("ingrese el nuevo legajo: ");
                guardarNumero(&legajo,"Ingrese el nuevo legajo: ","Error al ingresar el legajo. ",0,999);
                auxChofer.legajo=legajo;
                 retorno=1;
                break;

            }
            case 5:
                {
                    //pedirCadena("Ingrese la nueva nacionalidad: ","Error. Ingrese la nueva nacionalidad",nacionalidad);
                guardarCadenaSoloLetras(nacionalidad,"Ingrese la nueva nacionalidad: ","Error al ingresar la nacionalidad. ",20);
                strcpy(auxChofer.nacionalidad,nacionalidad);
                 retorno=1;
                break;
                }
                case 6:
                {
                    //pedirCadena("Ingrese el nuevo telefono: ","Error. Ingrese el nuevo telefono",telefono);
                    guardarCadenaSoloNumeros(telefono,"Ingrese el nuevo telefono: ","Error al ingresar el telefono. ",8);

                strcpy(auxChofer.telefono,telefono);
                 retorno=1;
                break;
                }
                case 7:
                {
                   //edad=pedirEntero("ingrese la nuevo edad: ");
                   guardarNumero(&edad,"Ingrese la nueva edad: ","Error al ingresar la edad. ",0,150);
                auxChofer.edad=edad;
                 retorno=1;
                break;
                }
                case 8:
                {
                    //sexo=pedirCaracter("ingrese el nuevo sexo: ");
                    guardarSexo(&sexo,"Ingrese el nuevo sexo: ","Error al ingresar el sexo. ");
                    auxChofer.sexo=sexo;
                     retorno=1;
                break;
                }
                case 9:
                {
                    printf("Usted esta saliendo");
                break;
                }

            default:
            {
                printf("Opcion invalida");
            }
            }
            if(retorno==1)
            {
               confirmar =pedirCaracter("Esta seguro que desea guardar los  cambios? Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               while(!(confirmar=='s'||confirmar=='n'||confirmar=='N'||confirmar=='S'))
               {
                   confirmar =pedirCaracter("Error.Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               }
                if(confirmar=='s'||confirmar=='S')
                {
                    listado[indice]=auxChofer;
                    printf("Se guardaron los datos correctamente\n");
                }
                else
                {
                    printf("No se han realizado las modificaciones\n");

                }
            }
        }
        system("pause");
        system("cls");
        return retorno;

}
float promedioEdad(eChofer listado[],int tam)
{
    int i;
    int acumulador=0;
    int cantidad=0;
    float promedio=0;

    for(i=0;i<tam;i++)
    {
        if( listado[i].estado==OCUPADO)
        {
            acumulador=acumulador+listado[i].edad;
            cantidad++;
        }

    }
    if(cantidad!=0)
    {
        promedio=acumulador/(float)cantidad;
    }
    return promedio;
}
void mostrarPromedio(eChofer listado[],int tam)
{
    float promedio;
    promedio=promedioEdad(listado,tam);
    printf("el promedio de las edades de los choferes: %.2f\n",promedio);
}
float promedioMasculino(eChofer listado[],int tam)
{
    int i;
    int cantidadM=0;
    int cantidad=0;
    float promedio=0;

    for(i=0;i<tam;i++)
    {
        if( listado[i].estado==OCUPADO)
        {
            if(listado[i].sexo=='m')
            {
                cantidadM++;
            }
            cantidad++;
        }

    }
    if(cantidad!=0)
    {
        promedio=cantidadM/(float)cantidad;
    }
    return promedio;
}
float promedioFemenino(eChofer listado[],int tam)
{
    int i;
    int cantidadF=0;
    int cantidad=0;
    float promedio=0;

    for(i=0;i<tam;i++)
    {
        if( listado[i].estado==OCUPADO)
        {
            if(listado[i].sexo=='f')
            {
                cantidadF++;
            }
            cantidad++;
        }

    }
    if(cantidad!=0)
    {
        promedio=cantidadF/(float)cantidad;
    }
    return promedio;
}
void mostrarPromedioMyF(eChofer listado[],int tam)
{
    float promedioM;
    //float promedioF;

    //promedioF=promedioFemenino(listado,tam);
    promedioM=promedioMasculino(listado,tam);

    printf("el promedio de los varones es: %f ",promedioM);//y el promedio de los mujeres es %fpromedioF
}
//funciones de pedir datos
int pedirNumero1(char texto[],int* numero)
{
    int retorno=0;
    char aux[100];
    printf("%s",texto);
    fflush(stdin);
   // scanf("%s",aux);
   gets(aux);
    if(validarNumero(aux)==1)
    {
        *numero=atoi(aux);
        retorno=1;
    }


    return retorno;
}
int validarNumero(char cadena[])
{
    int cantidad;
    int retorno=1;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0)
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') /*&& cadena[0]==""*/)
        {
            retorno=0;
            break;
        }
    }
    return retorno;

}
int guardarNumero(int* numero,char texto[],char textoError[],int min,int max)
{
    int aux;
    int retorno=1;
    while(pedirNumero1(texto,&aux)!=1 || aux<min || aux>max)
    {

        fflush(stdin);
        printf("\n%s.",textoError);

    }
    *numero=aux;
    return retorno;
}
int pedirFlotante1(char mensaje[],float* numero)
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
   // scanf("%s",aux);
   gets(aux);
    if(validarFlotante(aux)==1)
    {
        *numero=atof(aux);
        retorno=1;
    }


    return retorno;
}
int validarFlotante(char cadena[])
{
    int cantidad;
    int retorno=1;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 || cadena[0]=='.')
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && cadena[i]!='.')
        {
            retorno=0;
            break;
        }
    }
    return retorno;

}
int guardarFlotante(float* numero,char mensaje[],char mensajeError[],int min,int max)
{
    float aux;
    int retorno=1;
    while(pedirFlotante1(mensaje,&aux)!=1 || aux<min || aux>max)
    {

        fflush(stdin);
        printf("\n%s.",mensajeError);

    }
    *numero=aux;
    return retorno;
}

int pedirCadena1(char cadena[],char mensaje[])
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(validarCadenaSoloLetras(aux)==1)
    {
        strcpy(cadena,aux);
        retorno=1;
    }

    return retorno;
}
int validarCadenaSoloLetras(char cadena[])
{
    int retorno=1;
    int cantidad;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 )
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
return    retorno;
}
int guardarCadenaSoloLetras(char cadena[],char mensaje[],char mensajeError[],int tam)
{
    char aux[100];
    int retorno=1;
    while(pedirCadena1(aux,mensaje)!=1 ||strlen(aux)>tam )
    {
        fflush(stdin);
        printf("\n%s.",mensajeError);
    }
    strcpy(cadena,aux);
    return retorno;
}

int pedirCadenaLetras_Num(char cadena[],char mensaje[])
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(validarCadenaLetras_Num(aux)==1)
    {
        strcpy(cadena,aux);
        retorno=1;
    }

    return retorno;
}
int validarCadenaLetras_Num(char cadena[])
{
    int retorno=1;
    int cantidad;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 )
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'0' || cadena[i]>'9'))
        {
            retorno=0;
            break;
        }
    }
return    retorno;
}
int guardarCadenaletras_Num(char cadena[],char mensaje[],char mensajeError[],int tam)
{
    char aux[100];
    int retorno=1;
    while(pedirCadenaLetras_Num(aux,mensaje)!=1 ||strlen(aux)>tam )
    {
        fflush(stdin);
        printf("\n%s.",mensajeError);
    }
    strcpy(cadena,aux);
    return retorno;
}

int pedirCadenaSoloNumeros(char cadena[],char mensaje[])
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(validarCadenaSoloNumeros(aux)==1)
    {
        strcpy(cadena,aux);
        retorno=1;
    }

    return retorno;
}
int validarCadenaSoloNumeros(char cadena[])
{
    int retorno=1;
    int cantidad;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 )
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9'))
        {
            retorno=0;
            break;
        }
    }
return    retorno;
}
int guardarCadenaSoloNumeros(char cadena[],char mensaje[],char mensajeError[],int tam)
{
    char aux[100];
    int retorno=1;
    while(pedirCadenaSoloNumeros(aux,mensaje)!=1 ||strlen(aux)>tam )
    {
        fflush(stdin);
        printf("\n%s.",mensajeError);
    }
    strcpy(cadena,aux);
    return retorno;
}

int pedirSexo(char cadena[],char mensaje[])
{
    int retorno=0;
    char aux[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    if(validarSexo(aux)==1)
    {
        strcpy(cadena,aux);
        retorno=1;
    }

    return retorno;
}
int validarSexo(char cadena[])
{
    int retorno=1;
    int cantidad;
    int i;
    cantidad=strlen(cadena);
    if(cantidad==0 )
    {
        retorno=0;
        return retorno;
    }
    for(i=0;i<cantidad;i++)
    {
        if((cadena[i]!='f' &&  cadena[i]!='m') && (cadena[i]!='F' &&  cadena[i]!='M'))
        {
            retorno=0;
            break;
        }
    }
return    retorno;
}
int guardarSexo(char cadena[],char mensaje[],char mensajeError[])
{
    char aux[100];
    int retorno=1;
    while(pedirSexo(aux,mensaje)!=1 ||strlen(aux)>1 )
    {
        fflush(stdin);
        printf("\n%s.",mensajeError);
    }
    strcpy(cadena,aux);
    return retorno;
}

