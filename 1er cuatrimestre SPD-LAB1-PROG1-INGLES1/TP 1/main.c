#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    int opcion;
    float numero1;
    float numero2;
    float suma;
    float resta;
    float producto;
    float division;
    int flagA=0;
    int flagB=0;
    int flagDivision=0;
    int flagCalcular=0;
    int factorialA;
    int factorialB;


    do
    {
        if(flagA==0 && flagB==0)
        {
            printf("1) Ingresar 1er operando (A=x)");
            printf("\n2) Ingresar 2do operando (B=y)");
            printf("\n3) Calcular todas las operaciones");
            printf("\n4) Informar resultados ");
            printf("\n5) salir");
            printf("\nElija una opcion: ");
        }
       else if(flagA==1 && flagB==0)
       {
           printf("1) Ingresar 1er operando (A=%f)",numero1);
            printf("\n2) Ingresar 2do operando (B=y)");
            printf("\n3) Calcular todas las operaciones");
            printf("\n4) Informar resultados ");
            printf("\n5) salir");
            printf("\nElija una opcion: ");
       }
        else if(flagA==0 && flagB==1)
        {
            printf("1) Ingresar 1er operando (A=x)");
            printf("\n2) Ingresar 2do operando (B=%f)",numero2);
            printf("\n3) Calcular todas las operaciones");
            printf("\n4) Informar resultados ");
            printf("\n5) salir");
            printf("\nElija una opcion: ");

        }
        else

        {
            printf("1) Ingresar 1er operando (A=%f)",numero1);
            printf("\n2) Ingresar 2do operando (B=%f)",numero2);
            printf("\n3) Calcular todas las operaciones");
            printf("\n4) Informar resultados ");
            printf("\n5) salir\n");
            printf("\nElija una opcion: ");
        }

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
            {

                numero1=getFloat("Ingrese el primer numero: ");
                flagA=1;
                break;
            }
            case 2:
            {

                numero2=getFloat("Ingrese el segundo numero: ");
                flagB=1;
                break;
            }
            case 3:
                {
                    if(flagA==1 && flagB==1)
                    {
                      suma=sumar(numero1,numero2);
                    resta=restar(numero1,numero2);
                    producto=multiplicar(numero1,numero2);
                    if(numero2!=0)
                    {
                     division=dividir(numero1,numero2);
                     flagDivision=1;
                    }

                    factorialA=factorial(numero1);
                    factorialB=factorial(numero2);
                    printf("Se han realizado todas las operacion con exito.\n");
                    flagCalcular=1;
                    }
                    else
                    {
                        printf("Error. Intente ingresar 2 numeros anstes de entrar a esta opcion");
                    }
                    break;
                }
            case 4:
                {
                    if(flagCalcular==1 && flagA==1 && flagB==1)
                    {
                        printf("El resultado de A+B es: %f",suma);
                        printf("\nEl resultado de A-B es: %f",resta);
                        if(flagDivision==0)
                        {
                            printf("\nNo es posible dividir por cero");
                        }
                        else
                        {
                            printf("\nEl resultado de A/B es: %f",division);
                        }

                        printf("\nEl resultado de A*B es: %f",producto);
                        printf("\nEl factorial de A es: %d y El factorial de B es: %d\n",factorialA,factorialB);

                    }

                    else
                    {
                        printf("Error. Tiene que ingresar 2 numeros y despues calcularlos, antes de poder ingresar a esta opcion\n");
                    }

                    break;
                }
            case 5:
                {
                    printf("Usted esta saliendo, hasta luego.\n");
                    break;
                }
            default:
            {
                printf("Opcion incorrecta");
            }
        }


        system("pause");
        system("cls");
    }
    while(opcion!=5);

return 0;
}
