#include "input.h"
void pedirString (char mensaje[],char contenido[], char mensajeDeError[])
{
    char auxString[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(auxString);
    while(strlen(auxString)>50)
    {
        char auxString[100];
        printf(mensajeDeError,mensaje);
        fflush(stdin);
        gets(auxString);
    }
    strcpy(contenido,auxString);
}

int pedirEntero (char mensaje[])
{
    int numero;
    printf("%s",mensaje);;
    scanf("%d",&numero);

    return numero;
}

char pedirCaracter (char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}

//VERIFICA QUE TODOS LOS CARACTERES DEL NUMERO SEAN NUMEROS
/*int esNumero(char mensaje[])
{
    int i;
    int retorno = 1;

    for(i = 0; i < strlen(mensaje); i++)
    {
        if(mensaje[i] < '0' || mensaje[i] > '9')//si no es un numero devuelve 0
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}*/
