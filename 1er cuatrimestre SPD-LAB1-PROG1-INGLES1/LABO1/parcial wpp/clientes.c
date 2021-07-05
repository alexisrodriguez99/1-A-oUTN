#include "clientes.h"

void hardCodearCliente(eCliente listado[],int tam)
{
    char nombre[5][20]={"alesi","nombre2","nombre3","nombre4","nombre51"};
  char apellido[5][20]={"apellido1","apellido2","apellido3","apellido4","apellido5"};
  char localidad[5][20]={"localidad","localidad2","localidad3","localidad4","localidad5"};
  char telefono[5][20]={"telefono1","telefono2","telefono3","telefono4","telefono5"};
  int edad[5]={1,2,3,4,5};
    char sexo[5]={'m','m','m','m','f'};
  int estado[5]={1,1,1,1,1};
  int id[5]={1,2,3,4,5};
    int i;
    for(i=0; i<tam; i++)// defino un tam del hardcodeo xd no?
  {
            strcpy(listado[i].nombre, nombre[i]);
    strcpy(listado[i].apellido, apellido[i]);
            strcpy(listado[i].localidad, localidad[i]);
      listado[i].edad = edad[i];
    listado[i].sexo= sexo[i];
    strcpy(listado[i].telefono, telefono[i]);
            listado[i].id = id[i];

      listado[i].estado = estado[i];
}
}
void mostrarUnCliente (eCliente listado)
{
    printf("%10s %15s %15s %15s %3d %5c %5d\n",listado.nombre,listado.apellido,listado.localidad,listado.telefono,listado.edad,listado.sexo,listado.id);
}
void mostrarTodosLosCliente (eCliente listado[], int tam)
{
    int i;

   for(i=0; i<tam; i++)
   {
        if(listado[i].estado==1){
               mostrarUnCliente(listado[i]);
           }
   }
}
void inicializarCliente(eCliente listado[], int tam)
{
     int i;

  for(i=0; i<tam; i++)
  {
      listado[i].estado = -1;
      listado[i].id=0;
  }
}
/*int buscarLibre(eCliente listado[], int tam)
{

}*/
eCliente buscarClienteId(eCliente lista[],int tam, int idCliente)
{
    eCliente auxCliente={"no existe","no existe","no existe","no existe",2222,'s',3,4};
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].id==idCliente)
        {
            auxCliente=lista[i];
            break;
        }
    }
    return auxCliente;
}
void mostrarNombreCliente(eCliente listado)
{
    printf("%15s\n",listado.nombre);
}
