#include "funciones.h"

int main()
{
    int numero;
    int retorno;
            //printf("%d\n",numero);

    retorno=guardarNumero(&numero,"Igrese un numero: ","Error al ingresar el numero",-1,1000);
    if(retorno==1)
    {
            printf("%d\n",numero);

    }
    else if(retorno==0)
    {
        printf("ese no es un numero");
    }
   /* retorno=pedirNumero("ingrese un numero: ",&numero);
    if(retorno==1)
    {
            printf("%d",numero);

    }
    else if(retorno==0)
    {
        printf("ese no es un numero");
    }*/
}

