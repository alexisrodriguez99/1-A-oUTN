#include "funciones.h"
int pedirNumero(char texto[],int* numero)
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
    while(pedirNumero(texto,&aux)!=1 || aux<min || aux>max)
    {

        fflush(stdin);
        printf("\n%s.",textoError);

    }
    *numero=aux;
    return retorno;
}
