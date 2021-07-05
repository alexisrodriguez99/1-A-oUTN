#include <stdio.h>
#include <stdlib.h>
 #include<string.h>
#define TAM 30
int intentoDeStrcmp(char palabra1[],char palabra2[]);
int main()
{
    char char1[TAM];
    char char2[TAM];
    int numeroResta;
    printf("ingrese algo\n");
    gets(char1);
    printf("ingrese algo\n");
    gets(char2);
    numeroResta=char1[0]-char2[0];
    printf("el numero es: %d\n",numeroResta);
    numeroResta=strcmp(char1,char2);
    printf("el numero es: %d\n",numeroResta);
    numeroResta=intentoDeStrcmp(char1,char2);
    printf("el numero es: %d\n",numeroResta);

}
int intentoDeStrcmp(char palabra1[],char palabra2[])
{
    int i;
    int resultado=0;
    int tam;
    if(strlen(palabra1)<strlen(palabra2))
    {
        tam=strlen(palabra2);
    }
    else
    {
        tam=strlen(palabra1);
    }
    for(i=0;i<tam;i++)
    {
        resultado=palabra1[i]-palabra2[i];
        if(resultado>0)
        {
            resultado=1;
            break;
        }
        if(resultado<0)
        {
            resultado=-1;
            break;
        }
    }
    return resultado;
}
