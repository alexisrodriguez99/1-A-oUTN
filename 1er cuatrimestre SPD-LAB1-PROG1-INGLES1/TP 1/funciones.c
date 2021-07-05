#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
float getFloat(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    return numero;
}
float sumar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1+numero2;
    return resultado;
}
float restar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1-numero2;
    return resultado;
}
float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1*numero2;
    return resultado;
}
float dividir(float numero1, float numero2)
{
    float resultado;

    resultado=numero1/numero2;

    return resultado;

}
int factorial(float numero)
{
    int i;
    int resultado;

    if(numero==0)
    {
        resultado=1;

    }
    else
    {
        resultado=numero;
        for(i=numero-1; i>0; i--)
        {
            resultado=resultado*i;

        }

    }
        return resultado;


}

