#include "Input.h"
#define TMASCOTAS 11
typedef struct
{
    int idMascota;
    int idCliente;
    char nombre[21];
    char tipo[6];//gato, perro o raro
    char raza[21];
    int edad;
    float peso;
    char sexo;
    int estado;
}eMascota;

void hardcodearMascotas(eMascota lista[]);

void mostrarMascota(eMascota mascota);
void listarMascotas(eMascota lista[], int tamMascotas);

int buscarMascotaLibre(eMascota lista[], int tam);
int buscarMascota(eMascota lista[], int tamMascota, char cadena[]);

int ingresarTipo(eMascota * auxiliar);
int bajaMascota(eMascota lista[], int tamMascota);

int modificarMascota(eMascota lista[], int tamMascota);
int modificarDatos(eMascota* auxiliar);

void ordenarMascotas(eMascota lista[], int tamMascota);

