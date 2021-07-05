#include "Clientes.h"
#include "Mascotas.h"
#include "Input.h"

void mostrarClientesConMascotas(eCliente[], eMascota[], int, int);

int altaMascotas(eMascota[], eCliente[], int, int, int*);
int asignarCliente(eCliente listaClientes[], eMascota * auxiliar, int tamCliente);
int cargarMascota(eMascota* auxiliar, int * id, eCliente listaClientes[], int tamCliente);

