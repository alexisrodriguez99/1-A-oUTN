#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct

{
    char nombre[50];
    int edad;
}Alumnos;
void hardcodeo(Alumnos* alumnos);
int alumno_setNombre(Alumnos* alumno,char* nombre);
int alumno_getNombre(Alumnos* alumno,char* nombre);

int alumno_setEdad(Alumnos* alumno,int edad);
int alumno_getEdad(Alumnos* alumno,int* edad);

Alumnos* alumno_new();
void mostrarAlumnos(Alumnos* alumno);
void mostrarTodos(Alumnos* alumno);


int ordenarNombre(void*,void*);
int ordenarEdad(void*,void*);

void ordenar(Alumnos* alumno,int (*pFunc)(void*,void*));


int main()
//
{
 Alumnos* alumnos;
alumnos = (Alumnos*)calloc(5,sizeof(Alumnos)*5);
 hardcodeo(alumnos);
mostrarTodos(alumnos);


ordenar(alumnos,ordenarEdad);

mostrarTodos(alumnos);

}
void hardcodeo(Alumnos* alumnos)
{

 int i;
 char nombre[5][50]={"Alf","AAAA","EEEE","Lucas","BBBB"};
 int edad[5]={15,19,20,13,11};
 for(i=0;i<5;i++)
 {
   //alumnos=alumno_new();

  (alumnos+i)->edad=edad[i];

  strcpy((alumnos+i)->nombre,nombre[i]);
}
}
Alumnos* alumno_new()
{
    return (Alumnos*) malloc(sizeof(Alumnos));
}
void mostrarAlumnos(Alumnos* alumno)
{
//char  nombre[50];
    //int edad;
//printf("%d",alumno[0]->edad);
    printf("%d %s\n",alumno->edad,alumno->nombre);
}
void mostrarTodos(Alumnos* alumno)
{
    int i;
    printf("Edad  Nombre\n");
    for(i=0;i<5;i++)
    {
        mostrarAlumnos(alumno+i);
    }
}
int ordenarNombre(void* nombre1,void* nombre2)
{
    Alumnos* alumno1;
    Alumnos* alumno2;

    alumno1=(Alumnos*)nombre1;
    alumno2=(Alumnos*)nombre2;

    char alum1[50];
    char alum2[50];
    int retorno=0;
    alumno_getNombre(alumno1,alum1);
    alumno_getNombre(alumno2,alum2);
    if(strcmp(alum1,alum2)>0)
    {
        retorno=1;
    }
    return retorno;
}

int ordenarEdad(void* a1,void* a2)
{
    Alumnos* alumno1;
    Alumnos* alumno2;

    alumno1=(Alumnos*)a1;
    alumno2=(Alumnos*)a2;

    int alum1;
    int alum2;
    int retorno=0;
    alumno_getEdad(alumno1,&alum1);
    alumno_getEdad(alumno2,&alum2);
    if(alum1>alum2)
    {
        retorno=1;
    }
    return retorno;
}


void ordenar(Alumnos* alumno,int (*pFunc)(void*,void*))
{
    int i;
    int j;

    Alumnos aux;

    for(i=0;i<5-1;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(pFunc(alumno+i,alumno+j)>0)
            {
                aux=alumno[i];
                alumno[i]=alumno[j];
                alumno[j]=aux;

            }
        }
    }
}

int alumno_setNombre(Alumnos* alumno,char* nombre)
{
    int retorno=1;
    if(alumno!=NULL)
    {
        strcpy(alumno->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int alumno_getNombre(Alumnos* alumno,char* nombre)
{
   int retorno=1;
    if(alumno!=NULL)
    {
        strcpy(nombre,alumno->nombre);
        retorno=1;
    }
    return retorno;
}

int alumno_setEdad(Alumnos* alumno,int edad)
{
    int retorno=1;
    if(alumno!=NULL)
    {
        alumno->edad=edad;
        retorno=1;
    }
    return retorno;
}
int alumno_getEdad(Alumnos* alumno,int* edad)
{
    int retorno=1;
    if(alumno!=NULL)
    {
        *edad=alumno->edad;
        retorno=1;
    }
    return retorno;
}
