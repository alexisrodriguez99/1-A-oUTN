#include <stdio.h>
#include <stdlib.h>
 #include<string.h>
 #define TAM 50
void intentoDeSrtcat(char mensaje1[], char mensaje2[]);
int main()
{
    char char1[TAM];
    char char2[TAM];

    printf("ingrese algo\n");
    gets(char1);
    printf("ingrese algo\n");
    gets(char2);
    /*strcat(char1," ,");

    strcat(char1,char2);
    printf("%s\n",char1);
    printf("%s\n",char2);*/
    intentoDeSrtcat(char1," ,");
    intentoDeSrtcat(char1,char2);
    printf("%s\n",char1);
    printf("%s\n",char2);

}
void intentoDeSrtcat(char mensaje1[], char mensaje2[])
{
    int i=0;
    int j=0;
    //int tam;
    /*tam=strlen(mensaje2);
    for(i=0;i<tam;i++)
    {
        if(mensaje1[i]!='\0')
        {
            i++;
        }
        if(mensaje1[i]=='\0')
        {
            mensaje1[i]=mensaje2[i];
            i++;
        }
    }*/
    while(mensaje2[j]!='\0')
    {
        if(mensaje1[i]=='\0')
        {
            mensaje1[i]=mensaje2[j];
            mensaje1[i+1]='\0';
            i++;
            j++;
        }
        if(mensaje1[i]!='\0')
        {
            i++;
        }
    }
}
