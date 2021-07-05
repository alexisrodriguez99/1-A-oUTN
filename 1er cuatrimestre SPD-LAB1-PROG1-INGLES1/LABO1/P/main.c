#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define CANT 20

typedef struct
{
    int id;
    float precio;
    char procesador[CANT];
    char marca[CANT];
} eNotebook;
void ordenar(eNotebook lista[],int tam);
float aplicarAumento( float valor, int porcentaje);
int contarVocales(char texto[]);
int main()
{
    eNotebook listaN[TAM];

    printf("Hello world!\n");

    return 0;
}
float aplicarAumento( float valor, int porcentaje)
{
    float valorFinal;
    float valorMasPorc;
   valorMasPorc =valor*(porcentaje/100);
   valorFinal=valor+valorMasPorc;
   return valorFinal;
}
int contarVocales(char texto[])
{
    int i=0;
    int contadorV=0;
    while(texto!='\0')
    {
        if(texto[i]=='a' || texto[i]=='e' ||texto[i]=='i' ||texto[i]=='o' ||texto[i]=='u' || texto[i]=='A' ||texto[i]=='E' ||texto[i]=='I' ||texto[i]=='O' ||texto[i]=='U')
        {
            contadorV++;
        }
        i++;

    }
    return contadorV;
}
void ordenar(eNotebook lista[],int tam)
{
    int i=0;
    int j=0;
    char aux[100];
    int auxP;
    for(i=0; i< tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista.marca[i],lista.marca[j])>0)
            {
                strcpy(auxiliar,lista.marca[i]);
                strcpy(lista.marca[i],lista.marca[j]);
                strcpy(lista.marca[j], auxiliar);

            else if(strcmp(lista.marca[i],lista.marca[j])==0)
            {
                if(lista.precio[i]-lista.precio[j]<0)
                {
                        auxP=lista.precio[i];
                        lista.precio[i]=lista.precio[j];
                        lista.precio[i]=auxP;
                }

            }
            }
        }
    }
}
