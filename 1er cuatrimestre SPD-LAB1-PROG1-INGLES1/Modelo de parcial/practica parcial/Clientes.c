#include "Clientes.h"

void hardcodearClientes(eCliente lista[])
{
    int ID[TCLIENTES]= {1,2,3,4,5};
    char nombre[TCLIENTES][21]= {"cMujer1","zSenior1", "aChica1", "gChico1", "aSenior2"};
    char apellido[TCLIENTES][21]= {"eMujer1","aSenior1", "bChica1", "aChico1", "kSenior2"};
    char localidad[TCLIENTES][21]= {"Guernica", "Guernica", "Glew", "Longchamps", "Burzaco"};
    char telefono[TCLIENTES][21]= {"223-543", "225-723", "123-512", "092-002", "627-137"};
    int edad[TCLIENTES]= {40, 51, 22, 18, 38};
    char sexo[TCLIENTES]= {'f', 'm', 'f', 'm', 'm'};
    int estado[TCLIENTES]= {1, 1, 1, 1, 1};

    for(int i = 0; i < TCLIENTES; i++)
    {
        lista[i].ID = ID[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido, apellido[i]);
        strcpy(lista[i].localidad, localidad[i]);
        strcpy(lista[i].telefono, telefono[i]);
        lista[i].edad = edad[i];
        lista[i].sexo = sexo[i];
        lista[i].estado = estado[i];
    }
}

void mostrarCliente(eCliente cliente)
{
    printf("\n%15s|%15s|%15s|%15s|%9d|%9c|", cliente.apellido,
           cliente.nombre,
           cliente.localidad,
           cliente.telefono,
           cliente.edad,
           cliente.sexo);
}
void listarCliente(eCliente lista[], int tamcliente)
{
    printf("\nCLIETNES:");
    printf("\n       APELLIDO|\t NOMBRE|      LOCALIDAD|       TELEFONO|     EDAD|     SEXO|");
    for(int i = 0; i < tamcliente; i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarCliente(lista[i]);
        }
    }
}

void ordenarClientes(eCliente lista[], int tamCliente)
{
    eCliente aux;
    for(int i = 0; i < tamCliente -1; i++)
    {
        for(int j = i+1; j < tamCliente; j++)
        {
            if((strcmp(lista[i].apellido, lista[j].apellido) > 0) || ((strcmp(lista[i].apellido, lista[j].apellido) == 0) && (strcmp(lista[i].nombre, lista[j].nombre) > 0)))
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}
