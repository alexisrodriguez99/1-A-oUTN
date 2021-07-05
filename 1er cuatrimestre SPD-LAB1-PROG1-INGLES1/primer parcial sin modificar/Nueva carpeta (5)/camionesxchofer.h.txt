#include "camiones.h"
void mostrarCamionesYChoferes(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer);
int pedirFlotante(char mensaje[]);
void pedirCadena(char mensaje[], char mensajeError[], char laCadena[]);

int cargarCamion(eCamion listadoCamion[],int tamCamion,eChofer listadoChofer[],int tamChofer);
int asignarChofer(eChofer listado[],int tam);
void guardarCamion(eCamion lista[], int tam, int id, char patente[],char marca[],int anio,float peso,int cantidadDeRuedas,char tipo[],int idChofer,int i,int estado);
