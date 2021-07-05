#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 20
void copiar(char destino[], char origen[]);
int main()
{
    char char1[TAM];
    char char2[TAM];
    printf("ingrese algo\n");
    gets(char1);
    printf("ingrese algo\n");
    gets(char2);
    printf("la cadena 1 es: %s\n",char1);
    printf("la cadena 2 es: %s\n",char2);
    copiar(char1,char2);
   /* strcpy(char1,char2);*/
    printf("\nla cadena 1 es: %s\n",char1);
    printf("la cadena 2 es: %s\n",char2);

}
void copiar(char destino[], char origen[])
{
    /*int i;//ORIGEN
    int j=0;//DESTINO
    int tam;
    tam=strlen(origen);
    for(i=0;i<tam;i++)
    {

        destino[j]=origen[i];
        j++;
    }
    destino[i]='\0';*/
    int i=0;
    while(origen[i]!='\0')
    {
            destino[i]=origen[i];
            i++;
    }
    destino[i]='\0';
}
