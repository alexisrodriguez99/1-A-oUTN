#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"


int main()
{
    int respuesta;
    int edadUno;
    int edadDos;
    int resulatdoDeLaSuma;
    saludar();



    resulatdoDeLaSuma=pedirDatosYoperar();
    printf("\n la suma es %d",resulatdoDeLaSuma);


    edadUno=33;
    cambiarContenidoPorValor(edadUno);
    printf("\n la edad es %d",edadUno);

    edadDos=22;
    respuesta=Suma(3,7);
    printf("\nla suma es( de literales) : %d",respuesta);
    respuesta=Suma(edadUno,edadDos);
    printf("\nla suma es( de variables) : %d",respuesta);
    return 0;
}


