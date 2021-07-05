#include "camiones.h"
void mostrarChoferesConCamiones(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer);
//int pedirFlotante(char mensaje[]);
//void pedirCadena(char mensaje[], char mensajeError[], char laCadena[]);

int cargarCamion(eCamion listadoCamion[],int tamCamion,eChofer listadoChofer[],int tamChofer);
int asignarChofer(eChofer listado[],int tam);
void guardarCamion(eCamion lista[], int tam, int id, char patente[],char marca[],int anio,float peso,int cantidadDeRuedas,char tipo[],int idChofer,int i,int estado);
int modificarCamion(eCamion listaCamion[],int tamCamion,eChofer listaChofer[],int tamChofer);
int bajaChofer(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion);
void ordenarPorTipo(eCamion listado[], int tamCamion);
void  mostrarCamionesConChoferes(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer);
void choferesConMasUnCamiones(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion);
void camionesConMasAntiguedad(eCamion listaCamion[],int tamCamion,eChofer listaChofer[], int tamChofer);
void ordenarChoferMasCamiones(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion);
int cantidadDeCamiones(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion,int indice);
void mostrarChoferMCCamion(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion);
void ordenarChoferCant_Nom(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion);
void mostrarChoferFullOrden(eChofer listadoChofer[],int tamChofer,eCamion listadoCamion[],int tamCamion);
