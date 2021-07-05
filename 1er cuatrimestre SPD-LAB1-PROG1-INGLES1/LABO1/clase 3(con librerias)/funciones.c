#include "funciones.h"
#include <stdio.h>

/*
*saluda
*/
void saludar()
{
     printf("\nBienvenidos a las funciones");
}

/*
* cambia el valor
*/
void cambiarContenidoPorValor(int primerParametro)
{
    printf("\n el parametro antes es %d",primerParametro);
    primerParametro=9;
    printf("\n el parametro despues es %d",primerParametro);

}


/*
*suma dos numeros y retorna el resultado
*/
int Suma(int primerParametro, int segundoParametro)
{
    int respuestaSuma;
    respuestaSuma=primerParametro+segundoParametro;
    return respuestaSuma;
}

int pedirDatosYoperar(){

    int datoUno;
    int datoDos;
    int suma;

    datoUno=pedirUnDato();
    datoDos=pedirUnDato();

    suma=Suma(datoUno,datoDos);
    return suma;


}

int pedirUnDato(){
    int datoIngresado;
    printf("\ningrese un dato: ");
    scanf("%d",&datoIngresado);
    return datoIngresado;
}



