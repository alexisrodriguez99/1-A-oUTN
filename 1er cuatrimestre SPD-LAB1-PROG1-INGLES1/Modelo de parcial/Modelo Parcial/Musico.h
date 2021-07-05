#include "input.h"
#include "Orquesta.h"
#include "Instrumento.h"
#define TMUSICOS 4
#define TINSTRUMENTOS 4
#define TORQUESTA 4

typedef struct
{
    int IDMusico;
    char nombre[21];
    char apellido[21];
    int edad;
    int IDorquesta;
    int IDinstrumento;
    int estado;
}eMusico;

void hardcodearMusicos(eMusico lista[]);


void listarMusicos(eMusico lista[], int tam, eInstrumento[], int);
void mostrarMusico(eMusico orquesta, eInstrumento[], int);
int mostrarTipoInstrumento(int, eInstrumento[], int);
int mostrarNombreInstrumento(char[],int, eInstrumento[], int);

int inicializarMusicos(eMusico[], int tam);
int buscarMusicoLibre(eMusico[], int tam);
int agregarMusico(eMusico[], int tam, int*, eOrquesta[], int tamOrquesta, eInstrumento[], int tamInstrumento);
int cargarMusico(eMusico*, int*, eOrquesta[], int tamOrquesta, eInstrumento[], int tamInstrumento);

int ingresarIDOrquesta(int*, eOrquesta [], int tam);
int ingresarIDInstrumento(int*, eInstrumento [], int tam);

int bajaOrquesta(eOrquesta[], int, eMusico[], int);
