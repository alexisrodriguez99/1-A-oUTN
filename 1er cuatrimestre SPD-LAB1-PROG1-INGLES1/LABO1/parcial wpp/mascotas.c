#include "mascotas.h"
void hardCodearMascota(eMascota listado[],int tam)
{
    char nombre[11][20]= {"nombre1","nombre2","nombre3","nombre4","nombre5","nombre6","nombre7","nombre8","nombre9","nombre10","nombre11"};
    int tipo[11]= {2,2,1,1,2,1,3,1,2,2,1}; //1 perro 2gato 3otro
    char raza[11][20]= {"raza1","raza2","raza3","raza4","raza5","raza6","raza7","raza8","raza9","raza10","raza11"};
    int edad[11]= {12,2,4,1,6,3,7,8,4,2,4};
    int peso[11]= {13,44,55,66,22,55,22,55,11,44,11};
    char sexo[11]= {'m','m','m','m','f','f','f','f','f','f','f'};
    int estado[11]= {1,1,1,1,1,1,1,1,1,1,1};
    int id[11]= {1,2,3,4,5,6,7,8,9,10,11};
    int idCliente[11]={1,1,2,2,2,3,3,4,5,5,5};
    int i;
    for(i=0; i<tam; i++)// defino un tam del hardcodeo xd no?
    {
        strcpy(listado[i].nombre, nombre[i]);
        listado[i].tipo = tipo[i];
        strcpy(listado[i].raza, raza[i]);

        listado[i].peso = peso[i];

        listado[i].edad = edad[i];
        listado[i].sexo= sexo[i];
        listado[i].id = id[i];

        listado[i].estado = estado[i];
        listado[i].idCliente = idCliente[i];

    }
}
void mostarUnaMascota (eMascota listado,eCliente cliente[],int tamCliente)
{
    eCliente auxCliente;
    auxCliente=buscarClienteId(cliente,tamCliente,listado.idCliente);
    printf("%15s\t %d\t %15s\t %d\t %d\t %c\t %d\t",listado.nombre,listado.tipo,listado.raza,listado.edad,listado.peso,listado.sexo,listado.id);
    mostrarNombreCliente(auxCliente);
}
void mostarTodasLasMascotas (eMascota listado[], int tam,eCliente cliente[],int tamCliente)
{
    int i;

   for(i=0; i<tam; i++)
   {
        if(listado[i].estado==1){
               mostarUnaMascota(listado[i],cliente,tamCliente);
           }
   }
}
void mostrarSoloMascota(eMascota listado)
{
        printf("%10s %9d %15s %15d %3d %5c %5d\n\n",listado.nombre,listado.tipo,listado.raza,listado.edad,listado.peso,listado.sexo,listado.id);

}
void mostarTodasSoloMascota(eMascota listado[],int tam)
{
        int i;

   for(i=0; i<tam; i++)
   {
        if(listado[i].estado==1){
               mostrarSoloMascota(listado[i]);
           }
   }
}
int buscarLibre(eMascota listado[], int tam)
{
  int i;
    int indice=-1;
  for(i=0; i<tam; i++)
  {
      if( listado[i].estado==-1)
      {
         indice=i;
         break;
      }
  }
  return indice;
}
void inicializarMascota(eMascota listado[],int tam)
{
     int i;

  for(i=0; i<tam; i++)
  {
      listado[i].estado = -1;
      listado[i].id=0;
  }
}
