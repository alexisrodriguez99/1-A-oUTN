#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  char nombre[20];
  char apellido[20];
  char localidad[20];
  char telefono[20];
  int edad;
  char sexo;
  int estado;
  int id;

} eCliente;
void hardCodearCliente(eCliente listado[],int tam);
void mostrarUnCliente (eCliente listado);
void mostrarTodosLosCliente (eCliente listado[], int tam);
void inicializarCliente(eCliente listado[], int tam);
//int buscarLibre(eCliente listado[], int tam);
eCliente buscarClienteId(eCliente lista[],int tam, int idCurso);
void mostrarNombreCliente(eCliente listado);
