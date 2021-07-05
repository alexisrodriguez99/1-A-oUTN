#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int campo1;
    char campo2;
    float campo3;

}Estructura;
Estructura* estructura_new();
Estructura* estructura_newParametros(int campo1,char campo2, float campo3);
void mostrar(Estructura* estructura);

void escribirTxt();
void leerTxt();


void escribirBin(Estructura* estructura);
void leeBin();

int main()
{
    //int factorial;
   // factorial=0;
    Estructura* parcial;
    parcial=estructura_newParametros(3,'f',3.4);
    mostrar(parcial);

    escribirTxt();
     leerTxt();


     escribirBin(parcial);
     printf("\n lectura en binario\n");
     leeBin();
   /* printf("ingrese un numero %d", factorial);
    scanf("%d",&factorial);
    printf("el numero es %d", factorial);*/
}
Estructura* estructura_new()
{
    return (Estructura*)malloc(sizeof(Estructura));
}
Estructura* estructura_newParametros(int campo1,char campo2, float campo3)
{
    Estructura* estructura;
    estructura=estructura_new();
    if(estructura!=NULL)
    {
        estructura->campo1=campo1;
        estructura->campo2=campo2;
        estructura->campo3=campo3;
    }
    return estructura;
}
void mostrar(Estructura* estructura)
{
    printf("%d %c %f\n",estructura->campo1,estructura->campo2,estructura->campo3);
}


void escribirTxt()
{
    FILE* pFile;

    char nombre[50];
    int numero;
    //char apellido[50];
    printf("ingrese un nombre\n");
    //fflush(stdin);
    gets(nombre);

    printf("ingrese un numero\n");
    scanf("%d",&numero);
//fflush(stdin);
   // gets(apellido);

    pFile=fopen("Texto.txt","w");

    if(pFile!=NULL)
    {
        fprintf(pFile,"%s\n%d\n",nombre,numero);
    }
    fclose(pFile);
}
void leerTxt()
{
    FILE* pfile;
    char nombre[50];
    char numero[50];
    int numeroEnt;
   // int numeroEnt;
    pfile=fopen("Texto.txt","r");
    if(pfile!=NULL)
    {
        fscanf(pfile,"%[^\n]\n%[^\n]\n",nombre,numero);
    }
    fclose(pfile);
    numeroEnt=atoi(numero);
    numeroEnt=numeroEnt+222;
    printf("%s\n%d",nombre,numeroEnt);

}
void escribirBin(Estructura* estructura)
{
    FILE* pfile;
    int error;
    pfile=fopen("texto.bin","wb");
    if(pfile!=NULL)
    {
           error= fwrite(estructura,sizeof(Estructura),1,pfile);
            if(error!=1)
            {
                printf("Error en la lectura");
            }
    }

    fclose(pfile);
}
void leeBin()
{
    FILE* pFile;
    Estructura* aux;
    aux=estructura_new();
    pFile=fopen("texto.bin","rb");
    if(pFile!=NULL)
    {
        fread(aux,sizeof(Estructura),1,pFile);
    }
    fclose(pFile);
    printf("\n%d %c %f",aux->campo1,aux->campo2,aux->campo3);
}
