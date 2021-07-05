#include "Input.h"
#define TCLIENTES 5

typedef struct
{
    int ID;
    char nombre[21];
    char apellido[21];
    char localidad[21];
    char telefono[21];
    int edad;
    char sexo;
    int estado;
}eCliente;

void hardcodearClientes(eCliente lista[]);

void mostrarCliente(eCliente cliente);
void listarCliente(eCliente lista[], int tamcliente);

void ordenarClientes(eCliente lista[], int tamCliente);
