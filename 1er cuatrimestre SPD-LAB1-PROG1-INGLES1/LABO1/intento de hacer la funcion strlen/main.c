#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 20
int intentoStrln(char loQueCuenta[]);
int main()
{
  /*  char char1[TAM];
    char char2[TAM];
    char char3[TAM];
    int cantidadDeLetras;
    int cantidadDeLetras2;
    int cantidadDeLetras3;

    printf("ingrese algo\n");
    scanf("%s",char1);//CUANDO PASA EL LITIMITE DEL ARRAY LA CUENTA SE REINICIA || ADEMAS SOLO GUARDA ESPACIOS
    fflush(stdin);
    printf("ingrese algo de nuevo\n");
    fflush(stdin);
    gets(char2);//CUANDO PASA EL LIMITE DEL ARRAY SIGUE CONTANDO CON NORMALIDAD || GUARA ESPACIOS (USAR GETS ES MEJOR XD)
    printf("ingrese algo de nuevo 3\n");
    fgets(char3,TAM,stdin);//LO MISMO QUE GETS || NO SOLO GUARDA EL ESPACIO, TAMBIEN GUARDA EL ENTER, ES DECIR SIEMPRE CUENTA UN CARACTER DE MAS

    cantidadDeLetras=strlen(char1);

    cantidadDeLetras2=strlen(char2);
    cantidadDeLetras3=strlen(char3);

    printf("la cantidad es: %d\n",cantidadDeLetras);
    printf("la cantidad es: %d\n",cantidadDeLetras2);
    printf("la cantidad es: %d\n",cantidadDeLetras3);*/

    //___________________________________________QUIERO SIMILAR LA FUNCION STRLN___________________________________________________________
    char cadena1[TAM];
    int cantidadLetras;
    printf("ingrese algo\n");
    gets(cadena1);
    cantidadLetras=intentoStrln(cadena1);
    printf("la cantidad es: %d",cantidadLetras);


}
int intentoStrln(char loQueCuenta[])
{
   int i=0;


    while(loQueCuenta[i]!='\0'){
        i++;
    }
    return i;
}

