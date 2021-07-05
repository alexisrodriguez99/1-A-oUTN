#include <stdio.h>
#include <stdlib.h>
int texto();
int leer();
int main()
{

}
int texto()
{
    FILE* pFile;
    char nombre[50];
    char apellido[50];
    int cantidad;

    pFile=fopen("prueba.txt","w");

        printf("ingrese su nombre");
    gets(nombre);
    cantidad=strlen(nombre)
    fwrite(nombre,sizeof(char),pFile);

    printf("ingrese su apellido");
    gets(apellido);
    cantidad=strlen(apellido)
    fwrite(apellido,sizeof(char),pFile);


}
int leer();
/*
un programador deberia usar punteros para desarrollar el suso  de memoria dinamia ya que en el caso de usar dunciones staticas puede ser malo para la pila. en el caso de usar memoria dinamica, reserva espacio en memoria el cual hace que se guarde en el heap
*/
