#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int edad;
}Alumno;
int ordenar(Alumno* this, int (*pFunc)(int,int), int cantidad);
int funcionOrdenar(int a1,int a2);

int main()
{
    //printf("Hello world!\n");
    Alumno* alumno;
    alumno[4]={{"Amelia",15},{"Juan",27},{"Manuel",16},{"Ana",19}};
    alumno=(Alumno*)malloc(sizeof(*Alumno)*4);
    ordenar(alumno,funcionOrdenar(),4);
    return 0;
}
int ordenar(Alumno* alumno, int (*pFunc)(int,int),int cantidad )
{
    int returnAux =-1;
    Alumno* aux;
    int j;
    int i;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(pFunc(i,j)==1)
            {
                aux=alumno[i];
                alumno[i]=alumno[j];
                alumno[j]=aux;

            }
        }
    }
    returnAux=0;


    return returnAux;
}
int funcionOrdenar(int a1,int a2)
{
    int retorno=0;
    Alumno* alumno1;
    Alumno* alumno2;

    if((strcmp(alumno1[a1]->nombre,alumno2[a2]->nombre)>0)
       {
           retorno=1;
       }
    else if(strcmp(alumno1[a1]->nombre,alumno2[a2]->nombre)==0)
    {
        if(alumno1[a1]->edad<alumno2[a2]->edad)
        {
            retorno=1;
        }
    }
    return retorno;
}

/*
la memoria se divide en 4 segmentos, estos son el heap donde se encuantra lo que denominamos memoria dinamica (para poder acceder a esa memoria
usamos los punteros que son creados en la pila que a apuntan a esa direccion de memoria),
la pila en donde estan los llamados a funciones y sus parametros, la memoria estatida es donde se encuentran las variables globales
y por utimo el segmento codigo que es donde se guarda nuestro codigo en lenguaje maquina(binario).

tanto el malloc como el realloc nos permiten reservar espacio en memoria con la diferencia que el realloc se utiliza cuando
queremos modificar el tamaña de dicha memoria ya sea para aumentar o dismonuir ese tamaño.

*/
